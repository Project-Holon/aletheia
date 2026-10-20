/*
 * file:     pdwacc_message.c
 * unit:     yes
 * function: PDWACC_MESSAGE_DeleteButtonManager, PDWACC_MESSAGE_InitSystem, PDWACC_MESSAGE_UpdateSystem, PDWACC_MESSAGE_ExitSystem, PDWACC_MESSAGE_PrintStream, PDWACC_MESSAGE_RestartTimeIcon, PDWACC_MESSAGE_UpdateStream, PDWACC_MESSAGE_ClearStream, PDWACC_MESSAGE_OpenYesNoMenu, PDWACC_MESSAGE_PrintInWindow, PDWACC_MESSAGE_ClearWindow, PDWACC_MESSAGE_FormatNumber, PDWACC_MESSAGE_PrintNumberWindows, PDWACC_MESSAGE_DeleteNumberWindows
 * address:  0x021D92B8
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
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Main 0x020310C4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 *   d_021DABA8 0x021DABA8 data ov123 a1
 *   STRBUF_Clear 0x0204581C arm
 *   STRBUF_AppendChar 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   PRINTSYS_AppendTag  0x0201D60C  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 */
#include "pdwacc_message_types.h"

#include "../types.h"

/* 32-entry lookup from a 5-bit account code to its character glyph. */
typedef struct { u16 chars[32]; } AccountCodeCharTable;
struct TimeIcon;

#include "../arm9/time_icon.h"
struct BmpWin;
struct TcblList;


#include "../arm9/bmp_win.h"
struct Strbuf;
struct MsgBank;

#include "../arm9/msgdata.h"

#include "../arm9/gf_font.h"


#include "../arm9/bmp_menuwork.h"

#include "../arm9/arc_util.h"



typedef short s16_p07;
#include "../arm9/bmp.h"

struct GfFont;
struct Bmp;

#include "../arm9/printsys.h"


struct ButtonMan;

#include "../arm9/button_man.h"

#include "../arm9/bg_sys.h"

#include "../arm9/strbuf.h"



#include "../arm9/gfl_heap_wrap.h"





struct TaskMenuRes;
struct TaskMenuInitWork;
struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"
struct TextPrinter;




#include "../arm9/msg_speed.h"





struct TcblSystem;

#include "../arm9/tcbl.h"
struct PrintQueue;

struct GFont;








struct WordSet;


#include "../arm9/wordset.h"

#include "../arm9/g2.h"

#include "../arm9/key.h"

#include "../arm9/gf_standard.h"




extern const char d_021DABA8[];

extern const AccountCodeCharTable d_021DA868;

extern const u16 d_021DA864;

