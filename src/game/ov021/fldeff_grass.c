/*
 * file:     fldeff_grass.c
 * unit:     yes
 * function: func_021AC68C, func_021AC6C0, func_021AC6D4, func_021AC740, func_021AC760, func_021AC810, func_021AC8E4, func_021AC900, func_021AC9D4, func_021AC9D8
 * address:  0x021AC68C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC68C: __FILE__ fldeff_grass.c on 0x021AC68C (init, first
 * function).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02050278  0x02050278  arm
 *   d_021DE070  0x021DE070  data
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_020500F0  0x020500F0  arm
 *   d_021D911C     0x021D911C  data  a2
 *   d_021D90EC  0x021D90EC  data
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   d_021DE050     0x021DE050  data  a4
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 *   func_0205085C  0x0205085C  arm
 *   d_021D90C0     0x021D90C0  data
 *   d_021D90C8     0x021D90C8  data  a2
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 */
#include "field_effect_types.h"
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the grass resource in the field effect system. */
#define FLDEFF_ID_GRASS 2

/* The grass effect has eight billboard images. */
#define FLDEFF_GRASS_IMAGE_COUNT 8

/* Columns of the image file table (one per model base offset). */
#define FLDEFF_GRASS_FILE_COLUMNS 4

/* Billboard images are 32 by 32 pixels. */
#define FLDEFF_GRASS_IMAGE_SIZE_S 0x24
#define FLDEFF_GRASS_IMAGE_SIZE_T 0x20
#define FLDEFF_GRASS_IMAGE_PALETTE 0x20

/* Model status bit that selects the fixed grass height. */
#define FLDEFF_GRASS_FIXED_HEIGHT_BIT 0x2000

/* Grass height above the ground: fixed or above the map height. */
#define FLDEFF_GRASS_RAISE_FIXED 7
#define FLDEFF_GRASS_RAISE_MAP   9

/* The grass is drawn this far in front of the model. */
#define FLDEFF_GRASS_BACK_OFFSET 0x2000

/*
 * Resource of the grass effect (0x18 bytes, allocated by func_021AC68C).
 * It owns eight billboard slots, one per grass image.
 */
typedef struct FldeffGrass {
    FieldEffectSys *fieldEffect;                       /* 0x00 */
    struct BbActSys *billboardAct;                     /* 0x04 billboard system of the ground */
    u16 slotId[FLDEFF_GRASS_IMAGE_COUNT];              /* 0x08 */
} FldeffGrass;

/* Start parameter of one grass (0x24 bytes). */
typedef struct FldeffGrassParam {
    FldeffGrass *grass;                   /* 0x00 */
    Mmdl *mmdl;                           /* 0x04 model that steps into the grass */
    int gridX;                            /* 0x08 */
    int gridZ;                            /* 0x0C */
    u16 objId;                            /* 0x10 object id of the model */
    u16 zoneId;                           /* 0x12 zone id of the model */
    VecFx32 pos;                          /* 0x14 */
    int index;                            /* 0x20 which of the eight images */
} FldeffGrassParam;

