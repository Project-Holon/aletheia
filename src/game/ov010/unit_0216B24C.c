/*
 * file:     unit_0216B24C.c
 * unit:     yes
 * function: func_0216B24C, func_0216B280, func_0216B2E4, func_0216B340, func_0216B3A8, func_0216B3EC, func_0216B504, func_0216B538, func_0216B578, func_0216B5AC, func_0216B60C, func_0216B63C, func_0216B6DC, func_0216B720, func_0216B7B0, func_0216B7F8, func_0216B81C, func_0216B86C, func_0216B8B8, func_0216B91C, func_0216B970, func_0216B994, func_0216B9D8, func_0216BA08, func_0216BA40, func_0216BA88, func_0216BAE8, func_0216BB18, func_0216BB70, func_0216BB80, func_0216BB90, func_0216BBB4, func_0216BBC4, func_0216BBD4, func_0216BC88, func_0216BCE4, func_0216BD1C, func_0216BD54, func_0216BE20, func_0216BEC0
 * address:  0x0216B24C
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
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SendValueNow  0x02176850  thumb  ov011
 *   INTRUDE_COMM_IsRecordReceived  0x02176870  thumb  ov011
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021665D0  0x021665D0  thumb  ov010
 *   GAME_DATA_SetSymbolMapFlag  0x02012FA4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C22C  0x0200C22C  thumb
 *   GAME_BEACON_SetResearchTeamRank  0x02027138  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   d_0217219C     0x0217219C  data  ov010  a1
 *   d_021721BC     0x021721BC  data  ov010  a1
 *   func_0200E3A0  0x0200E3A0  thumb
 *   func_0200E3E8  0x0200E3E8  thumb
 *   GAME_BEACON_SetQuestionnaire  0x02027100  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021670F8  0x021670F8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200C34C 0x0200C34C thumb
 *   func_0200C37C  0x0200C37C  thumb
 *   func_020891E0  0x020891E0  arm
 *   d_021723BC 0x021723BC data a1
 *   d_021723BD 0x021723BD data a1
 *   d_021723BE 0x021723BE data a1
 *   d_021723BF 0x021723BF data a1
 *   d_021723C0 0x021723C0 data a1
 *   d_021723C1 0x021723C1 data a1
 *   d_021723C2 0x021723C2 data a1
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F39B8  0x021F39B8  thumb  ov045
 *   func_021F3AA0  0x021F3AA0  thumb  ov059
 *   func_021F3B68 0x021F3B68 thumb ov059
 *   func_021F3B40 0x021F3B40 thumb ov059
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202F630  0x0202F630  thumb
 */
struct GameSystem;
struct GameData;
struct GameEvent;
struct SaveControl;
struct BeaconSave;
struct ScriptContext;
struct ScrCmdWork;
struct RTCDate;
struct RTCTime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct { int x, y, z; } FxVec3;

typedef struct { u32 year, month, day, week; } RTCDateFields;
typedef struct { u32 hour, minute, second; } RTCTimeFields;

/* Work of the intrude request event: the word to report into and the request. */
typedef struct {
    u16 *result;        /* 0x00 */
    u8 requestType;     /* 0x04 */
    u8 padding[3];
} IntrudeRequestWork;

/* Work of the symbol entry event (0x24 bytes). */
typedef struct {
    u16 *result;        /* 0x00 */
    u16 tileId;         /* 0x04 */
    u8 padding06[2];
    FxVec3 position;    /* 0x08 */
    u16 edge;           /* 0x14 */
    u8 cellId;          /* 0x16 */
    u8 padding17;
    u16 accepted;       /* 0x18 */
    u8 padding1A[2];
    u32 playSe;         /* 0x1C */
    u32 solo;           /* 0x20 */
} SymbolEntryWork;

