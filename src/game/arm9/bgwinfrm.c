/*
 * file:     bgwinfrm.c
 * unit:     yes
 * function: BGWINFRM_Create, BGWINFRM_Delete, BGWINFRM_AddFrame, BGWINFRM_SetFrameData, BGWINFRM_SetFrameDataArc, BGWINFRM_SetFrameDataArcHandle, BGWINFRM_PutFrame, BGWINFRM_ShowFrame, BGWINFRM_HideFrame, BGWINFRM_StartMove, BGWINFRM_UpdateMoves, BGWINFRM_UpdateMove, BGWINFRM_IsMoving, BGWINFRM_ChangePalette, BGWINFRM_PutBmpWin, BGWINFRM_GetFrameBuffer, BGWINFRM_GetBgFrame, BGWINFRM_GetPos, BGWINFRM_GetSize, BGWINFRM_SetClipArea, BGWINFRM_EmptyStub, BGWINFRM_ScaleRatio, BGWINFRM_GetScaleRank, POKEGRA_GetArcID, POKEGRA_GetCgrArcIndex, POKEGRA_GetCbrArcIndex, POKEGRA_GetPalArcIndex, POKEGRA_GetCelArcIndex, POKEGRA_GetAnmArcIndex, POKEGRA_GetMCelArcIndex, POKEGRA_GetMAnmArcIndex, POKEGRA_GetNcecArcIndex
 * address:  0x0202C9B4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BgWinFrmFileName  0x020A7790  data
 *   MIi_CpuCopy16  0x02082A60  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive       0x02049EB4  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle       0x02049EF4  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BgWinFrmScreenTransFuncs     0x020A0058  data
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BMP_WIN_GetCharOffset  0x02045768  arm
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   POKEGRA_CalcArcIndex 0x0202D4A8 thumb arm9
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"
#include "bgwinfrm_shared_types.h"

typedef signed char    s8;

struct BgWinFrame {
    u16 *screen;
    u16 sizeX:6;
    u16 sizeY:6;
    u16 hidden:1;
    u16 moveFlag:3;
    s8 x;
    s8 y;
    s8 moveX;
    s8 moveY;
    u8 bgFrame;
    u8 moveCount;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct BgWinFrmWork {
    struct BgWinFrame *frames;
    u16 frameMax;
    u16 transMode : 15;
    u16 moving : 1;
    u32 heapId;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 member, u32 alloc, void **out,
                           u16 heap);

extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, const u16 *a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);

extern void (*BgWinFrmScreenTransFuncs[])(u32);

extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);

extern u8 BMP_WIN_GetPalette(struct Descriptor *p);

extern u8 BMP_WIN_GetWidth(struct Descriptor *p);

extern u8 BMP_WIN_GetHeight(struct Descriptor *p);

extern u8 BMP_WIN_GetPosX(struct Descriptor *p);

extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

struct BgWinFrmWork *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heapId);

void BGWINFRM_Delete(struct BgWinFrmWork *wk);

void BGWINFRM_AddFrame(struct BgWinFrmWork *wk, u32 idx, u32 bgFrame, u32 sizeX, u32 sizeY);

void BGWINFRM_SetFrameData(struct BgWinFrmWork *wk, u32 idx, const void *src);

void BGWINFRM_SetFrameDataArc(struct BgWinFrmWork *wk, u32 idx, u32 arcId, u32 datId, u32 compressed);

void BGWINFRM_SetFrameDataArcHandle(struct BgWinFrmWork *wk, u32 idx, void *arcHandle, u32 datId, u32 compressed);

void BGWINFRM_PutFrame(struct BgWinFrmWork *wk, u32 idx, s8 x, s8 y);

void BGWINFRM_ShowFrame(struct BgWinFrmWork *wk, u32 idx);

void BGWINFRM_HideFrame(struct BgWinFrmWork *wk, u32 idx);

void BGWINFRM_StartMove(struct BgWinFrmWork *wk, u32 idx, s8 moveX, s8 moveY, u8 count);

void BGWINFRM_UpdateMoves(struct BgWinFrmWork *wk);

u32 BGWINFRM_UpdateMove(struct BgWinFrmWork *wk, u32 idx);

u32 BGWINFRM_IsMoving(struct BgWinFrmWork *wk, u32 idx);

void BGWINFRM_ChangePalette(struct BgWinFrmWork *wk, u32 idx, s32 x, s32 y, u8 sizeX, u8 sizeY, u8 palette);

void BGWINFRM_PutBmpWin(struct BgWinFrmWork *wk, u32 idx, void *bmpWin);

u16 *BGWINFRM_GetFrameBuffer(struct BgWinFrmWork *wk, u32 idx);

u8 BGWINFRM_GetBgFrame(struct BgWinFrmWork *wk, u32 idx);

void BGWINFRM_GetPos(struct BgWinFrmWork *wk, u32 idx, s8 *x, s8 *y);

void BGWINFRM_GetSize(struct BgWinFrmWork *wk, u32 idx, u16 *sizeX, u16 *sizeY);

void BGWINFRM_SetClipArea(struct BgWinFrmWork *wk, u32 idx, s8 xmin, s8 xmax, s8 ymin, s8 ymax);

void BGWINFRM_EmptyStub(void);

u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c);

int BGWINFRM_GetScaleRank(u32 a, u32 b);

int POKEGRA_GetArcID(void);

s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);

void POKEGRA_CalcArcIndex(void *arcId, u32 monsNo, s32 formNo, s32 sex, u32 rare, u32 dir, u32 egg, u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare, u32 **outFormPalIndex, u32 isCgr);

extern const char BgWinFrmFileName[];

/*
 * TU: bgwinfrm.c (__FILE__ 0x020A7790, lines 0x56 and 0x5d).
 */
