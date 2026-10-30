/*
 * file:     gsync_message.c
 * unit:     yes
 * function: GSYNC_MESSAGE_DeleteButtonManager, GSYNC_MESSAGE_InitSystem, GSYNC_MESSAGE_UpdateSystem, GSYNC_MESSAGE_ExitSystem, GSYNC_MESSAGE_PrintStream, GSYNC_MESSAGE_PrintStreamId, GSYNC_MESSAGE_SetMonName, GSYNC_MESSAGE_UpdateStream, GSYNC_MESSAGE_ClearStream, GSYNC_MESSAGE_OpenYesNoMenu, GSYNC_MESSAGE_PrintId, GSYNC_MESSAGE_PrintInWindow, GSYNC_MESSAGE_PrintInSubWindow, GSYNC_MESSAGE_ClearWindow, GSYNC_MESSAGE_RestartTimeIcon, GSYNC_MESSAGE_PrintDefault
 * address:  0x021D54E0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_state.c by tools/splitfile.py.
 *
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Main 0x020310C4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   d_021DAA30 0x021DAA30 data a1
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PDWACC_MESSAGE_FormatNumber 0x021D97CC thumb ov123
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   PRINTSYS_CTRL_Init  0x02028470  thumb  arm9
 *   PRINTSYS_CTRL_Update  0x02028484  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 */
#include "gsync_message_types.h"
#include "../version.h"
#include "../sdk_ioreg.h"
#include "gsync_common_types.h"

struct Blk;
struct TimeIcon;

#include "../arm9/time_icon.h"
struct BmpWin;
struct TcblList;


#include "../arm9/bmp_win.h"

#ifdef __MWERKS__
#define MSGDATA_ReadString MSGDATA_ReadString_hdr
#endif
#include "../arm9/msgdata.h"
#ifdef __MWERKS__
#undef MSGDATA_ReadString
int MSGDATA_ReadString(struct MsgBank *, u32, struct Strbuf *);
#endif

#include "../arm9/gf_font.h"


#include "../arm9/bmp_menuwork.h"

#include "../arm9/arc_util.h"


struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"


#include "../arm9/printsys.h"


struct ButtonMan;

#include "../arm9/button_man.h"

#include "../arm9/bg_sys.h"
struct Strbuf;

#include "../arm9/strbuf.h"



#include "../arm9/gfl_heap_wrap.h"





struct TaskMenuRes;
struct TaskMenuInitWork;
struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"
struct TextPrinter;
struct KeyCursor;

#include "../arm9/app_keycursor.h"


#include "../arm9/msg_speed.h"





struct TcblSystem;

#include "../arm9/tcbl.h"

struct PrintQueue;

struct GFont;









struct WordSet;


#include "../arm9/wordset.h"




struct PrintStreamCtrl;


#include "../arm9/g2.h"

void GSYNC_MESSAGE_DeleteButtonManager(GsyncMessageWork *work);

GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank);

void GSYNC_MESSAGE_UpdateSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_ExitSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintStream(GsyncMessageWork *work, int instant);

void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon);

int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearStream(GsyncMessageWork *work);

struct TaskMenuWork *GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout);

int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_PrintInWindow(GsyncMessageWork *work, int top, int height);

void GSYNC_MESSAGE_PrintInSubWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value);

#include "pdwacc_message.h"

extern const char d_021DAA30[];

void GSYNC_MESSAGE_DeleteButtonManager(GsyncMessageWork *work)
{
    if (work->buttonMan) {
        BUTTON_MAN_Delete(work->buttonMan);
        work->buttonMan = 0;
    }
}

