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
 *   func_02045CAC 0x02045CAC arm
 *   func_0201DD68  0x0201DD68  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   func_02030734 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Main 0x020310C4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_0207D658 0x0207D658 arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GF_STANDARD_SetupCalc 0x0203F1FC arm
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
 *   GF_FONT_Create_EC64  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 */
#include "pdwacc_message_types.h"

typedef unsigned long long u64;

typedef struct { u16 a[32]; } Table_021D8A9C;

extern void TIME_ICON_Delete(u8 *);

extern u8 *TIME_ICON_CreateNode(void *tcbl, void *window, u8, u8, u16 heapId);

extern u32 BMP_WIN_Delete(void *d);

extern int func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void func_0201DD68(void);

extern void BMP_WIN_ClearScreen(void *d);

extern void func_0201F7A8(void *desc, u32 kind);

extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);

extern void *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(void *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

extern void PRINTSYS_Print(void *x, short y, short z, void *s, void *w);

extern void BMP_WIN_TransferChars(void *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BUTTON_MAN_Delete(void *p);

extern void func_02041B6C(u32 bit);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 func_020307B0(void *p);

extern void *func_0201F5DC(void *, u32, u32, u32);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern u32 MSGDATA_Delete(void *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void *APP_TASKMENU_OpenMenu(TaskMenuTmpl *tmpl, void *res);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void PRINTSYS_PrintStreamReleasePause(void *);

extern signed char MSG_SPEED_GetWait(void);

extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int textSpeed, void *tcbl, int, u16 heapId, int);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

extern void BMP_WIN_Init(u16);

extern void func_0201DD60(void);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void *PRINTSYS_QUE_Create(u32 heapId);

extern void *APP_TASKMENU_RES_Create(u16 a0, u16 a1, void *font, void *printQue, u16 heap);

extern void TCBL_Main(struct Tcbl *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void BMP_WIN_Exit(void);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern void func_0207D658(u32 addr, int plane, int brightness);

extern u32 KEY_GetTrg(void);

extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

extern void STRBUF_Clear(struct U16Vec *vec);

extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);

extern void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);

extern const char d_021DABA8[];

extern const Table_021D8A9C d_021DA868;

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
    work = func_02030734(heap, 0xb4, 1, d_021DABA8, 0x9b);
    work->heap = heap;
    BMP_WIN_Init(work->heap);
    func_0201DD60();
    work->tcbl = TCBL_Create(work->heap, work->heap, 2, 0);
    work->printQue = PRINTSYS_QUE_Create(work->heap);
    work->msgBuf = STRBUF_Create(400, work->heap);
    work->tmpBuf = STRBUF_Create(400, work->heap);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heap);
    work->msgData = func_02045B38(0, 2, (u16)bank, work->heap);
    work->wordSet = GF_FONT_Create_EC64(work->heap);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, work->font, work->printQue, work->heap);
    work->bg1Frame = (u32)func_0201F5DC((void *)1, 12, 0, work->heap);
    work->bg5Frame = (u32)func_0201F5DC((void *)5, 12, 0, work->heap);
    work->bg6Frame = (u32)func_0201F5DC((void *)6, 12, 0, work->heap);
    func_02049B40(23, 5, 4, 352, 32, work->heap);
    func_02049B40(23, 5, 0, 352, 32, work->heap);
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
    int i;
    BG_SYS_DeleteHalf(1, (u16)(work->bg1Frame), (u16)(work->bg1Frame >> 16));
    frameHi = work->bg5Frame >> 16;
    BG_SYS_DeleteHalf(5, (u16)(work->bg5Frame), (u16)frameHi);
    frameHi = work->bg6Frame >> 16;
    BG_SYS_DeleteHalf(6, (u16)(work->bg6Frame), (u16)frameHi);
    PDWACC_MESSAGE_DeleteButtonManager(work);
    func_0201DD68();
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->msgBuf);
    STRBUF_Delete(work->tmpBuf);
    WORDSET_DeleteStrbufED04(work->wordSet);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    if (work->printStream) PRINTSYS_PrintStreamDelete(work->printStream);
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->codeWin) BMP_WIN_Delete(work->codeWin);
    if (work->labelWin) BMP_WIN_Delete(work->labelWin);
    if (work->mainWin) BMP_WIN_Delete(work->mainWin);
    if (work->subWin) BMP_WIN_Delete(work->subWin);
    for (i = 0; i < 12; i++) if (work->windows[i]) BMP_WIN_Delete(work->windows[i]);
    TCBL_Destroy(work->tcbl);
    BMP_WIN_Exit();
    func_020307B0(work);
}

