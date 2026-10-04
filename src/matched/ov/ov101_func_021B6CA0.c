/*
 * unit: yes
 * function: func_021B6CA0, func_021B6CF8
 * address: 0x021B6CA0
 * packet: pkt_ov101_021B6CA0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * d_021B753C 0x021B753C data a1
 */
typedef unsigned short u16;
extern char d_021B753C[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(int,int,unsigned);
extern void func_020307B0(void *p);
int func_021B6CA0(unsigned a,int *p) {
 int q;
 q=(int)func_02030734(a,0x14,0,d_021B753C,0x36e);
 func_02082BCC(q,0,0x14);
 *(int *)q=*(int *)p[4];
 *(int *)(q+4)=p[0];
 *(int *)(q+0x10)=p[15];
 if(p[13]==1) {
  *(int *)(q+8)=0;
  p[13]=0;
 } else {
  if(p[14]!=0) {
   p[14]=0;
   *(int *)(q+8)=2;
  } else *(int *)(q+8)=1;
 }
 return q;
}
void func_021B6CF8(int p,int q) {
 *(int *)(q+0x20)=*(int *)(p+0xc);
 func_020307B0((void *)p);
}