/* The Japanese cartridge prints the number in full width. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define GSYNC_MESSAGE_NUMBER_HALF_WIDTH 0
#else
#define GSYNC_MESSAGE_NUMBER_HALF_WIDTH 1
#endif

/* The Japanese cartridge builds the key cursor without the live flag. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define GSYNC_MESSAGE_KEYCURSOR_LIVE 0
#else
#define GSYNC_MESSAGE_KEYCURSOR_LIVE 1
#endif

GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank)
{
    GsyncMessageWork *work;
    work = (GsyncMessageWork *)GFL_HEAP_Alloc(heap, sizeof(GsyncMessageWork), 1, d_021DAA30, 0x96);
    work->heap = heap;
    work->wordSet = WORDSET_CreateDefault(work->heap);
    BMP_WIN_Init(work->heap);
    GF_FONT_InitTextColor();
    work->tcbl = TCBL_Create(work->heap, work->heap, 2, 0);
    work->printQue = (void *)PRINTSYS_QUE_Create((u32)(u32)work->heap);
    work->msgBuf = STRBUF_Create(400, work->heap);
    work->tmpBuf = STRBUF_Create(400, work->heap);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heap);
    work->msgData = MSGDATA_CreateFromArchive(0, 2, (u16)msgBank, work->heap);
    work->keyCursor = (void *)APP_KEYCURSOR_CreateDefault(15, GSYNC_MESSAGE_KEYCURSOR_LIVE, 1, work->heap);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, (struct GFont *)work->font, (struct PrintQueue *)work->printQue, work->heap);
    work->bg5Frame = BMP_MENUWORK_LoadFrameGfx(5, 12, 0, work->heap);
    work->bg6Frame = BMP_MENUWORK_LoadFrameGfx(6, 12, 0, work->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 352, 32, work->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 0, 352, 32, work->heap);
    return work;
}

void GSYNC_MESSAGE_UpdateSystem(GsyncMessageWork *work)
{
    TCBL_Main(work->tcbl);
    PRINTSYS_QUE_Main(work->printQue);
}

/*
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 */
void GSYNC_MESSAGE_ExitSystem(GsyncMessageWork *work)
{
    int windowIndex;
    u32 high;
    GSYNC_MESSAGE_ClearStream(work);
    if (work->mainWindow)
        BMP_WIN_Delete(work->mainWindow);
    if (work->subWindow)
        BMP_WIN_Delete(work->subWindow);
    for (windowIndex = 0; windowIndex < 12; windowIndex++) {
        if (work->windows[windowIndex])
            BMP_WIN_Delete(work->windows[windowIndex]);
    }
    high = work->bg5Frame >> 16;
    BG_SYS_FreeTileRun((int)5, (u16)(work->bg5Frame), (u16)high);
    high = work->bg6Frame >> 16;
    BG_SYS_FreeTileRun((int)6, (u16)(work->bg6Frame), (u16)high);
    GSYNC_MESSAGE_DeleteButtonManager(work);
    APP_KEYCURSOR_Delete((struct KeyCursor *)(work->keyCursor));
    WORDSET_Delete(work->wordSet);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->msgBuf);
    STRBUF_Delete(work->tmpBuf);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    TCBL_Destroy(work->tcbl);
    BMP_WIN_Exit();
    GFL_HEAP_Free(work);
}

/* Prints msgBuf in the bottom message window; instant skips the typewriter stream. */
void GSYNC_MESSAGE_PrintStream(GsyncMessageWork *work, int instant)
{
    void *win;
    if (!work->mainWindow)
        work->mainWindow = (void *)BMP_WIN_Create((int)5, (int)1, (u8)1, (int)30, 4, 11, 1);
    win = work->mainWindow;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (instant) {
        PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    } else {
        work->printStream = PRINTSYS_PrintStream(win, (int)0, (int)0, work->msgBuf, work->font, MSG_SPEED_GetWait(), work->tcbl, (int)2, work->heap, 15);
        PRINTSYS_CTRL_Init((PrintStreamCtrl *)work->streamWait, (int)6);
    }
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg5Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(5);
}

void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId)
{
    MSGDATA_ReadString(work->msgData, msgId, work->msgBuf);
    GSYNC_MESSAGE_PrintStream(work, 0);
}

