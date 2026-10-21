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
 * The expansion object and model types come from ov021/fld_exp_obj_types.h.
 */

#include "../ov021/fld_exp_obj_types.h"

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
#include "../ov021/fld_exp_obj.h"

void FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(FieldGimmickSoundObjsSlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer);

#endif
