/*
 * file:     fld_exp_obj.c
 * unit:     yes
 * function: FLD_EXP_OBJ_Create, FLD_EXP_OBJ_Delete, FLD_EXP_OBJ_AddUnit, FLD_EXP_OBJ_RemoveUnit, FLD_EXP_OBJ_GetModelStatus, FLD_EXP_OBJ_SetModelCullDraw, FLD_EXP_OBJ_SetModelHidden, FLD_EXP_OBJ_GetModelObject, FLD_EXP_OBJ_Draw, FLD_EXP_OBJ_UpdateAnimes, FLD_EXP_OBJ_InitAnimeSet, FLD_EXP_OBJ_GetAnime, FLD_EXP_OBJ_SetAnimePaused, FLD_EXP_OBJ_IsAnimePaused, FLD_EXP_OBJ_SetAnimeLoop, FLD_EXP_OBJ_IsAnimeStopped, FLD_EXP_OBJ_SetAnimeFrame, FLD_EXP_OBJ_GetAnimeFrame, FLD_EXP_OBJ_SetAnimeEnabled, FLD_EXP_OBJ_GetAnimeLastFrame, FLD_EXP_OBJ_AddUnitFromArchive
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
 *   sFldExpObjFileName  0x021DE390  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3D_UTIL_AddUnitLoaded  0x02047F4C  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_UTIL_GetUnitObjIdx  0x020489F4  arm
 *   G3D_UTIL_GetObject  0x02048A18  arm
 *   G3D_UTIL_GetUnitObjCount  0x02048A00  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   G3D_UTIL_AddUnitFromArchive  0x02048010  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm  arm9
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm  arm9
 */
#include "fld_exp_obj_types.h"

typedef int (*GameEventFunc)(struct GameEvent *event, u32 *seq, void *work);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct G3dUtil *G3D_UTIL_Create(u16 resCount, u16 objCount, u16 heapId);
extern void G3D_UTIL_Delete(struct G3dUtil *util);
extern u32 GFL_HEAP_Free(void *block);
extern u16 G3D_UTIL_AddUnitLoaded(struct G3dUtil *util, const G3dUtilSetup *setup);
extern void MTX_Identity33_(MtxFx33 *mtx);
extern struct G3dAnime *G3D_SYSTEM_GetObjectAnime(struct G3dObject *obj, int anmIdx);
extern void G3D_UTIL_RemoveUnit(struct G3dUtil *util, u32 unitId);
extern u32 G3D_UTIL_GetUnitObjIdx(struct G3dUtil *util, int unitId);
extern struct G3dObject *G3D_UTIL_GetObject(struct G3dUtil *util, int objIdx);
extern u16 G3D_UTIL_GetUnitObjCount(struct G3dUtil *util, int unitId);
extern int G3D_SYSTEM_DrawObjectCulling(struct G3dObject *obj, G3dObjectStatus *status);
extern void G3D_SYSTEM_DrawObject(struct G3dObject *obj, G3dObjectStatus *status);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(struct G3dObject *obj, int anmIdx, fx32 step);
extern int G3D_SYSTEM_IncObjectAnimeFrame(struct G3dObject *obj, int anmIdx, fx32 step);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern s32 G3D_SYSTEM_GetObjectAnimeFrame(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern s32 G3D_SYSTEM_EnableObjectAnime(struct G3dObject *obj, u32 anmIdx);
extern int G3D_SYSTEM_DisableObjectAnime(struct G3dObject *obj, u32 anmIdx);
extern NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(struct G3dAnime *anime);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern u16 G3D_UTIL_AddUnitFromArchive(struct G3dUtil *util, const G3dUtilSetup *setup, void *archive);
extern void ARC_TOOL_DeleteHandle(void *archive);

FldExpObjCnt *FLD_EXP_OBJ_Create(u32 resCount, u32 objCount, u32 heapId);
void FLD_EXP_OBJ_Delete(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *cnt, G3dUtilSetup *setup, u16 unitIdx);
void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *cnt, u16 unitIdx);
G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *cnt, unsigned unitIdx, int modelIdx);
void FLD_EXP_OBJ_SetModelCullDraw(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int cullDraw);
void FLD_EXP_OBJ_SetModelHidden(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int hidden);
struct G3dObject *FLD_EXP_OBJ_GetModelObject(FldExpObjCnt *cnt, u32 unitIdx, int modelIdx);
void FLD_EXP_OBJ_Draw(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_InitAnimeSet(FldExpObjAnimeSet *animeSet, int count, int heapId);
FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *cnt, int unitIdx, unsigned int modelIdx, int animeIdx);
void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused);
u8 FLD_EXP_OBJ_IsAnimePaused(FldExpObjAnime *anime);
void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
int FLD_EXP_OBJ_IsAnimeStopped(FldExpObjAnime *anime);
void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int frame);
int FLD_EXP_OBJ_GetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx);
void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int enable);
int FLD_EXP_OBJ_GetAnimeLastFrame(FldExpObjAnime *anime);
void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *cnt, const G3dUtilSetup *setup, u16 unitIdx);

