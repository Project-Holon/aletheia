/*
 * function: func_021F5494
 * address: 0x021F5494
 * packet: pkt_ov194_021F5494
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045A98 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02045A98(void);
int func_021F5494(const u16 *a,const u16 *b) {int i;for(i=0;i<32;i++){if(a[i]!=b[i])return 0;if(a[i]==func_02045A98() && b[i]==func_02045A98())return 1;}return 0;}
