/*
 * function: func_021BA64C
 * address: 0x021BA64C
 * packet: pkt_ov100_021BA64C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *);
void func_021BA64C(unsigned a,unsigned b)
{
 if(*(unsigned *)(a+0x2c8+b*4)!=0) {
  func_0204B3B4(*(struct Obj **)(a+0x2c8+b*4));
  *(unsigned *)(a+0x2c8+b*4)=0;
 }
}
