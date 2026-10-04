/*
 * function: func_02189170
 * address:  0x02189170
 * packet:   pkt_ov096_02189170
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */
#include "../include/Obj06343.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 func_021D5440(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);

void func_02189170(int a, int b, int c)
{
    int t;
    int w;
    int y;
    int z;
    int r;

    func_0201134C(a);
    t = func_0201134C(a);
    w = func_021D59B4(*(u8 * *)&((struct Obj06343 *)b)->fC0, 0xd);
    y = func_021D5440(*(u8 * *)&((struct Obj06343 *)b)->fBC);
    z = func_021D5440(*(u8 * *)&((struct Obj06343 *)b)->fC0);
    r = func_021C7E14((u8 *)(((struct Obj06343 *)b)->fB4), y, z, ((struct Obj06343 *)b)->f2, 1, 0);
    func_0218A0F4((u8 *)a, c, w, r, t);
}
