/*
 * function: func_021ED268
 * address:  0x021ED268
 * packet:   pkt_ov093_021ED268
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 */
#include "../include/Obj21589.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *, u32);
extern void func_021F7C2C(int, int);
void func_021ED268(u8 *p, u8 k, u32 x)
{
    func_021F7C2C(BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj21589 *)p)->f134, k), x);
}
