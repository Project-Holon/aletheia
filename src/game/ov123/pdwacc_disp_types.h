/* Work areas of the Dream World account proc (pdwacc_disp.c). */
#ifndef PDWACC_DISP_TYPES_H
#define PDWACC_DISP_TYPES_H

#include "gsync_common_types.h"
#include "pdwacc_message_types.h"

#define PDWACC_BG_PALETTE_COUNT 15      /* palettes of the animated layer */
#define PDWACC_BG_PALETTE_FRAMES 60     /* 15 palettes, 4 blend steps each */
#define PDWACC_ACTOR_COUNT 13
#define PDWACC_RESOURCE_COUNT 9         /* 3 palettes, 3 characters, 3 cell animations */

/* Arguments the caller hands to the proc; the proc sets finished on exit. */
typedef struct PdwaccProcParam {
    void *gameData;     /* 0x00 */
    int connectionArg;  /* 0x04, third argument of NHTTP_RAP_Create */
    u16 heap;           /* 0x08 */
    u8 unused_0A[2];    /* alignment */
    int startMode;      /* 0x0C, 0: start with the intro message, 1: start with the result message */
    int finished;       /* 0x10, cleared on init, set to 1 on exit */
} PdwaccProcParam;

/* Animated palette of the background: the task receives a pointer to this part of the display work. */
typedef struct PdwaccPaletteAnim {
    void *task;                         /* 0x000 */
    u32 enabled;                        /* 0x004 */
    u16 basePalettes[PDWACC_BG_PALETTE_COUNT][16];      /* 0x008 */
    u16 blendedPalettes[PDWACC_BG_PALETTE_FRAMES][16];  /* 0x1E8 */
    s16 frame;                          /* 0x968 */
    u8 unused_96A;                      /* never accessed */
    u8 halfStep;                        /* 0x96B, toggled each call, the palette loads on even calls */
    u8 bgLayer;                         /* 0x96C */
    u8 unused_96D[3];                   /* never accessed */
} PdwaccPaletteAnim;

/* Work area of the display part: animated palette, sprite system, actors. Allocated with 0xB70 bytes. */
typedef struct PdwaccDispWork {
    u8 unused_00[8];                    /* never accessed */
    PdwaccPaletteAnim palette;          /* 0x008 */
    u8 unused_978[4];                   /* never accessed */
    void *clactUnit;                    /* 0x97C */
    void *vblankTask;                   /* 0x980 */
    void *unusedTask;                   /* 0x984, deleted on exit if set, never set here */
    void *clactResources[PDWACC_RESOURCE_COUNT];        /* 0x988 */
    u8 unused_9AC[4];                   /* never accessed */
    struct ClActor *actors[PDWACC_ACTOR_COUNT];         /* 0x9B0 */
    u16 heap;                           /* 0x9E4 */
    u8 unused_9E6[0x18A];               /* never accessed, allocation is 0xB70 bytes */
} PdwaccDispWork;

struct PdwaccProc;
typedef void (*PdwaccStateFunc)(struct PdwaccProc *proc);

/* Work area of the proc, 0x74 bytes. */
typedef struct PdwaccProc {
    u16 heap;                           /* 0x00 */
    u8 unused_02[2];                    /* alignment */
    void *unusedAlloc04;                /* 0x04, freed on exit if set, never set */
    void *connection;                   /* 0x08, NHTTP request object */
    PdwaccDispWork *disp;               /* 0x0C */
    PdwaccMessageWork *message;         /* 0x10 */
    void *yesNoMenu;                    /* 0x14, task menu while open */
    u8 unused_18[4];                    /* never accessed */
    void *saveControl;                  /* 0x1C */
    void *gameData;                     /* 0x20 */
    void *unusedAlloc24;                /* 0x24, freed on exit if set, never set */
    u32 profileId;                      /* 0x28, number shown to the player */
    u8 unused_2C[4];                    /* never accessed */
    PdwaccStateFunc state;              /* 0x30 */
    u8 unused_34[0x38];                 /* never accessed */
    int saving;                         /* 0x6C, nonzero between SaveStart and SaveMain end */
    u32 errorCode;                      /* 0x70 */
} PdwaccProc;

#endif
