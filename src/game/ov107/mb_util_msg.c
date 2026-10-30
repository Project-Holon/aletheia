/*
 * file:     mb_util_msg.c
 * unit:     yes
 * function: MB_UTIL_MSG_Create, MB_UTIL_MSG_Delete, MB_UTIL_MSG_Main, MB_UTIL_MSG_SetWindowLayout, MB_UTIL_MSG_PrintStream, MB_UTIL_MSG_PrintQueued, MB_UTIL_MSG_ClearWindow, MB_UTIL_MSG_CreateWordSet, MB_UTIL_MSG_DeleteWordSet, MB_UTIL_MSG_SetNumberLeft, MB_UTIL_MSG_SetNumberZeroPad, MB_UTIL_MSG_OpenYesNoTaskMenu, MB_UTIL_MSG_CloseTaskMenu, MB_UTIL_MSG_GetTaskMenuResult, MB_UTIL_MSG_OpenYesNoMenu, MB_UTIL_MSG_ClearYesNoMenu, MB_UTIL_MSG_ProcessYesNoMenu, MB_UTIL_MSG_PrintStreamSystemMsg, MB_UTIL_MSG_GetMsgData, MB_UTIL_MSG_GetWordSet, MB_UTIL_MSG_GetFont, MB_UTIL_MSG_IsPrintQueFinished, MB_UTIL_MSG_IsStreamIdle, MB_UTIL_MSG_SetKeyWaitFlag, MB_UTIL_MSG_SetTimeIconPending
 * address:  0x021F1404
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   TALKMSGWIN_Create 0x02194670 thumb ov021
 *   d_021F6E38 0x021F6E38 data a4
 *   ov021_id 0x00000015 data
 *   TALKMSGWIN_Delete 0x02194798 thumb ov021
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   TALKMSGWIN_DrawWindowFrame  0x02194A24  thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   TALKMSGWIN_ClearWindowFrame  0x02194A34  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 */
#include "../types.h"

struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct TaskMenu;
struct TaskMenuRes;
struct Strbuf;
struct WordSet;
struct BmpWin;
struct TextPrinter;
struct TalkMsgWin;
struct TimeIcon;

/* Parameters of the talk window (TALKMSGWIN_Create). */
typedef struct MbTalkWinParam {
    u16 heapId;
    u32 reserved;
    struct GfFont *font;
    u16 bgPalette;
    u32 bgFrame;
    u8 x;
    u8 y;
} MbTalkWinParam;

/* One entry of the yes/no task menu template. */
typedef struct MbMenuEntry {
    struct Strbuf *label;
    u16 color;
    u32 value;
} MbMenuEntry;

/* Task menu template (APP_TASKMENU_OpenMenu). */
typedef struct MbMenuTemplate {
    u32 heapId;
    u8 entryCount;
    MbMenuEntry *entries;
    u32 reserved;
    u8 x, y, width, height;
} MbMenuTemplate;

/* Position and size of a yes/no window (BMP_MENU_CreateYesNo). */
typedef struct MbWinRect {
    u8 frame;
    u8 x;
    u8 y;
    u8 width;
    u16 height;
} MbWinRect;

/* Message and menu helper of the Download Play screens: one font, one
   message bank, a print queue, a key cursor, an optional talk window and
   a task menu, all created together. */
typedef struct MbMsgWork {
    u16 heapId;
    u8 bgFrame;
    u8 menuBgFrame;
    int layout;
    int cursorMode;
    struct Tcbl *tcbl;
    struct BmpWin *window;
    struct GfFont *font;
    struct TextPrinter *stream;
    struct MsgBank *msgData;
    struct Strbuf *message;
    struct WordSet *wordSet;
    u8 keyCursorState[8];
    struct PrintSys *printQue;
    int printQueued;
    int keyWaitFlag;
    struct TaskMenu *taskMenu;
    struct TaskMenuRes *taskMenuRes;
    struct KeyCursor *keyCursor;
    MbWinRect yesNoRect;
    u8 pad4E[2];
    void *yesNoMenu;
    struct TalkMsgWin *talkWin;
    int timeIconPending;
    struct TimeIcon *timeIcon;
} MbMsgWork;

