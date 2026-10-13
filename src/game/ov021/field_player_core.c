/*
 * file:     field_player_core.c
 * unit:     yes
 * function: func_021A36E4, func_021A3810, func_021A3818, func_021A3898, func_021A38A4, func_021A3920, func_021A392C, func_021A3938, func_021A394C, func_021A395C, func_021A3960, func_021A3964, func_021A3968, func_021A396C, func_021A3970, func_021A3974, func_021A3980, func_021A398C, func_021A3990, func_021A3994, func_021A3998, func_021A39AC, func_021A39E4, func_021A3A10, func_021A3A20, func_021A3A3C, func_021A3AA0, func_021A3AB8, func_021A3AC4, func_021A3AD0, func_021A3AD4, func_021A3AD8, func_021A3B3C, func_021A3B78, func_021A3B94, func_021A3BB4, func_021A3C24, func_021A3C3C, func_021A3C54, func_021A3C6C, func_021A3C94, func_021A3CB0, func_021A3CC0, func_021A3CE8, func_021A3D08, func_021A3D50, func_021A3D6C, func_021A3DA0, func_021A3E14, func_021A3E48, func_021A3E54, func_021A3EE0, func_021A3F10, func_021A3F48, func_021A3F64, func_021A3F70, func_021A3F8C, func_021A3F98, func_021A3FB4, func_021A3FC0, func_021A3FDC, func_021A3FE8, func_021A408C, func_021A40A8, func_021A4114
 * address:  0x021A36E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A3804 (d_021DDEB8 "field_player_core.c"); 021A36E4 is the core constructor called by field_player.c 021A2E50.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02012B34  0x02012B34  thumb
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   d_021DDEB8     0x021DDEB8  data  a1
 *   d_021D89A0     0x021D89A0  data  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_02012B30  0x02012B30  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb
 *   func_02197C9C  0x02197C9C  thumb
 *   func_0219C648  0x0219C648  thumb
 *   func_020508EC  0x020508EC  arm
 *   func_0219D208  0x0219D208  thumb  ov021
 *   func_0216CD88  0x0216CD88  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   data_021D89C4  0x021D89C4  data  a4
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021D05D8  0x021D05D8  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_02164240  0x02164240  thumb  ov010
 *   func_0219F5C8  0x0219F5C8  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029D8C  0x02029D8C  thumb
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_021A31D0  0x021A31D0  thumb  ov021
 */
#include "field_player_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

/* Pad keys the avatar direction is read from, and the direction ids. */
#define FIELD_PLAYER_KEY_RIGHT 0x10
#define FIELD_PLAYER_KEY_LEFT  0x20
#define FIELD_PLAYER_KEY_UP    0x40
#define FIELD_PLAYER_KEY_DOWN  0x80
#define FIELD_PLAYER_DIR_UP    0
#define FIELD_PLAYER_DIR_DOWN  1
#define FIELD_PLAYER_DIR_LEFT  2
#define FIELD_PLAYER_DIR_RIGHT 3
#define FIELD_PLAYER_DIR_NONE  9

/* The form codes the player work stores (FieldPlayerFormEntry.formCode). */
#define FIELD_PLAYER_FORM_CODE_SURF 2
#define FIELD_PLAYER_FORM_CODE_DIVE 3

struct GameData;

