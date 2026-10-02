/*
 * function: func_021B3604
 * address: 0x021B3604
 * packet: pkt_ov013_021B3604
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B4C8C 0x021B4C8C data a4
 *   func_021B33F8 0x021B33F8 arm ov013
 */
extern short d_021B4C8C[];
extern void func_021B33F8(short *,short *,unsigned int,unsigned int);
void func_021B3604(short *a,unsigned int b,unsigned int c)
{
    func_021B33F8(a,d_021B4C8C,b,c);
}
