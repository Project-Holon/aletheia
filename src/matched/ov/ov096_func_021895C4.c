/*
 * function: func_021895C4
 * address:  0x021895C4
 * packet:   pkt_ov096_021895C4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_0218A580     0x0218A580  data   ov096  a4
 */
#include "../include/Obj10184.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { int a, b, c; } Tri;

extern const Tri d_0218A580;
extern int func_0201134C(int);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D59B4(u8 *p, int k);

int func_021895C4(int a, int b) {
    int r6;
    int r7;
    int x;
    int y;
    Tri t;
    r6 = func_0201134C(a);
    r7 = func_0201134C(a);
    t = d_0218A580;
    x = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fBC, 15);
    y = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fC0, 15);
    func_0218A0F4((u8 *)a, ((int *)&t)[r6], x, y, r7);
    return ((struct Obj10184 *)b)->fC4;
}