/* Loads message msgId into tmpBuf, with a Pokemon name and a number (digits wide) registered in the word set. */
void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon)
{
    MSGDATA_ReadString(work->msgData, msgId, work->tmpBuf);
    WORDSET_SetSlotMonNickname(work->wordSet, 0, mon);
    WORDSET_SetSlotNumber(work->wordSet, 1, digits, 3, 1, GSYNC_MESSAGE_NUMBER_HALF_WIDTH);
    WORDSET_CopyTaggedText(work->wordSet, work->msgBuf, work->tmpBuf);
}

/* Returns 1 when the message stream has finished. */
int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work)
{
    if (work->printStream) {
        APP_KEYCURSOR_Update(work->keyCursor, work->printStream, work->mainWindow);
        if (!PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)work->streamWait, work->printStream))
            return 0;
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
    }
    return 1;
}

void GSYNC_MESSAGE_ClearStream(GsyncMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->printStream) {
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
    }
    if (work->mainWindow) {
        BMP_MENUWORK_DrawWindowBorder(work->mainWindow, 2);
        BMP_WIN_ClearScreen(work->mainWindow);
        BG_SYS_MarkTileDirty(5);
    }
}

struct TaskMenuWork *GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout)
{
    TaskMenuInitWork tmpl;
    struct TaskMenuWork *result;
    tmpl.heapId = work->heap;
    tmpl.itemNum = 2;
    tmpl.itemWork = work->menuItems;
    switch (layout) {
    case 0: tmpl.charPosX = 32; tmpl.charPosY = 12; tmpl.posType = 1; break;
    case 1: tmpl.charPosX = 32; tmpl.charPosY = 24; tmpl.posType = 1; break;
    }
    tmpl.width = 13;
    tmpl.height = 3;
    work->menuItems[0].str = STRBUF_Create(100, work->heap);
    MSGDATA_ReadString(work->msgData, 4, work->menuItems[0].str);
    work->menuItems[0].msgColor = 0x39e0;
    work->menuItems[1].str = STRBUF_Create(100, work->heap);
    MSGDATA_ReadString(work->msgData, 5, work->menuItems[1].str);
    work->menuItems[1].msgColor = 0x39e0;
    result = APP_TASKMENU_OpenMenu( &tmpl, work->taskMenuRes);
    STRBUF_Delete(work->menuItems[0].str);
    STRBUF_Delete(work->menuItems[1].str);
    G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR, 9, -8);
    return result;
}

int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId)
{
#ifdef __MWERKS__
    return MSGDATA_ReadString((struct MsgBank *)(work->msgData), msgId, work->msgBuf);
#else
    MSGDATA_ReadString((struct MsgBank *)(work->msgData), msgId, work->msgBuf);
    return 0; /* the DS returns what r0 holds after MSGDATA_ReadString */
#endif
}

/* Prints msgBuf in a sub-screen window at row top, height rows high. */
void GSYNC_MESSAGE_PrintInWindow(GsyncMessageWork *work, int top, int height)
{
    void *win;
    if (work->subWindow)
        BMP_WIN_Delete(work->subWindow);
    win = (void *)BMP_WIN_Create((int)6, (int)1, (u8)top, (int)30, height, 11, 1);
    work->subWindow = win;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(6);
}

void GSYNC_MESSAGE_PrintInSubWindow(GsyncMessageWork *work)
{
    void *win;
    if (work->subWindow)
        BMP_WIN_Delete(work->subWindow);
    win = (void *)BMP_WIN_Create(6, 1, 9, 30, 6, 11, 1);
    work->subWindow = win;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(6);
}

void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work)
{
    BMP_MENUWORK_DrawWindowBorder(work->subWindow, 2);
    BMP_WIN_ClearScreen(work->subWindow);
    BG_SYS_MarkTileDirty(6);
}

void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode((struct TcblList *)work->tcbl, work->mainWindow, 15, 16, work->heap);
}

void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value)
{
    PDWACC_MESSAGE_FormatNumber(value, work->msgBuf);
}
