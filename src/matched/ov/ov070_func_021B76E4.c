/*
 * function: ITEMMENU_TaskBeginReturnToList
 * address: 0x021B76E4
 * packet: pkt_ov070_021B76E4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_IsMessageFinished 0x021BADF0 thumb ov070
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskReturnToListAfterMessage 0x021B7688 thumb ov070
 */

extern int ITEMMENU_IsMessageFinished(int p);
extern void ITEMMENU_SetTask(char *p, int k);
struct Obj;
extern void ITEMMENU_TaskReturnToListAfterMessage(struct Obj *o);
void ITEMMENU_TaskBeginReturnToList(int p) { if (ITEMMENU_IsMessageFinished(p)) ITEMMENU_SetTask((void *)p,(int)((void *)ITEMMENU_TaskReturnToListAfterMessage)); }
