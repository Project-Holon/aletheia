/*
 * function: func_021D7CB4
 * address: 0x021D7CB4
 * packet: pkt_ov123_021D7CB4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02009348 0x02009348 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02009348(int,int,u16,u8);
int func_021D7CB4(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) { func_02009348(a,i,n,p[132+i]); result=1; } } return result; }
