/*
 * file:     event_shortcut_menu.c
 * unit:     yes
 * function: EVENT_SHORTCUT_MENU_HasShortcuts, EVENT_SHORTCUT_MENU_Create, EVENT_SHORTCUT_MENU_MainEvent, EVENT_SHORTCUT_MENU_ReturnEvent, EVENT_SHORTCUT_MENU_ResolveShortcut, EVENT_SHORTCUT_MENU_GetAvailBit, EVENT_SHORTCUT_MENU_OpenLink, EVENT_SHORTCUT_MENU_CloseLink, EVENT_SHORTCUT_MENU_ResumeLinkHook, EVENT_SHORTCUT_MENU_SuspendLinkHook, EVENT_SHORTCUT_MENU_OpenMessage, EVENT_SHORTCUT_MENU_CheckPartyRibbon, EVENT_SHORTCUT_MENU_CreateProcEvent, EVENT_SHORTCUT_MENU_ProcEventMain, EVENT_SHORTCUT_MENU_InitHooks, EVENT_SHORTCUT_MENU_CallResumeHook, EVENT_SHORTCUT_MENU_CallSuspendHook, EVENT_SHORTCUT_MENU_CallExitHook
 * address:  0x0215FF34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   func_02012934   0x02012934  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   func_020355D8  0x020355D8  arm
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   MOVE_POKEMON_InitSkillInfo  0x0215E840  thumb  ov010
 *   EVENTDATA_SYSTEM_CreateFieldLinkEvent  0x021644F4  thumb  ov010
 *   func_0200C404   0x0200C404  thumb
 *   func_0200C468   0x0200C468  thumb
 *   d_02172960     0x02172960  data  a4
 *   func_02164480  0x02164480  thumb  ov010
 *   SHORTCUT_MENU_Main  0x021C5224  thumb  ov021
 *   SHORTCUT_MENU_Start  0x021C5348  thumb  ov021
 *   SHORTCUT_MENU_RequestClose  0x021C536C  thumb  ov021
 *   SHORTCUT_MENU_IsWaitingInput  0x021C5380  thumb  ov021
 *   SHORTCUT_MENU_GetResult  0x021C5394  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02028754  0x02028754  thumb
 *   func_0200C464  0x0200C464  thumb
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 *   FIELD_MSGBG_ReleaseBg  0x02190344  thumb
 *   GAME_DATA_GetRtcWork  0x02012C0C  thumb
 *   SHORTCUT_MENU_Create  0x021C4F7C  thumb
 *   SHORTCUT_MENU_Delete  0x021C51A0  thumb  ov021
 *   FIELD_MSGBG_SetupBgSingle  0x02190398  thumb
 *   SHORTCUT_MENU_RunPrint  0x021C5334  thumb  ov021
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_TOOL_HasRibbonData  0x0201897C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021712CC     0x021712CC  data
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GameSystem;
struct GameEvent;
struct GameData;
struct FieldMap;
struct SaveControl;
struct ShortcutLink;
struct ShortcutMenuWork;
struct ShortcutProcTask;

/*
 * Shortcut save block (save block 0x36, 26 bytes): the shortcut ids the
 * player registered, in order, in the first 25 slots. SHORTCUT_NONE marks an
 * empty slot; the last byte is never used. The accessors live in the arm9
 * file that owns the block.
 */
#define SHORTCUT_SLOT_COUNT 25
#define SHORTCUT_NONE       25

typedef struct ShortcutList {
    u8 id[SHORTCUT_SLOT_COUNT + 1];
} ShortcutList;

/* One bit per menu entry that is currently usable (filled by func_02164480). */
typedef struct ShortcutAvailMask {
    u32 bits[6];
} ShortcutAvailMask;

/* Field state snapshot taken when a shortcut proc task starts (MOVE_POKEMON_InitSkillInfo). */
typedef struct ShortcutFieldInfo {
    u16 zoneId;         /* 0x00 */
    u16 stateFlags;     /* 0x02 */
    u32 playerPosX;     /* 0x04 */
    u32 playerPosZ;     /* 0x08 */
    void *mapObj;       /* 0x0C */
    void *fieldMap;     /* 0x10 */
} ShortcutFieldInfo;

/*
 * Hook table of a proc task. Every hook gets the link (as ctx) and hookArg
 * and returns non-zero when it is done; a missing hook counts as done.
 * onResume reopens the link session, onSuspend closes it, onExit is unused
 * by the code in this file (always empty).
 */
typedef int (*ShortcutHook)(struct ShortcutLink *link, struct ShortcutMenuWork *arg);

