/*
 * function: func_021E53E4
 * address:  0x021E53E4
 * packet:   pkt_ov093_021E53E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 *
 * symbols:
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word func_021E8940(int k);
extern int func_021B9A40(int a);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);

void func_021E53E4(int a, int b, int c, int d)
{
    Word t = func_021E8940(4);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 4, t, 0x8c);
}
