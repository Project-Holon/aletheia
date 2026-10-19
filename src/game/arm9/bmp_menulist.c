/*
 * file:     bmp_menulist.c
 * unit:     yes
 * function: BMP_MENULIST_Create, BMP_MENULIST_Main, BMP_MENULIST_Delete, BMP_MENULIST_Redraw, BMP_MENULIST_SetColors, BMP_MENULIST_SetOverrideColors, BMP_MENULIST_GetListIndex, BMP_MENULIST_GetPos, BMP_MENULIST_GetCursorY, BMP_MENULIST_GetRowY, BMP_MENULIST_GetItemValue, BMP_MENULIST_GetAttr, BMP_MENULIST_PrintItem, BMP_MENULIST_DrawItems, BMP_MENULIST_DrawCursor, BMP_MENULIST_EraseCursor, BMP_MENULIST_StepCursor, BMP_MENULIST_ScrollRows, BMP_MENULIST_MoveCursor, BMP_MENULIST_NotifyCursor, BMP_MENULIST_ShiftChars4bpp, BMP_MENULIST_ShiftChars8bpp, BMP_MENULIST_ShiftWindow, BMP_MENULIST_ResetCursorTile, BMP_MENULIST_GetUserData, BMP_MENULIST_SetCancelDisabled
 * address:  0x0201FF30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_menulist.c by tools/splitfile.py.
 *
 * symbols:
 *   BMP_MENULIST_FILE_NAME     0x020A7390  data  a1
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_GetColorMode  0x0204169C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   BMP_CURSOR_Create 0x02020D18 thumb arm9
 *   BMP_CURSOR_Delete 0x02020D3C thumb arm9
 *   BMP_CURSOR_Draw 0x02020D5C thumb arm9
 *   BMP_CURSOR_SetTileBitmap 0x02020DC8 thumb arm9
 */
#include "bmp_menulist_shared_types.h"

#define COLOR(l, s, b) ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))

#define MENULIST_SEPARATOR ((u32)-3)

#include "../types.h"

struct BmpMenuList;

/*
 * The template the caller hands to the constructor.  It is copied over the
 * first 0x34 bytes of BmpMenuList, so it has no field names of its own.
 */
struct MenuTemplate {
    u32 w[13];
};

struct MenuItem {
    void *text;
    u32   value;
};

typedef void (*MenuDrawHook)(struct BmpMenuList *menu, u32 value, u8 y);

typedef void (*MenuCursorNotify)(struct BmpMenuList *menu, u32 value, void *arg);

/* The halfword at +0x1A. */
struct MenuFlags {
    u16 mode3 : 3;
    u16 lineGap : 4;
    u16 pageKeys : 2;
    u16 mode6 : 6;
    u16 cursorOff : 1;
};

struct BmpMenuList {
    struct MenuItem *items;
    MenuCursorNotify onCursor;
    MenuDrawHook     drawHook;
    struct BmpWin   *win;
    u16 count;
    u16 rows;
    u8 sepX;
    u8 itemX;
    u8 cursorX;
    u8 originY : 4;
    u8 letterColor : 4;
    u8 bgColor : 4;
    u8 shadowColor : 4;
    u8 reserved19;
    struct MenuFlags flags;
    u32 userData;
    u16 cursorW;
    u16 rowH;
    u8 reserved24[0x28 - 0x24];
    struct MenuTarget *target;
    void *printer;
    u32 font;
    u8 ovLetter : 4;
    u8 ovBg : 4;
    u8 ovShadow : 4;
    u8 reserved35 : 4;
    u8 mode3Copy : 6;
    u8 reserved36 : 2;
    u8 reserved37;
    u8 mode6Copy : 7;
    u8 useOverride : 1;
    u8 reserved39[0x3C - 0x39];
    struct MenuCursor *cursor;
    u16 scroll;
    u16 row;
    u8 keyRepeatCount;
    u8 keyRepeatDelay;
    u8 lastKeyMask;
    u8 moveDir;
    u16 heapId;
    u8 noCancel;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_Clear(struct Bmp *bmp, u8 color);

extern u32  KEY_GetTrg(void);

extern unsigned int KEY_GetRepeat(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 id);

extern u32 GFL_HEAP_Free(void *block);

extern void PRINTSYS_PrintQueColor(void *printer, struct Bmp *bmp, u32 x, u32 y, const void *text, u32 param, u16 color);

extern void PRINTSYS_PrintColor(struct Bmp *bmp, u32 x, u32 y, const void *text, u32 param, u16 color);

extern u8 BMP_WIN_GetWidth(struct BmpWin *win);

extern void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value);

extern u16 BMP_GetWidth(const struct Bmp *bmp);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern u16 BMP_GetHeight(const struct Bmp *bmp);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern u8 BG_SYS_GetColorMode(int channel);

struct BmpMenuList *BMP_MENULIST_Create(struct MenuTemplate *menuTemplate, u16 scroll, u16 row, u32 heap);

