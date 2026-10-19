/*
 * unit:     yes
 * function: POKELIST_OnGiveUpMoveChoice, POKELIST_OpenForgetMoveMenu
 * address:  0x021B9EC0
 * packet:   pkt_ov091_021B9EC0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb ov091
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove  0x021BB9CC  thumb ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb ov091
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb ov091
 *   POKELIST_OpenForgetMoveMenu  0x021B9F34  thumb ov091
 *   POKELIST_OpenChoiceMenu  0x021B9804  thumb ov091
 *   POKELIST_OnForgetMoveChoice  0x021B9F44  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetMove(int a, int b, int c, int d);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_OpenForgetMoveMenu();
extern void POKELIST_OpenChoiceMenu(u8 *p, int a1);
extern void POKELIST_OnForgetMoveChoice(u8 *p, u32 state);

void POKELIST_OnGiveUpMoveChoice(u8 *p, u32 state)
{
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (state == 14) {
        u32 *q = (u32 *)W(0x280);
        if (q[0x34 / 4] == 5 || q[0x34 / 4] == 8) {
            q[0x40 / 4] = 5;
        } else {
            q[0x40 / 4] = 4;
        }
        POKELIST_ShowMessage(p, 0x27, 1, (int)POKELIST_EndMessageToExit);
        return;
    }
    PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
    PLIST_MESSAGE_SetWordSetMove((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    POKELIST_ShowMessage(p, 0x23, 0, (int)POKELIST_OpenForgetMoveMenu);
    PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
}

void POKELIST_OpenForgetMoveMenu(u8 *p)
{
    POKELIST_OpenChoiceMenu(p, (int)POKELIST_OnForgetMoveChoice);
}