extern u32 func_020307B0(void *work);
extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *pos);
extern u16 func_0216D5F8(const Mmdl *mmdl);
extern struct MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern void *func_0216DDC0(struct MmdlSys *mmdlSys, u32 gridX, u32 gridZ, u32 mask);
extern u16 func_0216D83C(const Mmdl *mmdl);
extern u16 func_0216D854(const Mmdl *mmdl);
extern u16 func_0216D86C(const Mmdl *mmdl);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct GameSystem *func_02188C80(FieldMap *fieldMap);
extern Mmdl *func_0216DE94(struct MmdlSys *mmdlSys, u32 objId);
extern u16 func_02012B34(const struct PlayerWork *playerWork);
extern Mmdl *func_0216CE60(struct MmdlSys *mmdlSys, const FieldPlayerMmdlHeader *header, int zoneId);
extern void func_0216D844(Mmdl *mmdl, s16 gridX);
extern void func_0216D85C(Mmdl *mmdl, int gridY);
extern void func_0216D874(Mmdl *mmdl, int gridZ);
extern void func_0216D89C(Mmdl *mmdl, const VecFx32 *pos);
extern void func_0216DB80(Mmdl *mmdl, u32 flag);
extern int func_0216D3CC(Mmdl *mmdl);
extern int func_0216D454(Mmdl *mmdl);
extern void func_0216D80C(Mmdl *mmdl, u16 gridX);
extern void func_0216D818(Mmdl *mmdl, u16 gridY);
extern void func_0216D824(Mmdl *mmdl, u16 gridZ);
extern u32 func_02012B30(struct PlayerWork *playerWork, u32 objCode);
extern u32 func_02012B28(const struct PlayerWork *playerWork);
extern void func_02012B2C(struct PlayerWork *playerWork, u32 formCode);
extern u16 func_0216D598(Mmdl *mmdl);
extern int func_0216D7A8(Mmdl *mmdl, u32 drawProcParam);
extern struct MmdlSys *func_0216D67C(Mmdl *mmdl);
extern u32 func_0216D520(struct MmdlSys *mmdlSys);
extern u32 func_0219C9DC(u32 blActCont);
extern int func_02197C9C(Mmdl *mmdl);
extern int func_0219C648(Mmdl *mmdl);
extern u32 func_020508EC(u32 bbActSys, int entryIndex, u16 *out);
extern void func_0219D208(Mmdl *mmdl, u32 objCode);
extern int func_0216CD88(struct MmdlSys *mmdlSys);
extern void func_0216E204(Mmdl *mmdl, u32 objCode);
extern u16 func_0216D608(Mmdl *mmdl);
extern void func_021AC154(u32 effect);
extern void func_0216D8E0(Mmdl *mmdl, const VecFx32 *offset);
extern u32 func_02188CD0(FieldMap *fieldMap);
extern u32 func_021ACB38(u32 fieldEffect, u32 dir, VecFx32 *pos, Mmdl *mmdl, int flag);
extern void func_021D05D8(Mmdl *mmdl, u32 fieldEffect);
extern void func_021ACBC8(u32 effect, int enabled);
extern void func_02164240(int dir, s16 *gridX, s16 *gridZ, s16 amount);
extern void func_0219F5C8(Mmdl *mmdl, int state);
extern u32 func_02012A30(struct GameData *gameData);
extern u16 func_02188C9C(FieldMap *fieldMap);
extern void func_02029D8C(u32 bgmId, struct GameData *gameData, u32 zoneId);

extern u16 func_021A3190(int sex, int formSlot);
extern int func_021A31A4(int sex, int formCode);
extern int func_021A31D0(u16 objCode);

