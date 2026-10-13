/*
 * function: ITEMMENU_ShowMessageThenWait
 * address: 0x021B6AD8
 * packet: pkt_ov070_021B6AD8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_ShowMessage 0x021BACF0 thumb ov070
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskWaitMessage 0x021B6A14 thumb ov070
 */

extern void ITEMMENU_ShowMessage(int p, int mode);
extern void ITEMMENU_SetTask(char *p, int k);
typedef unsigned char  u8;
extern void ITEMMENU_TaskWaitMessage(u8 *p);
void ITEMMENU_ShowMessageThenWait(int p) { ITEMMENU_ShowMessage(p, 1); ITEMMENU_SetTask((void *)p, (int)((void *)ITEMMENU_TaskWaitMessage)); }