extern void *func_020120F4(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(void *owner, void *parent, void *proc, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern void func_02082BCC(void *dest, int value, int size);
extern void *func_020124E4(struct GameEvent *event);
extern void *func_02012138(const struct GameSystem *gameSystem);
extern u8 *func_02158344(void *gameComm);
extern int INTRUDE_COMM_SendValueNow(u8 *intrudeComm, u8 requestType);
extern u32 INTRUDE_COMM_IsRecordReceived(u8 *intrudeComm);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *gameComm, void *gameData);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern void *func_02188CB4(void *fieldMap);
extern void *func_021A3074(void *player);
extern void *func_0216D888(void *player);
extern void *func_02188C7C(void *fieldMap);
extern void func_0216D9A0(void *mmdlSys);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern void func_020061E4(u32 seNo);
extern void *func_021BE8D4(void *gameSystem, void *fieldMap, u32 a, u32 b);
extern int func_021665D0(int gameSystem, int cellId);
extern void GAME_DATA_SetSymbolMapFlag(void *gameData, unsigned char cellId);
extern void *func_021854B0(void *gameSystem, void *fieldMap, u32 tileId, void *position, u32 edge);
extern int func_0219C630(void *mmdlSys);
extern void *func_021BE92C(void *gameSystem, void *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 *func_0216D9E4(void *mmdlSys);
extern void *func_0215A5F4(struct ScrCmdWork *work);
extern void *func_0215A5E4(struct ScrCmdWork *work);
extern void *func_02012EBC(struct GameData *gameData);
extern struct BeaconSave *func_0200C0F0(void *saveControl);
extern u16 *func_02159AE8(struct ScriptContext *ctx, struct ScrCmdWork *work);
extern u8 func_0200C224(struct BeaconSave *beacon);
extern int func_0200C22C();
extern int GAME_BEACON_SetResearchTeamRank();
extern u8 func_0200C32C(struct BeaconSave *beacon);
extern int func_0200C33C(struct BeaconSave *beacon, u32 index);
extern void *func_0200E394(void *saveControl);
extern unsigned int func_02159B10(struct ScriptContext *ctx, struct ScrCmdWork *work);
extern void func_0200C334(struct BeaconSave *beacon, u8 missionIndex);
extern void func_0200C344(struct BeaconSave *beacon, u8 slot, u8 targetId);
extern void func_0200C358(struct BeaconSave *beacon, u32 slot, int value);
extern u64 func_0203F524();
extern void func_0200C384(struct BeaconSave *beacon, u32 lo, u32 hi);
extern int func_0200E4F8(int tally, int category, int entry);
extern u32 func_0200E4B0(u8 *tally, u32 category, u32 entry);
extern void *func_0200E3A0(void *survey);
extern void func_0200E3E8(u8 *answers, int questionId, u32 answer);
extern void GAME_BEACON_SetQuestionnaire(const void *answers);
extern void *func_0215A5DC(struct ScrCmdWork *work);
extern void *func_021670F8(void *gameSystem);
extern int func_0215897C(void *scriptSystem, void *event);
extern void *func_0200C0E8(void *saveControl);
extern u16 func_0200E458(const u16 *tally, int id);
extern u32 func_0200E47C(u8 *tally, int id);
extern u16 func_0200C34C(struct BeaconSave *beacon, u32 slot);
extern unsigned long long func_0200C37C(struct BeaconSave *beacon);
extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);
extern void func_021A3038(void *player, FxVec3 *out);
extern void *func_021F39B8(void *gameSystem, int fromPlayer, FxVec3 *from, FxVec3 *to, int height, int frames);
extern void func_021F3AA0(void *gameSystem, int mode, FxVec3 *position);
extern void *func_021F3B68(void *gameSystem, u32 value);
extern void *func_021F3B40(void *gameSystem, u32 value);
extern void *func_02012934(const struct GameData *gameData);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *party, u32 index);
extern int func_0202F488(void *mon, int kind);
extern u32 func_02017E1C(void *mon, u32 paramId, u32 arg);
extern void func_0202F630(void *mon, u32 kind);
extern u8 d_0217219C[];
extern u8 d_021721BC[];
extern const u8 d_021723BC[];
extern const u8 d_021723BD[];
extern const u8 d_021723BE[], d_021723BF[], d_021723C0[];
extern const u8 d_021723C1[];
extern const u8 d_021723C2[];

