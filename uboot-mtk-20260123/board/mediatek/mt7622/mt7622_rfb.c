// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2018 MediaTek Inc.
 * Author: Sam Shih <sam.shih@mediatek.com>
 */

#include <common.h>
#include <config.h>
#include <dm.h>
#include <button.h>
#include <env.h>
#include <init.h>
#include <asm/global_data.h>
#include <linux/delay.h>

#ifndef CONFIG_RESET_BUTTON_LABEL
#define CONFIG_RESET_BUTTON_LABEL "reset"
#endif

#include <mtd.h>
#include <linux/mtd/mtd.h>
#include <nmbm/nmbm.h>
#include <nmbm/nmbm-mtd.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x100;
	return 0;
}

int board_late_init(void)
{
	struct udevice *dev;

	if (!button_get_by_label(CONFIG_RESET_BUTTON_LABEL, &dev)) {
		puts("reset button found\n");
#ifdef CONFIG_RESET_BUTTON_SETTLE_DELAY
		mdelay(CONFIG_RESET_BUTTON_SETTLE_DELAY);
#endif
		if (button_get_state(dev) == BUTTON_ON) {
			puts("button pushed, resetting environment\n");
			gd->env_valid = ENV_INVALID;
		}
	}

	env_relocate();
	return 0;
}
