/*
 * function: func_021D5CF8
 * address: 0x021D5CF8
 * packet: pkt_ov123_021D5CF8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C5C38 0x021C5C38 arm ov114
 */
extern int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
int func_021D5CF8(char *p){int ok=1;*(int *)(p+0xb0)=0;*(int *)(p+0xcc)=1;*(int *)(p+0xd0)=0;if(!func_021C5C38(p,0,1))ok=0;return ok;}