s32 BMP_MENULIST_Main(struct BmpMenuList *menu);

void BMP_MENULIST_Delete(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow);

void BMP_MENULIST_Redraw(struct BmpMenuList *menu);

void BMP_MENULIST_SetColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow);

void BMP_MENULIST_SetOverrideColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow);

void BMP_MENULIST_GetListIndex(struct BmpMenuList *menu, u16 *outIndex);

void BMP_MENULIST_GetPos(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow);

u16 BMP_MENULIST_GetCursorY(struct BmpMenuList *menu);

u16 BMP_MENULIST_GetRowY(struct BmpMenuList *menu, u32 row);

u32 BMP_MENULIST_GetItemValue(struct BmpMenuList *menu, u32 index);

u32 BMP_MENULIST_GetAttr(struct BmpMenuList *menu, u32 attr);

void BMP_MENULIST_PrintItem(struct BmpMenuList *menu, const void *text, u32 x, u32 y, u32 queued);

void BMP_MENULIST_DrawItems(struct BmpMenuList *menu, u16 item, u16 winRow, u16 numRows, u32 scrollFirst);

void BMP_MENULIST_DrawCursor(struct BmpMenuList *menu);

void BMP_MENULIST_EraseCursor(struct BmpMenuList *menu, u32 row);

u8 BMP_MENULIST_StepCursor(struct BmpMenuList *menu, u8 dir);

void BMP_MENULIST_ScrollRows(struct BmpMenuList *menu, u16 numRows, u32 fromBottom);

u32 BMP_MENULIST_MoveCursor(struct BmpMenuList *menu, u8 redraw, u8 steps, u8 dir);

void BMP_MENULIST_NotifyCursor(struct BmpMenuList *menu, void *arg);

void BMP_MENULIST_ShiftChars4bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes);

void BMP_MENULIST_ShiftChars8bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes);

void BMP_MENULIST_ShiftWindow(struct BmpWin *win, u32 dir, u32 start, u32 fillColor, u16 tiles);

void BMP_MENULIST_ResetCursorTile(struct BmpMenuList *menu, int heap);

u32 BMP_MENULIST_GetUserData(struct BmpMenuList *menu);

void BMP_MENULIST_SetCancelDisabled(struct BmpMenuList *menu, u32 disabled);

struct MenuCursor *BMP_CURSOR_Create(u32 heap);

void BMP_CURSOR_Delete(struct MenuCursor *cursor);

void BMP_CURSOR_Draw(struct MenuCursor *cursor, u32 x, u32 y, struct MenuTarget *target, void *printer, u32 param);

void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap);

extern const char BMP_MENULIST_FILE_NAME[];

struct BmpMenuList *BMP_MENULIST_Create(struct MenuTemplate *menuTemplate, u16 scroll, u16 row, u32 heap)
{
    struct BmpMenuList *menu;

    menu = (struct BmpMenuList *)GFL_HEAP_Alloc(heap, 0x50, 1, BMP_MENULIST_FILE_NAME, 0x69);
    *(struct MenuTemplate *)menu = *menuTemplate;
    menu->cursor = BMP_CURSOR_Create(heap);
    menu->scroll = scroll;
    menu->row = row;
    menu->keyRepeatCount = 0;
    menu->keyRepeatDelay = 0;
    menu->lastKeyMask = 0xFF;
    menu->moveDir = 0;
    menu->heapId = (u16)heap;
    menu->ovLetter = menu->letterColor;
    menu->ovBg = menu->bgColor;
    menu->ovShadow = menu->shadowColor;
    menu->mode3Copy = (u8)menu->flags.mode3;
    menu->mode6Copy = (u8)menu->flags.mode6;
    menu->useOverride = 0;
    if (menu->count < menu->rows) {
        menu->rows = menu->count;
    }
    while (menu->items[menu->scroll + menu->row].value == MENULIST_SEPARATOR) {
        menu->row++;
    }
    {
        struct MenuTarget *t = menu->target;
        t->win = menu->win;
        t->dirty = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(menu->win), menu->bgColor);
    BMP_MENULIST_DrawItems(menu, menu->scroll, 0, menu->rows, 1);
    BMP_MENULIST_DrawCursor(menu);
    BMP_MENULIST_NotifyCursor(menu, (void *)1);
    return menu;
}

/*
 * The per-frame key handler of the menu-cursor object built by
 * BMP_MENULIST_Create: same shape as BMP_MENU_ProcessInput one block down, over the wider
 * struct that BMP_MENULIST_DrawCursor already spells out.  Sound ids 0x54C / 0x551 /
 * 0x548 sit in the trailing pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_Main.c \
 *       --func BMP_MENULIST_Main --addr 0x020200CC --thumb
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/BMP_MENULIST_Main.c.txt,
 * 81 bytes out).  The note read the residue as an allocator choice (`tst`
 * versus a copy and `ands`); it was a misread of the image.  In the
 * lineGap == 2 arm the masks are derived from the 0x80 still live in r2:
 * `lsls r1, r2, #2` is 0x200 and `adds r2, #0x80` is 0x100, so the arm reads
 * the L and R shoulder buttons (0x200, 0x100), not up/down (0x40, 0x80).
 * With the right constants the 0x40 test becomes a plain `tst` by itself,
 * and the switch closes once case 0 and default share one arm.
 * BMP_MENULIST_MoveCursor's prototype is the EXACT one (u8 scalar parameters).
 */
