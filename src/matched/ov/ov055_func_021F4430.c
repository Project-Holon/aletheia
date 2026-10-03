/*
 * function: func_021F4430
 * address: 0x021F4430
 * packet: pkt_ov055_021F4430
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F45A4 0x021F45A4 thumb ov055
 *   func_02045C04 0x02045C04 arm
 */
extern void func_021F45A4(unsigned short *,unsigned int);
struct Rec;
extern void func_02045C04(struct Rec *rec);
void func_021F4430(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),*(unsigned int *)(p+12)); *(unsigned int *)(p+12)=0; func_02045C04(*(void **)(p+8)); *(void **)(p+8)=0; }
