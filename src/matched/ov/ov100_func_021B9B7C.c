/*
 * function: func_021B9B7C
 * address: 0x021B9B7C
 * packet: pkt_ov100_021B9B7C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9AD8 0x021B9AD8 thumb ov100
 */
extern int func_020399A8(void);
extern int func_02039CB4(int,int,int);
extern int func_0201A918(void);
extern int func_0203D3F8(int,int,int,int,int,int,int,int);
extern int func_02039C68(int,int,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9AD8(void);
void func_021B9B7C(int a)
{
 int k=12;
 if(func_02039CB4(func_020399A8(),0x7e,k)!=0) {
  int p=func_020399A8();
  int q=func_0201A918();
  if(func_0203D3F8(p,0xff,0xc02,q,(*(int **)(a+0x244))[1],0,0,1)!=0) {
   func_02039C68(func_020399A8(),0x7a,k);
   func_021B95B8(a,func_021B9AD8);
  }
 }
}
