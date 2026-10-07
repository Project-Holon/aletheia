/*
 * function: func_020334CC
 * address:  0x020334CC
 * packet:   pkt_020334CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call thunk: forwards its arguments to func_020335E8 with the word at
 * +0x204 of the object at g_02146994 as the last argument.  No arm9 code
 * calls it; its callers are Thumb blx in ov228, so the listing carried it as
 * raw words until the seed in layout/function_starts.txt.
 *
 * symbols:
 *   g_02146994     0x02146994  data
 *   func_020335E8  0x020335E8  arm
 */

#include "../include/G_SaveMain.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct SaveMain *g_02146994;
extern int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));

int func_020334CC(u32 a, u32 b, u32 c)
{
    return func_020335E8(a, b, c, (void (*)(void))(*(u32 *)(((u8 *)g_02146994) + 0x204)));
}
