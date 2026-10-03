/*
 * function: func_021B99D4
 * address: 0x021B99D4
 * packet: pkt_ov100_021B99D4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 */
extern int func_02035C60(void);
extern void func_021B95C0(unsigned);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B96B8(void);
void func_021B99D4(unsigned a)
{
 if(func_02035C60()!=0) {
  func_021B95C0(a);
  func_021B95B8((unsigned char *)a,(unsigned)func_021B96B8);
 }
}
