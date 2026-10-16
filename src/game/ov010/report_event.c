/*
 * file:     report_event.c
 * unit:     yes
 * function: REPORT_EVENT_Main, REPORT_EVENT_Free, REPORT_EVENT_CreateMessageWindow, REPORT_EVENT_DeleteMessageWindow, REPORT_EVENT_PrintMessage, REPORT_EVENT_StartPrintStream, REPORT_EVENT_UpdatePrintStream, REPORT_EVENT_UpdateMessage, REPORT_EVENT_QueueMessage, REPORT_EVENT_UpdateMessageQueue, REPORT_EVENT_CreateMenuResources, REPORT_EVENT_DeleteMenuResources, REPORT_EVENT_OpenYesNoMenu, REPORT_EVENT_UpdateYesNoMenu, REPORT_EVENT_BeginAvatarAnim, REPORT_EVENT_EndAvatarAnim, REPORT_EVENT_IsAvatarRequestDone, REPORT_EVENT_IsAvatarReady, REPORT_EVENT_StartSaveEffect, REPORT_EVENT_StopSaveEffect
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
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb ov021
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportReady  0x021A1518  thumb  ov021
 *   FIELD_SUBSCREEN_PrepareReportSave  0x021A1524  thumb  ov021
 *   FIELD_SUBSCREEN_CheckReportSaveCounter  0x021A1554  thumb  ov021
 *   FIELD_SUBSCREEN_StartReportSaveAnim  0x021A1530  thumb  ov021
 *   FIELD_SUBSCREEN_StopReportSaveAnim  0x021A1548  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportSaveAnimDone  0x021A153C  thumb  ov021
 *   FIELD_SUBSCREEN_ResumeField  0x021A0FB4  thumb  ov021
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb
 *   TCBL_Create  0x0203101C  arm
 *   d_02172A50     0x02172A50  data
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   KEY_GetCont  0x0203630C  arm
 *   TCBL_Main  0x020310C4  arm
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   FIELD_MSGBG_GetPrintQue  0x021904A8  thumb  ov021
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   APP_TASKMENU_RES_Delete   0x02027FD8  thumb
 *   APP_TASKMENU_OpenMenuFastDecide  0x0202784C  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   FIELD_PLAYER_CheckNotWaterForm  0x021A3208  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb
 *   FIELD_PLAYER_CheckAnimePaused   0x021A3244  thumb  ov021
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb
 *   FIELD_SAVEANIME_Delete  0x021D1194  thumb
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
extern GameData *ICA_ANIME_GetField1C(GameSystem *gameSystem);
extern FieldAvatar *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern FieldMmdl *FIELD_PLAYER_GetMmdl(FieldAvatar *avatar);
extern MyStatus *GAME_DATA_GetMyStatus(GameData *gameData);
extern Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern MsgData *func_02045B38(u32 type, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(MsgData *msgData, u32 index, Strbuf *dest);
extern void MSGDATA_Delete(MsgData *msgData);
extern u32 KEY_GetTrg(void);
extern void STRBUF_Delete(Strbuf *str);
extern Strbuf *func_02045EC0(MsgData *msgData, u32 index);
extern FieldCommLink *FIELDMAP_GetSubscreen(FieldMap *fieldMap);
extern TrainerRecord *GAME_DATA_GetTrainerRecord(GameData *gameData);
extern int FIELD_SUBSCREEN_RequestMode(FieldCommLink *link, u32 mode);
extern int FIELD_SUBSCREEN_IsIdle(FieldCommLink *link);
extern int FIELD_SUBSCREEN_IsReportReady(FieldCommLink *link);
extern void FIELD_SUBSCREEN_PrepareReportSave(FieldCommLink *link);
extern int FIELD_SUBSCREEN_CheckReportSaveCounter(FieldCommLink *link);
extern void FIELD_SUBSCREEN_StartReportSaveAnim(FieldCommLink *link);
extern void FIELD_SUBSCREEN_StopReportSaveAnim(FieldCommLink *link);
extern int FIELD_SUBSCREEN_IsReportSaveAnimDone(FieldCommLink *link);
extern void FIELD_SUBSCREEN_ResumeField(FieldCommLink *link, u32 heapId);
extern TcblSystem *TCBL_Create(u16 heapId, u16 tag, u32 taskCount, u32 workSize);
extern AppKeyCursor *APP_KEYCURSOR_CreateDefault(u32 a0, u32 a1, u32 a2, u32 heapId);
extern PrintQue *PRINTSYS_QUE_Create(u32 heapId);
extern int func_020071F0(SaveControl *saveControl);
extern void BMP_MENUWORK_DrawWindowBorder(BmpWin *bmpWin, u32 kind);
extern u32 func_02008DF0(TrainerRecord *record, int id);
extern TcblSystem *func_020056BC(void);
extern TimeIcon *TIME_ICON_Create(TcblSystem *tcbl, BmpWin *bmpWin, u8 color, u8 priority, u16 heapId);
extern int GAME_DATA_SaveStart(GameData *gameData);
extern int GAME_DATA_SaveMain(GameData *gameData);
extern void TIME_ICON_Delete(TimeIcon *timeIcon);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern WordSet *WORDSET_CreateDefault(u32 heapId);
extern void WORDSET_SetSlotMyStatus(WordSet *wordSet, u32 index, MyStatus *myStatus);
extern void WORDSET_CopyTaggedText(WordSet *wordSet, Strbuf *dest, Strbuf *src);
extern void WORDSET_DeleteStrbufED04(WordSet *wordSet);
extern int GFL_USE_IsSeqPlaying(u32 seNo);
extern void PRINTSYS_QUE_Delete(PrintQue *printQue);
extern void APP_KEYCURSOR_Delete(AppKeyCursor *keyCursor);
extern void TCBL_Destroy(TcblSystem *tcbl);
extern BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u32 width, u8 height, u8 palette, u8 charOffset);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 bgLayer, u32 charOffset, u32 palette, u32 type, u32 heapId);
extern void func_02049B40(u32 arcId, u32 fileId, u32 palType, u32 offset, u32 size, u32 heapId);
extern void BMP_WIN_Delete(BmpWin *bmpWin);
extern Bmp *BMP_WIN_GetBmp(BmpWin *bmpWin);
extern void BMP_Clear(Bmp *bmp, u8 value);
extern void BMP_MENUWORK_DrawWindow(BmpWin *bmpWin, int a1, int a2, int a3);
extern u32 FIELD_MSGBG_GetFont(FieldMsgContext *msgContext);
extern signed char MSG_SPEED_GetWait(void);
extern PrintStream *PRINTSYS_PrintStream(BmpWin *bmpWin, u32 x, u32 y, Strbuf *str, u32 font, u32 speed, TcblSystem *tcbl, u32 priority, u16 heapId, u32 clearColor);
extern void BMP_WIN_TransferChars(BmpWin *bmpWin);
extern void BMP_WIN_MakeScreen(BmpWin *bmpWin);
extern u8 BMP_WIN_GetBgLayer(BmpWin *bmpWin);
extern void func_02041B6C(u32 bit);
extern u32 PRINTSYS_PrintStreamGetState(PrintStream *stream);
extern void PRINTSYS_PrintStreamShortWait(PrintStream *stream, int wait);
extern void PRINTSYS_PrintStreamReleasePause(PrintStream *stream);
extern void PRINTSYS_PrintStreamDelete(PrintStream *stream);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetCont(void);
extern void TCBL_Main(TcblSystem *tcbl);
extern void APP_KEYCURSOR_Update(AppKeyCursor *keyCursor, PrintStream *stream, BmpWin *bmpWin);
extern void PRINTSYS_PrintQue(PrintQue *printQue, Bmp *bmp, u32 x, u32 y, Strbuf *str, u32 font);
extern void PRINTSYS_QUE_Main(PrintQue *printQue);
extern u32 PRINTSYS_QUE_IsExistTarget(PrintQue *printQue, Bmp *bmp);
extern u32 PRINTSYS_QUE_IsFinished(const PrintQue *printQue);
extern u32 FIELD_MSGBG_GetPrintQue(FieldMsgContext *msgContext);
extern TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heapId);
extern void APP_TASKMENU_RES_Delete(TaskMenuRes *res);
extern TaskMenuWork *APP_TASKMENU_OpenMenuFastDecide(TaskMenuInitWork *init, TaskMenuRes *res);
extern void APP_TASKMENU_UpdateMenu(TaskMenuWork *menu);
extern u32 APP_TASKMENU_IsFinish(TaskMenuWork *menu);
extern u8 APP_TASKMENU_GetCursorPos(const TaskMenuWork *menu);
extern void APP_TASKMENU_CloseMenu(TaskMenuWork *menu);
extern int FIELD_PLAYER_CheckNotWaterForm(FieldAvatar *avatar);
extern int FIELD_PLAYER_StartFormChange(FieldAvatar *avatar, u32 code);
extern int FIELD_PLAYER_StepFormChange(FieldAvatar *avatar);
extern int FIELD_PLAYER_CheckAnimePaused(FieldAvatar *avatar);
extern char *FLDMMDL_OffMoveBitMovePause(FieldMmdl *mmdl);
extern u32 *FLDMMDL_ClearStatusBit(FieldMmdl *mmdl, u32 bits);
extern SaveEffect *FIELD_SAVEANIME_Create(u32 heapId, FieldMap *fieldMap);
extern int FIELD_SAVEANIME_Start(SaveEffect *effect);
extern int FIELD_SAVEANIME_Stop(SaveEffect *effect);
extern int FIELD_SAVEANIME_Delete(SaveEffect *effect);
extern const char d_02172A50[];

int REPORT_EVENT_Main(ReportEventWork *w, u32 *state);
void REPORT_EVENT_Free(ReportEventWork *w);
void REPORT_EVENT_CreateMessageWindow(ReportEventWork *w);
void REPORT_EVENT_DeleteMessageWindow(ReportEventWork *w);
void REPORT_EVENT_PrintMessage(ReportEventWork *w, u32 msgIndex);
void REPORT_EVENT_StartPrintStream(ReportEventWork *w);
int REPORT_EVENT_UpdatePrintStream(ReportEventWork *w);
int REPORT_EVENT_UpdateMessage(ReportEventWork *w);
void REPORT_EVENT_QueueMessage(ReportEventWork *w, u32 msgIndex);
int REPORT_EVENT_UpdateMessageQueue(ReportEventWork *w);
void REPORT_EVENT_CreateMenuResources(ReportEventWork *w);
void REPORT_EVENT_DeleteMenuResources(ReportEventWork *w);
void REPORT_EVENT_OpenYesNoMenu(ReportEventWork *w);
int REPORT_EVENT_UpdateYesNoMenu(ReportEventWork *w);
void REPORT_EVENT_BeginAvatarAnim(ReportEventWork *w);
void REPORT_EVENT_EndAvatarAnim(ReportEventWork *w);
int REPORT_EVENT_IsAvatarRequestDone(ReportEventWork *w);
int REPORT_EVENT_IsAvatarReady(ReportEventWork *w);
int REPORT_EVENT_StartSaveEffect(ReportEventWork *w);
int REPORT_EVENT_StopSaveEffect(ReportEventWork *w);

/*
 * Event function of the save-report event: asks "save?" with a yes/no menu,
 * runs the save with a time icon, then shows the result. Returns
 * REPORT_EVENT_RESULT_RUNNING until it is over.
 */