s32 BMP_MENULIST_Main(struct BmpMenuList *menu)
{
    u32 pressed = KEY_GetTrg();
    u32 okBit = 1;
    u32 held = KEY_GetRepeat();

    menu->moveDir = 0;

    if (pressed & okBit) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return menu->items[menu->scroll + menu->row].value;
    }
    if (menu->noCancel == 0) {
        u32 cancelBit = 2;
        if (pressed & cancelBit) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return cancelBit - 4;
        }
    }
    if (held & 0x40) {
        if (BMP_MENULIST_MoveCursor(menu, 1, 1, 0) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            menu->moveDir = 1;
        }
        return -1;
    }
    if (held & 0x80) {
        if (BMP_MENULIST_MoveCursor(menu, 1, 1, 1) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            menu->moveDir = 2;
        }
        return -1;
    }
    {
        u16 pagePrev, pageNext;
        switch (menu->flags.pageKeys) {
        case 0:
        default:
            pagePrev = 0;
            pageNext = 0;
            break;
        case 1:
            pagePrev = (u16)(held & 0x20);
            pageNext = (u16)(held & 0x10);
            break;
        case 2:
            pagePrev = (u16)(held & 0x200);
            pageNext = (u16)(held & 0x100);
            break;
        }
        if (pagePrev != 0) {
            if (BMP_MENULIST_MoveCursor(menu, 1, (u8)menu->rows, 0) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                menu->moveDir = 3;
            }
            return -1;
        }
        if (pageNext != 0) {
            if (BMP_MENULIST_MoveCursor(menu, 1, (u8)menu->rows, 1) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                menu->moveDir = 4;
            }
            return -1;
        }
    }
    return -1;
}

void BMP_MENULIST_Delete(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow)
{
    if (outScroll != 0) {
        *outScroll = menu->scroll;
    }
    if (outRow != 0) {
        *outRow = menu->row;
    }
    BMP_CURSOR_Delete(menu->cursor);
    GFL_HEAP_Free(menu);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_Redraw.c \
 *       --func BMP_MENULIST_Redraw --addr 0x02020234 --cc 1.1p1 --thumb
 */
void BMP_MENULIST_Redraw(struct BmpMenuList *menu)
{
    BMP_Clear(BMP_WIN_GetBmp(menu->win), menu->bgColor);
    BMP_MENULIST_DrawItems(menu, menu->scroll, 0, menu->rows, 1);
    BMP_MENULIST_DrawCursor(menu);
}

/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020268.c \
 *       --addr 0x02020268 --thumb
 *
 * The bmp_menulist.c attribute block 0x02020268..0x02020408, eight
 * functions of which only 0x02020268 was ever near a label.  The
 * worklist entry 0x020202CC (a "32-byte open function") is NOT a
 * function start: it is the middle of BMP_MENULIST_SetOverrideColors (the colour-override
 * setter), seeded into layout/function_starts.txt from a pending header
 * that misnamed WIPE_SUB_FadeVTask's tail-call target (the pool word there is
 * 0x020222CD; see docs/notes/pkt_02022940.c.txt, wave 11).  The 32 bytes
 * the worklist counted are BMP_MENULIST_SetOverrideColors's last eight instructions.
 *
 *   BMP_MENULIST_SetColors  set the three colour nibbles letterColor / bgColor / shadowColor
 *   BMP_MENULIST_SetOverrideColors  set the override nibbles ovLetter / ovBg / ovShadow and the
 *                  override flag useOverride (BMP_MENULIST_Create seeds the same
 *                  three from letterColor / bgColor / shadowColor)
 *   BMP_MENULIST_GetListIndex  *out = scroll + row (list index of the cursor row)
 *   BMP_MENULIST_GetPos  optional out-pointers for scroll and row
 *   BMP_MENULIST_GetCursorY  tail call to BMP_MENULIST_GetRowY with the cursor row row
 *   BMP_MENULIST_GetRowY  pixel y of row n: originY + n * (u8)(rowH + lineGap),
 *                  the expression unit_020206C0 inlines
 *   BMP_MENULIST_GetItemValue  arr[n].value, the item's value word
 *   BMP_MENULIST_GetAttr  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void BMP_MENULIST_SetColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow)
{
    menu->letterColor = letter;
    menu->bgColor = bg;
    menu->shadowColor = shadow;
}

