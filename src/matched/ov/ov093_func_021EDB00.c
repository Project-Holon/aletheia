/*
 * function: BTLV_SCU_RefreshNamePlateAt
 * address:  0x021EDB00
 * packet:   pkt_ov093_021EDB00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_GetNamePlateSide  0x021EDA3C  thumb  ov093
 *   BTLV_SCU_RefreshNamePlate  0x021EDF7C  thumb  ov093
 */
#include "../include/Obj21613.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTLV_SCU_GetNamePlateSide(u8 *, u32);
extern void BTLV_SCU_RefreshNamePlate(u8 *, u8);
void BTLV_SCU_RefreshNamePlateAt(u8 *p, u8 a)
{
    BTLV_SCU_RefreshNamePlate(p + 0x90 + BTLV_SCU_GetNamePlateSide(*(u8 * *)&((struct Obj21613 *)p)->f134, a) * 0x24, a);
}
