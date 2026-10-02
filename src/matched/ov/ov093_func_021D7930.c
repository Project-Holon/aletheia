/*
 * function: func_021D7930
 * address: 0x021D7930
 * packet: pkt_ov093_021D7930
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F041C 0x021F041C data a1
 *   func_021D78AC 0x021D78AC thumb ov093
 */
extern unsigned char d_021F041C[];
extern unsigned int func_021D78AC(unsigned int);
int func_021D7930(int i) { if ((unsigned char)func_021D78AC(d_021F041C[i]) == 0) return 1; return 0; }
