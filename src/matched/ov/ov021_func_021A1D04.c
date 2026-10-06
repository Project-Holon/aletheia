/*
 * function: func_021A1D04
 * address:  0x021A1D04
 * packet:   pkt_ov021_021A1D04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A2050  0x021A2050  thumb  ov021
 *   func_021A21B0  0x021A21B0  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01356.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u32 d_021D8868[];
struct O;
extern void func_021A2050(struct O *p, u32 a, u32 b);
extern int func_021A21B0(u8 *a0);
extern void func_021A1FEC(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);

void func_021A1D04(u8 *p, int x)
{
    u32 t;

    switch (((struct Obj01356 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A1FEC((struct O *)(((struct Obj01356 *)p)->f24), d_021D8868[((struct Obj01356 *)p)->fE * 2], 1, 1, 2,
                      ((struct Obj01356 *)p)->f10, x);
        func_021A2050((struct O *)(((struct Obj01356 *)p)->f20), 1, 2);
        ((struct Obj01356 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj01356 *)p)->f20)) == 0) {
            t = ((struct Obj01356 *)p)->f20;
            ((struct Obj01356 *)p)->f20 = ((struct Obj01356 *)p)->f24;
            ((struct Obj01356 *)p)->f24 = t;
            ((struct Obj01356 *)p)->fC = ((struct Obj01356 *)p)->fE;
            ((struct Obj01356 *)p)->fE = 0xFFFF;
            ((struct Obj01356 *)p)->f10 = 1;
            ((struct Obj01356 *)p)->fA = 0;
        }
        break;
    }
}