int REPORT_EVENT_Main(ReportEventWork *w, u32 *state)
{
    WordSet *wordSet;
    Strbuf *message;

    switch (*state) {
    case REPORT_EVENT_STATE_LOCK_PLAYER:
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->fieldMap), 7);
        *state = REPORT_EVENT_STATE_CREATE;
        break;
    case REPORT_EVENT_STATE_CREATE:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(w->fieldMap)) == 1
            && FIELD_SUBSCREEN_IsReportReady(FIELDMAP_GetSubscreen(w->fieldMap)) == 1) {
            w->res = func_02030734(w->heapId, 0x50, 0, d_02172A50, 0x9F);
            w->res->msgData = func_02045B38(0, 3, 0x9E, w->heapId);
            w->res->message = STRBUF_Create(0x200, w->heapId);
            w->res->tcbl = TCBL_Create(w->heapId, w->heapId, 1, 4);
            w->res->keyCursor = APP_KEYCURSOR_CreateDefault(0xF, 1, 1, w->heapId);
            w->res->printQue = PRINTSYS_QUE_Create(w->heapId);
            w->res->waitFrames = 0;
            REPORT_EVENT_CreateMessageWindow(w);
            REPORT_EVENT_CreateMenuResources(w);
            *state = REPORT_EVENT_STATE_PRINT_ASK;
        }
        break;
    case REPORT_EVENT_STATE_PRINT_ASK:
        REPORT_EVENT_PrintMessage(w, REPORT_EVENT_MSG_ASK);
        *state = REPORT_EVENT_STATE_WAIT_ASK;
        break;
    case REPORT_EVENT_STATE_WAIT_ASK:
        if (REPORT_EVENT_UpdateMessage(w) == 0) {
            REPORT_EVENT_OpenYesNoMenu(w);
            *state = REPORT_EVENT_STATE_YES_NO;
        }
        break;
    case REPORT_EVENT_STATE_YES_NO:
        switch (REPORT_EVENT_UpdateYesNoMenu(w)) {
        case 0:
            if (func_020071F0(w->saveControl) == 1) {
                REPORT_EVENT_PrintMessage(w, REPORT_EVENT_MSG_OVERWRITE);
                *state = REPORT_EVENT_STATE_WAIT_MESSAGE;
            } else {
                BMP_MENUWORK_DrawWindowBorder(w->res->window.bmpWin, 1);
                *state = REPORT_EVENT_STATE_PRINT_SAVING;
            }
            break;
        case 1:
            *state = REPORT_EVENT_STATE_CANCEL;
            break;
        }
        break;
    case REPORT_EVENT_STATE_PRINT_SAVING:
        func_02008DF0(GAME_DATA_GetTrainerRecord(ICA_ANIME_GetField1C(w->gameSystem)), 1);
        FIELD_SUBSCREEN_PrepareReportSave(FIELDMAP_GetSubscreen(w->fieldMap));
        if (FIELD_SUBSCREEN_CheckReportSaveCounter(FIELDMAP_GetSubscreen(w->fieldMap)) == 1)
            REPORT_EVENT_QueueMessage(w, REPORT_EVENT_MSG_SAVING_FIRST);
        else
            REPORT_EVENT_QueueMessage(w, REPORT_EVENT_MSG_SAVING);
        *state = REPORT_EVENT_STATE_WAIT_SAVING;
        break;
    case REPORT_EVENT_STATE_WAIT_SAVING:
        if (REPORT_EVENT_UpdateMessageQueue(w) == 1) {
            REPORT_EVENT_BeginAvatarAnim(w);
            *state = REPORT_EVENT_STATE_WAIT_REQUEST;
        }
        break;
    case REPORT_EVENT_STATE_WAIT_REQUEST:
        if (REPORT_EVENT_IsAvatarRequestDone(w) == 1)
            *state = REPORT_EVENT_STATE_START_SAVE;
        break;
    case REPORT_EVENT_STATE_START_SAVE:
        if (REPORT_EVENT_IsAvatarReady(w) != 0) {
            w->res->timeIcon = TIME_ICON_Create(func_020056BC(), w->res->window.bmpWin, 0xF, 0x10, w->heapId);
            FIELD_SUBSCREEN_StartReportSaveAnim(FIELDMAP_GetSubscreen(w->fieldMap));
            REPORT_EVENT_StartSaveEffect(w);
            GAME_DATA_SaveStart(ICA_ANIME_GetField1C(w->gameSystem));
            *state = REPORT_EVENT_STATE_SAVE;
        }
        break;
    case REPORT_EVENT_STATE_SAVE:
        switch (GAME_DATA_SaveMain(ICA_ANIME_GetField1C(w->gameSystem))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = REPORT_EVENT_STATE_SAVED;
            break;
        case 3:
            FIELD_SUBSCREEN_StopReportSaveAnim(FIELDMAP_GetSubscreen(w->fieldMap));
            REPORT_EVENT_StopSaveEffect(w);
            REPORT_EVENT_EndAvatarAnim(w);
            REPORT_EVENT_PrintMessage(w, REPORT_EVENT_MSG_FAILED);
            TIME_ICON_Delete(w->res->timeIcon);
            *state = REPORT_EVENT_STATE_FAILED;
            break;
        }
        break;
    case REPORT_EVENT_STATE_SAVED:
        if (FIELD_SUBSCREEN_IsReportSaveAnimDone(FIELDMAP_GetSubscreen(w->fieldMap)) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x558);
            REPORT_EVENT_StopSaveEffect(w);
            REPORT_EVENT_EndAvatarAnim(w);
            wordSet = WORDSET_CreateDefault(w->heapId);
            message = func_02045EC0(w->res->msgData, REPORT_EVENT_MSG_SAVED);
            WORDSET_SetSlotMyStatus(wordSet, 0, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(w->gameSystem)));
            WORDSET_CopyTaggedText(wordSet, w->res->message, message);
            STRBUF_Delete(message);
            WORDSET_DeleteStrbufED04(wordSet);
            REPORT_EVENT_StartPrintStream(w);
            TIME_ICON_Delete(w->res->timeIcon);
            *state = REPORT_EVENT_STATE_WAIT_SAVED_MSG;
        }
        break;
    case REPORT_EVENT_STATE_WAIT_SAVED_MSG:
        if (REPORT_EVENT_IsAvatarRequestDone(w) == 1 && REPORT_EVENT_IsAvatarReady(w) != 0 && REPORT_EVENT_UpdateMessage(w) == 0)
            *state = REPORT_EVENT_STATE_WAIT_SAVED_SE;
        break;
    case REPORT_EVENT_STATE_WAIT_SAVED_SE:
        if (GFL_USE_IsSeqPlaying(0x558) == 0)
            *state = REPORT_EVENT_STATE_WAIT_KEY_TIMEOUT;
        break;
    case REPORT_EVENT_STATE_FAILED:
        if (REPORT_EVENT_IsAvatarRequestDone(w) != 1 || REPORT_EVENT_IsAvatarReady(w) == 0)
            break;
        *state = REPORT_EVENT_STATE_WAIT_MESSAGE;
        /* fall through */
    case REPORT_EVENT_STATE_WAIT_MESSAGE:
        if (REPORT_EVENT_UpdateMessage(w) == 0)
            *state = REPORT_EVENT_STATE_WAIT_KEY;
        break;
    case REPORT_EVENT_STATE_WAIT_KEY:
        if (KEY_GetTrg() & 3)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        break;
    case REPORT_EVENT_STATE_WAIT_KEY_TIMEOUT:
        if (KEY_GetTrg() & 3)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        if (w->res->waitFrames >= 150)
            *state = REPORT_EVENT_STATE_FINISH_SAVED;
        else
            w->res->waitFrames++;
        break;
    case REPORT_EVENT_STATE_CANCEL:
        REPORT_EVENT_Free(w);
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->fieldMap), 1);
        *state = REPORT_EVENT_STATE_DONE_CANCELED;
        break;
    case REPORT_EVENT_STATE_DONE_CANCELED:
        return REPORT_EVENT_RESULT_CANCELED;
    case REPORT_EVENT_STATE_FINISH_SAVED:
        REPORT_EVENT_Free(w);
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->fieldMap), 0);
        *state = REPORT_EVENT_STATE_DONE_SAVED;
        break;
    case REPORT_EVENT_STATE_DONE_SAVED:
        FIELD_SUBSCREEN_ResumeField(FIELDMAP_GetSubscreen(w->fieldMap), w->heapId);
        return REPORT_EVENT_RESULT_SAVED;
    }
    return REPORT_EVENT_RESULT_RUNNING;
}

