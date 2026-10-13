/*
 * function: BTLV_SCU_ProcNamePlateAt
 * address:  0x021EDA94
 * packet:   pkt_ov093_021EDA94
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_GetNamePlateSide  0x021EDA3C  thumb  ov093
 *   BTLV_SCU_ProcNamePlate  0x021EDCA8  thumb  ov093
 */
#include "../include/Obj21610.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTLV_SCU_GetNamePlateSide(u8 *, u32);
extern int BTLV_SCU_ProcNamePlate(u8 *);
void BTLV_SCU_ProcNamePlateAt(u8 *p, u32 x)
{
    BTLV_SCU_ProcNamePlate(p + 0x90 + BTLV_SCU_GetNamePlateSide(*(u8 * *)&((struct Obj21610 *)p)->f134, x) * 0x24);
}
