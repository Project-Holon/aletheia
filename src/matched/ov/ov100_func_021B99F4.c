/*
 * function: func_021B99F4
 * address: 0x021B99F4
 * packet: pkt_ov100_021B99F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B99D4 0x021B99D4 thumb ov100
 */
extern int func_0203CEAC(int);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B99D4(unsigned a);
void func_021B99F4(unsigned a)
{
 if(++*(int *)(a+0xcac)>60) {
  func_0203CEAC(0);
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99D4);
 }
}
