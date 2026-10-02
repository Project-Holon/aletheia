/*
 * function: func_021B9930
 * address: 0x021B9930
 * packet: pkt_ov068_021B9930
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9FC0 0x021B9FC0 thumb ov068
 *   func_021B9BD0 0x021B9BD0 thumb ov068
 */
typedef unsigned char u8;
extern void func_021B9FC0(u8 *);
extern void func_021B9BD0(u8 *);
void func_021B9930(u8 *p)
{
    func_021B9FC0(p + 0x7c);
    func_021B9BD0(p);
}
