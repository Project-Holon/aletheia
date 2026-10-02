/*
 * function: func_021D78E4
 * address: 0x021D78E4
 * packet: pkt_ov093_021D78E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0448 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
extern unsigned char d_021F0448[][2];
extern unsigned int _u32_div_f(unsigned int, unsigned int);
unsigned short func_021D78E4(unsigned short a, int i) { return _u32_div_f((unsigned short)(a*d_021F0448[i][0]), d_021F0448[i][1]); }
