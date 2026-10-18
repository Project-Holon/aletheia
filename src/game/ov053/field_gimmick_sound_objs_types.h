#ifndef ALETHEIA_OV053_FIELD_GIMMICK_SOUND_OBJS_TYPES_H
#define ALETHEIA_OV053_FIELD_GIMMICK_SOUND_OBJS_TYPES_H

/*
 * Field gimmick 53 (overlay 53): five 3D sound objects that follow models of
 * the expansion unit, a background music track whose volume follows the
 * camera height, and a sliding sound effect that starts when the camera
 * drops quickly across a line.
 *
 * Each sound object plays its animation once, waits a random time between
 * its limits, and plays it again. The wait of the objects 1 and 3 is set to
 * one frame when the wait of the objects 0 and 2 ends. The frame of each
 * animation is kept in the gimmick work (slot 1) while the map is left.
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
struct FieldPlayer;
struct IssSystem;
struct Iss3dsSys;
struct SoundObj;

/* Archive of the sound data of this gimmick. */
#define FIELD_GIMMICK_SOUND_OBJS_ARC_ID 0x94
#define FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT 5

/* The gimmick work slot that keeps the animation frames. */
#define FIELD_GIMMICK_SOUND_OBJS_SAVE_SLOT 1

/* Largest volume of a background music track. */
#define FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_MAX 0x7f

/* Volume step of the music fade, per frame. */
#define FIELD_GIMMICK_SOUND_OBJS_BGM_VOLUME_STEP 16

/* Number of camera heights kept by the sliding sound. */
#define FIELD_GIMMICK_SOUND_OBJS_SLIDE_HISTORY 32

/* Phases of the sliding sound. */
#define FIELD_GIMMICK_SOUND_OBJS_SLIDE_IDLE 0
#define FIELD_GIMMICK_SOUND_OBJS_SLIDE_PLAYING 1
#define FIELD_GIMMICK_SOUND_OBJS_SLIDE_FADING 2

/* The music track that fades with the camera height, and the heights where the fade starts and ends. */
typedef struct FieldGimmickSoundObjsBgmFade {
    u16 track;          /* 0x00 */
    u8 reserved02[2];
    float heightLow;    /* 0x04: volume 0 up to this camera height */
    float heightHigh;   /* 0x08: full volume above this camera height */
} FieldGimmickSoundObjsBgmFade;

/* State of the sliding sound effect (0x90 bytes). */
typedef struct FieldGimmickSoundObjsSlideSe {
    int prevZ;                              /* 0x00: camera z of the last frame */
    int cameraY[FIELD_GIMMICK_SOUND_OBJS_SLIDE_HISTORY];   /* 0x04: ring of camera heights while z changes */
    short head;                               /* 0x84: oldest entry of the ring */
    short count;                              /* 0x86: entries in the ring */
    short volume;                             /* 0x88: volume of the fade out */
    u16 state;                              /* 0x8A: FIELD_GIMMICK_SOUND_OBJS_SLIDE_* */
    u16 seId;                               /* 0x8C: sound effect that plays */
    u8 reserved8E[2];
} FieldGimmickSoundObjsSlideSe;

/* Work of the gimmick (0xF8 bytes, common work id 0 of the field map). */
typedef struct FieldGimmickSoundObjsWork {
    u16 heapId;                                             /* 0x00 */
    u16 reserved02;
    struct Iss3dsSys *iss3ds;                               /* 0x04 */
    struct SoundObj *soundObj[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];   /* 0x08 */
    int waitFrames[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];              /* 0x1C: frames left before the animation starts again; 0 while it plays */
    int minWait[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];                 /* 0x30: shortest wait */
    int maxWait[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];                 /* 0x44: longest wait */
    FieldGimmickSoundObjsBgmFade bgmFade;                               /* 0x58 */
    int bgmVolume;                                          /* 0x64 */
    FieldGimmickSoundObjsSlideSe slideSe;                               /* 0x68 */
} FieldGimmickSoundObjsWork;

/* The animation frames (in whole frames) in the gimmick work. */
typedef struct FieldGimmickSoundObjsSave {
    int animeFrame[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];
} FieldGimmickSoundObjsSave;

/* Archive members that hold the wait limits of each object. */
typedef struct FieldGimmickSoundObjsWaitMembers {
    int member[FIELD_GIMMICK_SOUND_OBJS_SOUND_OBJ_COUNT];
} FieldGimmickSoundObjsWaitMembers;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);
extern void GFL_USE_SetBgmTrackVolume(u32 track, u32 volume);
extern int SOUND_OBJ_Delete(struct SoundObj *obj);
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern void FIELD_CAMERA_GetEyeRaw(struct FieldCamera *camera, VecFx32 *eye);
extern void FIELD_CAMERA_GetTargetRaw(struct FieldCamera *camera, VecFx32 *target);
extern void ISS_3DS_SYS_SetCamera(struct Iss3dsSys *iss3ds, VecFx32 *eye, VecFx32 *target);
extern u32 SOUND_OBJ_AdvanceAnime(struct SoundObj *obj, s32 deltaFrame);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct IssSystem *GAMESYSTEM_GetIssSystem(struct GameSystem *gameSystem);
extern struct Iss3dsSys *ISS_SYS_Get3dsSys(struct IssSystem *issSystem);
extern int *ARC_TOOL_LoadMember(u32 archiveId, u32 member, u32 heapId);
extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archiveId, u32 member, u32 offset, u32 size);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct SoundObj *SOUND_OBJ_Create(struct FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 radius, u32 amplitude);
extern struct SoundObj *SOUND_OBJ_CreateNoSource(struct FieldMap *fieldMap, G3dObjectStatus *target);
extern void SOUND_OBJ_SetAnime(struct SoundObj *obj, u32 arcId, u32 dataId, u32 bufferFrames);
extern u32 GFL_HEAP_Free(void *p);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern FieldGimmickSoundObjsSave *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickWork, u32 slotId);
extern u32 SOUND_OBJ_GetAnimeFrame(struct SoundObj *obj);
extern void SOUND_OBJ_SetAnimeFrame(struct SoundObj *obj, s32 frame);
extern unsigned GFL_USE_GetRandomBelow(unsigned limit);
extern void MIi_CpuClear32(int value, void *dst, unsigned int size);
extern void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *expObj);

void FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(FieldGimmickSoundObjsSlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer);

#endif
