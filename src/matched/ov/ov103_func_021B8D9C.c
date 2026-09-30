/*
 * function: func_021B8D9C
 * address: 0x021B8D9C
 * packet: pkt_ov103_021B8D9C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 */
typedef unsigned int u32;
extern int func_02035CB8(u32 *,u32 *);
int func_021B8D9C(u32 *p,u32 *out) {
 u32 x,y;
 if(func_02035CB8(&x,&y)) {
  if(x-p[0]<p[2]-p[0] && y-p[1]<p[3]-p[1]) {
   if(out) {out[0]=x;out[1]=y;}
   return 1;
  }
 }
 return 0;
}
