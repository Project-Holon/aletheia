/*
 * function: func_021C1A48
 * address:  0x021C1A48
 * packet:   pkt_ov021_021C1A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the effect instance and sets its two scale parameters.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
} S;

extern u32 func_02050C04(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02051788(u32 a);
extern void func_02048B60(u32 a, u32 *args);
extern void func_02048B6C(u32 a, u32 *args);

u32 func_021C1A48(S *p)
{
    u32 a;
    u32 b;
    u32 o;

    p->fC = func_02050C04(p->f8, 0x4800, 1, p->f4);
    o = func_02051788(p->fC);
    a = 1 << 12;
    b = 0x384000;
    func_02048B60(o, &a);
    func_02048B6C(o, &b);
    return p->fC;
}