typedef struct ShortcutHooks {
    ShortcutHook onResume;      /* 0x00 */
    ShortcutHook onSuspend;     /* 0x04 */
    ShortcutHook onExit;        /* 0x08 */
    struct ShortcutMenuWork *arg; /* 0x0C */
    struct ShortcutLink *link;  /* 0x10 */
} ShortcutHooks;

/*
 * The 0x40-byte block hung off the work. The caller fills procIndex and
 * procArg through EVENT_SHORTCUT_MENU_ResolveShortcut; the proc task reads the hooks from
 * +0x14..+0x20 and writes result and nextEvent back.
 */
typedef struct ShortcutLink {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    struct GameEvent *event;        /* 0x08 */
    u32 procIndex;                  /* 0x0C: first entry of the proc table to run */
    u32 procArg;                    /* 0x10: passed to the proc's init and start */
    ShortcutHook onResume;          /* 0x14 */
    ShortcutHook onSuspend;         /* 0x18 */
    ShortcutHook onExit;            /* 0x1C */
    struct ShortcutMenuWork *hookArg; /* 0x20 */
    u32 result;                     /* 0x24: 0 done, 1 cancelled, 2 and 3 other ends */
    u32 nextEvent;                  /* 0x28: index handed to EVENTDATA_SYSTEM_CreateFieldLinkEvent */
    u8 pad2C[0x40 - 0x2C];
} ShortcutLink;

/* Work of the two shortcut menu events (0x20 bytes). */
typedef struct ShortcutMenuWork {
    struct GameEvent *event;        /* 0x00 */
    struct GameSystem *gameSystem;  /* 0x04 */
    struct FieldMap *fieldMap;      /* 0x08 */
    void *commObj;                  /* 0x0C: link session object, 0 when closed */
    ShortcutLink *link;             /* 0x10 */
    u16 id;                         /* 0x14 */
    u8 pad16[2];
    u32 commClosed;                 /* 0x18: set when no shortcut is registered */
    u32 commCloseState;             /* 0x1C: step of the close sequence */
} ShortcutMenuWork;

/* One record of the proc table at 0x021712CC (24 bytes). */
typedef struct ShortcutProc {
    u32 overlayId;                                  /* 0x00 */
    void *procTemplate;                             /* 0x04 */
    void *(*init)(struct ShortcutProcTask *task, u32 procArg, u32 prevProc, void *prevWork); /* 0x08 */
    u32 (*finish)(struct ShortcutProcTask *task, void *work);  /* 0x0C */
    void (*start)(struct ShortcutProcTask *task, u32 procArg); /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} ShortcutProc;

/* Work of the proc task (0x74 bytes). */
typedef struct ShortcutProcTask {
    u16 id;                         /* 0x00 */
    u8 pad02[2];
    u32 proc;                       /* 0x04: index of the running proc */
    u32 prevProc;                   /* 0x08 */
    u32 nextProc;                   /* 0x0C */
    u32 procResult;                 /* 0x10: 0 done, 1 cancelled, 2, 3, 4 = run nextProc */
    struct GameEvent *event;        /* 0x14 */
    ShortcutLink *link;             /* 0x18 */
    void *procWork;                 /* 0x1C */
    ShortcutHooks hooks;            /* 0x20 */
    ShortcutAvailMask avail;        /* 0x34 */
    ShortcutFieldInfo fieldInfo;    /* 0x4C */
    u8 cursorIndex;                 /* 0x60 */
    u8 pad61;
    u16 scrollOffset;               /* 0x62 */
    u8 pad64[4];
    u32 selectedItem;               /* 0x68 */
    u8 pad6C[8];
} ShortcutProcTask;


extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *func, u32 size);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern void SCRIPT_WORK_SetParams(void *msgWindow, int messageIndex, int a, int b, u16 c);
extern int func_020307B0();
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procTemplate, void *work);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 a, u32 b);
extern void *func_02012934(const struct GameData *gameData);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_020355D8(u8 v);
extern void *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern void FLDMMDL_SysPauseMove(void *map);
extern u32 *FLDMMDL_SysResumeMove(void *map);
extern void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, ShortcutFieldInfo *out);
extern struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEvent(u32 index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern ShortcutList *func_0200C404(struct SaveControl *save);
extern u16 func_0200C468(const ShortcutList *list);
extern void func_02164480(ShortcutAvailMask *mask, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void SHORTCUT_MENU_Main(void *commObj);
extern void SHORTCUT_MENU_Start(void *commObj);
extern void SHORTCUT_MENU_RequestClose(void *commObj);
extern int SHORTCUT_MENU_IsWaitingInput(void *commObj);
extern u32 SHORTCUT_MENU_GetResult(void *commObj, u32 *result);
extern void *func_020127A4(const struct GameData *gameData);
extern u32 func_02012B28(const void *eventWork);
extern int func_02012B70(const struct GameData *gameData);
extern u32 func_02028754(const ShortcutAvailMask *mask, u32 bit);
extern u8 func_0200C464(const ShortcutList *list, u32 slot);
extern int func_02040588();
extern void *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern int FIELD_MSGBG_ReleaseBg();
extern const u16 *GAME_DATA_GetRtcWork(struct GameData *gameData);
extern void *SHORTCUT_MENU_Create(struct GameData *gameData, int mode, const u16 *playerName, u16 bufferSize, u16 heapId);
extern int SHORTCUT_MENU_Delete();
extern int FIELD_MSGBG_SetupBgSingle();
extern int SHORTCUT_MENU_RunPrint(void *commObj);
extern void *SCRIPT_SYS_CreateScriptEventSimple(struct GameSystem *gameSystem, int messageId, int a, int heapId);
extern void *SCRIPT_SYS_GetEventScriptWork(void *msgWindow);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *party, u32 index);
extern u32 func_02017E1C(void *mon, u32 param, u32 value);
extern u32 POKE_TOOL_HasRibbonData(void *mon);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void FIELDMAP_SetBgMode(void);
extern void FIELDMAP_ResetBgAffineShowMsg(void *map);


int EVENT_SHORTCUT_MENU_HasShortcuts(struct GameSystem *gameSystem);
struct GameEvent *EVENT_SHORTCUT_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
int EVENT_SHORTCUT_MENU_MainEvent(struct GameEvent *event, u32 *seq, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_ReturnEvent(struct GameEvent *event, u32 *seq, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_ResolveShortcut(ShortcutLink *link, u32 shortcutId);
int EVENT_SHORTCUT_MENU_GetAvailBit(u32 shortcutId, u32 *availBit, u32 *isUnknownId);
void EVENT_SHORTCUT_MENU_OpenLink(int mode, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_CloseLink(ShortcutMenuWork *work, u32 *seq);
int EVENT_SHORTCUT_MENU_ResumeLinkHook(ShortcutLink *link, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_SuspendLinkHook(ShortcutLink *link, ShortcutMenuWork *work);
void *EVENT_SHORTCUT_MENU_OpenMessage(struct GameSystem *gameSystem, u32 messageIndex);
int EVENT_SHORTCUT_MENU_CheckPartyRibbon(ShortcutMenuWork *work);
struct GameEvent *EVENT_SHORTCUT_MENU_CreateProcEvent(ShortcutLink *link, u16 id);
int EVENT_SHORTCUT_MENU_ProcEventMain(struct GameEvent *event, u32 *seq, ShortcutProcTask *task);
void EVENT_SHORTCUT_MENU_InitHooks(ShortcutHooks *hooks, ShortcutLink *link, ShortcutHook onResume, ShortcutHook onSuspend, ShortcutHook onExit, struct ShortcutMenuWork *arg);
int EVENT_SHORTCUT_MENU_CallResumeHook(ShortcutHooks *hooks);
int EVENT_SHORTCUT_MENU_CallSuspendHook(ShortcutHooks *hooks);
int EVENT_SHORTCUT_MENU_CallExitHook(ShortcutHooks *hooks);


extern const char d_02172960[];
extern ShortcutProc d_021712CC[];


/*
 * TRUE when at least one shortcut is registered in the save block.
 */
int EVENT_SHORTCUT_MENU_HasShortcuts(struct GameSystem *gameSystem)
{
    if (func_0200C468(func_0200C404(GAME_DATA_GetSaveControl(func_020120F4(gameSystem)))) != 0)
        return 1;

    return 0;
}


/*
 * Creates the shortcut menu event. With exactly one shortcut registered the
 * event (EVENT_SHORTCUT_MENU_ReturnEvent) runs it directly; otherwise the event shows the menu
 * and the link exchange (EVENT_SHORTCUT_MENU_MainEvent).
 */
struct GameEvent *EVENT_SHORTCUT_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id)
{
    ShortcutList *shortcuts;
    struct GameEvent *event;
    ShortcutMenuWork *work;

    shortcuts = func_0200C404(GAME_DATA_GetSaveControl(func_020120F4(gameSystem)));
    if (func_0200C468(shortcuts) == 1) {
        event = func_020122C0(gameSystem, 0, (void *)EVENT_SHORTCUT_MENU_ReturnEvent, sizeof(ShortcutMenuWork));
    } else {
        event = func_020122C0(gameSystem, 0, (void *)EVENT_SHORTCUT_MENU_MainEvent, sizeof(ShortcutMenuWork));
    }
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, sizeof(ShortcutMenuWork));
    work->gameSystem = gameSystem;
    work->event = event;
    work->fieldMap = fieldMap;
    work->id = id;
    work->commClosed = 0;
    work->link = func_02030734(4, sizeof(ShortcutLink), 0, d_02172960, 0xc2);
    MI_CpuFill8(work->link, 0, sizeof(ShortcutLink));
    work->link->gameSystem = work->gameSystem;
    work->link->fieldMap = work->fieldMap;
    work->link->event = event;
    if (func_0200C468(shortcuts) != 1) {
        work->link->onResume = EVENT_SHORTCUT_MENU_ResumeLinkHook;
        work->link->onSuspend = EVENT_SHORTCUT_MENU_SuspendLinkHook;
        work->link->hookArg = work;
    }
    FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(work->fieldMap));
    func_020355D8(0);
    return event;
}


/*
 * Proc main of the ov010 link exchange: a 16-state machine that drives
 * the ov021 connection object at +0xC, classifies the received result
 * code, and hands off to the result screens before tearing down.
 *
 * The ov021 calls to 0x021C536C, 0x021C5380 and 0x021C5394 (once folded
 * into SHORTCUT_MENU_Start) resolve since seeds_2 labelled them. Levers: in state 4 `noEligibleMon` declared first and `blocked`
 * last (noEligibleMon spills to sp+4, hasAvailBit to sp+0, launchEvent stays in r7), the result
 * code dispatched as a switch and the case-10 value as an if chain with
 * the commClosed != 0 arm first; in state 12 the tail call in a local written
 * as a nested if (nextEvent == 0, then the save test) with the call in all
 * three arms, which is what makes both work->gameSystem loads hoist above their
 * branches and lets state 11 cross-jump into the shared tail.
 */
int EVENT_SHORTCUT_MENU_MainEvent(struct GameEvent *event, u32 *seq, ShortcutMenuWork *work)
{
    switch (*seq) {
    case 0:
        *seq = 1;
        break;
    case 1:
        EVENT_SHORTCUT_MENU_OpenLink(0, work);
        *seq = 2;
        break;
    case 2:
        SHORTCUT_MENU_Start(work->commObj);
        *seq = 3;
        break;
    case 3:
        SHORTCUT_MENU_Main(work->commObj);
        if (SHORTCUT_MENU_IsWaitingInput(work->commObj) == 0)
            *seq = 4;
        break;
    case 4: {
        u32 code;
        int r;

        SHORTCUT_MENU_Main(work->commObj);
        r = SHORTCUT_MENU_GetResult(work->commObj, &code);
        if (r == 1) {
            ShortcutAvailMask avail;
            u32 availBit;
            u32 isUnknownId;
            int noEligibleMon = 0;
            int hasAvailBit;
            int launchEvent;
            int blocked = 0;

            hasAvailBit = EVENT_SHORTCUT_MENU_GetAvailBit(code, &availBit, &isUnknownId);
            launchEvent = EVENT_SHORTCUT_MENU_ResolveShortcut(work->link, code);
            if (isUnknownId == 0 && func_02012B70(func_020120F4(work->gameSystem)) == 1) {
                blocked = 1;
            } else if (hasAvailBit == 1) {
                func_02164480(&avail, work->gameSystem, work->fieldMap);
                if (func_02028754(&avail, availBit) == 0)
                    blocked = 1;
            }
            if (code == 9 && EVENT_SHORTCUT_MENU_CheckPartyRibbon(work) == 0)
                noEligibleMon = 1;
            if (blocked == 1) {
                *seq = 12;
            } else if (noEligibleMon == 1) {
                *seq = 14;
            } else {
                switch (launchEvent) {
                case 0:
                    *seq = 9;
                    break;
                case 1:
                    *seq = 11;
                    break;
                }
            }
        } else if (r == 2) {
            *seq = 5;
        }
        break;
    }
    case 5:
        SHORTCUT_MENU_RequestClose(work->commObj);
        *seq = 6;
        break;
    case 6:
        SHORTCUT_MENU_Main(work->commObj);
        if (SHORTCUT_MENU_IsWaitingInput(work->commObj) == 0)
            *seq = 7;
        break;
    case 7:
        if (EVENT_SHORTCUT_MENU_CloseLink(work, seq) != 0) {
            func_020307B0(work->link);
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
            return 1;
        }
        break;
    case 8:
        EVENT_SHORTCUT_MENU_OpenLink(1, work);
        *seq = 4;
        break;
    case 9:
        GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_CreateProcEvent(work->link, work->id));
        *seq = 10;
        break;
    case 10:
    {
        u32 result = work->link->result;

        if (result == 0) {
            if (work->commClosed != 0)
                *seq = 7;
            else
                *seq = 8;
        } else if (result == 1) {
            *seq = 7;
        } else if (result == 3) {
            *seq = 11;
        }
        break;
    }
    case 11:
        if (EVENT_SHORTCUT_MENU_CloseLink(work, seq) != 0) {
            u32 nextEvent = work->link->nextEvent;

            func_020307B0(work->link);
            work->link = 0;
            GAME_EVENT_CallEvent(event, EVENTDATA_SYSTEM_CreateFieldLinkEvent(nextEvent, work->gameSystem, work->fieldMap));
            *seq = 13;
        }
        break;
    case 12:
        if (EVENT_SHORTCUT_MENU_CloseLink(work, seq) != 0) {
            u32 nextEvent = work->link->nextEvent;

            func_020307B0(work->link);
            work->link = 0;
            {
                void *message;

                if (nextEvent == 0) {
                    if (func_02012B28(func_020127A4(func_020120F4(work->gameSystem))) == 1)
                        message = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 1);
                    else
                        message = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 0);
                } else {
                    message = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 0);
                }
                GAME_EVENT_CallEvent(event, message);
            }
            *seq = 13;
        }
        break;
    case 13:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    case 14:
        if (EVENT_SHORTCUT_MENU_CloseLink(work, seq) != 0) {
            func_020307B0(work->link);
            work->link = 0;
            GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 2));
            *seq = 15;
        }
        break;
    case 15:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    }
    return 0;
}