/* Prints message msgId into the BG 5 message window, one character at a time. */
void PDWACC_MESSAGE_PrintStream(PdwaccMessageWork *work, int msgId)
{
    void *win;
    func_02045CAC(work->msgData, msgId, work->msgBuf);
    if (!work->mainWin) work->mainWin = BMP_WIN_Create(5, 1, 3, 30, 4, 11, 1);
    win = work->mainWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    work->printStream = PRINTSYS_PrintStream(win, 0, 0, work->msgBuf, work->font, MSG_SPEED_GetWait(), work->tcbl, 2, work->heap, 15);
    func_0201F73C(win, 1, (u16)(work->bg5Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(5);
}

/*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 */
void PDWACC_MESSAGE_RestartTimeIcon(PdwaccMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode(work->tcbl, work->mainWin, 15, 16, work->heap);
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
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->mainWin) {
        func_0201F7A8(work->mainWin, 2);
        BMP_WIN_ClearScreen(work->mainWin);
        func_02041B6C(5);
        BMP_WIN_Delete(work->mainWin);
        work->mainWin = 0;
    }
}

/* Opens the Yes/No task menu; layout 0 and 1 place it at different heights. Returns the menu handle. */
void *PDWACC_MESSAGE_OpenYesNoMenu(PdwaccMessageWork *work, int layout)
{
    TaskMenuTmpl tmpl;
    void *result;
    tmpl.heapId = work->heap;
    tmpl.itemNum = 2;
    tmpl.items = work->menuItems;
    switch (layout) {
    case 0: tmpl.charPosX = 32; tmpl.charPosY = 14; tmpl.posType = 1; break;
    case 1: tmpl.charPosX = 32; tmpl.charPosY = 24; tmpl.posType = 1; break;
    }
    tmpl.width = 13;
    tmpl.height = 3;
    work->menuItems[0].text = STRBUF_Create(100, work->heap);
    func_02045CAC(work->msgData, 4, work->menuItems[0].text);
    work->menuItems[0].color = 0x39e0;
    work->menuItems[1].text = STRBUF_Create(100, work->heap);
    func_02045CAC(work->msgData, 5, work->menuItems[1].text);
    work->menuItems[1].color = 0x39e0;
    result = APP_TASKMENU_OpenMenu(&tmpl, work->taskMenuRes);
    STRBUF_Delete(work->menuItems[0].text);
    STRBUF_Delete(work->menuItems[1].text);
    func_0207D658(0x04001050, 17, -8);
    return result;
}

/* Prints message msgId into the BG 6 window. */
void PDWACC_MESSAGE_PrintInWindow(PdwaccMessageWork *work, int msgId)
{
    void *win;
    func_02045CAC(work->msgData, msgId, work->msgBuf);
    if (!work->subWin) work->subWin = BMP_WIN_Create(6, 1, 3, 30, 16, 11, 1);
    win = work->subWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    func_0201F73C(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(6);
}

void PDWACC_MESSAGE_ClearWindow(PdwaccMessageWork *work)
{
    func_0201F7A8(work->subWin, 2);
    BMP_WIN_ClearScreen(work->subWin);
    func_02041B6C(6);
}

/* Writes the 10 character account code of value into buf: 5 bits per character from the value and its checksum. */
void PDWACC_MESSAGE_FormatNumber(int value, void *buf)
{
    Table_021D8A9C table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 bits;
    int i;
    table = d_021DA868;
    copy = value;
    checksum = GF_STANDARD_SetupCalc((const u8 *)(&copy), 4);
    arg = d_021DA864;
    bits = (u64)(long long)copy + ((u64)checksum << 32);
    STRBUF_Clear(buf);
    for (i = 0; i < 10; i++) {
        u16 index;
        index = (u16)(bits & 31);
        bits >>= 5;
        STRBUF_AppendChar(buf, table.a[index]);
        func_0201D60C(buf, 189, 4, 1, &arg);
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
    func_0201F73C(win, 1, (u16)(work->bg1Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    if (!work->labelWin) work->labelWin = BMP_WIN_Create(1, 3, 3, 22, 2, 11, 1);
    win = work->labelWin;
    GF_FONT_SetTextColor(1, 2, 0);
    func_02045CAC(work->msgData, 10, work->msgBuf);
    PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(5);
}

void PDWACC_MESSAGE_DeleteNumberWindows(PdwaccMessageWork *work)
{
    if (work->codeWin) {
        func_0201F7A8(work->codeWin, 2);
        BMP_WIN_ClearScreen(work->codeWin);
        func_0201F7A8(work->labelWin, 2);
        BMP_WIN_ClearScreen(work->labelWin);
        BMP_WIN_Delete(work->codeWin);
        BMP_WIN_Delete(work->labelWin);
        func_02041B6C(5);
        work->codeWin = 0;
        work->labelWin = 0;
    }
}
