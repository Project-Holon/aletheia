/*
 * function: func_021F4BF0
 * address: 0x021F4BF0
 * packet: pkt_ov048_021F4BF0
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020477D4 0x020477D4 arm
 *   func_02047804 0x02047804 arm
 */
extern void func_020477D4(unsigned int h,unsigned short i);
extern void func_02047804(unsigned int h,unsigned short i);
void func_021F4BF0(int *p) { if(p[1]==1) { p[1]=0; func_020477D4(p[4],*(unsigned short *)(p+5)); func_02047804(p[4],*(unsigned short *)(p+5)); } }
