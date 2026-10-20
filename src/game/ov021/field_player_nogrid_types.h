#ifndef GAME_OV021_FIELD_PLAYER_NOGRID_TYPES_H
#define GAME_OV021_FIELD_PLAYER_NOGRID_TYPES_H

#include "../ov010/fldmmdl_types.h"
#include "../ov021/fldmmdl_rail_types.h"

#include "../types.h"

/*
 * The player movement controller for maps that use rails (field_player_nogrid.c).
 * The field player (field_player.c) holds one core, one grid controller and one
 * nogrid controller. The nogrid controller turns the keys of a frame into one
 * field model command (stand, walk, turn, bump, ledge jump) for the player's
 * model, and handles forced moves (tiles that carry the player on).
 */

struct FieldPlayerCore;
struct FieldMap;
struct RailWork;

/* A direction value that means "no direction" (no key held). */
#define FIELD_PLAYER_NOGRID_DIR_NONE 9

/* Move modes: the command that is running on the model (FieldPlayerNogrid.moveMode). */
#define FIELD_PLAYER_NOGRID_MODE_STAND   0
#define FIELD_PLAYER_NOGRID_MODE_WALK    1  /* also the ledge jump */
#define FIELD_PLAYER_NOGRID_MODE_TURN    2
#define FIELD_PLAYER_NOGRID_MODE_BLOCKED 3  /* walks into a wall or the map edge */

/* Actions: what one frame asks the model to do (result of the check functions). */
#define FIELD_PLAYER_NOGRID_ACTION_NONE       0  /* model busy */
#define FIELD_PLAYER_NOGRID_ACTION_STAND      1
#define FIELD_PLAYER_NOGRID_ACTION_WALK       2
#define FIELD_PLAYER_NOGRID_ACTION_TURN       3
#define FIELD_PLAYER_NOGRID_ACTION_BLOCKED    4
#define FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP 5

/* Movement kinds of the player core: select the family of check and start functions. */
#define FIELD_PLAYER_NOGRID_KIND_WALK 0
#define FIELD_PLAYER_NOGRID_KIND_SLOW 1
#define FIELD_PLAYER_NOGRID_KIND_RAIL 2  /* kinds 2 and 3 */

/* Bits of FieldPlayerNogrid.flags. */
#define FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE       0x01  /* a tile carries the player on */
#define FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED 0x02  /* the forced move was just stopped */
#define FIELD_PLAYER_NOGRID_FLAG_PENDING           0x04  /* cleared after every update */
#define FIELD_PLAYER_NOGRID_FLAG_SPIN_A            0x08  /* spin tile, first rotation order */
#define FIELD_PLAYER_NOGRID_FLAG_SPIN_B            0x10  /* spin tile, second rotation order */
#define FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT        0x20  /* turn to the right when the move stops */
#define FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD        0x40  /* held direction is tracked */

/* Spin tile animation (4 bytes): the model turns through four directions
 * while a sound plays. */
typedef struct NogridSpin {
    u8 active;      /* 0x00 */
    u8 variant;     /* 0x01 row of the direction table */
    s16 phase;      /* 0x02 column of the direction table */
} NogridSpin;

/* Held direction (8 bytes): the direction is kept for a while after the keys
 * are released, so that the next step keeps going the same way. */
typedef struct NogridInputHold {
    u8 enabled : 1;     /* 0x00 bit 0 */
    u8 keepDir : 1;     /* bit 1 the held direction is in use */
    u8 held : 1;        /* bit 2 set for the frame in which keepDir was taken */
    u8 idleDone : 5;    /* bits 3 to 7: 1 once idleFrames reached the limit */
    u8 reserved01;      /* 0x01 */
    s16 idleFrames;     /* 0x02 frames without a direction key, up to 30 */
    u32 heldDir;        /* 0x04 FIELD_PLAYER_NOGRID_DIR_NONE when none */
} NogridInputHold;

/* The nogrid player controller (0x24 bytes, allocated by the constructor). */
typedef struct FieldPlayerNogrid {
    int moveMode;                       /* 0x00 FIELD_PLAYER_NOGRID_MODE_* */
    u32 flags;                          /* 0x04 FIELD_PLAYER_NOGRID_FLAG_* */
    NogridSpin spin;                    /* 0x08 */
    NogridInputHold inputHold;          /* 0x0C */
    struct FieldPlayerCore *core;       /* 0x14 */
    struct FieldMap *fieldMap;          /* 0x18 */
    Mmdl *mmdl;                         /* 0x1C the player's field model */
    struct RailWork *railWork;          /* 0x20 rail walker of the model */
} FieldPlayerNogrid;

/* A forced move handler, one per tile kind (table indexed by the kind). */
typedef u32 (*NogridForcedMoveFunc)(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind);

#endif
