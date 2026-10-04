/*
 * function: func_021BA454
 * address: 0x021BA454
 * packet: pkt_ov100_021BA454
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes at 0x021BA52E.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern int func_020450F0(int,int,int,int,unsigned char,unsigned char,unsigned char),func_0201283C(int),func_02009A34(int);
extern void func_02045374(int),func_0201F73C(int,int,unsigned short,int),func_02043B5C(int,int),func_02045CAC(int,int,int),func_0201EFA4(int,int,int,int,int,int),func_0201F250(int,int,int),func_0201C7A4(int,short,short,int,int),func_02045334(struct Descriptor *);
void func_021BA454(int text,int a) {
 if(*(int *)(a+0x280)==0) {
  int v=func_020450F0(5,1,8,18,4,13,0);
  *(int *)(a+0x280)=v;
  func_02045374(v);
  func_0201F73C(*(int *)(a+0x280),0,*(int *)(a+0x304),14);
 }
 func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)(a+0x280)),255);
 func_02045CAC(*(int *)(a+0x288),text,*(int *)(a+0x294));
 func_0201EFA4(*(int *)(a+0x28c),0,func_02009A34(func_0201283C(**(int **)(a+0x244))),2,1,1);
 func_0201EFA4(*(int *)(a+0x28c),1,32,2,1,1);
 func_0201F250(*(int *)(a+0x28c),*(int *)(a+0x298),*(int *)(a+0x294));
 func_0201C7A4((int)func_02045770((struct Descriptor *)*(int *)(a+0x280)),0,2,*(int *)(a+0x298),*(int *)(a+0x290));
 func_02045334((struct Descriptor *)*(int *)(a+0x280));
}