void PDWACC_MESSAGE_DeleteButtonManager(PdwaccMessageWork *work);
PdwaccMessageWork *PDWACC_MESSAGE_InitSystem(u32 heap, u32 bank);
void PDWACC_MESSAGE_UpdateSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ExitSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_PrintStream(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_RestartTimeIcon(PdwaccMessageWork *work);
int PDWACC_MESSAGE_UpdateStream(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ClearStream(PdwaccMessageWork *work);
void *PDWACC_MESSAGE_OpenYesNoMenu(PdwaccMessageWork *work, int layout);
void PDWACC_MESSAGE_PrintInWindow(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_ClearWindow(PdwaccMessageWork *work);
void PDWACC_MESSAGE_FormatNumber(int value, void *buf);
void PDWACC_MESSAGE_PrintNumberWindows(PdwaccMessageWork *work, int value, int unused);
void PDWACC_MESSAGE_DeleteNumberWindows(PdwaccMessageWork *work);

void PDWACC_MESSAGE_DeleteButtonManager(PdwaccMessageWork *work)
{
    if (work->buttonMan) {
        BUTTON_MAN_Delete(work->buttonMan);
        work->buttonMan = 0;
    }
}

PdwaccMessageWork *PDWACC_MESSAGE_InitSystem(u32 heap, u32 bank)
{
    PdwaccMessageWork *work;
    work = GFL_HEAP_Alloc(heap, 0xb4, 1, d_021DABA8, 0x9b);
    work->heap = heap;
    BMP_WIN_Init(work->heap);
    GF_FONT_InitTextColor();
    work->tcbl = TCBL_Create(work->heap, work->heap, 2, 0);
    work->printQue = PRINTSYS_QUE_Create(work->heap);
    work->msgBuf = STRBUF_Create(400, work->heap);
    work->tmpBuf = STRBUF_Create(400, work->heap);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heap);
    work->msgData = MSGDATA_CreateFromArchive(0, 2, (u16)bank, work->heap);
    work->wordSet = WORDSET_CreateDefault(work->heap);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, work->font, work->printQue, work->heap);
    work->bg1Frame = (u32)(u32)BMP_MENUWORK_LoadFrameGfx((u32)1, 12, 0, work->heap);
    work->bg5Frame = (u32)(u32)BMP_MENUWORK_LoadFrameGfx((u32)5, 12, 0, work->heap);
    work->bg6Frame = (u32)(u32)BMP_MENUWORK_LoadFrameGfx((u32)6, 12, 0, work->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 352, 32, work->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 0, 352, 32, work->heap);
    return work;
}

void PDWACC_MESSAGE_UpdateSystem(PdwaccMessageWork *work)
{
    TCBL_Main(work->tcbl);
    PRINTSYS_QUE_Main(work->printQue);
}

void PDWACC_MESSAGE_ExitSystem(PdwaccMessageWork *work)
{
    u32 frameHi;
    int windowIndex;
    BG_SYS_FreeTileRun(1, (u16)(work->bg1Frame), (u16)(work->bg1Frame >> 16));
    frameHi = work->bg5Frame >> 16;
    BG_SYS_FreeTileRun(5, (u16)(work->bg5Frame), (u16)frameHi);
    frameHi = work->bg6Frame >> 16;
    BG_SYS_FreeTileRun(6, (u16)(work->bg6Frame), (u16)frameHi);
    PDWACC_MESSAGE_DeleteButtonManager(work);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->msgBuf);
    STRBUF_Delete(work->tmpBuf);
    WORDSET_Delete(work->wordSet);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    if (work->printStream) PRINTSYS_PrintStreamDelete(work->printStream);
    if (work->timeIcon) {
        TIME_ICON_Delete((struct TimeIcon *)work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->codeWin) BMP_WIN_Delete(work->codeWin);
    if (work->labelWin) BMP_WIN_Delete(work->labelWin);
    if (work->mainWin) BMP_WIN_Delete(work->mainWin);
    if (work->subWin) BMP_WIN_Delete(work->subWin);
    for (windowIndex = 0; windowIndex < 12; windowIndex++) if (work->windows[windowIndex]) BMP_WIN_Delete(work->windows[windowIndex]);
    TCBL_Destroy(work->tcbl);
    BMP_WIN_Exit();
    GFL_HEAP_Free(work);
}

/* Prints message msgId into the BG 5 message window, one character at a time. */
void PDWACC_MESSAGE_PrintStream(PdwaccMessageWork *work, int msgId)
{
    void *win;
    MSGDATA_ReadString(work->msgData, msgId, work->msgBuf);
    if (!work->mainWin) work->mainWin = BMP_WIN_Create(5, 1, 3, 30, 4, 11, 1);
    win = work->mainWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    work->printStream = PRINTSYS_PrintStream(win, 0, 0, work->msgBuf, work->font, MSG_SPEED_GetWait(), work->tcbl, 2, work->heap, 15);
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg5Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(5);
}

/*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 */
void PDWACC_MESSAGE_RestartTimeIcon(PdwaccMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete((struct TimeIcon *)work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = (u8 *)TIME_ICON_CreateNode(work->tcbl, work->mainWin, 15, 16, work->heap);
}

/* Runs the message print stream; returns 1 when no stream is active any more. */
int PDWACC_MESSAGE_UpdateStream(PdwaccMessageWork *work)
{
    if (work->printStream) {
        switch (PRINTSYS_PrintStreamGetState(work->printStream)) {
        case 2:
            PRINTSYS_PrintStreamDelete(work->printStream);
            work->printStream = 0;
            break;
        case 1:
            if (KEY_GetTrg() == 1) PRINTSYS_PrintStreamReleasePause(work->printStream);
            break;
        }
        return 0;
    }
    return 1;
}

void PDWACC_MESSAGE_ClearStream(PdwaccMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete((struct TimeIcon *)work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->mainWin) {
        BMP_MENUWORK_DrawWindowBorder(work->mainWin, 2);
        BMP_WIN_ClearScreen(work->mainWin);
        BG_SYS_MarkTileDirty(5);
        BMP_WIN_Delete(work->mainWin);
        work->mainWin = 0;
    }
}

/* Opens the Yes/No task menu; layout 0 and 1 place it at different heights. Returns the menu handle. */
void *PDWACC_MESSAGE_OpenYesNoMenu(PdwaccMessageWork *work, int layout)
{
    TaskMenuInitWork tmpl;
    void *result;
    tmpl.heapId = work->heap;
    tmpl.itemNum = 2;
    tmpl.itemWork = work->menuItems;
    switch (layout) {
    case 0: tmpl.charPosX = 32; tmpl.charPosY = 14; tmpl.posType = 1; break;
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
    result = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&tmpl), work->taskMenuRes);
    STRBUF_Delete(work->menuItems[0].str);
    STRBUF_Delete(work->menuItems[1].str);
    G2x_SetBlendBrightness_(0x04001050, 17, -8);
    return result;
}

/* Prints message msgId into the BG 6 window. */
void PDWACC_MESSAGE_PrintInWindow(PdwaccMessageWork *work, int msgId)
{
    void *win;
    MSGDATA_ReadString(work->msgData, msgId, work->msgBuf);
    if (!work->subWin) work->subWin = BMP_WIN_Create(6, 1, 3, 30, 16, 11, 1);
    win = work->subWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(6);
}

void PDWACC_MESSAGE_ClearWindow(PdwaccMessageWork *work)
{
    BMP_MENUWORK_DrawWindowBorder(work->subWin, 2);
    BMP_WIN_ClearScreen(work->subWin);
    BG_SYS_MarkTileDirty(6);
}

/* Writes the 10 character account code of value into buf: 5 bits per character from the value and its checksum. */
void PDWACC_MESSAGE_FormatNumber(int value, void *buf)
{
    AccountCodeCharTable table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 bits;
    int charIndex;
    table = d_021DA868;
    copy = value;
    checksum = GF_STANDARD_CalcCrc16((const u8 *)(&copy), 4);
    arg = d_021DA864;
    bits = (u64)(long long)copy + ((u64)checksum << 32);
    STRBUF_Clear(buf);
    for (charIndex = 0; charIndex < 10; charIndex++) {
        u16 index;
        index = (u16)(bits & 31);
        bits >>= 5;
        STRBUF_AppendChar(buf, table.chars[index]);
        PRINTSYS_AppendTag(buf, 189, 4, 1, &arg);
    }
}

/* Shows the account code of value in the BG 1 code window with its label below. */
void PDWACC_MESSAGE_PrintNumberWindows(PdwaccMessageWork *work, int value, int unused)
{
    void *win;
    PDWACC_MESSAGE_FormatNumber(value, work->msgBuf);
    if (!work->codeWin) work->codeWin = BMP_WIN_Create(1, 1, 8, 30, 4, 11, 1);
    win = work->codeWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bg1Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    if (!work->labelWin) work->labelWin = BMP_WIN_Create(1, 3, 3, 22, 2, 11, 1);
    win = work->labelWin;
    GF_FONT_SetTextColor(1, 2, 0);
    MSGDATA_ReadString(work->msgData, 10, work->msgBuf);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(5);
}

void PDWACC_MESSAGE_DeleteNumberWindows(PdwaccMessageWork *work)
{
    if (work->codeWin) {
        BMP_MENUWORK_DrawWindowBorder(work->codeWin, 2);
        BMP_WIN_ClearScreen(work->codeWin);
        BMP_MENUWORK_DrawWindowBorder(work->labelWin, 2);
        BMP_WIN_ClearScreen(work->labelWin);
        BMP_WIN_Delete(work->codeWin);
        BMP_WIN_Delete(work->labelWin);
        BG_SYS_MarkTileDirty(5);
        work->codeWin = 0;
        work->labelWin = 0;
    }
}
