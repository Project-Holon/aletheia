/*
 * function: func_021BADB0
 * address: 0x021BADB0
 * packet: pkt_ov100_021BADB0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D158 0x0203D158 arm
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAD78 0x021BAD78 thumb ov100
 *   func_021BB058 0x021BB058 thumb ov100
 */
typedef unsigned char u8;
extern int func_0203D158(void);
extern int func_020279E8(int);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(int),func_02041B6C(int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021BAD78(void),func_021BB058(void);
void func_021BADB0(int a) {
 if(func_0203D158()!=0) { func_021B95B8(a,func_021BAD78); return; }
 if(func_020279E8(*(int *)(a+0xcc0))!=0) {
  func_02027A04(*(const u8 **)(a+0xcc0));
  func_02027858(*(int *)(a+0xcc0));
  *(int *)(a+0xcc0)=0;
  func_02041B6C(6);
  func_021B95B8(a,func_021BB058);
 }
}