/* Per gimmick callbacks of the field map, indexed by the gimmick id. */
/* The __FILE__ string of the allocations below. */
extern const char sFldExpObjFileName[];
/* Effect id by [from zone group][to zone group]: exit effects, entrance effects. */

FldExpObjCnt *FLD_EXP_OBJ_Create(u32 resCount, u32 objCount, u32 heapId)
{
    FldExpObjCnt *cnt = GFL_HEAP_Alloc((u16)heapId, sizeof(FldExpObjCnt), 1, sFldExpObjFileName, 0x4c);

    cnt->util = G3D_UTIL_Create(resCount, objCount, heapId);
    cnt->heapId = heapId;
    return cnt;
}

void FLD_EXP_OBJ_Delete(FldExpObjCnt *cnt)
{
    u16 i;

    for (i = 0; i < FLD_EXP_OBJ_UNIT_MAX; i++) {
        if (cnt->units[i].active != 0) {
            FLD_EXP_OBJ_RemoveUnit(cnt, i);
        }
    }
    G3D_UTIL_Delete(cnt->util);
    GFL_HEAP_Free(cnt);
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
void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *cnt, G3dUtilSetup *setup, u16 unitIdx)
{
    u16 unitId;
    u16 modelCount;
    FldExpObjModel *models;
    u16 modelIdx;

    unitId = G3D_UTIL_AddUnitLoaded(cnt->util, setup);
    modelCount = setup->objCount;
    cnt->units[unitIdx].modelCount = modelCount;
    cnt->units[unitIdx].active = 1;
    cnt->units[unitIdx].unitId = unitId;
    models = GFL_HEAP_Alloc((u16)cnt->heapId, modelCount * sizeof(FldExpObjModel), 1, sFldExpObjFileName, 0x8b);
    cnt->units[unitIdx].models = models;
    cnt->units[unitIdx].animeSets = GFL_HEAP_Alloc((u16)cnt->heapId, modelCount * sizeof(FldExpObjAnimeSet), 1, sFldExpObjFileName, 0x8e);
    for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
        int animeIdx;
        FldExpObjModel *model;
        struct G3dObject *obj;
        FldExpObjAnimeSet *animeSet;

        FLD_EXP_OBJ_InitAnimeSet(&cnt->units[unitIdx].animeSets[modelIdx], setup->objTbl[modelIdx].anmCount, cnt->heapId);
        model = &models[modelIdx];
        SetVecFx32(&model->status.scale, 0x1000, 0x1000, 0x1000);
        MTX_Identity33_(&model->status.rotate);
        SetVecFx32(&model->status.trans, 0, 0, 0);
        model->cullDraw = 0;
        model->hidden = 0;
        obj = FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx);
        animeSet = &cnt->units[unitIdx].animeSets[modelIdx];
        for (animeIdx = 0; animeIdx < animeSet->count; animeIdx++)
            animeSet->anime[animeIdx].anime = G3D_SYSTEM_GetObjectAnime(obj, (u16)animeIdx);
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
void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *cnt, u16 unitIdx)
{
    u16 modelIdx;

    if (cnt->units[unitIdx].active != 0 && unitIdx < FLD_EXP_OBJ_UNIT_MAX) {
        for (modelIdx = 0; modelIdx < cnt->units[unitIdx].modelCount; modelIdx++)
            GFL_HEAP_Free(cnt->units[unitIdx].animeSets[modelIdx].anime);
        GFL_HEAP_Free(cnt->units[unitIdx].animeSets);
        GFL_HEAP_Free(cnt->units[unitIdx].models);
        G3D_UTIL_RemoveUnit(cnt->util, cnt->units[unitIdx].unitId);
        cnt->units[unitIdx].active = 0;
    }
}

