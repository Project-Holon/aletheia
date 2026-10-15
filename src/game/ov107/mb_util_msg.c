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
 *   func_02030734 0x02030734 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02034AC4 0x02034AC4 arm
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
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   TCBL_Main 0x020310C4 arm
 *   func_02028484 0x02028484 thumb
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
 *   func_020409B4  0x020409B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   TALKMSGWIN_DrawWindowFrame  0x02194A24  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02028470  0x02028470  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   TALKMSGWIN_ClearWindowFrame  0x02194A34  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;

struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct TaskMenu;
struct TaskMenuRes;
struct StrBuf;
struct WordSet;
struct BmpWin;
struct PrintStream;
struct TalkMsgWin;
struct TimeIcon;

/* Parameters of the talk window (TALKMSGWIN_Create). */
typedef struct MbTalkWinParam {
    u16 heapId;
    u32 reserved;
    u32 font;
    u16 bgPalette;
    u32 bgFrame;
    u8 x;
    u8 y;
} MbTalkWinParam;

/* One entry of the yes/no task menu template. */
typedef struct MbMenuEntry {
    struct StrBuf *label;
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
    struct PrintStream *stream;
    struct MsgBank *msgData;
    struct StrBuf *message;
    struct WordSet *wordSet;
    u8 keyCursorState[8];
    struct PrintSys *printQue;
    int printQueued;
    int keyWaitFlag;
    struct TaskMenu *taskMenu;
    struct TaskMenuRes *taskMenuRes;
    u32 keyCursor;
    u8 pad48[8];
    void *yesNoMenu;
    struct TalkMsgWin *talkWin;
    int timeIconPending;
    struct TimeIcon *timeIcon;
} MbMsgWork;

/* Yes/no window use of the same record: the rectangle sits at 0x48. */
typedef struct MbYesNoMsgWork {
    u16 heapId;
    u8 bgFrame;
    u8 menuBgFrame;
    u8 pad04[0x44];
    MbWinRect rect;
    u8 pad4E[2];
    void *yesNoMenu;
} MbYesNoMsgWork;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct PrintSys *PRINTSYS_QUE_Create(void *heapId);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 a0, u16 a1, struct GfFont *font, struct PrintSys *que, u16 heap);
extern unsigned func_02028590(int, int, int, unsigned);
extern int func_02034AC4(int);
extern struct TalkMsgWin *TALKMSGWIN_Create(u16 *param);
extern void TALKMSGWIN_Delete(struct TalkMsgWin *win);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void BMP_MENU_DeleteYesNo(void *menu);
extern void TIME_ICON_Delete(struct TimeIcon *icon);
extern int APP_KEYCURSOR_Delete(u32 cursor);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuRes *res);
extern void PRINTSYS_QUE_Delete(struct PrintSys *que);
extern void PRINTSYS_PrintStreamDelete(struct PrintStream *stream);
extern void STRBUF_Delete(struct StrBuf *buf);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
extern unsigned int BMP_WIN_Delete(struct BmpWin *win);
extern unsigned int GF_FONT_Delete(struct GfFont *font);
extern void TCBL_Destroy(struct Tcbl *tcbl);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern void TCBL_Main(struct Tcbl *tcbl);
extern void APP_KEYCURSOR_Update(u32 cursor, struct PrintStream *stream, struct BmpWin *win);
extern void BMP_WIN_TransferChars(struct BmpWin *);
extern void APP_TASKMENU_UpdateMenu(struct TaskMenu *);
extern int func_02028484(u8 *cursorState, struct PrintStream *stream);
extern unsigned int PRINTSYS_QUE_Main(struct PrintSys *ps);
extern unsigned int PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern struct TimeIcon *TIME_ICON_CreateNode(struct Tcbl *tcbl, struct BmpWin *win, u8 c, u8 d, u16 e);
u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void *BMP_WIN_GetBmp(struct BmpWin *p);
void BMP_Clear(void *buf, u8 value);
void BMP_WIN_MakeScreen(struct BmpWin *win);
void func_020409B4(u32 index);
struct StrBuf *func_02045EC0(struct MsgBank *bank, u32 index);
struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
void func_0201F250(struct WordSet *ws, struct StrBuf *dst, struct StrBuf *src);
int TALKMSGWIN_DrawWindowFrame(struct TalkMsgWin *, struct BmpWin *, int);
void func_0201F73C(struct BmpWin *, int, int, int);
struct PrintStream *PRINTSYS_PrintStream(struct BmpWin *, int, int, struct StrBuf *, struct GfFont *, int, struct Tcbl *, int, int, int);
void func_02028470(u8 *cursorState, u32 v);
void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, struct StrBuf *s, u32 e);
int TALKMSGWIN_ClearWindowFrame(struct TalkMsgWin *, struct BmpWin *);
void func_0201F7A8(struct BmpWin *win, u32 kind);
struct WordSet *GF_FONT_Create_EC64(u32 heap);
u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(MbMenuTemplate *tmpl, struct TaskMenuRes *res);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern unsigned char APP_TASKMENU_GetCursorPos(struct TaskMenu *);
void *BMP_MENU_CreateYesNo(MbWinRect *rect, int base, int pal, int pos, int heap);
u32 BMP_MENU_ProcessYesNo(void *menu);
extern const char d_021F6E38[];
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
void MB_UTIL_MSG_OpenYesNoMenu(MbYesNoMsgWork *work);
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
 * 2026-10-05 (wave P8 W4): 0x15 in the pool is an overlay id (ov021_id, passed to func_02034AC4). The sixth parameter is copied to an int local cursor first (stored to cursorMode, later passed to func_02028590); without the local the copy is propagated and the frame is 4 bytes short. EXACT in c99 and c.
 */
