#ifndef OV020_EL_SCOREBOARD_TYPES_H
#define OV020_EL_SCOREBOARD_TYPES_H

/*
 * Types of the season scoreboard (el_scoreboard.c, ov020).
 *
 * The including file defines u8, u16 and u32 first.
 */

typedef struct ElTexResult {
    u16 texIndex;
    u16 plttIndex;
    int texAddr;
    int plttSlot;
    int texVram;
    int plttVram;
} ElTexResult;

/* Scoreboard lamp palette animation state (0x1C bytes). */
typedef struct ElLamp {
    int flags;
    u16 texIndex;
    u16 plttIndex;
    int texAddr;
    int plttSlot;
    int texVram;
    u32 plttVram;
    int tick;
} ElLamp;

typedef struct ElLampPaletteRef {
    int index;
    u32 base;
} ElLampPaletteRef;

/* Called once when the scoreboard event ends (ELSCOREBOARD_CallFinishCallback). */
typedef void (*ElScoreboardCallback)(int arg);

/* Work of the season scoreboard event (0x28 bytes). */
typedef struct ElScoreboardWork {
    void *gameSystem;
    void *fieldMap;
    u16 heapId;
    u8 pad0A[2];
    u32 mode;                         /* 0: shares the field display, 1: standalone */
    u32 finished;                     /* set by the finish request */
    u8 targetSeason;                  /* season the board turns to */
    u8 shownSeason;                   /* season the board shows now */
    u8 pad16[2];
    u32 stateTimer;
    u32 stateDuration;
    ElScoreboardCallback finishCallback;
    int finishCallbackArg;
} ElScoreboardWork;

#endif
