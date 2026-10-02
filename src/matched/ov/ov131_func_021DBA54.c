/*
 * function: func_021DBA54
 * address: 0x021DBA54
 * packet: pkt_ov131_021DBA54
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DC2B8 0x021DC2B8 data
 *   d_021DC2B9 0x021DC2B9 data
 */
extern unsigned char d_021DC2B8[];
extern unsigned char d_021DC2B9[];
void func_021DBA54(unsigned char *p, unsigned short *o) {
 o[0] = d_021DC2B8[*p * 2] << 3;
 o[1] = d_021DC2B9[*p * 2] << 3;
}