#include "../arm9/bmp_menu.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/arc_util.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct GFont;
#include "../arm9/app_taskmenu.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
#include "../arm9/gf_overlay.h"
struct TalkMsgWinParam;
struct TalkMsgWinSys;
#include "../ov021/talkmsgwin.h"
struct TaskMenuWork;
#include "../arm9/time_icon.h"
struct TextPrinter;
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/bmp_win.h"
struct PrintStreamCtrl;
struct TcblList;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/bg_sys.h"
#include "../arm9/wordset.h"
#include "../version.h"
struct Bmp;
struct TaskMenuInitWork;
extern const char d_021F6E38[];
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021F6DA4[];
#endif
extern u8 ov021_id[];

MbMsgWork *MB_UTIL_MSG_Create(u16 heapId, u32 bgFrame, u32 menuBgFrame, u32 msgFile, u32 useTalkWin, u32 cursorMode);
void MB_UTIL_MSG_Delete(MbMsgWork *work);
void MB_UTIL_MSG_Main(MbMsgWork *work);
void MB_UTIL_MSG_SetWindowLayout(MbMsgWork *work, int layout);
void MB_UTIL_MSG_PrintStream(MbMsgWork *work, int msgId, int speed);
void MB_UTIL_MSG_PrintQueued(MbMsgWork *work, int msgId);
void MB_UTIL_MSG_ClearWindow(MbMsgWork *work);
void MB_UTIL_MSG_CreateWordSet(MbMsgWork *work);
void MB_UTIL_MSG_DeleteWordSet(MbMsgWork *work);
void MB_UTIL_MSG_SetNumberLeft(MbMsgWork *work, int index, int value, int digits);
void MB_UTIL_MSG_SetNumberZeroPad(MbMsgWork *work, int index, int value, int digits);
void MB_UTIL_MSG_OpenYesNoTaskMenu(MbMsgWork *work, int layout);
void MB_UTIL_MSG_CloseTaskMenu(MbMsgWork *work);
int MB_UTIL_MSG_GetTaskMenuResult(MbMsgWork *work);
void MB_UTIL_MSG_OpenYesNoMenu(MbMsgWork *work, int unused);
void MB_UTIL_MSG_ClearYesNoMenu(MbMsgWork *work);
int MB_UTIL_MSG_ProcessYesNoMenu(MbMsgWork *work);
void MB_UTIL_MSG_PrintStreamSystemMsg(MbMsgWork *work, int speed);
struct MsgBank *MB_UTIL_MSG_GetMsgData(MbMsgWork *work);
struct WordSet *MB_UTIL_MSG_GetWordSet(MbMsgWork *work);
struct GfFont *MB_UTIL_MSG_GetFont(MbMsgWork *work);
int MB_UTIL_MSG_IsPrintQueFinished(MbMsgWork *work);
int MB_UTIL_MSG_IsStreamIdle(MbMsgWork *work);
void MB_UTIL_MSG_SetKeyWaitFlag(MbMsgWork *work, int flag);
void MB_UTIL_MSG_SetTimeIconPending(MbMsgWork *work, int pending);

/*
 * 2026-10-05 (wave P8 W4): 0x15 in the pool is an overlay id (ov021_id, passed to GF_OVERLAY_Load). The sixth parameter is copied to an int local cursor first (stored to cursorMode, later passed to APP_KEYCURSOR_CreateDefault); without the local the copy is propagated and the frame is 4 bytes short. EXACT in c99 and c.
 */
MbMsgWork *MB_UTIL_MSG_Create(u16 heapId, u32 bgFrame, u32 menuBgFrame, u32 msgFile, u32 useTalkWin, u32 cursorMode)
{
    MbMsgWork *w;
    MbTalkWinParam talk;
#if LANGUAGE != LANGUAGE_JAPANESE
    int cursor;
#endif

    w = (MbMsgWork *)GFL_HEAP_Alloc(heapId, sizeof(MbMsgWork), 1, PM_LANG_JA(d_021F6E38, str_ja_021F6DA4), PM_SRC_LINE(0x66, 0x64));
    w->heapId = heapId;
    w->bgFrame = bgFrame;
    w->menuBgFrame = menuBgFrame;
#if LANGUAGE == LANGUAGE_JAPANESE
    w->cursorMode = cursorMode;
#else
    cursor = cursorMode;
    w->cursorMode = cursor;
#endif
    w->window = 0;
    w->font = GF_FONT_Create(0x17, 0, 0, 0, w->heapId);
    w->msgData = MSGDATA_CreateFromArchive(0, 2, (u16)msgFile, w->heapId);
    BMP_MENUWORK_LoadCharAndPltt(bgFrame, 1, 0xD, 0, w->heapId);
    if (bgFrame < 4)
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1C0, 0x20, w->heapId);
    else
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1C0, 0x20, w->heapId);
    GF_FONT_SetDefaultTextColor();
    w->tcbl = (struct Tcbl *)TCBL_Create(w->heapId, w->heapId, 3, 0x100);
    w->stream = 0;
    w->message = 0;
    w->wordSet = 0;
    w->printQue = (struct PrintSys *)PRINTSYS_QUE_Create((u32)w->heapId);
    w->taskMenuRes = APP_TASKMENU_RES_Create(w->menuBgFrame, 10, (struct GFont *)w->font, (struct PrintQueue *)w->printQue, w->heapId);
    w->taskMenu = 0;
    w->yesNoMenu = 0;
