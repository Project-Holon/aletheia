/*
 * file:     talkmsgwin.c
 * unit:     yes
 * function: TALKMSGWIN_Create, TALKMSGWIN_LoadTexture, TALKMSGWIN_Update, TALKMSGWIN_EndUpdate, TALKMSGWIN_Draw, TALKMSGWIN_Delete, TALKMSGWIN_SetupPlainWindow, TALKMSGWIN_SetupUpperBalloon, TALKMSGWIN_SetupLowerBalloon, TALKMSGWIN_SetupAutoBalloon, TALKMSGWIN_Release, TALKMSGWIN_Open, TALKMSGWIN_Close, TALKMSGWIN_IsFree, TALKMSGWIN_IsShown, TALKMSGWIN_GetPrintStream, TALKMSGWIN_GetBmpWin, TALKMSGWIN_Reprint, TALKMSGWIN_AddFrameWindow, TALKMSGWIN_DrawWindowFrame, TALKMSGWIN_ClearWindowFrame, TALKMSGWIN_DeleteFrameWindow, TALKMSGWIN_InitEntry, TALKMSGWIN_IsEntryFree, TALKMSGWIN_IsEntryShown, TALKMSGWIN_AddBmpWin, TALKMSGWIN_SetupEntry, TALKMSGWIN_ReleaseEntry, TALKMSGWIN_RequestOpen, TALKMSGWIN_RequestClose, TALKMSGWIN_UpdateBalloon, TALKMSGWIN_UpdatePlainWindow, TALKMSGWIN_DrawEntry, TALKMSGWIN_DrawBalloonShape, TALKMSGWIN_ProjectToWorld, TALKMSGWIN_GetAnchorWindowPoint, TALKMSGWIN_GetTailBaseX, TALKMSGWIN_CalcTail, TALKMSGWIN_GetWindowCornerPoints, TALKMSGWIN_BuildShape, TALKMSGWIN_UpdateShape, TALKMSGWIN_SetupCamera, TALKMSGWIN_SaveCamera, TALKMSGWIN_RestoreCamera, TALKMSGWIN_LoadFrameGraphics, TALKMSGWIN_UploadTexture, TALKMSGWIN_ReloadFrameGraphics, TALKMSGWIN_DrawSimpleFrame, TALKMSGWIN_DrawCorneredFrame, TALKMSGWIN_DrawFrameByType, TALKMSGWIN_DrawEntryFrame, TALKMSGWIN_RedrawEntryFrame, TALKMSGWIN_ClearFrame
 * address:  0x02194670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_wfbc.c at 0x02194670 (lane CL120, __FILE__ anchors).
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm  arm9
 *   func_020307B0  0x020307B0  arm
 *   TCBL_Create  0x0203101C  arm
 *   sTalkMsgWinFileName     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 *   TCBL_Main  0x020310C4  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   d_020A814C     0x020A814C  data  a4
 *   d_020A8144     0x020A8144  data  a4
 *   TCBL_Destroy  0x02031140  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   func_020409B4  0x020409B4  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_0206E0C4  0x0206E0C4  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetDispWidth  0x02045748  arm
 *   BMP_WIN_GetDispHeight  0x02045750  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02040804  0x02040804  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B54  0x02048B54  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 *   sTalkMsgWinTexture     0x021DDA84  data  a4
 *   sTalkMsgWinPalette     0x021DDAA4  data  a4
 *   func_02041300  0x02041300  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 */
#include "talkmsgwin_types.h"

#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)
#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_MTX_TRANS       (*(volatile u32 *)0x04000470)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)
#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)
#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)

extern s32 func_0207C768(s32 numerator, s32 denominator);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void TCBL_Main(struct Tcbl *tcbl);
extern void NNS_G3dGeFlushBuffer(void);
extern void TCBL_Destroy(struct Tcbl *tcbl);
extern void func_0206DF3C(const VecFx32 *worldPos, int *screenX, int *screenY);
extern void PRINTSYS_PrintStreamDelete(struct PrintStream *stream);
extern struct PrintStream *PRINTSYS_PrintStream(struct BmpWin *bmpWin, u32 x, u32 y, struct Strbuf *str, struct GfFont *font,
                                         u32 wait, struct Tcbl *tcbl, u32 tcblPri, u32 heapId, u32 clearColor);
extern void func_020409B4(u32 bgLayer);
extern void BMP_WIN_Delete(struct BmpWin *bmpWin);
extern struct BmpWin *BMP_WIN_Create(u32 bgFrame, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 slotId);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *bmpWin);
extern void BMP_Clear(struct Bmp *bmp, u8 color);
extern void BMP_WIN_TransferChars(struct BmpWin *bmpWin);
extern int func_0206E0C4(int screenX, int screenY, VecFx32 *out, int mode);
extern u8 BMP_WIN_GetPosX(struct BmpWin *bmpWin);
extern u8 BMP_WIN_GetPosY(struct BmpWin *bmpWin);
extern u8 BMP_WIN_GetDispWidth(struct BmpWin *bmpWin);
extern u8 BMP_WIN_GetDispHeight(struct BmpWin *bmpWin);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *bmpWin);
extern u32 func_02040804(u32 bgLayer);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern int func_0207CBD0(const VecFx32 *v);
extern void func_02048AFC(struct G3dCamera *camera, const VecFx32 *eye);
extern void func_02048B20(struct G3dCamera *camera, const VecFx32 *vec);
extern void func_02048B44(struct G3dCamera *camera, const VecFx32 *vec);
extern void func_02048B60(struct G3dCamera *camera, const s32 *scale);
extern void func_02048AD0(struct G3dCamera *camera);
extern void func_0207D7C4(const VecFx32 *eye, const VecFx32 *up, const VecFx32 *target, int a, int b);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B54(struct G3dCamera *camera, s32 *out);
extern void func_020414EC(u32 bgLayer);
extern void func_02049B40(u32 arcId, u32 fileId, u32 palBase, u32 byteOffset, u32 byteSize, u16 heapId);
extern u32 func_02049624(u32 arcId, u32 fileId, u32 layer, u32 tileOffset, u32 flagA, u32 flagB, u16 heapId);
extern void func_0207F7A0(void);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207F7FC(void *src, u32 offset, u32 size);
extern void func_0207F9B4(void);
extern void func_0207FA0C(void);
extern void func_0207FA40(void *src, u32 offset, u32 size);
extern void func_0207FADC(void);
extern void BMP_WIN_MakeScreen(struct BmpWin *bmpWin);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void BMP_WIN_ClearScreen(struct BmpWin *bmpWin);

TalkMsgWinSys *TALKMSGWIN_Create(const TalkMsgWinParam *param);
void TALKMSGWIN_LoadTexture(TalkMsgWinSys *sys);
void TALKMSGWIN_Update(TalkMsgWinSys *sys);
void TALKMSGWIN_EndUpdate(TalkMsgWinSys *sys);
void TALKMSGWIN_Draw(TalkMsgWinSys *sys);
void TALKMSGWIN_Delete(TalkMsgWinSys *sys);
void TALKMSGWIN_SetupPlainWindow(TalkMsgWinSys *sys, int index, struct Strbuf *str, u8 x, u8 y, u8 width, u8 height, u32 unusedColor,
                   u32 frameType, u32 wait, u8 textX, u8 textY);