int func_0216B280(struct GameEvent *event, int *state, IntrudeRequestWork *work);
void func_0216B2E4(FxVec3 *src, int edge, FxVec3 *dst);
struct GameEvent *func_0216B340(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId);
int func_0216B3EC(struct GameEvent *event, u32 *state, SymbolEntryWork *work);
int func_0216B8B8(void *saveControl, u16 *status);
int func_0216B91C(void *saveControl, int missionIndex, u16 *status);
u32 func_0216B970(const u16 *tally, int id);
int func_0216B994(const u16 *tally, int missionIndex);
int func_0216B9D8(void *saveControl);
int func_0216BA08(void *saveControl);
int func_0216BA40(const u16 *tally, int missionIndex);
u16 func_0216BA88(void *saveControl);
u16 func_0216BAE8(void *saveControl);
int func_0216BB18(void *saveControl);
int func_0216BB70(int missionIndex);
int func_0216BB80(int missionIndex);
void func_0216BB90(int missionIndex, u8 *targetIds);
int func_0216BBB4(int missionIndex);
int func_0216BBC4(int missionIndex);
int func_0216BE20(void *party, int species, int move, int kind, u16 *outIndex);

/* Starts the intrude request event: sends requestType and reports 0 or 1 into *result. */
struct GameEvent *func_0216B24C(struct GameSystem *gameSystem, u16 *result, int requestType)
{
    struct GameEvent *event;
    IntrudeRequestWork *work;
    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_0216B280, 8);
    work = func_020124E8(event);
    func_02082BCC(work, 0, 8);
    work->result = result;
    work->requestType = requestType;
    return event;
}

int func_0216B280(struct GameEvent *event, int *state, IntrudeRequestWork *work)
{
    u8 *intrudeComm;
    u16 *result;

    intrudeComm = func_02158344(func_02012138(func_020124E4(event)));
    if (intrudeComm == 0) {
        result = work->result;
        if (result != 0)
            *result = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_COMM_SendValueNow(intrudeComm, work->requestType) == 1)
            (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_IsRecordReceived(intrudeComm) == 1)
            (*state)++;
        break;
    case 2:
        result = work->result;
        if (result != 0)
            *result = 1;
        return 1;
    }
    return 0;
}

/*
 * Copies a 12-byte position, then moves one component to the map border
 * named by edge 0-3 (edges 4-9 keep it as copied).
 */
