/*
 * function: func_02188A08
 * address:  0x02188A08
 * packet:   pkt_ov096_02188A08
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021C82D0  0x021C82D0  thumb  ov093
 */
#include "../include/Obj21934.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021C82D0(int unused, unsigned int v, int k);

int func_02188A08(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    r = func_0218A160((u8 *)b, t0);
    r = func_021C82D0(((struct Obj21934 *)b)->fB4, r, t1);
    return func_0218A0F4((u8 *)a, c, r != 0, 1, t2);
}
