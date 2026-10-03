/*
 * function: func_021BF3D4
 * address: 0x021BF3D4
 * packet: pkt_ov110_021BF3D4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BAD20 0x021BAD20 thumb ov110
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BAD20(u8 *,unsigned);
extern unsigned func_021BEDD0(u8 *);
int func_021BF3D4(u8 *p,u8 *q) {
 if(*(u16 *)q<*(u16 *)(q+2)) {
  *(u16 *)q=func_021BAD20(p,*(u16 *)(q+2));
  *(int *)(q+8)=0;
  if((int)func_021BEDD0(q)<*(u16 *)(q+4)-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}
