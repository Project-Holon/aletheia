/*
 * function: GSYNC_MENU_StateWaitTouchAfterMessage
 * address: 0x021D4AFC
 * packet: pkt_ov123_021D4AFC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_UpdateMessageStream 0x021D4E7C thumb ov123
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GSYNC_MENU_DeleteMessageWindow 0x021D4E64 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GSYNC_MENU_SetPaletteFade 0x021D4D40 thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StateSetupButtons 0x021D4A04 thumb ov123
 */
#include "../include/Obj00273.h"
typedef unsigned int u32;
extern int GSYNC_MENU_UpdateMessageStream(char *);
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned char  u8;
extern void GSYNC_MENU_DeleteMessageWindow(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GSYNC_MENU_SetPaletteFade(char *, int);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_StateSetupButtons(char *);
void GSYNC_MENU_StateWaitTouchAfterMessage(char *p)
{
    if (GSYNC_MENU_UpdateMessageStream(p) != 0 && TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MENU_DeleteMessageWindow((u8 *)p);
        ((struct Obj00273 *)p)->f27C = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        GSYNC_MENU_SetPaletteFade(p, 0);
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateSetupButtons, 0x360);
    }
}