struct BgWinFrmWork *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heapId)
{
    struct BgWinFrmWork *wk;

    wk = GFL_HEAP_Alloc(heapId, sizeof(struct BgWinFrmWork), 0, BgWinFrmFileName, 0x56);
    wk->frameMax = frameMax;
    wk->heapId = heapId;
    wk->transMode = transMode;
    wk->moving = 0;
    wk->frames = GFL_HEAP_Alloc(heapId, frameMax << 4, 1, BgWinFrmFileName, 0x5d);

    return wk;
}

void BGWINFRM_Delete(struct BgWinFrmWork *wk)
{
    u32 i;

    for (i = 0; i < wk->frameMax; i++) {
        if (wk->frames[i].screen != 0) {
            GFL_HEAP_Free(wk->frames[i].screen);
        }
    }
    GFL_HEAP_Free(wk->frames);
    GFL_HEAP_Free(wk);
}

/*
 * Initialises one 16-byte window record: allocates w*h*2 bytes of tile
 * storage from the debug allocator on the manager's own heap id, then
 * writes the two 6-bit size bitfields, the bg index, the scroll pair, the
 * dirty bit and the default clip box (0, 0x20, 0, 0x18).  Same struct BgWinFrame
 * as src/matched/BGWINFRM_SetFrameData.c and src/matched/BGWINFRM_UpdateMove.c.
 *
 * The __FILE__ pool word 0x020A7790 spells "bgwinfrm.c"
 * (layout/file_anchors.txt line 119), which names this unit's source file.
 */
void BGWINFRM_AddFrame(struct BgWinFrmWork *wk, u32 idx, u32 bgFrame, u32 sizeX, u32 sizeY)
{
    struct BgWinFrame *frame = &wk->frames[idx];

    frame->screen = GFL_HEAP_Alloc((u16)wk->heapId, sizeX * sizeY * 2, 1,
                                    BgWinFrmFileName, 0x8a);
    frame->sizeX = (u16)sizeX;
    frame->sizeY = (u16)sizeY;
    frame->bgFrame = (u8)bgFrame;
    frame->x = 0;
    frame->y = 0;
    frame->moveFlag = 0;
    frame->hidden = 1;
    frame->xmin = 0;
    frame->xmax = 0x20;
    frame->ymin = 0;
    frame->ymax = 0x18;
}

void BGWINFRM_SetFrameData(struct BgWinFrmWork *wk, u32 idx, const void *src)
{
    MIi_CpuCopy16(src, (void *)wk->frames[idx].screen,
                  wk->frames[idx].sizeX * wk->frames[idx].sizeY * 2);
}

void BGWINFRM_SetFrameDataArc(struct BgWinFrmWork *wk, u32 idx, u32 arcId, u32 datId, u32 compressed)
{
    void *data;
    void *file;

    file = ARC_UTIL_LoadPaletteDataFromArchive(arcId, datId, compressed, (u32)(&data), wk->heapId);
    BGWINFRM_SetFrameData(wk, idx, (char *)data + 0xc);
    GFL_HEAP_Free(file);
}

