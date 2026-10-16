/*
 * file:     move_pokemon.c
 * unit:     yes
 * function: MOVE_POKEMON_StartSkillOnTarget, MOVE_POKEMON_CheckWaterfall, MOVE_POKEMON_CheckFlash, MOVE_POKEMON_CreateFlashEvent, MOVE_POKEMON_FlashEventMain, MOVE_POKEMON_CheckDig, MOVE_POKEMON_CreateDigEvent, MOVE_POKEMON_DigEventMain, MOVE_POKEMON_CheckTeleport, MOVE_POKEMON_CreateTeleportEvent, MOVE_POKEMON_TeleportEventMain, MOVE_POKEMON_CheckMilkDrink, MOVE_POKEMON_CreateMilkDrinkEvent, MOVE_POKEMON_MilkDrinkEventMain, MOVE_POKEMON_CheckSweetScent, MOVE_POKEMON_StartSweetScent, MOVE_POKEMON_SweetScentEventMain, MOVE_POKEMON_CreateSweetScentEvent, MOVE_POKEMON_SoftBoiledEventMain, MOVE_POKEMON_CreateSoftBoiledEvent, MOVE_POKEMON_GetSkillCheckFunc, MOVE_POKEMON_GetSkillEventFunc, MOVE_POKEMON_InitSkillWork, MOVE_POKEMON_IsSkillUsable, MOVE_POKEMON_IsInSkillArea
 * address:  0x0215EC54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This is the tail of move_pokemon.c.  Its first part (from the anchor
 * 0x0215E440) lives in src/game/ov010/scrcmd_musical.c; merge the two
 * at cut time.
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   FLD_WIPE_3DOBJ_CreateMapChangeEvent  0x021C8268  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMapEff  0x02189A10  thumb  ov021
 *   FIELDSKILL_MAPEFF_GetFlash  0x021C7FBC  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   FIELD_FLASH_SetPendingCommand  0x021C7E50  thumb  ov021
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELD_STATUS_SetMapEffectMask  0x0201446C  thumb
 *   FIELD_FLASH_GetState  0x021C7E54  thumb  ov021
 *   EVENT_MAPCHANGE_CreateEscapeRopeEvent  0x02184EEC  thumb  ov020
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   EVENT_MAPCHANGE_CreateSituationWarpEvent  0x02184F40  thumb  ov020
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   EVENT_PERAP_RECORD_Create   0x021D1C24  thumb
 *   ZONEDATA_IsZoneInTableDFB8 0x02013FFC thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */
struct GameSystem;
struct GameData;
struct GameEvent;
struct FieldStatus;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { FALSE, TRUE } Bool;

/* Usability test input of a field skill check function. */
typedef struct FieldSkillCheck {
    u16 zoneId;         /* 0x00 */
    u16 usableMask;     /* 0x02: bit n set = skill n can be used here */
} FieldSkillCheck;

/* The Pokemon and its skill target, copied into the skill event work. */
typedef struct FieldSkillTarget {
    u16 partySlot;      /* 0x00 */
    u16 pad02;
    u32 targetParam;    /* 0x04 */
} FieldSkillTarget;

/* Caller context of a skill use or skill event create function. */
typedef struct FieldSkillContext {
    u8 pad00[8];
    struct GameSystem *gameSystem;  /* 0x08 */
    u32 fieldMap;                   /* 0x0C */
    u32 fieldPlayer;                /* 0x10 */
} FieldSkillContext;

/* The 20-byte work of every skill event (MOVE_POKEMON_InitSkillWork). */
typedef struct FieldSkillWork {
    u32 magic;                      /* 0x00: 0x19740205 */
    u32 fieldMap;                   /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    FieldSkillTarget target;        /* 0x0C */
} FieldSkillWork;

/* Inside test box of MOVE_POKEMON_IsInSkillArea: centre and half extents. */
typedef struct Area {
    u16 x;              /* 0x00 */
    u16 z;              /* 0x02 */
    u16 w;              /* 0x04 */
    u16 h;              /* 0x06 */
} Area;


