/*
 * function: func_021F4458
 * address: 0x021F4458
 * packet: pkt_ov055_021F4458
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F45A4 0x021F45A4 thumb ov055
 */
extern void func_021F45A4(unsigned short *,unsigned int);
void func_021F4458(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),*(unsigned int *)(p+12)); }
