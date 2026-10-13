/*
 * function: P_STATUS_PrintWordSetMsgRightToWin
 * address: 0x021D62B4
 * packet: pkt_ov131_021D62B4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   P_STATUS_PrintWordSetMsgRight 0x021D6244 thumb ov131
 */
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void P_STATUS_PrintWordSetMsgRight(unsigned char *,int,void *,int,unsigned short,unsigned short,unsigned short);
void P_STATUS_PrintWordSetMsgRightToWin(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 P_STATUS_PrintWordSetMsgRight(p,(int)BMP_WIN_GetBmp((struct Descriptor *)a),b,c,d,e,f);
}
