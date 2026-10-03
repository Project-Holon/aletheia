/*
 * function: func_021D7E20
 * address: 0x021D7E20
 * packet: pkt_ov123_021D7E20
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6AA8 0x021D6AA8 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D6AA8(char *,int,u16);
void func_021D7E20(u8 *p,u8 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)(list+92+i*2); if(n!=0 && list[132+i]!=0 && n<=626) func_021D6AA8(*(char **)(p+20),i,n); } }
