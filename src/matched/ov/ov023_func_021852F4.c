/*
 * function: func_021852F4
 * address: 0x021852F4
 * packet: pkt_ov023_021852F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned short u16;
extern void func_0204B878(void *p, u16 value);
void func_021852F4(void *p, int flag)
{
    if (flag == 1)
        func_0204B878(p, 9);
    else
        func_0204B878(p, 1);
}
