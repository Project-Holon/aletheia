/*
 * unit:     yes
 * function: POKELIST_ShowLearnMoveResult, POKELIST_OpenTakeItemMenu
 * address:  0x021BA004
 * packet:   pkt_ov091_021BA004
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
 *   POKELIST_ApplyItemEffect  0x021BA60C  thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb ov091
 *   POKELIST_ReplaceMoveSlot  0x021BA5E0  thumb ov091
 *   PLIST_MENU_SkipToMoveLearn  0x021BC6C0  thumb ov091
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb ov091
 *   POKELIST_OpenChoiceMenu  0x021B9804  thumb ov091
 *   POKELIST_OnTakeItemChoice  0x021BA0A8  thumb ov091
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
extern void POKELIST_ApplyItemEffect(u8 *p, void *q);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_ReplaceMoveSlot(u8 *p, void *q, u32 slot);
extern void PLIST_MENU_SkipToMoveLearn(char *p);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_OpenChoiceMenu(u8 *p, int a1);
extern void POKELIST_OnTakeItemChoice(u8 *p, int action);

void POKELIST_ShowLearnMoveResult(u8 *p)
{
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
    PLIST_MESSAGE_SetWordSetPokemon((int)p, W(0x150), 0, W(0x38));
    PLIST_MESSAGE_SetWordSetMove((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
        POKELIST_ShowMessage(p, 0x29, 1, (int)PLIST_MENU_SkipToMoveLearn);
    } else {
        POKELIST_ShowMessage(p, 0x29, 1, (int)POKELIST_EndMessageToExit);
        POKELIST_ApplyItemEffect(p, (void *)W(0x38));
        *(u32 *)(W(0x280) + 0x40) = 10;
    }
    PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
    POKELIST_ReplaceMoveSlot(p, (void *)W(0x38), *(u8 *)(W(0x280) + 0x48));
}

void POKELIST_OpenTakeItemMenu(u8 *p)
{
    POKELIST_OpenChoiceMenu(p, (int)POKELIST_OnTakeItemChoice);
}
