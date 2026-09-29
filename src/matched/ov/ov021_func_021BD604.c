/*
 * function: func_021BD604
 * address:  0x021BD604
 * packet:   pkt_ov021_021BD604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u16 func_02045A98(void);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_02045994(u32 a, void *b, u32 c);
extern int func_0201D304(u32 a, u32 b, u32 c);
extern int func_0201D42C(u32 a, u32 b);
extern void func_02045808(u32 a);

void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e)
{
    u16 buf[2];
    u32 h;

    buf[0] = b;
    buf[1] = func_02045A98();
    h = func_020457B0(2, c);
    func_02045994(h, buf, 2);
    *d = func_0201D304(h, a, 0);
    *e = func_0201D42C(h, a);
    func_02045808(h);
}
