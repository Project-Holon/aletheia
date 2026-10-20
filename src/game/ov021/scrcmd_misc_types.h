#ifndef ALETHEIA_OV021_SCRCMD_MISC_TYPES_H
#define ALETHEIA_OV021_SCRCMD_MISC_TYPES_H

/*
 * Work blocks of the script command handlers and field events in
 * scrcmd_misc.c. Offsets come from every access in that file.
 */

#include "../types.h"

struct IcaAnime;
struct Mmdl;
struct FieldSubproc;
struct FieldSubscreen;
struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldPlayer;
struct PerapVoice;
struct PokemonParam;
struct FieldMsgBg;
struct MsgBank;
struct FieldSysWin;
struct FieldMenuFunc;
struct WordSet;
struct Strbuf;
struct BmpWin;
struct TimeIcon;
struct Unit;
struct ClactActor;

/* Script-driven ICA animation on a field object (0x1A0 bytes, FIELD_SUBPROC work). */
typedef struct MmdlIcaWork {
    struct Mmdl *mmdl;        /* 0x00: field object the animation moves */
    u8 icaBuffer[0x180];      /* 0x04: stream buffer of the ICA animation */
    struct IcaAnime *icaAnime; /* 0x184 */
    struct FieldSubproc *subprocHandle; /* 0x188 */
    VecFx32 offset;           /* 0x18C: start offset added to the translation */
    u8 pad198;                /* 0x198 */
    u8 animKind;              /* 0x199: index into the dir-restore table */
    u8 state;                 /* 0x19A: 0 idle, 1 playing */
    u8 pad19B;
    u16 heapId;               /* 0x19C */
} MmdlIcaWork;

/* Event task work of the ICA wait command (4 bytes). */
typedef struct MmdlIcaWaitWork {
    MmdlIcaWork *ica;         /* 0x00 */
} MmdlIcaWaitWork;

/* Chatot cry recording event (0x58 bytes, task work of EVENT_PERAP_RECORD_Main). */
typedef struct PerapRecordWork {
    struct PerapVoice *perapVoice; /* 0x00 */
    struct GameSystem *gameSystem; /* 0x04 */
    struct GameData *gameData;     /* 0x08 */
    struct FieldMap *fieldMap;     /* 0x0C */
    struct FieldPlayer *fieldPlayer; /* 0x10 */
    struct PokemonParam *partyMon; /* 0x14 */
    struct MsgBank *msgData;       /* 0x18 */
    struct FieldMsgBg *msgBg;      /* 0x1C */
    struct FieldSysWin *sysWin;    /* 0x20 */
    struct FieldMenuFunc *yesNoMenu; /* 0x24 */
    struct WordSet *wordSet;       /* 0x28 */
    struct Strbuf *msgBuf;         /* 0x2C */
    struct BmpWin *bmpWin;         /* 0x30 */
    struct TimeIcon *timeIcon;     /* 0x34 */
    struct Unit *clactUnit;        /* 0x38 */
    struct ClactActor *clactActor;      /* 0x3C */
    u32 charRes;              /* 0x40 */
    u32 palRes;               /* 0x44 */
    u32 cellRes;              /* 0x48 */
    u8 hopCount;              /* 0x4C */
    s8 hopSpeed;              /* 0x4D */
    u8 partySlot;             /* 0x4E */
    u8 pad4F;
    u32 voiceHandle;          /* 0x50: sound slot of the playing voice */
    int recordDone;           /* 0x54 */
} PerapRecordWork;

/* Poke icon window task work (0x18 bytes). */
typedef struct PokeIconWork {
    struct BmpWin *bmpWin;    /* 0x00 */
    struct Unit *clactUnit;   /* 0x04 */
    struct ClactActor *clactActor; /* 0x08 */
    u32 charRes;              /* 0x0C */
    u32 palRes;               /* 0x10 */
    u32 cellRes;              /* 0x14 */
} PokeIconWork;

/* Subscreen mode change task work (8 bytes). */
typedef struct SubscreenModeWork {
    struct FieldSubscreen *subscreen; /* 0x00: subscreen manager */
    u32 mode;                 /* 0x04: mode to switch to */
} SubscreenModeWork;

/* Subscreen animation task work (8 bytes). */
typedef struct SubscreenAnimWork {
    struct FieldMap *fieldMap;        /* 0x00 */
    struct FieldSubscreen *subscreen; /* 0x04 */
} SubscreenAnimWork;

/* Ripple warp event task work (0x10 bytes). */
typedef struct RippleWarpWork {
    struct GameSystem *gameSystem;    /* 0x00: owner passed to the task */
    struct FieldMap *fieldMap;        /* 0x04 */
    int useSpin;              /* 0x08: nonzero adds the spin effects */
    int waitFrames;           /* 0x0C */
} RippleWarpWork;

/* Camera shake setup, copied into the head of CameraShakeWork (0x18 bytes). */
typedef struct CameraShakeParams {
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    u16 thresh;
    u16 cnt;
    u16 period;
    u8 total;
    u8 left;
    u32 steps;
    u32 tick;
} CameraShakeParams;

#endif
