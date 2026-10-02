/*
 * function: func_02179998
 * address: 0x02179998
 * packet: pkt_ov015_02179998
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 *   func_0217A134 0x0217A134 arm ov015
 */
extern unsigned char d_0217AB80[];
extern void func_0217A134(void);
void func_02179998(void)
{
    if (d_0217AB80[0xC] == 1) func_0217A134();
    d_0217AB80[0xC] = 0;
}
