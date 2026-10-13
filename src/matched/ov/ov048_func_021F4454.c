/*
 * function: GIMMICK_OBJ_ELBOARD_AddNoticeList
 * address: 0x021F4454
 * packet: pkt_ov048_021F4454
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Post-increment in the table subscript schedules the counter update before the call.
 * symbols:
 *   FIELD_GIMMICK_GATE_FindListNewsEntry 0x021F3CB0 thumb ov048
 *   GIMMICK_OBJ_ELBOARD_AddNoticeMessage 0x021F440C thumb ov048
 *   gElboardNoticeLanes 0x021F4E84 data a4
 */
extern int *FIELD_GIMMICK_GATE_FindListNewsEntry(int *p);
extern void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(int *p,int *q,int i);
extern const int gElboardNoticeLanes[];
void GIMMICK_OBJ_ELBOARD_AddNoticeList(int *p) { int i; int *q; i=0; q=FIELD_GIMMICK_GATE_FindListNewsEntry(p); while(q && i<4) {GIMMICK_OBJ_ELBOARD_AddNoticeMessage(p,q,gElboardNoticeLanes[i++]);q=FIELD_GIMMICK_GATE_FindListNewsEntry(p);} }