extern FieldPlayerCore *func_021A36E4(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId);
void func_021A3810(FieldPlayerCore *core);
void func_021A3818(FieldPlayerCore *core);
void func_021A3898(FieldPlayerCore *core, VecFx32 *out);
void func_021A38A4(FieldPlayerCore *core, VecFx32 *pos);
u16 func_021A3920(FieldPlayerCore *core);
void func_021A392C(FieldPlayerCore *core, int dir);
int func_021A3938(FieldPlayerCore *core, u32 objCode);
void func_021A394C(FieldPlayerCore *core);
FieldMap *func_021A395C(FieldPlayerCore *core);
Mmdl *func_021A3960(FieldPlayerCore *core);
void func_021A3964(FieldPlayerCore *core, u32 stepKind);
u32 func_021A3968(FieldPlayerCore *core);
void func_021A396C(FieldPlayerCore *core, u32 stepPhase);
u32 func_021A3970(FieldPlayerCore *core);
u32 func_021A3974(FieldPlayerCore *core);
void func_021A3980(FieldPlayerCore *core, u32 formCode);
u32 func_021A398C(FieldPlayerCore *core);
struct GameSystem *func_021A3990(FieldPlayerCore *core);
struct PlayerWork *func_021A3994(FieldPlayerCore *core);
void func_021A3998(FieldPlayerCore *core);
void func_021A39AC(FieldPlayerCore *core, int formSlot);
int func_021A39E4(FieldPlayerCore *core);
int func_021A3A10(FieldPlayerCore *core);
int func_021A3A20(FieldPlayerCore *core);
int func_021A3A3C(FieldPlayerCore *core);
int func_021A3AA0(FieldPlayerCore *core);
u16 func_021A3AB8(FieldPlayerCore *core, u32 keys);
void func_021A3AC4(FieldPlayerCore *core, u32 keys);
void func_021A3AD0(FieldPlayerCore *core, u32 rideEffect);
u32 func_021A3AD4(FieldPlayerCore *core);
void func_021A3AD8(FieldPlayerCore *core, int objCode);
void func_021A3B3C(FieldPlayerCore *core, int formCode);
int func_021A3B78(FieldPlayerCore *core);
int func_021A3B94(FieldPlayerCore *core);
u16 func_021A3BB4(FieldPlayerCore *core, u32 keys);
void func_021A3C24(FieldPlayerCore *core, int keys);
int func_021A3C3C(u32 keys);
int func_021A3C54(u32 keys);
u16 func_021A3C6C(FieldPlayerCore *core, int formSlot);
int func_021A3C94(u32 mask);
FieldPlayerCore *func_021A3CB0(FieldPlayerCore *core, u32 mask);
int func_021A3CC0(FieldPlayerCore *core);
void func_021A3CE8(FieldPlayerCore *core);
int func_021A3D08(FieldPlayerCore *core, u32 objCode);
int func_021A3D50(FieldPlayerCore *core, u32 formSlot);
int func_021A3D6C(FieldPlayerCore *core, int formSlot);
void func_021A4114(FieldPlayerCore *core);

extern const char d_021DDEB8[];
extern FieldPlayerMmdlHeader d_021D89A0;
extern FieldPlayerFormStepFunc *const data_021D89C4[];

/*
 * Addresses are Black-image addresses.
 */
FieldPlayerCore *func_021A36E4(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId)
{
    FieldPlayerCore *core;
    struct MmdlSys *mmdlSys;
    int objCodeOverride;
    Mmdl *mmdl;

    core = func_02030734(heapId, 0x34, 1, d_021DDEB8, 0x97);
    core->playerWork = playerWork;
    core->fieldMap = fieldMap;
    core->gameSystem = func_02188C80(fieldMap);
    core->lastHorzDir = FIELD_PLAYER_DIR_NONE;
    core->lastVertDir = FIELD_PLAYER_DIR_NONE;
    mmdlSys = func_02188C7C(fieldMap);
    core->mmdl = func_0216DE94(mmdlSys, 0xff);
    core->sex = sex;
    objCodeOverride = func_02012B34(core->playerWork);
    mmdl = core->mmdl;
    if (mmdl == 0) {
        FieldPlayerMmdlHeader header = d_021D89A0;
        FieldPlayerGridPos *gridPos = &header.pos;

        gridPos->x = (pos->x >> 4) / 4096;
        gridPos->z = (pos->z >> 4) / 4096;
        gridPos->y = pos->y;
        if (objCodeOverride == 0xFFFF)
            header.objCode = func_021A31A4(sex, func_021A3974(core));
        else
            header.objCode = objCodeOverride;
        core->mmdl = func_0216CE60(mmdlSys, &header, 0);
    } else {
        int gridY;
        int gridZ;
        gridY = (pos->y >> 4) / 4096;
        gridZ = (pos->z >> 4) / 4096;
        func_0216D844(mmdl, (pos->x >> 4) / 4096);
        func_0216D85C(mmdl, (s16)gridY);
        func_0216D874(mmdl, (s16)gridZ);
        func_0216D89C(mmdl, pos);
        if (objCodeOverride == 0xFFFF)
            func_021A3998(core);
    }
    func_0216DB80(core->mmdl, 1);
    return core;
}

void func_021A3810(FieldPlayerCore *core)
{
    func_020307B0(core);
}

