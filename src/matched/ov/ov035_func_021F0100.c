/*
 * function: func_021F0100
 * address:  0x021F0100
 * packet:   pkt_ov035_021F0100
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0100 0x021F0100 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   func_02040588 0x02040588 arm
 */

extern void func_0203FB44(int, int, int);
extern void sub_020403F4(int ch);
extern void func_02040588(int, int);

void func_021F0100(char *p)
{
    unsigned int v = *(unsigned int *)(p + 0x10);
    func_0203FB44(6, (unsigned short)v, (unsigned short)(v >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}
