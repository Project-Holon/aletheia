/*
 * function: GSYNC_MENU_StateOpenYesNoAfterMessage
 * address: 0x021D44F4
 * packet: pkt_ov123_021D44F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_UpdateMessageStream 0x021D4E7C thumb ov123
 *   GSYNC_MENU_OpenYesNoMenu 0x021D4DA4 thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StateWaitMenuSelect 0x021D449C thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GSYNC_MENU_UpdateMessageStream(char *);
extern void GSYNC_MENU_OpenYesNoMenu(char *);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
extern void GSYNC_MENU_StateWaitMenuSelect(char *);
void GSYNC_MENU_StateOpenYesNoAfterMessage(char *p) { if(GSYNC_MENU_UpdateMessageStream(p)) { GSYNC_MENU_OpenYesNoMenu(p); GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateWaitMenuSelect,0x1c9); } }
