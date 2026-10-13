/*
 * function: P_STA_INFO_DeleteWindows
 * address: 0x021D7E84
 * packet: pkt_ov131_021D7E84
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void P_STA_INFO_DeleteWindows(void *p,void **q) {
 unsigned char i;
 for(i=0;i<10;i++) {
  BMP_WIN_Delete(q[3+i]);
 }
 BMP_WIN_Delete(q[13]);
 q[1]=0;
}
