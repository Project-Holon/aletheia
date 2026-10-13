/*
 * function: ITEMMENU_TaskOpenActionMenu
 * address: 0x021B7584
 * packet: pkt_ov070_021B7584
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_IsMessageFinished 0x021BADF0 thumb ov070
 *   ITEMMENU_OpenYesNoList 0x021BB0F8 thumb ov070
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskActionMenuInput 0x021B7504 thumb ov070
 */

extern int ITEMMENU_IsMessageFinished(int p);
extern void ITEMMENU_OpenYesNoList(int p);
extern void ITEMMENU_SetTask(char *p, int k);
struct Obj;
extern void ITEMMENU_TaskActionMenuInput(struct Obj *o);
void ITEMMENU_TaskOpenActionMenu(int p) { if (ITEMMENU_IsMessageFinished(p)) { ITEMMENU_OpenYesNoList(p); ITEMMENU_SetTask((void *)p,(int)((void *)ITEMMENU_TaskActionMenuInput)); } }
