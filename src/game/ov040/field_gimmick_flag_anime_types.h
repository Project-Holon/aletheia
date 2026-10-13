#ifndef ALETHEIA_OV040_FIELD_GIMMICK_FLAG_ANIME_TYPES_H
#define ALETHEIA_OV040_FIELD_GIMMICK_FLAG_ANIME_TYPES_H

/*
 * Field gimmick 40 (overlay 40): one expansion model with one animation.
 * Script commands set a flag, read it, and start the animation event.
 */

/*
 * The expansion object types come from ov021/fld_exp_obj_types.h, which the
 * source file includes first (the compiler resolves includes against the
 * source file directory, so this header cannot include it). A file that does
 * not include it sees the types as opaque.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;
typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct FldExpObjAnime FldExpObjAnime;
typedef struct G3dUtilSetup G3dUtilSetup;
typedef struct G3dObjectStatus G3dObjectStatus;
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/* The common work of the gimmick on the field map (4 bytes, id 1). */
typedef struct Gimmick40Work {
    u16 modelIndex;     /* 0x00: model whose animation the event plays */
    u16 reserved;       /* 0x02 */
} Gimmick40Work;

/* Where the model stands (x and z in fx32). */
typedef struct Gimmick40ModelPos {
    fx32 x;
    fx32 z;
} Gimmick40ModelPos;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *expObj, G3dUtilSetup *setup, u16 unitIndex);
extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int frame);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern int func_021BE748(FldExpObjAnime *anime);
extern void func_021BE580(FldExpObjCnt *expObj);

int FIELD_GIMMICK_FLAG_ANIME_EventPlayAnime(struct GameEvent *event, int *seq, void *work);

#endif
