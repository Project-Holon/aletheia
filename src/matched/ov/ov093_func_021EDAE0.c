/*
 * function: BTLV_SCU_IsNamePlateHiddenAt
 * address:  0x021EDAE0
 * packet:   pkt_ov093_021EDAE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_GetNamePlateSide  0x021EDA3C  thumb  ov093
 *   BTLV_SCU_IsNamePlateHidden  0x021EDF78  thumb  ov093
 */
#include "../include/Obj21612.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTLV_SCU_GetNamePlateSide(u8 *, u32);
extern int BTLV_SCU_IsNamePlateHidden(u8 *);
void BTLV_SCU_IsNamePlateHiddenAt(u8 *p, u32 x)
{
    u8 k = BTLV_SCU_GetNamePlateSide(*(u8 * *)&((struct Obj21612 *)p)->f134, x);
    BTLV_SCU_IsNamePlateHidden(p + 0x90 + k * 0x24);
}
