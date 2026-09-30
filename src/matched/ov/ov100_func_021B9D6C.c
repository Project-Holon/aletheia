/*
 * function: func_021B9D6C
 * address: 0x021B9D6C
 * packet: pkt_ov100_021B9D6C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02008468 0x02008468 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9CC4 0x021B9CC4 thumb ov100
 */
extern int func_020399A8(void);
extern int func_02008468(void);
extern int func_02012944(int);
extern int func_0203D3A8(int,int,unsigned short,int);
extern int func_02039C68(int,int,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9CC4(void);
void func_021B9D6C(int a) {
 int p=func_020399A8();
 int k=func_02008468();
 int v=func_02012944(**(int **)(a+0x244));
 if(func_0203D3A8(p,0xc01,k,v)!=0) {
  func_02039C68(func_020399A8(),0x7b,12);
  func_021B95B8(a,func_021B9CC4);
 }
}