/*
 * Unlabelled leaf in ov021, immediately after FLD_EXP_OBJ_RemoveUnit's epilogue
 * (0x021BE47C) and before the next traced function at 0x021BE4A4; it saves
 * nothing, so disasm.py prints it inside the pool/.word run.  It is the
 * blocker target of ov010's NAMEIN_SETUP_SyncObjHeightToAnim (pkt_0216C280), reached across the
 * ov010/ov021 overlay pair.  Returns the status of model modelIdx of unit
 * unitIdx: null when the unit is not loaded or the index is out of range.
 */
G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *cnt, unsigned unitIdx, int modelIdx)
{
    if (cnt->units[unitIdx].active == 0)
        return 0;
    if (unitIdx >= FLD_EXP_OBJ_UNIT_MAX)
        return 0;
    return &cnt->units[unitIdx].models[modelIdx].status;
}

void FLD_EXP_OBJ_SetModelCullDraw(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int cullDraw)
{
    cnt->units[unitIdx].models[modelIdx].cullDraw = cullDraw;
}

void FLD_EXP_OBJ_SetModelHidden(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int hidden)
{
    cnt->units[unitIdx].models[modelIdx].hidden = hidden;
}

/*
 * The 3D utility object of model modelIdx of unit unitIdx.
 */
struct G3dObject *FLD_EXP_OBJ_GetModelObject(FldExpObjCnt *cnt, u32 unitIdx, int modelIdx)
{
    int firstObjIdx;

    if (cnt->units[unitIdx].active == 0) {
        return 0;
    }
    if (unitIdx >= FLD_EXP_OBJ_UNIT_MAX) {
        return 0;
    }
    firstObjIdx = G3D_UTIL_GetUnitObjIdx(cnt->util, cnt->units[unitIdx].unitId);
    return G3D_UTIL_GetObject(cnt->util, (u16)(firstObjIdx + modelIdx));
}

/*
 * Draws every visible model of every active unit.
 */
void FLD_EXP_OBJ_Draw(FldExpObjCnt *cnt)
{
    u8 unitIdx;
    u8 modelIdx;
    int firstObjIdx;
    int modelCount;
    FldExpObjModel *model;

    for (unitIdx = 0; unitIdx < FLD_EXP_OBJ_UNIT_MAX; unitIdx++) {
        if (cnt->units[unitIdx].active == 1) {
            firstObjIdx = G3D_UTIL_GetUnitObjIdx(cnt->util, cnt->units[unitIdx].unitId);
            modelCount = G3D_UTIL_GetUnitObjCount(cnt->util, cnt->units[unitIdx].unitId);
            for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
                if (cnt->units[unitIdx].models[modelIdx].hidden == 0) {
                    struct G3dObject *obj = G3D_UTIL_GetObject(cnt->util, (u16)(firstObjIdx + modelIdx));
                    model = &cnt->units[unitIdx].models[modelIdx];
                    if (model->cullDraw != 0) {
                        G3D_SYSTEM_DrawObjectCulling(obj, &model->status);
                    } else {
                        G3D_SYSTEM_DrawObject(obj, &model->status);
                    }
                }
            }
        }
    }
}

/*
 * Advances every enabled, unpaused animation by its speed.
 */
void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *cnt)
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
            modelCount = G3D_UTIL_GetUnitObjCount(cnt->util, cnt->units[unitIdx].unitId);
            for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
                obj = FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx);
                animeCount = cnt->units[unitIdx].animeSets[modelIdx].count;
                for (animeIdx = 0; animeIdx < animeCount; animeIdx++) {
                    anime = &cnt->units[unitIdx].animeSets[modelIdx].anime[animeIdx];
                    if (anime->enabled != 0 && anime->paused == 0) {
                        if (anime->loop != 0)
                            anime->advanceResult = G3D_SYSTEM_LoopObjectAnimeFrame(obj, animeIdx, anime->speed);
                        else
                            anime->advanceResult = G3D_SYSTEM_IncObjectAnimeFrame(obj, animeIdx, anime->speed);
                    }
                }
            }
        }
    }
}

/*
 * Allocates count animations for a model: unpaused, looping, disabled, speed 1.
 */
void FLD_EXP_OBJ_InitAnimeSet(FldExpObjAnimeSet *animeSet, int count, int heapId)
{
    FldExpObjAnime *anime = GFL_HEAP_Alloc((u16)heapId, count << 4, 1, sFldExpObjFileName, 0x19D);
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

FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *cnt, int unitIdx, unsigned int modelIdx, int animeIdx)
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