/*
 * Nine-state connection sequence; returns 1 when the sequence has ended.
 * EXACT* because the listing extent runs over the unlabelled followers
 * 0x0216040C, 0x02160564 and 0x021605C0. Levers: the case-3 test is an
 * else-if chain with the `*seq = 1` arm written twice (the first copy is
 * cross-jumped into `b`), and cases 4 and 5 hand one local `child` to
 * GAME_EVENT_CallEvent, which is what lets case 4 cross-jump into case 5's call.
 */
int EVENT_SHORTCUT_MENU_ReturnEvent(struct GameEvent *event, u32 *seq, ShortcutMenuWork *work)
{
    ShortcutAvailMask avail;
    u32 availBit;
    u32 isUnknownId;
    u32 shortcutId;
    int result;
    int hasAvailBit;
    int blocked;
    int noEligibleMon;
    u32 nextIndex;
    struct GameEvent *child;

    switch (*seq) {
    case 0:
        shortcutId = func_0200C464(func_0200C404(GAME_DATA_GetSaveControl(func_020120F4(work->gameSystem))), 0);
        blocked = 0;
        result = EVENT_SHORTCUT_MENU_ResolveShortcut(work->link, shortcutId);
        noEligibleMon = 0;
        hasAvailBit = EVENT_SHORTCUT_MENU_GetAvailBit(shortcutId, &availBit, &isUnknownId);
        if (isUnknownId == 0 && func_02012B70(func_020120F4(work->gameSystem)) == 1) {
            blocked = 1;
        } else if (hasAvailBit == 1) {
            func_02164480(&avail, work->gameSystem, work->fieldMap);
            if (func_02028754(&avail, availBit) == 0)
                blocked = 1;
        }
        if (shortcutId == 9 && EVENT_SHORTCUT_MENU_CheckPartyRibbon(work) == 0)
            noEligibleMon = 1;
        if (blocked == 1) {
            *seq = 5;
        } else if (noEligibleMon == 1) {
            *seq = 7;
        } else {
            switch (result) {
            case 0:
                *seq = 2;
                break;
            case 1:
                *seq = 4;
                break;
            }
        }
        break;
    case 1:
        func_020307B0(work->link);
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    case 2:
        if (EVENT_SHORTCUT_MENU_CloseLink(work, seq) != 0) {
            GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_CreateProcEvent(work->link, work->id));
            *seq = 3;
        }
        break;
    case 3:
        result = work->link->result;
        if (result == 0) {
            *seq = 1;
        } else if (result == 1) {
            *seq = 1;
        } else if (result == 3) {
            *seq = 4;
        }
        break;
    case 4:
        nextIndex = work->link->nextEvent;
        func_020307B0(work->link);
        work->link = 0;
        child = EVENTDATA_SYSTEM_CreateFieldLinkEvent(nextIndex, work->gameSystem, work->fieldMap);
        GAME_EVENT_CallEvent(event, child);
        *seq = 6;
        break;
    case 5:
        nextIndex = work->link->nextEvent;
        func_020307B0(work->link);
        work->link = 0;
        if (nextIndex == 0) {
            if (func_02012B28(func_020127A4(func_020120F4(work->gameSystem))) == 1)
                child = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 1);
            else
                child = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 0);
        } else {
            child = EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 0);
        }
        GAME_EVENT_CallEvent(event, child);
        *seq = 6;
        break;
    case 6:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    case 7:
        func_020307B0(work->link);
        work->link = 0;
        GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_OpenMessage(work->gameSystem, 2));
        *seq = 8;
        break;
    case 8:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    }
    return 0;
}


