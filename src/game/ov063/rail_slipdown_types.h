#ifndef GAME_OV063_RAIL_SLIPDOWN_TYPES_H
#define GAME_OV063_RAIL_SLIPDOWN_TYPES_H

/* ov063: the slip down effect on a rail map. A field model (or the player)
 * at a rail edge slides along its facing direction and down onto the rail
 * below while the camera follows. Needs fldmmdl_rail_types.h of ov021
 * (u8, u16, s16, RailLocation) from the includer. */

typedef unsigned int u32;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

struct FieldNogridMapper;
struct FieldPlayer;
struct Mmdl;
struct FieldEffectSys;
struct TcbTask;
struct RailWork;
struct RailManager;
struct FieldCamera;

/* Steps of the task (RailSlipdown.state). States 2, 3, 6 and 7 are not used. */
#define SLIPDOWN_STATE_FIND_LANDING   0   /* looks for the landing place below */
#define SLIPDOWN_STATE_WAIT_CAMERA    1   /* waits for the camera delay of the player, then moves the camera */
#define SLIPDOWN_STATE_START_SLIDE    4   /* plays the sound, pauses the model */
#define SLIPDOWN_STATE_SLIDE          5   /* one step of the slide per frame */
#define SLIPDOWN_STATE_FINISH         8   /* places the model at the landing place */
#define SLIPDOWN_STATE_DONE           9

typedef struct SlipdownDir {
    s16 x;
    s16 y;
    s16 z;
} SlipdownDir;

/* Work of the effect (0x84 bytes), allocated by RAIL_SLIPDOWN_Create. */
typedef struct RailSlipdown {
    u32 state;                              /* 0x00 SLIPDOWN_STATE_* */
    struct FieldNogridMapper *nogridMapper; /* 0x04 */
    struct RailWork *railWork;              /* 0x08 rail work of the model */
    struct FieldPlayer *player;             /* 0x0C the field player when the model is the player, else 0 */
    struct Mmdl *mmdl;                      /* 0x10 the model that slides */
    struct FieldEffectSys *effectSys;       /* 0x14 dust effect every second step */
    struct FieldCamera *camera;             /* 0x18 */
    u32 reserved1C;                         /* 0x1C */
    VecFx32 start;                          /* 0x20 first point of the slide */
    VecFx32 end;                            /* 0x2C landing point */
    SlipdownDir dir;                        /* 0x38 unit vector from start to end */
    u16 reserved3E;                         /* 0x3E */
    int step;                               /* 0x40 steps done */
    int count;                              /* 0x44 steps of the whole slide */
    VecFx32 eyeStart;                       /* 0x48 camera eye before the slide */
    VecFx32 targetStart;                    /* 0x54 camera target before the slide */
    VecFx32 eyeDelta;                       /* 0x60 camera eye change over the slide */
    VecFx32 targetDelta;                    /* 0x6C camera target change over the slide */
    RailLocation landing;                   /* 0x78 rail location of the landing place */
    struct TcbTask *task;                   /* 0x80 task that runs the slide */
} RailSlipdown;

#endif
