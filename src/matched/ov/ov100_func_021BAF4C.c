/*
 * function: func_021BAF4C
 * address: 0x021BAF4C
 * packet: pkt_ov100_021BAF4C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB688 0x021BB688 data a4
 *   func_02049B40 0x02049B40 arm
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA1D0 0x021BA1D0 thumb ov100
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAE5C 0x021BAE5C thumb ov100
 */
struct Word { int x; };
extern const struct Word d_021BB688;
extern void func_02049B40(int,int,int,int,int,unsigned short);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA1D0(int),func_0201DD68(void);
extern void func_021B95B8(int,void (*)(void));
extern void func_021BAE5C(void);
void func_021BAF4C(int a) {
 struct Word x=d_021BB688;
 int v=*(int *)(a+0xcb0);
 func_02049B40(23,5,4,0x180,32,*(unsigned short *)(a+0x278));
 func_021BA3A4(&x,a);
 *(int *)(a+0xcb0)=v;
 func_021BA1D0(a);
 func_0201DD68();
 func_021B95B8(a,func_021BAE5C);
}
