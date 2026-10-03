/*
 * function: func_021D7DE8
 * address: 0x021D7DE8
 * packet: pkt_ov123_021D7DE8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D7D18 0x021D7D18 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D7D18(u8 *,int,int,int,int,int,int);
void func_021D7DE8(u8 *p,int a,u8 *records) { int i; u8 *r; for(i=0;i<10;i++) { r=records+i*8; if(*(u16 *)(r+4)==0) break; func_021D7D18(p,a,*(u16 *)(r+4),r[9],r[8],*(u16 *)(r+6),r[10]); } }