#if LANGUAGE == LANGUAGE_JAPANESE
    w->keyCursor = APP_KEYCURSOR_CreateDefault(0xF, 0, 1, w->heapId);
#else
    w->keyCursor = APP_KEYCURSOR_CreateDefault(0xF, cursor, 1, w->heapId);
#endif
    GF_OVERLAY_Load((sptr)ov021_id);
    if (useTalkWin == 1) {
        talk.heapId = heapId;
        talk.reserved = 0;
        talk.font = w->font;
        talk.bgPalette = 10;
        talk.bgFrame = bgFrame;
        talk.x = 12;
        talk.y = 14;
        w->talkWin = (struct TalkMsgWin *)TALKMSGWIN_Create((struct TalkMsgWinParam *)(&talk.heapId));
    } else {
        w->talkWin = 0;
    }
    w->printQueued = 0;
    w->keyWaitFlag = 0;
    w->timeIconPending = 0;
    w->timeIcon = 0;
    return w;
}

void MB_UTIL_MSG_Delete(MbMsgWork *work)
{
    if (work->talkWin)
        TALKMSGWIN_Delete((struct TalkMsgWinSys *)work->talkWin);
    if (work->taskMenu)
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)work->taskMenu);
    if (work->yesNoMenu)
        BMP_MENU_DeleteYesNo(work->yesNoMenu);
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    APP_KEYCURSOR_Delete(work->keyCursor);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printQue);
    if (work->stream)
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->stream);
    if (work->message)
        STRBUF_Delete((struct Strbuf *)work->message);
    if (work->wordSet)
        MB_UTIL_MSG_DeleteWordSet(work);
    MSGDATA_Delete(work->msgData);
    if (work->window)
        BMP_WIN_Delete(work->window);
    GF_FONT_Delete(work->font);
    TCBL_Destroy((struct TcblSystem *)work->tcbl);
    GFL_HEAP_Free(work);
    GF_OVERLAY_Unload((sptr)ov021_id);
}

void MB_UTIL_MSG_Main(MbMsgWork *work)
{
    int done;
    TCBL_Main((struct TcblSystem *)work->tcbl);
    if (work->stream) {
        done = PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)work->keyCursorState, (struct TextPrinter *)work->stream);
        APP_KEYCURSOR_Update(work->keyCursor, (struct TextPrinter *)work->stream, work->window);
        if (done == 1) {
            PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->stream);
            work->stream = 0;
        }
    }
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printQue);
    if (work->printQueued == 1 && PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQue) == 1) {
        BMP_WIN_TransferChars(work->window);
        work->printQueued = 0;
        if (work->timeIconPending == 1) {
            work->timeIconPending = 0;
            work->timeIcon = TIME_ICON_CreateNode((struct TcblList *)work->tcbl, work->window, 15, 16, work->heapId);
        }
    }
    if (work->taskMenu)
        APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)work->taskMenu);
}

void MB_UTIL_MSG_SetWindowLayout(MbMsgWork *work, int layout)
{
    if (work->layout != layout) {
        if (work->window != 0) {
            BMP_WIN_Delete(work->window);
            work->window = 0;
        }
        switch (layout) {
        case 0:
            break;
        case 1:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 3, 8, 0x1A, 8, 0xE, 1);
            break;
        case 2:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 3, 2, 0x1A, 0x12, 0xE, 1);
            break;
        case 3:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 3, 2, 0x1A, 0x14, 0xE, 1);
            break;
        case 4:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 1, 0x15, 0x1E, 2, 0xE, 1);
            break;
        case 5:
        case 8:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 1, 0x13, 0x1E, 4, 0xE, 1);
            break;
        case 6:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 1, 0x11, 0x1E, 6, 0xE, 1);
            break;
        case 7:
            work->window = (struct BmpWin *)BMP_WIN_Create(work->bgFrame, 1, 1, 0x1E, 4, 0xE, 1);
            break;
        }
        work->layout = layout;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0);
    BMP_WIN_TransferChars(work->window);
    BMP_WIN_MakeScreen(work->window);
    BG_SYS_PushTile(work->bgFrame);
}

