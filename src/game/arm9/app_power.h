#ifndef GAME_ARM9_APP_POWER_H
#define GAME_ARM9_APP_POWER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of app_power.c, prototypes copied from their definitions. */

#include "../types.h"

void APP_POWER_ClearCallback(void);
void APP_POWER_SetCallback(u32 on);
void APP_POWER_HaltWithMessage(u32 mode);
void APP_POWER_ShowShutdownScreen(u32 messageId);
void APP_POWER_LoadShutdownScreen(void);
void APP_POWER_DrawShutdownScreen(u32 messageId);
int APP_POWER_IsSupported(void);
int OVERLAY_LAUNCH_Driver(void *unused, u32 *state);
int APP_POWER_IsReady(void);
/* END mkheaders: generated region */

#endif
