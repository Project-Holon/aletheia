/*
 * unit:     yes
 * function: func_021C77D8, func_021C77FC
 * address:  0x021C77D8
 * packet:   pkt_ov021_021C77D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern void *func_021C6CCC(Q *q);
typedef struct { u16 f0; u16 f2; } X;
int func_021C77FC(X *x);
Q *func_021C77D8(u32 a, u16 b)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 4, func_021C77FC);
    X *x = func_021C6CCC(q);
    x->f0 = 0;
    x->f2 = b;
    return q;
}

int func_021C77FC(X *x)
{
    x->f0++;
    if (x->f2 <= x->f0)
        return 1;
    return 0;
}
