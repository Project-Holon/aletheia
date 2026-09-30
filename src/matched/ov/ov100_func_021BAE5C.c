/*
 * function: func_021BAE5C
 * address: 0x021BAE5C
 * packet: pkt_ov100_021BAE5C
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
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BADFC 0x021BADFC thumb ov100
 *   func_021BAE14 0x021BAE14 thumb ov100
 */
typedef unsigned char u8;
extern int func_020279E8(int);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(int),func_02041B6C(int),func_021BA5F4(int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021BADFC(void),func_021BAE14(void);
void func_021BAE5C(int a) {
 if(func_020279E8(*(int *)(a+0xcc0))!=0) {
  int v=func_02027A04(*(const u8 **)(a+0xcc0));
  func_02027858(*(int *)(a+0xcc0));
  *(int *)(a+0xcc0)=0;
  if(v==0) {
   func_021BA5F4(a); func_02041B6C(6); func_021B95B8(a,func_021BADFC); return;
  } else { func_021BA5F4(a); func_021B95B8(a,func_021BAE14); }
 }
}
