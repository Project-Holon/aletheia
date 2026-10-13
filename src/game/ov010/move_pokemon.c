/*
 * file:     move_pokemon.c
 * unit:     yes
 * function: func_0215EC54, func_0215EC6C, func_0215EC80, func_0215EC94, func_0215ECBC, func_0215ED8C, func_0215EDA0, func_0215EDD0, func_0215EE24, func_0215EE38, func_0215EE68, func_0215EEBC, func_0215EED0, func_0215EEF8, func_0215EF2C, func_0215EF40, func_0215EF60, func_0215EFCC, func_0215EFF4, func_0215F060, func_0215F088, func_0215F0B8, func_0215F0E8, func_0215F104, func_0215F118
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
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C8268  0x021C8268  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A10  0x02189A10  thumb  ov021
 *   func_021C7FBC  0x021C7FBC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02014468  0x02014468  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   func_021C7E50  0x021C7E50  thumb  ov021
 *   func_02014470  0x02014470  thumb
 *   func_0201446C  0x0201446C  thumb
 *   func_021C7E54  0x021C7E54  thumb  ov021
 *   func_02184EEC  0x02184EEC  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 *   func_02184F40  0x02184F40  thumb  ov020
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_021D1C24   0x021D1C24  thumb
 *   func_02013FFC 0x02013FFC thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020142E8  0x020142E8  thumb
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


extern int func_02165534(u32 seId);
extern int func_021C8268(struct GameSystem *gameSystem, u32 fieldPlayer, u32 targetParam);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, void *func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern u32 func_0201296C(struct GameData *gameData);
extern struct FieldStatus *func_02012B38(struct GameData *gameData);
extern void *func_0201210C(struct GameSystem *gameSystem);
extern void *func_02189A10(void *fieldMap);
extern void *func_021C7FBC(void *p);
extern u16 func_02188C84(void *fieldMap);
extern void *func_02158780(struct GameEvent *event, u32 msgId, u32 b, u32 c, u32 d);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern u8 func_02014468(struct FieldStatus *fieldStatus);
extern void FIELD_STATUS_SetFlashActive(struct FieldStatus *fieldStatus, u8 on);
extern void func_021C7E50(void *mapEffect, u16 mode);
extern u16 func_02014470(struct FieldStatus *fieldStatus);
extern void func_0201446C(struct FieldStatus *fieldStatus, u32 mask);
extern u16 func_021C7E54(void *mapEffect);
extern struct GameEvent *func_02184EEC(struct GameSystem *gameSystem);
extern void func_0201235C(struct GameEvent *event, struct GameEvent *next);
extern struct GameEvent *func_02184F40(struct GameSystem *gameSystem);
extern int func_021587B0(int event, int msgId, int c, int d);
extern void func_021D1C24(struct GameSystem *gameSystem, u32 fieldPlayer, unsigned partySlot);
extern u32 func_02013FFC(u32 zoneId);
extern void *func_02188C80(void *field);
extern u32 func_020142E8(void *eventWork, int flag);


int func_0215EC54(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused);
int func_0215EC6C(const FieldSkillCheck *check);
int func_0215EC80(const FieldSkillCheck *check);
struct GameEvent *func_0215EC94(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215ECBC(struct GameEvent *event, int *seq, FieldSkillWork *work);
int func_0215ED8C(const FieldSkillCheck *check);
struct GameEvent *func_0215EDA0(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215EDD0(struct GameEvent *event, int *seq, FieldSkillWork *work);
int func_0215EE24(const FieldSkillCheck *check);
struct GameEvent *func_0215EE38(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215EE68(struct GameEvent *event, int *seq, FieldSkillWork *work);
int func_0215EEBC(const FieldSkillCheck *check);
struct GameEvent *func_0215EED0(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215EEF8(struct GameEvent *event, int *seq, FieldSkillWork *work);
int func_0215EF2C(const FieldSkillCheck *check);
void func_0215EF40(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215EF60(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *func_0215EFCC(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215EFF4(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *func_0215F060(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215F088(const FieldSkillCheck *check, int skill);
int func_0215F0B8(const FieldSkillCheck *check, int skill);
void func_0215F0E8(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx);
int func_0215F104(const FieldSkillCheck *check, int skill);
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);


/* Skill function tables, 11 rows of { create function, check function }:
 * d_021711FC for most zones, d_02171254 for the zones of the 02013FFC table.
 * d_02171200 and d_02171258 are the check columns of the two tables. */
extern int d_02171258[];
extern int d_02171200[];
extern int d_02171254[];
extern int d_021711FC[];


int func_0215EC54(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused)
{
    func_02165534(0x13);
    return func_021C8268(ctx->gameSystem, ctx->fieldPlayer, target->targetParam);
}

int func_0215EC6C(const FieldSkillCheck *check)
{
    return func_0215F104(check, 4) != 0 ? FALSE : TRUE;
}