void TALKMSGWIN_SetupUpperBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType,
                   u32 tailSide, u32 wait);
void TALKMSGWIN_SetupLowerBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType,
                   u32 tailSide, u32 wait);
void TALKMSGWIN_SetupAutoBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u8 unusedColor, u32 frameType,
                   u32 wait);
void TALKMSGWIN_Release(TalkMsgWinSys *sys, int index);
void TALKMSGWIN_Open(TalkMsgWinSys *sys, int index);
void TALKMSGWIN_Close(TalkMsgWinSys *sys, int index);
u32 TALKMSGWIN_IsFree(TalkMsgWinSys *sys, u32 index, u32 unused1, u32 unused2);
int TALKMSGWIN_IsShown(TalkMsgWinSys *sys, int index);
struct PrintStream *TALKMSGWIN_GetPrintStream(TalkMsgWinSys *sys, u32 index);
struct BmpWin *TALKMSGWIN_GetBmpWin(TalkMsgWinSys *sys, u32 index);
void TALKMSGWIN_Reprint(TalkMsgWinSys *sys, int index, struct Strbuf *str, u32 wait);
struct BmpWin *TALKMSGWIN_AddFrameWindow(TalkMsgWinSys *sys, u8 x, u8 y, u8 width, u8 height, u32 frameType);
void TALKMSGWIN_DrawWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin, u32 frameType, u32 unused);
void TALKMSGWIN_ClearWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin);
void TALKMSGWIN_DeleteFrameWindow(TalkMsgWinSys *sys, struct BmpWin *bmpWin);
TalkMsgWin *TALKMSGWIN_InitEntry(TalkMsgWin *win);
int TALKMSGWIN_IsEntryFree(TalkMsgWin *win);
int TALKMSGWIN_IsEntryShown(TalkMsgWin *win);
struct BmpWin *TALKMSGWIN_AddBmpWin(TalkMsgWinSys *sys, u8 x, u8 y, int width, u8 height);
void TALKMSGWIN_SetupEntry(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *pos, struct Strbuf *str, const TalkMsgWinConfig *config);
void TALKMSGWIN_ReleaseEntry(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_RequestOpen(TalkMsgWin *win);
void TALKMSGWIN_RequestClose(TalkMsgWin *win);
void TALKMSGWIN_UpdateBalloon(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_UpdatePlainWindow(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_DrawEntry(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_DrawBalloonShape(TalkMsgWinSys *sys, TalkMsgWin *win, int tailOnly);
int TALKMSGWIN_ProjectToWorld(const VecFx32 *relPos, int *screenX, int *screenY, VecFx32 *outWorld);
void TALKMSGWIN_GetAnchorWindowPoint(TalkMsgWin *win, TalkMsgWin *anchor, int *screenX, int *screenY, VecFx32 *outWorld);
void TALKMSGWIN_GetTailBaseX(int x, int w, int side, u16 *left, u16 *right);
int TALKMSGWIN_CalcTail(TalkMsgWin *win, int targetX, int targetY, VecFx32 *outBaseA, VecFx32 *outBaseB);
void TALKMSGWIN_GetWindowCornerPoints(TalkMsgWin *win, VecFx32 *outTopLeft, VecFx32 *outTopRight, VecFx32 *outBottomLeft, VecFx32 *outBottomRight);
void TALKMSGWIN_BuildShape(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *tip, VecFx32 *tailBaseA, VecFx32 *tailBaseB,
                   VecFx32 *topLeft, VecFx32 *topRight, VecFx32 *bottomLeft, VecFx32 *bottomRight);
u32 TALKMSGWIN_UpdateShape(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_SetupCamera(TalkMsgWinSys *sys, int useCameraObject);
void TALKMSGWIN_SaveCamera(TalkMsgWinSys *sys);
void TALKMSGWIN_RestoreCamera(TalkMsgWinSys *sys);
u32 TALKMSGWIN_LoadFrameGraphics(TalkMsgWinSys *sys, TalkMsgWinParam *param);
void TALKMSGWIN_UploadTexture(TalkMsgWinSys *sys);
void TALKMSGWIN_ReloadFrameGraphics(TalkMsgWinSys *sys);
void TALKMSGWIN_DrawSimpleFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide);
void TALKMSGWIN_DrawCorneredFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide);
void TALKMSGWIN_DrawFrameByType(const TalkMsgWinParam *style, struct BmpWin *bmpWin, u8 frameType, u32 tailSide);
void TALKMSGWIN_DrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_RedrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_ClearFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin);

extern const char sTalkMsgWinFileName[];   /* source file name string passed to the heap allocator */
extern u32 sTalkMsgWinTexture[];      /* balloon texture, one 4bpp tile (0x20 bytes) */
extern u32 sTalkMsgWinPalette[];      /* balloon palette, 16 colors */
extern u32 (*d_020A8140)(int, int, int);   /* texture VRAM allocator */
extern u32 (*d_020A8148)(int, int, int);   /* palette VRAM allocator */
extern void (*d_020A814C)(u32 key);        /* palette VRAM free */
extern void (*d_020A8144)(u32 key);        /* texture VRAM free */

TalkMsgWinSys *TALKMSGWIN_Create(const TalkMsgWinParam *param)
{
    TalkMsgWinSys *sys;
    int i;

    sys = func_02030734(param->heapId, sizeof(TalkMsgWinSys), 1, sTalkMsgWinFileName, 0xec);
    sys->param = *param;
    sys->tcbl = TCBL_Create(param->heapId, param->heapId, TALKMSGWIN_MAX, 0x20);
    for (i = 0; i < TALKMSGWIN_MAX; i++)
        TALKMSGWIN_InitEntry(&sys->windows[i]);
    sys->texKey = d_020A8140(0x20, 0, 0);
    sys->plttKey = d_020A8148(0x20, 0, 0);
    sys->frameTileCount = TALKMSGWIN_LoadFrameGraphics(sys, &sys->param) >> 5;
    return sys;
}

/* Tail call to the balloon texture upload. */
void TALKMSGWIN_LoadTexture(TalkMsgWinSys *sys)
{
    TALKMSGWIN_UploadTexture(sys);
}

void TALKMSGWIN_Update(TalkMsgWinSys *sys)
{
    int i;

    TCBL_Main(sys->tcbl);
    TALKMSGWIN_SaveCamera(sys);
    TALKMSGWIN_SetupCamera(sys, 0);
    for (i = 0; i < TALKMSGWIN_MAX; i++) {
        if (sys->windows[i].isPlain == 0)
            TALKMSGWIN_UpdateBalloon(sys, &sys->windows[i]);
        else
            TALKMSGWIN_UpdatePlainWindow(sys, &sys->windows[i]);
    }
    TALKMSGWIN_RestoreCamera(sys);
}

/* Empty; field_msgbg.c calls it after every update. */
void TALKMSGWIN_EndUpdate(TalkMsgWinSys *sys)
{
}

void TALKMSGWIN_Draw(TalkMsgWinSys *sys)
{
    int i;

    NNS_G3dGeFlushBuffer();
    TALKMSGWIN_SetupCamera(sys, 1);
    for (i = 0; i < TALKMSGWIN_MAX; i++) {
        if (sys->windows[i].isPlain == 0) {
            TALKMSGWIN_DrawEntry(sys, &sys->windows[i]);
        }
    }
}

void TALKMSGWIN_Delete(TalkMsgWinSys *sys)
{
    int i;

    for (i = 0; i < TALKMSGWIN_MAX; i++)
        TALKMSGWIN_ReleaseEntry(sys, &sys->windows[i]);
    d_020A814C(sys->plttKey);
    d_020A8144(sys->texKey);
    TCBL_Destroy(sys->tcbl);
    func_020307B0(sys);
}

/* Plain text window: no balloon polygon, frame only. */
void TALKMSGWIN_SetupPlainWindow(TalkMsgWinSys *sys, int index, struct Strbuf *str, u8 x, u8 y, u8 width, u8 height, u32 unusedColor,
                   u32 frameType, u32 wait, u8 textX, u8 textY)
{
    TalkMsgWinConfig config;
    TalkMsgWin *win;

    config.tailMode = TALKMSGWIN_TAIL_MODE_AUTO;
    config.tailSide = 0;
    config.x = x;
    config.y = y;
    config.width = width;
    config.height = height;
    config.color = 0x7FFF;
    config.frameType = frameType;
    config.printWait = wait;
    win = &sys->windows[index];
    TALKMSGWIN_SetupEntry(sys, win, 0, str, &config);
    win->textX = textX;
    win->textY = textY;
    win->isPlain = 1;
}

/* Balloon in the upper rows; the tail leaves its lower edge. */
void TALKMSGWIN_SetupUpperBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType,
                   u32 tailSide, u32 wait)
{
    TalkMsgWinConfig config;

    config.tailMode = TALKMSGWIN_TAIL_MODE_LOWER_EDGE;
    config.tailSide = tailSide;
    config.x = 1;
    config.y = 1;
    config.width = 0x1E;
    config.height = 4;
    config.color = 0x7FFF;
    config.frameType = frameType;
    config.printWait = wait;
    TALKMSGWIN_SetupEntry(sys, &sys->windows[index], pos, str, &config);
}

/* Balloon in the lower rows; the tail leaves its upper edge. */
void TALKMSGWIN_SetupLowerBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType,
                   u32 tailSide, u32 wait)
{
    TalkMsgWinConfig config;

    config.tailMode = TALKMSGWIN_TAIL_MODE_UPPER_EDGE;
    config.tailSide = tailSide;
    config.x = 1;
    config.y = 0x13;
    config.width = 0x1E;
    config.height = 4;
    config.color = 0x7FFF;
    config.frameType = frameType;
    config.printWait = wait;
    TALKMSGWIN_SetupEntry(sys, &sys->windows[index], pos, str, &config);
}

