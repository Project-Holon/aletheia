/*
 * file:     report_event.c
 * unit:     yes
 * function: func_02169AB8, func_02169E0C, func_02169E4C, func_02169E98, func_02169EA4, func_02169EBC, func_02169F34, func_02169FB8, func_02169FFC, func_0216A07C, func_0216A0BC, func_0216A128, func_0216A148, func_0216A184, func_0216A1C0, func_0216A1F8, func_0216A21C, func_0216A244, func_0216A264, func_0216A280
 * address:  0x02169AB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x02169AB8: report_event.c __FILE__ string (0x02172A50) in the allocation call of 0x02169AB8.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02012944 0x02012944 thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A1518  0x021A1518  thumb  ov021
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1554  0x021A1554  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A0FB4  0x021A0FB4  thumb  ov021
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb
 *   func_0203101C  0x0203101C  arm
 *   d_02172A50     0x02172A50  data
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020450F0  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021904A8  0x021904A8  thumb  ov021
 *   func_02027F60  0x02027F60  thumb
 *   func_02027FD8   0x02027FD8  thumb
 *   APP_TASKMENU_OpenMenuFastDecide  0x0202784C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A2F54  0x021A2F54  thumb
 *   func_021A3244   0x021A3244  thumb  ov021
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Opaque objects owned by other files. */
typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct SaveControl SaveControl;
typedef struct MyStatus MyStatus;
typedef struct TrainerRecord TrainerRecord;
typedef struct FieldMap FieldMap;
typedef struct FieldCommLink FieldCommLink;
typedef struct FieldAvatar FieldAvatar;
typedef struct FieldMmdl FieldMmdl;
typedef struct FieldMsgContext FieldMsgContext;
typedef struct SaveEffect SaveEffect;
typedef struct TcblSystem TcblSystem;
typedef struct MsgData MsgData;
typedef struct Strbuf Strbuf;
typedef struct WordSet WordSet;
typedef struct BmpWin BmpWin;
typedef struct Bmp Bmp;
typedef struct PrintQue PrintQue;
typedef struct PrintStream PrintStream;
typedef struct AppKeyCursor AppKeyCursor;
typedef struct TimeIcon TimeIcon;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenuWork TaskMenuWork;

/* One entry of the yes/no menu (see app_taskmenu.c). */
typedef struct TaskMenuItem {
    Strbuf *str;        /* 0x00 */
    u16 msgColor;       /* 0x04 */
    u32 type;           /* 0x08 */
} TaskMenuItem;

/* Menu description handed to the task menu (see app_taskmenu.c). */
typedef struct TaskMenuInitWork {
    u32 heapId;             /* 0x00 */
    u8 itemNum;             /* 0x04 */
    TaskMenuItem *itemWork; /* 0x08 */
    u32 posType;            /* 0x0C */
    u8 charPosX;            /* 0x10 */
    u8 charPosY;            /* 0x11 */
    u8 width;               /* 0x12 */
    u8 height;              /* 0x13 */
} TaskMenuInitWork;

/* The message window and whether a print queue job still has to be transferred to it. */
typedef struct ReportEventWindow {
    BmpWin *bmpWin;         /* 0x00 */
    u8 queuePending;        /* 0x04 */
    u8 pad05[3];
} ReportEventWindow;

/* Everything the report event allocates for its message window and yes/no menu. */
typedef struct ReportEventRes {
    TcblSystem *tcbl;           /* 0x00: task list of the print stream */
    MsgData *msgData;           /* 0x04 */
    ReportEventWindow window;   /* 0x08 */
    PrintStream *printStream;   /* 0x10 */
    PrintQue *printQue;         /* 0x14 */
    Strbuf *message;            /* 0x18: text buffer of the current message */
    AppKeyCursor *keyCursor;    /* 0x1C */
    u32 printWait;              /* 0x20: set once a pause was released by a key press */
    TaskMenuItem menuItems[2];  /* 0x24: yes, no */
    TaskMenuRes *taskMenuRes;   /* 0x3C */
    TaskMenuWork *taskMenu;     /* 0x40 */
    TimeIcon *timeIcon;         /* 0x44 */
    SaveEffect *saveEffect;     /* 0x48 */
    u32 waitFrames;             /* 0x4C: frames spent waiting for a key after saving */
} ReportEventRes;

