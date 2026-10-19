#ifndef OV020_EVENT_MAPCHANGE_TYPES_H
#define OV020_EVENT_MAPCHANGE_TYPES_H

/*
 * Types of the map change events (event_mapchange.c, ov020).
 *
 * The including file defines u8, u16, s16 and u32 first.
 *
 * Location and RailLocation are the arm9 zonedata.c records; the field
 * names follow zonedata.c (zoneId, exitId, dir, widthGrid, lineGrid).
 */

struct GameSystem;
struct GameData;
struct FieldMap;
struct GameEvent;
struct GameComm;
struct FieldStatus;
struct PlayerWork;
struct MmdlSys;
struct EventData;
struct EventWork;
struct EventDataSystem;
struct SaveControl;
struct MiscSave;
struct AreaData;
struct FieldSoundSystem;
struct PlaceNameSys;
struct ConsoleInfo;
struct ConsoleInfoSession;

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct FieldMap FieldMap;
typedef struct GameEvent GameEvent;
typedef struct GameComm GameComm;
typedef struct FieldStatus FieldStatus;
typedef struct PlayerWork PlayerWork;
typedef struct MmdlSys MmdlSys;
typedef struct EventData EventData;

#include "../sdk_fx.h"

/* RailLocation: the rail position record of ov021 fldmmdl_rail. */
#include "../ov021/fldmmdl_rail_types.h"

/* A place on a map (0x1C bytes): zone, facing and position. */
typedef struct Location {
    int type;          /* 00: 1 = direct position, 2 = rail position */
    u16 zoneId;        /* 04 */
    s16 exitId;        /* 06 */
    s16 dir;           /* 08 */
    u16 exitOffset;    /* 0A */
    int posType;       /* 0C */
    union {            /* 10 */
        VecFx32 vec;
        RailLocation rail;
    } pos;
} Location;

/* Parameter block of the entrance effect events (0x50 bytes), embedded in MapChangeWork. */
typedef struct EntranceParam {
    GameEvent *event;          /* 00 */
    GameSystem *gameSystem;    /* 04 */
    GameData *gameData;        /* 08 */
    FieldMap *fieldMap;        /* 0C */
    int exitType;              /* 10: copied from MapChangeWork.exitType */
    int destExitType;          /* 14: connect exit type of the destination exit, 0 when the location type is 1 */
    u16 currentZoneId;         /* 18 */
    u8 pad1A[2];
    Location destination;      /* 1C */
    int exitEffectId;          /* 38: picked from the zone pair */
    int entranceEffectId;      /* 3C */
    int seasonChanged;         /* 40 */
    u8 fromSeasonIndex;        /* 44 */
    u8 toSeason;               /* 45 */
    u8 pad46[2];
    int bgmReplaced;           /* 48: set when the entrance replaced the BGM */
    int bgmFadeStarted;        /* 4C: set when the BGM fade started */
} EntranceParam;

/* Work area of one map change event (0x9C bytes, allocated with the event). */
typedef struct MapChangeWork {
    GameSystem *gameSystem;    /* 00 */
    GameData *gameData;        /* 04 */
    FieldMap *fieldMap;        /* 08 */
    u16 currentZoneId;         /* 0C: zone the player leaves */
    u8 pad0E[2];
    Location destination;      /* 10 */
    int exitType;              /* 2C: connect exit type of the exit used, 0 for direct warps */
    u8 changeKind;             /* 30: 0 normal, 1 to 3 select the arrival setup, 4 skips the beacon update */
    u8 pad31[3];
    VecFx32 targetPos;         /* 34 */
    int seasonFadeAllowed;     /* 40 */
    int seasonChanged;         /* 44 */
    u16 fromSeason;            /* 48 */
    u16 toSeason;              /* 4A: season set on arrival */
    EntranceParam entrance;    /* 4C */
} MapChangeWork;

/* Work area of the intrude arrival events (0x30 bytes). */
typedef struct {
    Location location;       /* 00 */
    GameSystem *gameSystem;  /* 1C */
    GameData *gameData;      /* 20 */
    FieldMap *fieldMap;      /* 24 */
    int requestSession;      /* 28 */
    u8 intrudeId;            /* 2C */
} MapChangeIntrudeWork;

/* Work area of the warp id arrival event (0x24 bytes). */
typedef struct {
    GameSystem *gameSystem;  /* 00 */
    GameData *gameData;      /* 04 */
    Location location;       /* 08 */
} WarpIdArrivalWork;

/* Intrude communication work (only the parts these events read). */
typedef struct {
    u8 unused00[0x86];
    u16 slot : 3;            /* 86 */
    u16 reserved86 : 13;
    u8 unused88[0x124];
    u8 requestInfo[0x756];   /* 1AC */
    u8 slotCount;            /* 902 */
} IntrudeComm;

#endif