/* Frees the menu strings, message window, print queue, key cursor, task list, text buffer, message bank and the resource record. */
void REPORT_EVENT_Free(ReportEventWork *w)
{
    REPORT_EVENT_DeleteMenuResources(w);
    REPORT_EVENT_DeleteMessageWindow(w);
    PRINTSYS_QUE_Delete(w->res->printQue);
    APP_KEYCURSOR_Delete(w->res->keyCursor);
    TCBL_Destroy(w->res->tcbl);
    STRBUF_Delete(w->res->message);
    MSGDATA_Delete(w->res->msgData);
    func_020307B0(w->res);
}

/* Creates the message window on layer 6 and loads its frame graphics and palette. */
void REPORT_EVENT_CreateMessageWindow(ReportEventWork *w)
{
    u32 bgLayer = 6;

    w->res->window.bmpWin = BMP_WIN_Create(bgLayer, 1, 1, 0x1E, 4, 12, 1);
    BMP_MENUWORK_LoadCharAndPltt(6, 1, 13, 0, w->heapId);
    func_02049B40(0x17, 5, 4, bgLayer << 6, 0x20, w->heapId);
}

void REPORT_EVENT_DeleteMessageWindow(ReportEventWork *w)
{
    BMP_WIN_Delete(w->res->window.bmpWin);
}

