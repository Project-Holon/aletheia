/*
 * function: func_021ED9A4
 * address:  0x021ED9A4
 * packet:   pkt_ov093_021ED9A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 */
#include "../include/Obj10122.h"
typedef unsigned char u8;
struct E { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };
typedef unsigned int   u32;
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
void func_021ED9A4(struct E *e, u8 *o, u8 k)
{
    e->k8 = k;
    e->v9 = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj10122 *)o)->f134, k);
    e->owner = o;
    e->fa = 0;
    e->fb = 1;
    e->a0 = 0;
}