void func_0216B2E4(FxVec3 *src, int edge, FxVec3 *dst)
{
    *dst = *src;
    switch (edge) {
    case 0:
        dst->z = 0x62 << 14;
        break;
    case 1:
        dst->z = 0x26 << 14;
        break;
    case 2:
        dst->x = 0x6A << 14;
        break;
    case 3:
        dst->x = 0x16 << 14;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

struct GameEvent *func_0216B340(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId)
{
    void *gameData;
    struct GameEvent *event;
    SymbolEntryWork *work;

    gameData = func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_0216B3EC, 0x24);
    work = func_020124E8(event);
    func_02082BCC(work, 0, 0x24);
    work->position = *position;
    work->edge = edge;
    work->result = 0;
    work->cellId = cellId;
    work->playSe = playSe;
    if (INTRUDE_COMM_GetPartnerSlot(func_02012138(gameSystem), gameData) == 4)
        work->solo = 1;
    return event;
}

struct GameEvent *func_0216B3A8(struct GameSystem *gameSystem, int edge, int cellId)
{
    FxVec3 position;
    void *fieldMap;

    fieldMap = func_0201210C(gameSystem);
    func_020120F4(gameSystem);
    func_0216B2E4(func_0216D888(func_021A3074(func_02188CB4(fieldMap))), edge, &position);
    return func_0216B340(gameSystem, edge != 9, &position, edge, cellId);
}

/*
 * Seven-state proc of the symbol entry: ask the intrude partner (unless
 * playing solo), fade out, show the symbol cell's tile, fade back in, and
 * write 0 or 1 to the caller's result word.
 */
int func_0216B3EC(struct GameEvent *event, u32 *state, SymbolEntryWork *work)
{
    void *gameSystem = func_020124E4(event);
    void *gameData;
    void *fieldMap;

    func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(fieldMap));
        if (work->solo == 1) {
            *state = 2;
        } else {
            func_02012374(event, func_0216B24C(gameSystem, &work->accepted, work->cellId));
            (*state)++;
        }
        break;
    case 1:
        if (work->accepted == 0) {
            if (work->result != 0)
                *work->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (work->playSe != 0)
            func_020061E4(1369);
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 9, 0));
        (*state)++;
        break;
    case 3:
        work->tileId = func_021665D0((int)gameSystem, work->cellId);
        GAME_DATA_SetSymbolMapFlag(gameData, work->cellId);
        func_02012374(event, func_021854B0(gameSystem, fieldMap, work->tileId, &work->position, work->edge));
        (*state)++;
        break;
    case 4:
        if (func_0219C630(func_02188C7C(func_0201210C(gameSystem))) == 1)
            break;
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (work->result != 0)
            *work->result = 1;
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(fieldMap));
        return 1;
    }
    return 0;
}

/* Script command: writes the research team rank to a work variable. */
int func_0216B504(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    struct BeaconSave *beacon;
    u16 *dst;

    func_0215A5F4(scrWork);
    gameData = func_0215A5E4(scrWork);
    saveControl = func_02012EBC(gameData);
    beacon = func_0200C0F0(saveControl);
    dst = func_02159AE8(ctx, scrWork);
    *dst = func_0200C224(beacon);
    return 0;
}

/* Script command: raises the research team rank by one (up to 5). */
int func_0216B538(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    struct BeaconSave *beacon;
    int rank;

    func_0215A5F4(scrWork);
    gameData = func_0215A5E4(scrWork);
    beacon = func_0200C0F0(func_02012EBC(gameData));
    rank = func_0200C224(beacon);
    if (rank >= 5)
        return 0;
    func_0200C22C(beacon, rank + 1);
    GAME_BEACON_SetResearchTeamRank((u8)(rank + 1));
    return 0;
}

/* Script command: writes the current mission index to a work variable. */
int func_0216B578(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    struct BeaconSave *beacon;
    u16 *dst;

    func_0215A5F4(scrWork);
    gameData = func_0215A5E4(scrWork);
    saveControl = func_02012EBC(gameData);
    beacon = func_0200C0F0(saveControl);
    dst = func_02159AE8(ctx, scrWork);
    *dst = func_0200C32C(beacon);
    return 0;
}

/* Script command: writes the three mission target ids to three work variables. */
int func_0216B5AC(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct BeaconSave *beacon;
    u16 *dst0;
    u16 *dst1;
    u16 *dst2;

    func_0215A5F4(scrWork);
    beacon = func_0200C0F0(func_02012EBC(func_0215A5E4(scrWork)));
    dst0 = func_02159AE8(ctx, scrWork);
    dst1 = func_02159AE8(ctx, scrWork);
    dst2 = func_02159AE8(ctx, scrWork);
    *dst0 = func_0200C33C(beacon, 0);
    *dst1 = func_0200C33C(beacon, 1);
    *dst2 = func_0200C33C(beacon, 2);
    return 0;
}

/* Script command: writes the hours elapsed since the mission started (at most 24). */
int func_0216B60C(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    u16 *dst;

    func_0215A5F4(scrWork);
    gameData = func_0215A5E4(scrWork);
    saveControl = func_02012EBC(gameData);
    dst = func_02159AE8(ctx, scrWork);
    *dst = func_0216BB18(saveControl);
    return 0;
}

