/*
 * function: func_021B9A24
 * address: 0x021B9A24
 * packet: pkt_ov093_021B9A24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9A40 0x021B9A40 thumb ov093
 */
extern unsigned char func_021B9A40(unsigned int);
int func_021B9A24(unsigned int a, unsigned int b)
{
    unsigned char v = func_021B9A40(a);
    if (v == func_021B9A40(b)) return 1;
    return 0;
}
