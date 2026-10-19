/*
 * file:     event_research_radar.c
 * unit:     yes
 * function: EVENT_RESEARCH_RADAR_TopTaskMain, EVENT_RESEARCH_RADAR_CreateTopTask, EVENT_RESEARCH_RADAR_ReportTaskMain, EVENT_RESEARCH_RADAR_CreateReportTask, EVENT_RESEARCH_RADAR_InitReportWork, EVENT_RESEARCH_RADAR_LoadReportMsgData, EVENT_RESEARCH_RADAR_DeleteReportMsgData, EVENT_RESEARCH_RADAR_CreateInfoWindow, EVENT_RESEARCH_RADAR_DeleteInfoWindow, EVENT_RESEARCH_RADAR_CreateWordSet, EVENT_RESEARCH_RADAR_DeleteWordSet, EVENT_RESEARCH_RADAR_PrintReport, EVENT_RESEARCH_RADAR_CloseInfoWindow, EVENT_RESEARCH_RADAR_GetReportKind, EVENT_RESEARCH_RADAR_GetReportNumberA, EVENT_RESEARCH_RADAR_GetReportNumberB, EVENT_RESEARCH_RADAR_GetReportMessageId
 * address:  0x02166F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from symbol_map_work.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ov217_id  0x000000D9  data
 *   gResearchTopProcData  0x021C3FE0  data  ov217
 *   g_ResearchRadarFileName 0x02172A00 data a1
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_GetMsgBg 0x02188C54 thumb ov021
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_ClearAllSlots  0x0201F31C  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb  ov021
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb
 *   GAME_DATA_GetSaveControlWork  0x02012EC0  thumb
 *   MISC_GetFromSave  0x0200C0E8  thumb
 *   MISC_GetResearchRank  0x0200C224  thumb
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   MISC_GetGreetCount  0x0200C1C4  thumb
 */
#include "symbol_map_shared_types.h"

struct FieldMap;

struct MsgBank;

struct WordSet;

struct InfoWindow;

struct StrBuf;

struct ReportBlock;

/* Heap block handed to ov217: it holds the game system. */
typedef struct ResearchTopParam {
    struct GameSystem *gameSystem;
} ResearchTopParam;

/* Work of the ov217 task (close field, run ov217, open field). */
typedef struct ResearchTopTaskWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    int transitionArg;              /* 0x04, argument of the field close and open events */
    ResearchTopParam *param;        /* 0x08 */
} ResearchTopTaskWork;

/* Work of the research report task. */
typedef struct ResearchReportWork {
    u16 heapId;                     /* 0x00 */
    u8 pad02[2];
    struct GameSystem *gameSystem;  /* 0x04 */
    struct GameData *gameData;      /* 0x08 */
    struct FieldMap *fieldMap;      /* 0x0C */
    void *fx;                       /* 0x10 */
    struct InfoWindow *window;      /* 0x14 */
    struct MsgBank *msgBank;        /* 0x18 */
    struct WordSet *wordSet;        /* 0x1C */
} ResearchReportWork;

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *fileName, u16 line);

extern struct GameTask *GAME_EVENT_Create(void *parent, void *reserved, void *mainFunc, u32 workSize);
struct GameEvent;

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern u32 GFL_HEAP_Free(void *block);

extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procTable, void *param);

extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait, int restoreBg, unsigned char seasonShown, unsigned char seasonTarget);
struct MyStatus;

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
struct FieldMsgWin;

extern int FIELD_MSGBG_IsMsgWinTransDone(struct FieldMsgWin *msgWin);

extern u32 KEY_GetTrg(void);

extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
struct FieldMsgBg;

extern struct FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct MsgBank *bank);
struct MsgData;

extern struct FieldMsgWin *FIELD_MSGBG_CreateMsgWin(struct FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);

extern int FIELD_MSGBG_DeleteMsgWin(struct FieldMsgWin *msgWin);

