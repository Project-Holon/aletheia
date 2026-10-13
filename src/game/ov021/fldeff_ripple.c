/*
 * file:     fldeff_ripple.c
 * unit:     yes
 * function: func_021C457C, func_021C459C, func_021C4608, func_021C4628, func_021C4678, func_021C46A4, func_021C46F8, func_021C474C, func_021C4788, func_021C47B4, func_021C47E8, func_021C47FC, func_021C483C, func_021C484C, func_021C48A0, func_021C4938, func_021C4954, func_021C4974
 * address:  0x021C457C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   g_020A7370     0x020A7370  data
 *   func_021C1094  0x021C1094  thumb  ov021
 *   func_021C10A0  0x021C10A0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021C1024  0x021C1024  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C12C4  0x021C12C4  thumb  ov021
 *   func_021C12D0  0x021C12D0  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1228  0x021C1228  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021C9550  0x021C9550  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D2418  0x021D2418  thumb  ov021
 *   func_021D2440  0x021D2440  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov063_id       0x0000003F  data
 *   func_021F3758  0x021F3758  thumb  ov063
 *   func_021F376C  0x021F376C  thumb  ov063
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   d_021DE468     0x021DE468  data  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_02050278  0x02050278  arm
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DA9F0     0x021DA9F0  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021DE464     0x021DE464  data  a4
 */
#include "../arm9/billboard_act_types.h"
#include "field_effect_types.h"

struct Pokemon;
struct Personal;
struct MyStatus;
struct BbActSys;
struct FieldMap;
struct MsgBank;
struct StrBuf;

typedef struct ArcHandle ArcHandle;
typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */

/* Mon data ids read and written through the Pokemon data accessors. */
enum {
    MON_DATA_SPECIES = 5,
    MON_DATA_HELD_ITEM = 6,
    MON_DATA_OT_ID = 7,
    MON_DATA_FRIENDSHIP = 9,
    MON_DATA_ABILITY = 0xA,
    MON_DATA_LANGUAGE = 0xC,
    MON_DATA_MOVE1 = 0x36,
    MON_DATA_MOVE2 = 0x37,
    MON_DATA_MOVE3 = 0x38,
    MON_DATA_MOVE4 = 0x39,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_GENDER = 0x6E,
    MON_DATA_FORM = 0x6F,
    MON_DATA_NATURE = 0x70,
    MON_DATA_NICKNAME = 0x73,
    MON_DATA_OT_NAME = 0x8D,
    MON_DATA_ABILITY_SET = 0xB2
};

/* Day care work (same object as SodateyaWork in fld3d_ci_types.h). */
typedef struct SodateyaWork {
    u16 heapId;                           /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;            /* 0x04 */
    void *dayCare;                        /* 0x08 */
    u16 stepCount;                        /* 0x0C steps walked since the last egg check */
} SodateyaWork;

/* The four move slots of a Pokemon, as mon data ids. */
typedef struct MoveSlotIdTable { u32 ids[4]; } MoveSlotIdTable;

/* The six IVs or the six power items, in HP, Atk, Def, SpAtk, SpDef, Speed order. */
typedef struct StatTable { u32 ids[6]; } StatTable;

/* A baby species, the incense that lets it hatch, and the species hatched without it. */
typedef struct IncenseBabyEntry {
    u32 babySpecies;
    u32 incenseItem;
    u32 adultSpecies;
} IncenseBabyEntry;

typedef struct IncenseBabyTable { IncenseBabyEntry entries[12]; } IncenseBabyTable;

/* Resources of the ripple effect (allocated 0xC bytes by FLDEFF_RIPPLE_Create). */
typedef struct RippleWork {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    struct BbActSys *bbActSys;            /* 0x04 */
    u16 actorId;                          /* 0x08 */
} RippleWork;

/* Start parameter of one ripple. */
typedef struct RippleStartParam {
    RippleWork *work;
    VecFx32 pos;
} RippleStartParam;

