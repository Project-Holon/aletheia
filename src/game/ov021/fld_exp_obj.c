/*
 * file:     fld_exp_obj.c
 * unit:     yes
 * function: func_021BE2A8, func_021BE2E0, func_021BE310, func_021BE418, func_021BE480, func_021BE4A4, func_021BE4B4, func_021BE4C4, func_021BE4F8, func_021BE580, func_021BE630, func_021BE674, func_021BE6B0, func_021BE6B4, func_021BE6B8, func_021BE6BC, func_021BE6CC, func_021BE6E8, func_021BE700, func_021BE748, func_021BE760
 * address:  0x021BE2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cut proposed (lane CL124): 021BE89C..021BEE74 (map change effect ids and fade event creators) belong with event_fieldmap_control.c, which holds their handlers; the __FILE__ anchor covers only 021BE2A8..021BE760.
 *
 * symbols:
 *   d_021DE390  0x021DE390  data
 *   func_02030734  0x02030734  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E54  0x02047E54  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047F4C  0x02047F4C  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02047790  0x02047790  arm
 *   func_020480E4  0x020480E4  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_02047674  0x02047674  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02048010  0x02048010  arm
 *   func_02049238  0x02049238  arm
 */
#include "fld_exp_obj_types.h"

typedef int (*GameEventFunc)(struct GameEvent *event, u32 *seq, void *work);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct G3dUtil *func_02047CFC(u16 resCount, u16 objCount, u16 heapId);
extern void func_02047E54(struct G3dUtil *util);
extern u32 func_020307B0(void *block);
extern u16 func_02047F4C(struct G3dUtil *util, const G3dUtilSetup *setup);
extern void func_0207ADC4(MtxFx33 *mtx);
extern struct G3dAnime *func_02047790(struct G3dObject *obj, int anmIdx);
extern void func_020480E4(struct G3dUtil *util, u32 unitId);
extern u32 func_020489F4(struct G3dUtil *util, int unitId);
extern struct G3dObject *func_02048A18(struct G3dUtil *util, int objIdx);
extern u16 func_02048A00(struct G3dUtil *util, int unitId);
extern int func_02047AC8(struct G3dObject *obj, G3dObjectStatus *status);
extern void func_02047A60(struct G3dObject *obj, G3dObjectStatus *status);
extern int func_02047910(struct G3dObject *obj, int anmIdx, fx32 step);
extern int func_020478B8(struct G3dObject *obj, int anmIdx, fx32 step);
extern u32 func_0204784C(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern u32 func_02047828(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern u32 func_020477A4(struct G3dObject *obj, u32 anmIdx);
extern int func_020477D4(struct G3dObject *obj, u32 anmIdx);
extern NNSG3dAnmObj *func_02047674(struct G3dAnime *anime);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern u16 func_02048010(struct G3dUtil *util, const G3dUtilSetup *setup, void *archive);
extern void func_02049238(void *archive);

FldExpObjCnt *func_021BE2A8(u32 resCount, u32 objCount, u32 heapId);
void func_021BE2E0(FldExpObjCnt *cnt);
void func_021BE310(FldExpObjCnt *cnt, G3dUtilSetup *setup, u16 unitIdx);
void func_021BE418(FldExpObjCnt *cnt, u16 unitIdx);
G3dObjectStatus *func_021BE480(FldExpObjCnt *cnt, unsigned unitIdx, int modelIdx);
void func_021BE4A4(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int cullDraw);
void func_021BE4B4(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int hidden);
struct G3dObject *func_021BE4C4(FldExpObjCnt *cnt, u32 unitIdx, int modelIdx);
void func_021BE4F8(FldExpObjCnt *cnt);
void func_021BE580(FldExpObjCnt *cnt);
void func_021BE630(FldExpObjAnimeSet *animeSet, int count, int heapId);
FldExpObjAnime *func_021BE674(FldExpObjCnt *cnt, int unitIdx, unsigned int modelIdx, int animeIdx);
void func_021BE6B0(FldExpObjAnime *anime, int paused);
u8 func_021BE6B4(FldExpObjAnime *anime);
void func_021BE6B8(FldExpObjAnime *anime, int loop);
int func_021BE6BC(FldExpObjAnime *anime);
void func_021BE6CC(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int frame);
int func_021BE6E8(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx);
void func_021BE700(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int enable);
int func_021BE748(FldExpObjAnime *anime);
void func_021BE760(FldExpObjCnt *cnt, const G3dUtilSetup *setup, u16 unitIdx);

/* Per gimmick callbacks of the field map, indexed by the gimmick id. */
/* The __FILE__ string of the allocations below. */
extern const char d_021DE390[];
/* Effect id by [from zone group][to zone group]: exit effects, entrance effects. */

FldExpObjCnt *func_021BE2A8(u32 resCount, u32 objCount, u32 heapId)
{
    FldExpObjCnt *cnt = func_02030734((u16)heapId, sizeof(FldExpObjCnt), 1, d_021DE390, 0x4c);

    cnt->util = func_02047CFC(resCount, objCount, heapId);
    cnt->heapId = heapId;
    return cnt;
}

void func_021BE2E0(FldExpObjCnt *cnt)
{
    u16 i;

    for (i = 0; i < FLD_EXP_OBJ_UNIT_MAX; i++) {
        if (cnt->units[i].active != 0) {
            func_021BE418(cnt, i);
        }
    }
    func_02047E54(cnt->util);
    func_020307B0(cnt);
}

static inline void SetVecFx32(VecFx32 *dst, fx32 x, fx32 y, fx32 z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/*
 * Loads a setup into unit slot unitIdx and builds its models and animation
 * sets.
 * The u16 slot index is what moves its home store (str r2, [sp, #0xc]) to
 * the front of the prologue; with animeIdx declared ahead of model the loop counter
 * takes r4, the register the zero stores share.
 */
void func_021BE310(FldExpObjCnt *cnt, G3dUtilSetup *setup, u16 unitIdx)
{
    u16 unitId;
    u16 modelCount;
    FldExpObjModel *models;
    u16 modelIdx;

    unitId = func_02047F4C(cnt->util, setup);
    modelCount = setup->objCount;
    cnt->units[unitIdx].modelCount = modelCount;
    cnt->units[unitIdx].active = 1;
    cnt->units[unitIdx].unitId = unitId;
    models = func_02030734((u16)cnt->heapId, modelCount * sizeof(FldExpObjModel), 1, d_021DE390, 0x8b);
    cnt->units[unitIdx].models = models;
    cnt->units[unitIdx].animeSets = func_02030734((u16)cnt->heapId, modelCount * sizeof(FldExpObjAnimeSet), 1, d_021DE390, 0x8e);
    for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
        int animeIdx;
        FldExpObjModel *model;
        struct G3dObject *obj;
        FldExpObjAnimeSet *animeSet;

        func_021BE630(&cnt->units[unitIdx].animeSets[modelIdx], setup->objTbl[modelIdx].anmCount, cnt->heapId);
        model = &models[modelIdx];
        SetVecFx32(&model->status.scale, 0x1000, 0x1000, 0x1000);
        func_0207ADC4(&model->status.rotate);
        SetVecFx32(&model->status.trans, 0, 0, 0);
        model->cullDraw = 0;
        model->hidden = 0;
        obj = func_021BE4C4(cnt, unitIdx, modelIdx);
        animeSet = &cnt->units[unitIdx].animeSets[modelIdx];
        for (animeIdx = 0; animeIdx < animeSet->count; animeIdx++)
            animeSet->anime[animeIdx].anime = func_02047790(obj, (u16)animeIdx);
    }
}

/*
 * Frees the models and animation sets of unit slot unitIdx and removes its
 * unit from the 3D utility.
 * The listing extent (172) runs on into unlabelled leaves 0x021BE480,
 * 0x021BE4A4 and 0x021BE4B4; the function itself is 102 bytes.
 * unitIdx is a u16 parameter (spilled to [sp] at entry and reloaded for the
 * < 4 test). The unit fields are indexed directly: a pointer to the unit
 * would fold the +8 of the units array into the base and change the frame.
 */
void func_021BE418(FldExpObjCnt *cnt, u16 unitIdx)
{
    u16 modelIdx;

    if (cnt->units[unitIdx].active != 0 && unitIdx < FLD_EXP_OBJ_UNIT_MAX) {
        for (modelIdx = 0; modelIdx < cnt->units[unitIdx].modelCount; modelIdx++)
            func_020307B0(cnt->units[unitIdx].animeSets[modelIdx].anime);
        func_020307B0(cnt->units[unitIdx].animeSets);
        func_020307B0(cnt->units[unitIdx].models);
        func_020480E4(cnt->util, cnt->units[unitIdx].unitId);
        cnt->units[unitIdx].active = 0;
    }
}

/*
 * Unlabelled leaf in ov021, immediately after func_021BE418's epilogue
 * (0x021BE47C) and before the next traced function at 0x021BE4A4; it saves
 * nothing, so disasm.py prints it inside the pool/.word run.  It is the
 * blocker target of ov010's func_0216C280 (pkt_0216C280), reached across the
 * ov010/ov021 overlay pair.  Returns the status of model modelIdx of unit
 * unitIdx: null when the unit is not loaded or the index is out of range.
 */
G3dObjectStatus *func_021BE480(FldExpObjCnt *cnt, unsigned unitIdx, int modelIdx)
{
    if (cnt->units[unitIdx].active == 0)
        return 0;
    if (unitIdx >= FLD_EXP_OBJ_UNIT_MAX)
        return 0;
    return &cnt->units[unitIdx].models[modelIdx].status;
}

void func_021BE4A4(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int cullDraw)
{
    cnt->units[unitIdx].models[modelIdx].cullDraw = cullDraw;
}

void func_021BE4B4(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int hidden)
{
    cnt->units[unitIdx].models[modelIdx].hidden = hidden;
}

/*
 * The 3D utility object of model modelIdx of unit unitIdx.
 */
struct G3dObject *func_021BE4C4(FldExpObjCnt *cnt, u32 unitIdx, int modelIdx)
{
    int firstObjIdx;

    if (cnt->units[unitIdx].active == 0) {
        return 0;
    }
    if (unitIdx >= FLD_EXP_OBJ_UNIT_MAX) {
        return 0;
    }
    firstObjIdx = func_020489F4(cnt->util, cnt->units[unitIdx].unitId);
    return func_02048A18(cnt->util, (u16)(firstObjIdx + modelIdx));
}

/*
 * Draws every visible model of every active unit.
 */
void func_021BE4F8(FldExpObjCnt *cnt)
{
    u8 unitIdx;
    u8 modelIdx;
    int firstObjIdx;
    int modelCount;
    FldExpObjModel *model;

    for (unitIdx = 0; unitIdx < FLD_EXP_OBJ_UNIT_MAX; unitIdx++) {
        if (cnt->units[unitIdx].active == 1) {
            firstObjIdx = func_020489F4(cnt->util, cnt->units[unitIdx].unitId);
            modelCount = func_02048A00(cnt->util, cnt->units[unitIdx].unitId);
            for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
                if (cnt->units[unitIdx].models[modelIdx].hidden == 0) {
                    struct G3dObject *obj = func_02048A18(cnt->util, (u16)(firstObjIdx + modelIdx));
                    model = &cnt->units[unitIdx].models[modelIdx];
                    if (model->cullDraw != 0) {
                        func_02047AC8(obj, &model->status);
                    } else {
                        func_02047A60(obj, &model->status);
                    }
                }
            }
        }
    }
}

/*
 * Advances every enabled, unpaused animation by its speed.
 */
void func_021BE580(FldExpObjCnt *cnt)
{
    u8 unitIdx;
    u8 modelIdx;
    u8 animeIdx;
    int animeCount;
    u16 modelCount;
    struct G3dObject *obj;
    FldExpObjAnime *anime;

    for (unitIdx = 0; unitIdx < FLD_EXP_OBJ_UNIT_MAX; unitIdx++) {
        if (cnt->units[unitIdx].active == 1) {
            modelCount = func_02048A00(cnt->util, cnt->units[unitIdx].unitId);
            for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
                obj = func_021BE4C4(cnt, unitIdx, modelIdx);
                animeCount = cnt->units[unitIdx].animeSets[modelIdx].count;
                for (animeIdx = 0; animeIdx < animeCount; animeIdx++) {
                    anime = &cnt->units[unitIdx].animeSets[modelIdx].anime[animeIdx];
                    if (anime->enabled != 0 && anime->paused == 0) {
                        if (anime->loop != 0)
                            anime->advanceResult = func_02047910(obj, animeIdx, anime->speed);
                        else
                            anime->advanceResult = func_020478B8(obj, animeIdx, anime->speed);
                    }
                }
            }
        }
    }
}

