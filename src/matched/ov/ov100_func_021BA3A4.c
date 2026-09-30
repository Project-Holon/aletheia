/*
 * function: func_021BA3A4
 * address: 0x021BA3A4
 * packet: pkt_ov100_021BA3A4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021BA452.
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
struct Word { int x; };
extern void func_02049B40(int,int,int,int,int,unsigned short);
extern int func_020450F0(int,int,int,int,unsigned char,unsigned char,unsigned char);
extern void func_02045374(int),func_0201F73C(int,int,unsigned short,int);
extern int func_02045770(int);
extern void func_02043B5C(int,int),func_02045CAC(int,int,int),func_0201C7A4(int,short,short,int,int),func_02045334(int);
void func_021BA3A4(struct Word *p,int a) {
 func_02049B40(23,5,4,0x1a0,32,*(unsigned short *)(a+0x278));
 if(*(int *)(a+0x27c)==0) {
  int v=func_020450F0(5,1,1,30,5,13,0);
  *(int *)(a+0x27c)=v;
  func_02045374(v);
  func_0201F73C(*(int *)(a+0x27c),0,*(int *)(a+0x304),14);
 }
 func_02043B5C(func_02045770(*(int *)(a+0x27c)),255);
 *(int *)(a+0xcb0)=p->x;
 func_02045CAC(*(int *)(a+0x288),p->x,*(int *)(a+0x298));
 func_0201C7A4(func_02045770(*(int *)(a+0x27c)),4,4,*(int *)(a+0x298),*(int *)(a+0x290));
 func_02045334(*(int *)(a+0x27c));
}
