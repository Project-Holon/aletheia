/*
 * file:     bmp_menu.c
 * unit:     yes
 * function: BMP_MENU_Create, BMP_MENU_Add, BMP_MENU_Delete, BMP_MENU_ProcessInput, BMP_MENU_MoveCursor, BMP_MENU_StepSelection, BMP_MENU_GetMaxItemWidth, BMP_MENU_DrawItems, BMP_MENU_DrawCursor, BMP_MENU_GetItemPixelPos, BMP_MENU_CreateYesNo, BMP_MENU_ProcessYesNo, BMP_MENU_DeleteYesNo
 * address:  0x0201F93C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_menu.c by tools/splitfile.py.
 *
 * symbols:
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   GFL_HEAP_Alloc        0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sBmpMenuFile    0x020A7384  data
 *   BMP_CURSOR_Create   0x02020D18  thumb
 *   BMP_CURSOR_SetTileBitmap   0x02020DC8  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   BMP_Clear   0x02043B5C  arm
 *   PRINTSYS_PrintQue   0x0201C6FC  thumb
 *   BMP_CURSOR_Draw   0x02020D5C  thumb
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   MSGDATA_Delete   0x02045C04  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   GF_FONT_Create   0x0201D7EC  thumb
 *   GF_FONT_GetLineHeight   0x0201DC80  thumb
 *   PRINTSYS_QUE_Create   0x0201C440  thumb
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_CURSOR_Delete  0x02020D3C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb arm9
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb arm9
 *   BMP_MENUWORK_Create 0x0201F81C thumb arm9
 *   BMP_MENUWORK_Delete 0x0201F868 thumb arm9
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb arm9
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 */
#include "bmp_menuwork_shared_types.h"
#include "bmp_menu_types.h"


#include "bmp_win.h"

#include "bg_sys.h"

#include "gfl_heap_wrap.h"

struct MenuCursor;

#include "bmp_cursor.h"



#include "key.h"

#include "gfl_use.h"
#include "bmp_shared_types.h"

typedef short s16_p07;
#include "bmp.h"
struct Strbuf;

#ifdef __MWERKS__
extern u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing);
extern void PRINTSYS_PrintQue(void *que, void *bitmap, u32 x, u32 y, const void *str, struct GfFont *font); /* original prototype; the definition differs in argument width, pointer or integer, pointer type, return type */
#else
#include "printsys.h"
#endif
struct MenuTarget;


#include "msgdata.h"


#include "mi_memory.h"


#include "gf_font.h"


#ifdef __MWERKS__
extern void *PRINTSYS_QUE_Create(void *heapIdAsPtr); /* original prototype; the definition differs in argument width, pointer or integer, pointer type, return type */
#endif


struct PrintQueue;




#include "bmp_menuwork.h"





BmpMenu *BMP_MENU_Create(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);

BmpMenu *BMP_MENU_Add(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);

void BMP_MENU_Delete(BmpMenu *menu, u8 *outSelected);

u32 BMP_MENU_ProcessInput(BmpMenu *menu);

int BMP_MENU_MoveCursor(BmpMenu *menu, u32 dir, u32 sfxId);

int BMP_MENU_StepSelection(BmpMenu *menu, u32 dir);

u32 BMP_MENU_GetMaxItemWidth(BmpMenu *menu);

void BMP_MENU_DrawItems(BmpMenu *menu);

void BMP_MENU_DrawCursor(BmpMenu *menu);

void BMP_MENU_GetItemPixelPos(BmpMenu *menu, u8 *outX, u8 *outY, u8 itemPos);

BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winData, u16 tileBase, u8 palette, u8 startPos, u16 heapId);

u32 BMP_MENU_ProcessYesNo(BmpMenu *menu);

void BMP_MENU_DeleteYesNo(BmpMenu *menu);

extern char sBmpMenuFile[];