/* Reads message msgIndex into the text buffer and starts printing it. */
void REPORT_EVENT_PrintMessage(ReportEventWork *w, u32 msgIndex)
{
    func_02045CAC(w->res->msgData, msgIndex, w->res->message);
    REPORT_EVENT_StartPrintStream(w);
}

/* Clears the message window, draws its frame and starts a print stream of the text buffer. */
void REPORT_EVENT_StartPrintStream(ReportEventWork *w)
{
    ReportEventRes *res;
    u32 font;
    BmpWin *bmpWin;

    BMP_Clear(BMP_WIN_GetBmp(w->res->window.bmpWin), 15);
    BMP_MENUWORK_DrawWindow(w->res->window.bmpWin, 2, 1, 13);
    res = w->res;
    font = FIELD_MSGBG_GetFont(w->msgContext);
    w->res->printStream = PRINTSYS_PrintStream(res->window.bmpWin, 0, 0, res->message, font, MSG_SPEED_GetWait(), res->tcbl, 10, w->heapId, 15);
    w->res->printWait = 0;
    bmpWin = w->res->window.bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    func_02041B6C(BMP_WIN_GetBgLayer(bmpWin));
}

/* Advances the print stream; A, B or a touch speeds it up and continues after a pause. Returns 0 once it has finished. */
int REPORT_EVENT_UpdatePrintStream(ReportEventWork *w)
{
    switch (PRINTSYS_PrintStreamGetState(w->res->printStream)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3) != 0)
            PRINTSYS_PrintStreamShortWait(w->res->printStream, 0);
        w->res->printWait = 0;
        break;
    case 1:
        if (w->res->printWait == 0) {
            if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(w->res->printStream);
                w->res->printWait = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(w->res->printStream);
        w->res->printWait = 0;
        return 0;
    }
    return 1;
}