extern struct WordSet *WORDSET_CreateDefault(u16 heapId);

extern u32 WORDSET_Delete(struct WordSet *words);
struct Strbuf;

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void WORDSET_SetSlotMyStatus(struct WordSet *wordSet, u32 index, void *myStatus);

extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 c, u32 d);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);

extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

extern void WORDSET_ClearAllSlots(struct WordSet *wordSet);

extern void FIELD_MSGBG_MsgWinPrintStr(struct FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
struct BmpWin;

extern struct BmpWin *FIELD_MSGBG_GetMsgWinBmpWin(struct FieldMsgWin *msgWin);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BG_SYS_PushTile(u32 index);

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern void FIELD_MSGBG_ClearMsgWin(struct FieldMsgWin *msgWin);
struct SaveControl;

extern struct SaveControl *GAME_DATA_GetSaveControlWork(struct GameData *gameData);
struct MiscSave;

extern struct MiscSave *MISC_GetFromSave(struct SaveControl *save);

extern u8 MISC_GetResearchRank(struct MiscSave *beacon);

extern u32 MISC_GetThanksCount(struct MiscSave *beacon);

extern u32 MISC_GetGreetCount(struct MiscSave *beacon);

int EVENT_RESEARCH_RADAR_TopTaskMain(void *task, int *state, ResearchTopTaskWork *work);

void *EVENT_RESEARCH_RADAR_CreateTopTask(void *gameSystem, void *transitionArg);

int EVENT_RESEARCH_RADAR_ReportTaskMain(void *task, int *state, ResearchReportWork *work, int extra);

void *EVENT_RESEARCH_RADAR_CreateReportTask(void *gameSystem);

void EVENT_RESEARCH_RADAR_InitReportWork(ResearchReportWork *work, void *gameSystem);

struct MsgBank *EVENT_RESEARCH_RADAR_LoadReportMsgData(ResearchReportWork *work, int stateRef, ResearchReportWork *workCopy, int extra);

int EVENT_RESEARCH_RADAR_DeleteReportMsgData(ResearchReportWork *work);

void EVENT_RESEARCH_RADAR_CreateInfoWindow(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_DeleteInfoWindow(ResearchReportWork *work);

struct WordSet *EVENT_RESEARCH_RADAR_CreateWordSet(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_DeleteWordSet(ResearchReportWork *work);

void EVENT_RESEARCH_RADAR_PrintReport(ResearchReportWork *work);

void EVENT_RESEARCH_RADAR_CloseInfoWindow(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_GetReportKind(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_GetReportNumberA(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_GetReportNumberB(ResearchReportWork *work);

int EVENT_RESEARCH_RADAR_GetReportMessageId(unsigned int kind);

extern char ov217_id[];

extern char gResearchTopProcData[];

extern const char g_ResearchRadarFileName[];

/*
 * Task main of EVENT_RESEARCH_RADAR_CreateTopTask: closes the field, runs ov217 (pooled 0xD9)
 * on the heap block, opens the field and frees the block.
 */
int EVENT_RESEARCH_RADAR_TopTaskMain(void *task, int *state, ResearchTopTaskWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    int transitionArg = work->transitionArg;
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, (struct FieldMap *)transitionArg, 0, 0));
        *state = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)transitionArg));
        *state = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov217_id, gResearchTopProcData, work->param);
        *state = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)((int)FIELD_STATUS_CreateFieldOpenEvent(gameSystem)));
        *state = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct GameEvent *)task, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (struct FieldMap *)transitionArg, 0, 0, 1, 0, 0));
        *state = 5;
        break;
    case 5:
        GFL_HEAP_Free(work->param);
        return 1;
    }
    return 0;
}

