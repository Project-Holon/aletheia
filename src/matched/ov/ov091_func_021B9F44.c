/*
 * function: POKELIST_OnForgetMoveChoice
 * address:  0x021B9F44
 * packet:   pkt_ov091_021B9F44
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
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove  0x021BB9CC  thumb ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb ov091
 *   PLIST_MENU_SkipToMoveLearn  0x021BC6C0  thumb ov091
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb ov091
 *   POKELIST_OpenLearnMoveMenu  0x021B9EB0  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetMove(int a, int b, int c, int d);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void PLIST_MENU_SkipToMoveLearn(char *p);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_OpenLearnMoveMenu(u8 *p);

void POKELIST_OnForgetMoveChoice(u8 *p, u32 state)
{
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (state == 14) {
        *(u32 *)(W(0x280) + 0x40) = 10;
        PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p, W(0x150), 0, W(0x38));
        PLIST_MESSAGE_SetWordSetMove((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
        if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
            POKELIST_ShowMessage(p, 0x26, 1, (int)PLIST_MENU_SkipToMoveLearn);
        } else {
            POKELIST_ShowMessage(p, 0x26, 1, (int)POKELIST_EndMessageToExit);
        }
        PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
        return;
    }
    PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
    PLIST_MESSAGE_SetWordSetPokemon((int)p, W(0x150), 0, W(0x38));
    PLIST_MESSAGE_SetWordSetMove((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    POKELIST_ShowMessage(p, 0x20, 0, (int)POKELIST_OpenLearnMoveMenu);
    PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
}
