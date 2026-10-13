#ifndef ALETHEIA_OV058_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV058_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 58 (overlay 58): two trains pass the player on a track, one
 * eastbound and one westbound. Each train is a pair of expansion models (a
 * lead and a trail model 0x60000 behind it). Three sets of four models exist
 * (model index = lane * 4 + 0..3: eastbound lead and trail, westbound lead
 * and trail); a train picks a random lane, runs along the track, then waits a
 * random time. The player hears a sound when a train passes in front.
 */

/*
 * The expansion object types come from ov021/fld_exp_obj_types.h, which the
 * source file includes first (the compiler resolves includes against the
 * source file directory, so this header cannot include it). A file that does
 * not include it gets the few types it needs from the fallback below.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct G3dUtilSetup G3dUtilSetup;

/* Position, scale and rotation of a model (same layout as arm9 g3d_system_types.h). */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;
#endif

struct FieldMap;
struct FieldPlayer;
struct GameSystem;
struct GameData;
struct GimmickWork;

#define GIMMICK58_LANE_COUNT       3
#define GIMMICK58_MODELS_PER_LANE  4

/* The track runs along x between these two positions (fx32). */
#define GIMMICK58_TRACK_MIN_X      0x1770000
#define GIMMICK58_TRACK_MAX_X      0x1C60000
/* How far the trail model stays behind the lead model. */
#define GIMMICK58_TRAIL_GAP        0x60000
/* Height of the models. */
#define GIMMICK58_TRAIN_Y          0x50000
/* The z of the eastbound and the westbound track. */
#define GIMMICK58_EAST_TRACK_Z     0x2100000
#define GIMMICK58_WEST_TRACK_Z     0x20B0000
/* The player hears a train while the player stands in this z range. */
#define GIMMICK58_HEAR_MIN_Z       0x2020000
#define GIMMICK58_HEAR_MAX_Z       0x2140000
/* The player hears it when the lead model is at most this far ahead of the player. */
#define GIMMICK58_HEAR_DISTANCE    0x40000

/* Movement state of one train (8 bytes). */
typedef struct Gimmick58Train {
    int  step;          /* 0x00: frames moved along the track, 1.0 per frame */
    u16  waitFrames;    /* 0x04: frames to wait before the next run */
    u16  lane;          /* 0x06: lane (0..2) of the current run */
} Gimmick58Train;

/* The common work of the gimmick on the field map (0x20 bytes, id 1). */
typedef struct Gimmick58Work {
    u8             pad00[8];            /* 0x00: never read */
    Gimmick58Train eastbound;           /* 0x08: moves towards larger x */
    int            eastSoundPlayed;     /* 0x10: the pass sound was started for this run */
    Gimmick58Train westbound;           /* 0x14: moves towards smaller x */
    int            westSoundPlayed;     /* 0x1C */
} Gimmick58Work;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void func_021BE4A4(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, int cullDraw);
extern void func_0207AF1C(MtxFx33 *matrix, s32 sin, s32 cos);

/* Sine and cosine of each angle step (short pairs, arm9 table). */
extern short d_020A1B38[];

#endif
