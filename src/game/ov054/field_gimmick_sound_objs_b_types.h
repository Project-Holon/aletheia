#ifndef ALETHEIA_OV054_FIELD_GIMMICK_SOUND_OBJS_B_TYPES_H
#define ALETHEIA_OV054_FIELD_GIMMICK_SOUND_OBJS_B_TYPES_H

/*
 * Field gimmick 54 (overlay 54): two 3D sound objects that follow models of
 * the expansion unit. Each plays its animation once, waits a random time
 * between its limits, and plays it again. The frame of each animation is
 * kept in the gimmick work (slot 11) while the map is left.
 *
 * The expansion object and model types come from ov021/fld_exp_obj_types.h,
 * which the source file includes first (the compiler resolves includes
 * against the source file directory, so this header cannot include it).
 */

#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
#error "include ../ov021/fld_exp_obj_types.h before this header"
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct FieldCamera;
struct G3dCamera;
struct IssSystem;
struct Iss3dsSys;
struct SoundObj;

/* Archive of the sound data of this gimmick, and the sound sources of its two objects. */
#define FIELD_GIMMICK_SOUND_OBJS_B_ARC_ID 0x7f
#define FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT 2

/* The gimmick work slot that keeps the animation frames. */
#define FIELD_GIMMICK_SOUND_OBJS_B_SAVE_SLOT 11

/* Work of the gimmick (0x28 bytes, common work id 0 of the field map). */
typedef struct FieldGimmickSoundObjsBWork {
    u16 heapId;                                         /* 0x00 */
    u16 reserved02;
    struct Iss3dsSys *iss3ds;                           /* 0x04 */
    struct SoundObj *soundObj[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];   /* 0x08 */
    int waitFrames[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];          /* 0x10: frames left before the animation starts again; 0 while it plays */
    int minWait[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];             /* 0x18: shortest wait */
    int maxWait[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];             /* 0x20: longest wait */
} FieldGimmickSoundObjsBWork;

/* The animation frames (in whole frames) in the gimmick work. */
typedef struct FieldGimmickSoundObjsBSave {
    int animeFrame[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];
} FieldGimmickSoundObjsBSave;

/* Archive members that hold the wait limits of each object. */
typedef struct FieldGimmickSoundObjsBWaitMembers {
    int member[FIELD_GIMMICK_SOUND_OBJS_B_SOUND_OBJ_COUNT];
} FieldGimmickSoundObjsBWaitMembers;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *expObj, G3dUtilSetup *setup, u16 unitIndex);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);
extern int SOUND_OBJ_Delete(struct SoundObj *obj);
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern struct G3dCamera *FIELD_CAMERA_GetG3dCamera(struct FieldCamera *camera);
extern void G3D_CAMERA_GetEye(struct G3dCamera *camera, VecFx32 *eye);
extern void G3D_CAMERA_GetUp(struct G3dCamera *camera, VecFx32 *target);
extern void ISS_3DS_SYS_SetCamera(struct Iss3dsSys *iss3ds, VecFx32 *eye, VecFx32 *target);
extern u32 SOUND_OBJ_AdvanceAnime(struct SoundObj *obj, s32 deltaFrame);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct IssSystem *GAMESYSTEM_GetIssSystem(struct GameSystem *gameSystem);
extern struct Iss3dsSys *ISS_SYS_Get3dsSys(struct IssSystem *issSystem);
extern int *ARC_TOOL_LoadMember(u32 archiveId, u32 member, u32 heapId);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct SoundObj *SOUND_OBJ_Create(struct FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 radius, u32 amplitude);
extern void SOUND_OBJ_SetAnime(struct SoundObj *obj, u32 arcId, u32 dataId, u32 bufferFrames);
extern u32 GFL_HEAP_Free(void *p);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern FieldGimmickSoundObjsBSave *GIMMICK_WORK_GetWork(struct GimmickWork *gimmickWork, u32 slotId);
extern u32 SOUND_OBJ_GetAnimeFrame(struct SoundObj *obj);
extern void SOUND_OBJ_SetAnimeFrame(struct SoundObj *obj, s32 frame);
extern unsigned GFL_USE_GetRandomBelow(unsigned limit);

void FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(FieldGimmickSoundObjsBWork *work, int index);

#endif