/* Creates the ov217 task (see EVENT_RESEARCH_RADAR_TopTaskMain) with a 4-byte heap block that holds the game system. */
void *EVENT_RESEARCH_RADAR_CreateTopTask(void *gameSystem, void *transitionArg) {
    struct GameTask *task;
    ResearchTopTaskWork *work;
    ResearchTopParam *param;
    task = GAME_EVENT_Create(gameSystem, 0, EVENT_RESEARCH_RADAR_TopTaskMain, 12);
    work = GAME_EVENT_GetWork((struct GameEvent *)task);
    work->gameSystem = gameSystem;
    work->transitionArg = (int)transitionArg;
    param = GFL_HEAP_Alloc(4, 4, 0, g_ResearchRadarFileName, 117);
    work->param = param;
    param->gameSystem = gameSystem;
    return task;
}

/*
 * Task main of the research report: builds the message window (stage 0),
 * waits for it to open (1), waits for a key press (2) and tears it all down (3).
 */
int EVENT_RESEARCH_RADAR_ReportTaskMain(void *task, int *state, ResearchReportWork *work, int extra)
{
    switch (*state) {
    case 0:
        EVENT_RESEARCH_RADAR_LoadReportMsgData(work, (int)state, work, extra);
        EVENT_RESEARCH_RADAR_CreateInfoWindow(work);
        EVENT_RESEARCH_RADAR_CreateWordSet(work);
        EVENT_RESEARCH_RADAR_PrintReport(work);
        *state = *state + 1;
        break;
    case 1:
        if (FIELD_MSGBG_IsMsgWinTransDone((struct FieldMsgWin *)work->window) == 1)
            *state = *state + 1;
        break;
    case 2:
        if (KEY_GetTrg() & 0xf3)
            *state = *state + 1;
        break;
    case 3:
        EVENT_RESEARCH_RADAR_CloseInfoWindow(work);
        EVENT_RESEARCH_RADAR_DeleteWordSet(work);
        EVENT_RESEARCH_RADAR_DeleteInfoWindow(work);
        EVENT_RESEARCH_RADAR_DeleteReportMsgData(work);
        return 1;
    }
    return 0;
}

void *EVENT_RESEARCH_RADAR_CreateReportTask(void *gameSystem) {
    struct GameTask *task;
    task = GAME_EVENT_Create(gameSystem, 0, EVENT_RESEARCH_RADAR_ReportTaskMain, 32);
    EVENT_RESEARCH_RADAR_InitReportWork(GAME_EVENT_GetWork((struct GameEvent *)task), gameSystem);
    return task;
}

/*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 */
void EVENT_RESEARCH_RADAR_InitReportWork(ResearchReportWork *work, void *gameSystem) {
    void *fieldMap;
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    MI_CpuFill8(work, 0, 32);
    work->heapId = FIELDMAP_GetHeapId(fieldMap);
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->fieldMap = fieldMap;
    work->fx = (void *)FIELDMAP_GetMsgBg(fieldMap);
}

/* Loads the report message bank. */
struct MsgBank *EVENT_RESEARCH_RADAR_LoadReportMsgData(ResearchReportWork *work, int stateRef, ResearchReportWork *workCopy, int extra)
{
    struct MsgBank *bank;

    bank = MSGDATA_CreateFromArchive(0, 3, 0x2f, work->heapId);
    work->msgBank = bank;
    return bank;
}

int EVENT_RESEARCH_RADAR_DeleteReportMsgData(ResearchReportWork *work)
{
    MSGDATA_Delete(work->msgBank);
    work->msgBank = 0;
    return 0;
}

/* Opens the info window; it is 4 lines high for report kind 0 and 8 lines for the others. */
void EVENT_RESEARCH_RADAR_CreateInfoWindow(ResearchReportWork *work)
{
    int x;
    int width;
    int height;
    switch (EVENT_RESEARCH_RADAR_GetReportKind(work)) {
    case 0:
        x = 1;
        width = 0x1e;
        height = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        x = 1;
        width = 0x1e;
        height = 8;
        break;
    }
    work->window = (struct InfoWindow *)FIELD_MSGBG_CreateMsgWin(work->fx, (struct MsgData *)work->msgBank, x, x, width, height);
}

