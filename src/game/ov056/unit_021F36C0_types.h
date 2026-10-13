#ifndef ALETHEIA_OV056_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV056_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 56 (overlay 56): a camera demo with four variants. A script
 * command starts the demo (FIELD_FK_DEMO event). The event
 *   - hides the player's move model and shows a stand-in 3D player model
 *     (model and animations from archive 0x96, the model depends on the
 *     player's gender) that plays two animations,
 *   - takes over the field camera and drives it with an ICA animation, shifted
 *     by the demo origin (the set is built away from the map),
 *   - optionally plays an animation of a map building model, and
 *   - plays sound effects whose timing is stored in a second ICA animation
 *     (field_fk_sound_anime.c).
 * When the animations end it puts the camera and the player back.
 *
 * The overlay also holds four small field map procs (templates in the data
 * table at 0x021F4344) that play sound effects tied to a building animation
 * or to a script work variable.
 */

#include "../ov021/fieldmap_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct GameSystem;
struct GameData;
struct GameEvent;
struct MyStatus;
struct EventWork;
struct FieldPlayer;
struct FieldG3dMapper;
struct FieldmapFunc;
struct FieldSubproc;
struct FieldSubprocTemplate;
struct FieldSoundSystem;
struct Mmdl;
struct Tcb;
struct IcaAnime;
struct ArcFile;
struct G3dCamera;
struct G3dResource;
struct G3dRender;
struct G3dAnime;
struct G3dObject;
struct BuildModelMan;
struct BuildModelEntry;
struct BuildModelNode;

/* Field camera mode FIELD_CAMERA_MODE_FREE (ov021 field_camera_types.h): eye and target follow their own sources. */
#define FK_CAMERA_MODE_FREE     2

/* Number of demo variants (script slot - 1). */
#define FK_DEMO_VARIANT_COUNT   4

/* Archive 0x96 holds the demo files. */
#define FK_DEMO_ARC_ID          0x96
#define FK_DEMO_CAMERA_FILE     0x18    /* + variant: ICA animation of the camera */
#define FK_SOUND_ANIME_FILE     0x1C    /* + variant: ICA animation that triggers sounds */
#define FK_DEMO_MODEL_FILE_STEP 6       /* files per variant for the player model */

/* Frames of an animation are fx32 values; one tick is one frame. */
#define FK_FRAME_ONE            0x1000

/* Value of an ICA channel that starts / stops a sound effect of the sound anime. */
#define FK_SOUND_CHANNEL_PLAY   0x1000
#define FK_SOUND_CHANNEL_STOP   0x2000
#define FK_SOUND_CHANNEL_COUNT  9       /* translate xyz, scale xyz, rotate xyz */
#define FK_SOUND_NONE           0xFFFF

/* Script work variable that stops the ambient sounds of the gimmick when it is not 0. */
#define FK_AMBIENT_STOP_WORK_ID 0x4001

/* Sound effects. */
#define FK_SE_BUILD_ANIME_LOOP  0x746   /* plays while the building animation runs */
#define FK_SE_BUILD_ANIME_HIT   0x692   /* at the trigger frame of the building animation */
#define FK_SE_FRAME_HIT         0x743   /* at the listed frames */
#define FK_SE_FRAME_HIT_END     0x76E   /* when the countdown after the hit ends */
#define FK_SE_AMBIENT_A         0x756
#define FK_SE_AMBIENT_B         0x7EF

/* Position, scale and rotation a 3D object is drawn with (same layout as arm9 g3d_system_types.h). */
typedef struct MtxFx33 {
    int m[9];
} MtxFx33;

typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

/* The head of a NitroSystem animation object and of its animation resource (only the fields read here). */
typedef struct G3dAnmResHead {
    u8 pad00[4];
    u16 frameCount;                     /* 0x04 */
} G3dAnmResHead;

typedef struct G3dAnmObjHead {
    u8 pad00[8];
    G3dAnmResHead *res;                 /* 0x08 */
} G3dAnmObjHead;

/*
 * The stand-in player model of the demo (0x80 bytes, FkDemoWork.model). The
 * model resource is chosen by the player's gender; the first animation gives
 * the length of the demo.
 */
typedef struct FkDemoModel {
    struct G3dResource *modelRes;       /* 0x00 */
    struct G3dResource *sharedAnimeRes; /* 0x04: animation for both genders */
    struct G3dResource *genderAnimeRes; /* 0x08: animation of the chosen gender */
    int uploadPending;                  /* 0x0C: 1 until the model has been uploaded once */
    struct G3dRender *render;           /* 0x10 */
    struct G3dAnime *anime[2];          /* 0x14: [0] from sharedAnimeRes, [1] from genderAnimeRes; the first one gives the length */
    struct G3dObject *object;           /* 0x1C: render object with its two animations */
    G3dObjectStatus status;             /* 0x20 */
    int playerHidden;                   /* 0x5C: 1 while the real player model is hidden */
    struct MyStatus *myStatus;          /* 0x60 */
    struct FieldPlayer *player;         /* 0x64 */
    struct Mmdl *playerMmdl;            /* 0x68 */
    VecFx32 endTile;                    /* 0x6C: tile the player stands on after the demo */
    u16 endDir;                         /* 0x78: facing of the player after the demo */
    u16 endDirPad;                      /* 0x7A */
    int animeFrame;                     /* 0x7C: fx32 */
} FkDemoModel;

/* Camera state of the demo (0x30 bytes, FkDemoWork.camera): the saved field camera and the demo camera. */
typedef struct FkDemoCamera {
    struct IcaAnime *anime;             /* 0x00: camera path */
    struct G3dCamera *g3dCamera;        /* 0x04: camera the ICA animation drives */
    struct FieldCamera *fieldCamera;    /* 0x08 */
    u16 savedMode;                      /* 0x0C: field camera mode before the demo */
    u16 savedAreasEnabled;              /* 0x0E */
    VecFx32 savedTargetShift;           /* 0x10 */
    VecFx32 savedUp;                    /* 0x1C */
    int frame;                          /* 0x28: fx32 */
    u32 endSettingId;                   /* 0x2C: camera setting the field camera gets after the demo */
} FkDemoCamera;

/* A map building model whose animation runs with the demo (0xC bytes, FkDemoWork.buildAnime). */
typedef struct FkBuildModelAnime {
    struct BuildModelNode *node;        /* 0x00: 0 when the variant has none */
    struct BuildModelEntry *entry;      /* 0x04 */
    struct BuildModelMan *man;          /* 0x08 */
} FkBuildModelAnime;

/*
 * The sound anime (field_fk_sound_anime.c, 0x1C bytes): an ICA animation whose
 * nine channels are read as switches. A channel value of FK_SOUND_CHANNEL_PLAY
 * plays the sound of that channel, FK_SOUND_CHANNEL_STOP stops it.
 */
typedef struct FkSoundAnime {
    struct IcaAnime *anime;                     /* 0x00 */
    int frame;                                  /* 0x04: fx32 */
    u16 soundId[FK_SOUND_CHANNEL_COUNT];        /* 0x08: FK_SOUND_NONE for no sound */
} FkSoundAnime;

/* Work of the demo event (0xD4 bytes). */
typedef struct FkDemoWork {
    struct FieldMap *fieldMap;          /* 0x00 */
    struct GameSystem *gameSystem;      /* 0x04 */
    int variant;                        /* 0x08: 0..3 */
    FkDemoCamera camera;                /* 0x0C */
    FkDemoModel model;                  /* 0x3C */
    FkBuildModelAnime buildAnime;       /* 0xBC */
    FkSoundAnime *soundAnime;           /* 0xC8: 0 when the variant has none */
    struct FieldSubproc *drawProc;      /* 0xCC: field proc that draws the model */
    struct Tcb *uploadTcb;              /* 0xD0 */
} FkDemoWork;

/* Work of the draw proc: the model to draw. */
typedef struct FkDemoDrawWork {
    FkDemoModel *model;
} FkDemoDrawWork;

/* Work of the proc that ties sounds to a building animation (template 0x021F4344). */
typedef struct FkAnimeSoundWork {
    struct BuildModelMan *man;          /* 0x00 */
    struct BuildModelEntry *entry;      /* 0x04 */
    int triggerFrame;                   /* 0x08: building animation frame of the next trigger (fx32) */
    int triggerIndex;                   /* 0x0C */
} FkAnimeSoundWork;

/* Work of the proc that plays a sound at the listed frames (template 0x021F435C). */
typedef struct FkFrameSoundWork {
    struct BuildModelMan *man;          /* 0x00 */
    struct BuildModelEntry *entry;      /* 0x04 */
    u16 hitActive;                      /* 0x08: 1 while the countdown after a hit runs */
    s16 hitCountdown;                   /* 0x0A */
    struct FieldSoundSystem *soundSys;  /* 0x0C */
} FkFrameSoundWork;

/* Work of the procs that play an ambient sound until a script variable is set (templates 0x021F4374, 0x021F438C). */
typedef struct FkAmbientSoundWork {
    u16 *stopVar;                       /* 0x00: script work variable FK_AMBIENT_STOP_WORK_ID */
    u16 stopped;                        /* 0x04: 1 once the sound is stopped */
    u16 stoppedPad;                     /* 0x06 */
    struct EventWork *eventWork;        /* 0x08 */
    struct FieldSoundSystem *soundSys;  /* 0x0C */
} FkAmbientSoundWork;

typedef int (*FkDemoEventFunc)(struct GameEvent *event, int *seq, FkDemoWork *work);
typedef void (*FkDemoTcbFunc)(struct Tcb *tcb, FkDemoWork *work);

/* Data of the overlay. */
extern const u32 d_021F42B0[FK_DEMO_VARIANT_COUNT];                /* field camera setting id restored after the demo */
extern const struct FieldSubprocTemplate d_021F42C0;               /* draw only proc */
extern u32 d_021F4290[FK_DEMO_VARIANT_COUNT];                      /* 1: variant has a building animation */
extern VecFx32 d_021F42D8[FK_DEMO_VARIANT_COUNT];                  /* position of that building model */
extern const VecFx32 d_021F4338;                                   /* camera up vector */
extern const VecFx32 d_021F426C;                                   /* demo origin offset */
extern const VecFx32 d_021F4308[FK_DEMO_VARIANT_COUNT];            /* end tile of the player */
extern const u16 d_021F4264[FK_DEMO_VARIANT_COUNT];                /* end facing of the player */
extern u32 d_021F42A0[FK_DEMO_VARIANT_COUNT];                      /* 1: variant has a sound anime */
extern u16 d_021F43A4[][FK_SOUND_CHANNEL_COUNT];                   /* sound ids of the sound animes, one row per variant */
extern VecFx32 d_021F4278;                                         /* building model of the anime sound proc */
extern int d_021F4258[];                                           /* trigger frames of the anime sound proc */
extern VecFx32 d_021F4284;                                         /* building model of the frame sound proc */
extern int d_021F425C[];                                           /* frames of the frame sound proc */
extern char d_021F4400[];                                          /* source file name for allocations */

/* Field map accessors and shared helpers (overlay 21 and arm9). */
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern struct FieldG3dMapper *func_02188C98(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct FieldmapFunc *func_02188D24(struct FieldMap *fieldMap);
extern struct BuildModelMan *func_0218DC6C(struct FieldG3dMapper *mapper);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct FieldSoundSystem *func_02012A30(const struct GameData *gameData);
extern u8 func_02008550(const struct MyStatus *myStatus);
extern u16 *func_020143CC(struct EventWork *eventWork, u32 workId);
extern struct BuildModelEntry *func_0218C654(struct BuildModelMan *man, int kind, const VecFx32 *pos);
extern int func_0218C6F4(struct BuildModelMan *man, struct BuildModelEntry *entry, int animeId);
extern void func_02028A7C(struct FieldSoundSystem *soundSys, u32 seId);
extern void func_02028B50(struct FieldSoundSystem *soundSys, int seId);
extern u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime);
extern void func_020115EC(struct IcaAnime *anime, s32 frame);
extern void func_02011558(struct IcaAnime *anime);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);

/* Sound anime (field_fk_sound_anime.c). */
FkSoundAnime *func_021F4040(const void *soundIds, u32 arcId, u32 dataId, u32 bufFrameNum, u16 heapId);
void func_021F408C(FkSoundAnime *sound);
int func_021F40A0(FkSoundAnime *sound);
void func_021F4224(FkSoundAnime *sound, u32 channel);
void func_021F423C(FkSoundAnime *sound, u32 channel);

#endif
