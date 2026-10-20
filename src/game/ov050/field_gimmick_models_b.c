/*
 * file:     field_gimmick_models_b.c
 * unit:     yes
 * function: FIELD_GIMMICK_MODELS_B_Init, FIELD_GIMMICK_MODELS_B_Exit, FIELD_GIMMICK_MODELS_B_Update, FIELD_GIMMICK_MODELS_B_StartModel0Anime, FIELD_GIMMICK_MODELS_B_StopModel0Anime, FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone, FIELD_GIMMICK_MODELS_B_HideModel1, FIELD_GIMMICK_MODELS_B_ShowModel1, FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone, FIELD_GIMMICK_MODELS_B_InitModels, FIELD_GIMMICK_MODELS_B_InitExtra, FIELD_GIMMICK_MODELS_B_ExitExtra
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
 *   FIELD_GIMMICK_MODELS_B_ExitExtra 0x021F3894 thumb ov050
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
 *   gModelsBSetup     0x021F38A4  data  a4
 *   gModelsBModelPos     0x021F38B4  data  a4
 */
/* Original prototypes (docs/ORIGINAL_BUGS.tsv): the DS file declares these differently from the ARM9 headers. */
#ifdef __MWERKS__
#define FLD_EXP_OBJ_GetAnime FLD_EXP_OBJ_GetAnime_header
#define FLD_EXP_OBJ_SetAnimeEnabled FLD_EXP_OBJ_SetAnimeEnabled_header
#endif
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_models_b_types.h"
#include "../ov021/fieldmap.h"
#include "../ov021/fld_exp_obj.h"
#include "field_gimmick_models_b.h"
#ifdef __MWERKS__
#undef FLD_EXP_OBJ_GetAnime
#undef FLD_EXP_OBJ_SetAnimeEnabled
void *FLD_EXP_OBJ_GetAnime(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx);
void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx, int enable);
#endif

void FIELD_GIMMICK_MODELS_B_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_StartModel0Anime(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_StopModel0Anime(struct FieldMap *fieldMap);
int FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_HideModel1(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_ShowModel1(struct FieldMap *fieldMap);
int FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_InitModels(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_InitExtra(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap);

extern const G3dUtilSetup gModelsBSetup;
extern const VecFx32 gModelsBModelPos[FIELD_GIMMICK_MODELS_B_MODEL_COUNT];
struct FieldMap;
struct FieldGimmickModelsBWork;

/* Gimmick setup: allocate the common work, then place the models. */
void FIELD_GIMMICK_MODELS_B_Init(struct FieldMap *fieldMap)
{
    u16 heapId;
    FieldGimmickModelsBWork *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, 1, heapId, 2);
    work->heapId = heapId;
    FIELD_GIMMICK_MODELS_B_InitModels(work, fieldMap);
    FIELD_GIMMICK_MODELS_B_InitExtra(work, fieldMap);
}

/* Gimmick exit: release the common work. */
void FIELD_GIMMICK_MODELS_B_Exit(struct FieldMap *fieldMap)
{
    FIELD_GIMMICK_MODELS_B_ExitExtra(FIELDMAP_GetCommonWork(fieldMap, 1), fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
}

/* Gimmick update: advance the animations. */
void FIELD_GIMMICK_MODELS_B_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Script command: start the animation of model 0 and let it stop at the last frame. */
void FIELD_GIMMICK_MODELS_B_StartModel0Anime(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);

    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, 0, 0), 0);
}

/* Switch the animation of model 0 off. */
void FIELD_GIMMICK_MODELS_B_StopModel0Anime(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_SetAnimeEnabled(FIELDMAP_GetExpObj(fieldMap), 0, 0, 0, 0);
}

/* Script command: 1 when the animation of model 0 has stopped. */
int FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone(struct FieldMap *fieldMap)
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
void FIELD_GIMMICK_MODELS_B_HideModel1(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 1);
    for (i = 0; i < 2; i++)
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 0);
}

/* Script command: show model 1 and play both of its animations once. */
void FIELD_GIMMICK_MODELS_B_ShowModel1(struct FieldMap *fieldMap)
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
int FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone(struct FieldMap *fieldMap)
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
void FIELD_GIMMICK_MODELS_B_InitModels(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int i;
    G3dObjectStatus *status;
    const VecFx32 *pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gModelsBSetup, 0);
    for (i = 0; i < FIELD_GIMMICK_MODELS_B_MODEL_COUNT; i++) {
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, i);
        pos = &gModelsBModelPos[i];
        status->trans.x = pos->x;
        status->trans.y = pos->y;
        status->trans.z = pos->z;
    }
    FIELD_GIMMICK_MODELS_B_StopModel0Anime(fieldMap);
    FIELD_GIMMICK_MODELS_B_HideModel1(fieldMap);
}

/*
 * Empty function.
 */
void FIELD_GIMMICK_MODELS_B_InitExtra(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap)
{
}

/* Empty function: the gimmick exit hook, called with the common work just before it is released. */
void FIELD_GIMMICK_MODELS_B_ExitExtra(struct FieldGimmickModelsBWork *work, struct FieldMap *fieldMap)
{
}
