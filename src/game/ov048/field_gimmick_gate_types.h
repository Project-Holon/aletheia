#ifndef ALETHEIA_OV048_FIELD_GIMMICK_GATE_TYPES_H
#define ALETHEIA_OV048_FIELD_GIMMICK_GATE_TYPES_H

/*
 * Field gimmick of the gate buildings (overlay 48): an electric message
 * board (gimmick_obj_elboard.c) on the wall of a gate. The gimmick loads the
 * board model, picks the board record of the current zone, loads the news
 * list and keeps the scroll position and the shown messages in the gimmick
 * save area.
 *
 * Model for the gimmick files (FIELD_GIMMICK_<NAME>_*): a work in the field
 * map work table (id 0), the common gimmick work for the save area, and the
 * init, exit and update entry points that the gimmick tables of field_gimmick.c
 * call with the field map.
 */

#include "../ov021/fld_exp_obj_types.h"

#include "../types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct EventWork;
struct SaveControl;
struct ConfigSave;
struct MiscSave;
struct ExtraSaveRecord;
struct GimmickObjElboard;
struct Strbuf;
typedef struct FieldMap FieldMap;

/* Work id of the gate work in the field map work table. */
#define GATE_WORK_ID 0

/* The expansion object unit of the gate and its board model. */
#define GATE_EXP_OBJ_UNIT_INDEX   1
#define GATE_EXP_OBJ_MODEL_BOARD  0

/* Archives of the gate: one record per board, one record per news entry. */
#define GATE_BOARD_ARCHIVE_ID 0xae
#define GATE_NEWS_ARCHIVE_ID  0xa6

/* Id of the extra save that holds the second list of values. */
#define GATE_EXTRA_SAVE_ID 8

/* Event flags that switch the board to a list of values from a save. */
#define GATE_FLAG_SAVE_BLOCK_LIST 0x960
#define GATE_FLAG_EXTRA_SAVE_LIST 0x97b

/* GateNewsEntry.zoneIds value that matches every zone. */
#define GATE_NEWS_ZONE_ANY 0x1ab

/* GateNewsEntry.kind */
#define GATE_NEWS_KIND_SINGLE 0     /* one message */
#define GATE_NEWS_KIND_LIST   2     /* the same entry on up to four panels */

/* GateMessageLog.messageType of a news message; the flag id is logged with it. */
#define GATE_MESSAGE_TYPE_NEWS 8

#define GATE_MESSAGE_LOG_MAX 7
#define GATE_NEWS_ZONE_COUNT 4

/* Directions of GateBoardRecord.facing. */
enum GateFacing {
    GATE_FACING_UP = 0,
    GATE_FACING_DOWN = 1,
    GATE_FACING_LEFT = 2,
    GATE_FACING_RIGHT = 3
};

/* One board of the gate archive (0x7c bytes): where it stands and which animation it plays. */
typedef struct GateBoardRecord {
    u32 zoneId;                 /* 0x00 */
    u32 specialPowerId;         /* 0x04: 0 for every Entralink power, else the power that shows it */
    s32 x;                      /* 0x08: tile position, shifted by 12 into fx32 */
    s32 y;                      /* 0x0C */
    s32 z;                      /* 0x10 */
    s32 facing;                 /* 0x14: GateFacing */
    u32 elboardParams[23];      /* 0x18: message and panel ids, read by gimmick_obj_elboard.c */
    s32 animeKind;              /* 0x74: index into the animation table */
    u32 enabled;                /* 0x78: nonzero when the board shows messages */
} GateBoardRecord;

/* One news entry of the gate archive (0x24 bytes). */
typedef struct GateNewsEntry {
    u32 specialPowerId;                 /* 0x00: 0 for every Entralink power, else the power that shows it */
    u32 eventFlag;                      /* 0x04: the entry is eligible while this event flag is set */
    s32 clearsFlagWhenShown;            /* 0x08: 1 clears eventFlag when the message is shown */
    s32 messageId;                      /* 0x0C */
    s32 kind;                           /* 0x10: GATE_NEWS_KIND_* */
    s32 zoneIds[GATE_NEWS_ZONE_COUNT];  /* 0x14: zones that show it, GATE_NEWS_ZONE_ANY for all */
} GateNewsEntry;

/* The messages shown on the board (0x3C bytes), kept in the work and in the save. */
typedef struct GateMessageLog {
    u8 count;                           /* 0x00 */
    u8 pad01[3];
    s32 messageType[GATE_MESSAGE_LOG_MAX];  /* 0x04 */
    s32 flagId[GATE_MESSAGE_LOG_MAX];       /* 0x20 */
} GateMessageLog;

/* The gate gimmick work (0x68 bytes, field map work id 0). */
typedef struct GateWork {
    u16 heapId;                         /* 0x00 */
    u16 pad02;
    FieldMap *fieldMap;                 /* 0x04 */
    struct GameData *gameData;          /* 0x08 */
    struct GameSystem *gameSystem;      /* 0x0C */
    s32 initialized;                    /* 0x10: the save area holds a state */
    struct GimmickObjElboard *board;    /* 0x14 */
    s32 scrollPos;                      /* 0x18: board scroll in whole units */
    GateBoardRecord *record;            /* 0x1C: board of the current zone */
    GateNewsEntry *newsList;            /* 0x20 */
    u8 newsCount;                       /* 0x24 */
    u8 pad25[3];
    GateMessageLog messageLog;          /* 0x28 */
    u16 gatePoints;                  /* 0x64: mirrored in the misc save */
    u16 pad66;
} GateWork;

/* The gimmick save area (0x48 bytes). */
typedef struct GateSave {
    s32 initialized;                    /* 0x00 */
    s32 scrollPos;                      /* 0x04 */
    u16 gatePoints;                  /* 0x08 */
    u16 pad0A;
    GateMessageLog messageLog;          /* 0x0C */
} GateSave;

/* What the board needs to be created (12 bytes). */
typedef struct GateElboardSetup {
    u16 heapId;                         /* 0x00 */
    u8 maxMessages;                     /* 0x02 */
    u8 bitmapWidthCells;                /* 0x03 */
    u8 bitmapHeightCells;               /* 0x04 */
    u8 pad05[3];
    G3dObject *model;                   /* 0x08: board model of the expansion object */
} GateElboardSetup;


#endif