/*
 * Unlabelled (inside EVENT_SHORTCUT_MENU_ReturnEvent's listing extent): maps a registered
 * shortcut id (0..24) to the proc table entry and argument the link should
 * run (procIndex/procArg), or to an event index in nextEvent (returning 1
 * for those, which launch a separate event instead of a proc).
 */
int EVENT_SHORTCUT_MENU_ResolveShortcut(ShortcutLink *link, u32 shortcutId)
{
    switch (shortcutId) {
    case 0:
        link->nextEvent = 0;
        return 1;
    case 1:
        link->procIndex = 7;
        return 0;
    case 2:
        link->procIndex = 11;
        return 0;
    case 3:
        link->procIndex = 8;
        return 0;
    case 4:
        link->nextEvent = 4;
        return 1;
    case 5:
        link->nextEvent = 5;
        return 1;
    case 6:
        link->procIndex = 0;
        link->procArg = 5;
        return 0;
    case 7:
        link->procIndex = 6;
        link->procArg = 0;
        return 0;
    case 8:
        link->procIndex = 6;
        link->procArg = 1;
        return 0;
    case 9:
        link->procIndex = 6;
        link->procArg = 2;
        return 0;
    case 10:
        link->procIndex = 2;
        link->procArg = 0;
        return 0;
    case 11:
        link->procIndex = 2;
        link->procArg = 1;
        return 0;
    case 12:
        link->procIndex = 2;
        link->procArg = 2;
        return 0;
    case 13:
        link->procIndex = 2;
        link->procArg = 3;
        return 0;
    case 14:
        link->procIndex = 2;
        link->procArg = 4;
        return 0;
    case 15:
        link->procIndex = 1;
        link->procArg = 1;
        return 0;
    case 16:
        link->procIndex = 1;
        link->procArg = 6;
        return 0;
    case 17:
        link->procIndex = 1;
        link->procArg = 2;
        return 0;
    case 18:
        link->procIndex = 1;
        link->procArg = 3;
        return 0;
    case 19:
        link->procIndex = 1;
        link->procArg = 4;
        return 0;
    case 20:
        link->procIndex = 1;
        link->procArg = 5;
        return 0;
    case 21:
        link->procIndex = 3;
        link->procArg = 1;
        return 0;
    case 22:
        link->procIndex = 3;
        link->procArg = 2;
        return 0;
    case 23:
        link->procIndex = 3;
        link->procArg = 3;
        return 0;
    case 24:
        link->procIndex = 5;
        return 0;
    }
    link->procIndex = 1;
    return 0;
}


