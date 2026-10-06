/*
 * function: func_0217D870
 * address: 0x0217D870
 * packet: pkt_ov018_0217D870
 * region: ov018
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
extern void func_020403F4(unsigned int);
void func_0217D870(void)
{
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(6);
    func_020403F4(7);
}