void BGWINFRM_SetFrameDataArcHandle(struct BgWinFrmWork *wk, u32 idx, void *arcHandle, u32 datId, u32 compressed)
{
    void *data;
    void *file;

    file = ARC_UTIL_LoadPaletteDataFromHandle(arcHandle, datId, compressed, &data, wk->heapId);
    BGWINFRM_SetFrameData(wk, idx, (char *)data + 0xc);
    GFL_HEAP_Free(file);
}

void BGWINFRM_PutFrame(struct BgWinFrmWork *wk, u32 idx, s8 x, s8 y)
{
    struct BgWinFrame *frame = &wk->frames[idx];
    u8 putX, putSizeX, srcX;
    u8 putY, putSizeY, srcY;
    s32 right, bottom;

    frame->x = x;
    frame->y = y;
    if (x >= frame->xmax) {
        return;
    }
    if (y >= frame->ymax) {
        return;
    }
    right = x + frame->sizeX;
    if (right < frame->xmin) {
        return;
    }
    bottom = y + frame->sizeY;
    if (bottom < frame->ymin) {
        return;
    }

    putX = x;
    putSizeX = frame->sizeX;
    srcX = 0;
    if (x < frame->xmin) {
        putX = frame->xmin;
        srcX = frame->xmin - x;
        putSizeX = putSizeX - srcX;
    }
    if (right >= frame->xmax) {
        putSizeX = putSizeX - (u8)(right - frame->xmax);
    }

    putY = y;
    putSizeY = frame->sizeY;
    srcY = 0;
    if (y < frame->ymin) {
        putY = frame->ymin;
        srcY = frame->ymin - y;
        putSizeY = putSizeY - srcY;
    }
    if (bottom >= frame->ymax) {
        putSizeY = putSizeY - (u8)(bottom - frame->ymax);
    }

    BG_SYS_DrawTileEx(frame->bgFrame, putX, putY, putSizeX, putSizeY, frame->screen, srcX, srcY, frame->sizeX, frame->sizeY);
    BgWinFrmScreenTransFuncs[wk->transMode](frame->bgFrame);
    frame->hidden = 0;
}

void BGWINFRM_ShowFrame(struct BgWinFrmWork *wk, u32 idx)
{
    BGWINFRM_PutFrame(wk, idx, wk->frames[idx].x, wk->frames[idx].y);
}

/*
 * bgwinfrm.c.  Marks a window record dirty, rejects it when it lies wholly
 * outside its clip box (xmin..xmax, ymin..ymax), clips the origin and the
 * size against the box, then blits it through BG_SYS_SetTileEntry and runs the
 * manager's mode callback.  Same struct BgWinFrame as src/matched/BGWINFRM_StartMove.c.
 *
 * What closed it (wave 19): four spelling choices, all required.
 *  - xmax is a named local; the first guard and the right-edge clip read it.
 *  - sx = win->x is written before ow = w, so the sx spill store lands
 *    ahead of ow's sign extension.
 *  - sy is s8: it only ever holds win->y or win->ymin, both s8 fields, so
 *    the narrow type is value-preserving.  With s32 sy the clip copies ymin
 *    between registers; with s8 sy it reloads ymin from its spill slot, as
 *    the image does, and the call's argument stores fall into order.
 *  - Declarations with oh first and sy last.  mwcc numbers spill slots from
 *    the last declared local upward, so sx, h, y, sy must keep that relative
 *    order (slots 0x20, 0x1c, 0x18, 0x14).
 * The callee prototype is the one BG_SYS_SetTileEntry's own body declares.
 */
