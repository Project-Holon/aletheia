/*
 * function: func_021ED494
 * address:  0x021ED494
 * packet:   pkt_ov093_021ED494
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021F8118  0x021F8118  thumb  ov094
 *   func_021F80FC  0x021F80FC  thumb  ov094
 */
#include "../include/Obj13567.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
typedef unsigned int   u32;
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void func_021F8118(u32 a, u32 b);
extern void func_021F80FC(u32 a, u32 b);
void func_021ED494(u8 *p, u8 k, int x)
{
    int d = func_021D59B4(BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj13567 *)p)->f138, k), 0xd);
    u8 r = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj13567 *)p)->f134, k);
    if (x != 0)
        func_021F8118(r, d);
    else
        func_021F80FC(r, d);
}
