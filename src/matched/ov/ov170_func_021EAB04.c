/*
 * function: BOX2_SEQ_FlushDirtyBmpWins
 * address: 0x021EAB04
 * packet: pkt_ov170_021EAB04
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#define WORK(p) (*(char **)((p)+0x2C))
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void BOX2_SEQ_FlushDirtyBmpWins(unsigned char *w) {
 unsigned i; unsigned char mask; unsigned char index;
 for(i=0;i<28;i++) {
  if(*(void **)(w+0x94+i*8)!=0) {
   mask=1<<(i&7); index=i>>3;
   if(w[0x174+index]&mask) {
    BMP_WIN_TransferChars(*(void **)(w+0x94+i*8));
    w[0x174+index]^=mask;
   }
  }
 }
}
