/*
 * function: func_021F0D9C
 * address: 0x021F0D9C
 * packet: pkt_ov032_021F0D9C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02028148 0x02028148 thumb
 */
extern void func_02028148(unsigned char *);
void func_021F0D9C(char *p) { int i; for(i=0;i<2;i++) { func_02028148(*(unsigned char **)(p+i*16+0xf0)); *(unsigned *)(p+i*16+0xf0)=0; } }