MbMsgWork *MB_UTIL_MSG_Create(u16 heapId, u32 bgFrame, u32 menuBgFrame, u32 msgFile, u32 useTalkWin, u32 cursorMode)
{
    MbMsgWork *w;
    MbTalkWinParam talk;
    int cursor;

    w = (MbMsgWork *)func_02030734(heapId, 0x60, 1, d_021F6E38, 0x66);
    w->heapId = heapId;
    w->bgFrame = bgFrame;
    w->menuBgFrame = menuBgFrame;
    cursor = cursorMode;
    w->cursorMode = cursor;
    w->window = 0;
    w->font = GF_FONT_Create(0x17, 0, 0, 0, w->heapId);
    w->msgData = func_02045B38(0, 2, (u16)msgFile, w->heapId);
    func_0201F5BC(bgFrame, 1, 0xD, 0, w->heapId);
    if (bgFrame < 4)
        func_02049B40(0x17, 5, 0, 0x1C0, 0x20, w->heapId);
    else
        func_02049B40(0x17, 5, 4, 0x1C0, 0x20, w->heapId);
    func_0201DD68();
    w->tcbl = TCBL_Create(w->heapId, w->heapId, 3, 0x100);
    w->stream = 0;
    w->message = 0;
    w->wordSet = 0;
    w->printQue = PRINTSYS_QUE_Create((void *)w->heapId);
    w->taskMenuRes = APP_TASKMENU_RES_Create(w->menuBgFrame, 10, w->font, w->printQue, w->heapId);
    w->taskMenu = 0;
    w->yesNoMenu = 0;
    w->keyCursor = func_02028590(0xF, cursor, 1, w->heapId);
    func_02034AC4((int)ov021_id);
    if (useTalkWin == 1) {
        talk.heapId = heapId;
        talk.reserved = 0;
        talk.font = (u32)w->font;
        talk.bgPalette = 10;
        talk.bgFrame = bgFrame;
        talk.x = 12;
        talk.y = 14;
        w->talkWin = TALKMSGWIN_Create(&talk.heapId);
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
        TALKMSGWIN_Delete(work->talkWin);
    if (work->taskMenu)
        APP_TASKMENU_CloseMenu(work->taskMenu);
    if (work->yesNoMenu)
        BMP_MENU_DeleteYesNo(work->yesNoMenu);
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    APP_KEYCURSOR_Delete(work->keyCursor);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    PRINTSYS_QUE_Delete(work->printQue);
    if (work->stream)
        PRINTSYS_PrintStreamDelete(work->stream);
    if (work->message)
        STRBUF_Delete(work->message);
    if (work->wordSet)
        MB_UTIL_MSG_DeleteWordSet(work);
    MSGDATA_Delete(work->msgData);
    if (work->window)
        BMP_WIN_Delete(work->window);
    GF_FONT_Delete(work->font);
    TCBL_Destroy(work->tcbl);
    func_020307B0(work);
    func_02034A5C((int)ov021_id);
}

void MB_UTIL_MSG_Main(MbMsgWork *work)
{
    int done;
    TCBL_Main(work->tcbl);
    if (work->stream) {
        done = func_02028484(work->keyCursorState, work->stream);
        APP_KEYCURSOR_Update(work->keyCursor, work->stream, work->window);
        if (done == 1) {
            PRINTSYS_PrintStreamDelete(work->stream);
            work->stream = 0;
        }
    }
    PRINTSYS_QUE_Main(work->printQue);
    if (work->printQueued == 1 && PRINTSYS_QUE_IsFinished(work->printQue) == 1) {
        BMP_WIN_TransferChars(work->window);
        work->printQueued = 0;
        if (work->timeIconPending == 1) {
            work->timeIconPending = 0;
            work->timeIcon = TIME_ICON_CreateNode(work->tcbl, work->window, 15, 16, work->heapId);
        }
    }
    if (work->taskMenu)
        APP_TASKMENU_UpdateMenu(work->taskMenu);
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
    func_020409B4(work->bgFrame);
}

void MB_UTIL_MSG_PrintStream(MbMsgWork *work, int msgId, int speed)
{
    struct StrBuf *expanded;

    if (work->stream != 0) {
        PRINTSYS_PrintStreamDelete(work->stream);
        work->stream = 0;
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->keyWaitFlag = 0;
    work->timeIconPending = 0;
    if (work->message != 0) {
        STRBUF_Delete(work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0xF);
    work->message = func_02045EC0(work->msgData, msgId);
    if (work->wordSet != 0) {
        expanded = STRBUF_Create(0x17B, work->heapId);
        func_0201F250(work->wordSet, expanded, work->message);
        STRBUF_Delete(work->message);
        work->message = expanded;
    }
    work->stream = PRINTSYS_PrintStream(work->window, 0, 0, work->message, work->font, speed, work->tcbl, 2, work->heapId, 0xF);
    if (work->layout == 8) {
        TALKMSGWIN_DrawWindowFrame(work->talkWin, work->window, 0);
    } else {
        func_0201F73C(work->window, 1, 1, 0xD);
    }
    if (work->cursorMode == 1) {
        func_02028470(work->keyCursorState, 6);
    } else {
        func_02028470(work->keyCursorState, 4);
    }
}

void MB_UTIL_MSG_PrintQueued(MbMsgWork *work, int msgId)
{
    struct StrBuf *expanded;

    if (work->stream != 0) {
        PRINTSYS_PrintStreamDelete(work->stream);
        work->stream = 0;
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->message != 0) {
        STRBUF_Delete(work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0xF);
    work->message = func_02045EC0(work->msgData, msgId);
    if (work->wordSet != 0) {
        expanded = STRBUF_Create(0x17B, work->heapId);
        func_0201F250(work->wordSet, expanded, work->message);
        STRBUF_Delete(work->message);
        work->message = expanded;
    }
    PRINTSYS_PrintQue(work->printQue, (u32)BMP_WIN_GetBmp(work->window), 0, 0, work->message, (u32)work->font);
    work->printQueued = 1;
    if (work->layout == 8) {
        TALKMSGWIN_DrawWindowFrame(work->talkWin, work->window, 0);
        func_020409B4(work->bgFrame);
    } else {
        func_0201F73C(work->window, 1, 1, 0xD);
    }
}

void MB_UTIL_MSG_ClearWindow(MbMsgWork *work)
{
    BMP_Clear(BMP_WIN_GetBmp(work->window), 0);
    if (work->layout == 8) {
        TALKMSGWIN_ClearWindowFrame(work->talkWin, work->window);
        func_020409B4(work->bgFrame);
    } else {
        func_0201F7A8(work->window, 1);
    }
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
}

void MB_UTIL_MSG_CreateWordSet(MbMsgWork *work)
{
    if (work->wordSet == 0) {
        work->wordSet = GF_FONT_Create_EC64(work->heapId);
    }
}

void MB_UTIL_MSG_DeleteWordSet(MbMsgWork *work)
{
    if (work->wordSet != 0) {
        WORDSET_DeleteStrbufED04(work->wordSet);
        work->wordSet = 0;
    }
}

void MB_UTIL_MSG_SetNumberLeft(MbMsgWork *work, int index, int value, int digits)
{
    func_0201EFA4(work->wordSet, index, value, digits, 0, 1);
}

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void MB_UTIL_MSG_SetNumberZeroPad(MbMsgWork *work, int index, int value, int digits) { func_0201EFA4(work->wordSet, index, value, digits, 2, 1); }

void MB_UTIL_MSG_OpenYesNoTaskMenu(MbMsgWork *work, int layout)
{
    MbMenuEntry entries[2];
    MbMenuTemplate tmpl;
    entries[0].label = func_02045EC0(work->msgData, 18);
    entries[1].label = func_02045EC0(work->msgData, 19);
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
    work->taskMenu = APP_TASKMENU_OpenMenu(&tmpl, work->taskMenuRes);
    STRBUF_Delete(entries[0].label);
    STRBUF_Delete(entries[1].label);
}

void MB_UTIL_MSG_CloseTaskMenu(MbMsgWork *work) { APP_TASKMENU_CloseMenu(work->taskMenu); work->taskMenu = 0; }

int MB_UTIL_MSG_GetTaskMenuResult(MbMsgWork *work) { if (APP_TASKMENU_IsFinish(work->taskMenu) == 1) return APP_TASKMENU_GetCursorPos(work->taskMenu) + 1; return 0; }

void MB_UTIL_MSG_OpenYesNoMenu(MbYesNoMsgWork *work)
{
    work->rect.frame = work->menuBgFrame;
    work->rect.x = 0x18;
    work->rect.y = 0xD;
    work->rect.width = 0xE;
    work->rect.height = 0;
    work->yesNoMenu = BMP_MENU_CreateYesNo(&work->rect, 1, 0xD, 0, work->heapId);
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
    sysMsg = func_02045B38(0, 3, 158, work->heapId);
    if (work->stream) {
        PRINTSYS_PrintStreamDelete(work->stream);
        work->stream = 0;
    }
    work->keyWaitFlag = 0;
    work->timeIconPending = 0;
    if (work->message) {
        STRBUF_Delete(work->message);
        work->message = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(work->window), 15);
    work->message = func_02045EC0(sysMsg, 22);
    work->stream = PRINTSYS_PrintStream(work->window, 0, 0, work->message, work->font, speed, work->tcbl, 2, work->heapId, 15);
    func_0201F73C(work->window, 1, 1, 13);
    MSGDATA_Delete(sysMsg);
    if (work->cursorMode == 1)
        func_02028470(work->keyCursorState, 6);
    else
        func_02028470(work->keyCursorState, 4);
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
    return PRINTSYS_QUE_IsFinished(work->printQue);
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
    func_020409B4(work->bgFrame);
}

void MB_UTIL_MSG_SetTimeIconPending(MbMsgWork *work, int pending) { work->timeIconPending = pending; }