void MB_UTIL_MSG_PrintStream(MbMsgWork *work, int msgId, int speed)
{
    struct Strbuf *expanded;

    if (work->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->stream);
        work->stream = 0;
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->keyWaitFlag = 0;
    work->timeIconPending = 0;
    if (work->message != 0) {
        STRBUF_Delete((struct Strbuf *)work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0xF);
    work->message = MSGDATA_AllocString(work->msgData, msgId);
    if (work->wordSet != 0) {
        expanded = (struct Strbuf *)STRBUF_Create(PM_LANG_JA(0x17B, 0x100), work->heapId);
        WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)expanded, (struct Strbuf *)work->message);
        STRBUF_Delete((struct Strbuf *)work->message);
        work->message = expanded;
    }
    work->stream = PRINTSYS_PrintStream(work->window, 0, 0, work->message, work->font, speed, work->tcbl, 2, work->heapId, 0xF);
    if (work->layout == 8) {
        TALKMSGWIN_DrawWindowFrame((struct TalkMsgWinSys *)work->talkWin, work->window, 0);
    } else {
        BMP_MENUWORK_DrawWindow(work->window, 1, 1, 0xD);
    }
    if (work->cursorMode == 1) {
        PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)work->keyCursorState, 6);
    } else {
        PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)work->keyCursorState, 4);
    }
}

void MB_UTIL_MSG_PrintQueued(MbMsgWork *work, int msgId)
{
    struct Strbuf *expanded;

    if (work->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->stream);
        work->stream = 0;
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->message != 0) {
        STRBUF_Delete((struct Strbuf *)work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0xF);
    work->message = MSGDATA_AllocString(work->msgData, msgId);
    if (work->wordSet != 0) {
        expanded = (struct Strbuf *)STRBUF_Create(PM_LANG_JA(0x17B, 0x100), work->heapId);
        WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)expanded, (struct Strbuf *)work->message);
        STRBUF_Delete((struct Strbuf *)work->message);
        work->message = expanded;
    }
    PRINTSYS_PrintQue((struct PrintQueue *)work->printQue, (struct Bmp *)BMP_WIN_GetBmp(work->window), 0, 0, (struct Strbuf *)work->message, (struct GfFont *)work->font);
    work->printQueued = 1;
    if (work->layout == 8) {
        TALKMSGWIN_DrawWindowFrame((struct TalkMsgWinSys *)work->talkWin, work->window, 0);
        BG_SYS_PushTile(work->bgFrame);
    } else {
        BMP_MENUWORK_DrawWindow(work->window, 1, 1, 0xD);
    }
}

void MB_UTIL_MSG_ClearWindow(MbMsgWork *work)
{
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0);
    if (work->layout == 8) {
        TALKMSGWIN_ClearWindowFrame((struct TalkMsgWinSys *)work->talkWin, work->window);
        BG_SYS_PushTile(work->bgFrame);
    } else {
        BMP_MENUWORK_DrawWindowBorder(work->window, 1);
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
}

void MB_UTIL_MSG_CreateWordSet(MbMsgWork *work)
{
    if (work->wordSet == 0) {
        work->wordSet = WORDSET_CreateDefault(work->heapId);
    }
}

void MB_UTIL_MSG_DeleteWordSet(MbMsgWork *work)
{
    if (work->wordSet != 0) {
        WORDSET_Delete(work->wordSet);
        work->wordSet = 0;
    }
}

void MB_UTIL_MSG_SetNumberLeft(MbMsgWork *work, int index, int value, int digits)
{
    WORDSET_SetSlotNumber(work->wordSet, index, value, digits, 0, PM_LANG_HALF_WIDTH_DIGITS);
}

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void MB_UTIL_MSG_SetNumberZeroPad(MbMsgWork *work, int index, int value, int digits) { WORDSET_SetSlotNumber(work->wordSet, index, value, digits, 2, PM_LANG_HALF_WIDTH_DIGITS); }

