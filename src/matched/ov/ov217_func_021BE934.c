/*
 * function: func_021BE934
 * address:  0x021BE934
 * packet:   pkt_ov217_021BE934
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021BEB6C  0x021BEB6C  thumb  ov217
 *
 * Case 4 passes the context pointer through to func_021BEB6C (r0 is still
 * live), which keeps the switch value in r1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25908.h"

typedef unsigned char u8;

typedef struct E {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 pad[0x20];
} E;

extern E d_021C3AC8[];
typedef unsigned int   u32;
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_020409B4(int);
extern u32 func_021BEB6C(u32 a0);

int func_021BE934(char *p)
{
    switch (((struct Obj25908 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(int *)(p + 0x34)].a,
                      d_021C3AC8[*(int *)(p + 0x34)].b,
                      d_021C3AC8[*(int *)(p + 0x34)].c,
                      d_021C3AC8[*(int *)(p + 0x34)].d, 0xa);
        break;
    case 1:
        func_020413B0(2, 0xd, 4, 0x13, 4, 0xa);
        func_020413B0(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        func_021BEB6C((u32)p);
        break;
    }
    return func_020409B4(2);
}
