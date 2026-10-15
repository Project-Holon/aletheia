/*
 * function: POKELIST_HandleCommand
 * address:  0x021B8508
 * packet:   pkt_ov091_021B8508
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   PLIST_PLATE_GetLabelState  0x021BB43C  thumb  ov091
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   POKELIST_ApplySelection  0x021B7CC4  thumb  ov091
 *   POKELIST_ConfirmBattleParty  0x021B892C  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   PLIST_MENU_ButtonWinSetActive  0x021BBE5C  thumb  ov091
 *   PLIST_MENU_ButtonWinSetDecide  0x021BBE68  thumb  ov091
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern int POKELIST_IsItemMode(u32 p);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern int PLIST_PLATE_GetLabelState(int *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void POKELIST_ApplySelection(u8 *p);
extern void POKELIST_ConfirmBattleParty(u8 *p);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
extern void PLIST_MENU_ButtonWinSetActive(int h, int f);
extern void PLIST_MENU_ButtonWinSetDecide(int h, int f);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

#define W(o) (*(int *)(p + (o)))

void POKELIST_HandleCommand(u8 *p)
{
    u8 i;
    u8 k;
    int n;

    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (POKELIST_IsItemMode((u32)p) == 1) {
        BG_SYS_SetTileEntry(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            ((u8 *)W(0x280))[i + 0x49] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = PLIST_PLATE_GetLabelState((int *)(*(int *)(p + k * 4 + 0x160)));
            if (n <= 5) {
                ((u8 *)W(0x280))[n + 0x49] = k + 1;
            }
        }
    }
    switch (p[0xf]) {
    case 3:
        CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
        W(0x38) = (int)POKEPARTY_GetMember(*(void **)W(0x280), W(0x2c));
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        POKELIST_ApplySelection(p);
        return;
    case 0:
        if (POKELIST_IsItemMode((u32)p) == 1) {
            POKELIST_ConfirmBattleParty(p);
            return;
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 6;
        *(int *)(W(0x280) + 0x40) = 0;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return;
    case 1:
        if (W(0x2c) <= 5) {
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
        }
        if (POKELIST_IsItemMode((u32)p) == 1) {
            PLIST_MENU_ButtonWinSetActive(W(0x108), 0);
            PLIST_MENU_ButtonWinSetDecide(W(0x10c), 1);
            p[0xc] = 0xc;
            W(0x2c) = 7;
        } else {
            p[0xc] = 0x13;
            W(0x1e8) = W(0x1e0);
            CLACT_SetActorAnimSeq((struct Obj *)W(0x1e8), 9);
        }
        *(int *)(W(0x280) + 0x3c) = 7;
        *(int *)(W(0x280) + 0x40) = 0;
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    case 2:
        if (W(0x2c) <= 5) {
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 8;
        *(int *)(W(0x280) + 0x40) = 0;
        GFL_USE_PlaySeDefaultVolume(0x556);
        W(0x1e8) = W(0x1e4);
        CLACT_SetActorAnimSeq((struct Obj *)W(0x1e8), 8);
        return;
    }
}
