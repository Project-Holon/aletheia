/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC, GIMMICK49_Update, GIMMICK49_InitModels, GIMMICK50_StopModel0Anime, GIMMICK50_IsModel0AnimeDone, GIMMICK50_HideModel1, GIMMICK50_ShowModel1, GIMMICK50_IsModel1AnimeDone, GIMMICK50_InitModels, GIMMICK50_InitExtra
 * address:  0x021F36C0
 * region:   ov050
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
 *   GIMMICK50_ExitExtra 0x021F3894 thumb ov050
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeLoop 0x021BE6B8 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   FLD_EXP_OBJ_SetModelHidden 0x021BE4B4 thumb ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   d_021F38A4     0x021F38A4  data  a4
 *   gGimmick50ModelPos     0x021F38B4  data  a4
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F36EC(struct FieldMap *fieldMap);
void GIMMICK49_Update(struct FieldMap *fieldMap);
void GIMMICK49_InitModels(struct FieldMap *fieldMap);
void GIMMICK50_StopModel0Anime(struct FieldMap *fieldMap);
int GIMMICK50_IsModel0AnimeDone(struct FieldMap *fieldMap);
void GIMMICK50_HideModel1(struct FieldMap *fieldMap);
void GIMMICK50_ShowModel1(struct FieldMap *fieldMap);
int GIMMICK50_IsModel1AnimeDone(struct FieldMap *fieldMap);
void GIMMICK50_InitModels(Gimmick50Work *work, struct FieldMap *fieldMap);
void GIMMICK50_InitExtra(Gimmick50Work *work, struct FieldMap *fieldMap);
extern void GIMMICK50_ExitExtra(Gimmick50Work *work, struct FieldMap *fieldMap);

extern const G3dUtilSetup d_021F38A4;
extern const VecFx32 gGimmick50ModelPos[GIMMICK50_MODEL_COUNT];

/* Gimmick setup: allocate the common work, then place the models. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    u16 heapId;
    Gimmick50Work *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, 1, heapId, 2);
    work->heapId = heapId;
    GIMMICK50_InitModels(work, fieldMap);
    GIMMICK50_InitExtra(work, fieldMap);
}

/* Gimmick exit: release the common work. */
void func_021F36EC(struct FieldMap *fieldMap)
{
    GIMMICK50_ExitExtra(FIELDMAP_GetCommonWork(fieldMap, 1), fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
}

/* Gimmick update: advance the animations. */
void GIMMICK49_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Script command: start the animation of model 0 and let it stop at the last frame. */
void GIMMICK49_InitModels(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);

    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0), 0);
}

/* Switch the animation of model 0 off. */
void GIMMICK50_StopModel0Anime(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_SetAnimeEnabled(FIELDMAP_GetExpObj(fieldMap), 0, 0, 0, 0);
}

/* Script command: 1 when the animation of model 0 has stopped. */
int GIMMICK50_IsModel0AnimeDone(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    for (i = 0; i < 1; i++) {
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, i)) == 0)
            return 0;
    }
    return 1;
}

/* Hide model 1 and switch both of its animations off. */
void GIMMICK50_HideModel1(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 1);
    for (i = 0; i < 2; i++)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 0);
}

/* Script command: show model 1 and play both of its animations once. */
void GIMMICK50_ShowModel1(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int i;
    int j;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 0);
    for (i = 0; i < 2; i++)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 1);
    for (j = 0; j < 2; j++)
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, 1, j), 0);
}

/*
 * Script command: 1 when both animations of model 1 have stopped.
 * note: two-byte alignment padding at 0x021F383A; index declared before pointer restores r4/r5.
 */
int GIMMICK50_IsModel1AnimeDone(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    for (i = 0; i < 2; i++) {
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 1, i)) == 0)
            return 0;
    }
    return 1;
}

/* Load the unit, place the two models, then switch off model 0 and hide model 1. */
void GIMMICK50_InitModels(Gimmick50Work *work, struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int i;
    G3dObjectStatus *status;
    const VecFx32 *pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &d_021F38A4, 0);
    for (i = 0; i < GIMMICK50_MODEL_COUNT; i++) {
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, i);
        pos = &gGimmick50ModelPos[i];
        status->trans.x = pos->x;
        status->trans.y = pos->y;
        status->trans.z = pos->z;
    }
    GIMMICK50_StopModel0Anime(fieldMap);
    GIMMICK50_HideModel1(fieldMap);
}

/*
 * Empty function.
 */
void GIMMICK50_InitExtra(Gimmick50Work *work, struct FieldMap *fieldMap)
{
}