/* Puts the balloon on the screen half away from the target position. */
void TALKMSGWIN_SetupAutoBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u8 unusedColor, u32 frameType,
                   u32 wait)
{
    int screenX;
    int screenY;

    func_0206DF3C(pos, &screenX, &screenY);
    if (screenY < 0x60)
        TALKMSGWIN_SetupLowerBalloon(sys, index, pos, str, unusedColor, frameType, 0, wait);
    else
        TALKMSGWIN_SetupUpperBalloon(sys, index, pos, str, unusedColor, frameType, 0, wait);
}

void TALKMSGWIN_Release(TalkMsgWinSys *sys, int index)
{
    TALKMSGWIN_ReleaseEntry(sys, &sys->windows[index]);
}

void TALKMSGWIN_Open(TalkMsgWinSys *sys, int index)
{
    TALKMSGWIN_RequestOpen(&sys->windows[index]);
}

void TALKMSGWIN_Close(TalkMsgWinSys *sys, int index)
{
    TALKMSGWIN_RequestClose(&sys->windows[index]);
}

u32 TALKMSGWIN_IsFree(TalkMsgWinSys *sys, u32 index, u32 unused1, u32 unused2)
{
    if (sys->windows[index].state == TALKMSGWIN_STATE_FREE) {
        return 1;
    }
    return 0;
}

int TALKMSGWIN_IsShown(TalkMsgWinSys *sys, int index)
{
    return TALKMSGWIN_IsEntryShown(&sys->windows[index]);
}

struct PrintStream *TALKMSGWIN_GetPrintStream(TalkMsgWinSys *sys, u32 index)
{
    return sys->windows[index].printStream;
}

struct BmpWin *TALKMSGWIN_GetBmpWin(TalkMsgWinSys *sys, u32 index)
{
    return sys->windows[index].bmpWin;
}

/* Replaces the text of a window and starts printing it. */
void TALKMSGWIN_Reprint(TalkMsgWinSys *sys, int index, struct Strbuf *str, u32 wait)
{
    TalkMsgWin *win;

    win = &sys->windows[index];
    if (win->printStream != 0) {
        PRINTSYS_PrintStreamDelete(win->printStream);
        win->printStream = 0;
    }
    if (str != 0) {
        win->printWait = wait;
        win->str = str;
        win->printStream = PRINTSYS_PrintStream(win->bmpWin, win->textX, win->textY, win->str, sys->param.font, wait,
                                         sys->tcbl, 0, sys->param.heapId, 15);
        win->state = TALKMSGWIN_STATE_SHOWN;
    }
}

/* Adds a text window that carries only a frame, no balloon. */
struct BmpWin *TALKMSGWIN_AddFrameWindow(TalkMsgWinSys *sys, u8 x, u8 y, u8 width, u8 height, u32 frameType)
{
    struct BmpWin *bmpWin;

    bmpWin = TALKMSGWIN_AddBmpWin(sys, x, y, width, height);
    TALKMSGWIN_DrawFrameByType(&sys->param, bmpWin, frameType, 0);
    return bmpWin;
}

void TALKMSGWIN_DrawWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin, u32 frameType, u32 unused)
{
    TALKMSGWIN_DrawFrameByType(&sys->param, bmpWin, frameType, 0);
}

void TALKMSGWIN_ClearWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin)
{
    TALKMSGWIN_ClearFrame(&sys->param, bmpWin);
    func_020409B4((u8)sys->param.bgLayer);
}

void TALKMSGWIN_DeleteFrameWindow(TalkMsgWinSys *sys, struct BmpWin *bmpWin)
{
    TALKMSGWIN_ClearFrame(&sys->param, bmpWin);
    BMP_WIN_Delete(bmpWin);
}

