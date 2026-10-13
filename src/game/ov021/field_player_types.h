#ifndef ALETHEIA_OV021_FIELD_PLAYER_TYPES_H
#define ALETHEIA_OV021_FIELD_PLAYER_TYPES_H

#include "fieldmap_types.h"
#include "../ov010/fldmmdl_types.h"

/*
 * The field player (field_player.c): a thin layer over three parts. The core
 * (field_player_core.c) holds the avatar model and form for both movement
 * kinds; the grid part (field_player_grid.c) and the nogrid part
 * (field_player_nogrid.c, rails) exist one at a time, chosen by the map's move
 * kind (FIELDMAP_GetMoveKind: 0 grid, 1 nogrid).
 */

struct GameSystem;
struct PlayerWork;

typedef struct FieldPlayerCore FieldPlayerCore;
typedef struct FieldPlayerGrid FieldPlayerGrid;
typedef struct FieldPlayerNogrid FieldPlayerNogrid;

typedef struct FieldPlayer {
    FieldMap *fieldMap;             /* 0x00 */
    FieldPlayerCore *core;          /* 0x04 */
    FieldPlayerGrid *grid;          /* 0x08: only when the map moves on a grid */
    FieldPlayerNogrid *nogrid;      /* 0x0C: only when the map moves on rails */
} FieldPlayer;

/* Avatar form slots: the column index of the form table. */
#define FIELD_PLAYER_AVATAR_FORM_NORMAL   0
#define FIELD_PLAYER_AVATAR_FORM_CYCLE    1
#define FIELD_PLAYER_AVATAR_FORM_SURF     2
#define FIELD_PLAYER_AVATAR_FORM_DIVE     3
#define FIELD_PLAYER_AVATAR_FORM_COUNT    10

/* Model codes of the plain walking avatar, one per sex. */
#define FIELD_PLAYER_OBJ_CODE_HERO        1
#define FIELD_PLAYER_OBJ_CODE_HEROINE     4

/* One slot of the avatar form table: the model code and the form code that
 * the player work stores while the avatar looks like that. */
typedef struct FieldPlayerFormEntry {
    unsigned short objCode;
    unsigned short formCode;
} FieldPlayerFormEntry;

/* One row of the form table per sex (gFieldPlayerFormTable). */
typedef struct FieldPlayerFormRow {
    FieldPlayerFormEntry entries[FIELD_PLAYER_AVATAR_FORM_COUNT];
} FieldPlayerFormRow;

/* A grid position as the model header stores it. */
typedef struct FieldPlayerGridPos {
    short x;
    short z;
    int y;
} FieldPlayerGridPos;

/* The placement record for the avatar model: MmdlHeader with pos seen as a
 * grid position (0x24 bytes). */
typedef struct FieldPlayerMmdlHeader {
    unsigned short objId;           /* 0x00 */
    unsigned short objCode;         /* 0x02 */
    unsigned char rest[0x18];       /* 0x04: the other MmdlHeader fields */
    FieldPlayerGridPos pos;         /* 0x1C */
} FieldPlayerMmdlHeader;

/* One step of a form change sequence; returns 1 to run the next step at once. */
typedef int (*FieldPlayerFormStepFunc)(FieldPlayerCore *core);

struct FieldPlayerCore {
    unsigned char pad_00[4];            /* 0x00: never read */
    struct GameSystem *gameSystem;      /* 0x04 */
    FieldMap *fieldMap;                 /* 0x08 */
    struct PlayerWork *playerWork;      /* 0x0C */
    unsigned int stepPhase;             /* 0x10: 0 none, 1 and 2 first and second half step, 3 end */
    unsigned int stepKind;              /* 0x14: 0 none, 1 walk, 2 run */
    unsigned int sex;                   /* 0x18: row of the form table */
    Mmdl *mmdl;                         /* 0x1C */
    unsigned short lastHorzDir;         /* 0x20: 9 for none */
    unsigned short lastVertDir;         /* 0x22: 9 for none */
    unsigned int formChangeMask;        /* 0x24: one bit per form slot to change to */
    unsigned int rideEffect;            /* 0x28: surf or dive effect handle, 0 for none */
    unsigned short animeWait;           /* 0x2C */
    unsigned short formChangeCount;     /* 0x2E: slots changed so far */
    short formChangeStep;               /* 0x30: step of the running form sequence */
    unsigned short formChangeDone;      /* 0x32 */
};

#endif