/*
 * Unlabelled (inside EVENT_SHORTCUT_MENU_ReturnEvent's listing extent): translates a
 * shortcut id into the index of its bit in the availability mask; *isUnknownId
 * is set for ids above 6. Returns 0 when the id has no bit to test.
 */
int EVENT_SHORTCUT_MENU_GetAvailBit(u32 shortcutId, u32 *availBit, u32 *isUnknownId)
{
    *isUnknownId = 0;
    switch (shortcutId) {
    case 0:
        *availBit = 0;
        return 1;
    case 1:
        *availBit = 1;
        return 1;
    case 2:
        *availBit = 6;
        return 1;
    case 3:
        *availBit = 2;
        return 1;
    case 4:
        *availBit = 5;
        return 1;
    case 5:
        *availBit = 9;
        return 1;
    case 6:
        return 0;
    }
    *isUnknownId = 1;
    return 0;
}


/*
 * Opens the link session object (once) in the given mode: leaves the
 * current comm state, then creates the session from the player's name.
 */
void EVENT_SHORTCUT_MENU_OpenLink(int mode, ShortcutMenuWork *work)
{
    struct GameData *gameData;
    void *fieldComm;

    if (work->commObj == 0 && work->commClosed == 0) {
        func_02040588(1, 0);
        fieldComm = FIELDMAP_GetMsgBg(work->fieldMap);
        if (fieldComm != 0)
            FIELD_MSGBG_ReleaseBg(fieldComm);
        gameData = func_020120F4(work->gameSystem);
        work->commObj = SHORTCUT_MENU_Create(gameData, mode, GAME_DATA_GetRtcWork(gameData), 0x50, 0x15);
    }
}


/*
 * unblocked: SHORTCUT_MENU_Delete is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 92 bytes against 90 compiled: the unlabelled follower.
 *
 * Close sequence of the link session, one step per call (steps in
 * commCloseState); returns 1 when the session is closed.
 */
