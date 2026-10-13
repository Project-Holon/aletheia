/*
 * function: func_021ED2D0
 * address:  0x021ED2D0
 * packet:   pkt_ov093_021ED2D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021EDA04  0x021EDA04  thumb  ov093
 */
#include "../include/Obj13566.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
struct E;
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021EDA04(struct E *e);
void func_021ED2D0(u8 *p, u8 k)
{
    u8 r = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj13566 *)p)->f134, k);
    func_021F7EE8(BTL_POKEPARAM_GetDisplayMon((struct Work *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj13566 *)p)->f138, k)), r);
    func_021EDA04((struct E *)(p + 0x48 + k * 12));
}
