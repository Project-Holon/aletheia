/*
 * function: func_021F2AD4
 * address: 0x021F2AD4
 * packet: pkt_ov029_021F2AD4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F06B8 0x021F06B8 thumb ov029
 */
typedef unsigned char u8;
extern void func_021F06B8(u8 *p, int a, int b);
void func_021F2AD4(u8 *p)
{
    if (p != 0) {
        p[0x462] = 0;
        func_021F06B8(p, 0, 0);
    }
}
