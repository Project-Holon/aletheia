/*
 * function: func_021BA668
 * address: 0x021BA668
 * packet: pkt_ov100_021BA668
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA454 0x021BA454 thumb ov100
 *   func_021BA530 0x021BA530 thumb ov100
 *   func_0201283C 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   d_021BB694 0x021BB694 data a4
 *   d_021BB690 0x021BB690 data a4
 *   d_021BB670 0x021BB670 data a4
 *   d_021BB680 0x021BB680 data a4
 *   d_021BB684 0x021BB684 data a4
 *   d_021BB67C 0x021BB67C data a4
 *   d_021BB66C 0x021BB66C data a4
 *   d_021BB6A0 0x021BB6A0 data a4
 *   d_021BB698 0x021BB698 data a4
 */
struct Word { int x; };
extern const struct Word d_021BB694,d_021BB690,d_021BB670,d_021BB680,d_021BB684,d_021BB67C,d_021BB66C,d_021BB6A0,d_021BB698;
extern void func_021BA3A4(struct Word *,int),func_021BA454(int,int),func_021BA530(int,int);
extern int func_0201283C(int),func_02009A34(int);
void func_021BA668(int a) {
 if(*(int *)(a+0xca0)==1) {struct Word t=d_021BB694;func_021BA3A4(&t,a);return;}
 if(*(int *)(a+0x24c)==7) {
  if(func_02009A34(func_0201283C(**(int **)(a+0x244)))==32) {struct Word t=d_021BB690;func_021BA3A4(&t,a);return;}
  else {struct Word t=d_021BB670;func_021BA3A4(&t,a);func_021BA454(0x22,a);return;}
 }
 if(*(int *)(a+0x24c)==6) {struct Word t=d_021BB680;func_021BA3A4(&t,a);return;}
 if(*(int *)(a+0x24c)==5) {struct Word t=d_021BB684;func_021BA3A4(&t,a);return;}
 if(*(int *)(a+0x24c)==9) {struct Word t=d_021BB67C;func_021BA3A4(&t,a);func_021BA530(0x27,a);return;}
 if(*(int *)(a+0x24c)==10) {struct Word t=d_021BB66C;func_021BA3A4(&t,a);return;}
 if(*(int *)(a+0x24c)==11) {struct Word t=d_021BB6A0;func_021BA3A4(&t,a);return;}
 else {struct Word t=d_021BB698;func_021BA3A4(&t,a);return;}
}
