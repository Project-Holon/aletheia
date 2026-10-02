/*
 * function: func_021D63EC
 * address: 0x021D63EC
 * packet: pkt_ov093_021D63EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D67F4 0x021D67F4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D67F4(u8 *);
void func_021D63EC(u8 *p, u16 n)
{
    *(u16 *)(p + 0x148) = n;
    *(u16 *)(p + 0x146) = 0;
    p[0x1b] |= 0x80;
    func_021D67F4(p);
}
