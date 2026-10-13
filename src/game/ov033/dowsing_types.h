#ifndef DOWSING_TYPES_H
#define DOWSING_TYPES_H

/* The includer must include ov021/field_subscreen_types.h first (FieldSubscreen). */

/* Types of the dowsing machine sub-screen (field sub-screen mode 6). */

typedef signed short s16;
typedef signed int s32;

/* Dowsing level of the grid cell the player stands on: 0 .. 7 are the
 * distance steps, 8 is "on top of the target", 9 is "nothing near". */
#define DOWSING_LEVEL_ON_TARGET 8
#define DOWSING_LEVEL_NONE 9

/* Values of DowsingWork.fadeRequest. */
#define DOWSING_FADE_NONE 0
#define DOWSING_FADE_IN 1
#define DOWSING_FADE_OUT 2

/* Values of DowsingWork.buttonState. */
#define DOWSING_BUTTON_IDLE 0
#define DOWSING_BUTTON_PRESSED 1          /* press animation plays */
#define DOWSING_BUTTON_RELEASED 2         /* animation done, close pending */
#define DOWSING_BUTTON_CLOSE_REQUESTED 3

/* Kinds of DowsingTarget. */
#define DOWSING_TARGET_NONE 0
#define DOWSING_TARGET_HIDDEN_ITEM 1
#define DOWSING_TARGET_MAP_EVENT 2

/* Sound effects. */
#define DOWSING_SE_PROXIMITY 0x760
#define DOWSING_SE_LEVEL_CHANGE 0x762
#define DOWSING_SE_CLOSE 0x556

/* Indices of DowsingWork.parts. */
#define DOWSING_PART_LEFT_GAUGE 0
#define DOWSING_PART_RIGHT_GAUGE 1
#define DOWSING_PART_DIRECTION 2
#define DOWSING_PART_FOUND_MARK 3
#define DOWSING_PART_COUNT 4

struct ClactUnit;
struct ClactActor;
struct TaskSys;
struct Task;
struct PalAnm;

/* Hidden item row (10 bytes) of the table that overlay 10 returns. */
typedef struct DowsingHiddenItem {
    u16 flagIndex;         /* picked-up flag number, relative to the base flag */
    u8 crossZone;          /* nonzero: also found from a neighbouring zone */
    u8 pad3;
    u16 zoneId;
    u16 x;                 /* tile position */
    u16 z;
} DowsingHiddenItem;

/* Object event of the map that the machine can also find. */
typedef struct DowsingMapEvent {
    s16 x;
    s16 y;
    s16 z;
    s16 zoneId;
} DowsingMapEvent;

/* One thing the machine looks for: only the member that matches kind is set. */
typedef struct DowsingTarget {
    u32 kind;              /* DOWSING_TARGET_* */
    const DowsingHiddenItem *item;
    const DowsingMapEvent *event;
} DowsingTarget;

/* Cursor over all targets of the current map (0x10 bytes). */
typedef struct DowsingSearch {
    void *eventFlags;      /* event flag bitmap of the save */
    u16 itemIndex;         /* next row of the hidden item table */
    u16 pad6;
    void *eventData;       /* map events, walked by eventIndex */
    u16 eventIndex;
    u16 padE;
} DowsingSearch;

/* Resources and actor of one sprite of the screen. */
typedef struct DowsingPart {
    s32 charRes;
    s32 cellRes;
    struct ClactActor *actor;
} DowsingPart;

/* Work of the dowsing machine screen (0xD4 bytes). */
typedef struct DowsingWork {
    u16 heapId;
    u16 ownerHeapId;       /* heap of the field sub-screen */
    FieldSubscreen *subscreen;
    void *fieldMap;
    struct ClactUnit *clactUnit;
    u32 bgCharRegion7;     /* packed offset and size of the BG 7 tiles */
    u32 bgCharRegion4;     /* same for BG 4 (close button panel) */
    s32 buttonPalRes;
    s32 buttonCharRes;
    s32 buttonCellRes;
    struct ClactActor *buttonActor;
    u32 buttonState;       /* DOWSING_BUTTON_* */
    s32 partsPalRes;       /* palette shared by the four parts */
    DowsingPart parts[DOWSING_PART_COUNT];
    u8 *levelGrid;         /* 32 x 24 level per cell, centred on the player */
    s32 prevLevel;
    s32 level;
    s32 shownLevel;        /* level the sprites currently show */
    DowsingTarget prevTarget;
    DowsingTarget target;
    s32 gridX;             /* player tile position at the last update */
    s32 gridY;
    s32 gridZ;
    s32 hasSearched;
    s32 seHandle;
    s32 seStarted;
    u16 seTimer;
    u16 padA2;
    s32 restartFoundAnim;
    struct Task *task;
    u8 tick;               /* counts 1..4 while the machine is on */
    u8 padAD[3];
    s32 isOn;
    struct TaskSys *fadeTaskSys;
    void *fadeTaskMem;
    struct PalAnm *palAnm;
    s32 fadeRequest;       /* DOWSING_FADE_* */
    s32 fadeState;         /* 0 shown, 1 faded out */
    s32 needReset;         /* search cursor must be rewound */
    s32 needFullScan;      /* next update scans every target */
    DowsingSearch *search;
} DowsingWork;

/* Row of the level table: sprite animations and marker position per level. */
typedef struct DowsingLevelEntry {
    u32 leftAnim : 3;
    u32 rightAnim : 3;
    u32 directionAnim : 3;
    u32 directionX : 8;
    u32 directionY : 8;
    u32 pan : 7;           /* stereo pan of the sound, 8 is the centre */
} DowsingLevelEntry;

/* Resource ids of one part, per part. */
typedef struct DowsingPartIds {
    u8 charId;
    u8 cellId;
    u8 animId;
} DowsingPartIds;

/* Setup of one background layer. */
typedef struct DowsingBgSetup {
    u32 bgId;
    u32 bgTemplate[8];
    u32 bgType;
    u32 visible;
} DowsingBgSetup;

/* Parameters for creating an actor. */
typedef struct ClactSetup {
    u16 x;
    u16 y;
    u16 z;
    u8 priority;
    u8 palOffset;
} ClactSetup;

typedef struct ScreenPos {
    u16 x;
    u16 y;
} ScreenPos;

/* Layout of a screen data file: header, then the tile map. */
typedef struct ScreenData {
    u8 header[0xC];
    u16 tiles[0x300];
} ScreenData;

#endif
