/*
 * function: func_021BACC8
 * address: 0x021BACC8
 * packet: pkt_ov100_021BACC8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BB270 0x021BB270 thumb ov100
 */
struct Word { int x; };
extern void func_021BA5F4(unsigned a);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA290(int,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021BB270(void);
void func_021BACC8(int a) {
 struct Word x;
 func_021BA5F4(a);
 x.x=*(int *)(a+0xcb0);
 func_021BA3A4(&x,a);
 if(*(int *)(a+0x24c)==9 && *(int *)(a+0xce8)>0) {
  func_021BA290(a,1);
  func_021B95B8(a,func_021BB270);
  return;
 }
 func_021BA290(a,0);
 func_021B95B8(a,func_021BB270);
}
