#ifndef ALETHEIA_OV041_FIELD_GIMMICK_CANNONS_TYPES_H
#define ALETHEIA_OV041_FIELD_GIMMICK_CANNONS_TYPES_H

/*
 * Field gimmick 41 (overlay 41): ten cannons. The player steps up to a
 * cannon, an animation file (ICA) moves the player along a flight path while
 * the field camera follows, and the cannon models play two animations per
 * direction. Names are a best guess from the behavior.
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
typedef signed short s16;
typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;
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
struct FieldCamera;
struct FieldPlayer;
struct IcaAnime;
struct Mmdl;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

#define GIMMICK41_CANNON_COUNT 10
#define GIMMICK41_DIRECTION_COUNT 4

/* The camera bounce after the landing (0x10 bytes). */
typedef struct Gimmick41Bounce {
    int active;                 /* 0x00: the bounce runs */
    int finished;               /* 0x04: the bounce ended (two down steps made) */
    int cameraMoveStarted;      /* 0x08: the camera move to the player was started */
    u8  wait;                   /* 0x0C: frames left before the next step */
    u8  phase;                  /* 0x0D: 0 moves the camera up, 1 down */
    u8  downSteps;              /* 0x0E: down steps made */
    u8  tick;                   /* 0x0F: calls made */
} Gimmick41Bounce;

/* The common work of the gimmick on the field map (0x730 bytes, id 1). */
typedef struct Gimmick41Work {
    u8  cannonIndex;            /* 0x00: cannon the player uses */
    u8  facing;                 /* 0x01: player direction when stepping up */
    u8  flying;                 /* 0x02: the flight is running */
    u8  cameraArrived;          /* 0x03: the camera reached the landing view */
    u8  icaBuffer[0x708];       /* 0x04: buffer of the flight animation file */
    u8  padding[8];             /* 0x70C */
    struct IcaAnime *flightAnime;   /* 0x714 */
    u16 frame;                  /* 0x718: flight frame */
    u16 frameCount;             /* 0x71A: frames of the flight animation */
    u16 cameraFollowEndFrame;   /* 0x71C: frame the camera stops following the player */
    u16 cameraReturnFrames;     /* 0x71E: frames of the camera move back */
    Gimmick41Bounce bounce;     /* 0x720 */
} Gimmick41Work;

/* The cannon cells (grid x, y, z). */
typedef struct Gimmick41CannonCell {
    u16 x;
    u16 y;
    u16 z;
} Gimmick41CannonCell;

/* The flight of one cannon in one direction; -1 as the animation id means no flight. */
typedef struct Gimmick41Flight {
    int icaDataId;              /* 0x00: flight animation data id */
    int landX;                  /* 0x04: landing cell */
    int landY;                  /* 0x08 */
    int landZ;                  /* 0x0C */
    int cameraInfoIndex;        /* 0x10: Gimmick41CameraInfo of the flight */
} Gimmick41Flight;

/* The camera setting of a flight (8 bytes). */
typedef struct Gimmick41CameraInfo {
    u16 pitch;                  /* 0x00: camera pitch at the landing */
    u16 yaw;                    /* 0x02: camera yaw at the landing */
    u8  moveFrames;             /* 0x04: frames of the move to the landing view */
    u8  followFrames;           /* 0x05: frames the camera follows the player */
    u8  returnFrames;           /* 0x06: frames of the move back */
    u8  reserved;               /* 0x07 */
} Gimmick41CameraInfo;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern void FIELD_CAMERA_GetEyeRaw(struct FieldCamera *camera, VecFx32 *out);
extern void FIELD_CAMERA_SetEyeRaw(struct FieldCamera *camera, const VecFx32 *eye);

/* The bounce functions (the last two live in the unplaced file). */
void GIMMICK41_StartBounce(Gimmick41Work *work);
void GIMMICK41_ResetBounce(Gimmick41Bounce *bounce);
void GIMMICK41_UpdateBounce(Gimmick41Bounce *bounce, struct FieldCamera *camera);

#endif