void BGWINFRM_HideFrame(struct BgWinFrmWork *wk, u32 idx)
{
    struct BgWinFrame *frame = &wk->frames[idx];
    s8 clearSizeY, clearSizeX;
    s32 clearX;
    s32 sizeX, sizeY;
    s32 right, clipRight;
    s32 top, bottom;
    s8 clearY;

    frame->hidden = 1;
    clipRight = frame->xmax;
    if (frame->x >= clipRight) {
        return;
    }
    if (frame->y >= frame->ymax) {
        return;
    }
    sizeX = frame->sizeX;
    right = frame->x + sizeX;
    if (right < frame->xmin) {
        return;
    }
    sizeY = frame->sizeY;
    clearY = frame->y;
    top = clearY;
    bottom = top + sizeY;
    if (bottom < frame->ymin) {
        return;
    }

    clearX = frame->x;
    clearSizeX = sizeX;
    if (frame->x < frame->xmin) {
        clearX = frame->xmin;
        clearSizeX = clearSizeX - (s8)(frame->xmin - frame->x);
    }
    if (right >= clipRight) {
        clearSizeX = clearSizeX - (s8)(right - clipRight);
    }

    clearSizeY = sizeY;
    if (clearY < frame->ymin) {
        clearY = frame->ymin;
        clearSizeY = clearSizeY - (s8)(frame->ymin - top);
    }
    if (bottom >= frame->ymax) {
        clearSizeY = clearSizeY - (s8)(bottom - frame->ymax);
    }

    BG_SYS_SetTileEntry(frame->bgFrame, 0, (u8)clearX, (u8)clearY, (u8)clearSizeX, (u8)clearSizeY, 0x10);
    BgWinFrmScreenTransFuncs[wk->transMode](frame->bgFrame);
}

/*
 * bgwinfrm.c.  Arms the scroll animation on one window record: stores the
 * per-frame delta pair and the frame count, sets the 3-bit unk04_13 field
 * to 1, and raises the manager's top bit at offset 6.  Same struct BgWinFrame as
 * src/matched/BGWINFRM_UpdateMove.c, same struct BgWinFrmWork as
 * src/matched/BGWINFRM_PutFrame.c.
 */
void BGWINFRM_StartMove(struct BgWinFrmWork *wk, u32 idx, s8 moveX, s8 moveY, u8 count)
{
    struct BgWinFrame *frame = &wk->frames[idx];

    frame->moveX = moveX;
    frame->moveY = moveY;
    frame->moveCount = count;
    frame->moveFlag = 1;
    wk->moving = 1;
}

void BGWINFRM_UpdateMoves(struct BgWinFrmWork *wk)
{
    u32 i;

    if (!wk->moving) return;
    wk->moving = 0;
    for (i = 0; i < wk->frameMax; i++) {
        if (BGWINFRM_UpdateMove(wk, i) == 1) wk->moving = 1;
    }
}

u32 BGWINFRM_UpdateMove(struct BgWinFrmWork *wk, u32 idx)
{
    if (wk->frames[idx].moveFlag == 0) {
        return 0;
    }

    BGWINFRM_HideFrame(wk, idx);
    wk->frames[idx].x = wk->frames[idx].x + wk->frames[idx].moveX;
    wk->frames[idx].y = wk->frames[idx].y + wk->frames[idx].moveY;
    BGWINFRM_ShowFrame(wk, idx);
    wk->frames[idx].moveCount = wk->frames[idx].moveCount - 1;
    if (wk->frames[idx].moveCount == 0) {
        wk->frames[idx].moveFlag = 0;
        return 0;
    }
    return 1;
}

u32 BGWINFRM_IsMoving(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].moveFlag;
}

void BGWINFRM_ChangePalette(struct BgWinFrmWork *wk, u32 idx, s32 x, s32 y,
                   u8 sizeX, u8 sizeY, u8 palette)
{
    u16 *screen = wk->frames[idx].screen;
    u32 rowSize = wk->frames[idx].sizeX;
    s32 bottom = y + sizeY;
    s32 column;

    if (y < bottom) {
        u32 palBits = palette << 12;
        s32 right = x + sizeX;

        do {
            for (column = x; column < right; column = (u16)(column + 1)) {
                screen[y * rowSize + column] = (screen[y * rowSize + column] & 0x0fff)
                                      | palBits;
            }
            y = (u16)(y + 1);
        } while (y < bottom);
    }
}

