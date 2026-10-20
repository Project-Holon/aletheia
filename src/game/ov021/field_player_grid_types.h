#ifndef ALETHEIA_OV021_FIELD_PLAYER_GRID_TYPES_H
#define ALETHEIA_OV021_FIELD_PLAYER_GRID_TYPES_H

#include "../ov021/field_player_types.h"

/*
 * The grid part of the field player (field_player_grid.c, 0x20 bytes). It
 * turns one move request per frame into a move result for the avatar's
 * model, starts the matching animation and tracks the movement state.
 */

/* Movement state (FieldPlayerGrid.state). */
#define FIELD_PLAYER_GRID_STATE_STAND       0
#define FIELD_PLAYER_GRID_STATE_WALK        1
#define FIELD_PLAYER_GRID_STATE_TURN        2
#define FIELD_PLAYER_GRID_STATE_BLOCKED     3
#define FIELD_PLAYER_GRID_STATE_HOLD        4   /* waits about one second on a hop tile */
#define FIELD_PLAYER_GRID_STATE_HOP         5   /* jump onto the hop tile */
#define FIELD_PLAYER_GRID_STATE_HOP_AIR     6
#define FIELD_PLAYER_GRID_STATE_HOP_FALL    7   /* sinks until the ground height */

/* Bits of FieldPlayerGrid.flags. */
#define FIELD_PLAYER_GRID_FLAG_FORCED_MOVE      0x01    /* model is held in a forced move */
#define FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE   0x02    /* skip the forced move tile check */
#define FIELD_PLAYER_GRID_FLAG_STEP_PENDING     0x04    /* cleared at every move start, never set here */
#define FIELD_PLAYER_GRID_FLAG_HOLD             0x08
#define FIELD_PLAYER_GRID_FLAG_HOP              0x10
#define FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK     0x20

/* Result of the move check, and the value the apply step switches on. */
#define FIELD_PLAYER_GRID_RESULT_NONE           0
#define FIELD_PLAYER_GRID_RESULT_STAND          1
#define FIELD_PLAYER_GRID_RESULT_WALK           2
#define FIELD_PLAYER_GRID_RESULT_TURN           3
#define FIELD_PLAYER_GRID_RESULT_BLOCKED        4
#define FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP     5
#define FIELD_PLAYER_GRID_RESULT_HOLD           6
#define FIELD_PLAYER_GRID_RESULT_HOP            7
#define FIELD_PLAYER_GRID_RESULT_HOP_AIR        8
#define FIELD_PLAYER_GRID_RESULT_HOP_FALL       9

#define FIELD_PLAYER_GRID_DIR_NONE              9
#define FIELD_PLAYER_GRID_SOUND_NONE            0x546

/* One frame of input as the move check sees it. */
typedef struct FieldPlayerGridMoveRequest {
    unsigned int keyTrigger;        /* 0x00: not read in this file */
    unsigned int keyHeld;           /* 0x04: bit 1 (B) selects the dash */
    unsigned short dir;             /* 0x08: wanted direction, 9 for none */
    unsigned int dashAllowed;       /* 0x0C: bit 0 */
    unsigned int isDash;            /* 0x10: 1 selects the dash animation */
} FieldPlayerGridMoveRequest;

struct FieldPlayerGrid {
    unsigned int state;             /* 0x00: FIELD_PLAYER_GRID_STATE_* */
    unsigned int lastResult;        /* 0x04: last move result, never read */
    unsigned int flags;             /* 0x08: FIELD_PLAYER_GRID_FLAG_* */
    FieldPlayerCore *core;          /* 0x0C */
    FieldMap *fieldMap;             /* 0x10 */
    unsigned short holdFrames;      /* 0x14: counts to 60 in the hold state */
    unsigned char holdEffectPending;/* 0x16 */
    unsigned char pad_17;           /* 0x17 */
    unsigned short soundId;         /* 0x18: last tile sound, 0x546 for none */
    unsigned short soundRepeat;     /* 0x1A: frames since that sound started */
    unsigned int hopLanded;         /* 0x1C: set when the hop fall reaches the ground */
};

#endif
