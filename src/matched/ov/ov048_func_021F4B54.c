/*
 * function: func_021F4B54
 * address: 0x021F4B54
 * packet: pkt_ov048_021F4B54
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020477A4 0x020477A4 arm
 *   func_02047804 0x02047804 arm
 */
extern unsigned int func_020477A4(void *h,unsigned int i);
extern void func_02047804(unsigned int h,unsigned short i);
void func_021F4B54(int *p) { if(p[1]!=1) { p[1]=1; p[2]=0; p[6]=0; func_020477A4((void *)p[4],*(unsigned short *)(p+5)); func_02047804(p[4],*(unsigned short *)(p+5)); } }
