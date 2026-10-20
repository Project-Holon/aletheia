#ifndef ALETHEIA_OV058_FIELD_GIMMICK_LANE_TRAINS_TYPES_H
#define ALETHEIA_OV058_FIELD_GIMMICK_LANE_TRAINS_TYPES_H

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
#include "../sdk_fx.h"

typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct G3dUtilSetup G3dUtilSetup;

#include "../arm9/g3d_system_types.h"
#endif

struct FieldMap;
struct FieldPlayer;
struct GameSystem;
struct GameData;
struct GimmickWork;

#define FIELD_GIMMICK_LANE_TRAINS_LANE_COUNT       3
#define FIELD_GIMMICK_LANE_TRAINS_MODELS_PER_LANE  4

/* The track runs along x between these two positions (fx32). */
#define FIELD_GIMMICK_LANE_TRAINS_TRACK_MIN_X      0x1770000
#define FIELD_GIMMICK_LANE_TRAINS_TRACK_MAX_X      0x1C60000
/* How far the trail model stays behind the lead model. */
#define FIELD_GIMMICK_LANE_TRAINS_TRAIL_GAP        0x60000
/* Height of the models. */
#define FIELD_GIMMICK_LANE_TRAINS_TRAIN_Y          0x50000
/* The z of the eastbound and the westbound track. */
#define FIELD_GIMMICK_LANE_TRAINS_EAST_TRACK_Z     0x2100000
#define FIELD_GIMMICK_LANE_TRAINS_WEST_TRACK_Z     0x20B0000
/* The player hears a train while the player stands in this z range. */
#define FIELD_GIMMICK_LANE_TRAINS_HEAR_MIN_Z       0x2020000
#define FIELD_GIMMICK_LANE_TRAINS_HEAR_MAX_Z       0x2140000
/* The player hears it when the lead model is at most this far ahead of the player. */
#define FIELD_GIMMICK_LANE_TRAINS_HEAR_DISTANCE    0x40000

/* Movement state of one train (8 bytes). */
typedef struct FieldGimmickLaneTrainsTrain {
    int  step;          /* 0x00: frames moved along the track, 1.0 per frame */
    u16  waitFrames;    /* 0x04: frames to wait before the next run */
    u16  lane;          /* 0x06: lane (0..2) of the current run */
} FieldGimmickLaneTrainsTrain;

/* The common work of the gimmick on the field map (0x20 bytes, id 1). */
typedef struct FieldGimmickLaneTrainsWork {
    u8             pad00[8];            /* 0x00: never read */
    FieldGimmickLaneTrainsTrain eastbound;           /* 0x08: moves towards larger x */
    int            eastSoundPlayed;     /* 0x10: the pass sound was started for this run */
    FieldGimmickLaneTrainsTrain westbound;           /* 0x14: moves towards smaller x */
    int            westSoundPlayed;     /* 0x1C */
} FieldGimmickLaneTrainsWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
#include "../ov021/fld_exp_obj.h"
extern void MTX_RotY33_(MtxFx33 *matrix, s32 sin, s32 cos);

/* Sine and cosine of each angle step (short pairs, arm9 table). */
extern short FX_SinCosTable_[];

#endif
