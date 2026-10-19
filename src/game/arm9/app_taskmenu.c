/*
 * file:     app_taskmenu.c
 * unit:     yes
 * function: APP_TASKMENU_OpenMenu, APP_TASKMENU_OpenMenuFastDecide, APP_TASKMENU_CloseMenu, APP_TASKMENU_TransWinAfterPrint, APP_TASKMENU_UpdateMenu, APP_TASKMENU_IsFinish, APP_TASKMENU_GetCursorPos, APP_TASKMENU_SetCursorActive, APP_TASKMENU_IsDecide, APP_TASKMENU_CreateWindows, APP_TASKMENU_SetWinActive, APP_TASKMENU_UpdateCursorColor, APP_TASKMENU_UpdateCursorColorBlend, APP_TASKMENU_SetDisableKey, APP_TASKMENU_SetCursorPos, APP_TASKMENU_UpdateKey, APP_TASKMENU_UpdateTouch, APP_TASKMENU_RES_Create, APP_TASKMENU_RES_Delete, APP_TASKMENU_WIN_Create, APP_TASKMENU_WIN_CreateEx, APP_TASKMENU_WIN_CreateExNoScreen, APP_TASKMENU_WIN_CreateCore, APP_TASKMENU_WIN_Delete, APP_TASKMENU_WIN_DeleteNoClear, APP_TASKMENU_WIN_Free, APP_TASKMENU_WIN_Update, APP_TASKMENU_WIN_SetActive, APP_TASKMENU_WIN_SetDecide, APP_TASKMENU_WIN_IsFinish, APP_TASKMENU_WIN_IsTouch, APP_TASKMENU_WIN_ResetDecide, APP_TASKMENU_WIN_ChangePalette, APP_TASKMENU_DrawWinFrame, APP_TASKMENU_WIN_ClearScreen, APP_TASKMENU_WIN_TransChar, APP_TASKMENU_WIN_IsUpdateTrans
 * address:  0x02027778
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_taskmenu.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MIi_CpuCopy16     0x02082A60  arm
 *   app_taskmenu_File  0x020A74E0  data
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   PRINTSYS_PrintQueColor   0x0201C724  thumb
 *   FX_SinCosTable_   0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask   0x02061CA4  arm
 *   UI_GetInputMode 0x020355C4  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   ARC_UTIL_LoadBgCharDataFromArchive   0x02049DB4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole   0x02049B40  arm
 *   GF_FONT_MeasureWidestLine   0x0201D304  thumb
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_SetPalette  0x02045798  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb arm9
 */
#include "beacon_status_shared_types.h"

typedef signed short   s16;

typedef signed int     s32;

struct BmpWin;          /* BG bitmap window */

struct Bmp;             /* bitmap of a window */

struct PrintQueue;      /* deferred text print queue */

struct GFont;           /* font */

/* ------------------------------------------------------------------ */
/* app_taskmenu.c                                                      */
/* ------------------------------------------------------------------ */

/* Unpacked character data (the 0x14-byte header, then the raw data pointer). */
typedef struct TaskMenuChrData {
    u16 H;
    u16 W;
    u32 pixelFmt;
    u32 mapingType;
    u32 characterFmt;
    u32 szByte;
    void *pRawData;             /* +0x14 window frame tiles, 0x20 bytes each */
} TaskMenuChrData;

/* Shared resources of the task menus of one BG frame (0x18 bytes). */
typedef struct TaskMenuRes {
    u16 bgFrame;                /* +0x00 */
    u16 palNo;                  /* +0x02 active palette; palNo + 1 is the inactive one */
    TaskMenuChrData *chrData;   /* +0x04 */
    void *chrBuf;               /* +0x08 loaded frame character file */
    u32 reserved0C;             /* +0x0C never read; role unknown */
    struct GFont *font;         /* +0x10 */
    struct PrintQueue *printQue;/* +0x14 */
} TaskMenuRes;

/* One menu entry (0xC bytes). */
typedef struct TaskMenuItem {
    struct StrBuf *str;         /* +0x00 */
    u16 msgColor;               /* +0x04 print colour */
    u32 type;                   /* +0x08 frame style; 1 is the back/cancel entry */
} TaskMenuItem;

/* Caller-filled template of a task menu (0x14 bytes). */
typedef struct TaskMenuInitWork {
    u32 heapId;                 /* +0x00 */
    u8 itemNum;                 /* +0x04 */
    u8 pad_05[3];
    const TaskMenuItem *itemWork; /* +0x08 */
    u32 posType;                /* +0x0C 0: (charPosX, charPosY) is the top left; else the bottom right */
    u8 charPosX;                /* +0x10 */
    u8 charPosY;                /* +0x11 */
    u8 width;                   /* +0x12 in characters, 13 when 0 */
    u8 height;                  /* +0x13 per entry, 3 when 0 */
} TaskMenuInitWork;

