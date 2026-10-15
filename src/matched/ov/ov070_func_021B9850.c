/*
 * function: ITEMMENU_DrawMoveInfo
 * address:  0x021B9850
 * packet:   pkt_ov070_021B9850
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Redraw the selected item's detail pane: hide the three detail icons and
 * the 17 list markers, then print the item's name, count or TM/HM number
 * into the three text windows at +0x73C/+0x744/+0x74C and draw its icon.
 * Twin of ITEMMENU_PrintItemList (same record getters and window helpers).
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   ITEMMENU_SetMoveTypeIconsVisible  0x021B97E8  thumb  ov070
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   FILE_UTIL_Get_12B0  0x020212B0  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemName  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_PrintToWindow  0x021BB6E0  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02021350  0x02021350  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   ITEMMENU_PrintMoveInfoText  0x021BAB04  thumb  ov070
 *   func_02020FB4  0x02020FB4  thumb
 *   ITEMMENU_FlushWindowAt  0x021BB724  thumb  ov070
 *   ITEMMENU_CreateMovingCursor  0x021B9E14  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern void *ITEMMENU_GetSlot(u8 *p, int i);
extern void ITEMMENU_SetMoveTypeIconsVisible(char *, int);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u16 FILE_UTIL_Get_12B0(u16 id);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_PrintToWindow(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02021350(u16 id);
extern u32 FILE_UTIL_GetId(u32 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void ITEMMENU_PrintMoveInfoText(u8 *p, int x);
extern void func_02020FB4(void *dst, u32 entry, u32 heap);
extern void ITEMMENU_FlushWindowAt(void **p);
extern void ITEMMENU_CreateMovingCursor(char *p, int id);

void ITEMMENU_DrawMoveInfo(char *p)
{
    u32 i;
    u32 j;
    u16 *e;
    u16 kind;
    u8 n;

    j = 0;
    for (i = 0; i < 3; i++)
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x6C0), 0);
    for (j = 0; j < 17; j++)
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + j * 4 + 0x6CC), 0);
    e = ITEMMENU_GetSlot((u8 *)p, ITEMMENU_GetCursorIndex((u8 *)p));
    if (e == 0 || *e == 0) {
        ITEMMENU_SetMoveTypeIconsVisible(p, 0);
        return;
    }
    ITEMMENU_SetMoveTypeIconsVisible(p, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f73C)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00002 *)p)->f744)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00002 *)p)->f74C)), 0);
    kind = FILE_UTIL_Get_12B0(*e);
    if (kind == 0) {
        MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x86, (void *)(((struct Obj00002 *)p)->f524));
        ITEMMENU_RegisterItemName((u8 *)p, 0, *e);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        if (((struct Obj00002 *)p)->f80C != 4) {
            MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x83, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, e[1], 3, 0, 1);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x744), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        } else {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00002 *)p)->f744);
        }
        BMP_WIN_ClearScreen((struct Descriptor *)(*(u32 *)&((struct Obj00002 *)p)->f734));
    } else {
        n = func_02021350(*e);
        if (n == 0xFF) {
            MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x45, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, FILE_UTIL_GetId(*e) + 1, 2, 2, 1);
        } else {
            MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x47, (void *)(((struct Obj00002 *)p)->f524));
            func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, n + 1, 2, 2, 1);
        }
        func_0201EF34((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 1, kind);
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x73C), *(u32 *)&((struct Obj00002 *)p)->f528, 0, 4, 0x3DC0);
        ITEMMENU_PrintMoveInfoText((u8 *)p, kind);
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00002 *)p)->f744);
    }
    func_02020FB4((void *)(((struct Obj00002 *)p)->f524), *e, ((struct Obj00002 *)p)->f544);
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x74C), ((struct Obj00002 *)p)->f524, 0, 4, 0x3DC0);
    ITEMMENU_FlushWindowAt((void **)(p + 0x73C));
    ITEMMENU_FlushWindowAt((void **)(p + 0x744));
    ITEMMENU_FlushWindowAt((void **)(p + 0x74C));
    ITEMMENU_CreateMovingCursor(p, *e);
}
