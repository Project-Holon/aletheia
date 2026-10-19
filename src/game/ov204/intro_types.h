#ifndef INTRO_TYPES_H
#define INTRO_TYPES_H

#include "../types.h"

struct Obj;

struct WordSet;

struct Rec;

struct Rec3;

/* One slot of the intro command work: tag plus two data words. */
typedef struct Slot { unsigned data[3]; } Slot;

/* A 3D vector of ints (camera position and friends). */
typedef struct IntroVec { int v[3]; } IntroVec;

/*
 * One MCSS animation slot. The object pointer is the MCSS_Add result; the
 * MCSS anim callback (INTRO_G3D_OnAnimEnd) marks animFinished and, when
 * loopAnim is set, restarts the animation.
 */
typedef struct IntroMcssSlot {
    void *object;               /* 0x00: MCSS_Add result */
    unsigned int animFinished;  /* 0x04 */
    unsigned int loopAnim;      /* 0x08 */
} IntroMcssSlot;

/*
 * The intro MCSS effect object (0x6C allocated). Shared by intro_mcss.c
 * (create/delete/add) and intro_g3d.c (slot helpers).
 */
typedef struct IntroMcssWork {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad_2[2];
    void *sys;                  /* 0x04: MCSS_Init result */
    IntroMcssSlot slots[8];     /* 0x08 */
    unsigned int idleTimer;     /* 0x68: random idle countdown */
} IntroMcssWork;

/*
 * One script command row: a tag that selects a handler in the intro handler
 * table plus five data words handed to it. The scenario tables indexed by
 * INTRO_CMD_GetScenarioRow hold arrays of these. The low bit of the fifth
 * word is the "row accepted" flag read by INTRO_CMD_AddCommand.
 */
typedef union IntroCommandTail {
    unsigned int word;              /* 0x00: the whole fifth data word */
    struct { unsigned char flag : 1; } bits;
} IntroCommandTail;

typedef struct IntroCommand {
    unsigned int tag;               /* 0x00: handler table index */
    unsigned int data[4];           /* 0x04: handler arguments 0..3 */
    IntroCommandTail tail;          /* 0x14: fifth word; bit 0 is the flag */
} IntroCommand;

/* An opaque CLACT handle: created as a void pointer, released as an id. */
typedef union IntroHandle { void *ptr; unsigned int id; } IntroHandle;

/*
 * The intro command work (0x10D8 allocated). Created by INTRO_CMD_Create
 * (INTRO_CMD_Create in intro_cmd.c) and shared by intro_cmd.c (the command
 * handlers and the actor tables) and intro_graphic.c (the scenario handlers).
 * It starts with the 0xA8 command header, then the 4096-byte script data
 * block, then the actor handle tables.
 */
typedef struct IntroCmdWork {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad_2[2];
    void *args;                 /* 0x04: IntroArgs */
    void *mcss;                 /* 0x08: IntroMcssWork */
    void *g3d;                  /* 0x0C: IntroG3dWork (intro_g3d.c) */
    void *particle;             /* 0x10: INTRO_PARTICLE_Create result */
    void *display;              /* 0x14: IntroDisplay (intro_graphic.c) */
    void *msg;                  /* 0x18: IntroMsgWork (intro_msg.c) */
    unsigned int scenarioId;    /* 0x1C: index into the scenario table list */
    void *commands[8];          /* 0x20: IntroCommand pointers */
    Slot slots[8];              /* 0x40: per-command state words */
    unsigned int rowIndex;      /* 0xA0: current row in the scenario table */
    void *saveControl;          /* 0xA4: args->saveControl */
    unsigned char data[4096];   /* 0xA8: script data block */
    void *actor[3];             /* 0x10A8: CLACT_CreateActor results */
    IntroHandle charHandle[3];  /* 0x10B4 */
    IntroHandle palHandle[3];   /* 0x10C0 */
    IntroHandle cellAnimHandle[3]; /* 0x10CC */
} IntroCmdWork;

struct IntroGameState;

/*
 * The intro args object handed to INTRO_GRAPHIC_Create and stored in the
 * command work at 0x04. The fields used in ov204 are the game state pointer
 * at 0x00, the applied flag pointer handed to CONFIG_SetTextLanguage at 0x04,
 * the intro mode at 0x08, the save control object at 0x0C, a voice id at
 * 0x10 and one more word written by a command handler at 0x14.
 */
typedef struct IntroArgs {
    struct IntroGameState *gameState; /* 0x00 */
    void *appliedFlag;          /* 0x04: u16 * for CONFIG_SetTextLanguage */
    unsigned int mode;          /* 0x08: intro mode/kind */
    void *saveControl;          /* 0x0C */
    unsigned int voiceId;       /* 0x10: PM_VOICE_Start / IsSlotActive slot */
    unsigned int value;         /* 0x14: written by INTRO_GRAPHIC_CmdSetArg */
} IntroArgs;

#endif