void BGWINFRM_PutBmpWin(struct BgWinFrmWork *wk, u32 idx, void *bmpWin)
{
    u16 *screen = wk->frames[idx].screen;
    u32 rowSize = wk->frames[idx].sizeX;
    u32 charRow;
    u32 charY;
    u32 charX;
    u32 palBits;
    u16 *dstStart;
    s32 charSizeY;
    u32 charNo;
    s32 charSizeX;

    charNo = BMP_WIN_GetCharOffset(bmpWin);
    palBits = ((u32)BMP_WIN_GetPalette(bmpWin) << 0x1c) >> 0x10;
    charSizeX = BMP_WIN_GetWidth(bmpWin);
    charSizeY = BMP_WIN_GetHeight(bmpWin);
    charX = BMP_WIN_GetPosX(bmpWin);
    charY = BMP_WIN_GetPosY(bmpWin);
    charRow = 0;

    if (charSizeY > 0) {
        dstStart = screen + charX;

        do {
            s32 y = charY + charRow;
            s32 charCol;

            if (y >= wk->frames[idx].sizeY) {
                break;
            }
            charCol = 0;
            if (charSizeX > 0) {
                u16 *dstLine = dstStart + rowSize * y;

                do {
                    if ((s32)(charX + charCol) >= (s32)wk->frames[idx].sizeX) {
                        break;
                    }
                    dstLine[charCol] = palBits + (charNo + charCol);
                    charCol = (u16)(charCol + 1);
                } while (charCol < charSizeX);
            }
            charNo = (u16)(charNo + charSizeX);
            charRow = (u16)(charRow + 1);
        } while ((s32)charRow < charSizeY);
    }
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct BgWinFrame as
 * src/matched/BGWINFRM_UpdateMove.c.  All leaves; the unit calls nothing.
 */
u16 *BGWINFRM_GetFrameBuffer(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].screen;
}

u8 BGWINFRM_GetBgFrame(struct BgWinFrmWork *wk, u32 idx)
{
    return wk->frames[idx].bgFrame;
}

void BGWINFRM_GetPos(struct BgWinFrmWork *wk, u32 idx, s8 *x, s8 *y)
{
    if (x != 0) {
        *x = wk->frames[idx].x;
    }
    if (y != 0) {
        *y = wk->frames[idx].y;
    }
}

void BGWINFRM_GetSize(struct BgWinFrmWork *wk, u32 idx, u16 *sizeX, u16 *sizeY)
{
    if (sizeX != 0) {
        *sizeX = wk->frames[idx].sizeX;
    }
    if (sizeY != 0) {
        *sizeY = wk->frames[idx].sizeY;
    }
}

void BGWINFRM_SetClipArea(struct BgWinFrmWork *wk, u32 idx, s8 xmin, s8 xmax,
                   s8 ymin, s8 ymax)
{
    wk->frames[idx].xmin = xmin;
    wk->frames[idx].xmax = xmax;
    wk->frames[idx].ymin = ymin;
    wk->frames[idx].ymax = ymax;
}

void BGWINFRM_EmptyStub(void)
{
}

u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c)
{
    u8 res = (a * c) / b;

    if (res != 0 || a == 0) {
        return res;
    }
    return 1;
}

int BGWINFRM_GetScaleRank(u32 a, u32 b)
{
    a <<= 8;
    b <<= 8;

    if (a > b / 2) {
        return 0;
    }
    if (a > b / 5) {
        return 1;
    }
    if (a != 0) {
        return 2;
    }
    return 3;
}

int POKEGRA_GetArcID(void){ return 4; }

/*
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 1);
    return sexOffset + (index + dirOffset);
}

s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;
    s32 sexOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), (u32 *)(&sexOffset), 0, 0, 0);
    return sexOffset + (index + dirOffset + 2);
}

/*
 * One of a family of thin wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8: it forwards its own three stack
 * arguments, hands the callee out-pointers for two width accumulators and
 * a status word, and folds the results into a single returned extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKEGRA_GetPalArcIndex.c \
 *       --func POKEGRA_GetPalArcIndex --addr 0x0202D0D4 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 rareOffset;
    s32 palIndex;

    palIndex = 0;
    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), 0, 0, (u32 *)(&rareOffset), (u32 **)(&palIndex), 0);
    if (palIndex == 0) {
        palIndex = index + 0x12 + rareOffset;
    }
    return palIndex;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 4;
}

s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 5;
}

s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 6;
}

/*
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */
s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 7;
}

s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg)
{
    s32 index;
    s32 dirOffset;

    POKEGRA_CalcArcIndex((void *)arcId, monsNo, formNo, sex, rare, dir, egg, (u32 *)(&index), (u32 *)(&dirOffset), 0, 0, 0, 0);
    return index + dirOffset + 8;
}