/*
 * bmp_menu.c constructor (line 0x61, __FILE__ 0x020A7384 "bmp_menu.c"):
 * allocate the 0x38-byte menu, copy the 0x24-byte header in, create the
 * cursor, record cancelMask mask, start position, widest item (BMP_MENU_GetMaxItemWidth),
 * heap id and the pixel origin, then draw (BMP_MENU_DrawItems) and place the
 * cursor (BMP_MENU_DrawCursor).
 *
 * The residue in docs/notes/BMP_MENU_Create.c.txt (the stack-passed u16 heap
 * cached once in a callee-saved register instead of reloaded, 92 bytes out)
 * depended on the conversion at the allocation call: the allocator's heap
 * parameter is `u32`, and the explicit `(u32)(int)heap` keeps that site's
 * signed conversion distinct from the other uses. Without it, the u16 value
 * is zero-extended once and CSE'd into all four uses. With the conversion,
 * the first `ldrh` feeds r0 directly, the header pointer's register is
 * reused for the second load, and the frame shrinks to the original's
 * push {r3-r7,lr} / sub sp,#8.  Found by tools/permuter.py hill (a
 * `(int)heap` cast at that one site), then retained explicitly at the call
 * while preserving the allocator's unsigned-word parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_Create.c \
 *       --func BMP_MENU_Create --addr 0x0201F93C --thumb
 */
BmpMenu *BMP_MENU_Create(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask)
{
    BmpMenu *menu = GFL_HEAP_Alloc((u32)(int)heapId, sizeof(BmpMenu), 1, sBmpMenuFile, 0x61);

    menu->header = *header;
    menu->cursor = (struct BmpCursor *)BMP_CURSOR_Create(heapId);
    menu->cancelMask = cancelMask;
    menu->selected = startPos;
    menu->colWidth = BMP_MENU_GetMaxItemWidth(menu);
    menu->heapId = heapId;
    menu->originX = originX;
    menu->originY = originY;
    BMP_CURSOR_SetTileBitmap((struct MenuCursor *)menu->cursor, (u32)heapId);
    menu->xPad = menu->header.xPad;
    menu->lineHeight = menu->header.lineHeight;
    BMP_MENU_DrawItems(menu);
    BMP_MENU_DrawCursor(menu);
    return menu;
}

/*
 * A pass-through onto BMP_MENU_Create: the four register arguments are never
 * touched and only the two stacked ones are copied down into the new frame.
 * The fifth is a halfword and needs `add r4, sp, #0x10` + `ldrh` because
 * Thumb has no halfword load with an sp base; the sixth is a word and loads
 * directly.
 *
 * Blocked on the `label` class: 0x0201F93C has no branch reference anywhere
 * in the image except the one in this function, and the range cannot be cut
 * smaller than the single function, so no witness exists.  0x0201F93C is a
 * 148-byte constructor (debug allocator at 0x02030734, 0x38 bytes, line 97,
 * a nine-word ldm/stm copy of the caller's descriptor, then BMP_MENU_GetMaxItemWidth)
 * and was not attempted in wave 20B for budget reasons, not for difficulty.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_Add.c \
 *       --func BMP_MENU_Add --addr 0x0201F9D0 --cc 1.1p1 --thumb
 */
BmpMenu *BMP_MENU_Add(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask)
{
    return BMP_MENU_Create(header, originX, originY, startPos, heapId, cancelMask);
}

void BMP_MENU_Delete(BmpMenu *menu, u8 *outSelected)
{
    if (outSelected != 0) {
        *outSelected = menu->selected;
    }
    BMP_CURSOR_Delete((struct MenuCursor *)menu->cursor);
    GFL_HEAP_Free(menu);
}

/*
 * The menu's per-frame input step.  Field +0x33 is cleared first and holds
 * the direction that was accepted this frame (1..4).  A is a confirm: it
 * plays 0x54C and answers the selected entry's second word.  Any bit in the
 * caller-supplied cancelMask mask at +0x28 plays 0x551 and answers -2.  The four
 * direction bits each ask BMP_MENU_MoveCursor to move the cursor with its own
 * sound id; a successful move records the direction at +0x33.  Every
 * direction path answers -1, and a frame with nothing pressed answers -1 as
 * well, spelled off the last mask constant so it costs no extra byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_ProcessInput.c \
 *       --func BMP_MENU_ProcessInput --addr 0x0201FA04 --cc 1.1p1 --thumb
 */