int EVENT_SHORTCUT_MENU_CloseLink(ShortcutMenuWork *work, u32 *seq)
{
    if (work->commClosed == 0) {
        switch (work->commCloseState) {
        case 0:
            if (work->commObj != 0) {
                func_02040588(1, 0);
                SHORTCUT_MENU_Delete(work->commObj);
                work->commObj = 0;
                work->commCloseState = 1;
                break;
            }
            work->commCloseState = 2;
            break;
        case 1:
            FIELD_MSGBG_SetupBgSingle(FIELDMAP_GetMsgBg(work->fieldMap));
            work->commCloseState = 2;
            break;
        case 2:
            work->commCloseState = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


/*
 * Resume hook: reopens the link session when shortcuts remain, and
 * returns 1 once the session is ready again (0 while it is opening).
 */
int EVENT_SHORTCUT_MENU_ResumeLinkHook(ShortcutLink *link, ShortcutMenuWork *work)
{
    ShortcutList *shortcuts;

    shortcuts = func_0200C404(GAME_DATA_GetSaveControl(func_020120F4(work->gameSystem)));
    switch (work->commCloseState) {
    case 0:
        if (func_0200C468(shortcuts) == 0) {
            work->commClosed = 1;
            work->commCloseState = 2;
        } else if (link->result - 1 <= 2) {
            work->commCloseState = 2;
        } else {
            EVENT_SHORTCUT_MENU_OpenLink(1, work);
            work->commCloseState = 1;
        }
        break;
    case 1:
        if (SHORTCUT_MENU_RunPrint(work->commObj) != 0) {
            work->commCloseState = 2;
        }
        break;
    case 2:
        work->commCloseState = 0;
        return 1;
    }
    return 0;
}


/*
 * Suspend hook: closes the link session. Unlabelled thunk that
 * tail-calls EVENT_SHORTCUT_MENU_CloseLink with the work as both arguments.
 */
int EVENT_SHORTCUT_MENU_SuspendLinkHook(ShortcutLink *link, ShortcutMenuWork *work)
{
    return EVENT_SHORTCUT_MENU_CloseLink(work, (u32 *)work);
}


/*
 * Opens a message window (message 0x7D6) and selects the variant given
 * by messageIndex.
 */
void *EVENT_SHORTCUT_MENU_OpenMessage(struct GameSystem *gameSystem, u32 messageIndex)
{
    void *msgWindow;

    msgWindow = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0x7D6, 0, 0x15);
    SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork(msgWindow), messageIndex, 0, 0, 0);
    return msgWindow;
}


/*
 * TRUE when some party member has field 0xA9 set and passes POKE_TOOL_HasRibbonData.
 */
int EVENT_SHORTCUT_MENU_CheckPartyRibbon(ShortcutMenuWork *work)
{
    void *party;
    void *mon;
    int i;

    party = func_02012934(func_020120F4(work->gameSystem));
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0 && POKE_TOOL_HasRibbonData(mon) != 0)
            return 1;
    }
    return 0;
}


/*
 * Creates the 0x74-byte task that runs EVENT_SHORTCUT_MENU_ProcEventMain and initialises it
 * from the link.
 */
struct GameEvent *EVENT_SHORTCUT_MENU_CreateProcEvent(ShortcutLink *link, u16 id)
{
    struct GameEvent *event;
    ShortcutProcTask *task;

    event = func_020122C0(link->gameSystem, link->event, EVENT_SHORTCUT_MENU_ProcEventMain, sizeof(ShortcutProcTask));
    task = func_020124E8(event);
    MI_CpuFill8(task, 0, sizeof(ShortcutProcTask));
    task->id = id;
    task->link = link;
    task->procResult = 4;
    task->event = event;
    task->proc = link->procIndex;
    task->prevProc = link->procIndex;
    task->nextProc = link->procIndex;
    task->cursorIndex = 0;
    task->scrollOffset = 0;
    task->selectedItem = 0;
    EVENT_SHORTCUT_MENU_InitHooks(&task->hooks, task->link, task->link->onResume, task->link->onSuspend, task->link->onExit, task->link->hookArg);
    func_02164480(&task->avail, task->link->gameSystem, task->link->fieldMap);
    MOVE_POKEMON_InitSkillInfo(task->link->fieldMap, &task->fieldInfo);
    return event;
}


/*
 * The fourteen-state task EVENT_SHORTCUT_MENU_CreateProcEvent creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 */