void BMP_MENULIST_SetOverrideColors(struct BmpMenuList *menu, u8 letter, u8 bg, u8 shadow)
{
    menu->ovLetter = letter;
    menu->ovBg = bg;
    menu->ovShadow = shadow;
    menu->useOverride = 1;
}

void BMP_MENULIST_GetListIndex(struct BmpMenuList *menu, u16 *outIndex)
{
    *outIndex = menu->scroll + menu->row;
}

void BMP_MENULIST_GetPos(struct BmpMenuList *menu, u16 *outScroll, u16 *outRow)
{
    if (outScroll != 0) {
        *outScroll = menu->scroll;
    }
    if (outRow != 0) {
        *outRow = menu->row;
    }
}

u16 BMP_MENULIST_GetCursorY(struct BmpMenuList *menu)
{
    return BMP_MENULIST_GetRowY(menu, menu->row);
}

u16 BMP_MENULIST_GetRowY(struct BmpMenuList *menu, u32 row)
{
    return (u16)(menu->originY + row * (u8)(menu->rowH + menu->flags.lineGap));
}

u32 BMP_MENULIST_GetItemValue(struct BmpMenuList *menu, u32 index)
{
    return menu->items[index].value;
}

u32 BMP_MENULIST_GetAttr(struct BmpMenuList *menu, u32 attr)
{
    switch (attr) {
    case 0:  return (u32)menu->onCursor;
    case 1:  return (u32)menu->drawHook;
    case 2:  return menu->count;
    case 3:  return menu->rows;
    case 5:  return menu->sepX;
    case 6:  return menu->itemX;
    case 7:  return menu->cursorX;
    case 8:  return menu->originY;
    case 9:  return menu->rowH + menu->flags.lineGap;
    case 10: return menu->letterColor;
    case 11: return menu->bgColor;
    case 12: return menu->shadowColor;
    case 13: return menu->flags.mode3;
    case 14: return menu->flags.lineGap;
    case 15: return menu->flags.pageKeys;
    case 16: return menu->flags.mode6;
    case 17: return menu->flags.cursorOff;
    case 18: return (u32)menu->win;
    case 19: return menu->userData;
    }
    return -1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_PrintItem.c \
 *       --func BMP_MENULIST_PrintItem --addr 0x02020408 --thumb
 *
 * Print one item's text into the menu window.  useOverride selects the override
 * colours at +0x34/+0x35 (set by BMP_MENULIST_SetOverrideColors) over the
 * list's own at +0x17/+0x18; sel picks PRINTSYS_PrintQueColor (which also marks the
 * target dirty) over PRINTSYS_PrintColor.  Closed in wave 13; the 2026-09-21 note
 * (docs/notes/BMP_MENULIST_PrintItem.c.txt) had it at 314 of 338 bytes.
 *
 * The packed colour is a 5:5:5 triple built by a masking macro,
 *     ((l & 0x1f) << 10) | ((s & 0x1f) << 5) | (b & 0x1f)
 * over the 4-bit nibbles: mwcc turns each mask-then-shift into the
 * `<< 27 / >> 17` and `<< 27 / >> 22` pairs and keeps the bare `ands 0x1f`
 * on the unshifted term, which is exactly the "5-bit destination over a
 * 4-bit source" shape the note described.  No 5-bit bitfield struct needed.
 *
 * THE IMAGE'S FOURTH ARM (useOverride clear, sel == 0) READS THE OVERRIDE BYTES
 * +0x34/+0x35, not +0x17/+0x18 like the third arm.  That is what the bytes
 * say, and the C reproduces it; it reads like a copy-paste slip in the
 * original.  EXACT* only because the extent includes 2 bytes of padding.
 */
void BMP_MENULIST_PrintItem(struct BmpMenuList *menu, const void *text, u32 x, u32 y, u32 queued)
{
    if (text == 0)
        return;
    if (menu->useOverride) {
        if (queued) {
            u32 printer = (u32)menu->printer;
            struct MenuTarget *target = menu->target;
            PRINTSYS_PrintQueColor((void *)printer, BMP_WIN_GetBmp(target->win), x, y, text, menu->font,
                          COLOR(menu->ovLetter, menu->ovShadow, menu->ovBg));
            target->dirty = 1;
        } else {
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(menu->target->win), x, y, text, menu->font,
                          COLOR(menu->ovLetter, menu->ovShadow, menu->ovBg));
        }
    } else {
        if (queued) {
            u32 printer = (u32)menu->printer;
            struct MenuTarget *target = menu->target;
            PRINTSYS_PrintQueColor((void *)printer, BMP_WIN_GetBmp(target->win), x, y, text, menu->font,
                          COLOR(menu->letterColor, menu->shadowColor, menu->bgColor));
            target->dirty = 1;
        } else {
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(menu->target->win), x, y, text, menu->font,
                          COLOR(menu->ovLetter, menu->ovShadow, menu->ovBg));
        }
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_DrawItems.c \
 *       --func BMP_MENULIST_DrawItems --addr 0x0202055C --thumb
 *
 * Redraw n + 1 rows of the menu list from item `row`, starting at window
 * row `col`.  When flag is set and row > 0 the window is first scrolled by
 * one row: the band is cleared with BMP_FillRect, the item above is
 * redrawn and BMP_MENULIST_ShiftWindow moves the pixels.  Every item goes through the
 * optional per-item hook at +0x08 (obj, item value, y) and then
 * BMP_MENULIST_PrintItem at x = itemX, or sepX for a separator (value -3).
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/BMP_MENULIST_DrawItems.c.txt,
 * 96 out).  That source misread three things, all fixed here from the image:
 * the hook's second argument inside the loop is the item's value word (still
 * live in r1 from the separator test), not 0; BMP_MENULIST_ShiftWindow's last argument
 * is (step*2/8) * (BMP_GetWidth(bitmap) / 8), the bitmap's width in tiles,
 * not step >> 3; and the x colour is an int (no truncation after the
 * ternary).  Then the permuter's type:l(step:u8->int) (the value is still
 * (u8)-truncated at its one assignment) swapped the last two stack slots.
 * EXACT* only because the extent includes 2 bytes of padding.
 */
