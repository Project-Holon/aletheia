/*
 * function: func_021BA400
 * address: 0x021BA400
 * packet: pkt_ov071_021BA400
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 */
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020403F4(unsigned);
void func_021BA400(void) {
    func_02040588(0, 0); func_02040588(2, 0);
    func_020403F4(0); func_020403F4(2);
}