/* A task menu: one window per entry, a cursor and the decide animation (0x38 bytes). */
typedef struct TaskMenuWork {
    u8 cursorPos;               /* +0x00 */
    u8 anmCnt;                  /* +0x01 decide blink frame count */
    u16 colorPhase;             /* +0x02 cursor colour animation phase */
    u16 cursorColor;            /* +0x04 */
    u8 pad_06[2];
    u32 isUpdateTrans;          /* +0x08 transfer the windows when printing ends */
    u32 isDecide;               /* +0x0C */
    u32 isDisableKey;           /* +0x10 */
    u32 anmSpeed;               /* +0x14 decide blink speed (1 or 2) */
    struct BmpWin **winWork;    /* +0x18 itemNum windows */
    TaskMenuItem *itemWork;     /* +0x1C itemNum entries, copied from the template */
    TaskMenuInitWork init;      /* +0x20 */
    TaskMenuRes *res;           /* +0x34 */
} TaskMenuWork;

/* A single task menu window (a button) (0x20 bytes). */
typedef struct TaskMenuWin {
    struct BmpWin *bmpWin;      /* +0x00 */
    u32 reserved04;             /* +0x04 never read; role unknown */
    u32 isDecide;               /* +0x08 */
    u32 isUpdateTrans;          /* +0x0C */
    u16 anmCnt;                 /* +0x10 */
    u16 anmSpeed;               /* +0x12 */
    u16 colorPhase;             /* +0x14 */
    u16 cursorColor;            /* +0x16 */
    TaskMenuRes *res;           /* +0x18 */
    u16 activeColor0;           /* +0x1C cursor colour blend end points */
    u16 activeColor1;           /* +0x1E */
} TaskMenuWin;

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *memory);

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

extern u32 PRINTSYS_QUE_Main(struct PrintQueue *printQue);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *printQue, struct Bmp *bmp);

extern void BG_SYS_MarkTileDirty(u32 bgFrame);

extern u32 BMP_WIN_Delete(struct BmpWin *win);

extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern struct BmpWin *BMP_WIN_Create(u32 bgFrame, u32 charPosX, u32 charPosY, u32 sizeX, u8 sizeY,
                                   u8 palNo, u8 dir);

extern void PRINTSYS_PrintQueColor(struct PrintQueue *printQue, struct Bmp *bmp, u32 x, u32 y,
                         struct StrBuf *str, struct GFont *font, u16 color);

extern void BMP_WIN_SetPalette(struct BmpWin *win, u8 palNo);

extern s32 NNS_GfdRegisterNewVramTransferTask(u32 transType, u32 offset, const void *src, s32 size);

extern u8 UI_GetInputMode(void);

extern u32 KEY_GetTrg(void);

extern unsigned int KEY_GetRepeat(void);

extern void UI_SetInputMode(u8 isTouch);

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern int TOUCHPANEL_HitTrg(const void *hitTbl);

extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 arcId, u32 datId, u32 compressed, TaskMenuChrData **chrData, u16 heapId);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 arcId, u32 datId, u32 pltType, u32 offset, u32 size, u16 heapId);

extern u32 GF_FONT_MeasureWidestLine(struct StrBuf *str, struct GFont *font, u32 margin);

extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);

extern u8 BMP_WIN_GetWidth(struct BmpWin *win);

extern u8 BMP_WIN_GetPosX(struct BmpWin *win);

extern u8 BMP_WIN_GetPosY(struct BmpWin *win);

extern u8 BMP_WIN_GetHeight(struct BmpWin *win);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 n);

u32 APP_ICON_GetArchiveId(void);

TaskMenuWork *APP_TASKMENU_OpenMenu(TaskMenuInitWork *init, TaskMenuRes *res);

TaskMenuWork *APP_TASKMENU_OpenMenuFastDecide(TaskMenuInitWork *init, TaskMenuRes *res);

void APP_TASKMENU_CloseMenu(TaskMenuWork *menu);

void APP_TASKMENU_TransWinAfterPrint(TaskMenuWork *menu);

void APP_TASKMENU_UpdateMenu(TaskMenuWork *menu);

u32 APP_TASKMENU_IsFinish(TaskMenuWork *menu);

u8 APP_TASKMENU_GetCursorPos(const TaskMenuWork *menu);

void APP_TASKMENU_SetCursorActive(TaskMenuWork *menu, u32 isActive);

u32 APP_TASKMENU_IsDecide(TaskMenuWork *menu);

void APP_TASKMENU_CreateWindows(TaskMenuWork *menu, TaskMenuRes *res);

void APP_TASKMENU_SetWinActive(struct BmpWin *win, TaskMenuRes *res, int isActive);

void APP_TASKMENU_UpdateCursorColor(u16 *colorPhase, u16 *color, u32 bgFrame, u32 palNo);

void APP_TASKMENU_UpdateCursorColorBlend(u16 *colorPhase, u16 *color, u16 bgFrame, u32 palNo, u16 color0, u16 color1);

void APP_TASKMENU_SetDisableKey(TaskMenuWork *menu, int isDisable);

void APP_TASKMENU_SetCursorPos(TaskMenuWork *menu, int pos);

void APP_TASKMENU_UpdateKey(TaskMenuWork *menu);

void APP_TASKMENU_UpdateTouch(TaskMenuWork *menu);

TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, struct GFont *font, struct PrintQueue *printQue, u16 heapId);