u32 BMP_MENU_ProcessInput(BmpMenu *menu)
{
    u32 pressed = KEY_GetTrg();

    menu->movedDir = 0;

    if (pressed & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return menu->header.items[menu->selected].value;
    }
    if (pressed & menu->cancelMask) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    if (pressed & 0x40) {
        if (BMP_MENU_MoveCursor(menu, 0, 0x548) == 1) {
            menu->movedDir = 1;
        }
        return -1;
    }
    if (pressed & 0x80) {
        if (BMP_MENU_MoveCursor(menu, 1, 0x548) == 1) {
            menu->movedDir = 2;
        }
        return -1;
    }
    if (pressed & 0x20) {
        if (BMP_MENU_MoveCursor(menu, 2, 0x548) == 1) {
            menu->movedDir = 3;
        }
        return -1;
    }
    if (pressed & 0x10) {
        if (BMP_MENU_MoveCursor(menu, 3, 0x548) == 1) {
            menu->movedDir = 4;
        }
        return -1;
    }
    return -1;
}

/*
 * Commit a cursor move: remember where the cursor was, ask BMP_MENU_StepSelection to
 * step it, and on a refusal answer 0 without side effects.  On a move, redraw
 * from the old cell through BMP_MENU_GetItemPixelPos into an on-stack pair, repaint at
 * the new position with BMP_FillRect and play the sound id the caller passed
 * in r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_MoveCursor.c \
 *       --func BMP_MENU_MoveCursor --addr 0x0201FAD0 --cc 1.1p1 --thumb
 */
int BMP_MENU_MoveCursor(BmpMenu *menu, u32 dir, u32 sfxId)
{
    u8 cellXY[2];
    u8 oldSelected;

    oldSelected = menu->selected;
    if (BMP_MENU_StepSelection(menu, dir) == 0) {
        return 0;
    }

    BMP_MENU_GetItemPixelPos(menu, &cellXY[1], &cellXY[0], oldSelected);
    BMP_FillRect(BMP_WIN_GetBmp(menu->header.win), cellXY[1], cellXY[0], menu->xPad,
                  menu->lineHeight, 0xff);
    BMP_MENU_DrawCursor(menu);
    GFL_USE_PlaySeDefaultVolume(sfxId);
    return 1;
}

/*
 * Grid cursor step.  The menu grid is numColumns by itemsPerColumn with a
 * one-byte cursor at +0x2d; the header's wrap bit gates wrapping.  Each of the
 * four directions computes the candidate cell, wraps only when the flag is
 * set, and commits the move only when the entry's second word is not -3.
 * The row/column split needs the real quotient AND remainder, so it reads as
 * one _s32_div_f call per direction, not a division and a modulo.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_StepSelection.c \
 *       --func BMP_MENU_StepSelection --addr 0x0201FB30 --cc 1.1p1 --thumb
 */
int BMP_MENU_StepSelection(BmpMenu *menu, u32 dir)
{
    s8 nextPos;
    u8 perColumn;
    u8 curPos;

    if (dir == 0) {
        perColumn = menu->header.itemsPerColumn;
        if (perColumn <= 1) {
            return 0;
        }
        curPos = menu->selected;
        if (curPos % perColumn == 0) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos + (perColumn - 1));
        } else {
            nextPos = (s8)(curPos - 1);
        }
    } else if (dir == 1) {
        perColumn = menu->header.itemsPerColumn;
        if (perColumn <= 1) {
            return 0;
        }
        curPos = menu->selected;
        if (curPos % perColumn == perColumn - 1) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos - (perColumn - 1));
        } else {
            nextPos = (s8)(curPos + 1);
        }
    } else if (dir == 2) {
        u8 numColumns = menu->header.numColumns;

        if (numColumns <= 1) {
            return 0;
        }
        perColumn = menu->header.itemsPerColumn;
        curPos = menu->selected;
        if (curPos < perColumn) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos + perColumn * (numColumns - 1));
        } else {
            nextPos = (s8)(curPos - perColumn);
        }
    } else {
        u8 numColumns = menu->header.numColumns;

        if (numColumns <= 1) {
            return 0;
        }
        curPos = menu->selected;
        perColumn = menu->header.itemsPerColumn;
        if (curPos >= perColumn * (numColumns - 1)) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos % perColumn);
        } else {
            nextPos = (s8)(curPos + perColumn);
        }
    }

    if (menu->header.items[nextPos].value == -3) {
        return 0;
    }
    menu->selected = (u8)nextPos;
    return 1;
}