/* Runs the task list, key cursor and print stream, twice per call. Returns 0 once the message is done. */
int REPORT_EVENT_UpdateMessage(ReportEventWork *w)
{
    TCBL_Main(w->res->tcbl);
    APP_KEYCURSOR_Update(w->res->keyCursor, w->res->printStream, w->res->window.bmpWin);
    if (REPORT_EVENT_UpdatePrintStream(w) == 0)
        return 0;
    TCBL_Main(w->res->tcbl);
    APP_KEYCURSOR_Update(w->res->keyCursor, w->res->printStream, w->res->window.bmpWin);
    return REPORT_EVENT_UpdatePrintStream(w);
}

/* Reads message msgIndex and prints it through the print queue (no key wait). */
void REPORT_EVENT_QueueMessage(ReportEventWork *w, u32 msgIndex)
{
    Strbuf *message;
    u32 font;
    ReportEventWindow *window;
    PrintQue *printQue;
    BmpWin *bmpWin;

    BMP_Clear(BMP_WIN_GetBmp(w->res->window.bmpWin), 15);
    BMP_MENUWORK_DrawWindow(w->res->window.bmpWin, 2, 1, 13);
    message = func_02045EC0(w->res->msgData, msgIndex);
    font = FIELD_MSGBG_GetFont(w->msgContext);
    window = &w->res->window;
    printQue = w->res->printQue;
    PRINTSYS_PrintQue(printQue, BMP_WIN_GetBmp(window->bmpWin), 0, 0, message, font);
    window->queuePending = 1;
    STRBUF_Delete(message);
    bmpWin = w->res->window.bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    func_02041B6C(BMP_WIN_GetBgLayer(bmpWin));
}