void BMP_MENULIST_DrawItems(struct BmpMenuList *menu, u16 item, u16 winRow, u16 numRows, u32 scrollFirst)
{
    int rowStep;
    int x;
    u8 y;
    int i;
    int end;

    rowStep = (u8)(menu->rowH + menu->flags.lineGap);
    if (item != 0 && scrollFirst != 0) {
        struct Bmp *bmp;
        u8 widthTiles;
        u8 bg;
        x = (menu->items[item - 1].value != MENULIST_SEPARATOR) ? menu->itemX : menu->sepX;
        bmp = BMP_WIN_GetBmp(menu->win);
        widthTiles = BMP_WIN_GetWidth(menu->win);
        BMP_FillRect(bmp, 0, 0, (u16)(widthTiles * 8),
                      (u16)(menu->originY + (winRow + 1) * rowStep * 2), menu->bgColor);
        y = (u8)(menu->originY + winRow * rowStep);
        if (menu->drawHook != 0)
            menu->drawHook(menu, menu->items[item - 1].value, y);
        BMP_MENULIST_PrintItem(menu, menu->items[item - 1].text, x, y, 0);
        bg = menu->bgColor;
        BMP_MENULIST_ShiftWindow(menu->win, 0, rowStep, (u8)((bg << 4) | bg),
                      (u16)((rowStep * 2 / 8) * (BMP_GetWidth(BMP_WIN_GetBmp(menu->win)) / 8)));
    }
    end = (u16)(numRows + 1);
    for (i = 0; i < end; i++) {
        x = (menu->items[item].value != MENULIST_SEPARATOR) ? menu->itemX : menu->sepX;
        y = (u8)(menu->originY + (i + winRow) * rowStep);
        if (menu->drawHook != 0)
            menu->drawHook(menu, menu->items[item].value, y);
        BMP_MENULIST_PrintItem(menu, menu->items[item].text, x, y, 1);
        item++;
        if (item >= menu->count)
            return;
    }
}

/*
 * The two redraw entry points of the menu-cursor block, BMP_MENULIST_DrawCursor and
 * BMP_MENULIST_EraseCursor, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, originY + <row> * (u8)(rowH + lineGap), to
 * their callee; in BMP_MENULIST_DrawCursor the row is the cursor's own row and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * cursorX), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In BMP_MENULIST_EraseCursor the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */
void BMP_MENULIST_DrawCursor(struct BmpMenuList *menu)
{
    u8 baseY = menu->originY;
    u8 cursorX = menu->cursorX;
    u8 cursorY = (u8)(baseY + menu->row * (u8)(menu->rowH + menu->flags.lineGap));

    switch (menu->flags.cursorOff) {
    case 0:
        BMP_CURSOR_Draw(menu->cursor, cursorX, cursorY, menu->target, menu->printer, (u32)menu->font);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void BMP_MENULIST_EraseCursor(struct BmpMenuList *menu, u32 row)
{
    switch (menu->flags.cursorOff) {
    case 0:
        BMP_FillRect(BMP_WIN_GetBmp(menu->win),
                      menu->cursorX,
                      (s16)(u16)(menu->originY + row * (u8)(menu->rowH + menu->flags.lineGap)),
                      menu->cursorW,
                      menu->rowH,
                      menu->bgColor);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_StepCursor.c \
 *       --func BMP_MENULIST_StepCursor --addr 0x02020780 --thumb
 *
 * One cursor step of the scrolling menu list, dir 0 = up, else down.  The
 * cursor row (row) moves inside the window, skipping items whose value word
 * is -3 (separators), and answers 1; at the window's middle row the list
 * scrolls instead (scroll -= 1 / += 1, cursor parked on the middle row) and it
 * answers 2; at either end of the list it answers 0.  The middle row is
 * rows - (rows/2 + rows%2) - 1 going up and rows/2 + rows%2 going down, 0
 * for a one-row window.
 *
 * Re-derived in wave 13 (the 2026-09-21 note, docs/notes/BMP_MENULIST_StepCursor.c.txt,
 * kept no source).  What pinned the register map obj=r0 row=r4 col=r3
 * rows=r2, which that note could not reach:
 *   - col (scroll) is an int local, not u16 (u16 keeps obj out of r0);
 *   - rows is read into its local INSIDE each arm, not before the test
 *     (the image loads +0x12 after `cmp r1, #0`);
 *   - declaration order ncol, col, rows, mid, row (the permuter's
 *     decl-order row<->ncol; row declared first swaps r3/r4).
 * EXACT* only because the listing's extent includes the two bytes of
 * alignment padding after the function.
 */
u8 BMP_MENULIST_StepCursor(struct BmpMenuList *menu, u8 dir)
{
    int newScroll;
    int scroll;
    u16 rows;
    u16 midRow;
    u16 row;

    row = menu->row;
    scroll = menu->scroll;
    if (dir == 0) {
        rows = menu->rows;
        if (rows == 1) {
            midRow = 0;
        } else {
            midRow = rows - (rows / 2 + rows % 2) - 1;
        }
        if (scroll == 0) {
            while (row != 0) {
                row--;
                if (menu->items[scroll + row].value != MENULIST_SEPARATOR) {
                    menu->row = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row > midRow) {
            row--;
            if (menu->items[scroll + row].value != MENULIST_SEPARATOR) {
                menu->row = row;
                return 1;
            }
        }
        menu->row = midRow;
        newScroll = scroll - 1;
    } else {
        rows = menu->rows;
        if (rows == 1) {
            midRow = 0;
        } else {
            midRow = rows / 2 + rows % 2;
        }
        if (scroll == menu->count - rows) {
            while ((int)row < rows - 1) {
                row++;
                if (menu->items[scroll + row].value != MENULIST_SEPARATOR) {
                    menu->row = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row < midRow) {
            row++;
            if (menu->items[scroll + row].value != MENULIST_SEPARATOR) {
                menu->row = row;
                return 1;
            }
        }
        menu->row = midRow;
        newScroll = scroll + 1;
    }
    menu->scroll = newScroll;
    return 2;
}

void BMP_MENULIST_ScrollRows(struct BmpMenuList *menu, u16 numRows, u32 fromBottom)
{
    u8 rowStep;

    if (numRows >= (int)menu->rows) {
        BMP_Clear(BMP_WIN_GetBmp(menu->win), menu->bgColor);
        BMP_MENULIST_DrawItems(menu, menu->scroll, 0, menu->rows, 1);
        return;
    }

    rowStep = (u8)(menu->rowH + menu->flags.lineGap);
    if (fromBottom == 0) {
        u8 bg = menu->bgColor;
        BMP_MENULIST_ShiftWindow(menu->win, 1, (u8)(numRows * rowStep), (u8)((bg << 4) | bg), 0);
        BMP_MENULIST_DrawItems(menu, menu->scroll, 0, numRows, 1);
    } else {
        u8 bg = menu->bgColor;
        BMP_MENULIST_ShiftWindow(menu->win, 0, (u8)(numRows * rowStep), (u8)((bg << 4) | bg), 0);
        BMP_MENULIST_DrawItems(menu, (u16)(menu->scroll + (menu->rows - numRows)), (u16)(menu->rows - numRows), numRows, 0);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_MoveCursor.c \
 *       --func BMP_MENULIST_MoveCursor --addr 0x02020970 --thumb
 *
 * Move the menu cursor count steps in direction dir (BMP_MENULIST_StepCursor does one
 * step and answers 0 = no move, 1 = cursor moved inside the window, 2 = the
 * list scrolled), then, if notify, redraw what changed.  Closed in wave 13
 * after the 2026-09-21 note (docs/notes/BMP_MENULIST_MoveCursor.c.txt) left it at 34
 * bytes out.  What closed it, in order of weight:
 *   - ALL THREE SCALAR PARAMETERS ARE NARROW (u8 here; u16 compiles the
 *     same).  u8 count is what gives the guard its `cmp r0,#0 / bls` with
 *     the reload from the home slot (u32 count gives `cmp #1 / blo` or folds
 *     onto r2); u8/u16 notify and dir are what schedule the three home
 *     stores ahead of the obj copy.
 *   - the guard is `i < count` with i already 0, around a do/while;
 *   - a skipped row (item value -3) re-runs the step WITHOUT advancing i:
 *     a goto to the top of the body, not a continue (continue reaches the
 *     condition);
 *   - `case 0: default: return 1;` written first; without case 0 the switch
 *     becomes a compare chain, with a separate default it duplicates.
 */
u32 BMP_MENULIST_MoveCursor(struct BmpMenuList *menu, u8 redraw, u8 steps, u8 dir)
{
    u8 result;
    u8 scrolled;
    u8 i;
    u8 stepResult;
    u16 oldRow;

    scrolled = 0;
    result = 0;
    oldRow = menu->row;
    i = 0;
    if (i < steps) {
        do {
        again:
            stepResult = BMP_MENULIST_StepCursor(menu, dir);
            result |= stepResult;
            if (stepResult == 2) {
                scrolled++;
                if (menu->items[menu->scroll + menu->row].value == MENULIST_SEPARATOR)
                    goto again;
            }
            i++;
        } while (i < steps);
    }
    if (redraw != 0) {
        switch (result) {
        case 0:
        default:
            return 1;
        case 1:
            BMP_MENULIST_EraseCursor(menu, oldRow);
            BMP_MENULIST_DrawCursor(menu);
            BMP_MENULIST_NotifyCursor(menu, 0);
            BMP_WIN_TransferChars(menu->win);
            break;
        case 2:
        case 3:
            BMP_MENULIST_EraseCursor(menu, oldRow);
            BMP_MENULIST_ScrollRows(menu, scrolled, dir);
            BMP_MENULIST_DrawCursor(menu);
            BMP_MENULIST_NotifyCursor(menu, 0);
            break;
        }
    }
    return 0;
}

void BMP_MENULIST_NotifyCursor(struct BmpMenuList *menu, void *arg)
{
    if (menu->onCursor != 0) {
        menu->onCursor(menu, menu->items[menu->scroll + menu->row].value, arg);
    }
}

void BMP_MENULIST_ShiftChars4bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes)
{
    u32  widthTiles;
    u32  fillWord;
    s32  length;
    s32  blockOff;
    s32  srcOff;
    s32  dstOff;
    u32  srcLine;
    s32  lineIdx;
    u8  *pixels;

    pixels = BMP_GetPixels(bmp);
    fillWord = (fillColor << 24) | (fillColor << 16) | (fillColor << 8) | fillColor;
    widthTiles = (u32)BMP_GetWidth(bmp) >> 3;
    length = sizeBytes;
    if (length == 0)
        length = (widthTiles * ((u32)BMP_GetHeight(bmp) >> 3)) << 5;

    switch (dir) {
    case 0:
        for (blockOff = 0; blockOff < length; blockOff += 0x20) {
            srcLine = startTile;
            for (lineIdx = 0; lineIdx < 8; lineIdx++) {
                dstOff = blockOff + lineIdx * 4;
                srcOff = blockOff + (((srcLine & 7) | (widthTiles * (srcLine & ~7u))) << 2);
                *(u32 *)(pixels + dstOff) =
                    (srcOff < length) ? *(u32 *)(pixels + srcOff) : fillWord;
                srcLine++;
            }
        }
        break;
    case 1:
        pixels = pixels + (length - 4);
        for (blockOff = 0; blockOff < length; blockOff += 0x20) {
            srcLine = startTile;
            for (lineIdx = 0; lineIdx < 8; lineIdx++) {
                u32 *dstPtr;
                u32  word;
                dstOff = blockOff + lineIdx * 4;
                srcOff = blockOff + (((srcLine & 7) | (widthTiles * (srcLine & ~7u))) << 2);
                if (srcOff < length) {
                    word = *(u32 *)(pixels - srcOff);
                    dstPtr = (u32 *)(pixels - dstOff);
                } else {
                    dstPtr = (u32 *)(pixels - dstOff);
                    word = fillWord;
                }
                srcLine++;
                *dstPtr = word;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

void BMP_MENULIST_ShiftChars8bpp(struct Bmp *bmp, u32 dir, u32 startTile, u32 fillColor, u16 sizeBytes)
{
    u32  widthTiles;
    u32  fillWord;
    s32  length;
    s32  blockOff;
    s32  srcOff;
    s32  dstOff;
    u32  srcLine;
    s32  lineIdx;
    u8  *pixels;

    pixels = BMP_GetPixels(bmp);
    fillWord = (fillColor << 24) | (fillColor << 16) | (fillColor << 8) | fillColor;
    widthTiles = (u32)BMP_GetWidth(bmp) >> 3;
    length = sizeBytes;
    if (length == 0)
        length = (widthTiles * ((u32)BMP_GetHeight(bmp) >> 3)) << 6;

    switch (dir) {
    case 0:
        for (blockOff = 0; blockOff < length; blockOff += 0x40) {
            srcLine = startTile;
            for (lineIdx = 0; lineIdx < 8; lineIdx++) {
                u32 word;
                dstOff = blockOff + lineIdx * 8;
                srcOff = blockOff + (((srcLine & 7) | (widthTiles * (srcLine & ~7u))) << 3);
                if (srcOff < length) {
                    word = *(u32 *)(pixels + srcOff);
                    *(u32 *)(pixels + dstOff) = word;
                } else {
                    word = fillWord;
                    *(u32 *)(pixels + dstOff) = word;
                }
                if (srcOff + 4 < length + 4) {
                    word = *(u32 *)(pixels + (srcOff + 4));
                    *(u32 *)(pixels + (dstOff + 4)) = word;
                } else {
                    word = fillWord;
                    *(u32 *)(pixels + (dstOff + 4)) = word;
                }
                srcLine++;
            }
        }
        break;
    case 1:
        pixels = pixels + (length - 8);
        for (blockOff = 0; blockOff < length; blockOff += 0x40) {
            srcLine = startTile;
            for (lineIdx = 0; lineIdx < 8; lineIdx++) {
                u32  word;
                dstOff = blockOff + lineIdx * 8;
                srcOff = blockOff + (((srcLine & 7) | (widthTiles * (srcLine & ~7u))) << 3);
                if (srcOff < length) {
                    word = *(u32 *)(pixels - srcOff);
                    *(u32 *)(pixels - dstOff) = word;
                } else {
                    word = fillWord;
                    *(u32 *)(pixels - dstOff) = word;
                }
                if (srcOff - 4 < length - 4) {
                    word = *(u32 *)(pixels - (srcOff - 4));
                    dstOff = dstOff - 4;
                    *(u32 *)(pixels - dstOff) = word;
                } else {
                    dstOff = dstOff - 4;
                    word = fillWord;
                    *(u32 *)(pixels - dstOff) = word;
                }
                srcLine++;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

/*
 * UNBLOCKED 2026-09-21: the two THM_CALL sites at +0x36 and +0x4e now
 * attest `matched` off src/matched/BMP_MENULIST_ShiftChars4bpp.c and the newly filed
 * src/matched/BMP_MENULIST_ShiftChars8bpp.c.  All 5 relocation sites resolve and the
 * verdict is EXACT*; promoted from src/pending/ unchanged apart from
 * this header.  EXACT* only because 0x02020CF8 has no label.
 *
 * Window-fill front end.  The window descriptor names a BG channel
 * (BMP_WIN_GetBgLayer, the +2 accessor) and carries the bitmap it draws into
 * (BMP_WIN_GetBmp, the +0xc handle).  BG_SYS_GetColorMode says whether that
 * channel is 8bpp; the 4bpp path calls BMP_MENULIST_ShiftChars4bpp and the 8bpp path
 * BMP_MENULIST_ShiftChars8bpp, and the caller's tile offset is converted to a byte
 * offset by the depth: (t & 0x7ff) << 5 for 4bpp, (t & 0x3ff) << 6 for
 * 8bpp, i.e. 32 or 64 bytes per tile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_ShiftWindow.c \
 *       --func BMP_MENULIST_ShiftWindow --addr 0x02020CA0 --cc 1.1p1 --thumb
 */
void BMP_MENULIST_ShiftWindow(struct BmpWin *win, u32 dir, u32 start, u32 fillColor, u16 tiles)
{
    int   channel;
    struct Bmp *bmp;

    channel = BMP_WIN_GetBgLayer(win);
    bmp = BMP_WIN_GetBmp(win);

    if (BG_SYS_GetColorMode(channel) == 0)
        BMP_MENULIST_ShiftChars4bpp(bmp, dir, start, fillColor, (u16)(tiles << 5));
    else
        BMP_MENULIST_ShiftChars8bpp(bmp, dir, start, fillColor, (u16)(tiles << 6));
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * BMP_MENULIST_GetUserData and BMP_MENULIST_SetCancelDisabled carry no label in the generated listing:
 * they are a two-instruction word getter and a two-instruction byte setter
 * with no register-saving prologue, so disasm.py's prologue sweep never
 * fires on them and the listing prints them as a run of data between
 * BMP_MENULIST_ResetCursorTile and BMP_CURSOR_Create
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * BMP_CURSOR_Create is a debug-allocator constructor in the
 * `GFL_HEAP_Alloc(heap, size, count, file, line)` shape documented for
 * playtime.c: it allocates a 12-byte object tagged with the string at
 * 0x020A73A0 and line 0x3a, zeroing the first word when the allocation
 * succeeds.  0x020A73A0 spells "bmp_cursor.c", the second original source
 * file name this project has recovered (after playtime.c); the functions
 * keep their sub_<address> names because the file identity is attested and
 * the individual entry points are not.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020CF8.c \
 *       --addr 0x02020CF8 --thumb
 */
void BMP_MENULIST_ResetCursorTile(struct BmpMenuList *menu, int heap)
{
    BMP_CURSOR_SetTileBitmap(menu->cursor, heap);
    BMP_MENULIST_DrawCursor(menu);
}

u32 BMP_MENULIST_GetUserData(struct BmpMenuList *menu)
{
    return menu->userData;
}

void BMP_MENULIST_SetCancelDisabled(struct BmpMenuList *menu, u32 disabled)
{
    menu->noCancel = disabled;
}