#include "field_event_types.h"

/* Values returned by the event function to its caller. */
enum {
    REPORT_EVENT_RESULT_SAVED,
    REPORT_EVENT_RESULT_CANCELED,
    REPORT_EVENT_RESULT_RUNNING
};

/* States of the event function. */
enum {
    REPORT_EVENT_STATE_LOCK_PLAYER,
    REPORT_EVENT_STATE_CREATE,
    REPORT_EVENT_STATE_PRINT_ASK,
    REPORT_EVENT_STATE_WAIT_ASK,
    REPORT_EVENT_STATE_YES_NO,
    REPORT_EVENT_STATE_PRINT_SAVING,
    REPORT_EVENT_STATE_WAIT_SAVING,
    REPORT_EVENT_STATE_WAIT_REQUEST,
    REPORT_EVENT_STATE_START_SAVE,
    REPORT_EVENT_STATE_SAVE,
    REPORT_EVENT_STATE_SAVED,
    REPORT_EVENT_STATE_WAIT_SAVED_MSG,
    REPORT_EVENT_STATE_WAIT_SAVED_SE,
    REPORT_EVENT_STATE_FAILED,
    REPORT_EVENT_STATE_WAIT_MESSAGE,
    REPORT_EVENT_STATE_WAIT_KEY,
    REPORT_EVENT_STATE_WAIT_KEY_TIMEOUT,
    REPORT_EVENT_STATE_CANCEL,
    REPORT_EVENT_STATE_DONE_CANCELED,
    REPORT_EVENT_STATE_FINISH_SAVED,
    REPORT_EVENT_STATE_DONE_SAVED
};

/* Message indices in the event's message bank. */
enum {
    REPORT_EVENT_MSG_ASK = 2,
    REPORT_EVENT_MSG_SAVING = 4,
    REPORT_EVENT_MSG_SAVED = 5,
    REPORT_EVENT_MSG_FAILED = 7,
    REPORT_EVENT_MSG_OVERWRITE = 8,
    REPORT_EVENT_MSG_SAVING_FIRST = 10
};