/* Script command: starts a mission (index and three target ids), zeroes the progress and stamps the time. */
int func_0216B63C(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct BeaconSave *beacon;
    u16 targetId[3];
    int i;
    void *saveControl;
    int missionIndex;
    int zero;
    u64 now;

    func_0215A5F4(scrWork);
    saveControl = func_02012EBC(func_0215A5E4(scrWork));
    beacon = func_0200C0F0(saveControl);
    func_0200E394(saveControl);
    missionIndex = func_02159B10(ctx, scrWork);
    targetId[0] = func_02159B10(ctx, scrWork);
    targetId[1] = func_02159B10(ctx, scrWork);
    targetId[2] = func_02159B10(ctx, scrWork);
    func_0200C334(beacon, missionIndex);
    zero = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(beacon, i, targetId[i]);
        func_0200C358(beacon, (u8)i, zero);
    }
    now = func_0203F524();
    func_0200C384(beacon, (u32)now, (u32)(now >> 32));
    return zero;
}

/* Script command: clears the mission (index 0, target ids 0xFF). */
int func_0216B6DC(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *saveControl;
    struct BeaconSave *beacon;
    int i;

    func_0215A5F4(scrWork);
    saveControl = func_02012EBC(func_0215A5E4(scrWork));
    beacon = func_0200C0F0(saveControl);
    func_0200E394(saveControl);
    func_0200C334(beacon, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(beacon, (u8)i, 0xFF);
    return 0;
}

/* Script command: writes the id of the entry with the highest tally (both counters summed) in a category. */
int func_0216B720(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    int i;
    int category;
    void *tally;
    int best;
    u16 *dst;
    int entryId;
    int entryCount;

    func_0215A5F4(scrWork);
    tally = func_0200E394(func_02012EBC(func_0215A5E4(scrWork)));
    category = func_02159B10(ctx, scrWork);
    dst = func_02159AE8(ctx, scrWork);
    entryCount = d_0217219C[category];
    best = -1;
    for (i = 0; i < entryCount; i++) {
        int countA = func_0200E4F8((int)tally, category, i + 1);
        int countB = func_0200E4B0(tally, category, i + 1);
        int score = countA + countB;
        if (best < score) {
            best = score;
            entryId = d_021721BC[category * 17 + i];
        }
    }
    *dst = entryId;
    return 0;
}

/* Script command: stores one answer of the survey. */
int func_0216B7B0(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *answers;
    int questionId;
    int answer;

    func_0215A5F4(scrWork);
    answers = func_0200E3A0(func_0200E394(func_02012EBC(func_0215A5E4(scrWork))));
    questionId = func_02159B10(ctx, scrWork);
    answer = func_02159B10(ctx, scrWork);
    func_0200E3E8(answers, (u8)questionId, answer);
    GAME_BEACON_SetQuestionnaire(answers);
    return 0;
}

/* Script command: starts the research report event. */
int func_0216B7F8(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem;
    void *gameSystem;
    void *reportEvent;

    scriptSystem = func_0215A5F4(scrWork);
    gameSystem = func_0215A5DC(scrWork);
    reportEvent = func_021670F8(gameSystem);
    func_0215897C(scriptSystem, reportEvent);
    return 1;
}

/* Script command: writes the status of a mission (current one or another by index). */
int func_0216B81C(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *saveControl;
    void *beacon;
    int missionIndex;
    u16 *dst;

    saveControl = func_02012EBC(func_0215A5E4(scrWork));
    beacon = func_0200C0E8(saveControl);
    missionIndex = (u8)func_02159B10(ctx, scrWork);
    dst = func_02159AE8(ctx, scrWork);
    if (missionIndex == func_0200C32C(beacon)) {
        func_0216B8B8(saveControl, dst);
    } else {
        func_0216B91C(saveControl, missionIndex, dst);
    }
    return 0;
}

/* Script command: writes the progress of the current mission (shortfall or hours left, by kind). */
int func_0216B86C(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    u16 *dst;
    void *saveControl;
    void *beacon;
    int progress;
    u8 kind;

    saveControl = func_02012EBC(func_0215A5E4(scrWork));
    beacon = func_0200C0E8(saveControl);
    dst = func_02159AE8(ctx, scrWork);
    kind = func_0216BB70(func_0200C32C(beacon));
    if (kind != 0) {
        if (kind == 1) {
            progress = func_0216BAE8(saveControl);
        }
    } else {
        progress = func_0216BA88(saveControl);
    }
    *dst = progress;
    return 0;
}

/* Status of the current mission: 1 done, 2 not yet (kind 0), 3 running, 4 failed (kind 1). */
int func_0216B8B8(void *saveControl, u16 *status)
{
    const u16 *tally;
    void *beacon;
    int missionIndex;
    int kind;

    tally = func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    kind = (u8)func_0216BB70(missionIndex);
    if (kind == 0) {
        if (func_0216B994(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (func_0216B9D8(saveControl) != 0) {
            if (func_0216BA08(saveControl) != 0) {
                *status = 1;
                return 1;
            }
            *status = 4;
            return 4;
        }
        *status = 3;
        return 3;
    }
    return kind;
}

/* Status of the mission given by index (kind 0: 1 done, 2 not yet; kind 1: 1 done, 3 running). */
int func_0216B91C(void *saveControl, int missionIndex, u16 *status)
{
    const u16 *tally;
    int kind;

    tally = func_0200E394(saveControl);
    func_0200C0E8(saveControl);
    kind = (u8)func_0216BB70(missionIndex);
    if (kind == 0) {
        if (func_0216B994(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (func_0216BA40(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 3;
        return 3;
    }
    return kind;
}

/* Tally of an id: both counters summed, capped at 999999. */
u32 func_0216B970(const u16 *tally, int id)
{
    u32 total = func_0200E458(tally, id);
    total += func_0200E47C((u8 *)tally, id);
    if (total > 999999) total = 999999;
    return total;
}

/* 1 when every target of the mission reached its goal. */
int func_0216B994(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;
    u32 goal;

    func_0216BB90(missionIndex, targetId);
    targetCount = (u8)func_0216BB80(missionIndex);
    goal = func_0216BBB4(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (func_0216B970(tally, targetId[i]) < goal) {
            return 0;
        }
    }
    return 1;
}

/* 1 when the time limit of the current mission is used up. */
int func_0216B9D8(void *saveControl)
{
    int missionIndex;
    int elapsedHours;
    void *beacon;

    func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    elapsedHours = func_0216BB18(saveControl);
    if (func_0216BBC4((u8)missionIndex) > elapsedHours)
        return 0;
    return 1;
}

/* 1 when every target slot of the current mission holds a recorded value. */
int func_0216BA08(void *saveControl)
{
    void *beacon;
    int i, targetCount;
    beacon = func_0200C0E8(saveControl);
    targetCount = (u8)func_0216BB80(func_0200C32C(beacon));
    for (i = 0; i < targetCount; i++) {
        if (func_0200C34C(beacon, (u8)i) == 0) return 0;
    }
    return 1;
}

/* 1 when every target of the mission is at the cap of 999999. */
int func_0216BA40(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;

    func_0216BB90(missionIndex, targetId);
    targetCount = (u8)func_0216BB80(missionIndex);
    func_0216BBB4(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (func_0216B970(tally, targetId[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}

/* Goal minus the smallest target tally of the current mission. */
u16 func_0216BA88(void *saveControl)
{
    int i;
    u8 targetId[4];
    int targetCount;
    u32 goal;
    u32 smallest;
    void *tally;
    int missionIndex;

    tally = func_0200E394(saveControl);
    missionIndex = func_0200C32C(func_0200C0E8(saveControl));
    goal = func_0216BBB4(missionIndex);
    targetCount = (u8)func_0216BB80(missionIndex);
    func_0216BB90(missionIndex, targetId);
    smallest = 1009998;
    for (i = 0; i < targetCount; i++) {
        u32 value = func_0216B970(tally, targetId[i]);
        if (value < smallest) {
            smallest = value;
        }
    }
    return goal - smallest;
}

/*
 * Hours left of the current mission (0 when used up).
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: this caller loads saveControl into r0 at 0216BAFC and
 * func_0216BB18 forwards entry r0 to 0200C0F0; preserve that input.
 */
u16 func_0216BAE8(void *saveControl)
{
    int missionIndex, elapsedHours, hoursLeft;
    func_0200E394(saveControl);
    missionIndex = func_0200C32C(func_0200C0E8(saveControl));
    elapsedHours = func_0216BB18(saveControl);
    hoursLeft = (int)((u32)func_0216BBC4((u8)missionIndex) - (u32)elapsedHours);
    if (hoursLeft < 0) hoursLeft = 0;
    return (u16)hoursLeft;
}

/* Hours since the mission started, 24 when a day or more passed, 0 when no mission runs. */
int func_0216BB18(void *saveControl)
{
    struct {
        RTCTimeFields time;
        RTCDateFields date;
    } elapsed;
    struct BeaconSave *beacon;
    u64 startTime;

    beacon = func_0200C0F0(saveControl);
    if (func_0200C32C(beacon) == 0) {
        return 0;
    }
    startTime = func_0200C37C(beacon);
    func_020891E0((struct RTCDate *)&elapsed.date, (struct RTCTime *)&elapsed.time, func_0203F524() - startTime);
    if (elapsed.date.year != 0 || elapsed.date.month > 1 || elapsed.date.day > 1) {
        return 24;
    }
    return (u16)elapsed.time.hour;
}

/*
 * The mission table is an array of 7-byte records: kind, target count,
 * three target ids, goal, time limit in hours (one symbol per field).
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 */
int func_0216BB70(int missionIndex)
{
    return *(const u8 *)((u32)d_021723BC + (u32)missionIndex * 7u);
}

int func_0216BB80(int missionIndex)
{
    return *(const u8 *)((u32)d_021723BD + (u32)missionIndex * 7u);
}

/*
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 */
void func_0216BB90(int missionIndex, u8 *targetIds)
{
    targetIds[0] = *(const u8 *)((u32)d_021723BE + (u32)missionIndex * 7u);
    targetIds[1] = *(const u8 *)((u32)d_021723BF + (u32)missionIndex * 7u);
    targetIds[2] = *(const u8 *)((u32)d_021723C0 + (u32)missionIndex * 7u);
}

int func_0216BBB4(int missionIndex)
{
    return *(const u8 *)((u32)d_021723C1 + (u32)missionIndex * 7u);
}

int func_0216BBC4(int missionIndex)
{
    return *(const u8 *)((u32)d_021723C2 + (u32)missionIndex * 7u);
}

/* Script command: starts a special Pokemon gimmick task between the player and a grid position. */
int func_0216BBD4(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem;
    void *gameSystem;
    void *fieldMap;
    int fromPlayer;
    int gridX;
    int height;
    int gridZ;
    int speed;
    int frames;
    FxVec3 playerPos;
    FxVec3 targetPos;
    FxVec3 *from;
    FxVec3 *to;
    void *gimmickTask;

    scriptSystem = func_0215A5F4(scrWork);
    gameSystem = func_0215A5DC(scrWork);
    fieldMap = func_0201210C(gameSystem);
    fromPlayer = func_02159B10(ctx, scrWork);
    gridX = func_02159B10(ctx, scrWork);
    height = func_02159B10(ctx, scrWork);
    gridZ = func_02159B10(ctx, scrWork);
    speed = func_02159B10(ctx, scrWork);
    frames = func_02159B10(ctx, scrWork);
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    targetPos.x = (gridX << 16) + 0x8000;
    targetPos.y = height << 15;
    targetPos.z = (gridZ << 16) + 0x8000;
    if (fromPlayer == 0) {
        from = &playerPos;
        to = &targetPos;
    } else {
        from = &targetPos;
        to = &playerPos;
    }
    gimmickTask = func_021F39B8(gameSystem, fromPlayer, from, to, speed << 15, frames);
    if (gimmickTask == 0) {
        return 1;
    }
    func_0215897C(scriptSystem, gimmickTask);
    return 1;
}

/* Script command: moves the special Pokemon gimmick to a grid position. */
int func_0216BC88(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *gameSystem;
    int mode;
    int gridX;
    int height;
    int gridZ;
    FxVec3 position;

    gameSystem = func_0215A5DC(scrWork);
    mode = func_02159B10(ctx, scrWork);
    gridX = func_02159B10(ctx, scrWork);
    height = func_02159B10(ctx, scrWork);
    gridZ = func_02159B10(ctx, scrWork);
    position.x = (gridX << 16) + 0x8000;
    position.y = height << 15;
    position.z = (gridZ << 16) + 0x8000;
    func_021F3AA0(gameSystem, mode, &position);
    return 0;
}

/* Script command: starts the first special Pokemon gimmick step task and waits on it. */
int func_0216BCE4(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = func_0215A5F4(scrWork);
    gameSystem = func_0215A5DC(scrWork);
    task = func_021F3B68(gameSystem, func_02159B10(ctx, scrWork));
    if (task == 0) return 1;
    func_0215897C(scriptSystem, task);
    return 1;
}

/* Script command: starts the second special Pokemon gimmick step task and waits on it. */
int func_0216BD1C(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = func_0215A5F4(scrWork);
    gameSystem = func_0215A5DC(scrWork);
    task = func_021F3B40(gameSystem, func_02159B10(ctx, scrWork));
    if (task == 0) return 1;
    func_0215897C(scriptSystem, task);
    return 1;
}

/*
 * Script command: reads a species, a signature-move flag and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a flag
 * kind and, for 647/648, a signature move (548/547, dropped when the flag
 * is 0), and stores func_0216BE20's answer in the second variable; any other
 * species stores 0.
 */
int func_0216BD54(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party = func_02012934(func_0215A5E4(scrWork));
    int species = func_02159B10(ctx, scrWork);
    unsigned int useSignatureMove = func_02159B10(ctx, scrWork);
    u16 *outIndex = func_02159AE8(ctx, scrWork);
    u16 *outFound = func_02159AE8(ctx, scrWork);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *outFound = 0;
        return 0;
    }
    if (useSignatureMove == 0) {
        move = 0;
    }
    *outFound = func_0216BE20(party, species, move, kind, outIndex);
    return 0;
}

/* Finds the first party member of the species that has the event flag and does not know the move. */
int func_0216BE20(void *party, int species, int move, int kind, u16 *outIndex)
{
    int found;
    int count;
    int i;
    void *mon;

    count = func_0201AA18(party);
    found = 0;
    *outIndex = 0;
    for (i = 0; i < count; i++) {
        mon = func_0201AB28(party, i);
        if (func_0202F488(mon, kind) == 0) {
            continue;
        }
        if (species != func_02017E1C(mon, 5, 0)) {
            continue;
        }
        if (move != 0) {
            if (move == func_02017E1C(mon, 0x36, 0)
                || move == func_02017E1C(mon, 0x37, 0)
                || move == func_02017E1C(mon, 0x38, 0)
                || move == func_02017E1C(mon, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *outIndex = i;
        break;
    }
    return found;
}

/* Script command: clears the event flag of the party member at an index when its species has one. */
int func_0216BEC0(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party;
    int species;
    int partyIndex;
    int kind;
    void *mon;

    party = func_02012934(func_0215A5E4(scrWork));
    species = func_02159B10(ctx, scrWork);
    partyIndex = func_02159B10(ctx, scrWork);
    switch (species) {
    case 0xFB:
        kind = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        kind = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    mon = func_0201AB28(party, partyIndex);
    if (func_0202F488(mon, kind) == 0) {
        return 0;
    }
    func_0202F630(mon, kind);
    return 0;
}
