/*
 * function: func_021544D4
 * address: 0x021544D4
 * packet: pkt_ov006_021544D4
 * region: ov006
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of alignment padding at 0x021544EE.
 * symbols:
 *   func_02005CBC 0x02005CBC thumb
 *   func_02006734 0x02006734 thumb
 */
typedef unsigned char u8;
extern void func_02005CBC(int, int);
extern void func_02006734(int);
void func_021544D4(u8 *p)
{
    func_02005CBC(127, 63);
    func_02006734(127);
    *(int *)(p + 0xAC) = 1;
}
