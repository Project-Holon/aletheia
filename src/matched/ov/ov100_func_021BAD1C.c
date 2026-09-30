/*
 * function: func_021BAD1C
 * address: 0x021BAD1C
 * packet: pkt_ov100_021BAD1C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B967C 0x021B967C thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 *   func_021BACC8 0x021BACC8 thumb ov100
 */
typedef unsigned char u8;
extern int func_020279E8(int);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(int),func_02041B6C(int),func_021BA5F4(int),func_021B95C0(int),func_021B967C(int,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B96B8(void),func_021BACC8(void);
void func_021BAD1C(int a) {
 if(func_020279E8(*(int *)(a+0xcc0))!=0) {
  int v=func_02027A04(*(const u8 **)(a+0xcc0));
  func_02027858(*(int *)(a+0xcc0));
  *(int *)(a+0xcc0)=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a); func_021B95C0(a); func_021B95B8(a,func_021B96B8);
  } else func_021B95B8(a,func_021BACC8);
  func_021B967C(a,0);
 }
}
