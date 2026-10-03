/*
 * function: func_021BAF7C
 * address: 0x021BAF7C
 * packet: pkt_ov110_021BAF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
void func_021BAF7C(unsigned p,int v) { int n; *(u16 *)(p+*(u8 *)(p+0xaf0)*2+0xad4)=v; n=*(u8 *)(p+0xaf0)+1; if(n>12) n=12; else if(n<0) n=0; *(u8 *)(p+0xaf0)=n; }
