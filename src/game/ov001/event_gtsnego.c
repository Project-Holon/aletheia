/*
 * file:     event_gtsnego.c
 * unit:     yes
 * function: EVENT_GTSNEGO_Main, EVENT_GTSNEGO_InitWork, EVENT_GTSNEGO_Create
 * address:  0x021542C0
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   func_02012138  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov115_id       0x00000073  data   a1
 *   ov120_id       0x00000078  data   a1
 *   ov119_id       0x00000077  data   a1
 *   ov195_id       0x000000C3  data   a1
 *   gNetSaveMainProc     0x021D6338  data   ov115  a4
 *   gNetSaveRetryProc     0x021D654C  data   ov115  a4
 *   d_021D890C     0x021D890C  data   ov120  a4
 *   d_021E759C     0x021E759C  data   ov119  a4
 *   d_02208C40     0x02208C40  data   ov195  a4
 *   d_021546A0     0x021546A0  data   ov001  a4
 *   func_020124E8   0x020124E8  thumb
 *   GAME_COMM_RequestExitNoCallback   0x02026400  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   MYSTATUS_GetSize   0x02008468  thumb
 *   func_02012944   0x02012944  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_020122C0  0x020122C0  thumb
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct FieldMap;
struct GameComm;
struct NetHandle;
struct Party;
struct MyStatus;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* Request read by the evolution demo overlay (ov195). */
typedef struct EvolutionRequest {
    struct GameData *gameData;
    struct Party *party;
    u16 partyIndex;
    u8  reserved;
    u8  evolveCondition;
    u32 fromTrade;
    u32 reserved2;
} EvolutionRequest;

/* Parameter block read by the WiFi login overlay (ov115), 0x28 bytes. */
typedef struct WifiLoginParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
    u32 result;
    u32 reserved[2];
} WifiLoginParam;

/* Short parameter block of the second ov115 call (session confirm), 0x1C bytes. */
typedef struct WifiConfirmParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
} WifiConfirmParam;

/* Parameter block read by the GTS negotiation screen (ov120), 0x1B4 bytes. */
typedef struct GtsDispParam {
    struct GameData *gameData;
    u8 reserved[0x10];
    struct MyStatus *myStatusCopy;
    struct MyStatus *partnerStatusCopy;
    u8 reserved2[0x194];
    u32 result;
} GtsDispParam;

/* Parameter block read by the trade screen (ov119), 0x30 bytes. */
typedef struct GtsTradeParam {
    u32 reserved[2];
    u32 result;
    u32 partyIndex;
    u32 evolveCondition;
    struct GameData *gameData;
    GtsDispParam *dispParam;
    struct Party *party;
    EvolutionRequest *evolutionRequest;
    u8 *loginSaveData;
    u32 reserved2[2];
} GtsTradeParam;

/* Work of the GTS negotiation event (0x3B4 bytes). */
typedef struct GtsNegoEventWork {
    u32 savedBgmNo;
    int timeoutFrames;
    u8 loginSaveData[0x174];
    struct GameSystem *gameSystem;
    u8 reserved[4];
    GtsDispParam dispParam;
    GtsTradeParam tradeParam;
    WifiLoginParam login;
    WifiConfirmParam confirm;
    struct Party *tradedParty;
    u32 startMode;
} GtsNegoEventWork;

extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern u32 GAME_COMM_GetKind(void *gameComm);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int fieldMap);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent **newEvent);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern int   GFL_NET_GetRunState(void);
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void  GFL_NET_HANDLE_SetTimingSyncRange(struct NetHandle *handle, u32 rangeStart, u32 rangeEnd);
extern u32   GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, u32 rangeStart, u32 rangeEnd);
extern void GFL_NET_SetAutoExit(u8 enable);
extern void GFL_NET_SetLoginOption(u8 option);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020307B0(void *p);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
void *func_020124E8(struct GameEvent *event);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
struct Party *POKEPARTY_Create(u32 heapId);
void MI_CpuFill8(void *dst, int value, int size);
int MYSTATUS_GetSize(void);
u8 *func_02012944(void *gameData);
void MI_CpuCopy8(u32 src, void *dst, u32 size);
void *func_020122C0(void *gameSystem, void *a, void *callback, u32 workSize);
extern char ov115_id[];
extern char ov120_id[];
extern char ov119_id[];
extern char ov195_id[];
extern char gNetSaveMainProc[];
extern char gNetSaveRetryProc[];
extern char d_021D890C[];
extern char d_021E759C[];
extern char d_02208C40[];
extern char d_021546A0[];
u32 EVENT_GTSNEGO_Main(struct GameEvent *event, u32 *seq, GtsNegoEventWork *work);
void *EVENT_GTSNEGO_InitWork(void *event, void *gameSystem, int a, int startMode);
void *EVENT_GTSNEGO_Create(void *gameSystem, int a);


