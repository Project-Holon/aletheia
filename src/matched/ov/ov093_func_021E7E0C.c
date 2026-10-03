/*
 * function: func_021E7E0C
 * address:  0x021E7E0C
 * packet:   pkt_ov093_021E7E0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word func_021E8940(int v);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);
extern void func_021E3C5C(int a, int c, int d);

void func_021E7E0C(int a, int b, int c, int d)
{
    Word t = func_021E8940(1);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 10, t, 0xa2);
    func_021E3C5C(b, c, 1);
}