void APP_TASKMENU_RES_Delete(TaskMenuRes *res);

TaskMenuWin *APP_TASKMENU_WIN_Create(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u16 heapId);

TaskMenuWin *APP_TASKMENU_WIN_CreateEx(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);

TaskMenuWin *APP_TASKMENU_WIN_CreateExNoScreen(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);

TaskMenuWin *APP_TASKMENU_WIN_CreateCore(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);

void APP_TASKMENU_WIN_Delete(TaskMenuWin *win);

void APP_TASKMENU_WIN_DeleteNoClear(TaskMenuWin *win);

void APP_TASKMENU_WIN_Free(TaskMenuWin *win);

void APP_TASKMENU_WIN_Update(TaskMenuWin *win);

void APP_TASKMENU_WIN_SetActive(TaskMenuWin *win, u32 isActive);

void APP_TASKMENU_WIN_SetDecide(TaskMenuWin *win, int isDecide);

u32 APP_TASKMENU_WIN_IsFinish(TaskMenuWin *win);

u32 APP_TASKMENU_WIN_IsTouch(TaskMenuWin *win);

void APP_TASKMENU_WIN_ResetDecide(TaskMenuWin *win);

void APP_TASKMENU_WIN_ChangePalette(TaskMenuWin *win, TaskMenuRes *res, u32 palNo, u32 color0, u16 color1);

void APP_TASKMENU_DrawWinFrame(struct BmpWin *win, TaskMenuRes *res, u32 frameStyle);

void APP_TASKMENU_WIN_ClearScreen(TaskMenuWin *win);

void APP_TASKMENU_WIN_TransChar(TaskMenuWin *win);

u32 APP_TASKMENU_WIN_IsUpdateTrans(TaskMenuWin *win);

extern const char app_taskmenu_File[];

extern const s16 FX_SinCosTable_[];

/* ================================================================== */
/* app_taskmenu.c                                                      */
/* ================================================================== */

/*
 * Open a task menu: copy the template, allocate the window and entry
 * arrays, copy the entries, default the window size to 13x3, create and
 * draw the windows and, in key mode, highlight the first entry.
 *
 * The template parameter is NOT const: with a const pointer mwcc proves
 * the stores into the menu cannot reach the template and hoists the
 * init->width load above them; without it the load stays in source order.
 * The two defaults are unconditional stores of a conditioned value.
 */
TaskMenuWork *APP_TASKMENU_OpenMenu(TaskMenuInitWork *init, TaskMenuRes *res)
{
    TaskMenuWork *menu;
    u8 width;
    u8 height;

    menu = GFL_HEAP_Alloc((u16)init->heapId, sizeof(TaskMenuWork), 0, app_taskmenu_File, 162);
    menu->init = *init;
    menu->res = res;
    menu->winWork = GFL_HEAP_Alloc((u16)menu->init.heapId, menu->init.itemNum * sizeof(struct BmpWin *), 0, app_taskmenu_File, 168);
    menu->itemWork = GFL_HEAP_Alloc((u16)menu->init.heapId, menu->init.itemNum * sizeof(TaskMenuItem), 0, app_taskmenu_File, 169);
    MIi_CpuCopy16(menu->init.itemWork, menu->itemWork, menu->init.itemNum * sizeof(TaskMenuItem));
    menu->isDecide = 0;
    menu->isDisableKey = 0;
    menu->cursorPos = 0;
    menu->anmCnt = 0;
    menu->colorPhase = 0;
    menu->anmSpeed = 1;
    width = init->width;
    if (width == 0) {
        width = 13;
    }
    menu->init.width = width;
    height = init->height;
    if (height == 0) {
        height = 3;
    }
    menu->init.height = height;
    APP_TASKMENU_CreateWindows(menu, res);
    if (UI_GetInputMode() == 0) {
        APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 1);
    }
    menu->isUpdateTrans = 1;
    return menu;
}

/* Open a task menu whose decide blink runs twice as fast. */
TaskMenuWork *APP_TASKMENU_OpenMenuFastDecide(TaskMenuInitWork *init, TaskMenuRes *res)
{
    TaskMenuWork *menu;

    menu = APP_TASKMENU_OpenMenu(init, res);
    menu->anmSpeed = 2;
    return menu;
}

/*
 * Close a task menu: drain every queued print of every window, delete the
 * windows, request the BG screen load and free the three blocks.
 *
 * The two loop counters are u8 (the lsls #24 / lsrs #24 pair after each
 * increment). The second loop's entry test reuses the count the first
 * loop's last bottom-of-loop read left in a register.
 */
void APP_TASKMENU_CloseMenu(TaskMenuWork *menu)
{
    u8 bgFrame;
    u8 i;
    u8 j;

    bgFrame = BMP_WIN_GetBgLayer(menu->winWork[0]);
    for (i = 0; i < menu->init.itemNum; i++) {
        while (PRINTSYS_QUE_IsExistTarget(menu->res->printQue,
                             BMP_WIN_GetBmp(menu->winWork[i])) != 0) {
            PRINTSYS_QUE_Main(menu->res->printQue);
        }
    }
    for (j = 0; j < menu->init.itemNum; j++) {
        BMP_WIN_ClearScreen(menu->winWork[j]);
        BMP_WIN_Delete(menu->winWork[j]);
    }
    BG_SYS_MarkTileDirty(bgFrame);
    GFL_HEAP_Free(menu->winWork);
    GFL_HEAP_Free(menu->itemWork);
    GFL_HEAP_Free(menu);
}

