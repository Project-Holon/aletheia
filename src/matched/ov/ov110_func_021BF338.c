/*
 * function: func_021BF338
 * address: 0x021BF338
 * packet: pkt_ov110_021BF338
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_021BF338(u8 *p) {
 if(*(u16 *)p!=0) {
  if(*(u16 *)p>=6) { *(u16 *)p-=6; *(int *)(p+8)=-6; }
  else { *(int *)(p+8)=-*(u16 *)p; *(u16 *)p=0; }
  return 2;
 }
 return 4;
}