int EVENT_RESEARCH_RADAR_DeleteInfoWindow(ResearchReportWork *work)
{
    FIELD_MSGBG_DeleteMsgWin((struct FieldMsgWin *)work->window);
    work->window = 0;
    return 0;
}

struct WordSet *EVENT_RESEARCH_RADAR_CreateWordSet(ResearchReportWork *work)
{
    struct WordSet *wordSet;

    wordSet = WORDSET_CreateDefault(work->heapId);
    work->wordSet = wordSet;
    return wordSet;
}

int EVENT_RESEARCH_RADAR_DeleteWordSet(ResearchReportWork *work)
{
    WORDSET_Delete(work->wordSet);
    work->wordSet = 0;
    return 0;
}

/* Formats the report text (player name and two numbers) and prints it in the info window. */
void EVENT_RESEARCH_RADAR_PrintReport(ResearchReportWork *work)
{
    struct StrBuf *rawText;
    struct StrBuf *formattedText;
    int messageId;
    int numberA;
    int numberB;
    rawText = (struct StrBuf *)STRBUF_Create(0x100, work->heapId);
    formattedText = (struct StrBuf *)STRBUF_Create(0x100, work->heapId);
    messageId = EVENT_RESEARCH_RADAR_GetReportKind(work);
    numberA = EVENT_RESEARCH_RADAR_GetReportNumberA(work);
    numberB = EVENT_RESEARCH_RADAR_GetReportNumberB(work);
    messageId = EVENT_RESEARCH_RADAR_GetReportMessageId(messageId);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, GAME_DATA_GetMyStatus(work->gameData));
    WORDSET_SetSlotNumber(work->wordSet, 1, numberA, 5, 1, 1);
    WORDSET_SetSlotNumber(work->wordSet, 2, numberB, 5, 1, 1);
    MSGDATA_ReadString(work->msgBank, messageId, (struct Strbuf *)rawText);
    WORDSET_CopyTaggedText(work->wordSet, (struct Strbuf *)formattedText, (struct Strbuf *)rawText);
    WORDSET_ClearAllSlots(work->wordSet);
    FIELD_MSGBG_MsgWinPrintStr((struct FieldMsgWin *)work->window, 8, 0, (struct Strbuf *)formattedText);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((void *)FIELD_MSGBG_GetMsgWinBmpWin((struct FieldMsgWin *)work->window)));
    STRBUF_Delete((struct Strbuf *)rawText);
    STRBUF_Delete((struct Strbuf *)formattedText);
}

void EVENT_RESEARCH_RADAR_CloseInfoWindow(ResearchReportWork *work)
{
    FIELD_MSGBG_ClearMsgWin((struct FieldMsgWin *)work->window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((void *)FIELD_MSGBG_GetMsgWinBmpWin((struct FieldMsgWin *)work->window)));
}

/* Report kind (0..5) from the research report block. */
int EVENT_RESEARCH_RADAR_GetReportKind(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = MISC_GetFromSave(gameDataSave);
    result = MISC_GetResearchRank(block);
    return result;
}

/* First number of the research report block. */
int EVENT_RESEARCH_RADAR_GetReportNumberA(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = MISC_GetFromSave(gameDataSave);
    result = MISC_GetThanksCount(block);
    return result;
}

/* Second number of the research report block. */
int EVENT_RESEARCH_RADAR_GetReportNumberB(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = MISC_GetFromSave(gameDataSave);
    result = MISC_GetGreetCount(block);
    return result;
}

/* Message id of the report text for a report kind (0..5), 0 otherwise. */
int EVENT_RESEARCH_RADAR_GetReportMessageId(unsigned int kind)
{
    switch (kind) {
    case 0:
        return 0x174;
    case 1:
        return 0x175;
    case 2:
        return 0x176;
    case 3:
        return 0x177;
    case 4:
        return 0x178;
    case 5:
        return 0x179;
    }
    return 0;
}
