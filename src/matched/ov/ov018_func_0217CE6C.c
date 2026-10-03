/*
 * function: func_0217CE6C
 * address:  0x0217CE6C
 * packet:   pkt_ov018_0217CE6C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_02184D38  0x02184D38  thumb  ov020
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V12;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u8 *func_02158344();
extern u32 *func_0217BEA8(u16);
extern void *func_02184D38(void *, void *, u16, V12 *, int, int);

void *func_0217CE6C(void *a0, void *a1, int a2)
{
    u8 *p;
    u32 *q;
    V12 v;
    u16 s;

    p = func_02158344(func_02012138(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = func_0217BEA8(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = (*q << 2) >> 22;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return func_02184D38(a0, a1, s, &v, 0, 0);
}
