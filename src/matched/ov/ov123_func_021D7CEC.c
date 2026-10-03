/*
 * function: func_021D7CEC
 * address: 0x021D7CEC
 * packet: pkt_ov123_021D7CEC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021D7CEC(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }
