/*
 * function: func_021B6844
 * address: 0x021B6844
 * packet: pkt_ov180_021B6844
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: d.a=2 before d.g=d.a<<21 shares the stored constant's register; literal 0x400000 was two bytes longer.
 * symbols:
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 */
typedef struct { int a,b,c,d,e,f,g,h; } Desc;
extern int func_02051758(int a0); extern void func_02051648(void *,Desc *,unsigned short,void *,void *,void *,unsigned);
void func_021B6844(char *p,void *q,int mode) {
 Desc d;
 if(q!=0) {
  if(mode==1) { d.b=0x4000; d.c=-0x4000; } else { d.b=0xE000; d.c=0x6000; }
  d.d=-0x5548; d.e=0x5548; d.a=2; d.g=d.a<<21;
  d.f=0; d.h=0;
  func_02051758((int)q);
  func_02051648(q,&d,0x2000,0,0,0,141);
 }
}
