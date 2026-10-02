/*
 * function: func_0217F174
 * address: 0x0217F174
 * packet: pkt_ov018_0217F174
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
extern void func_0204B6F4(void *, unsigned int, unsigned int);
void func_0217F174(u8 *p)
{
    p[0x117] = 0;
    p[0x116] = 1;
    func_0204B6F4(*(void **)(p + 0x9c), 6, 1);
}