u32 BMP_MENU_GetMaxItemWidth(BmpMenu *menu)
{
    u32 maxWidth = 0;
    u8 idx;

    for (idx = 0; idx < menu->header.numColumns * menu->header.itemsPerColumn; idx++) {
        u32 width = (u8)PRINTSYS_MeasureWidestLine((struct Strbuf *)menu->header.items[idx].u.text, menu->header.fontH, 0);

        if (maxWidth < width) {
            maxWidth = width;
        }
    }
    return maxWidth;
}

static inline void PrintUtil_Print(PrintUtil *util, void *que, s32 x, s32 y, const void *str, struct GfFont *font)
{
    PRINTSYS_PrintQue(que, BMP_WIN_GetBmp(util->win), x, y, str, font);
    util->transReq = 1;
}

/*
 * bmp_menu.c: the three drawing helpers the constructor BMP_MENU_Create calls.
 *   BMP_MENU_DrawItems  clear the window bitmap to 0xFF and print every item of
 *                  the numColumns * itemsPerColumn grid (column-major index j + i * itemsPerColumn)
 *                  through the print-util inline (the BMP_CURSOR_Draw shape:
 *                  print via PRINTSYS_PrintQue, then util->transReq = 1).
 *   BMP_MENU_DrawCursor  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   BMP_MENU_GetItemPixelPos  item index -> pixel position: column = pos / itemsPerColumn, row =
 *                  pos % itemsPerColumn.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in BMP_MENU_GetItemPixelPos is `pos % itemsPerColumn`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (BMP_MENU_CreateYesNo
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` BMP_MENU_DrawCursor needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in BMP_MENU_DrawItems.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void BMP_MENU_DrawItems(BmpMenu *menu)
{
    u8 col, row;
    u8 x, colStep;

    BMP_Clear(BMP_WIN_GetBmp(menu->header.win), 0xFF);
    x = menu->originX;
    colStep = menu->colWidth + menu->xPad * 2;
    for (col = 0; col < menu->header.numColumns; col++) {
        for (row = 0; row < menu->header.itemsPerColumn; row++) {
            PrintUtil_Print(menu->header.util, menu->header.que, x,
                            (u8)(menu->originY + row * (menu->lineHeight + menu->header.lineSpacing)),
                            menu->header.items[row + col * menu->header.itemsPerColumn].u.text, menu->header.fontH);
        }
        x += colStep;
    }
}

void BMP_MENU_DrawCursor(BmpMenu *menu)
{
    u8 x, y;

    if (menu->header.cursorMode != 1) {
        BMP_MENU_GetItemPixelPos(menu, &x, &y, menu->selected);
        BMP_CURSOR_Draw((struct MenuCursor *)menu->cursor, (u32)x, (u32)y, (struct MenuTarget *)menu->header.util, menu->header.que, menu->header.fontH);
    }
}

void BMP_MENU_GetItemPixelPos(BmpMenu *menu, u8 *outX, u8 *outY, u8 itemPos)
{
    *outX = (itemPos / menu->header.itemsPerColumn) * (menu->colWidth + menu->xPad * 2);
    *outY = menu->originY + (itemPos % menu->header.itemsPerColumn) * (menu->lineHeight + menu->header.lineSpacing);
}

static inline void PrintUtil_Init(PrintUtil *util, void *cell)
{
    util->win = cell;
    util->transReq = 0;
}

/*
 * bmp_menu.c: the yes/no menu builder (message archive 2 entry 0xE9, a
 * two-item BmpMenuWork list, a BmpMenuHeader filled on the stack, then
 * BMP_MENU_Add and the window upload).  docs/notes/pkt_0201FC5C.c.txt.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 284/284, 2 bytes out for
 * five waves: the r3 home store `str r3, [sp, #0x14]` scheduled after
 * `ldr r4, [sp, #0x50]` / `adds r5, r0, #0`): the fifth (stack) parameter
 * is a heap id and is u16, with u16 on the heap parameter of every callee
 * it is passed to.  docs/idioms/a-u16-stack-parameter-passed-to-a-u16-
 * callee-stays-behind-a-spill-store.md is the same lever; with u16 heap
 * and the old u32 prototypes the body narrows at every call.
 */
BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winData, u16 tileBase, u8 palette, u8 startPos, u16 heapId)
{
    BmpMenuHeader header;
    struct MsgBank *yesNoText;
    BmpMenuWork *items;
    BmpMenu *menu;

    yesNoText = MSGDATA_CreateFromArchive(0, 2, 0xE9, heapId);
    items = BMP_MENUWORK_Create(2, (int)(u16)heapId);
    BMP_MENUWORK_AddMsgItem(items, yesNoText, 0, 0, heapId);
    BMP_MENUWORK_AddMsgItem(items, yesNoText, 1, -2, heapId);
    MSGDATA_Delete(yesNoText);

    MI_CpuFill8(&header, 0, sizeof(header));
    header.items = items;
    header.win = BMP_WIN_Create(winData->bgFrame, winData->x, winData->y, 7, 4, winData->palette, 1);
    header.numColumns = 1;
    header.itemsPerColumn = 2;
    header.lineSpacing = 1;
    header.cursorMode = 0;
    header.wrap = 0;
    header.util = GFL_HEAP_Alloc(heapId, sizeof(PrintUtil), 1, sBmpMenuFile, 0x263);
    header.fontH = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    header.lineHeight = GF_FONT_GetLineHeight(header.fontH);
    header.xPad = 10;
    PrintUtil_Init(header.util, header.win);
#ifdef __MWERKS__
    header.que = PRINTSYS_QUE_Create((void *)heapId);
#else
    header.que = PRINTSYS_QUE_Create((u32)(uptr)(void *)heapId);
#endif
    header.committed = 0;

    menu = BMP_MENU_Add(&header, 0xE, 0, startPos, heapId, 2);
    BMP_WIN_MakeScreen(header.win);
    BMP_MENUWORK_DrawWindow(header.win, 0, tileBase, palette);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(header.win));
    BMP_WIN_TransferChars(header.win);
    return menu;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_MENU_ProcessYesNo.c \
 *       --func BMP_MENU_ProcessYesNo --addr 0x0201FEBC --cc 1.1p1 --thumb
 */
u32 BMP_MENU_ProcessYesNo(BmpMenu *menu)
{
    u32 result = BMP_MENU_ProcessInput(menu);
    u32 printDone = PRINTSYS_QUE_Main(menu->header.que);

    if (menu->header.committed == 0 && printDone != 0) {
        BMP_WIN_TransferChars(menu->header.win);
        menu->header.committed = 1;
    }
    if (result != 0xffffffff) {
        BMP_MENU_DeleteYesNo(menu);
    }
    return result;
}

void BMP_MENU_DeleteYesNo(BmpMenu *menu)
{
    PRINTSYS_QUE_Clear(menu->header.que);
    PRINTSYS_QUE_Delete(menu->header.que);
    GFL_HEAP_Free(menu->header.util);
    BMP_MENUWORK_DrawWindowBorder(menu->header.win, 0);
    GF_FONT_Delete(menu->header.fontH);
    BMP_MENUWORK_Delete(menu->header.items);
    BMP_WIN_Delete(menu->header.win);
    BMP_MENU_Delete(menu, 0);
}