TalkMsgWin *TALKMSGWIN_InitEntry(TalkMsgWin *win)
{
    win->state = TALKMSGWIN_STATE_FREE;
    win->printStream = 0;
    win->shape.tip.x = 0;
    win->shape.tip.y = 0;
    win->shape.tip.z = 0;
    win->shape.tailBaseA.x = 0;
    win->shape.tailBaseA.y = 0;
    win->shape.tailBaseA.z = 0;
    win->shape.tailBaseB.x = 0;
    win->shape.tailBaseB.y = 0;
    win->shape.tailBaseB.z = 0;
    return win;
}

int TALKMSGWIN_IsEntryFree(TalkMsgWin *win)
{
    if (win->state == TALKMSGWIN_STATE_FREE) {
        return 1;
    }
    return 0;
}

int TALKMSGWIN_IsEntryShown(TalkMsgWin *win)
{
    return win->state == TALKMSGWIN_STATE_SHOWN;
}

/* Creates the BG window of a balloon, cleared to color 15. */
struct BmpWin *TALKMSGWIN_AddBmpWin(TalkMsgWinSys *sys, u8 x, u8 y, int width, u8 height)
{
    struct BmpWin *bmpWin;

    bmpWin = BMP_WIN_Create((u8)sys->param.bgLayer, x, y, width, height, sys->param.bmpWinPalette, 1);
    BMP_Clear(BMP_WIN_GetBmp(bmpWin), 15);
    BMP_WIN_TransferChars(bmpWin);
    return bmpWin;
}

void TALKMSGWIN_SetupEntry(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *pos, struct Strbuf *str, const TalkMsgWinConfig *config)
{
    int width;
    u8 height;
    int y;
    u8 x;

    TALKMSGWIN_ReleaseEntry(sys, win);
    win->targetPos = pos;
    win->str = str;
    win->color = config->color;
    win->anchorIndex = 0;
    win->tailMode = config->tailMode;
    win->frameType = config->frameType;
    win->printWait = config->printWait;
    width = config->width;
    x = config->x;
    x = (x + width > 0x20) ? 0x20 - width : x;
    height = config->height;
    y = config->y;
    if (y + height > 0x18)
        y = 0x18 - height;
    win->bmpWin = TALKMSGWIN_AddBmpWin(sys, x, y, width, height);
    win->shape.tailSide = config->tailSide;
    win->textX = 8;
    win->textY = 0;
    win->state = TALKMSGWIN_STATE_READY;
}

/* Releases the text stream, the frame and the BG window of a used window. */
void TALKMSGWIN_ReleaseEntry(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    if (TALKMSGWIN_IsEntryFree(win) == 0) {
        if (win->printStream != 0) {
            PRINTSYS_PrintStreamDelete(win->printStream);
            win->printStream = 0;
        }
        TALKMSGWIN_ClearFrame(&sys->param, win->bmpWin);
        BMP_WIN_Delete(win->bmpWin);
        win->isPlain = 0;
        win->state = TALKMSGWIN_STATE_FREE;
    }
}

void TALKMSGWIN_RequestOpen(TalkMsgWin *win)
{
    win->state = TALKMSGWIN_STATE_OPEN_REQUEST;
}

void TALKMSGWIN_RequestClose(TalkMsgWin *win)
{
    win->state = TALKMSGWIN_STATE_CLOSE_REQUEST;
    win->scaleEighths = 4;
}

/* Per-frame update of a balloon window: grow, print, shrink, release. */
void TALKMSGWIN_UpdateBalloon(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    u32 wait;

    switch (win->state) {
    case TALKMSGWIN_STATE_FREE:
    case TALKMSGWIN_STATE_READY:
        break;
    case TALKMSGWIN_STATE_OPEN_REQUEST:
        TALKMSGWIN_UpdateShape(sys, win);
        win->scaleEighths = 0;
        win->state = TALKMSGWIN_STATE_OPENING;
        return;
    case TALKMSGWIN_STATE_OPENING:
        TALKMSGWIN_UpdateShape(sys, win);
        if (win->scaleEighths < 8) {
            win->scaleEighths += 1;
            return;
        }
        win->state = TALKMSGWIN_STATE_SHOWN;
        wait = win->printWait;
        TALKMSGWIN_RedrawEntryFrame(sys, win);
        win->printStream = PRINTSYS_PrintStream(win->bmpWin, win->textX, win->textY, win->str, sys->param.font, wait,
                                         sys->tcbl, 0, sys->param.heapId, 15);
        return;
    case TALKMSGWIN_STATE_SHOWN:
        if (TALKMSGWIN_UpdateShape(sys, win) == 1) {
            TALKMSGWIN_RedrawEntryFrame(sys, win);
        }
        return;
    case TALKMSGWIN_STATE_CLOSE_REQUEST:
        if (win->scaleEighths != 0) {
            win->scaleEighths -= 1;
            return;
        }
        win->state = TALKMSGWIN_STATE_CLOSED;
        return;
    case TALKMSGWIN_STATE_CLOSED:
        TALKMSGWIN_ReleaseEntry(sys, win);
        return;
    }
}

/* Per-frame update of a plain window: it opens at once, without the grow steps. */
void TALKMSGWIN_UpdatePlainWindow(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    u32 wait;

    switch (win->state) {
    case TALKMSGWIN_STATE_OPEN_REQUEST:
        win->scaleEighths = 0;
        win->state = TALKMSGWIN_STATE_OPENING;
    case TALKMSGWIN_STATE_OPENING:
        win->state = TALKMSGWIN_STATE_SHOWN;
        wait = win->printWait;
        TALKMSGWIN_DrawEntryFrame(sys, win);
        win->printStream = PRINTSYS_PrintStream(win->bmpWin, win->textX, win->textY, win->str, sys->param.font, wait,
                                         sys->tcbl, 0, sys->param.heapId, 15);
        return;
    case TALKMSGWIN_STATE_CLOSE_REQUEST:
        win->state = TALKMSGWIN_STATE_CLOSED;
        return;
    case TALKMSGWIN_STATE_CLOSED:
        TALKMSGWIN_ReleaseEntry(sys, win);
        return;
    }
}

/* Draws the balloon polygon of a window that is growing or shown. */
void TALKMSGWIN_DrawEntry(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    switch (win->state) {
    case TALKMSGWIN_STATE_FREE:
    case TALKMSGWIN_STATE_READY:
    case TALKMSGWIN_STATE_OPEN_REQUEST:
    case TALKMSGWIN_STATE_CLOSE_REQUEST:
    case TALKMSGWIN_STATE_CLOSED:
        break;
    case TALKMSGWIN_STATE_OPENING:
        TALKMSGWIN_DrawBalloonShape(sys, win, 0);
        break;
    case TALKMSGWIN_STATE_SHOWN:
        TALKMSGWIN_DrawBalloonShape(sys, win, 1);
        break;
    }
}

