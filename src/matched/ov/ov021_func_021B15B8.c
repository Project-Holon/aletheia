/*
 * function: func_021B15B8
 * address:  0x021B15B8
 * packet:   pkt_ov021_021B15B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113D0  0x020113D0  thumb
 *   func_021B1550  0x021B1550  thumb  ov021
 */

typedef unsigned int u32;

extern void func_020113D0(char *p, int val);
extern int func_021B1550(int a, int b);

int func_021B15B8(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B1550);
    return 1;
}
