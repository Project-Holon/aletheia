/*
 * function: func_021C7AE4
 * address:  0x021C7AE4
 * packet:   pkt_ov021_021C7AE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: DIFF only in the V copy into x->f1C. Original loads v->x
 * before the x->fC store and interleaves (ldr x; str fC; ldr y; str x; ldr z;
 * str y; str z). Inline set3(d, x, y, z) (which matched the sibling
 * func_021C754C) gives the right colouring but loads z,y,x after the fC store;
 * element-wise / struct copy / reversed helper all tried, none interleave.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7B1C  0x021C7B1C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u32 func_02188C84(u32 a);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern void *func_021C6CCC(Q *q);
typedef struct { u8 f0; u32 f4; u32 f8; u32 fC; u8 pad[0xc]; V f1C; } X;
extern int func_021C7B1C(X *x);
static inline void set3(V *d, u32 x, u32 y, u32 z) { d->x = x; d->y = y; d->z = z; }
Q *func_021C7AE4(u32 a, u32 b, V *v)
{
    Q *q = func_021C6C70(func_02188C84(a), 0x28, func_021C7B1C);
    X *x = func_021C6CCC(q);
    x->f0 = 0;
    x->f4 = a;
    x->f8 = 0;
    x->fC = b;
    set3(&x->f1C, v->x, v->y, v->z);
    return q;
}
