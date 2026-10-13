#ifndef ALETHEIA_OV053_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV053_UNIT_021F36C0_TYPES_H

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
#define GIMMICK53_ARC_ID 0x94
#define GIMMICK53_SOUND_OBJ_COUNT 5

/* The gimmick work slot that keeps the animation frames. */
#define GIMMICK53_SAVE_SLOT 1

/* Largest volume of a background music track. */
#define GIMMICK53_BGM_VOLUME_MAX 0x7f

/* Volume step of the music fade, per frame. */
#define GIMMICK53_BGM_VOLUME_STEP 16

/* Number of camera heights kept by the sliding sound. */
#define GIMMICK53_SLIDE_HISTORY 32

/* Phases of the sliding sound. */
#define GIMMICK53_SLIDE_IDLE 0
#define GIMMICK53_SLIDE_PLAYING 1
#define GIMMICK53_SLIDE_FADING 2

/* The music track that fades with the camera height, and the heights where the fade starts and ends. */
typedef struct Gimmick53BgmFade {
    u16 track;          /* 0x00 */
    u8 reserved02[2];
    float heightLow;    /* 0x04: volume 0 up to this camera height */
    float heightHigh;   /* 0x08: full volume above this camera height */
} Gimmick53BgmFade;

/* State of the sliding sound effect (0x90 bytes). */
typedef struct Gimmick53SlideSe {
    int prevZ;                              /* 0x00: camera z of the last frame */
    int cameraY[GIMMICK53_SLIDE_HISTORY];   /* 0x04: ring of camera heights while z changes */
    short head;                               /* 0x84: oldest entry of the ring */
    short count;                              /* 0x86: entries in the ring */
    short volume;                             /* 0x88: volume of the fade out */
    u16 state;                              /* 0x8A: GIMMICK53_SLIDE_* */
    u16 seId;                               /* 0x8C: sound effect that plays */
    u8 reserved8E[2];
} Gimmick53SlideSe;

/* Work of the gimmick (0xF8 bytes, common work id 0 of the field map). */
typedef struct Gimmick53Work {
    u16 heapId;                                             /* 0x00 */
    u16 reserved02;
    struct Iss3dsSys *iss3ds;                               /* 0x04 */
    struct SoundObj *soundObj[GIMMICK53_SOUND_OBJ_COUNT];   /* 0x08 */
    int waitFrames[GIMMICK53_SOUND_OBJ_COUNT];              /* 0x1C: frames left before the animation starts again; 0 while it plays */
    int minWait[GIMMICK53_SOUND_OBJ_COUNT];                 /* 0x30: shortest wait */
    int maxWait[GIMMICK53_SOUND_OBJ_COUNT];                 /* 0x44: longest wait */
    Gimmick53BgmFade bgmFade;                               /* 0x58 */
    int bgmVolume;                                          /* 0x64 */
    Gimmick53SlideSe slideSe;                               /* 0x68 */
} Gimmick53Work;

/* The animation frames (in whole frames) in the gimmick work. */
typedef struct Gimmick53Save {
    int animeFrame[GIMMICK53_SOUND_OBJ_COUNT];
} Gimmick53Save;

/* Archive members that hold the wait limits of each object. */
typedef struct Gimmick53WaitMembers {
    int member[GIMMICK53_SOUND_OBJ_COUNT];
} Gimmick53WaitMembers;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern FldExpObjAnime *func_021BE674(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);
extern void GFL_USE_SetBgmTrackVolume(u32 track, u32 volume);
extern int func_021C4DA8(struct SoundObj *obj);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern void func_0218ECE4(struct FieldCamera *camera, VecFx32 *eye);
extern void func_0218ECB4(struct FieldCamera *camera, VecFx32 *target);
extern void ISS_3DS_SYS_SetCamera(struct Iss3dsSys *iss3ds, VecFx32 *eye, VecFx32 *target);
extern u32 func_021C4DE4(struct SoundObj *obj, s32 deltaFrame);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct IssSystem *func_02012134(struct GameSystem *gameSystem);
extern struct Iss3dsSys *func_0202B57C(struct IssSystem *issSystem);
extern int *func_02048F60(u32 archiveId, u32 member, u32 heapId);
extern void func_02048F74(void *dst, u32 archiveId, u32 member, u32 offset, u32 size);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct SoundObj *func_021C4D14(struct FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 radius, u32 amplitude);
extern struct SoundObj *func_021C4D7C(struct FieldMap *fieldMap, G3dObjectStatus *target);
extern void func_021C4DC0(struct SoundObj *obj, u32 arcId, u32 dataId, u32 bufferFrames);
extern u32 func_020307B0(void *p);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern Gimmick53Save *func_0200B3A4(struct GimmickWork *gimmickWork, u32 slotId);
extern u32 func_021C4E20(struct SoundObj *obj);
extern void func_021C4E08(struct SoundObj *obj, s32 frame);
extern unsigned func_02005728(unsigned limit);
extern void func_02082A7C(int value, void *dst, unsigned int size);
extern void func_021BE580(FldExpObjCnt *expObj);

void func_021F3B40(Gimmick53SlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer);

#endif
