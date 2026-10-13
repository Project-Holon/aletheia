#ifndef ALETHEIA_OV050_FIELD_GIMMICK_MODELS_B_TYPES_H
#define ALETHEIA_OV050_FIELD_GIMMICK_MODELS_B_TYPES_H

/*
 * Field gimmick 50 (overlay 50): one expansion unit of two models. Model 0
 * has one animation, model 1 has two. Script commands start, stop and poll
 * them; model 1 is hidden until it is shown.
 */

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;

#define FIELD_GIMMICK_MODELS_B_MODEL_COUNT 2

/* The common work of the gimmick on the field map (2 bytes, id 1). */
typedef struct FieldGimmickModelsBWork {
    u16 heapId;         /* 0x00: heap of the field map */
} FieldGimmickModelsBWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern void func_021BE580(FldExpObjCnt *expObj);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, u16 modelIndex);
extern void func_021BE4B4(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int hidden);
/* The model and animation indices are u16: the callers truncate them. */
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int enable);

#endif
