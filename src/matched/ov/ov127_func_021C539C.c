/*
 * function: func_021C539C
 * address: 0x021C539C
 * packet: pkt_ov127_021C539C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C5564 0x021C5564 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C49A4(u8 *,unsigned int);
extern void func_021C5564(u8 *,void *,int,int,int);
int func_021C539C(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5);  if(v==0 || v==4) { func_021C5564(out,p,*(u16 *)desc,desc[3],desc[2]); return 1; } return 0; }

