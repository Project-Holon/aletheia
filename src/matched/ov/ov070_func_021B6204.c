/*
 * function: func_021B6204
 * address: 0x021B6204
 * packet: pkt_ov070_021B6204
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes.
 * symbols:
 *   func_0201EF6C 0x0201EF6C thumb
 */
typedef unsigned char u8;
extern void func_0201EF6C(void *, int, unsigned int, int, int);
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d)
{
    func_0201EF6C(*(void **)(p + 0x520), a, b, c, d);
}
