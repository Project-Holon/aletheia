#ifndef ALETHEIA_OV042_FIELD_GIMMICK_BUTTON_STATES_TYPES_H
#define ALETHEIA_OV042_FIELD_GIMMICK_BUTTON_STATES_TYPES_H

/*
 * Field gimmick 42 (overlay 42): twelve expansion models. Models 0 to 8 are
 * shown in a state set by an event (first or last animation frame). Models 9
 * to 11 play their animation once; the save area remembers which ones did.
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

#define GIMMICK42_STATE_MODEL_COUNT 9       /* models 0 to 8 */
#define GIMMICK42_ONE_SHOT_FIRST_MODEL 9    /* models 9 to 11 */
#define GIMMICK42_ONE_SHOT_COUNT 3

/* The common work of the gimmick on the field map (4 bytes, id 1), filled by the event creators. */
typedef struct Gimmick42Work {
    u8 stateModel;      /* 0x00: model the state event changes */
    u8 oneShotIndex;    /* 0x01: one-shot model (relative to the first one) the play event runs */
    u8 showLastFrame;   /* 0x02: nonzero: the state event shows the last frame */
    u8 reserved;        /* 0x03 */
} Gimmick42Work;

/* The gimmick save area (work id 4 of the gimmick work). */
typedef struct Gimmick42Save {
    u8 oneShotPlayed[GIMMICK42_ONE_SHOT_COUNT];     /* 0x00: the model played its animation */
} Gimmick42Save;

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
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void func_021BE4A4(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int cullDraw);
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int frame);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int enable);
extern int func_021BE748(FldExpObjAnime *anime);
extern void func_021BE580(FldExpObjCnt *expObj);

int GIMMICK42_EventPlayOneShot(struct GameEvent *event, int *seq, void *work);

#endif