/*
 * When a transfer is pending and no window has text left in the print
 * queue, transfer every window and clear the pending flag.
 *
 * The `adds r7, r4, #0` before the loop is the constant isPrintDone = 0
 * rematerialised off the already-zero r4
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 */
void APP_TASKMENU_TransWinAfterPrint(TaskMenuWork *menu)
{
    u8 i;
    u8 isPrintDone;

    if (menu->isUpdateTrans != 1) {
        return;
    }
    isPrintDone = 1;
    for (i = 0; i < menu->init.itemNum; i++) {
        if (PRINTSYS_QUE_IsExistTarget(menu->res->printQue, BMP_WIN_GetBmp(menu->winWork[i])) == 1) {
            isPrintDone = 0;
        }
    }
    if (isPrintDone != 1) {
        return;
    }
    for (i = 0; i < menu->init.itemNum; i++) {
        struct BmpWin *win = menu->winWork[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
    }
    menu->isUpdateTrans = 0;
}

/*
 * Per-frame step: pending transfer, then key and touch input until an
 * entry is decided, then the decide blink; the cursor colour animates in
 * every state.
 */
void APP_TASKMENU_UpdateMenu(TaskMenuWork *menu)
{
    u32 step;
    TaskMenuRes *res;

    APP_TASKMENU_TransWinAfterPrint(menu);
    if (menu->isDecide == 0) {
        APP_TASKMENU_UpdateKey(menu);
        if (menu->isDecide == 0) {
            APP_TASKMENU_UpdateTouch(menu);
        }
    } else {
        step = 4 / menu->anmSpeed;
        if ((u8)((menu->anmCnt / step) & 1) == 0) {
            APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 1);
        } else {
            APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 0);
        }
        menu->anmCnt = (u8)(menu->anmCnt + 1);
    }
    res = menu->res;
    APP_TASKMENU_UpdateCursorColor(&menu->colorPhase, &menu->cursorColor, (u8)res->bgFrame, (u8)res->palNo);
}

/*
 * Whether the decide blink has ended: 16 / anmSpeed frames. The unsigned
 * division makes the comparison `blo`; the 1-returning arm falls through
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 */
u32 APP_TASKMENU_IsFinish(TaskMenuWork *menu)
{
    if (menu->anmCnt >= 16 / menu->anmSpeed) {
        return 1;
    }
    return 0;
}

u8 APP_TASKMENU_GetCursorPos(const TaskMenuWork *menu)
{
    return menu->cursorPos;
}

/* Highlight (1) or un-highlight (0) the entry under the cursor. */
void APP_TASKMENU_SetCursorActive(TaskMenuWork *menu, u32 isActive)
{
    APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, isActive);
}

u32 APP_TASKMENU_IsDecide(TaskMenuWork *menu)
{
    return menu->isDecide;
}

/*
 * Create one window per entry, stacked downwards from the menu position,
 * draw its frame, queue its text and transfer it.
 *
 * With posType set the position is the bottom right corner; both arms
 * narrow to u8, which keeps the two lsls/lsrs #0x18 pairs.
 */
void APP_TASKMENU_CreateWindows(TaskMenuWork *menu, TaskMenuRes *res)
{
    u32 posX;
    u32 posY;
    u8  i;
    struct BmpWin *win;
    TaskMenuItem *items;
    TaskMenuItem *item;

    if (menu->init.posType == 0) {
        posX = menu->init.charPosX;
        posY = menu->init.charPosY;
    } else {
        posX = (u8)(menu->init.charPosX - menu->init.width);
        posY = (u8)(menu->init.charPosY - menu->init.height * menu->init.itemNum);
    }
    for (i = 0; i < menu->init.itemNum; i++) {
        menu->winWork[i] = BMP_WIN_Create((u8)menu->res->bgFrame, posX,
                                        (u8)(posY + i * menu->init.height), menu->init.width,
                                        menu->init.height, (u8)(menu->res->palNo + 1), 1);
        APP_TASKMENU_DrawWinFrame(menu->winWork[i], res, menu->itemWork[i].type);
        items = menu->itemWork;
        item = &items[i];
        PRINTSYS_PrintQueColor(res->printQue, BMP_WIN_GetBmp(menu->winWork[i]), 0xa, 6,
                     items[i].str, res->font, item->msgColor);
        win = menu->winWork[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
    }
}

/* Show a window with the active palette (1) or the inactive one (0). */
void APP_TASKMENU_SetWinActive(struct BmpWin *win, TaskMenuRes *res, int isActive)
{
    if (isActive == 1) {
        BMP_WIN_SetPalette(win, (u8)res->palNo);
    } else if (isActive == 0) {
        BMP_WIN_SetPalette(win, (u8)(res->palNo + 1));
    }
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
}

/*
 * Advance the cursor colour phase by 0x400 and write the pulsing cursor
 * colour into colour 6 of palette palNo (main BG for frames 0..3, else
 * sub BG).
 */
void APP_TASKMENU_UpdateCursorColor(u16 *colorPhase, u16 *color, u32 bgFrame, u32 palNo)
{
    s32 wave;
    u8 b, r, g;

    if (*colorPhase + 0x400 >= 0x10000) {
        *colorPhase = (u16)(*colorPhase - 0xfc00);
    } else {
        *colorPhase = (u16)(*colorPhase + 0x400);
    }
    wave = (s16)((FX_SinCosTable_[2 * (*colorPhase >> 4) + 1] + 0x1000) / 2);
    b = (u8)(((wave + wave * 16) >> 12) + 0xd);
    r = (u8)(((wave * 7) >> 12) + 5);
    g = (u8)(((wave * 15) >> 12) + 0xa);
    *color = (u16)(r | (g << 5) | (b << 10));
    if (bgFrame <= 3) {
        NNS_GfdRegisterNewVramTransferTask(0xf, palNo * 32 + 0xc, color, 2);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x1f, palNo * 32 + 0xc, color, 2);
    }
}