void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused)
{
    anime->paused = paused;
}

u8 FLD_EXP_OBJ_IsAnimePaused(FldExpObjAnime *anime)
{
    return anime->paused;
}

/*
 * Unlabelled leaf: strb r1, [r0, #1].
 */
void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop)
{
    anime->loop = loop;
}

int FLD_EXP_OBJ_IsAnimeStopped(FldExpObjAnime *anime)
{
    return anime->advanceResult == 0;
}

void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int frame)
{
    int frameTmp = frame;

    G3D_SYSTEM_SetObjectAnimeFrame(FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx), animeIdx, &frameTmp);
}

int FLD_EXP_OBJ_GetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx)
{
    int frame;

    G3D_SYSTEM_GetObjectAnimeFrame(FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx), animeIdx, &frame);
    return frame;
}

void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx, int enable)
{
    struct G3dObject *obj = FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx);
    FldExpObjAnime *anime = FLD_EXP_OBJ_GetAnime(cnt, unitIdx, modelIdx, animeIdx);

    if (anime == 0) {
        return;
    }
    if (enable != 0) {
        if (anime->enabled != 0) {
            return;
        }
        G3D_SYSTEM_EnableObjectAnime(obj, animeIdx);
    } else {
        if (anime->enabled == 0) {
            return;
        }
        G3D_SYSTEM_DisableObjectAnime(obj, animeIdx);
    }
    anime->enabled = enable;
}

/*
 * Last frame of the animation, in 20.12 fixed point.
 */
int FLD_EXP_OBJ_GetAnimeLastFrame(FldExpObjAnime *anime)
{
    return (((const NNSG3dResAnmCommon *)G3D_SYSTEM_GetAnimeObj(anime->anime)->resAnm)->numFrame << 12) - (1 << 12);
}

/*
 * note:     twin of FLD_EXP_OBJ_AddUnit, opening its own archive for the setup call. Needs both
 *           the twin's `u16 unitIdx` and `const G3dUtilSetup *setup`: int unitIdx swaps its
 *           home store and the model->hidden store (12 bytes), u16 unitIdx alone loads
 *           the setup's archive before cnt->heapId (18 bytes).
 */
void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *cnt, const G3dUtilSetup *setup, u16 unitIdx)
{
    void *archive;
    u16 unitId;
    u16 modelCount;
    FldExpObjModel *models;
    u16 modelIdx;

    archive = ARC_TOOL_CreateHandle(setup->resTbl->arc, (u16)(((u16)cnt->heapId & 0x7FFF) | 0x8000));
    unitId = G3D_UTIL_AddUnitFromArchive(cnt->util, setup, archive);
    ARC_TOOL_DeleteHandle(archive);
    modelCount = setup->objCount;
    cnt->units[unitIdx].modelCount = modelCount;
    cnt->units[unitIdx].active = 1;
    cnt->units[unitIdx].unitId = unitId;
    models = GFL_HEAP_Alloc((u16)cnt->heapId, modelCount * sizeof(FldExpObjModel), 1, sFldExpObjFileName, 0x23E);
    cnt->units[unitIdx].models = models;
    cnt->units[unitIdx].animeSets = GFL_HEAP_Alloc((u16)cnt->heapId, modelCount * sizeof(FldExpObjAnimeSet), 1, sFldExpObjFileName, 0x241);
    for (modelIdx = 0; modelIdx < modelCount; modelIdx++) {
        int animeIdx;
        FldExpObjModel *model;
        struct G3dObject *obj;
        FldExpObjAnimeSet *animeSet;

        FLD_EXP_OBJ_InitAnimeSet(&cnt->units[unitIdx].animeSets[modelIdx], setup->objTbl[modelIdx].anmCount, cnt->heapId);
        model = &models[modelIdx];
        SetVecFx32(&model->status.scale, 0x1000, 0x1000, 0x1000);
        MTX_Identity33_(&model->status.rotate);
        SetVecFx32(&model->status.trans, 0, 0, 0);
        model->cullDraw = 0;
        model->hidden = 0;
        obj = FLD_EXP_OBJ_GetModelObject(cnt, unitIdx, modelIdx);
        animeSet = &cnt->units[unitIdx].animeSets[modelIdx];
        for (animeIdx = 0; animeIdx < animeSet->count; animeIdx++)
            animeSet->anime[animeIdx].anime = G3D_SYSTEM_GetObjectAnime(obj, (u16)animeIdx);
    }
}