static inline void G3_Translate(s32 x, s32 y, s32 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(s32 x, s32 y, s32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}

static inline void G3_TexCoord(s32 s, s32 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}

static inline void G3_Vtx(s16 x, s16 y, s16 z)
{
    reg_G3_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    reg_G3_VTX_16 = (u32)(u16)z;
}

/*
 * Immediate-mode draw of one balloon through the geometry engine registers:
 * push, translate to the target point, uniform scale, texture and palette from
 * the system's VRAM keys, material, polygon attributes, the tail triangle
 * (tip, base A, base B) when the shape has a tail side and, unless tailOnly,
 * the window quad (top left, top right, bottom left, bottom right); then pop.
 *
 * What closed the match: the SDK G3_Vtx / G3_TexCoord inline shapes, a
 * sub-struct pointer for the shape (the image keeps it in r6), translate loaded
 * z, y, x into locals, and non-const parameters (with const the loads float
 * across the volatile stores).
 */
void TALKMSGWIN_DrawBalloonShape(TalkMsgWinSys *sys, TalkMsgWin *win, int tailOnly)
{
    TalkMsgWinShape *shape = &win->shape;
    s32 x, y, z;
    s32 scale;

    reg_G3_MTX_PUSH = 0;
    z = shape->origin.z;
    y = shape->origin.y;
    x = shape->origin.x;
    G3_Translate(x, y, z);
    scale = shape->scale * win->scaleEighths / 8;
    G3_Scale(scale, scale, scale);
    reg_G3_TEXIMAGE_PARAM = (((u16)sys->texKey & 0x1FFFFFFF)) | 0x0C030000;
    reg_G3_TEXPLTT_BASE = ((sys->plttKey & 0xFFFF) << 3) >> 4;
    reg_G3_DIF_AMB = 0x4210FFFF;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_POLYGON_ATTR = 0x3F1F00C0;
    if (shape->tailSide) {
        reg_G3_BEGIN_VTXS = 0;
        reg_G3_COLOR = win->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(shape->tailBaseB.x, shape->tailBaseB.y, shape->tailBaseB.z);
        G3_TexCoord(0, 0);
        G3_Vtx(shape->tip.x, shape->tip.y, shape->tip.z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(shape->tailBaseA.x, shape->tailBaseA.y, shape->tailBaseA.z);
        reg_G3_END_VTXS = 0;
    }
    if (tailOnly == 0) {
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_COLOR = win->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(shape->cornerBottomLeft.x, shape->cornerBottomLeft.y, shape->cornerBottomLeft.z);
        G3_TexCoord(0, 0);
        G3_Vtx(shape->cornerTopLeft.x, shape->cornerTopLeft.y, shape->cornerTopLeft.z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(shape->cornerTopRight.x, shape->cornerTopRight.y, shape->cornerTopRight.z);
        G3_TexCoord(0x8000, 0x8000);
        G3_Vtx(shape->cornerBottomRight.x, shape->cornerBottomRight.y, shape->cornerBottomRight.z);
        reg_G3_END_VTXS = 0;
    }
    reg_G3_MTX_POP = 1;
}

/* Projects a position (relative to the camera target) to the screen and back onto the draw plane. */
int TALKMSGWIN_ProjectToWorld(const VecFx32 *relPos, int *screenX, int *screenY, VecFx32 *outWorld)
{
    func_0206DF3C(relPos, screenX, screenY);
    return func_0206E0C4(*screenX, *screenY, outWorld, 0);
}

/*
 * Tail target for a window without a target position: the point on the border
 * of the anchor window that is nearest to this window (its center line when
 * the two overlap on an axis).
 */
void TALKMSGWIN_GetAnchorWindowPoint(TalkMsgWin *win, TalkMsgWin *anchor, int *screenX, int *screenY, VecFx32 *outWorld)
{
    int winX;
    int winY;
    int winW;
    int winH;
    int anchorX;
    int anchorY;
    int anchorW;
    int anchorH;

    winX = (BMP_WIN_GetPosX(win->bmpWin) - 1) << 3;
    winY = (BMP_WIN_GetPosY(win->bmpWin) - 1) << 3;
    winW = (BMP_WIN_GetDispWidth(win->bmpWin) + 2) << 3;
    winH = (BMP_WIN_GetDispHeight(win->bmpWin) + 2) << 3;
    anchorX = (BMP_WIN_GetPosX(anchor->bmpWin) - 1) << 3;
    anchorY = (BMP_WIN_GetPosY(anchor->bmpWin) - 1) << 3;
    anchorW = (BMP_WIN_GetDispWidth(anchor->bmpWin) + 2) << 3;
    anchorH = (BMP_WIN_GetDispHeight(anchor->bmpWin) + 2) << 3;
    if (winX + winW < anchorX) {
        *screenX = anchorX;
    } else if (winX > anchorX + anchorW) {
        *screenX = anchorX + anchorW;
    } else {
        *screenX = anchorX + anchorW / 2;
    }
    if (winY + winH < anchorY) {
        *screenY = anchorY;
    } else if (winY > anchorY + anchorH) {
        *screenY = anchorY + anchorH;
    } else {
        *screenY = anchorY + anchorH / 2;
    }
    func_0206E0C4(*screenX, *screenY, outWorld, 0);
}

/* Horizontal span of the tail base: 16 pixels, 64 pixels in from the left or right window edge. */
void TALKMSGWIN_GetTailBaseX(int x, int w, int side, u16 *left, u16 *right)
{
    if (side == 0) {
        *left = x + 0x40;
        *right = *left + 0x10;
    } else {
        *right = x + w - 0x40;
        *left = *right - 0x10;
    }
}

/*
 * Chooses the tail side and places the two tail base points on the window
 * border, from the screen position of the target. Returns the tail side.
 */
int TALKMSGWIN_CalcTail(TalkMsgWin *win, int targetX, int targetY, VecFx32 *outBaseA, VecFx32 *outBaseB)
{
    int x;
    int y;
    int w;
    int h;
    int baseWidth;
    int tailSide;
    int side;
    u16 t;
    u16 yA;
    u16 yB;
    u16 baseX[2];  /* [1]: left end of the base, [0]: right end */

    x = (BMP_WIN_GetPosX(win->bmpWin) - 1) << 3;
    y = (BMP_WIN_GetPosY(win->bmpWin) - 1) << 3;
    w = (BMP_WIN_GetDispWidth(win->bmpWin) + 2) << 3;
    h = (BMP_WIN_GetDispHeight(win->bmpWin) + 2) << 3;
    y += func_02040804(BMP_WIN_GetBgLayer(win->bmpWin));
    switch (win->tailMode) {
    case TALKMSGWIN_TAIL_MODE_AUTO:
    default:
        if (w >= 16 && h >= 16) {
            baseWidth = 16;
        } else {
            baseWidth = h;
        }
        if (targetY < y) {
            yB = yA = y + 3;
            baseX[1] = x + w / 2 - baseWidth / 2;
            baseX[0] = baseWidth / 2 + (x + w / 2);
            tailSide = TALKMSGWIN_TAIL_SIDE_TOP;
        } else if (targetY > y + h) {
            yB = yA = y + h - 3;
            baseX[1] = x + w / 2 - baseWidth / 2;
            baseX[0] = baseWidth / 2 + (x + w / 2);
            tailSide = TALKMSGWIN_TAIL_SIDE_BOTTOM;
        } else {
            yA = y + h / 2 - baseWidth / 2;
            yB = baseWidth / 2 + (y + h / 2);
            if (targetX < x) {
                t = x + 1;
                baseX[1] = t;
                baseX[0] = t;
                tailSide = TALKMSGWIN_TAIL_SIDE_LEFT;
            } else if (targetX > x + w) {
                t = x + w - 1;
                baseX[1] = t;
                baseX[0] = t;
                tailSide = TALKMSGWIN_TAIL_SIDE_RIGHT;
            } else {
                t = x + w / 2;
                baseX[1] = t;
                baseX[0] = t;
                tailSide = TALKMSGWIN_TAIL_SIDE_NONE;
            }
        }
        break;
    case TALKMSGWIN_TAIL_MODE_LOWER_EDGE:
        yB = yA = y + h - 4;
        if (win->shape.tailSide == TALKMSGWIN_TAIL_SIDE_NONE) {
            if (targetX < 0x80) {
                side = 0;
                tailSide = TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT;
            } else {
                side = 1;
                tailSide = TALKMSGWIN_TAIL_SIDE_BOTTOM_RIGHT;
            }
        } else if (win->shape.tailSide == TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT) {
            side = 0;
            tailSide = TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT;
        } else {
            side = 1;
            tailSide = TALKMSGWIN_TAIL_SIDE_BOTTOM_RIGHT;
        }
        TALKMSGWIN_GetTailBaseX(x, w, side, &baseX[1], &baseX[0]);
        break;
    case TALKMSGWIN_TAIL_MODE_UPPER_EDGE:
        yB = yA = y + 4;
        if (win->shape.tailSide == TALKMSGWIN_TAIL_SIDE_NONE) {
            if (targetX < 0x80) {
                side = 0;
                tailSide = TALKMSGWIN_TAIL_SIDE_TOP_LEFT;
            } else {
                side = 1;
                tailSide = TALKMSGWIN_TAIL_SIDE_TOP_RIGHT;
            }
        } else if (win->shape.tailSide == TALKMSGWIN_TAIL_SIDE_TOP_LEFT) {
            side = 0;
            tailSide = TALKMSGWIN_TAIL_SIDE_TOP_LEFT;
        } else {
            side = 1;
            tailSide = TALKMSGWIN_TAIL_SIDE_TOP_RIGHT;
        }
        TALKMSGWIN_GetTailBaseX(x, w, side, &baseX[1], &baseX[0]);
        break;
    }
    func_0206E0C4(baseX[1], yA, outBaseA, 0);
    func_0206E0C4(baseX[0], yB, outBaseB, 0);
    return tailSide;
}

/* World positions of the four window corners (top left, top right, bottom left, bottom right). */
void TALKMSGWIN_GetWindowCornerPoints(TalkMsgWin *win, VecFx32 *outTopLeft, VecFx32 *outTopRight, VecFx32 *outBottomLeft, VecFx32 *outBottomRight)
{
    int x;
    int y;
    int w;
    int h;

    x = BMP_WIN_GetPosX(win->bmpWin) << 3;
    y = (BMP_WIN_GetPosY(win->bmpWin) - 1) << 3;
    w = BMP_WIN_GetDispWidth(win->bmpWin) << 3;
    h = (BMP_WIN_GetDispHeight(win->bmpWin) + 2) << 3;
    func_0206E0C4(x, y, outTopLeft, 0);
    func_0206E0C4(x + w, y, outTopRight, 0);
    func_0206E0C4(x, y + h, outBottomLeft, 0);
    func_0206E0C4(x + w, y + h, outBottomRight, 0);
}

static inline void setVec32(VecFx32 *out, s32 x, s32 y, s32 z)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void setVec16(VecFx16 *out, s16 x, s16 y, s16 z)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

/*
 * Stores the balloon polygon: the origin is the tip, every other vertex is
 * the offset from the tip divided by the largest distance (so it fits 16 bits),
 * and the largest distance becomes the draw scale.
 */
void TALKMSGWIN_BuildShape(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *tip, VecFx32 *tailBaseA, VecFx32 *tailBaseB,
                   VecFx32 *topLeft, VecFx32 *topRight, VecFx32 *bottomLeft, VecFx32 *bottomRight)
{
    VecFx32 offsetA;
    VecFx32 offsetB;
    VecFx32 offsetTopLeft;
    VecFx32 offsetTopRight;
    VecFx32 offsetBottomLeft;
    VecFx32 offsetBottomRight;
    int maxDist;
    int distB;
    int distTopLeft;
    int distTopRight;
    int distBottomLeft;
    int distBottomRight;

    func_0207CA00(tailBaseA, tip, &offsetA);
    func_0207CA00(tailBaseB, tip, &offsetB);
    func_0207CA00(topLeft, tip, &offsetTopLeft);
    func_0207CA00(topRight, tip, &offsetTopRight);
    func_0207CA00(bottomLeft, tip, &offsetBottomLeft);
    func_0207CA00(bottomRight, tip, &offsetBottomRight);
    maxDist = func_0207CBD0(&offsetA);
    distB = func_0207CBD0(&offsetB);
    distTopLeft = func_0207CBD0(&offsetTopLeft);
    distTopRight = func_0207CBD0(&offsetTopRight);
    distBottomLeft = func_0207CBD0(&offsetBottomLeft);
    distBottomRight = func_0207CBD0(&offsetBottomRight);
    if (maxDist < distB) {
        maxDist = distB;
    }
    if (maxDist < distTopLeft) {
        maxDist = distTopLeft;
    }
    if (maxDist < distTopRight) {
        maxDist = distTopRight;
    }
    if (maxDist < distBottomLeft) {
        maxDist = distBottomLeft;
    }
    if (maxDist < distBottomRight) {
        maxDist = distBottomRight;
    }
    setVec32(&win->shape.origin, tip->x, tip->y, tip->z);
    win->shape.scale = maxDist;
    win->shape.tip.x = 0;
    win->shape.tip.y = 0;
    win->shape.tip.z = 0;
    setVec16(&win->shape.tailBaseA, func_0207C768(offsetA.x, maxDist), func_0207C768(offsetA.y, maxDist), func_0207C768(offsetA.z, maxDist));
    setVec16(&win->shape.tailBaseB, func_0207C768(offsetB.x, maxDist), func_0207C768(offsetB.y, maxDist), func_0207C768(offsetB.z, maxDist));
    setVec16(&win->shape.cornerTopLeft, func_0207C768(offsetTopLeft.x, maxDist), func_0207C768(offsetTopLeft.y, maxDist),
             func_0207C768(offsetTopLeft.z, maxDist));
    setVec16(&win->shape.cornerTopRight, func_0207C768(offsetTopRight.x, maxDist), func_0207C768(offsetTopRight.y, maxDist),
             func_0207C768(offsetTopRight.z, maxDist));
    setVec16(&win->shape.cornerBottomLeft, func_0207C768(offsetBottomLeft.x, maxDist),
             func_0207C768(offsetBottomLeft.y, maxDist), func_0207C768(offsetBottomLeft.z, maxDist));
    setVec16(&win->shape.cornerBottomRight, func_0207C768(offsetBottomRight.x, maxDist),
             func_0207C768(offsetBottomRight.y, maxDist), func_0207C768(offsetBottomRight.z, maxDist));
}

/* Recomputes the balloon polygon of a window. Returns 1 when the tail side changed. */
u32 TALKMSGWIN_UpdateShape(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    VecFx32 tipPos;
    VecFx32 tailBaseA;
    VecFx32 tailBaseB;
    VecFx32 topLeft;
    VecFx32 topRight;
    VecFx32 bottomLeft;
    VecFx32 bottomRight;
    VecFx32 relPos;
    int screenX;
    int screenY;
    int tailSide;

    if (win->targetPos != 0) {
        func_0207CA00(win->targetPos, &sys->savedTarget, &relPos);
        TALKMSGWIN_ProjectToWorld(&relPos, &screenX, &screenY, &tipPos);
    } else {
        TALKMSGWIN_GetAnchorWindowPoint(win, &sys->windows[win->anchorIndex], &screenX, &screenY, &tipPos);
    }
    tailSide = TALKMSGWIN_CalcTail(win, screenX, screenY, &tailBaseA, &tailBaseB);
    TALKMSGWIN_GetWindowCornerPoints(win, &topLeft, &topRight, &bottomLeft, &bottomRight);
    TALKMSGWIN_BuildShape(sys, win, &tipPos, &tailBaseA, &tailBaseB, &topLeft, &topRight, &bottomLeft, &bottomRight);
    if (win->shape.tailSide != tailSide) {
        win->shape.tailSide = tailSide;
        return 1;
    }
    return 0;
}

/*
 * Sets the camera the balloons are drawn with: eye at the saved eye relative
 * to the saved target, looking at the origin. useCameraObject 0 writes it to
 * the field camera object, otherwise it is applied directly.
 */
void TALKMSGWIN_SetupCamera(TalkMsgWinSys *sys, int useCameraObject)
{
    VecFx32 eyeOffset;
    VecFx32 eye;
    VecFx32 up;
    VecFx32 target;
    int scale;

    func_0207CA00(&sys->savedEye, &sys->savedTarget, &eyeOffset);
    eye.x = eyeOffset.x;
    eye.y = eyeOffset.y;
    eye.z = eyeOffset.z;
    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    target.x = 0;
    target.y = 0;
    target.z = 0;
    if (useCameraObject == 0) {
        scale = 0x40000;
        if (sys->savedScale >= scale)
            scale = sys->savedScale + 0x1000;
        func_02048AFC(sys->param.camera, &eye);
        func_02048B20(sys->param.camera, &up);
        func_02048B44(sys->param.camera, &target);
        func_02048B60(sys->param.camera, &scale);
        func_02048AD0(sys->param.camera);
        return;
    }
    func_0207D7C4(&eye, &up, &target, 1, 0);
}

/* Saves the field camera state. */
void TALKMSGWIN_SaveCamera(TalkMsgWinSys *sys)
{
    func_02048AE8(sys->param.camera, &sys->savedEye);
    func_02048B0C(sys->param.camera, &sys->savedUp);
    func_02048B30(sys->param.camera, &sys->savedTarget);
    func_02048B54(sys->param.camera, &sys->savedScale);
}

/* Restores the field camera state saved by TALKMSGWIN_SaveCamera. */
void TALKMSGWIN_RestoreCamera(TalkMsgWinSys *sys)
{
    func_02048AFC(sys->param.camera, &sys->savedEye);
    func_02048B20(sys->param.camera, &sys->savedUp);
    func_02048B44(sys->param.camera, &sys->savedTarget);
    func_02048B60(sys->param.camera, &sys->savedScale);
    func_02048AD0(sys->param.camera);
}

/* Loads the frame palette and tiles (archive 5, files 0 and 5). Returns the tile data size. */
u32 TALKMSGWIN_LoadFrameGraphics(TalkMsgWinSys *sys, TalkMsgWinParam *param)
{
    u32 screenSelect;

    func_020414EC(param->bgLayer & 0xFF);
    screenSelect = 0;
    switch (param->bgLayer) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        screenSelect = 4;
        break;
    }
    func_02049B40(5, 0, screenSelect, param->framePalette << 5, 0x20, param->heapId);
    return func_02049624(5, 5, param->bgLayer, param->frameBaseTile, 0, 0, param->heapId);
}

/* Uploads the balloon texture and palette into the VRAM blocks of the system's keys. */
void TALKMSGWIN_UploadTexture(TalkMsgWinSys *sys)
{
    func_0207F7A0();
    DC_FlushRange(sTalkMsgWinTexture, 0x20);
    func_0207F7FC(sTalkMsgWinTexture, (u16)sys->texKey << 3, 0x20);
    func_0207F9B4();
    func_0207FA0C();
    DC_FlushRange(sTalkMsgWinPalette, 0x20);
    func_0207FA40(sTalkMsgWinPalette, (u16)sys->plttKey << 3, 0x20);
    func_0207FADC();
}

/* Reloads the frame palette and tiles; same as TALKMSGWIN_LoadFrameGraphics without the result. */
void TALKMSGWIN_ReloadFrameGraphics(TalkMsgWinSys *sys)
{
    u32 screenSelect;
    u32 bgLayer;

    func_020414EC(sys->param.bgLayer & 0xFF);
    bgLayer = sys->param.bgLayer;
    screenSelect = 0;
    switch (bgLayer) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        screenSelect = 4;
        break;
    }
    func_02049B40(5, 0, screenSelect, (u32)sys->param.framePalette << 5, 0x20, sys->param.heapId);
    func_02049624(5, 5, sys->param.bgLayer, sys->param.frameBaseTile, 0, 0, sys->param.heapId);
}

/*
 * Draws a simple frame (corners and edges, one tile each) around a window on
 * its BG layer, plus an optional notch tile pair on the side chosen by
 * tailSide. Sibling of TALKMSGWIN_DrawCorneredFrame, which draws the double-corner frame.
 * Edges that touch the screen border (x == 0, x + w == 32, y == 0, y + h == 24)
 * are skipped.
 */
void TALKMSGWIN_DrawSimpleFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bgLayer;
    int palBits;
    u16 baseTile;
    int top;
    int right;
    int bottom;
    u16 notchTile;

    x = BMP_WIN_GetPosX(bmpWin);
    y = BMP_WIN_GetPosY(bmpWin);
    w = BMP_WIN_GetDispWidth(bmpWin);
    h = BMP_WIN_GetDispHeight(bmpWin);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bgLayer = style->bgLayer;
    palBits = (style->framePalette & 0xF) << 12;
    baseTile = style->frameBaseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    BMP_WIN_MakeScreen(bmpWin);

    if (!topClip) {
        if (!leftClip)
            func_02041300(bgLayer, (baseTile + 1) | palBits, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bgLayer, (baseTile + 3) | palBits, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bgLayer, (baseTile + 0x401) | palBits, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bgLayer, (baseTile + 4) | palBits, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bgLayer, (baseTile + 0x404) | palBits, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bgLayer, (baseTile + 0x801) | palBits, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bgLayer, (baseTile + 0x803) | palBits, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bgLayer, (baseTile + 0xC01) | palBits, right, bottom, 1, 1, 0x11);
    }

    notchTile = (baseTile + 2) | palBits;
    switch (tailSide) {
    case TALKMSGWIN_TAIL_SIDE_TOP:
        if (!topClip)
            func_02041300(bgLayer, notchTile, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM:
        if (!bottomClip)
            func_02041300(bgLayer, notchTile | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_LEFT:
        if (!leftClip)
            func_02041300(bgLayer, (baseTile + 5) | palBits, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_RIGHT:
        if (!rightClip)
            func_02041300(bgLayer, (baseTile + 5) | palBits, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_TOP_LEFT:
        if (!topClip)
            func_02041300(bgLayer, notchTile, x + 7, y - 1, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT:
        if (!topClip)
            func_02041300(bgLayer, notchTile | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_TOP_RIGHT:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bgLayer, notchTile, right, y - 1, 2, 1, 0x11);
        }
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM_RIGHT:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bgLayer, notchTile | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bgLayer);
}

/*
 * Draws a frame with double corners around a window on its BG layer: corners,
 * edges, and an optional notch tile pair on the side chosen by tailSide. Edges
 * that touch the screen border (x == 0, x + w == 32, y == 0, y + h == 24) are
 * skipped. The window geometry getters are held in u16 locals and the palette
 * nibble is masked and shifted into an int; both are what the truncations and
 * the lsl #28 / lsr #16 fold in the image require.
 */
void TALKMSGWIN_DrawCorneredFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bgLayer;
    int palBits;
    u16 baseTile;
    int right;
    int bottom;
    u16 notchTile;

    x = BMP_WIN_GetPosX(bmpWin);
    y = BMP_WIN_GetPosY(bmpWin);
    w = BMP_WIN_GetDispWidth(bmpWin);
    h = BMP_WIN_GetDispHeight(bmpWin);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bgLayer = style->bgLayer;
    palBits = (style->framePalette & 0xF) << 12;
    baseTile = style->frameBaseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    BMP_WIN_MakeScreen(bmpWin);

    if (!topClip) {
        if (!leftClip) {
            func_02041300(bgLayer, (baseTile + 9) | palBits, x - 1, y - 1, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 10) | palBits, x, y - 1, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 11) | palBits, x - 1, y, 1, 1, 0x11);
        }
        func_02041300(bgLayer, (baseTile + 6) | palBits, x + 1, y - 1, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bgLayer, (baseTile + 0x409) | palBits, x + w, y - 1, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0x40A) | palBits, x + w - 1, y - 1, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0x40B) | palBits, x + w, y, 1, 1, 0x11);
        }
    }
    if (!leftClip) {
        if (!topClip)
            func_02041300(bgLayer, (baseTile + 7) | palBits, x - 1, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bgLayer, (baseTile + 7) | palBits, x - 1, y, 1, h, 0x11);
    }
    if (!rightClip) {
        if (!topClip)
            func_02041300(bgLayer, (baseTile + 0x407) | palBits, right, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bgLayer, (baseTile + 0x407) | palBits, right, y, 1, h, 0x11);
    }
    if (!bottomClip) {
        if (!leftClip) {
            func_02041300(bgLayer, (baseTile + 0x809) | palBits, x - 1, y + h, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0x80A) | palBits, x, y + h, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0x80B) | palBits, x - 1, y + h - 1, 1, 1, 0x11);
        }
        func_02041300(bgLayer, (baseTile + 0x806) | palBits, x + 1, bottom, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bgLayer, (baseTile + 0xC09) | palBits, x + w, y + h, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0xC0A) | palBits, x + w - 1, y + h, 1, 1, 0x11);
            func_02041300(bgLayer, (baseTile + 0xC0B) | palBits, x + w, y + h - 1, 1, 1, 0x11);
        }
    }

    notchTile = (baseTile + 8) | palBits;
    switch (tailSide) {
    case TALKMSGWIN_TAIL_SIDE_TOP:
        if (!topClip)
            func_02041300(bgLayer, notchTile, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM:
        if (!bottomClip)
            func_02041300(bgLayer, notchTile | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_LEFT:
        if (!leftClip)
            func_02041300(bgLayer, (baseTile + 5) | palBits, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_RIGHT:
        if (!rightClip)
            func_02041300(bgLayer, (baseTile + 5) | palBits, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_TOP_LEFT:
        if (!topClip)
            func_02041300(bgLayer, notchTile, x + 7, y - 1, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT:
        if (!topClip)
            func_02041300(bgLayer, notchTile | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case TALKMSGWIN_TAIL_SIDE_TOP_RIGHT:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bgLayer, notchTile, right, y - 1, 2, 1, 0x11);
        }
        break;
    case TALKMSGWIN_TAIL_SIDE_BOTTOM_RIGHT:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bgLayer, notchTile | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bgLayer);
}

/* Draws the frame of the given type around a window. */
void TALKMSGWIN_DrawFrameByType(const TalkMsgWinParam *style, struct BmpWin *bmpWin, u8 frameType, u32 tailSide)
{
    switch (frameType) {
    case TALKMSGWIN_FRAME_SIMPLE:
        TALKMSGWIN_DrawSimpleFrame(style, bmpWin, tailSide);
        break;
    case TALKMSGWIN_FRAME_CORNERED:
        TALKMSGWIN_DrawCorneredFrame(style, bmpWin, tailSide);
        break;
    }
}

/* Draws the frame of a window without a tail notch. */
void TALKMSGWIN_DrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    TALKMSGWIN_DrawFrameByType(&sys->param, win->bmpWin, win->frameType, 0);
}

/* Draws the frame of a window with the notch of its current tail side. */
void TALKMSGWIN_RedrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win)
{
    TALKMSGWIN_DrawFrameByType(&sys->param, win->bmpWin, win->frameType, win->shape.tailSide);
}

/*
 * Clears the one-tile frame around a window (tile 0 on all eight edges),
 * skipping any edge that touches the 32x24 screen border. The erase
 * counterpart of TALKMSGWIN_DrawCorneredFrame.
 */
void TALKMSGWIN_ClearFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bgLayer;
    int top;
    int right;
    int bottom;

    x = BMP_WIN_GetPosX(bmpWin);
    y = BMP_WIN_GetPosY(bmpWin);
    w = BMP_WIN_GetDispWidth(bmpWin);
    h = BMP_WIN_GetDispHeight(bmpWin);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bgLayer = style->bgLayer;

    BMP_WIN_ClearScreen(bmpWin);

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    if (!topClip) {
        if (!leftClip)
            func_02041300(bgLayer, 0, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bgLayer, 0, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bgLayer, 0, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bgLayer, 0, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bgLayer, 0, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bgLayer, 0, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bgLayer, 0, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bgLayer, 0, right, bottom, 1, 1, 0x11);
    }
    func_020409B4(bgLayer);
}