void MB_UTIL_MSG_OpenYesNoTaskMenu(MbMsgWork *work, int layout)
{
    MbMenuEntry entries[2];
    MbMenuTemplate tmpl;
    entries[0].label = MSGDATA_AllocString(work->msgData, 18);
    entries[1].label = MSGDATA_AllocString(work->msgData, 19);
    entries[0].color = 0x39E3;
    entries[1].color = 0x39E3;
    entries[0].value = 0;
    entries[1].value = 0;
    tmpl.heapId = work->heapId;
    tmpl.entryCount = 2;
    tmpl.entries = entries;
    tmpl.reserved = 0;
    switch (layout) {
    case 0: tmpl.x = 24; tmpl.y = 6; break;
    case 1: tmpl.x = 24; tmpl.y = 12; break;
    case 2: tmpl.x = 24; tmpl.y = 18; break;
    }
    tmpl.width = 8;
    tmpl.height = 3;
    work->taskMenu = (struct TaskMenu *)APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&tmpl), work->taskMenuRes);
    STRBUF_Delete((struct Strbuf *)entries[0].label);
    STRBUF_Delete((struct Strbuf *)entries[1].label);
}

void MB_UTIL_MSG_CloseTaskMenu(MbMsgWork *work) { APP_TASKMENU_CloseMenu((struct TaskMenuWork *)work->taskMenu); work->taskMenu = 0; }

int MB_UTIL_MSG_GetTaskMenuResult(MbMsgWork *work) { if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)work->taskMenu) == 1) return APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)work->taskMenu) + 1; return 0; }

void MB_UTIL_MSG_OpenYesNoMenu(MbMsgWork *work, int unused)
{
    work->yesNoRect.frame = work->menuBgFrame;
    work->yesNoRect.x = 0x18;
    work->yesNoRect.y = 0xD;
    work->yesNoRect.width = 0xE;
    work->yesNoRect.height = 0;
    work->yesNoMenu = BMP_MENU_CreateYesNo((const struct WinDat *)&work->yesNoRect, 1, 0xD, 0, work->heapId);
}

void MB_UTIL_MSG_ClearYesNoMenu(MbMsgWork *work) { work->yesNoMenu = 0; }

int MB_UTIL_MSG_ProcessYesNoMenu(MbMsgWork *work)
{
    int r = BMP_MENU_ProcessYesNo(work->yesNoMenu);
    if (r == 0) {
        work->yesNoMenu = 0;
        return 1;
    }
    if (r == -2) {
        work->yesNoMenu = 0;
        return 2;
    }
    return 0;
}

void MB_UTIL_MSG_PrintStreamSystemMsg(MbMsgWork *work, int speed)
{
    struct MsgBank *sysMsg;
    sysMsg = MSGDATA_CreateFromArchive(0, 3, 158, work->heapId);
    if (work->stream) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->stream);
        work->stream = 0;
    }
    work->keyWaitFlag = 0;
    work->timeIconPending = 0;
    if (work->message) {
        STRBUF_Delete((struct Strbuf *)work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 15);
    work->message = MSGDATA_AllocString(sysMsg, 22);
    work->stream = PRINTSYS_PrintStream(work->window, 0, 0, work->message, work->font, speed, work->tcbl, 2, work->heapId, 15);
    BMP_MENUWORK_DrawWindow(work->window, 1, 1, 13);
    MSGDATA_Delete(sysMsg);
    if (work->cursorMode == 1)
        PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)work->keyCursorState, 6);
    else
        PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)work->keyCursorState, 4);
}

struct MsgBank *MB_UTIL_MSG_GetMsgData(MbMsgWork *work) { return work->msgData; }

struct WordSet *MB_UTIL_MSG_GetWordSet(MbMsgWork *work) { return work->wordSet; }

/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
struct GfFont *MB_UTIL_MSG_GetFont(MbMsgWork *work)
{
    return work->font;
}

/*
 * leaf: parent cleared original 12-byte Thumb tail getter. Full matched
 * 0201C6B4 returns only0/1 and reads its first input's pointer field10.
 */
int MB_UTIL_MSG_IsPrintQueFinished(MbMsgWork *work)
{
    return PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQue);
}

int MB_UTIL_MSG_IsStreamIdle(MbMsgWork *work)
{
    if (work->stream == 0) {
        return 1;
    }
    return 0;
}

void MB_UTIL_MSG_SetKeyWaitFlag(MbMsgWork *work, int flag)
{
    work->keyWaitFlag = flag;
    BMP_WIN_MakeScreen(work->window);
    BG_SYS_PushTile(work->bgFrame);
}

void MB_UTIL_MSG_SetTimeIconPending(MbMsgWork *work, int pending) { work->timeIconPending = pending; }