/* Moves the step phase on after a step: 1 and 2 are the two halves, 3 the end. */
void func_021A3818(FieldPlayerCore *core)
{
    Mmdl *mmdl = core->mmdl;
    u32 stepKind;
    u32 oldPhase = core->stepPhase;

    core->stepPhase = 0;
    stepKind = core->stepKind;
    if (func_0216D3CC(mmdl) == 0) {
        switch (stepKind) {
        case 0:
            break;
        case 1:
            if (oldPhase == 0 || oldPhase == 3)
                core->stepPhase = 1;
            else
                core->stepPhase = 2;
            break;
        case 2:
            core->stepPhase = 2;
            break;
        }
    } else if (func_0216D454(mmdl) == 1) {
        switch (stepKind) {
        case 0:
            break;
        case 1:
            if (oldPhase == 0)
                break;
            if (oldPhase == 3)
                core->stepPhase = 0;
            else
                core->stepPhase = 3;
            break;
        case 2:
            if (oldPhase == 0)
                break;
            if (oldPhase == 3)
                core->stepPhase = 0;
            else
                core->stepPhase = 3;
            break;
        }
    }
}

void func_021A3898(FieldPlayerCore *core, VecFx32 *out)
{
    func_0216D88C(core->mmdl, out);
}

void func_021A38A4(FieldPlayerCore *core, VecFx32 *pos)
{
    int gridX = (pos->x >> 4) / 4096;
    int gridY = (pos->y >> 4) / 4096;
    int gridZ = (pos->z >> 4) / 4096;
    Mmdl *mmdl = core->mmdl;

    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
    func_0216D844(mmdl, (short)gridX);
    func_0216D85C(mmdl, (short)gridY);
    func_0216D874(mmdl, (short)gridZ);
    func_0216D89C(mmdl, pos);
}

u16 func_021A3920(FieldPlayerCore *core)
{
    return func_0216D5F8(core->mmdl);
}

void func_021A392C(FieldPlayerCore *core, int dir)
{
    func_0216D5E0(core->mmdl, dir);
}

/* Changes the avatar model and remembers it in the player work. */
int func_021A3938(FieldPlayerCore *core, u32 objCode)
{
    func_021A3AD8(core, objCode);
    return func_02012B30(core->playerWork, objCode);
}

/* Forgets the remembered model (0xFFFF). */
void func_021A394C(FieldPlayerCore *core)
{
    func_02012B30(core->playerWork, 0xFFFF);
}

FieldMap *func_021A395C(FieldPlayerCore *core)
{
    return core->fieldMap;
}

Mmdl *func_021A3960(FieldPlayerCore *core)
{
    return core->mmdl;
}

void func_021A3964(FieldPlayerCore *core, u32 stepKind)
{
    core->stepKind = stepKind;
}

u32 func_021A3968(FieldPlayerCore *core)
{
    return core->stepKind;
}

void func_021A396C(FieldPlayerCore *core, u32 stepPhase)
{
    core->stepPhase = stepPhase;
}

u32 func_021A3970(FieldPlayerCore *core)
{
    return core->stepPhase;
}

u32 func_021A3974(FieldPlayerCore *core)
{
    return func_02012B28(core->playerWork);
}

void func_021A3980(FieldPlayerCore *core, u32 formCode)
{
    func_02012B2C(core->playerWork, formCode);
}

u32 func_021A398C(FieldPlayerCore *core)
{
    return core->sex;
}

struct GameSystem *func_021A3990(FieldPlayerCore *core)
{
    return core->gameSystem;
}

struct PlayerWork *func_021A3994(FieldPlayerCore *core)
{
    return core->playerWork;
}

/* Puts the avatar model of the stored form code on. */
void func_021A3998(FieldPlayerCore *core)
{
    func_021A3B3C(core, func_021A3974(core));
}

/* Puts the model of a form slot on without changing the stored form code. */
void func_021A39AC(FieldPlayerCore *core, int formSlot)
{
    u32 sex = func_021A398C(core);
    Mmdl *mmdl = func_021A3960(core);
    int objCode = func_021A3190(sex, formSlot);

    if (objCode != func_0216D598(mmdl))
        func_021A3AD8(core, objCode);
    core->animeWait = 0;
}

