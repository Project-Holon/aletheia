/*
 * function: ITEMMENU_TaskStartRegisterResult
 * address: 0x021B761C
 * packet: pkt_ov070_021B761C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_IsMessageFinished 0x021BADF0 thumb ov070
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskRegisterResultMessage 0x021B75A4 thumb ov070
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */

extern int ITEMMENU_IsMessageFinished(int p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);
extern void ITEMMENU_SetTask(char *p, int k);
struct Obj;
extern void ITEMMENU_TaskRegisterResultMessage(struct Obj *o);
void ITEMMENU_TaskStartRegisterResult(int p) { if (ITEMMENU_IsMessageFinished(p)) { GFL_USE_PlaySeDefaultVolume(0x55C); ITEMMENU_SetTask((void *)p,(int)((void *)ITEMMENU_TaskRegisterResultMessage)); } }