extern int GAME_BEACON_SEARCH_SetCountValue(u32 seId);
extern int FLD_WIPE_3DOBJ_CreateMapChangeEvent(struct GameSystem *gameSystem, u32 fieldPlayer, u32 targetParam);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, void *func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern u32 GAME_DATA_GetEventWork(struct GameData *gameData);
extern struct FieldStatus *GAME_DATA_GetMoveModelSys(struct GameData *gameData);
extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern void *FIELDMAP_GetMapEff(void *fieldMap);
extern void *FIELDSKILL_MAPEFF_GetFlash(void *p);
extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern void *SCRIPT_SYS_CallScriptEvent(struct GameEvent *event, u32 msgId, u32 b, u32 c, u32 d);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
extern u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fieldStatus);
extern void FIELD_STATUS_SetFlashActive(struct FieldStatus *fieldStatus, u8 on);
extern void FIELD_FLASH_SetPendingCommand(void *mapEffect, u16 mode);
extern u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *fieldStatus);
extern void FIELD_STATUS_SetMapEffectMask(struct FieldStatus *fieldStatus, u32 mask);
extern u16 FIELD_FLASH_GetState(void *mapEffect);
extern struct GameEvent *EVENT_MAPCHANGE_CreateEscapeRopeEvent(struct GameSystem *gameSystem);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *next);
extern struct GameEvent *EVENT_MAPCHANGE_CreateSituationWarpEvent(struct GameSystem *gameSystem);
extern int SCRIPT_SYS_ChangeScriptEvent(int event, int msgId, int c, int d);
extern void EVENT_PERAP_RECORD_Create(struct GameSystem *gameSystem, u32 fieldPlayer, unsigned partySlot);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 zoneId);
extern void *FIELDMAP_GetGameSystem(void *field);
extern u32 ZONEDATA_CheckEventFlag(void *eventWork, int flag);


int MOVE_POKEMON_StartSkillOnTarget(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused);
int MOVE_POKEMON_CheckWaterfall(const FieldSkillCheck *check);
int MOVE_POKEMON_CheckFlash(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateFlashEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_FlashEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckDig(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateDigEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_DigEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckTeleport(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateTeleportEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_TeleportEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckMilkDrink(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateMilkDrinkEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_MilkDrinkEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckSweetScent(const FieldSkillCheck *check);
void MOVE_POKEMON_StartSweetScent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_SweetScentEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *MOVE_POKEMON_CreateSweetScentEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_SoftBoiledEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *MOVE_POKEMON_CreateSoftBoiledEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_GetSkillCheckFunc(const FieldSkillCheck *check, int skill);
int MOVE_POKEMON_GetSkillEventFunc(const FieldSkillCheck *check, int skill);
void MOVE_POKEMON_InitSkillWork(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_IsSkillUsable(const FieldSkillCheck *check, int skill);
int MOVE_POKEMON_IsInSkillArea(const Area *a, u16 x, u16 z, u32 flag, void *field);


/* Skill function tables, 11 rows of { create function, check function }:
 * d_021711FC for most zones, d_02171254 for the zones of the 02013FFC table.
 * d_02171200 and d_02171258 are the check columns of the two tables. */
extern int d_02171258[];
extern int d_02171200[];
extern int d_02171254[];
extern int d_021711FC[];


int MOVE_POKEMON_StartSkillOnTarget(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused)
{
    GAME_BEACON_SEARCH_SetCountValue(0x13);
    return FLD_WIPE_3DOBJ_CreateMapChangeEvent(ctx->gameSystem, ctx->fieldPlayer, target->targetParam);
}

int MOVE_POKEMON_CheckWaterfall(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 4) != 0 ? FALSE : TRUE;
}

int MOVE_POKEMON_CheckFlash(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 5) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateFlashEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_FlashEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

/*
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 */
int MOVE_POKEMON_FlashEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    struct GameData *gameData;
    struct FieldStatus *fieldStatus;
    void *mapEffect;
    u32 windowParam;
    void *msg;
    struct FieldStatus *status;
    u16 partySlot;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    GAME_DATA_GetEventWork(gameData);
    fieldStatus = GAME_DATA_GetMoveModelSys(gameData);
    mapEffect = FIELDSKILL_MAPEFF_GetFlash(FIELDMAP_GetMapEff(GAMESYSTEM_GetFieldMap(work->gameSystem)));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x2718, 0, 0, windowParam);
        SCRIPT_WORK_SetParams((int)msg, partySlot, 0, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_STATUS_IsFlashActive(fieldStatus) == 0) {
            status = GAME_DATA_GetMoveModelSys(gameData);
            FIELD_STATUS_SetFlashActive(fieldStatus, 1);
            GAME_BEACON_SEARCH_SetCountValue(0x94);
            FIELD_FLASH_SetPendingCommand(mapEffect, 1);
            FIELD_STATUS_SetMapEffectMask(status, (FIELD_STATUS_GetMapEffectMask(status) & ~1) | 2);
        } else {
            return 1;
        }
        (*seq)++;
        break;
    case 2:
        if (FIELD_FLASH_GetState(mapEffect) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}

int MOVE_POKEMON_CheckDig(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 7) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateDigEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    GAME_BEACON_SEARCH_SetCountValue(91);
    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_DigEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

int MOVE_POKEMON_DigEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)SCRIPT_SYS_CallScriptEvent(event, 0x271a, 0, 0, 0x15);
        SCRIPT_WORK_SetParams((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        GAME_EVENT_ChangeEvent(event, EVENT_MAPCHANGE_CreateEscapeRopeEvent(work->gameSystem));
        break;
    }
    return 0;
}

/*
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 */
int MOVE_POKEMON_CheckTeleport(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 6) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateTeleportEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    GAME_BEACON_SEARCH_SetCountValue(100);
    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_TeleportEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

int MOVE_POKEMON_TeleportEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)SCRIPT_SYS_CallScriptEvent(event, 0x2719, 0, 0, 0x15);
        SCRIPT_WORK_SetParams((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        GAME_EVENT_ChangeEvent(event, EVENT_MAPCHANGE_CreateSituationWarpEvent(work->gameSystem));
        break;
    }
    return 0;
}

int MOVE_POKEMON_CheckMilkDrink(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 10) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateMilkDrinkEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_MilkDrinkEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

/*
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 */
int MOVE_POKEMON_MilkDrinkEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    int partySlot;
    int msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    partySlot = work->target.partySlot;
    msg = SCRIPT_SYS_ChangeScriptEvent((int)event, 0x271c, 0, 0);
    SCRIPT_WORK_SetParams(msg, partySlot, 0, 0, 0);
    return 0;
}