u32 EVENT_GTSNEGO_Main(struct GameEvent *event, u32 *seq, GtsNegoEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = func_020120F4(gameSystem);
    void *fieldMap = func_0201210C(gameSystem);
    EvolutionRequest *request;

    switch (*seq) {
    case 0:
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        (*seq)++;
        break;
    case 1:
        if (GAME_COMM_GetKind(func_02012138(gameSystem)) == 0) {
            GAME_EVENT_CallEvent(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)fieldMap));
            (*seq)++;
        }
        break;
    case 2:
        work->login.saveData = work->loginSaveData;
        work->login.messageId = 0x33;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov115_id, gNetSaveMainProc, &work->login);
        (*seq)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->login.result == 0)
                (*seq)++;
            else
                *seq = 14;
        }
        break;
    case 4:
        work->dispParam.result = 0;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov120_id, d_021D890C, &work->dispParam);
        (*seq)++;
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->dispParam.result == 1) {
                *seq = 12;
            } else if (work->dispParam.result == 0) {
                work->login.useSaveData = 1;
                *seq = 2;
            } else {
                work->tradeParam.result = 0;
                (*seq)++;
            }
        }
        break;
    case 6:
        work->tradeParam.gameData = gameData;
        work->tradeParam.dispParam = &work->dispParam;
        work->tradeParam.loginSaveData = work->loginSaveData;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov119_id, d_021E759C, &work->tradeParam);
        (*seq)++;
        break;
    case 7:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (GFL_NET_GetRunState() == 0) {
                work->login.useSaveData = 1;
                *seq = 2;
            } else if (work->tradeParam.result == 2) {
                *seq = 4;
            } else if (work->tradeParam.result == 1) {
                *seq = 10;
            } else {
                GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0xc);
                GFL_NET_SetAutoExit(0);
                GFL_NET_SetLoginOption(0);
                work->timeoutFrames = 100;
                *seq = 8;
            }
        }
        break;
    case 8:
        work->timeoutFrames--;
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0xc))
            *seq = 9;
        if (work->timeoutFrames < 0)
            *seq = 9;
        break;
    case 9:
        GFL_NET_STATE_WifiDisconnect(1);
        *seq = 4;
        break;
    case 10:
        request = func_02030734(4, 0x14, 0, d_021546A0, 0xcc);
        request->gameData = work->tradeParam.gameData;
        request->party = work->tradedParty;
        request->partyIndex = work->tradeParam.partyIndex;
        request->reserved = 0;
        request->evolveCondition = work->tradeParam.evolveCondition;
        request->fromTrade = 1;
        request->reserved2 = 0;
        work->tradeParam.evolutionRequest = request;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov195_id, d_02208C40, request);
        (*seq)++;
        break;
    case 11:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            func_020307B0(work->tradeParam.evolutionRequest);
            if (GFL_NET_GetRunState() == 0) {
                work->login.useSaveData = 1;
                *seq = 2;
            } else {
                work->tradeParam.result = 1;
                *seq = 6;
            }
        }
        break;
    case 12:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov115_id, gNetSaveRetryProc, &work->confirm);
        (*seq)++;
        break;
    case 13:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            (*seq)++;
        break;
    case 14:
        func_020307B0(work->dispParam.myStatusCopy);
        func_020307B0(work->dispParam.partnerStatusCopy);
        func_020307B0(work->tradedParty);
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 15:
        (*seq)++;
        break;
    case 16:
        return 1;
    }
    return 0;
}


/*
 * Builder: guard + allocator, then a straight slab/field layout.
 * Fills the event work: game system, party for traded Pokemon, status copies
 * for the negotiation screen and the two login parameter blocks.
 */
void *EVENT_GTSNEGO_InitWork(void *event, void *gameSystem, int a, int startMode)
{
    GtsNegoEventWork *work;

    if (GAME_COMM_GetKind(func_02012138(gameSystem)))
        GAME_COMM_RequestExitNoCallback(func_02012138(gameSystem));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->startMode = startMode;
    work->tradedParty = POKEPARTY_Create(4);
    work->tradeParam.party = work->tradedParty;
    MI_CpuFill8(&work->dispParam, 0, 0x1b4);
    work->dispParam.gameData = func_020120F4(gameSystem);
    work->dispParam.myStatusCopy = func_02030734(4, MYSTATUS_GetSize(), 1, d_021546A0, 0x123);
    work->dispParam.partnerStatusCopy = func_02030734(4, MYSTATUS_GetSize(), 1, d_021546A0, 0x124);
    MI_CpuCopy8((u32)func_02012944(func_020120F4(gameSystem)), work->dispParam.myStatusCopy, MYSTATUS_GetSize());
    MI_CpuFill8(&work->login, 0, 0x28);
    work->login.gameData = func_020120F4(gameSystem);
    work->login.loginType = 0;
    work->login.loginOption = 1;
    work->confirm.gameData = func_020120F4(gameSystem);
    work->confirm.loginType = 0;
    work->confirm.loginOption = 1;
    return work;
}


/*
 * Allocator call with a callback, then a two-argument tail setup; returns the
 * allocator result.
 */
void *EVENT_GTSNEGO_Create(void *gameSystem, int a)
{
    void *event = func_020122C0(gameSystem, 0, EVENT_GTSNEGO_Main, 0x3B4);
    EVENT_GTSNEGO_InitWork(event, gameSystem, a, 0);
    return event;
}