int EVENT_SHORTCUT_MENU_ProcEventMain(struct GameEvent *event, u32 *seq, ShortcutProcTask *task)
{
    u32 result;
    void *procWork;

    switch (*seq) {
    case 0:
        *seq = 1;
        break;
    case 1:
        result = task->procResult;
        if (result <= 1) {
            *seq = 2;
        } else if (result == 4) {
            if (d_021712CC[task->proc].start == 0)
                *seq = 6;
            else
                *seq = 3;
        } else if (result == 3) {
            task->link->result = 3;
            *seq = 2;
        } else if (result == 2) {
            task->link->result = 2;
            *seq = 2;
        }
        break;
    case 2:
        result = task->procResult;
        if (result == 0)
            task->link->result = 0;
        else if (result == 1)
            task->link->result = 1;
        return 1;
    case 3:
        if (EVENT_SHORTCUT_MENU_CallSuspendHook(&task->hooks) == 0)
            break;
        d_021712CC[task->proc].start(task, task->link->procArg);
        *seq = 4;
        break;
    case 4:
        *seq = 5;
        break;
    case 5:
        if (task->procResult == 0) {
            if (EVENT_SHORTCUT_MENU_CallResumeHook(&task->hooks) == 0)
                break;
            *seq = 1;
        } else {
            *seq = 1;
        }
        break;
    case 6:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(task->link->gameSystem, task->link->fieldMap, 0, 0));
        *seq = 7;
        break;
    case 7:
        if (EVENT_SHORTCUT_MENU_CallSuspendHook(&task->hooks) == 0)
            break;
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(task->link->gameSystem, task->link->fieldMap));
        *seq = 11;
        break;
    case 8:
        EVENT_SHORTCUT_MENU_CallExitHook(&task->hooks);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(task->link->gameSystem));
        *seq = 9;
        break;
    case 9:
        task->link->fieldMap = func_0201210C(task->link->gameSystem);
        FIELDMAP_SetBgMode();
        FIELDMAP_ResetBgAffineShowMsg(task->link->fieldMap);
        *seq = 10;
        break;
    case 10:
        if (EVENT_SHORTCUT_MENU_CallResumeHook(&task->hooks) == 0)
            break;
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(task->link->gameSystem, task->link->fieldMap, 0, 0, 0, 0, 0));
        *seq = 1;
        break;
    case 11:
        procWork = d_021712CC[task->proc].init(task, task->link->procArg, task->prevProc, task->procWork);
        if (task->procWork != 0) {
            d_021712CC[task->prevProc].exit(task->procWork);
            task->procWork = 0;
        }
        task->procWork = procWork;
        if (d_021712CC[task->proc].procTemplate == 0)
            break;
        GAMESYSTEM_CallProc(task->link->gameSystem, d_021712CC[task->proc].overlayId, d_021712CC[task->proc].procTemplate, procWork);
        *seq = 12;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(task->link->gameSystem) != 0)
            break;
        *seq = 13;
        break;
    case 13:
        task->procResult = d_021712CC[task->proc].finish(task, task->procWork);
        result = task->procResult;
        if (result == 0)
            task->link->result = 0;
        else if (result == 1)
            task->link->result = 1;
        else if (result == 3)
            task->link->result = 3;
        else if (result == 2)
            task->link->result = 2;
        if (task->procResult == 4) {
            task->prevProc = task->proc;
            task->proc = task->nextProc;
            *seq = 11;
        } else {
            if (task->procWork != 0) {
                func_020307B0(task->procWork);
                task->procWork = 0;
            }
            *seq = 8;
        }
        break;
    }
    return 0;
}


/*
 * Clears a hook table and fills it from the five arguments (the stores
 * run in this order in the original).
 */
void EVENT_SHORTCUT_MENU_InitHooks(ShortcutHooks *hooks, ShortcutLink *link, ShortcutHook onResume, ShortcutHook onSuspend, ShortcutHook onExit, struct ShortcutMenuWork *arg)
{
    MI_CpuFill8(hooks, 0, sizeof(ShortcutHooks));
    hooks->onResume = onResume;
    hooks->onExit = onExit;
    hooks->onSuspend = onSuspend;
    hooks->arg = arg;
    hooks->link = link;
}


/*
 * Runs the onResume hook, or returns 1 when the hook is empty.
 */
int EVENT_SHORTCUT_MENU_CallResumeHook(ShortcutHooks *hooks)
{
    if (hooks->onResume != 0)
        return hooks->onResume(hooks->link, hooks->arg);
    return 1;
}


/*
 * Runs the onSuspend hook, or returns 1 when the hook is empty.
 */
int EVENT_SHORTCUT_MENU_CallSuspendHook(ShortcutHooks *hooks)
{
    if (hooks->onSuspend != 0)
        return hooks->onSuspend(hooks->link, hooks->arg);
    return 1;
}


/*
 * Runs the onExit hook, or returns 1 when the hook is empty.
 */
int EVENT_SHORTCUT_MENU_CallExitHook(ShortcutHooks *hooks)
{
    if (hooks->onExit != 0)
        return hooks->onExit(hooks->link, hooks->arg);
    return 1;
}
