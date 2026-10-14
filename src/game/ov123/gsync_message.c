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
 *   func_0203FB44 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   func_02030734 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Main 0x020310C4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   d_021DAA30 0x021DAA30 data a1
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0207D658 0x0207D658 arm
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PDWACC_MESSAGE_FormatNumber 0x021D97CC thumb ov123
 */
#include "gsync_message_types.h"
#include "gsync_common_types.h"

struct Blk;

extern void TIME_ICON_Delete(u8 *);

extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);

extern u32 BMP_WIN_Delete(void *d);

extern int func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void func_0201DD68(void);

extern void BMP_WIN_ClearScreen(void *d);

extern void func_0201F7A8(void *desc, u32 kind);

extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

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

extern void func_0203FB44(u32 layer, u32 offset, u32 size);

extern u32 MSGDATA_Delete(void *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void STRBUF_Delete(struct U16Vec *vec);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern signed char func_02012FFC(void);

extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, void *, void *, int, u16, int);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

extern void BMP_WIN_Init(u16);

extern void func_0201DD60(void);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern u32 func_02028590(u32,u32,u32,u32);

extern u32 PRINTSYS_QUE_Create(void *);

extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

extern void TCBL_Main(struct Tcbl *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern int APP_KEYCURSOR_Delete(int a0);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void BMP_WIN_Exit(void);

extern struct WordSet *func_0201EC64(u32 heap);

extern u32 func_0201ED04(struct WordSet *p);

extern void func_02028470(u8 *p, u32 v);

extern void func_0201EEF4(struct WordSet *,u32,void *);

extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);

extern void func_0201F250(struct WordSet *,void *,void *);

extern s32 func_02028484(struct Blk *blk, void *h);

extern void func_0207D658(u32 addr, int plane, int brightness);

void GSYNC_MESSAGE_DeleteButtonManager(GsyncMessageWork *work);

GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank);

void GSYNC_MESSAGE_UpdateSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_ExitSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintStream(GsyncMessageWork *work, int instant);

void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon);

int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearStream(GsyncMessageWork *work);

int GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout);

int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_PrintInWindow(GsyncMessageWork *work, int top, int height);

void GSYNC_MESSAGE_PrintInSubWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value);

void PDWACC_MESSAGE_FormatNumber(int value, void *p);

extern const char d_021DAA30[];

void GSYNC_MESSAGE_DeleteButtonManager(GsyncMessageWork *work)
{
    if (work->buttonMan) {
        BUTTON_MAN_Delete(work->buttonMan);
        work->buttonMan = 0;
    }
}

GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank)
{
    GsyncMessageWork *work;
    work = (GsyncMessageWork *)func_02030734(heap, sizeof(GsyncMessageWork), 1, d_021DAA30, 0x96);
    work->heap = heap;
    work->wordSet = func_0201EC64(work->heap);
    BMP_WIN_Init(work->heap);
    func_0201DD60();
    work->tcbl = TCBL_Create(work->heap, work->heap, 2, 0);
    work->printQue = (void *)PRINTSYS_QUE_Create((void *)(u32)work->heap);
    work->msgBuf = STRBUF_Create(400, work->heap);
    work->tmpBuf = STRBUF_Create(400, work->heap);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heap);
    work->msgData = func_02045B38(0, 2, (u16)msgBank, work->heap);
    work->keyCursor = (void *)func_02028590(15, 1, 1, work->heap);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, (u32)work->font, (u32)work->printQue, work->heap);
    work->bg5Frame = (u32)func_0201F5DC((void *)5, 12, 0, work->heap);
    work->bg6Frame = (u32)func_0201F5DC((void *)6, 12, 0, work->heap);
    func_02049B40(23, 5, 4, 352, 32, work->heap);
    func_02049B40(23, 5, 0, 352, 32, work->heap);
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
    int i;
    u32 high;
    GSYNC_MESSAGE_ClearStream(work);
    if (work->mainWindow)
        BMP_WIN_Delete(work->mainWindow);
    if (work->subWindow)
        BMP_WIN_Delete(work->subWindow);
    for (i = 0; i < 12; i++) {
        if (work->windows[i])
            BMP_WIN_Delete(work->windows[i]);
    }
    high = work->bg5Frame >> 16;
    func_0203FB44((int)5, (u16)(work->bg5Frame), (u16)high);
    high = work->bg6Frame >> 16;
    func_0203FB44((int)6, (u16)(work->bg6Frame), (u16)high);
    GSYNC_MESSAGE_DeleteButtonManager(work);
    APP_KEYCURSOR_Delete((int)(work->keyCursor));
    func_0201ED04(work->wordSet);
    func_0201DD68();
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->msgBuf);
    STRBUF_Delete(work->tmpBuf);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    TCBL_Destroy(work->tcbl);
    BMP_WIN_Exit();
    func_020307B0(work);
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
        work->printStream = PRINTSYS_PrintStream(win, (int)0, (int)0, work->msgBuf, work->font, (void *)((int)func_02012FFC()), work->tcbl, (int)2, work->heap, 15);
        func_02028470(work->streamWait, (int)6);
    }
    func_0201F73C(win, 1, (u16)(work->bg5Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(5);
}

void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId)
{
    func_02045CAC(work->msgData, msgId, work->msgBuf);
    GSYNC_MESSAGE_PrintStream(work, 0);
}

/* Loads message msgId into tmpBuf, with a Pokemon name and a number (digits wide) registered in the word set. */
void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon)
{
    func_02045CAC(work->msgData, msgId, work->tmpBuf);
    func_0201EEF4(work->wordSet, 0, mon);
    func_0201EFA4(work->wordSet, 1, digits, 3, 1, 1);
    func_0201F250(work->wordSet, work->msgBuf, work->tmpBuf);
}

/* Returns 1 when the message stream has finished. */
int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work)
{
    if (work->printStream) {
        APP_KEYCURSOR_Update(work->keyCursor, work->printStream, work->mainWindow);
        if (!func_02028484((struct Blk *)work->streamWait, work->printStream))
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
        func_0201F7A8(work->mainWindow, 2);
        BMP_WIN_ClearScreen(work->mainWindow);
        func_02041B6C(5);
    }
}

int GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout)
{
    TaskMenuTmpl tmpl;
    int result;
    tmpl.heapId = work->heap;
    tmpl.itemNum = 2;
    tmpl.items = work->menuItems;
    switch (layout) {
    case 0: tmpl.charPosX = 32; tmpl.charPosY = 12; tmpl.posType = 1; break;
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
    result = (int)APP_TASKMENU_OpenMenu(&tmpl, work->taskMenuRes);
    STRBUF_Delete(work->menuItems[0].text);
    STRBUF_Delete(work->menuItems[1].text);
    func_0207D658(0x04001050, 9, -8);
    return result;
}

int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId)
{
    return func_02045CAC((struct MsgBank *)(work->msgData), msgId, work->msgBuf);
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
    func_0201F73C(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(6);
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
    func_0201F73C(win, 1, (u16)(work->bg6Frame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(6);
}

void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work)
{
    func_0201F7A8(work->subWindow, 2);
    BMP_WIN_ClearScreen(work->subWindow);
    func_02041B6C(6);
}

void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode((u32)work->tcbl, work->mainWindow, 15, 16, work->heap);
}

void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value)
{
    PDWACC_MESSAGE_FormatNumber(value, work->msgBuf);
}
