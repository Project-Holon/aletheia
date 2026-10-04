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

extern int func_02050C04(int a, int b, int c, int d);
struct Light;
extern int func_02051788(char *p);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);

u32 func_021C1A48(S *p)
{
    u32 a;
    u32 b;
    u32 o;

    p->fC = func_02050C04(p->f8, 0x4800, 1, p->f4);
    o = func_02051788((char *)p->fC);
    a = 1 << 12;
    b = 0x384000;
    func_02048B60((struct Light *)o, &a);
    func_02048B6C((struct Light *)o, &b);
    return p->fC;
}