int MOVE_POKEMON_CheckSweetScent(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 9) != 0 ? FALSE : TRUE;
}

/*
 * Play the skill sound, then hand the game system, the field player and
 * the party slot to the ov021 sweet scent start.
 */
void MOVE_POKEMON_StartSweetScent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    GAME_BEACON_SEARCH_SetCountValue(0x1C0);
    EVENT_PERAP_RECORD_Create(ctx->gameSystem, ctx->fieldPlayer, (u8)target->partySlot);
}

int MOVE_POKEMON_SweetScentEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x271e, 0, 0, windowParam);
        SCRIPT_WORK_SetParams((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        SCRIPT_SYS_ChangeScriptEvent((int)event, 0x28e3, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *MOVE_POKEMON_CreateSweetScentEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_SweetScentEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

int MOVE_POKEMON_SoftBoiledEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x271d, 0, 0, windowParam);
        SCRIPT_WORK_SetParams((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        SCRIPT_SYS_ChangeScriptEvent((int)event, 0x28e2, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *MOVE_POKEMON_CreateSoftBoiledEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_SoftBoiledEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(event), target, ctx);
    return event;
}

int MOVE_POKEMON_GetSkillCheckFunc(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (ZONEDATA_IsZoneInTableDFB8(check->zoneId)) return *(int *)((u32)d_02171258 + ((u32)skill << 3));
    return *(int *)((u32)d_02171200 + ((u32)skill << 3));
}

int MOVE_POKEMON_GetSkillEventFunc(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (ZONEDATA_IsZoneInTableDFB8(check->zoneId)) return *(int *)((u32)d_02171254 + ((u32)skill << 3));
    return *(int *)((u32)d_021711FC + ((u32)skill << 3));
}

void MOVE_POKEMON_InitSkillWork(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    work->magic = 0x19740205;
    work->fieldMap = ctx->fieldMap;
    work->target = *target;
    work->gameSystem = ctx->gameSystem;
}

int MOVE_POKEMON_IsSkillUsable(const FieldSkillCheck *check, int skill)
{
    if ((check->usableMask & (1 << skill)) != 0)
        return 1;
    return 0;
}

/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int MOVE_POKEMON_IsInSkillArea(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}
