/*
 * function: func_02185B88
 * address: 0x02185B88
 * packet: pkt_ov020_02185B88
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 */
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(unsigned int *, unsigned int);
void func_02185B88(void *p, unsigned int v)
{
    func_0216DAC8(func_021A3074(func_02188CB4(p)), v);
}
