/*
 * function: P_STATUS_PrintWordSetMsgToWin
 * address: 0x021D6214
 * packet: pkt_ov131_021D6214
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   P_STATUS_PrintWordSetMsg 0x021D61B8 thumb ov131
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void P_STATUS_PrintWordSetMsg(unsigned char *,int,void *,int,unsigned short,unsigned short,unsigned short);
void P_STATUS_PrintWordSetMsgToWin(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 P_STATUS_PrintWordSetMsg(p,(int)func_02045770((struct Descriptor *)a),b,c,d,e,f);
}