/* Waits one call after the model draw proc is ready; 1 when the wait is over. */
int func_021A39E4(FieldPlayerCore *core)
{
    if (func_0216D7A8(func_021A3960(core), 0) != 0xFFFF) {
        if (core->animeWait == 1)
            return 1;
        (core->animeWait)++;
    }
    return 0;
}

/* Form slot of the model the avatar has now. */
int func_021A3A10(FieldPlayerCore *core)
{
    return func_021A31D0(func_0216D598(func_021A3960(core)));
}

/* 1 when the avatar model belongs to a form slot. */
int func_021A3A20(FieldPlayerCore *core)
{
    if (func_021A31D0(func_0216D598(func_021A3960(core))) != FIELD_PLAYER_AVATAR_FORM_COUNT) {
        return 1;
    }
    return 0;
}

/* 1 when the avatar animation is paused on its last frame. */
int func_021A3A3C(FieldPlayerCore *core)
{
    u16 lastCommand;
    u32 bbActSys;
    u32 drawAnimeId;

    bbActSys = func_0219C9DC(func_0216D520(func_0216D67C(core->mmdl)));
    if (func_02197C9C(core->mmdl) == 1 && func_0219C648(core->mmdl) == 1)
        return 1;
    drawAnimeId = func_0216D7A8(core->mmdl, 0);
    if (drawAnimeId != 0xFFFF && func_020508EC(bbActSys, (u16)drawAnimeId, &lastCommand) != 0 && lastCommand == (0xFFFF >> 2))
        return 1;
    return 0;
}

int func_021A3AA0(FieldPlayerCore *core)
{
    if (func_0216D3CC(func_021A3960(core)) == 1) {
        return 1;
    }
    return 0;
}

/* Widens the keys to 16 bits before the call. */
u16 func_021A3AB8(FieldPlayerCore *core, u32 keys)
{
    return func_021A3BB4(core, (u16)keys);
}

void func_021A3AC4(FieldPlayerCore *core, u32 keys)
{
    func_021A3C24(core, (u16)keys);
}

void func_021A3AD0(FieldPlayerCore *core, u32 rideEffect)
{
    core->rideEffect = rideEffect;
}

u32 func_021A3AD4(FieldPlayerCore *core)
{
    return core->rideEffect;
}

/*
 * Changes the avatar model. A change from or to the plain hero or heroine
 * model is direct; any other change goes through the plain model first.
 */
void func_021A3AD8(FieldPlayerCore *core, int objCode)
{
    Mmdl *mmdl = func_021A3960(core);
    struct MmdlSys *mmdlSys = func_0216D67C(mmdl);
    int nowObjCode = func_0216D598(mmdl);

    if (objCode == FIELD_PLAYER_OBJ_CODE_HERO || objCode == FIELD_PLAYER_OBJ_CODE_HEROINE
        || nowObjCode == FIELD_PLAYER_OBJ_CODE_HERO || nowObjCode == FIELD_PLAYER_OBJ_CODE_HEROINE) {
        func_0219D208(mmdl, objCode);
        func_0216CD88(mmdlSys);
        return;
    }
    func_0216E204(mmdl, func_021A31A4(func_021A398C(core), FIELD_PLAYER_AVATAR_FORM_NORMAL));
    func_0216CD88(mmdlSys);
    func_0219D208(mmdl, objCode);
    func_0216CD88(mmdlSys);
}

/* Puts on the model of a form code and stores the code in the player work. */
void func_021A3B3C(FieldPlayerCore *core, int formCode)
{
    u32 sex = func_021A398C(core);
    Mmdl *mmdl = func_021A3960(core);
    int objCode = func_021A31A4(sex, formCode);

    if (objCode != func_0216D598(mmdl))
        func_021A3AD8(core, objCode);
    func_021A3980(core, formCode);
}

