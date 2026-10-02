/*
 * function: func_021751B4
 * address: 0x021751B4
 * packet: pkt_ov012_021751B4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The flag address groups base plus index before the constant offset.
 */
typedef unsigned char u8;
typedef struct { int w[5]; } E;
void func_021751B4(u8 *p, int i, const E *src)
{
    *(E *)(p + 0xe0 + i * 20) = *src;
    (p + i)[0x130] = 1;
}
