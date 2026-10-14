/*
 * function: GSYNC_MENU_StateOpenConfirmMenu
 * address: 0x021D50F8
 * packet: pkt_ov123_021D50F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GSYNC_MENU_UpdateMessageStream 0x021D4E7C thumb ov123
 *   GSYNC_MENU_OpenYesNoMenu 0x021D4DA4 thumb ov123
 *   GSYNC_MENU_StateConfirmSelect 0x021D504C thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 */
extern int GSYNC_MENU_UpdateMessageStream(char *);
extern void GSYNC_MENU_OpenYesNoMenu(char *);
extern void GSYNC_MENU_StateConfirmSelect(char *);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
void GSYNC_MENU_StateOpenConfirmMenu(char *p){if(GSYNC_MENU_UpdateMessageStream(p)){GSYNC_MENU_OpenYesNoMenu(p);GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateConfirmSelect,0x536);}}
