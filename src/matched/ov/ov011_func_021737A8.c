/*
 * function: func_021737A8
 * address: 0x021737A8
 * packet: pkt_ov011_021737A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
extern int func_021736D8(void);
extern unsigned int func_020399A8(void);
extern int func_0203D3A8(unsigned int, unsigned int, unsigned int, unsigned int);
int func_021737A8(void)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3A8(func_020399A8(), 0x202, 0, 0);
}
