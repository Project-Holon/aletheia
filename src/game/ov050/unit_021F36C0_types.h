#ifndef ALETHEIA_OV050_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV050_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 50 (overlay 50): one expansion unit of two models. Model 0
 * has one animation, model 1 has two. Script commands start, stop and poll
 * them; model 1 is hidden until it is shown.
 */

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;

#define GIMMICK50_MODEL_COUNT 2

/* The common work of the gimmick on the field map (2 bytes, id 1). */
typedef struct Gimmick50Work {
    u16 heapId;         /* 0x00: heap of the field map */
} Gimmick50Work;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern void func_021BE580(FldExpObjCnt *expObj);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, u16 modelIndex);
extern void func_021BE4B4(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int hidden);
/* The model and animation indices are u16: the callers truncate them. */
extern FldExpObjAnime *func_021BE674(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int enable);

#endif
