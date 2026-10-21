#ifndef ALETHEIA_OV054_FIELD_GIMMICK_SOUND_OBJS_B_TYPES_H
#define ALETHEIA_OV054_FIELD_GIMMICK_SOUND_OBJS_B_TYPES_H

/*
 * Field gimmick 54 (overlay 54): two 3D sound objects that follow models of
 * the expansion unit. Each plays its animation once, waits a random time
 * between its limits, and plays it again. The frame of each animation is
 * kept in the gimmick work (slot 11) while the map is left.
 *
 * The expansion object and model types come from ov021/fld_exp_obj_types.h.
 */

#include "../ov021/fld_exp_obj_types.h"

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
#include "../ov021/fld_exp_obj.h"

void FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(FieldGimmickSoundObjsBWork *work, int index);

#endif
