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
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
void func_021BA64C(unsigned a,unsigned b)
{
 if(*(unsigned *)(a+0x2c8+b*4)!=0) {
  CLACT_DeleteActor(*(struct Obj **)(a+0x2c8+b*4));
  *(unsigned *)(a+0x2c8+b*4)=0;
 }
}
