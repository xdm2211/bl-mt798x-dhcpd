# SPDX-License-Identifier: GPL-2.0

ifeq ($(CONFIG_XPL_BUILD),)

ifeq ($(CONFIG_WEBUI_FAILSAFE_UI_GL),y)
obj-y += fsdata_gl/
else ifeq ($(CONFIG_WEBUI_FAILSAFE_UI_MTK),y)
obj-y += fsdata_mtk/
else
obj-y += fsdata/
endif

obj-y += fs.o failsafe.o
obj-$(CONFIG_WEBUI_FAILSAFE_CONSOLE) += failsafe_console.o
obj-$(CONFIG_WEBUI_FAILSAFE_ENV) += failsafe_env.o
obj-$(CONFIG_WEBUI_FAILSAFE_BACKUP) += failsafe_backup_flash.o
obj-$(CONFIG_WEBUI_FAILSAFE_UI_NEW) += failsafe_theme.o

endif
