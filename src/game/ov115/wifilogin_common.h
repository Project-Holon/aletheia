#ifndef GAME_OV115_WIFILOGIN_COMMON_H
#define GAME_OV115_WIFILOGIN_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilogin_common.c, prototypes copied from their definitions. */

#include "../types.h"

int WIFILOGIN_COMMON_IsCancelInput(u8 *p);
void WIFILOGIN_COMMON_SetStateHandler(u8 *p, void (*handler)(u8 *));
void WIFILOGIN_COMMON_CheckLocalAid(u32 localAid, u32 unused1, u32 unused2, u8 *state, void *handle);
u8 *WIFILOGIN_COMMON_GetSessionId(void);
int WIFILOGIN_COMMON_GetMaxPlayers(void);
int WIFILOGIN_COMMON_IsSameId(int a, int b);
/* END mkheaders: generated region */

#endif