/*
 * The same pulse, blended channel by channel between color0 and color1.
 *
 * bgFrame is a u16: nothing in the instruction stream shows the width,
 * but the narrower type changes the order the scheduler emits the
 * colour unpack in.
 */
void APP_TASKMENU_UpdateCursorColorBlend(u16 *colorPhase, u16 *color, u16 bgFrame, u32 palNo,
                   u16 color0, u16 color1)
{
    s32 wave;
    u8 r0, g0, b0;
    u8 r1, g1, b1;
    u8 r, g, b;

    r0 = (u8)(color0 & 0x1f);
    g0 = (u8)((color0 & (0x1f << 5)) >> 5);
    b0 = (u8)((color0 & (0x1f << 10)) >> 10);
    r1 = (u8)(color1 & 0x1f);
    g1 = (u8)((color1 & (0x1f << 5)) >> 5);
    b1 = (u8)((color1 & (0x1f << 10)) >> 10);
    if (*colorPhase + 0x400 >= 0x10000) {
        *colorPhase = (u16)(*colorPhase - 0xfc00);
    } else {
        *colorPhase = (u16)(*colorPhase + 0x400);
    }
    wave = (s16)((FX_SinCosTable_[2 * (*colorPhase >> 4) + 1] + 0x1000) / 2);
    b = (u8)(b0 + ((wave * (b1 - b0)) >> 12));
    r = (u8)(r0 + ((wave * (r1 - r0)) >> 12));
    g = (u8)(g0 + ((wave * (g1 - g0)) >> 12));
    *color = (u16)(r | (g << 5) | (b << 10));
    if (bgFrame <= 3) {
        NNS_GfdRegisterNewVramTransferTask(0xf, palNo * 32 + 0xc, color, 2);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x1f, palNo * 32 + 0xc, color, 2);
    }
}

/* Disable key input; switching to touch mode un-highlights the cursor entry. */
void APP_TASKMENU_SetDisableKey(TaskMenuWork *menu, int isDisable)
{
    menu->isDisableKey = isDisable;
    if (isDisable == 1) {
        UI_SetInputMode(1);
        APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 0);
    }
}

/* Move the cursor; in key mode highlight only the new entry. */
void APP_TASKMENU_SetCursorPos(TaskMenuWork *menu, int pos)
{
    int i;

    menu->cursorPos = pos;
    if (UI_GetInputMode() != 0) {
        return;
    }
    for (i = 0; i < menu->init.itemNum; i++) {
        if (i == pos) {
            APP_TASKMENU_SetWinActive(menu->winWork[i], menu->res, 1);
        } else {
            APP_TASKMENU_SetWinActive(menu->winWork[i], menu->res, 0);
        }
    }
}

/*
 * Key input: up/down move the cursor with wrap-around (SE 0x548); A
 * decides (SE 0x551 on the back entry, else 0x54C); B jumps to the last
 * entry and decides (SE 0x551). In touch mode the first key press only
 * shows the cursor again.
 *
 * In the B arm the cursor store is written before the isDecide store: the
 * scheduler emits them the other way round, but the source order decides
 * which of the constant 1 and the count temporary gets r0.
 */
