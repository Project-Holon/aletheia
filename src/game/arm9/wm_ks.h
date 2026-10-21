#ifndef GAME_ARM9_WM_KS_H
#define GAME_ARM9_WM_KS_H

#include "../sdk_wm.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_ks.c, prototypes copied from their definitions. */

#include "../types.h"

WMErrCode WM_StartKeySharing(void *dsInfo, u16 port);
WMErrCode WM_EndKeySharing(void *dsInfo);
/* END mkheaders: generated region */

#endif
