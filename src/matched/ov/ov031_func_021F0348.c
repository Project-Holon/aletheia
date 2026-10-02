/*
 * function: func_021F0348
 * address: 0x021F0348
 * packet: pkt_ov031_021F0348
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 */
extern void func_02040588(unsigned char, unsigned int);
extern void func_020403F4(unsigned int);
void func_021F0348(void)
{
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}
