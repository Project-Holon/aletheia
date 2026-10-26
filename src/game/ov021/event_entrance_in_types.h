#ifndef ALETHEIA_OV021_EVENT_ENTRANCE_IN_TYPES_H
#define ALETHEIA_OV021_EVENT_ENTRANCE_IN_TYPES_H

/*
 * Entrance events of a map change (event_entrance_in.c and event_entrance_out.c).
 *
 * The "in" events run on the old map while the player walks into the
 * entrance (fade out, door sound, music change). The "out" events run on the
 * new map while the player comes out of the entrance (fade in, place name).
 * Both pick their event from a table by the exit type of the connection.
 *
 * The including file defines u8, u16, s16 and u32 first. EntranceParam is the
 * record of ov020 event_mapchange_types.h.
 */

#include "../ov020/event_mapchange_types.h"
#include "../arm9/ica_anime_shared_types.h"

/* Exit types of a connection (EntranceParam.exitType and destExitType). */
enum {
    ENTRANCE_EXIT_TYPE_DEFAULT,         /* 0: plain entrance, direct warps */
    ENTRANCE_EXIT_TYPE_PLAIN,           /* 1: same events as the default */
    ENTRANCE_EXIT_TYPE_OBJECT_ANIME,    /* 2: an object animation plays */
    ENTRANCE_EXIT_TYPE_GROUND_ANIME,    /* 3: a ground animation plays */
    ENTRANCE_EXIT_TYPE_OBJECT_ANIME_B,  /* 4: same events as 2 */
    ENTRANCE_EXIT_TYPE_APPEAR,          /* 5: the warp to a position (appear event) */
    ENTRANCE_EXIT_TYPE_FADE_SE          /* 6: fade with a sound effect only */
};

/* Entries of the event tables gEntranceInEventTable and gEntranceOutEventTable. */
enum {
    ENTRANCE_EVENT_PLAIN,
    ENTRANCE_EVENT_GROUND_ANIME,
    ENTRANCE_EVENT_OBJECT_ANIME,
    ENTRANCE_EVENT_APPEAR,
    ENTRANCE_EVENT_CAMERA,          /* every exit type from 7 on (entrance_camera.c records) */
    ENTRANCE_EVENT_FADE_SE,
    ENTRANCE_EVENT_COUNT
};

/* Values the entrance events return to the event runner. */
#define ENTRANCE_EVENT_CONTINUE 0
#define ENTRANCE_EVENT_FINISHED 1
#define ENTRANCE_EVENT_YIELD 0x21

#define ENTRANCE_EFFECT_NO_DOOR_SE 2    /* exitEffectId value that skips the door sound */
#define ENTRANCE_IN_SE_DOOR 0x559
#define ENTRANCE_IN_SE_FADE 0x737
#define ENTRANCE_IN_BGM_FADE_FRAMES 30
#define ENTRANCE_OUT_BGM_FADE_FRAMES 6
#define ENTRANCE_IN_BGM_KEPT 0x3F4

/* Work of one "in" event (12 bytes). */
typedef struct EntranceInWork {
    int reserved00;             /* 0x00: not touched by the events */
    void *animHandle;           /* 0x04: handle of the started object animation */
    EntranceParam *param;       /* 0x08 */
} EntranceInWork;

/* Work of one "out" event (4 bytes). */
typedef struct EntranceOutWork {
    EntranceParam *param;       /* 0x00 */
} EntranceOutWork;

typedef GameEventFunc EntranceInEventFunc;
typedef GameEventFunc EntranceOutEventFunc;

typedef struct EntranceInEventTable {
    EntranceInEventFunc func[ENTRANCE_EVENT_COUNT];
} EntranceInEventTable;

typedef struct EntranceOutEventTable {
    EntranceOutEventFunc func[ENTRANCE_EVENT_COUNT];
} EntranceOutEventTable;

#endif