/* Runs the print queue and transfers the window once its job is done. Returns the queue's finished flag. */
int REPORT_EVENT_UpdateMessageQueue(ReportEventWork *w)
{
    ReportEventWindow *window;
    PrintQue *printQue;

    PRINTSYS_QUE_Main(w->res->printQue);
    printQue = w->res->printQue;
    window = &w->res->window;
    if (window->queuePending != 0 && PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(window->bmpWin)) == 0) {
        BMP_WIN_TransferChars(window->bmpWin);
        window->queuePending = 0;
    }
    return PRINTSYS_QUE_IsFinished(w->res->printQue);
}

/* Loads the yes and no strings and creates the task menu resources. */
void REPORT_EVENT_CreateMenuResources(ReportEventWork *w)
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
    MSGDATA_Delete(msgData);
    font = FIELD_MSGBG_GetFont(w->msgContext);
    w->res->taskMenuRes = APP_TASKMENU_RES_Create(6, 14, font, FIELD_MSGBG_GetPrintQue(w->msgContext), w->heapId);
}

/* Deletes the task menu resources and the two menu strings. */
void REPORT_EVENT_DeleteMenuResources(ReportEventWork *w)
{
    APP_TASKMENU_RES_Delete(w->res->taskMenuRes);
    STRBUF_Delete(w->res->menuItems[1].str);
    STRBUF_Delete(w->res->menuItems[0].str);
}

