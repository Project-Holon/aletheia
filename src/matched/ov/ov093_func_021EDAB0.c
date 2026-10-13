/*
 * function: BTLV_SCU_HideNamePlateAt
 * address:  0x021EDAB0
 * packet:   pkt_ov093_021EDAB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_SCU_GetNamePlateSide  0x021EDA3C  thumb  ov093
 *   BTLV_SCU_HideNamePlate  0x021EDF4C  thumb  ov093
 *   func_021F8504  0x021F8504  thumb  ov094
 */
#include "../include/Obj21611.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct W;
extern int BTLV_SCU_GetNamePlateSide(u8 *, u32);
extern void BTLV_SCU_HideNamePlate(struct W *w);
extern void func_021F8504(u32, u32, u32);
void BTLV_SCU_HideNamePlateAt(u8 *p, u32 x)
{
    u8 k = BTLV_SCU_GetNamePlateSide(*(u8 * *)&((struct Obj21611 *)p)->f134, x);
    BTLV_SCU_HideNamePlate((struct W *)(p + 0x90 + k * 0x24));
    if (k == 0)
        func_021F8504(0, 1, 0);
}
