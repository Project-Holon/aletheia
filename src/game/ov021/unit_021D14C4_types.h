#ifndef ALETHEIA_OV021_UNIT_021D14C4_TYPES_H
#define ALETHEIA_OV021_UNIT_021D14C4_TYPES_H

/*
 * Work blocks of the script command handlers and field events in
 * unit_021D14C4.c. Offsets come from every access in that file.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

struct IcaAnime;

/* Script-driven ICA animation on a field object (0x1A0 bytes, FIELD_SUBPROC work). */
typedef struct MmdlIcaWork {
    void *mmdl;               /* 0x00: field object the animation moves */
    u8 icaBuffer[0x180];      /* 0x04: stream buffer of the ICA animation */
    struct IcaAnime *icaAnime; /* 0x184 */
    void *subprocHandle;      /* 0x188 */
    int offset[3];            /* 0x18C: start offset added to the translation */
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
    void *perapVoice;         /* 0x00 */
    void *gameSystem;         /* 0x04 */
    void *gameData;           /* 0x08 */
    void *fieldMap;           /* 0x0C */
    void *fieldPlayer;        /* 0x10 */
    void *partyMon;           /* 0x14 */
    void *msgData;            /* 0x18 */
    void *msgBg;              /* 0x1C */
    void *sysWin;             /* 0x20 */
    void *yesNoMenu;          /* 0x24 */
    void *wordSet;            /* 0x28 */
    void *msgBuf;             /* 0x2C */
    u32 bmpWin;               /* 0x30 */
    void *timeIcon;           /* 0x34 */
    u32 clactUnit;            /* 0x38 */
    u32 clactActor;           /* 0x3C */
    u32 charRes;              /* 0x40 */
    u32 palRes;               /* 0x44 */
    u32 cellRes;              /* 0x48 */
    u8 hopCount;              /* 0x4C */
    s8 hopSpeed;              /* 0x4D */
    u8 partySlot;             /* 0x4E */
    u8 pad4F;
    void *voiceHandle;        /* 0x50 */
    int recordDone;           /* 0x54 */
} PerapRecordWork;

/* Poke icon window task work (0x18 bytes). */
typedef struct PokeIconWork {
    u32 bmpWin;               /* 0x00 */
    u32 clactUnit;            /* 0x04 */
    u32 clactActor;           /* 0x08 */
    u32 charRes;              /* 0x0C */
    u32 palRes;               /* 0x10 */
    u32 cellRes;              /* 0x14 */
} PokeIconWork;

/* Subscreen mode change task work (8 bytes). */
typedef struct SubscreenModeWork {
    u32 subscreen;            /* 0x00: subscreen manager */
    u32 mode;                 /* 0x04: mode to switch to */
} SubscreenModeWork;

/* Subscreen animation task work (8 bytes). */
typedef struct SubscreenAnimWork {
    u32 fieldWork;            /* 0x00 */
    u32 subscreen;            /* 0x04 */
} SubscreenAnimWork;

/* Ripple warp event task work (0x10 bytes). */
typedef struct RippleWarpWork {
    void *field;              /* 0x00: owner passed to the task */
    u32 fieldWork;            /* 0x04 */
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
