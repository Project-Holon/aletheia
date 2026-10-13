/*
 * file:     field_gimmick_models_a.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, func_021F3708, func_021F3714, GIMMICK49_InitExtra, func_021F3868
 * address:  0x021F36C0
 * region:   ov049
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   func_021F3868 0x021F3868 thumb ov049
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   gGimmick49Setup     0x021F3894  data  ov049  a4
 *   d_021F38A4     0x021F38A4  data  a4
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_models_a_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F36EC(struct FieldMap *fieldMap);
void func_021F3708(struct FieldMap *fieldMap);
void func_021F3714(Gimmick49Work *work, struct FieldMap *fieldMap);
void GIMMICK49_InitExtra(Gimmick49Work *work, struct FieldMap *fieldMap);
extern void func_021F3868(Gimmick49Work *work, struct FieldMap *fieldMap);

extern const G3dUtilSetup gGimmick49Setup;
extern const VecFx32 d_021F38A4[GIMMICK49_MODEL_COUNT];
struct FieldMap;
struct Gimmick49Work;

/* Gimmick setup: allocate the common work, then place the models. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    u16 heapId;
    Gimmick49Work *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, 2);
    work->heapId = heapId;
    func_021F3714(work, fieldMap);
    GIMMICK49_InitExtra(work, fieldMap);
}

/* Gimmick exit: release the common work. */
void func_021F36EC(struct FieldMap *fieldMap)
{
    func_021F3868(FIELDMAP_GetCommonWork(fieldMap, 0), fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

/* Gimmick update: advance the animations. */
void func_021F3708(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Load the unit, place the six models and start the animations of the models whose event flags are set. */
void func_021F3714(Gimmick49Work *work, struct FieldMap *fieldMap)
{
    int model2Lit;
    int model3Lit;
    int model4Lit;
    int model5Lit;
    struct EventWork *eventWork;
    FldExpObjCnt *expObj;
    int i;
    G3dObjectStatus *status;

    eventWork = GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    model2Lit = ZONEDATA_CheckEventFlag(eventWork, GIMMICK49_FLAG_MODEL2);
    model3Lit = ZONEDATA_CheckEventFlag(eventWork, GIMMICK49_FLAG_MODEL3);
    model4Lit = ZONEDATA_CheckEventFlag(eventWork, GIMMICK49_FLAG_MODEL4);
    model5Lit = ZONEDATA_CheckEventFlag(eventWork, GIMMICK49_FLAG_MODEL5);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gGimmick49Setup, 0);
    for (i = 0; i < GIMMICK49_MODEL_COUNT; i++) {
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, i);
        status->trans.x = d_021F38A4[i].x;
        status->trans.y = d_021F38A4[i].y;
        status->trans.z = d_021F38A4[i].z;
    }
    if (model2Lit && model3Lit && model4Lit && model5Lit) {
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, 0, 1);
    }
    if (model2Lit)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 2, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 2, 0, 1);
    if (model3Lit)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 3, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 3, 0, 1);
    if (model4Lit)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 4, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 4, 0, 1);
    if (model5Lit)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 5, 1, 1);
    else
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 5, 0, 1);
}

/*
 * Empty function.
 */
void GIMMICK49_InitExtra(Gimmick49Work *work, struct FieldMap *fieldMap)
{
}

/* Empty function: the gimmick exit hook, called with the common work just before it is released. */
void func_021F3868(struct Gimmick49Work *work, struct FieldMap *fieldMap)
{
}
