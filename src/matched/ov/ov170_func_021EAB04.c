/*
 * function: func_021EAB04
 * address: 0x021EAB04
 * packet: pkt_ov170_021EAB04
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045334 0x02045334 arm
 */
#define WORK(p) (*(char **)((p)+0x2C))
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
void func_021EAB04(unsigned char *w) {
 unsigned i; unsigned char mask; unsigned char index;
 for(i=0;i<28;i++) {
  if(*(void **)(w+0x94+i*8)!=0) {
   mask=1<<(i&7); index=i>>3;
   if(w[0x174+index]&mask) {
    func_02045334(*(void **)(w+0x94+i*8));
    w[0x174+index]^=mask;
   }
  }
 }
}