int func_0215EC80(const FieldSkillCheck *check)
{
    return func_0215F104(check, 5) != 0 ? FALSE : TRUE;
}

struct GameEvent *func_0215EC94(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215ECBC, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

/*
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 */
int func_0215ECBC(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    struct GameData *gameData;
    struct FieldStatus *fieldStatus;
    void *mapEffect;
    u32 windowParam;
    void *msg;
    struct FieldStatus *status;
    u16 partySlot;

    gameData = func_020120F4(work->gameSystem);
    func_0201296C(gameData);
    fieldStatus = func_02012B38(gameData);
    mapEffect = func_021C7FBC(func_02189A10(func_0201210C(work->gameSystem)));
    windowParam = func_02188C84(func_0201210C(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = func_02158780(event, 0x2718, 0, 0, windowParam);
        func_02159058((int)msg, partySlot, 0, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (func_02014468(fieldStatus) == 0) {
            status = func_02012B38(gameData);
            FIELD_STATUS_SetFlashActive(fieldStatus, 1);
            func_02165534(0x94);
            func_021C7E50(mapEffect, 1);
            func_0201446C(status, (func_02014470(status) & ~1) | 2);
        } else {
            return 1;
        }
        (*seq)++;
        break;
    case 2:
        if (func_021C7E54(mapEffect) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}

int func_0215ED8C(const FieldSkillCheck *check)
{
    return func_0215F104(check, 7) != 0 ? FALSE : TRUE;
}

struct GameEvent *func_0215EDA0(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    func_02165534(91);
    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215EDD0, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

int func_0215EDD0(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)func_02158780(event, 0x271a, 0, 0, 0x15);
        func_02159058((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        func_0201235C(event, func_02184EEC(work->gameSystem));
        break;
    }
    return 0;
}

/*
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 */
int func_0215EE24(const FieldSkillCheck *check)
{
    return func_0215F104(check, 6) != 0 ? FALSE : TRUE;
}

struct GameEvent *func_0215EE38(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    func_02165534(100);
    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215EE68, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

int func_0215EE68(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)func_02158780(event, 0x2719, 0, 0, 0x15);
        func_02159058((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        func_0201235C(event, func_02184F40(work->gameSystem));
        break;
    }
    return 0;
}

int func_0215EEBC(const FieldSkillCheck *check)
{
    return func_0215F104(check, 10) != 0 ? FALSE : TRUE;
}

struct GameEvent *func_0215EED0(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215EEF8, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

/*
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 */
int func_0215EEF8(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    int partySlot;
    int msg;

    func_0201296C(func_020120F4(work->gameSystem));
    partySlot = work->target.partySlot;
    msg = func_021587B0((int)event, 0x271c, 0, 0);
    func_02159058(msg, partySlot, 0, 0, 0);
    return 0;
}

int func_0215EF2C(const FieldSkillCheck *check)
{
    return func_0215F104(check, 9) != 0 ? FALSE : TRUE;
}

/*
 * Play the skill sound, then hand the game system, the field player and
 * the party slot to the ov021 sweet scent start.
 */
void func_0215EF40(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    func_02165534(0x1C0);
    func_021D1C24(ctx->gameSystem, ctx->fieldPlayer, (u8)target->partySlot);
}

int func_0215EF60(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    func_0201296C(func_020120F4(work->gameSystem));
    windowParam = func_02188C84(func_0201210C(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = func_02158780(event, 0x271e, 0, 0, windowParam);
        func_02159058((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        func_021587B0((int)event, 0x28e3, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *func_0215EFCC(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215EF60, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

int func_0215EFF4(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    func_0201296C(func_020120F4(work->gameSystem));
    windowParam = func_02188C84(func_0201210C(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = func_02158780(event, 0x271d, 0, 0, windowParam);
        func_02159058((int)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        func_021587B0((int)event, 0x28e2, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *func_0215F060(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = func_020122C0(ctx->gameSystem, 0, (void *)func_0215EFF4, 20);
    func_0215F0E8(func_020124E8(event), target, ctx);
    return event;
}

int func_0215F088(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (func_02013FFC(check->zoneId)) return *(int *)((u32)d_02171258 + ((u32)skill << 3));
    return *(int *)((u32)d_02171200 + ((u32)skill << 3));
}

int func_0215F0B8(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (func_02013FFC(check->zoneId)) return *(int *)((u32)d_02171254 + ((u32)skill << 3));
    return *(int *)((u32)d_021711FC + ((u32)skill << 3));
}

void func_0215F0E8(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    work->magic = 0x19740205;
    work->fieldMap = ctx->fieldMap;
    work->target = *target;
    work->gameSystem = ctx->gameSystem;
}

int func_0215F104(const FieldSkillCheck *check, int skill)
{
    if ((check->usableMask & (1 << skill)) != 0)
        return 1;
    return 0;
}

/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (func_020142E8((void *)func_0201296C(func_020120F4(func_02188C80(field))), flag) != 0)
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
