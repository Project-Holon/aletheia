#ifndef ALETHEIA_OV049_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV049_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 49 (overlay 49): one expansion unit of six models. Models 0
 * and 1 start their animation once all four event flags are set; models 2 to
 * 5 start theirs one by one with the flag of the same row.
 */

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;
struct GameData;
struct EventWork;

#define GIMMICK49_MODEL_COUNT 6

/* Event flags that switch on models 2, 3, 4 and 5. */
#define GIMMICK49_FLAG_MODEL2 0x96B
#define GIMMICK49_FLAG_MODEL3 0x96A
#define GIMMICK49_FLAG_MODEL4 0x969
#define GIMMICK49_FLAG_MODEL5 0x96C

/* The common work of the gimmick on the field map (2 bytes, id 0). */
typedef struct Gimmick49Work {
    u16 heapId;         /* 0x00: heap of the field map */
} Gimmick49Work;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct EventWork *GAME_DATA_GetEventWork(const struct GameData *gameData);
extern int ZONEDATA_CheckEventFlag(struct EventWork *eventWork, int flagId);
extern void func_021BE580(FldExpObjCnt *expObj);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, u16 modelIndex);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);

#endif
