/*
 * unit:     yes
 * function: POKELIST_CheckItemUsable, POKELIST_OpenLearnMoveMenu
 * address:  0x021B9E44
 * packet:   pkt_ov091_021B9E44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKELIST_CheckBagItem  0x021BA65C  thumb ov091
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb ov091
 *   POKELIST_SetupModeScreen  0x021B7B98  thumb ov091
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb ov091
 *   PLIST_MESSAGE_SetWordSetItem  0x021BB9AC  thumb ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb ov091
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb ov091
 *   POKELIST_OpenChoiceMenu  0x021B9804  thumb ov091
 *   POKELIST_OnLearnMoveChoice  0x021B9EC0  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern u32 POKELIST_CheckBagItem(u8 *p, u16 id);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void POKELIST_SetupModeScreen(u8 *p);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetItem(int a, int b, int c, int d);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_OpenChoiceMenu(u8 *p, int a1);
extern void POKELIST_OnLearnMoveChoice(u8 *p, u32 state);

void POKELIST_CheckItemUsable(u8 *p)
{
    if (POKELIST_CheckBagItem(p, *(u16 *)(W(0x280) + 0x44))) {
        PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
        p[0xc] = 2;
        POKELIST_SetupModeScreen(p);
        return;
    }
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
    PLIST_MESSAGE_SetWordSetItem((int)p, W(0x150), 0, *(u16 *)(W(0x280) + 0x44));
    POKELIST_ShowMessage(p, 0xb3, 1, (int)POKELIST_EndMessageToExit);
    PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
}

void POKELIST_OpenLearnMoveMenu(u8 *p)
{
    POKELIST_OpenChoiceMenu(p, (int)POKELIST_OnLearnMoveChoice);
}
