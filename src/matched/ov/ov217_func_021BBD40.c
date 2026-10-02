/*
 * function: func_021BBD40
 * address: 0x021BBD40
 * packet: pkt_ov217_021BBD40
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021BC6DC 0x021BC6DC thumb ov217
 */
typedef unsigned char u8;

extern int _s32_div_f(int, int);
extern int func_021BC6DC(u8 *p);

void func_021BBD40(u8 *p, int a)
{
    int base = p[0x32];
    int x = func_021BC6DC(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % func_021BC6DC(p));
}