void APP_TASKMENU_UpdateKey(TaskMenuWork *menu)
{
    u32 trg;
    u32 repeat;
    int prev;

    trg = KEY_GetTrg();
    repeat = KEY_GetRepeat();
    if (menu->isDisableKey == 1) {
        return;
    }
    if (UI_GetInputMode() == 1) {
        if ((trg & 2) == 0) {
            if ((trg & 0xC3) == 0) {
                return;
            }
            APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 1);
            UI_SetInputMode(0);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return;
        }
    }
    prev = menu->cursorPos;
    if (repeat & 0x40) {
        if (prev == 0) {
            menu->cursorPos = (u8)(menu->init.itemNum - 1);
        } else {
            menu->cursorPos = (u8)(prev - 1);
        }
        menu->colorPhase = 0;
        GFL_USE_PlaySeDefaultVolume(0x548);
    } else if (repeat & 0x80) {
        if (prev >= menu->init.itemNum - 1) {
            menu->cursorPos = 0;
        } else {
            menu->cursorPos = (u8)(prev + 1);
        }
        menu->colorPhase = 0;
        GFL_USE_PlaySeDefaultVolume(0x548);
    } else {
        if (trg & 1) {
            menu->isDecide = 1;
            if (menu->itemWork[prev].type == 1) {
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
        } else if (trg & 2) {
            menu->cursorPos = (u8)(menu->init.itemNum - 1);
            menu->isDecide = 1;
            GFL_USE_PlaySeDefaultVolume(0x551);
            UI_SetInputMode(0);
        }
    }
    if (prev == menu->cursorPos) {
        return;
    }
    APP_TASKMENU_SetWinActive(menu->winWork[prev], menu->res, 0);
    APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 1);
}

/*
 * Touch input: build one hit rectangle (top, bottom, left, right in
 * pixels) per entry, 0xFF-terminated; a hit moves the cursor, decides
 * and switches to touch mode.
 */
void APP_TASKMENU_UpdateTouch(TaskMenuWork *menu)
{
    u8  hitTbl[0x24];
    u32 posX;
    u8  posY;
    u8  i;
    int hit;

    if (menu->init.posType == 0) {
        posX = menu->init.charPosX;
        posY = menu->init.charPosY;
    } else {
        posX = (u8)(menu->init.charPosX - menu->init.width);
        posY = (u8)(menu->init.charPosY - menu->init.height * menu->init.itemNum);
    }
    for (i = 0; i < menu->init.itemNum; i++) {
        hitTbl[i * 4 + 0] = (u8)((posY << 3) + menu->init.height * 8 * i);
        hitTbl[i * 4 + 1] = (u8)((posY << 3) + menu->init.height * 8 * (i + 1));
        hitTbl[i * 4 + 2] = (u8)(posX << 3);
        hitTbl[i * 4 + 3] = (u8)(((posX + menu->init.width) << 3) - 1);
    }
    hitTbl[i * 4] = 0xff;
    hit = TOUCHPANEL_HitTrg(hitTbl);
    if (hit == ~0) {
        return;
    }
    UI_SetInputMode(1);
    APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 0);
    menu->cursorPos = (u8)hit;
    menu->isDecide = 1;
    APP_TASKMENU_SetWinActive(menu->winWork[menu->cursorPos], menu->res, 1);
    if (menu->cursorPos == 0) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return;
    }
    if (menu->itemWork[menu->cursorPos].type == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    }
    GFL_USE_PlaySeDefaultVolume(0x54C);
}

/*
 * Create the shared resources: load the window frame characters (file
 * 0x20) and the frame palette (file 0x1F) into palette palNo (main BG for
 * frames 0..3, else sub BG).
 *
 * The archive id is the first argument of both loaders and the heap id
 * is the last of six, an ordinary fifth (stack) parameter here.
 */
TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, struct GFont *font, struct PrintQueue *printQue, u16 heapId)
{
    TaskMenuRes *res;
    u32 pltType;

    pltType = 0;
    res = GFL_HEAP_Alloc(heapId, sizeof(TaskMenuRes), 0, app_taskmenu_File, 0x2c6);
    MI_CpuFill8(res, 0, sizeof(TaskMenuRes));
    res->bgFrame = bgFrame;
    res->palNo = palNo;
    res->font = font;
    res->printQue = printQue;
    if (bgFrame > 3) {
        pltType = 4;
    }
    res->chrBuf = ARC_UTIL_LoadBgCharDataFromArchive(APP_ICON_GetArchiveId(), 0x20, 0, &res->chrData, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(APP_ICON_GetArchiveId(), 0x1f, pltType, palNo << 5, 0x40, heapId);
    return res;
}

void APP_TASKMENU_RES_Delete(TaskMenuRes *res)
{
    GFL_HEAP_Free(res->chrBuf);
    GFL_HEAP_Free(res);
}

/* A single window three characters high, transferred at once. */
TaskMenuWin *APP_TASKMENU_WIN_Create(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u16 heapId)
{
    return APP_TASKMENU_WIN_CreateEx(res, item, charPosX, charPosY, width, 3, 0, 0, heapId);
}

TaskMenuWin *APP_TASKMENU_WIN_CreateEx(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height,
                           u32 anmSpeed, u32 isCenter, u16 heapId)
{
    TaskMenuWin *win = APP_TASKMENU_WIN_CreateCore(res, item, charPosX, charPosY, width, height, anmSpeed, isCenter, heapId);
    struct BmpWin *bmpWin = win->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(bmpWin));
    return win;
}

/* As APP_TASKMENU_WIN_CreateEx, without writing the window into the BG screen. */
TaskMenuWin *APP_TASKMENU_WIN_CreateExNoScreen(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY, u8 width, u8 height,
                           u32 anmSpeed, u32 isCenter, u16 heapId)
{
    TaskMenuWin *win = APP_TASKMENU_WIN_CreateCore(res, item, charPosX, charPosY, width, height, anmSpeed, isCenter, heapId);
    BMP_WIN_MakeScreen(win->bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win->bmpWin));
    return win;
}