/* Request codes for the player avatar. */
enum {
    REPORT_EVENT_AVATAR_BEGIN = 0x20,
    REPORT_EVENT_AVATAR_END = 8
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *p);
extern GameData *func_020120F4(GameSystem *gameSystem);
extern FieldAvatar *func_02188CB4(FieldMap *fieldMap);
extern FieldMmdl *func_021A3074(FieldAvatar *avatar);
extern MyStatus *func_02012944(GameData *gameData);
extern Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern MsgData *func_02045B38(u32 type, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(MsgData *msgData, u32 index, Strbuf *dest);
extern void func_02045C04(MsgData *msgData);
extern u32 func_020362DC(void);
extern void func_02045808(Strbuf *str);
extern Strbuf *func_02045EC0(MsgData *msgData, u32 index);
extern FieldCommLink *func_02188CCC(FieldMap *fieldMap);
extern TrainerRecord *func_02012F2C(GameData *gameData);
extern int func_021A0F30(FieldCommLink *link, u32 mode);
extern int func_021A0ED4(FieldCommLink *link);
extern int func_021A1518(FieldCommLink *link);
extern void func_021A1524(FieldCommLink *link);
extern int func_021A1554(FieldCommLink *link);
extern void func_021A1530(FieldCommLink *link);
extern void func_021A1548(FieldCommLink *link);
extern int func_021A153C(FieldCommLink *link);
extern void func_021A0FB4(FieldCommLink *link, u32 heapId);
extern TcblSystem *func_0203101C(u16 heapId, u16 tag, u32 taskCount, u32 workSize);
extern AppKeyCursor *func_02028590(u32 a0, u32 a1, u32 a2, u32 heapId);
extern PrintQue *func_0201C440(u32 heapId);
extern int func_020071F0(SaveControl *saveControl);
extern void func_0201F7A8(BmpWin *bmpWin, u32 kind);
extern u32 func_02008DF0(TrainerRecord *record, int id);
extern TcblSystem *func_020056BC(void);
extern TimeIcon *func_0202EE30(TcblSystem *tcbl, BmpWin *bmpWin, u8 color, u8 priority, u16 heapId);
extern int func_02012DAC(GameData *gameData);
extern int func_02012DD0(GameData *gameData);
extern void func_0202F038(TimeIcon *timeIcon);
extern void func_020061E4(u32 seNo);
extern WordSet *func_0201EC64(u32 heapId);
extern void func_0201F02C(WordSet *wordSet, u32 index, MyStatus *myStatus);
extern void func_0201F250(WordSet *wordSet, Strbuf *dest, Strbuf *src);
extern void func_0201ED04(WordSet *wordSet);
extern int GFL_USE_IsSeqPlaying(u32 seNo);
extern void func_0201C4C0(PrintQue *printQue);
extern void func_02028604(AppKeyCursor *keyCursor);
extern void func_02031140(TcblSystem *tcbl);
extern BmpWin *func_020450F0(u32 bgLayer, u32 posX, u32 posY, u32 width, u8 height, u8 palette, u8 charOffset);
extern void func_0201F5BC(u32 bgLayer, u32 charOffset, u32 palette, u32 type, u32 heapId);
extern void func_02049B40(u32 arcId, u32 fileId, u32 palType, u32 offset, u32 size, u32 heapId);
extern void func_020452E8(BmpWin *bmpWin);
extern Bmp *func_02045770(BmpWin *bmpWin);
extern void func_02043B5C(Bmp *bmp, u8 value);
extern void func_0201F73C(BmpWin *bmpWin, int a1, int a2, int a3);
extern u32 func_021904AC(FieldMsgContext *msgContext);
extern signed char func_02012FFC(void);
extern PrintStream *func_0201CCE4(BmpWin *bmpWin, u32 x, u32 y, Strbuf *str, u32 font, u32 speed, TcblSystem *tcbl, u32 priority, u16 heapId, u32 clearColor);
extern void func_02045334(BmpWin *bmpWin);
extern void func_02045374(BmpWin *bmpWin);
extern u8 func_02045730(BmpWin *bmpWin);
extern void func_02041B6C(u32 bit);
extern u32 func_0201CE30(PrintStream *stream);
extern void func_0201CE5C(PrintStream *stream, int wait);
extern void func_0201CE38(PrintStream *stream);
extern void func_0201CE48(PrintStream *stream);
extern int func_02035C60(void);
extern u32 func_0203630C(void);
extern void func_020310C4(TcblSystem *tcbl);
extern void func_020286C4(AppKeyCursor *keyCursor, PrintStream *stream, BmpWin *bmpWin);
extern void func_0201C6FC(PrintQue *printQue, Bmp *bmp, u32 x, u32 y, Strbuf *str, u32 font);
extern void func_0201C4E4(PrintQue *printQue);
extern u32 func_0201C6C4(PrintQue *printQue, Bmp *bmp);
extern u32 func_0201C6B4(const PrintQue *printQue);
extern u32 func_021904A8(FieldMsgContext *msgContext);
extern TaskMenuRes *func_02027F60(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heapId);
extern void func_02027FD8(TaskMenuRes *res);
extern TaskMenuWork *APP_TASKMENU_OpenMenuFastDecide(TaskMenuInitWork *init, TaskMenuRes *res);
extern void func_02027974(TaskMenuWork *menu);
extern u32 func_020279E8(TaskMenuWork *menu);
extern u8 func_02027A04(const TaskMenuWork *menu);
extern void func_02027858(TaskMenuWork *menu);
extern int func_021A3208(FieldAvatar *avatar);
extern int func_021A2F48(FieldAvatar *avatar, u32 code);
extern int func_021A2F54(FieldAvatar *avatar);
extern int func_021A3244(FieldAvatar *avatar);
extern char *func_0216DB04(FieldMmdl *mmdl);
extern u32 *func_0216D550(FieldMmdl *mmdl, u32 bits);
extern SaveEffect *func_021D1164(u32 heapId, FieldMap *fieldMap);
extern int func_021D11B0(SaveEffect *effect);
extern int func_021D11D8(SaveEffect *effect);
extern int func_021D1194(SaveEffect *effect);
extern const char d_02172A50[];

int func_02169AB8(ReportEventWork *w, u32 *state);
void func_02169E0C(ReportEventWork *w);
void func_02169E4C(ReportEventWork *w);
void func_02169E98(ReportEventWork *w);
void func_02169EA4(ReportEventWork *w, u32 msgIndex);
void func_02169EBC(ReportEventWork *w);
int func_02169F34(ReportEventWork *w);
int func_02169FB8(ReportEventWork *w);
void func_02169FFC(ReportEventWork *w, u32 msgIndex);
int func_0216A07C(ReportEventWork *w);
void func_0216A0BC(ReportEventWork *w);
void func_0216A128(ReportEventWork *w);
void func_0216A148(ReportEventWork *w);
int func_0216A184(ReportEventWork *w);
void func_0216A1C0(ReportEventWork *w);
void func_0216A1F8(ReportEventWork *w);
int func_0216A21C(ReportEventWork *w);
int func_0216A244(ReportEventWork *w);
int func_0216A264(ReportEventWork *w);
int func_0216A280(ReportEventWork *w);

/*
 * Event function of the save-report event: asks "save?" with a yes/no menu,
 * runs the save with a time icon, then shows the result. Returns
 * REPORT_EVENT_RESULT_RUNNING until it is over.
 */
int func_02169AB8(ReportEventWork *w, u32 *state)
{
    WordSet *wordSet;
    Strbuf *message;

    switch (*state) {
    case REPORT_EVENT_STATE_LOCK_PLAYER:
        func_021A0F30(func_02188CCC(w->fieldMap), 7);
        *state = REPORT_EVENT_STATE_CREATE;
        break;
    case REPORT_EVENT_STATE_CREATE:
        if (func_021A0ED4(func_02188CCC(w->fieldMap)) == 1
            && func_021A1518(func_02188CCC(w->fieldMap)) == 1) {
            w->res = func_02030734(w->heapId, 0x50, 0, d_02172A50, 0x9F);
            w->res->msgData = func_02045B38(0, 3, 0x9E, w->heapId);
            w->res->message = func_020457B0(0x200, w->heapId);
            w->res->tcbl = func_0203101C(w->heapId, w->heapId, 1, 4);
            w->res->keyCursor = func_02028590(0xF, 1, 1, w->heapId);
            w->res->printQue = func_0201C440(w->heapId);
            w->res->waitFrames = 0;
            func_02169E4C(w);
            func_0216A0BC(w);
            *state = REPORT_EVENT_STATE_PRINT_ASK;
        }
        break;
    case REPORT_EVENT_STATE_PRINT_ASK:
        func_02169EA4(w, REPORT_EVENT_MSG_ASK);
        *state = REPORT_EVENT_STATE_WAIT_ASK;
        break;
    case REPORT_EVENT_STATE_WAIT_ASK:
        if (func_02169FB8(w) == 0) {
            func_0216A148(w);
            *state = REPORT_EVENT_STATE_YES_NO;
        }
        break;
    case REPORT_EVENT_STATE_YES_NO:
        switch (func_0216A184(w)) {
        case 0:
            if (func_020071F0(w->saveControl) == 1) {
                func_02169EA4(w, REPORT_EVENT_MSG_OVERWRITE);
                *state = REPORT_EVENT_STATE_WAIT_MESSAGE;
            } else {
                func_0201F7A8(w->res->window.bmpWin, 1);
                *state = REPORT_EVENT_STATE_PRINT_SAVING;
            }
            break;
        case 1:
            *state = REPORT_EVENT_STATE_CANCEL;
            break;
        }
        break;
    case REPORT_EVENT_STATE_PRINT_SAVING:
        func_02008DF0(func_02012F2C(func_020120F4(w->gameSystem)), 1);
        func_021A1524(func_02188CCC(w->fieldMap));
        if (func_021A1554(func_02188CCC(w->fieldMap)) == 1)
            func_02169FFC(w, REPORT_EVENT_MSG_SAVING_FIRST);
        else
            func_02169FFC(w, REPORT_EVENT_MSG_SAVING);
        *state = REPORT_EVENT_STATE_WAIT_SAVING;
        break;
    case REPORT_EVENT_STATE_WAIT_SAVING:
        if (func_0216A07C(w) == 1) {
            func_0216A1C0(w);
            *state = REPORT_EVENT_STATE_WAIT_REQUEST;
        }
        break;
    case REPORT_EVENT_STATE_WAIT_REQUEST:
        if (func_0216A21C(w) == 1)
            *state = REPORT_EVENT_STATE_START_SAVE;
        break;
    case REPORT_EVENT_STATE_START_SAVE:
        if (func_0216A244(w) != 0) {
            w->res->timeIcon = func_0202EE30(func_020056BC(), w->res->window.bmpWin, 0xF, 0x10, w->heapId);
            func_021A1530(func_02188CCC(w->fieldMap));
            func_0216A264(w);
            func_02012DAC(func_020120F4(w->gameSystem));
            *state = REPORT_EVENT_STATE_SAVE;
        }
        break;
    case REPORT_EVENT_STATE_SAVE:
        switch (func_02012DD0(func_020120F4(w->gameSystem))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = REPORT_EVENT_STATE_SAVED;
            break;
        case 3:
            func_021A1548(func_02188CCC(w->fieldMap));
            func_0216A280(w);
            func_0216A1F8(w);
            func_02169EA4(w, REPORT_EVENT_MSG_FAILED);
            func_0202F038(w->res->timeIcon);
            *state = REPORT_EVENT_STATE_FAILED;
            break;
        }
        break;
    case REPORT_EVENT_STATE_SAVED:
        if (func_021A153C(func_02188CCC(w->fieldMap)) == 1) {
            func_020061E4(0x558);
            func_0216A280(w);
            func_0216A1F8(w);
            wordSet = func_0201EC64(w->heapId);
            message = func_02045EC0(w->res->msgData, REPORT_EVENT_MSG_SAVED);
            func_0201F02C(wordSet, 0, func_02012944(func_020120F4(w->gameSystem)));
            func_0201F250(wordSet, w->res->message, message);
            func_02045808(message);
            func_0201ED04(wordSet);
            func_02169EBC(w);
            func_0202F038(w->res->timeIcon);
            *state = REPORT_EVENT_STATE_WAIT_SAVED_MSG;
        }
        break;
    case REPORT_EVENT_STATE_WAIT_SAVED_MSG:
        if (func_0216A21C(w) == 1 && func_0216A244(w) != 0 && func_02169FB8(w) == 0)
            *state = REPORT_EVENT_STATE_WAIT_SAVED_SE;
        break;
    case REPORT_EVENT_STATE_WAIT_SAVED_SE:
        if (GFL_USE_IsSeqPlaying(0x558) == 0)
            *state = REPORT_EVENT_STATE_WAIT_KEY_TIMEOUT;
        break;
    case REPORT_EVENT_STATE_FAILED:
        if (func_0216A21C(w) != 1 || func_0216A244(w) == 0)
            break;
        *state = REPORT_EVENT_STATE_WAIT_MESSAGE;
        /* fall through */
    case REPORT_EVENT_STATE_WAIT_MESSAGE:
        if (func_02169FB8(w) == 0)
            *state = REPORT_EVENT_STATE_WAIT_KEY;
        break;
    case REPORT_EVENT_STATE_WAIT_KEY:
        if (func_020362DC() & 3)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        break;
    case REPORT_EVENT_STATE_WAIT_KEY_TIMEOUT:
        if (func_020362DC() & 3)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        if (w->res->waitFrames >= 150)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        else
            w->res->waitFrames++;
        break;
    case REPORT_EVENT_STATE_CANCEL:
        func_02169E0C(w);
        func_021A0F30(func_02188CCC(w->fieldMap), 1);
        *state = REPORT_EVENT_STATE_DONE_CANCELED;
        break;
    case REPORT_EVENT_STATE_DONE_CANCELED:
        return REPORT_EVENT_RESULT_CANCELED;
    case REPORT_EVENT_STATE_FINISH_SAVED:
        func_02169E0C(w);
        func_021A0F30(func_02188CCC(w->fieldMap), 0);
        *state = REPORT_EVENT_STATE_DONE_SAVED;
        break;
    case REPORT_EVENT_STATE_DONE_SAVED:
        func_021A0FB4(func_02188CCC(w->fieldMap), w->heapId);
        return REPORT_EVENT_RESULT_SAVED;
    }
    return REPORT_EVENT_RESULT_RUNNING;
}

/* Frees the menu strings, message window, print queue, key cursor, task list, text buffer, message bank and the resource record. */
void func_02169E0C(ReportEventWork *w)
{
    func_0216A128(w);
    func_02169E98(w);
    func_0201C4C0(w->res->printQue);
    func_02028604(w->res->keyCursor);
    func_02031140(w->res->tcbl);
    func_02045808(w->res->message);
    func_02045C04(w->res->msgData);
    func_020307B0(w->res);
}

/* Creates the message window on layer 6 and loads its frame graphics and palette. */
void func_02169E4C(ReportEventWork *w)
{
    u32 bgLayer = 6;

    w->res->window.bmpWin = func_020450F0(bgLayer, 1, 1, 0x1E, 4, 12, 1);
    func_0201F5BC(6, 1, 13, 0, w->heapId);
    func_02049B40(0x17, 5, 4, bgLayer << 6, 0x20, w->heapId);
}

void func_02169E98(ReportEventWork *w)
{
    func_020452E8(w->res->window.bmpWin);
}

/* Reads message msgIndex into the text buffer and starts printing it. */
void func_02169EA4(ReportEventWork *w, u32 msgIndex)
{
    func_02045CAC(w->res->msgData, msgIndex, w->res->message);
    func_02169EBC(w);
}

/* Clears the message window, draws its frame and starts a print stream of the text buffer. */
void func_02169EBC(ReportEventWork *w)
{
    ReportEventRes *res;
    u32 font;
    BmpWin *bmpWin;

    func_02043B5C(func_02045770(w->res->window.bmpWin), 15);
    func_0201F73C(w->res->window.bmpWin, 2, 1, 13);
    res = w->res;
    font = func_021904AC(w->msgContext);
    w->res->printStream = func_0201CCE4(res->window.bmpWin, 0, 0, res->message, font, func_02012FFC(), res->tcbl, 10, w->heapId, 15);
    w->res->printWait = 0;
    bmpWin = w->res->window.bmpWin;
    func_02045334(bmpWin);
    func_02045374(bmpWin);
    func_02041B6C(func_02045730(bmpWin));
}

/* Advances the print stream; A, B or a touch speeds it up and continues after a pause. Returns 0 once it has finished. */
int func_02169F34(ReportEventWork *w)
{
    switch (func_0201CE30(w->res->printStream)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C(w->res->printStream, 0);
        w->res->printWait = 0;
        break;
    case 1:
        if (w->res->printWait == 0) {
            if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
                func_020061E4(0x547);
                func_0201CE38(w->res->printStream);
                w->res->printWait = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(w->res->printStream);
        w->res->printWait = 0;
        return 0;
    }
    return 1;
}

/* Runs the task list, key cursor and print stream, twice per call. Returns 0 once the message is done. */
int func_02169FB8(ReportEventWork *w)
{
    func_020310C4(w->res->tcbl);
    func_020286C4(w->res->keyCursor, w->res->printStream, w->res->window.bmpWin);
    if (func_02169F34(w) == 0)
        return 0;
    func_020310C4(w->res->tcbl);
    func_020286C4(w->res->keyCursor, w->res->printStream, w->res->window.bmpWin);
    return func_02169F34(w);
}

/* Reads message msgIndex and prints it through the print queue (no key wait). */
void func_02169FFC(ReportEventWork *w, u32 msgIndex)
{
    Strbuf *message;
    u32 font;
    ReportEventWindow *window;
    PrintQue *printQue;
    BmpWin *bmpWin;

    func_02043B5C(func_02045770(w->res->window.bmpWin), 15);
    func_0201F73C(w->res->window.bmpWin, 2, 1, 13);
    message = func_02045EC0(w->res->msgData, msgIndex);
    font = func_021904AC(w->msgContext);
    window = &w->res->window;
    printQue = w->res->printQue;
    func_0201C6FC(printQue, func_02045770(window->bmpWin), 0, 0, message, font);
    window->queuePending = 1;
    func_02045808(message);
    bmpWin = w->res->window.bmpWin;
    func_02045334(bmpWin);
    func_02045374(bmpWin);
    func_02041B6C(func_02045730(bmpWin));
}

/* Runs the print queue and transfers the window once its job is done. Returns the queue's finished flag. */
int func_0216A07C(ReportEventWork *w)
{
    ReportEventWindow *window;
    PrintQue *printQue;

    func_0201C4E4(w->res->printQue);
    printQue = w->res->printQue;
    window = &w->res->window;
    if (window->queuePending != 0 && func_0201C6C4(printQue, func_02045770(window->bmpWin)) == 0) {
        func_02045334(window->bmpWin);
        window->queuePending = 0;
    }
    return func_0201C6B4(w->res->printQue);
}

/* Loads the yes and no strings and creates the task menu resources. */
void func_0216A0BC(ReportEventWork *w)
{
    MsgData *msgData;
    u32 font;

    msgData = func_02045B38(0, 2, 0xA8, w->heapId);
    w->res->menuItems[0].str = func_02045EC0(msgData, 8);
    w->res->menuItems[0].msgColor = 0x39E3;
    w->res->menuItems[0].type = 0;
    w->res->menuItems[1].str = func_02045EC0(msgData, 9);
    w->res->menuItems[1].msgColor = 0x39E3;
    w->res->menuItems[1].type = 0;
    func_02045C04(msgData);
    font = func_021904AC(w->msgContext);
    w->res->taskMenuRes = func_02027F60(6, 14, font, func_021904A8(w->msgContext), w->heapId);
}

/* Deletes the task menu resources and the two menu strings. */
void func_0216A128(ReportEventWork *w)
{
    func_02027FD8(w->res->taskMenuRes);
    func_02045808(w->res->menuItems[1].str);
    func_02045808(w->res->menuItems[0].str);
}

/* Opens the two-entry yes/no menu. */
void func_0216A148(ReportEventWork *w)
{
    TaskMenuInitWork init;

    init.heapId = w->heapId;
    init.itemNum = 2;
    init.itemWork = w->res->menuItems;
    init.posType = 1;
    init.charPosX = 0x20;
    init.charPosY = 12;
    init.width = 8;
    init.height = 3;
    w->res->taskMenu = APP_TASKMENU_OpenMenuFastDecide(&init, w->res->taskMenuRes);
}

/* Updates the yes/no menu. Returns -1 while open, then 0 for yes or 1 for no. */
int func_0216A184(ReportEventWork *w)
{
    u8 cursorPos;

    func_02027974(w->res->taskMenu);
    if (func_020279E8(w->res->taskMenu) == 1) {
        cursorPos = func_02027A04(w->res->taskMenu);
        func_02027858(w->res->taskMenu);
        if (cursorPos != 0)
            return 1;
        return 0;
    }
    return -1;
}

/* Asks the player avatar for the begin-report animation and runs the request once. */
void func_0216A1C0(ReportEventWork *w)
{
    FieldAvatar *avatar;
    FieldMmdl *mmdl;

    avatar = func_02188CB4(w->fieldMap);
    if (func_021A3208(avatar) == 1) {
        mmdl = func_021A3074(avatar);
        func_021A2F48(avatar, REPORT_EVENT_AVATAR_BEGIN);
        func_0216DB04(mmdl);
        func_0216D550(mmdl, 0x10);
        func_021A2F54(avatar);
    }
}

/* Asks the player avatar to end the report animation. */
void func_0216A1F8(ReportEventWork *w)
{
    FieldAvatar *avatar;

    avatar = func_02188CB4(w->fieldMap);
    if (func_021A3208(avatar) == 1) {
        func_021A2F48(avatar, REPORT_EVENT_AVATAR_END);
        func_021A2F54(avatar);
    }
}

/* Returns 1 once the avatar request has finished (or there is no avatar to wait for). */
int func_0216A21C(ReportEventWork *w)
{
    FieldAvatar *avatar;

    avatar = func_02188CB4(w->fieldMap);
    if (func_021A3208(avatar) == 0)
        return 1;
    if (func_021A2F54(avatar) == 1)
        return 1;
    return 0;
}

/*
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 */
int func_0216A244(ReportEventWork *w)
{
    FieldAvatar *avatar = func_02188CB4(w->fieldMap);

    if (func_021A3208(avatar) == 1)
        return func_021A3244(avatar);

    return 1;
}

/* Creates the save effect object and starts it. */
int func_0216A264(ReportEventWork *w)
{
    w->res->saveEffect = func_021D1164(w->heapId, w->fieldMap);
    return func_021D11B0(w->res->saveEffect);
}

/* Stops and frees the save effect object. */
int func_0216A280(ReportEventWork *w)
{
    func_021D11D8(w->res->saveEffect);
    return func_021D1194(w->res->saveEffect);
}