/*
 * Allocates count animations for a model: unpaused, looping, disabled, speed 1.
 */
void func_021BE630(FldExpObjAnimeSet *animeSet, int count, int heapId)
{
    FldExpObjAnime *anime = func_02030734((u16)heapId, count << 4, 1, d_021DE390, 0x19D);
    int i;

    animeSet->anime = anime;
    animeSet->count = count;
    for (i = 0; i < count; i++) {
        anime[i].paused = 0;
        anime[i].loop = 1;
        anime[i].enabled = 0;
        anime[i].speed = 0x1000;
    }
}

FldExpObjAnime *func_021BE674(FldExpObjCnt *cnt, int unitIdx, unsigned int modelIdx, int animeIdx)
{
    FldExpObjAnime *animeTbl;

    if (cnt->units[unitIdx].active == 0) {
        return 0;
    }
    if (modelIdx >= cnt->units[unitIdx].modelCount) {
        return 0;
    }
    animeTbl = cnt->units[unitIdx].animeSets[modelIdx].anime;
    if (animeIdx >= cnt->units[unitIdx].animeSets[modelIdx].count) {
        return 0;
    }
    return &animeTbl[animeIdx];
}

void func_021BE6B0(FldExpObjAnime *anime, int paused)
{
    anime->paused = paused;
}

