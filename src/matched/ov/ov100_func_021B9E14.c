/*
 * function: func_021B9E14
 * address: 0x021B9E14
 * packet: pkt_ov100_021B9E14
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9EF8 0x021B9EF8 thumb ov100
 */
struct Word { int x; };
extern void func_021BA5F4(unsigned);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA290(int,int);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B9EF8(int a);
void func_021B9E14(unsigned a)
{
 struct Word x;
 func_021BA5F4(a);
 x.x=*(int *)(a+0xcb0);
 func_021BA3A4(&x,a);
 func_021BA290(a,0);
 func_021B95B8((unsigned char *)a,(unsigned)func_021B9EF8);
}
