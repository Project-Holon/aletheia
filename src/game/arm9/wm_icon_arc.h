#ifndef GAME_ARM9_WM_ICON_ARC_H
#define GAME_ARM9_WM_ICON_ARC_H

/* Public functions of wm_icon_arc.c, prototypes copied from their definitions. */

struct NetDeviceHeader;
typedef struct NetDeviceHeader NetDeviceHeader;

#include "../types.h"

u32 WM_ICON_GetArcId(void);
void WM_ICON_InitArcData(NetDeviceHeader *hdr);

#endif