u8 func_021BE6B4(FldExpObjAnime *anime)
{
    return anime->paused;
}

/*
 * Unlabelled leaf: strb r1, [r0, #1].
 */
void func_021BE6B8(FldExpObjAnime *anime, int loop)
{
    anime->loop = loop;
}

int func_021BE6BC(FldExpObjAnime *anime)
{
    return anime->advanceResult == 0;
}

void func_021BE6CC(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int frame)
{
    int frameTmp = frame;

    func_0204784C(func_021BE4C4(cnt, unitIdx, modelIdx), animeIdx, &frameTmp);
}

int func_021BE6E8(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx)
{
    int frame;

    func_02047828(func_021BE4C4(cnt, unitIdx, modelIdx), animeIdx, &frame);
    return frame;
}

void func_021BE700(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int enable)
{
    struct G3dObject *obj = func_021BE4C4(cnt, unitIdx, modelIdx);
    FldExpObjAnime *anime = func_021BE674(cnt, unitIdx, modelIdx, animeIdx);

    if (anime == 0) {
        return;
    }
    if (enable != 0) {
        if (anime->enabled != 0) {
            return;
        }
        func_020477A4(obj, animeIdx);
    } else {
        if (anime->enabled == 0) {
            return;
        }
        func_020477D4(obj, animeIdx);
    }
    anime->enabled = enable;
}

