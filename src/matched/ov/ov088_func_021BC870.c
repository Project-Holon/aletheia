/*
 * function: func_021BC870
 * address: 0x021BC870
 * packet: pkt_ov088_021BC870
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 */
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021BC870(unsigned char *p) { unsigned char i; for(i=0;i<2;i++) { if(i==p[0]) func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,1,3); else func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,31,4); } }