/*
 * Allocate a cleared window, create its BG window, draw the frame and
 * queue the text (centred when isCenter is 1, else 8 pixels in).
 *
 * charPosX and charPosY are u16 parameters: the original spills them with
 * a full-word str, reloads with a full-word ldr and never truncates, so
 * only a parameter already 16 bits wide at entry gives the image.
 * frameStyle is lifted into a local before the frame call: it pins the
 * load ahead of the argument setup.
 */
TaskMenuWin *APP_TASKMENU_WIN_CreateCore(TaskMenuRes *res, const TaskMenuItem *item, u16 charPosX, u16 charPosY,
                           u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId)
{
    TaskMenuWin *win;
    struct BmpWin *bmpWin;
    s16 strX;
    u32 frameStyle;

    strX = 2;
    win = GFL_HEAP_Alloc(heapId, sizeof(TaskMenuWin), 0, app_taskmenu_File, 0x337);
    MI_CpuFill8(win, 0, sizeof(TaskMenuWin));
    win->res = res;
    win->isUpdateTrans = 1;
    win->anmSpeed = (u16)(anmSpeed + 1);
    bmpWin = BMP_WIN_Create((u8)res->bgFrame, charPosX, charPosY, width, height, (u8)(res->palNo + 1), 1);
    frameStyle = item->type;
    win->bmpWin = bmpWin;
    APP_TASKMENU_DrawWinFrame(bmpWin, res, frameStyle);
    if (isCenter == 1) {
        strX = (u8)(((width << 3) - GF_FONT_MeasureWidestLine(item->str, res->font, 0)
                     - 0x10) >> 1);
    }
    PRINTSYS_PrintQueColor(res->printQue, BMP_WIN_GetBmp(win->bmpWin),
                 (s16)(strX + 8), 6, item->str, res->font, item->msgColor);
    win->activeColor0 = 0x3545;
    win->activeColor1 = 0x7B2C;
    return win;
}

void APP_TASKMENU_WIN_Delete(TaskMenuWin *win)
{
    BMP_WIN_ClearScreen(win->bmpWin);
    APP_TASKMENU_WIN_Free(win);
}

/* Delete without clearing the screen: an `ldr r3, [pc, #0]; bx r3` tail call. */
void APP_TASKMENU_WIN_DeleteNoClear(TaskMenuWin *win)
{
    APP_TASKMENU_WIN_Free(win);
}

void APP_TASKMENU_WIN_Free(TaskMenuWin *win)
{
    BMP_WIN_Delete(win->bmpWin);
    GFL_HEAP_Free(win);
}

/*
 * Per-frame step of a window: transfer it once its text is printed, run
 * the decide blink (4 / anmSpeed frames per phase) and animate the cursor
 * colour. The parity test is the signed `% 2` sequence, not a mask.
 */
void APP_TASKMENU_WIN_Update(TaskMenuWin *win)
{
    struct BmpWin *bmpWin;
    TaskMenuRes *res;

    if (win->isUpdateTrans != 0) {
        if (PRINTSYS_QUE_IsExistTarget(win->res->printQue, BMP_WIN_GetBmp(win->bmpWin)) == 0) {
            bmpWin = win->bmpWin;
            BMP_WIN_TransferChars(bmpWin);
            BMP_WIN_MakeScreen(bmpWin);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(bmpWin));
            win->isUpdateTrans = 0;
        }
    }
    if (win->isDecide != 0) {
        s32 step = 4 / win->anmSpeed;
        if ((u8)(win->anmCnt / step % 2) == 0) {
            APP_TASKMENU_SetWinActive(win->bmpWin, win->res, 1);
        } else {
            APP_TASKMENU_SetWinActive(win->bmpWin, win->res, 0);
        }
        win->anmCnt = win->anmCnt + 1;
    }
    res = win->res;
    APP_TASKMENU_UpdateCursorColorBlend(&win->colorPhase, &win->cursorColor, (u8)res->bgFrame, (u8)res->palNo,
                  win->activeColor0, win->activeColor1);
}

void APP_TASKMENU_WIN_SetActive(TaskMenuWin *win, u32 isActive)
{
    win->colorPhase = 0;
    APP_TASKMENU_SetWinActive(win->bmpWin, win->res, isActive);
}

void APP_TASKMENU_WIN_SetDecide(TaskMenuWin *win, int isDecide)
{
    win->isDecide = isDecide;
}

/*
 * Alternate entry: APP_TASKMENU_WIN_SetDecideReturn() is the `bx lr` at APP_TASKMENU_WIN_SetDecide + 2
 * (the function map lists it as its own symbol); it has no code of its own.
 */
u32 APP_TASKMENU_WIN_IsFinish(TaskMenuWin *win)
{
    s32 frames = 0x10 / win->anmSpeed;
    if (win->anmCnt < frames) {
        return 0;
    }
    return 1;
}

/*
 * Whether the touch panel is touched inside the window. The bottom edge
 * is computed from the window WIDTH (BMP_WIN_GetWidth twice), as in the
 * original.
 */