extern u32 func_020307B0(void *p);
extern void *func_0215A64C(void *a);
extern int func_021C1094(void *x);
extern int func_021C10A0(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const void *p);
extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern u16 func_0216D5F8(void *p);
extern u32 func_02188C98(void *p);
extern u16 func_0215A5CC(void *a0);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_021C1024(void *a, u32 b, u32 c, u32 d);
extern void func_0215A644(void *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021C12C4(void *x);
extern void func_021C12D0(void *x);
extern u16 func_021A3050(void *p);
extern u32 func_02159B10(void *a, void *b);
extern u32 func_021C1228(void *a, u32 b, u32 c, u32 d);
extern u32 func_02188CD0(void *p);
extern void func_021C9550(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_021D2418(void *a, u32 b);
extern void *func_021D2440(void *a, u32 b, u32 c);
extern void func_0215897C(void *a, void *b);
extern void *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
extern int func_02034AC4(int a);
extern void func_021A305C(void *p, u32 b);
extern void *func_021F36C0(void *a, u32 b, u32 c, u32 d);
extern void func_02034A5C(s32 handle);
extern int func_021F376C(int *p);
extern void func_021F3758(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct FieldMap *func_021ABE14(FieldEffectSys *fieldEffect);
extern struct BbActSys *func_02188C90(struct FieldMap *fieldMap);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern void func_021AC1F0(FieldEffectSys *fieldEffect, G3dResource *res);
extern u16 func_020500F0(struct BbActSys *sys, const struct BbActRec *recs, u32 count);
extern void func_02050278(struct BbActSys *sys, u32 first, u32 count);
extern void func_02164280(int x, int y, int *p);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const void *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *g_020A7370;

int func_021C457C(void *vm, void *scriptWork);
u32 func_021C459C(u32 vm, void *scriptWork);
int func_021C4608(void *vm, void *scriptWork);
u32 func_021C4628(u32 vm, void *scriptWork);
int func_021C4678(void *vm, void *scriptWork);
int func_021C46A4(void *vm, void *scriptWork);
u32 func_021C46F8(u32 a, u32 b, u32 c);
void *func_021C474C(void *a, u32 b, u32 c);
int func_021C4788(void *task);
RippleWork *func_021C47B4(FieldEffectSys *fieldEffect, u32 heapId);
void func_021C47E8(u32 unused, RippleWork *work);
void func_021C47FC(RippleWork *work);
void func_021C483C(RippleWork *work);
void func_021C484C(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height);
extern unsigned char ov063_id[];
extern char d_021DE468[];
extern u8 d_021DA9F0[];

/* Work of one ripple effect object. */
typedef struct RippleObjWork {
    RippleWork *res;
    u16 entryId;
} RippleObjWork;

extern void *func_021AC1AC(FieldEffectObj *obj);
extern void func_021AC1CC(FieldEffectObj *obj, VecFx32 *pos);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(FieldEffectObj *obj);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(struct BbActSys *p, int i, u16 *out);
void func_021C48A0(FieldEffectObj *obj, RippleObjWork *work);
void func_021C4938(FieldEffectObj *obj, RippleObjWork *work);
void func_021C4954(FieldEffectObj *obj, RippleObjWork *work);
void func_021C4974(void);
extern u8 d_021DE464[];

/*
 * Script wait callback of the first grid event command: done once
 * func_021C1094 reports 1.
 */
int func_021C457C(void *vm, void *scriptWork)
{
    void *gridEvent = func_0215A64C(scriptWork);

    if (func_021C1094(gridEvent) == 1) {
        func_021C10A0((u32)gridEvent);
        return 1;
    }
    return 0;
}

/*
 * First grid event script command: starts the event on the player's grid
 * position and installs func_021C457C as the wait callback.
 */
u32 func_021C459C(u32 vm, void *scriptWork)
{
    u32 pos[3];
    u32 playerWork, effectId, result;
    void *fieldMap;
    void *player;

    fieldMap = func_0201210C(func_0215A5DC((void *)scriptWork));
    player = func_02188CB4((void *)fieldMap);
    playerWork = func_0216D5F8(func_021A3074(player));
    fieldMap = (void *)func_02188C98(fieldMap);
    effectId = func_0215A5CC((void *)scriptWork);
    func_021A3364(player, playerWork, (int *)pos);
    result = func_021AB0D4(fieldMap, pos);
    result = func_021C1024(player, playerWork, result, effectId);
    func_0215A644((void *)scriptWork, result);
    func_020113D0((char *)vm, (int)func_021C457C);
    return 1;
}

/*
 * Script wait callback of the second grid event command.
 */
int func_021C4608(void *vm, void *scriptWork)
{
    void *gridEvent = func_0215A64C(scriptWork);

    if (func_021C12C4(gridEvent) == 1) {
        func_021C12D0(gridEvent);
        return 1;
    }
    return 0;
}

/*
 * Second grid event script command (see func_021C459C).
 */
u32 func_021C4628(u32 vm, void *scriptWork)
{
    u32 effectId, playerWork, result;
    void *player;

    effectId = func_0215A5CC(scriptWork);
    player = func_02188CB4(func_0201210C(func_0215A5DC((void *)scriptWork)));
    playerWork = func_021A3050(player);
    result = func_02159B10((void *)vm, (void *)scriptWork);
    result = func_021C1228(player, playerWork, result, effectId);
    func_0215A644((void *)scriptWork, result);
    func_020113D0((char *)vm, (int)func_021C4608);
    return 1;
}

/*
 * Script command: starts the Cut effect on the player's field object.
 */
int func_021C4678(void *vm, void *scriptWork)
{
    void *fieldMap = func_0201210C(func_0215A5DC(scriptWork));
    void *playerMmdl = func_021A3074(func_02188CB4((void *)fieldMap));

    func_021C9550((u32)playerMmdl, func_02188CD0(fieldMap));
    return 0;
}

/*
 * Script command: starts a saved animation chosen by the type func_02159B10
 * returns. The shared func_0215897C call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills the script object instead of scriptWork.
 */
int func_021C46A4(void *vm, void *scriptWork)
{
    u32 type;
    void *fieldMap;
    void *saveAnimeArg;
    void *scriptObj;

    saveAnimeArg = func_0215A5DC(scriptWork);
    fieldMap = func_0201210C(saveAnimeArg);
    scriptObj = func_0215A5F4(scriptWork);
    type = func_02159B10(vm, scriptWork);
    if (type == 0)
        func_0215897C(scriptObj, func_021D2418(saveAnimeArg, (u32)fieldMap));
    else if (type == 1)
        func_0215897C(scriptObj, func_021D2440(saveAnimeArg, (u32)fieldMap, 0));
    else
        func_0215897C(scriptObj, func_021D2440(saveAnimeArg, (u32)fieldMap, 1));
    return 1;
}

/*
 * Starts the ov063 effect for the player's grid event with the player's
 * data and spawns the task that drives it.
 */
u32 func_021C46F8(u32 a, u32 b, u32 c)
{
    u32 task = (u32)func_020122C0((void *)a, 0, func_021C4788, 4);
    u32 *effectSlot = func_020124E8((void *)task);
    void *fieldMap;
    void *player;

    func_02034AC4((int)ov063_id);
    fieldMap = func_02188CB4((void *)b);
    player = func_021A3074((void *)fieldMap);
    func_021A305C(fieldMap, c);
    *effectSlot = (u32)func_021F36C0((void *)a, b, (u32)player, 1);
    return task;
}

/*
 * Loads ov063 and spawns the task that drives its effect.
 */
void *func_021C474C(void *a, u32 b, u32 c)
{
    void *task = func_020122C0(a, 0, func_021C4788, 4);
    void **effectSlot = func_020124E8(task);

    func_02034AC4((u32)ov063_id);
    *effectSlot = func_021F36C0(a, b, c, 0);
    return task;
}

/*
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 */
int func_021C4788(void *task)
{
    void **effectSlot = func_020124E8(task);

    if (func_021F376C(*effectSlot) != 0) {
        func_021F3758(*effectSlot);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}

/*
 * Allocates the 0xC-byte ripple record and registers its billboard actor.
 */
RippleWork *func_021C47B4(FieldEffectSys *fieldEffect, u32 heapId)
{
    RippleWork *work = func_02030734(heapId, 0xC, 1, d_021DE468, 0x56);

    work->fieldEffect = fieldEffect;
    work->bbActSys = func_02188C90(func_021ABE14(fieldEffect));
    func_021C47FC(work);
    return work;
}

/* Removes the billboard actor and frees the ripple record. */
void func_021C47E8(u32 unused, RippleWork *work)
{
    func_021C483C(work);
    func_020307B0(work);
}

/* Loads the ripple model and adds its billboard actor. */
void func_021C47FC(RippleWork *work)
{
    struct BbActRec rec;
    G3dResource *res;
    ArcHandle *arc = func_021ABE24(work->fieldEffect);

    rec.format = 2;
    rec.sizeS = 0x13;
    rec.sizeT = 0x10;
    rec.paletteId = 0x10;
    rec.kind = 1;
    res = func_02046E24(arc, 0x2e);
    rec.resource = (u32)res;
    func_021AC1F0(work->fieldEffect, (void *)rec.resource);
    work->actorId = func_020500F0(work->bbActSys, &rec, 1);
}

void func_021C483C(RippleWork *work)
{
    func_02050278(work->bbActSys, work->actorId, 1);
}

/* Starts a ripple on the tile at the given grid position and height. */
void func_021C484C(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height)
{
    VecFx32 pos;
    RippleStartParam param;

    func_02164280(gridX, gridZ, (int *)(&pos));
    pos.y = height - 0x8000;
    pos.z -= 0x5000;
    param.work = func_021ABEA0(fieldEffect, 7);
    param.pos = pos;
    func_021ABFA8(fieldEffect, d_021DA9F0, 0, 0, &param, 0);
}

/* Ripple effect (fldeff_ripple.c): callbacks of its field effect object. */
void func_021C48A0(FieldEffectObj *obj, RippleObjWork *work)
{
    RippleStartParam *param = (RippleStartParam *)func_021AC1AC(obj);
    RippleWork *bbRes;
    u32 actSys, entryId;
    struct BbActDesc desc;

    work->res = param->work;
    func_021AC1CC(obj, &param->pos);
    bbRes = work->res;
    actSys = (u32)bbRes->bbActSys;
    desc.slot = bbRes->actorId;
    desc.width = 0x1000;
    desc.height = 0x1000;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.pos = param->pos;
    desc.hook = 0;
    desc.hookArg = (u32)work;
    work->entryId = func_02050340((struct BbActSys *)actSys, 0, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        func_021AC154(obj);
        return;
    }
    func_02050804((struct BbActSys *)actSys, work->entryId, (u32)d_021DE464, 1);
    entryId = work->entryId;
    func_0205082C((struct BbActSys *)actSys, entryId, 0);
    func_020507F0((struct BbActSys *)actSys, entryId, 1);
}

/* Exit: deletes the billboard entry unless the creation failed. */
void func_021C4938(FieldEffectObj *obj, RippleObjWork *work)
{
    u32 actSys = (u32)work->res->bbActSys;

    if (work->entryId != 0xFFFF)
        func_02050468((struct BbActSys *)actSys, work->entryId, 1);
}

/* Update: ends the effect when the entry has run its last command. */
void func_021C4954(FieldEffectObj *obj, RippleObjWork *work)
{
    u32 lastCommand;

    if (func_020508EC(work->res->bbActSys, work->entryId, (u16 *)(&lastCommand)) != 0)
        func_021AC154(obj);
}

/* Draw: nothing to do, the billboard system draws the entry. */
void func_021C4974(void) {}
