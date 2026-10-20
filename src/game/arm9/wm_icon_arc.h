#ifndef GAME_ARM9_WM_ICON_ARC_H
#define GAME_ARM9_WM_ICON_ARC_H

typedef struct NetDeviceHeader NetDeviceHeader;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_icon_arc.c, prototypes copied from their definitions. */

struct NetDeviceHeader;
typedef struct NetDeviceHeader NetDeviceHeader;

#include "../types.h"

u32 WM_ICON_GetArcId(void);
void WM_ICON_InitArcData(NetDeviceHeader *hdr);
/* END mkheaders: generated region */

#endif
