/*
 * function: func_021D7E84
 * address: 0x021D7E84
 * packet: pkt_ov131_021D7E84
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021D7E84(void *p,void **q) {
 unsigned char i;
 for(i=0;i<10;i++) {
  func_020452E8(q[3+i]);
 }
 func_020452E8(q[13]);
 q[1]=0;
}
