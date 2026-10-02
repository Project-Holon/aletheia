/*
 * function: func_021BB890
 * address: 0x021BB890
 * packet: pkt_ov093_021BB890
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB830 0x021BB830 thumb ov093
 */
typedef unsigned char u8;
extern int func_021BB830(u8 *);
int func_021BB890(u8 *p, unsigned int i) { if (i < 4) return func_021BB830(p+20+i*12); return 0; }
