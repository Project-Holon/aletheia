/*
 * function: P_STATUS_PrintMsgToWin
 * address: 0x021D618C
 * packet: pkt_ov131_021D618C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   P_STATUS_PrintMsg 0x021D614C thumb ov131
 */
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void P_STATUS_PrintMsg(unsigned char *,int,int,int,unsigned short,unsigned short);
void P_STATUS_PrintMsgToWin(unsigned char *p,unsigned int a,int b,int c,unsigned short d,unsigned short e) {
 P_STATUS_PrintMsg(p,(int)BMP_WIN_GetBmp((struct Descriptor *)a),b,c,d,e);
}