/*
 * Last frame of the animation, in 20.12 fixed point.
 */
int func_021BE748(FldExpObjAnime *anime)
{
    return (func_02047674(anime->anime)->resAnm->numFrame << 12) - (1 << 12);
}

/*
 * note:     twin of func_021BE310, opening its own archive for the setup call. Needs both
 *           the twin's `u16 unitIdx` and `const G3dUtilSetup *setup`: int unitIdx swaps its
 *           home store and the model->hidden store (12 bytes), u16 unitIdx alone loads
 *           the setup's archive before cnt->heapId (18 bytes).
 */
void func_021BE760(FldExpObjCnt *cnt, const G3dUtilSetup *setup, u16 unitIdx)
{
    void *archive;
    u16 unitId;
    u16 modelCount;
    FldExpObjModel *models;
    u16 modelIdx;

    archive = func_020490F4(setup->resTbl->arc, (u16)(((u16)cnt->heapId & 0x7FFF) | 0x8000));
    unitId = func_02048010(cnt->util, setup, archive);
    func_02049238(archive);
    modelCount = setup->objCount;
    cnt->units[unitIdx].modelCount = modelCount;
    cnt->units[unitIdx].active = 1;
    cnt->units[unitIdx].unitId = unitId;
    models = func_02030734((u16)cnt->heapId, modelCount * sizeof(FldExpObjModel), 1, d_021DE390, 0x23E);
    cnt->units[unitIdx].models = models;
    cnt->units[unitIdx].animeSets = func_02030734((u16)cnt->heapId, modelCount * sizeof(FldExpObjAnimeSet), 1, d_021DE390, 0x241);
    for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
        int animeIdx;
        FldExpObjModel *model;
        struct G3dObject *obj;
        FldExpObjAnimeSet *animeSet;

        func_021BE630(&cnt->units[unitIdx].animeSets[modelIdx], setup->objTbl[modelIdx].anmCount, cnt->heapId);
        model = &models[modelIdx];
        SetVecFx32(&model->status.scale, 0x1000, 0x1000, 0x1000);
        func_0207ADC4(&model->status.rotate);
        SetVecFx32(&model->status.trans, 0, 0, 0);
        model->cullDraw = 0;
        model->hidden = 0;
        obj = func_021BE4C4(cnt, unitIdx, modelIdx);
        animeSet = &cnt->units[unitIdx].animeSets[modelIdx];
        for (animeIdx = 0; animeIdx < animeSet->count; animeIdx++)
            animeSet->anime[animeIdx].anime = func_02047790(obj, (u16)animeIdx);
    }
}
