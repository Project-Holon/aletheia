/*
 * file:     time_icon.c
 * unit:     yes
 * function: TIME_ICON_Create, TIME_ICON_CreateNode, TIME_ICON_Init, TIME_ICON_Alloc, TIME_ICON_Start, TIME_ICON_Delete, TIME_ICON_TaskMain, TIME_ICON_NodeMain, TIME_ICON_Update
 * address:  0x0202EE30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   time_icon_File     0x020A7814  data
 *   TCB_AddTask  0x02030DA8  arm
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   GFL_USE_GetRandom   0x020056EC  thumb
 *   BMP_CreateFromArchive   0x0204384C  arm
 *   BMP_WIN_GetBgLayer   0x02045730  arm
 *   BMP_WIN_GetPosX   0x02045758  arm
 *   BMP_WIN_GetWidth   0x02045738  arm
 *   BMP_WIN_GetPosY   0x02045760  arm
 *   BMP_WIN_GetHeight   0x02045740  arm
 *   BMP_WIN_GetPalette   0x02045778  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   BG_SYS_MarkTileDirty   0x02041B6C  arm
 *   BMP_Delete   0x020437AC  arm
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_Delete   0x020452E8  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 *   TCBL_DeleteTask   0x02031194  arm
 *   BMP_Blit   0x020439A0  arm
 */
#include "comm_player_support_shared_types.h"
#include "time_icon_shared_types.h"

struct Tcb;

struct TcbList;

struct TcblNode;

struct TcblList;

struct BmpWin;

/*
 * TIME_ICON object (0x1c bytes): the animated wait icon, a 2x2 tile window
 * in the bottom right corner of a reference window.  Each tick copies the
 * next 16x16 frame of the 8-frame sheet into the window.
 */
struct TimeIcon {
    struct Tcb *task;           /* 0x00, set when created with a task list */
    struct TcblNode *node;      /* 0x04, set when created with a TCBL node */
    struct BmpWin *win;         /* 0x08 */
    struct Bmp *sheet;          /* 0x0c, frame sheet loaded from archive 0xC6 */
    u16 heapId;                 /* 0x10 */
    u8 fillColor;               /* 0x12, window background fill value */
    u8 waitCounter;             /* 0x13, ticks left until the next frame */
    u8 waitInterval;            /* 0x14, ticks per frame */
    u8 frame;                   /* 0x15, current frame, 0..7 */
    u8 reserved16[2];           /* 0x16 */
    u32 isActive;               /* 0x18 */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern struct Tcb *TCB_AddTask(struct TcbList *list, void (*callback)(struct Tcb *, void *), void *work, u32 priority);

extern struct TcblNode *TCBL_AddTask(struct TcblList *list, void (*callback)(struct TcblNode *, void *), u32 size, u32 flags);

extern void *TCBL_GetWork(struct TcblNode *node);

extern u32 GFL_USE_GetRandom(u32 range);

extern struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern u8 BMP_WIN_GetPosX(struct BmpWin *win);

extern u8 BMP_WIN_GetWidth(struct BmpWin *win);

extern u8 BMP_WIN_GetPosY(struct BmpWin *win);

extern u8 BMP_WIN_GetHeight(struct BmpWin *win);

extern u8 BMP_WIN_GetPalette(struct BmpWin *win);

extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u32 width, u32 height, u32 palette, u32 allocDir);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern void BG_SYS_MarkTileDirty(u32 bgLayer);

extern void BMP_Delete(struct Bmp *bmp);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern u32 BMP_WIN_Delete(struct BmpWin *win);

extern void TCB_DeleteTask(struct Tcb *tcb);

extern void TCBL_DeleteTask(struct TcblNode *node);

extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u32 colorKey);

struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId);

struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);

void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);

struct TimeIcon *TIME_ICON_Alloc(u32 heapId);

void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval);

void TIME_ICON_Delete(struct TimeIcon *icon);

void TIME_ICON_TaskMain(struct Tcb *tcb, void *work);

void TIME_ICON_NodeMain(struct TcblNode *node, void *work);

void TIME_ICON_Update(struct TimeIcon *icon);

extern char time_icon_File[];

/*
 * Allocates and fills the 0x1c-byte time icon.  The heap id is the fifth
 * (stack) argument and is re-read from its slot for the second use (it is
 * also what TIME_ICON_Init's u16 tail parameter receives), so it is spelled
 * `volatile u16`.  When the optional task list is non-null the icon is
 * registered as a task (callback TIME_ICON_TaskMain); otherwise `task` is zeroed.
 *
 * Sibling of TIME_ICON_CreateNode, which builds the same object through the
 * TCBL_AddTask allocator instead.
 */
struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId)
{
    struct TimeIcon *icon;

    icon = GFL_HEAP_Alloc(heapId, sizeof(struct TimeIcon), 0, time_icon_File, 0x49);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    if (taskList != 0) {
        icon->task = TCB_AddTask(taskList, TIME_ICON_TaskMain, icon, 0);
    } else {
        icon->task = 0;
    }
    icon->node = 0;
    icon->isActive = 1;
    return icon;
}

/*
 * Sibling of TIME_ICON_Create: the same 0x1c-byte TimeIcon, built through the
 * TCBL_AddTask node allocator instead of GFL_HEAP_Alloc.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of TIME_ICON_Create, which
 * registers a task into +0 and zeroes +4.  The node callback is
 * TIME_ICON_NodeMain.
 */
struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    struct TcblNode *node;
    struct TimeIcon *icon;

    node = TCBL_AddTask(nodeList, TIME_ICON_NodeMain, 0x1c, 0);
    icon = TCBL_GetWork(node);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    icon->node = node;
    icon->task = 0;
    icon->isActive = 1;
    return icon;
}

/*
 * Fills in a freshly allocated icon: the heap id, the fill color, the frame
 * timing and a random start frame, then builds the 2x2 window from the
 * reference window's six accessors (x and y are the sum of position and
 * size, minus two, truncated to a byte).
 */
void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->heapId = heapId;
    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = GFL_USE_GetRandom(8);
    icon->sheet = BMP_CreateFromArchive(0xC6, 0, 1, icon->heapId);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(icon->win));
}

/* Allocates an idle TimeIcon: heap id and frame sheet only; TIME_ICON_Start finishes it. */
struct TimeIcon *TIME_ICON_Alloc(u32 heapId)
{
    struct TimeIcon *icon = GFL_HEAP_Alloc(heapId, 0x1c, 0, time_icon_File, 0xa6);

    icon->heapId = (u16)heapId;
    icon->sheet = BMP_CreateFromArchive(0xc6, 0, 1, icon->heapId);
    icon->win = 0;
    icon->task = 0;
    icon->node = 0;
    return icon;
}

/*
 * TIME_ICON_Init's twin for an icon from TIME_ICON_Alloc: the window is built
 * the same way, then the icon is registered as a task of the caller's list.
 */
void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = GFL_USE_GetRandom(8);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(icon->win));

    icon->node = 0;
    icon->task = TCB_AddTask(taskList, TIME_ICON_TaskMain, icon, 0);
    icon->isActive = 1;
}

/*
 * Deletes the icon.  An icon that never got a window (neither task nor
 * node) only frees its sheet and itself; otherwise it clears the window,
 * frees the sheet and removes whichever of task and node it holds.
 */
void TIME_ICON_Delete(struct TimeIcon *icon)
{
    if (icon->task == 0 && icon->node == 0) {
        BMP_Delete(icon->sheet);
        GFL_HEAP_Free(icon);
        return;
    }

    icon->isActive = 0;
    BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
    BMP_WIN_TransferChars(icon->win);
    BMP_WIN_Delete(icon->win);
    BMP_Delete(icon->sheet);

    if (icon->task != 0) {
        TCB_DeleteTask(icon->task);
        GFL_HEAP_Free(icon);
        return;
    }

    if (icon->node != 0)
        TCBL_DeleteTask(icon->node);
}

/* Task callback of an icon created with a task list. */
void TIME_ICON_TaskMain(struct Tcb *tcb, void *work)
{
    TIME_ICON_Update(work);
}

/* Node callback of an icon created with a TCBL node. */
void TIME_ICON_NodeMain(struct TcblNode *node, void *work)
{
    TIME_ICON_Update(work);
}

/*
 * One tick of the icon: while the wait counter runs down it only counts;
 * at zero it fills the window, copies the next 16x16 frame of the sheet
 * into it, commits the window and reloads the counter.  The frame wraps at 8.
 */
void TIME_ICON_Update(struct TimeIcon *icon)
{
    if (icon->isActive == 0)
        return;

    if (icon->waitCounter == 0) {
        BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
        BMP_Blit(icon->sheet, BMP_WIN_GetBmp(icon->win), 0,
                      (u32)icon->frame << 4, 0, 0, 0x10, 0x10, 0);
        BMP_WIN_TransferChars(icon->win);

        icon->waitCounter = icon->waitInterval;
        icon->frame = icon->frame + 1;

        if (icon->frame == 8)
            icon->frame = 0;
    } else {
        icon->waitCounter = icon->waitCounter - 1;
    }
}