/* 1 while the avatar wears the plain hero or heroine model. */
int func_021A3B78(FieldPlayerCore *core)
{
    int objCode = func_0216D598(func_021A3960(core));

    if (objCode == FIELD_PLAYER_OBJ_CODE_HERO || objCode == FIELD_PLAYER_OBJ_CODE_HEROINE)
        return 1;
    return 0;
}

/* 1 when the model draw proc is ready. */
int func_021A3B94(FieldPlayerCore *core)
{
    int ready = 0;

    if ((u16)func_0216D7A8(core->mmdl, 0) != 0xFFFF)
        ready = 1;
    return ready;
}

/*
 * Picks the move direction from the pad keys when two directions are held:
 * the one that changed since the last call wins, and a held direction that
 * is the model's current direction is kept.
 */
u16 func_021A3BB4(FieldPlayerCore *core, u32 keys)
{
    u32 horzDir;
    u32 vertDir;
    u32 nowDir;
    u32 lastHorzDir;
    u32 lastVertDir;

    horzDir = func_021A3C3C(keys);
    vertDir = func_021A3C54(keys);
    if (horzDir == FIELD_PLAYER_DIR_NONE) {
        return vertDir;
    }
    if (vertDir == FIELD_PLAYER_DIR_NONE) {
        return horzDir;
    }
    nowDir = func_0216D608(func_021A3960(core));
    lastHorzDir = core->lastHorzDir;
    lastVertDir = core->lastVertDir;
    if (nowDir != FIELD_PLAYER_DIR_NONE) {
        if (horzDir == lastHorzDir && vertDir == lastVertDir) {
            if (vertDir == nowDir) {
                return vertDir;
            }
            if (horzDir == nowDir) {
                return horzDir;
            }
        }
        if (vertDir != lastVertDir) {
            return vertDir;
        }
        return horzDir;
    }
    return vertDir;
}

/* Stores the held directions for the next call of the direction choice. */
void func_021A3C24(FieldPlayerCore *core, int keys)
{
    core->lastHorzDir = func_021A3C3C(keys);
    core->lastVertDir = func_021A3C54(keys);
}

/* Left or right direction of the held keys, FIELD_PLAYER_DIR_NONE for none. */
int func_021A3C3C(u32 keys)
{
    if (keys & FIELD_PLAYER_KEY_LEFT) {
        return FIELD_PLAYER_DIR_LEFT;
    }
    if (keys & FIELD_PLAYER_KEY_RIGHT) {
        return FIELD_PLAYER_DIR_RIGHT;
    }
    return FIELD_PLAYER_DIR_NONE;
}

/* Up or down direction of the held keys, FIELD_PLAYER_DIR_NONE for none. */
int func_021A3C54(u32 keys)
{
    if (keys & FIELD_PLAYER_KEY_UP) {
        return FIELD_PLAYER_DIR_UP;
    }
    if (keys & FIELD_PLAYER_KEY_DOWN) {
        return FIELD_PLAYER_DIR_DOWN;
    }
    return FIELD_PLAYER_DIR_NONE;
}

/* Runs the steps of the sequence for a form slot until one stops or the change is done. */
u16 func_021A3C6C(FieldPlayerCore *core, int formSlot)
{
    FieldPlayerFormStepFunc *steps;

    if (core->formChangeDone == 0) {
        steps = data_021D89C4[formSlot];
        while (steps[core->formChangeStep](core) == 1)
            ;
    }
    return core->formChangeDone;
}

/* Index of the lowest set bit among the first FIELD_PLAYER_AVATAR_FORM_COUNT, else that count. */
int func_021A3C94(u32 mask)
{
    int slot = FIELD_PLAYER_AVATAR_FORM_COUNT;

    if (mask != 0) {
        for (slot = 0; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++) {
            if (mask & 1)
                break;
            mask >>= 1;
        }
    }
    return slot;
}

/* Starts a form change to the slots in mask. */
FieldPlayerCore *func_021A3CB0(FieldPlayerCore *core, u32 mask)
{
    core->formChangeMask = mask;
    core->formChangeStep = 0;
    core->formChangeDone = 0;
    core->animeWait = 0;
    core->formChangeCount = 0;
    return core;
}

