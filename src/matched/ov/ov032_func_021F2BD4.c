/*
 * function: func_021F2BD4
 * address:  0x021F2BD4
 * packet:   pkt_ov032_021F2BD4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2BD4 0x021F2BD4 thumb
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 */

extern void func_02040588(unsigned, unsigned);
extern void func_020403F4(unsigned);

void func_021F2BD4(char *p)
{
    unsigned short z = 0;

    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    *(volatile unsigned short *)0x04001050 = z;
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}
