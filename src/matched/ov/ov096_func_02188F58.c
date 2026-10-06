/*
 * function: func_02188F58
 * address:  0x02188F58
 * packet:   pkt_ov096_02188F58
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 */
#include "../include/Obj06342.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 func_021D5440(u8 *p);
extern int func_021C7DAC(u8 *p, int a, int b, int c);

int func_02188F58(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int y;
    int z;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    y = func_021D5440(*(u8 * *)&((struct Obj06342 *)b)->fBC);
    z = func_021D5440(*(u8 * *)&((struct Obj06342 *)b)->fC0);
    r = func_021C7DAC((u8 *)(((struct Obj06342 *)b)->fB4), y, z, ((struct Obj06342 *)b)->f2);
    func_0218A0F4((u8 *)a, 2, r, t0, t1);
    return ((struct Obj06342 *)b)->fC4;
}