/* Runs the form change one slot at a time; 1 when no slot is left or the slot is done. */
int func_021A3CC0(FieldPlayerCore *core)
{
    int formSlot = func_021A3C94(core->formChangeMask);

    if (formSlot >= FIELD_PLAYER_AVATAR_FORM_COUNT)
        return 1;
    if (func_021A3C6C(core, formSlot) == 1)
        return 1;
    return 0;
}

/* Runs the form change of the lowest requested slot to its end. */
void func_021A3CE8(FieldPlayerCore *core)
{
    int formSlot = func_021A3C94(core->formChangeMask);

    if (formSlot < FIELD_PLAYER_AVATAR_FORM_COUNT) {
        while (func_021A3C6C(core, formSlot) == 0)
            ;
    }
}

/* Changes to an object code; 1 when the change is done, 0 while it goes through the plain model. */
int func_021A3D08(FieldPlayerCore *core, u32 objCode)
{
    if (objCode == func_0216D598(func_021A3960(core))) {
        core->formChangeDone = 1;
        return 1;
    }
    if (func_021A3B78(core) == 1) {
        func_021A3AD8(core, objCode);
        core->formChangeDone = 1;
        return 1;
    }
    func_021A3AD8(core, func_021A3190(func_021A398C(core), 0));
    return 0;
}

int func_021A3D50(FieldPlayerCore *core, u32 formSlot)
{
    return func_021A3D08(core, func_021A3190(func_021A398C(core), formSlot));
}

/* Ends the change to a form slot once the model draw proc is ready. */
int func_021A3D6C(FieldPlayerCore *core, int formSlot)
{
    if (func_021A3B94(core) == 1) {
        core->formChangeCount++;
        func_021A3AD8(core, func_021A3190(func_021A398C(core), formSlot));
        core->formChangeDone = 1;
        return 1;
    }
    return 0;
}

/* Step of the sequence to the normal form: model, form code, no ride effect. */
int func_021A3DA0(FieldPlayerCore *core)
{
    VecFx32 zeroOffset = { 0, 0, 0 };
    u32 sex;
    Mmdl *mmdl;
    u32 rideEffect;

    sex = func_021A398C(core);
    mmdl = func_021A3960(core);
    sex = func_021A3190(sex, 0);
    if (sex != func_0216D598(mmdl)) {
        func_021A3AD8(core, sex);
    }
    func_021A3980(core, 0);
    func_021A4114(core);
    if ((rideEffect = func_021A3AD4(core)) != 0) {
        func_021AC154(rideEffect);
        func_021A3AD0(core, 0);
    }
    func_0216D8E0(mmdl, &zeroOffset);
    core->formChangeDone = 1;
    return 0;
}