u32 APP_TASKMENU_WIN_IsTouch(TaskMenuWin *win)
{
    u32 x;
    u32 y;
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;

    if (TOUCHPANEL_GetPointTrg(&x, &y) == 0) {
        goto fail;
    }
    left = BMP_WIN_GetPosX(win->bmpWin) * 8;
    top = BMP_WIN_GetPosY(win->bmpWin) * 8;
    right = left + BMP_WIN_GetWidth(win->bmpWin) * 8;
    bottom = top + BMP_WIN_GetWidth(win->bmpWin) * 8;
    if (x - left > right - left) {
        goto fail;
    }
    if (y - top > bottom - top) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}

void APP_TASKMENU_WIN_ResetDecide(TaskMenuWin *win)
{
    win->isDecide = 0;
    win->anmCnt = 0;
}

/* Set the shared palette number and the window's blend colours, then repaint inactive. */
void APP_TASKMENU_WIN_ChangePalette(TaskMenuWin *win, TaskMenuRes *res, u32 palNo, u32 color0, u16 color1)
{
    res->palNo = palNo;
    win->activeColor0 = color0;
    win->activeColor1 = color1;
    BMP_WIN_SetPalette(win->bmpWin, (u8)(palNo + 1));
    BMP_WIN_MakeScreen(win->bmpWin);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win->bmpWin));
}

/*
 * Draw a window frame into the window's characters, one 0x20-byte tile per
 * cell: four corners, three edges, two style tiles (frameStyle != 0) left
 * of the right edge, the left and right edges, the interior.
 *
 * Both loops are a top guard plus a bottom back-edge, not a plain `for`.
 * cellOfs must be declared before charBuf: the two spilled locals take
 * sp+0xc and sp+0x10 in declaration order
 * (docs/idioms/local-declaration-order-is-stack-order.md).
 */
void APP_TASKMENU_DrawWinFrame(struct BmpWin *win, TaskMenuRes *res, u32 frameStyle)
{
    u8  y;
    u8  x;
    u32 cellOfs;
    u32 charBuf;
    u32 styleTileL;
    u32 styleTileR;
    u32 src;
    u32 style;

    y = 0;
    if (y >= BMP_WIN_GetHeight(win)) {
        return;
    }
    style = frameStyle - 1;
    styleTileL = (style + style * 2 + 9) << 5;
    styleTileR = (style + style * 2 + 10) << 5;
    for (;;) {
        x = 0;
        if (x >= BMP_WIN_GetWidth(win)) {
            goto nextrow;
        }
        for (;;) {
        charBuf = (u32)BMP_GetPixels(BMP_WIN_GetBmp(win));
        cellOfs = (x + y * BMP_WIN_GetWidth(win)) << 5;
        if (y == 0 && x == 0) {
            src = (u32)res->chrData->pRawData;
        } else if (y == 0 && x == BMP_WIN_GetWidth(win) - 1) {
            src = (u32)res->chrData->pRawData + 0x40;
        } else if (y == 0) {
            src = (u32)res->chrData->pRawData + 0x20;
        } else if (y == BMP_WIN_GetHeight(win) - 1 && x == 0) {
            src = (u32)res->chrData->pRawData + 0xc0;
        } else if (y == BMP_WIN_GetHeight(win) - 1 && x == BMP_WIN_GetWidth(win) - 1) {
            src = (u32)res->chrData->pRawData + (1 << 8);
        } else if (y == BMP_WIN_GetHeight(win) - 1) {
            src = (u32)res->chrData->pRawData + 0xe0;
        } else if (frameStyle != 0 && x == BMP_WIN_GetWidth(win) - 3) {
            src = (u32)res->chrData->pRawData + styleTileL;
        } else if (frameStyle != 0 && x == BMP_WIN_GetWidth(win) - 2) {
            src = (u32)res->chrData->pRawData + styleTileR;
        } else if (x == 0) {
            src = (u32)res->chrData->pRawData + 0x60;
        } else if (x == BMP_WIN_GetWidth(win) - 1) {
            src = (u32)res->chrData->pRawData + 0xa0;
        } else {
            src = (u32)res->chrData->pRawData + 0x80;
        }
        MIi_CpuCopy32((const void *)src, (void *)(charBuf + cellOfs), 0x20);
            x++;
            if (x >= BMP_WIN_GetWidth(win)) {
                break;
            }
        }
nextrow:
        y++;
        if (y >= BMP_WIN_GetHeight(win)) {
            return;
        }
    }
}

void APP_TASKMENU_WIN_ClearScreen(TaskMenuWin *win)
{
    BMP_WIN_ClearScreen(win->bmpWin);
    BG_SYS_MarkTileDirty((u8)win->res->bgFrame);
}

void APP_TASKMENU_WIN_TransChar(TaskMenuWin *win)
{
    BMP_WIN_MakeScreen(win->bmpWin);
    BG_SYS_MarkTileDirty((u8)win->res->bgFrame);
}

u32 APP_TASKMENU_WIN_IsUpdateTrans(TaskMenuWin *win)
{
    return win->isUpdateTrans;
}