extern u32 func_020307B0(void *p);
extern void *func_02188C80(struct FieldMap *fieldmap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern int func_0216D83C(const Mmdl *mmdl);
extern int func_0216D86C(const Mmdl *mmdl);
extern void *func_02046E24(u32 arcHandle, u32 fileId);
extern u16 func_020500F0(struct BbActSys *act, const struct BbActRec *recs, u32 count);
extern void func_02050278(struct BbActSys *act, u32 first, u32 count);
extern struct BbActSys *func_02188C90(struct FieldMap *fieldmap);
extern u16 func_0216D588(const Mmdl *mmdl);
extern u16 func_0216D590(const Mmdl *mmdl);
extern void func_02164280(int gridX, int gridZ, VecFx32 *out);
extern u32 func_0216D8AC(const Mmdl *mmdl);
extern int func_0216D55C(const Mmdl *mmdl, int bit);
extern void func_02163E58(const Mmdl *mmdl, VecFx32 *pos, int *outHeight);
struct FieldMap *func_021ABE14(FieldEffectSys *sys);
u32 func_021ABE24(FieldEffectSys *sys);
u8 func_021ABE28(FieldEffectSys *sys);
void *func_021ABEA0(FieldEffectSys *sys, int id);
void func_021ABFA8(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void func_021AC1F0(FieldEffectSys *sys, void *model);
FldeffGrass *func_021AC68C(FieldEffectSys *sys, int heapId);
void func_021AC6C0(FieldEffectSys *sys, FldeffGrass *grass);
void func_021AC6D4(FldeffGrass *grass);
void func_021AC740(FldeffGrass *grass);
void func_021AC760(FieldEffectSys *sys, Mmdl *mmdl, u32 mode, int index);
extern char d_021DE070[];
extern u16 d_021D911C[];
extern FieldEffectObjFuncs d_021D90EC;

/* Work of one grass effect object. */
typedef struct GrassWork {
    u32 state;             /* 0x00 GRASS_STATE_* */
    FldeffGrassParam param; /* 0x04 */
    u16 checkInfo[4];      /* 0x28 model check info taken at the start */
    u16 entry;             /* 0x30 billboard entry of the effect */
} GrassWork;

#define GRASS_STATE_PLAY   0
#define GRASS_STATE_SETTLE 1
#define GRASS_STATE_HOLD_A 2
#define GRASS_STATE_HOLD_B 3

extern int func_0216E1A4(Mmdl *mmdl, u16 *info);
extern int func_0216E1C4(Mmdl *mmdl, u16 *info);
extern u16 func_0216D608(Mmdl *mmdl);
extern int func_0216D804(Mmdl *mmdl);
extern int func_0216D81C(Mmdl *mmdl);
extern u16 func_02050340(struct BbActSys *billboards, u16 baseSlot, const struct BbActDesc *desc, u32 count, u32 mode);
extern void func_02050468(struct BbActSys *billboards, u16 first, u32 count);
extern void func_02050804(struct BbActSys *billboards, int entry, u32 commands, u16 loop);
extern void func_0205082C(struct BbActSys *billboards, int entry, u32 cursor);
extern void func_020507F0(struct BbActSys *billboards, int entry, u32 enabled);
extern u32 func_020508EC(struct BbActSys *billboards, int entry, u16 *lastCommand);
extern void func_0205085C(struct BbActSys *billboards, int entry, u32 cursor);
extern void func_021AC154(FieldEffectObj *effect);
extern void func_021AC178(FieldEffectObj *effect);
extern int func_021AC1A0(FieldEffectObj *effect);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_021AC1CC(FieldEffectObj *effect, const VecFx32 *pos);
void func_021AC810(FieldEffectObj *effect, GrassWork *work);
void func_021AC8E4(FieldEffectObj *effect, GrassWork *work);
void func_021AC900(FieldEffectObj *effect, GrassWork *work);
void func_021AC9D4(void);
int func_021AC9D8(GrassWork *work);
extern u32 d_021DE050[];                            /* grass: billboard animation commands of each kind */
extern u8 d_021D90C0[];                             /* grass: 1 = the effect ends when the model leaves */
extern u16 d_021D90C8[];                            /* grass: command cursor of each kind after the first play */

/* Resource creation: allocates the resource and makes the billboard slots. */
FldeffGrass *func_021AC68C(FieldEffectSys *sys, int heapId)
{
    FldeffGrass *grass;

    grass = func_02030734(heapId, sizeof(FldeffGrass), 1, d_021DE070, 0x6c);
    grass->fieldEffect = sys;
    grass->billboardAct = func_02188C90(func_021ABE14(sys));
    func_021AC6D4(grass);
    return grass;
}









/* Resource deletion: frees the billboard slots and the resource. */
void func_021AC6C0(FieldEffectSys *sys, FldeffGrass *grass)
{
    func_021AC740(grass);
    func_020307B0(grass);
}









/* Makes one billboard slot for each of the eight grass images. */
void func_021AC6D4(FldeffGrass *grass)
{
    struct BbActRec rec;
    int i;
    u32 arcHandle = func_021ABE24(grass->fieldEffect);
    u16 *fileTable;
    u32 modelBase;
    func_02188C80(func_021ABE14(grass->fieldEffect));
    modelBase = func_021ABE28(grass->fieldEffect);
    rec.format = 0;
    rec.sizeS = FLDEFF_GRASS_IMAGE_SIZE_S;
    rec.sizeT = FLDEFF_GRASS_IMAGE_SIZE_T;
    rec.paletteId = FLDEFF_GRASS_IMAGE_PALETTE;
    rec.kind = 1;
    fileTable = d_021D911C + modelBase;
    for (i = 0; i < FLDEFF_GRASS_IMAGE_COUNT; i++) {
        rec.resource = (u32)func_02046E24(arcHandle, fileTable[i * FLDEFF_GRASS_FILE_COLUMNS]);
        func_021AC1F0(grass->fieldEffect, (void *)rec.resource);
        grass->slotId[i] = func_020500F0(grass->billboardAct, &rec, 1);
    }
}





/* Frees the eight billboard slots. */
void func_021AC740(FldeffGrass *grass)
{
    int i;

    for (i = 0; i < FLDEFF_GRASS_IMAGE_COUNT; i++)
        func_02050278(grass->billboardAct, grass->slotId[i], 1);
}





/*
 * The pos.z -= FLDEFF_GRASS_BACK_OFFSET adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 */
/* Starts a grass effect under a model, drawn with one of the eight images. */
void func_021AC760(FieldEffectSys *sys, Mmdl *mmdl, u32 mode, int index)
{
    VecFx32 pos;
    FldeffGrassParam param;
    int mapHeight;

    if (index >= FLDEFF_GRASS_IMAGE_COUNT)
        return;
    param.grass = func_021ABEA0(sys, FLDEFF_ID_GRASS);
    param.mmdl = mmdl;
    param.index = index;
    param.objId = func_0216D588(mmdl);
    param.zoneId = func_0216D590(mmdl);
    param.gridX = func_0216D83C(mmdl);
    param.gridZ = func_0216D86C(mmdl);
    func_02164280((s16)param.gridX, (s16)param.gridZ, &pos);
    pos.y = func_0216D8AC(mmdl);
    if (func_0216D55C(mmdl, FLDEFF_GRASS_FIXED_HEIGHT_BIT) != 0) {
        pos.y += FLDEFF_GRASS_RAISE_FIXED * 0x1000;
        pos.z -= FLDEFF_GRASS_BACK_OFFSET;
    } else {
        func_02163E58(mmdl, &pos, &mapHeight);
        pos.y = mapHeight + FLDEFF_GRASS_RAISE_MAP * 0x1000;
        pos.z -= FLDEFF_GRASS_BACK_OFFSET;
    }
    param.pos = pos;
    func_021ABFA8(sys, &d_021D90EC, 0, mode, &param, 0);
}

/* Grass effect init: shows the billboard of the kind and starts its animation. */
void func_021AC810(FieldEffectObj *effect, GrassWork *work)
{
    FldeffGrassParam *param = func_021AC1AC(effect);
    struct BbActDesc desc;
    u16 kind;
    u32 billboards;
    u16 entry;

    work->param = *param;
    func_0216E1A4(param->mmdl, work->checkInfo);
    func_021AC1CC(effect, &param->pos);
    kind = work->param.index;
    desc.slot = work->param.grass->slotId[kind];
    desc.width = 0x2000;
    desc.height = 0x2000;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.pos = param->pos;
    desc.hook = 0;
    desc.hookArg = (u32)work;
    billboards = (u32)work->param.grass->billboardAct;
    work->entry = func_02050340((struct BbActSys *)billboards, 0, &desc, 1, 0);
    if (work->entry == 0xFFFF) {
        func_021AC154(effect);
        return;
    }
    func_02050804((struct BbActSys *)billboards, work->entry, d_021DE050[kind], 1);
    entry = work->entry;
    func_0205082C((struct BbActSys *)billboards, entry, 0);
    func_020507F0((struct BbActSys *)billboards, entry, 1);
    if (func_021AC1A0(effect) == 0)
        work->state = GRASS_STATE_SETTLE;
    func_021AC178(effect);
}

/* Grass effect exit: removes the billboard. */
void func_021AC8E4(FieldEffectObj *effect, GrassWork *work)
{
    u32 billboards = (u32)work->param.grass->billboardAct;

    if (work->entry != 0xFFFF)
        func_02050468((struct BbActSys *)billboards, work->entry, 1);
}

/*
 * Compiled 212 of a 216-byte extent: the follower at 0x021AC9D4 is an
 * unlabelled `bx lr` stub.
 *
 * Addresses are Black-image addresses.
 */
/* Grass effect update: plays the animation, then keeps the grass while the model stays on the tile. */
void func_021AC900(FieldEffectObj *effect, GrassWork *work)
{
    u32 billboards = (u32)work->param.grass->billboardAct;
    Mmdl *mmdl;
    u16 lastCommand;

    switch (work->state) {
    case GRASS_STATE_PLAY:
        if (d_021D90C0[work->param.index] == 1) {
            mmdl = work->param.mmdl;
            if (func_0216E1C4(mmdl, work->checkInfo) == 1 && func_021AC9D8(work) == 0 && func_0216D608(mmdl) == 1) {
                func_021AC154(effect);
                return;
            }
        }
        if (func_020508EC((struct BbActSys *)billboards, work->entry, &lastCommand) != 0)
            work->state++;
        break;
    case GRASS_STATE_SETTLE:
        if (func_0216E1C4(work->param.mmdl, work->checkInfo) == 0) {
            func_021AC154(effect);
            return;
        }
        func_0205085C((struct BbActSys *)billboards, work->entry, d_021D90C8[work->param.index]);
        work->state++;
        break;
    case GRASS_STATE_HOLD_A:
        work->state++;
    case GRASS_STATE_HOLD_B:
        if (func_0216E1C4(work->param.mmdl, work->checkInfo) == 0) {
            func_021AC154(effect);
            return;
        }
        if (func_021AC9D8(work) == 0)
            func_021AC154(effect);
        break;
    }
}

/* Grass effect draw: empty, the billboard system draws the grass. */
void func_021AC9D4(void) {}

/* Returns 1 when the model stands on the tile of the effect, or just left it while still moving off. */
int func_021AC9D8(GrassWork *work)
{
    Mmdl *mmdl = work->param.mmdl;
    u32 x = func_0216D83C(mmdl);
    u32 z = func_0216D86C(mmdl);
    u32 leaveEnds = d_021D90C0[work->param.index];
    if (work->param.gridX == x && work->param.gridZ == z)
        goto onTile;
    if (leaveEnds == 0 && func_0216D608(mmdl) == 0) {
        x = func_0216D804(mmdl);
        z = func_0216D81C(mmdl);
        if (work->param.gridX == x && work->param.gridZ == z)
            return 1;
    }
    return 0;
onTile:
    return 1;
}
