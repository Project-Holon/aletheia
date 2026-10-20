#ifndef GAME_TWL_NWM_WPA_H
#define GAME_TWL_NWM_WPA_H

#include "../types.h"

typedef struct TwlReq {
    u16 kind;
    u8 data[0x20];
} TwlReq;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_wpa.c, prototypes copied from their definitions. */

#include "../types.h"

u32 NWM_SetWPAPSK(void *callback, TwlReq *pskInfo);
/* END mkheaders: generated region */

#endif