int func_021A3E14(FieldPlayerCore *core)
{
    func_021A398C(core);
    func_021A3960(core);
    func_021A3980(core, 1);
    func_021A4114(core);
    if (func_021A3D50(core, 1) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3E48(FieldPlayerCore *core)
{
    func_021A3D6C(core, 1);

    return 0;
}

/* Step of the sequence to the surf form: model, form code, surf effect. */
int func_021A3E54(FieldPlayerCore *core)
{
    VecFx32 pos;
    u32 sex;
    Mmdl *mmdl;
    u32 fieldEffect;
    u32 dir;

    sex = func_021A398C(core);
    mmdl = func_021A3960(core);
    sex = func_021A3190(sex, 2);
    if (sex != func_0216D598(mmdl)) {
        func_021A3AD8(core, sex);
    }
    if (func_021A3974(core) != FIELD_PLAYER_FORM_CODE_SURF) {
        func_021A3980(core, FIELD_PLAYER_FORM_CODE_SURF);
    }
    func_021A4114(core);
    if (func_021A3AD4(core) == 0) {
        fieldEffect = func_02188CD0(core->fieldMap);
        dir = func_0216D5F8(mmdl);
        func_0216D88C(mmdl, &pos);
        func_021A3AD0(core, func_021ACB38(fieldEffect, dir, &pos, mmdl, 1));
    }
    core->formChangeDone = 1;
    return 0;
}

int func_021A3EE0(FieldPlayerCore *core)
{
    int formCode = func_021A3974(core);

    if (func_021A3D08(core, func_021A31A4(func_021A398C(core), formCode)) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3F10(FieldPlayerCore *core)
{
    int formCode;

    if (func_021A3B94(core) == 1) {
        core->formChangeCount++;
        formCode = func_021A3974(core);
        func_021A3AD8(core, func_021A31A4(func_021A398C(core), formCode));
        core->formChangeDone = 1;
    }
    return 0;
}

int func_021A3F48(FieldPlayerCore *core)
{
    if (func_021A3D50(core, 4) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3F64(FieldPlayerCore *core)
{
    func_021A3D6C(core, 4);

    return 0;
}

int func_021A3F70(FieldPlayerCore *core)
{
    if (func_021A3D50(core, 5) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3F8C(FieldPlayerCore *core)
{
    func_021A3D6C(core, 5);

    return 0;
}

int func_021A3F98(FieldPlayerCore *core)
{
    if (func_021A3D50(core, 6) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3FB4(FieldPlayerCore *core)
{
    func_021A3D6C(core, 6);

    return 0;
}

int func_021A3FC0(FieldPlayerCore *core)
{
    if (func_021A3D50(core, 9) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A3FDC(FieldPlayerCore *core)
{
    func_021A3D6C(core, 9);

    return 0;
}

/* Step of the sequence to the dive form: model, form code, dive effect, bubbles. */
int func_021A3FE8(FieldPlayerCore *core)
{
    VecFx32 pos;
    u32 sex;
    Mmdl *mmdl;
    u32 fieldEffect;
    u32 dir;
    u32 bubbleEffect;

    bubbleEffect = func_02188CD0(core->fieldMap);
    sex = func_021A398C(core);
    mmdl = func_021A3960(core);
    sex = func_021A3190(sex, 3);
    if (sex != func_0216D598(mmdl)) {
        func_021A3AD8(core, sex);
    }
    if (func_021A3974(core) != FIELD_PLAYER_FORM_CODE_DIVE) {
        func_021A3980(core, FIELD_PLAYER_FORM_CODE_DIVE);
    }
    if (func_021A3AD4(core) == 0) {
        fieldEffect = func_02188CD0(core->fieldMap);
        dir = func_0216D5F8(mmdl);
        func_0216D88C(mmdl, &pos);
        func_021A3AD0(core, func_021ACB38(fieldEffect, dir, &pos, mmdl, 1));
    }
    func_021D05D8(core->mmdl, bubbleEffect);
    if (core->rideEffect != 0) {
        func_021ACBC8(core->rideEffect, 0);
    }
    core->formChangeDone = 1;
    return 0;
}

int func_021A408C(FieldPlayerCore *core)
{
    if (func_021A3D50(core, 8) != 1)
        core->formChangeStep++;
    return 0;
}

int func_021A40A8(FieldPlayerCore *core)
{
    s16 grid[2];
    int blocked;
    Mmdl *mmdl;
    struct MmdlSys *mmdlSys;

    func_021A3D6C(core, 8);
    if (core->formChangeDone == 1 && func_021A3974(core) == FIELD_PLAYER_FORM_CODE_SURF) {
        blocked = 0;
        mmdl = func_021A3960(core);
        mmdlSys = func_0216D67C(mmdl);
        grid[1] = func_0216D83C(mmdl);
        grid[0] = func_0216D86C(mmdl);
        func_02164240(1, &grid[1], &grid[0], 1);
        if (func_0216DDC0(mmdlSys, grid[1], grid[0], 1) != 0) {
            blocked = 1;
        }
        func_0219F5C8(mmdl, blocked);
    }
    return 0;
}

/* Posts the BGM change for the zone the field map shows. */
void func_021A4114(FieldPlayerCore *core)
{
    struct GameData *gameData = func_020120F4(func_02188C80(core->fieldMap));
    u32 bgmId = func_02012A30(gameData);

    func_02029D8C(bgmId, gameData, (u16)(int)func_02188C9C(core->fieldMap));
}