/* Opens the two-entry yes/no menu. */
void REPORT_EVENT_OpenYesNoMenu(ReportEventWork *w)
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
int REPORT_EVENT_UpdateYesNoMenu(ReportEventWork *w)
{
    u8 cursorPos;

    APP_TASKMENU_UpdateMenu(w->res->taskMenu);
    if (APP_TASKMENU_IsFinish(w->res->taskMenu) == 1) {
        cursorPos = APP_TASKMENU_GetCursorPos(w->res->taskMenu);
        APP_TASKMENU_CloseMenu(w->res->taskMenu);
        if (cursorPos != 0)
            return 1;
        return 0;
    }
    return -1;
}

/* Asks the player avatar for the begin-report animation and runs the request once. */
void REPORT_EVENT_BeginAvatarAnim(ReportEventWork *w)
{
    FieldAvatar *avatar;
    FieldMmdl *mmdl;

    avatar = FIELDMAP_GetFieldPlayer(w->fieldMap);
    if (FIELD_PLAYER_CheckNotWaterForm(avatar) == 1) {
        mmdl = FIELD_PLAYER_GetMmdl(avatar);
        FIELD_PLAYER_StartFormChange(avatar, REPORT_EVENT_AVATAR_BEGIN);
        FLDMMDL_OffMoveBitMovePause(mmdl);
        FLDMMDL_ClearStatusBit(mmdl, 0x10);
        FIELD_PLAYER_StepFormChange(avatar);
    }
}

/* Asks the player avatar to end the report animation. */
void REPORT_EVENT_EndAvatarAnim(ReportEventWork *w)
{
    FieldAvatar *avatar;

    avatar = FIELDMAP_GetFieldPlayer(w->fieldMap);
    if (FIELD_PLAYER_CheckNotWaterForm(avatar) == 1) {
        FIELD_PLAYER_StartFormChange(avatar, REPORT_EVENT_AVATAR_END);
        FIELD_PLAYER_StepFormChange(avatar);
    }
}

/* Returns 1 once the avatar request has finished (or there is no avatar to wait for). */
int REPORT_EVENT_IsAvatarRequestDone(ReportEventWork *w)
{
    FieldAvatar *avatar;

    avatar = FIELDMAP_GetFieldPlayer(w->fieldMap);
    if (FIELD_PLAYER_CheckNotWaterForm(avatar) == 0)
        return 1;
    if (FIELD_PLAYER_StepFormChange(avatar) == 1)
        return 1;
    return 0;
}

/*
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 */
int REPORT_EVENT_IsAvatarReady(ReportEventWork *w)
{
    FieldAvatar *avatar = FIELDMAP_GetFieldPlayer(w->fieldMap);

    if (FIELD_PLAYER_CheckNotWaterForm(avatar) == 1)
        return FIELD_PLAYER_CheckAnimePaused(avatar);

    return 1;
}

/* Creates the save effect object and starts it. */
int REPORT_EVENT_StartSaveEffect(ReportEventWork *w)
{
    w->res->saveEffect = FIELD_SAVEANIME_Create(w->heapId, w->fieldMap);
    return FIELD_SAVEANIME_Start(w->res->saveEffect);
}

/* Stops and frees the save effect object. */
int REPORT_EVENT_StopSaveEffect(ReportEventWork *w)
{
    FIELD_SAVEANIME_Stop(w->res->saveEffect);
    return FIELD_SAVEANIME_Delete(w->res->saveEffect);
}
