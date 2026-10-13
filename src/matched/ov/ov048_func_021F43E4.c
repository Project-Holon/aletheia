/*
 * function: GIMMICK_OBJ_ELBOARD_AddNoticeMessages
 * address: 0x021F43E4
 * packet: pkt_ov048_021F43E4
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_GIMMICK_GATE_FindNewsEntry 0x021F3C2C thumb ov048
 *   GIMMICK_OBJ_ELBOARD_AddNoticeMessage 0x021F440C thumb ov048
 *   GIMMICK_OBJ_ELBOARD_AddNoticeList 0x021F4454 thumb ov048
 */
typedef unsigned char u8;
extern u8 *FIELD_GIMMICK_GATE_FindNewsEntry(u8 *p);
extern void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(int *p,int *q,int i);
extern void GIMMICK_OBJ_ELBOARD_AddNoticeList(int *p);
void GIMMICK_OBJ_ELBOARD_AddNoticeMessages(int *p) { int *q; q=(int *)FIELD_GIMMICK_GATE_FindNewsEntry((u8 *)p); switch(q[4]) {case 0:GIMMICK_OBJ_ELBOARD_AddNoticeMessage(p,q,3);break;case 2:GIMMICK_OBJ_ELBOARD_AddNoticeList(p);break;} }
