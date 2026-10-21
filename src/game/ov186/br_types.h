#ifndef BR_TYPES_H
#define BR_TYPES_H

/* Owner header for the battle recorder (BR) work structures of ov186.
 * Battle record data itself lives in ../arm9/battle_rec_types.h. */
#include "../arm9/battle_rec_types.h"

#include "../types.h"

#include "../ov125/gds_rap_types.h"

struct Unit;

/* Actor (CLACT) system handle, 4 bytes. */
struct BrActorSys {
    struct Unit *unit;
};

/* BR graphic system, 16 bytes, allocated by BR_GRAPHIC_Create. */
struct BrGraphic {
    u32 bgState;              /* zeroed by BG window init/exit, never read */
    struct BrActorSys actors;
    u32 unused8;              /* zeroed with the block, never touched */
    void *vblankTask;         /* task that runs draw and vblank handlers */
};

/* One button description row, 12 halfwords (24 bytes), in the section tables. */
struct BrBtnTemplate {
    u16 x;
    u16 y;
    u16 resultKind4;
    u16 msgId;          /* message index; set to 26 when the config enables the button */
    u16 anim;
    u16 resultKind0;
    u16 resultKind1;
    u16 resultKind2;
    u16 enabled;        /* filled from BrBtnConfig by BR_BTN_DATA_Fill */
    u16 resultKind5;
    u16 resultKind6;
    u16 kind;           /* 0 always on, 1 mainFlag, 2..5 select a config flag */
};

/* One section of the button description table (12 sections). */
struct BrBtnSection {
    u16 count;
    u16 unused;
    const struct BrBtnTemplate *records;
    int unknown;
};

/* Feature flags the caller passes in when the button table is built. */
struct BrBtnConfig {
    int mainFlag;
    int slotFlag[4];
    int unused14[15];
    int extraFlag;
};

/* Runtime button description table: config pointer followed by all rows. */
struct BrBtnTable {
    struct BrBtnConfig *config;
    struct BrBtnTemplate records[1];  /* sum of section counts rows */
};

struct PaletteFade;

struct BrFade;

typedef int (*BrFadeStepFunc)(struct BrFade *fade, int *state);

/* Screen and palette fade work, 0x40 bytes, allocated by BR_FADE_Create. */
struct BrFade {
    int done;                 /* result of the last step call */
    int planeMask;            /* bit 0: main, bit 1: sub (palette steps: bank pairs) */
    int direction;            /* 0: fade out, 1: fade in */
    int state;                /* step function state, passed by address */
    u32 frame;
    u32 frameCount;
    int durationParam;        /* 0: use the global fade speed */
    BrFadeStepFunc step;
    struct PaletteFade *palAnm;
    u16 blendColor;
    u16 pad26;
    u32 unused28[5];
    u32 unused3C;             /* initialised to 0xFFFF, never read in ov186 */
};

struct GfFont;
struct MsgBank;
struct WordSet;

/* One actor resource set: cell animation, character and palette ids. */
struct BrResSprite {
    u32 cellAnimId;
    u32 charId;
    u32 paletteId;
};

#define BR_RES_SPRITE_COUNT 14

/* Shared BR resources (fonts, messages, actor resources), 0xFC bytes. */
struct BrRes {
    u32 paletteId[2];                          /* main/sub UI palettes, -1 when released */
    struct BrResSprite sprite[BR_RES_SPRITE_COUNT];
    int spriteLoaded[BR_RES_SPRITE_COUNT];
    struct GfFont *font;
    struct MsgBank *msgData;
    struct WordSet *wordSet;
    volatile u32 useCustomSet;                 /* nonzero: palSet comes from the caller */
    volatile u32 palSet;                       /* index 0..7 into the palette/cell tables */
};

struct GameData;
struct GdsProfile;
struct BrNet;
struct BrNetTask;

/* Request kinds of BR_NET_StartRequest. */
enum BrNetRequestKind {
    BR_NET_REQUEST_UPLOAD_ENTRY = 0,
    BR_NET_REQUEST_DOWNLOAD_ENTRIES = 1,
    BR_NET_REQUEST_UPLOAD_VIDEO = 2,
    BR_NET_REQUEST_GET_VIDEO = 3,
    BR_NET_REQUEST_SEARCH_VIDEOS = 4,
    BR_NET_REQUEST_SEARCH_KIND1 = 5,
    BR_NET_REQUEST_SEARCH_KIND3 = 6,
    BR_NET_REQUEST_SEARCH_KIND2 = 7,
    BR_NET_REQUEST_MARK_VIDEO = 8,
    BR_NET_REQUEST_COUNT = 9
};

/* Task step: runs once per BR_NET_Main until it installs another step. */
typedef void (*BrNetStepFunc)(struct BrNetTask *task, u32 *counter, struct BrNet *net);

/* Small task that drives one request, 16 bytes. */
struct BrNetTask {
    BrNetStepFunc step;
    u32 counter;              /* zeroed whenever a step is installed, passed by address */
    struct BrNet *net;
    u32 unusedC;              /* zeroed with the block, never touched */
};

/* Arguments of the request in flight (8 bytes); the active member depends on the kind. */
union BrNetRequest {
    const GdsPayloadBlock *payload;       /* UPLOAD_ENTRY */
    u16 downloadKey;                      /* DOWNLOAD_ENTRIES */
    struct {
        u32 lo;
        u32 hi;
    } dataNumber;                         /* GET_VIDEO, MARK_VIDEO */
    struct {
        u16 keyId;
        u8 mode;
        u8 flag;
        u32 category;
    } search;                             /* SEARCH_VIDEOS */
    int words[2];
};

/* BR network (online battle video upload and download) work, 0x5E4 bytes. */
struct BrNet {
    GdsRapWork rap;                       /* GDS request layer of ov125 */
    int rapActive;                        /* nonzero between GDS_RAP_Init and GDS_RAP_Exit */
    struct GdsProfile *profile;
    struct BrNetTask *task;
    union BrNetRequest request;
    int uploadEntryDone;                  /* set by the GDS call-backs */
    int downloadEntriesDone;
    int uploadVideoDone;
    int getVideoDone;
    int searchVideosDone;
    int unused5CC[3];                     /* zeroed with the flags, never touched */
    int markVideoDone;
    int fatal;                            /* set when the error was fatal */
    struct GameData *gameData;
};

struct Actor;

/* Position record read by CLACT_CreateActor. */
struct BrActorPos {
    s16 x;
    s16 y;
    u16 animSeq;
    u8 drawPriority;
    u8 bgPriority;
};

/* One row of the sidebar icon table (24 bytes), copied into the slot. */
struct BrSidebarConfig {
    s16 x;
    s16 y;
    s16 scale;                /* initial and resting actor scale */
    s16 duration;             /* frames of the slide animation */
    s16 restX;                /* x the wobble starts from, slide target of the bounce */
    s16 unused3E;             /* never read */
    s16 phase;                /* start angle of the wobble */
    s16 phaseStep;            /* angle added each wobble step */
    u32 space;                /* 0 main, 1 sub screen; selects the sprite set */
    u32 reverse;              /* nonzero: the wobble swings the other way */
};

struct BrSidebarSlot;

typedef void (*BrSidebarUpdateFunc)(struct BrSidebarSlot *slot);

#define BR_SIDEBAR_SLOT_COUNT 12

/* One animated sidebar icon, 0x4C bytes. */
struct BrSidebarSlot {
    u32 active;
    struct Actor *actor;
    int baseX;                /* x in 20.12 fixed point, written once */
    int baseY;                /* y in 20.12 fixed point, written once */
    int posFixed;             /* animated position, 20.12 fixed point */
    int scale;
    BrSidebarUpdateFunc update;
    int state;
    int angle;
    int counter;
    int tick;                 /* the animation runs every second call */
    int stepPos;
    int stepScale;
    struct BrSidebarConfig config;
};

/* The sidebar: 12 icons. */
struct BrSidebar {
    struct BrSidebarSlot slot[BR_SIDEBAR_SLOT_COUNT];
};

struct PrintSys;
struct Strbuf;
struct ZukanSave;
struct BrTextWin;
struct BrButton;
struct BrListMenu;
struct BrTapFx;

/* Screen point (touch position). */
struct BrPoint {
    int x;
    int y;
};

/* One list entry: name string and the value the list reports when it is chosen. */
struct BrMenuItem {
    void *text;
    int id;
};

/* Parameter block of the list menu (40 bytes), copied from a template and filled in. */
struct BrListMenuConfig {
    struct BrMenuItem *list;
    u32 count;
    u8 x, y, width, height, palette, bg, spacing, pad;
    int mode;
    struct BrRes *resources;
    uptr manager;             /* actor unit for the list marks */
    uptr cursor;              /* cursor effect */
    uptr other;               /* second effect, or the PMS draw */
    u16 *selection;           /* start and index are written back here */
};

#define BR_POKESEARCH_GROUP_COUNT 9

/* Pokemon search screen work (nine name groups, then a list of the seen species), 0x90 bytes. */
struct BrPokeSearch {
    int state;
    int nextState;            /* state to enter once the fade out has finished */
    int result;               /* 0 none, 1 back, 2 species picked */
    int touchedGroup;         /* group index touched, 9 when none */
    int listChoice;           /* species id chosen in the list, -1 when none */
    u8 groupHasSeen[BR_POKESEARCH_GROUP_COUNT];
    u8 pad1D[3];              /* alignment before the next word */
    int done;
    u16 heapId;
    u16 pad26;                /* alignment */
    struct BrRes *res;
    struct BrButton *backButton;
    struct BrFade *fade;
    u32 uiParamA;
    u32 uiParamB;
    struct PrintSys *printQue;
    struct BrTextWin *groupWin[BR_POKESEARCH_GROUP_COUNT];
    struct BrMenuItem *menuItems;
    struct BrListMenu *listMenu;
    int active;
    int listShown;
    u32 listParam;
    struct BrTapFx *tapFx;
    struct ZukanSave *zukan;
    u16 *groupTable;          /* species ids of all groups, from the overlay data archive */
    u32 groupTableCount;
    u16 *seenList;            /* species of the chosen group that the player has seen */
    u32 seenCount;
};

/* Opaque objects referenced by the button and process-system code. */
struct Big;
struct RecGet;
struct U16Vec;
struct Bmp;
struct Node;
struct Cfg;
struct Grid;
struct Vec2;
struct Param;
struct Sys;

/* Small coordinate pairs used by the button and text helpers. */
typedef struct { int x, y; } BrPair;
typedef struct { int x, y, z; } BrTriple;

/* One button result entry (button kind and message id) of a button set. */
struct BrBtnResult { u16 a, b; };

/* A set of button results read from a script, up to six entries. */
struct BrBtnResultSet { struct BrBtnResult rec[6]; u32 count; };

/* One battle-recorder button: resources, button data and label records, 0x60 bytes. */
struct BrBtn {
    u16 heap;                    /* 0x00 heap id */
    u16 pad0;                    /* 0x02 alignment, never read */
    int resBase;                 /* 0x04 resource base handed to BR_RES_* */
    int oamData;                 /* 0x08 argument of BMP_OAM_CreateSys */
    int *task;                   /* 0x0C BR_UTIL task driving the button */
    int spriteIndex;             /* 0x10 first sprite of the button */
    int pressed;                 /* 0x14 set when a button was pressed */
    int placement;               /* 0x18 returned by BR_BTN_GetPlacement */
    unsigned int resultKind;     /* 0x1C row field 0, drives the state switch */
    int kind3;                   /* 0x20 row field 3 */
    int section;                 /* 0x24 row field 1 / section index */
    int offsetY;                 /* 0x28 row field 2 / placement y */
    int selected;                /* 0x2C index of the selected button */
    int touchX;                  /* 0x30 touch x of the last press */
    int touchY;                  /* 0x34 touch y of the last press */
    u8 rowCount;                 /* 0x38 rows of the main section */
    u8 sectionCount;             /* 0x39 rows of the current section */
    u8 maxRows;                  /* 0x3A capacity of the tail record array */
    u8 recordCount;              /* 0x3B records in the tail array */
    char *tailRecords;           /* 0x3C Button records of the tail list */
    char *rowRecords;            /* 0x40 Button records of the main list */
    void *dataTable;             /* 0x44 BR_BTN_DATA table */
    void *oamSys;                /* 0x48 BMP OAM system */
    u32 printQue;                /* 0x4C print queue */
    void *textWin;               /* 0x50 text window of the current row */
    int resultValue;             /* 0x54 returned by BR_BTN_GetField54 */
    int effect;                  /* 0x58 effect handle */
    struct BrBtnResultSet *resultSet; /* 0x5C pushed results */
};

/* A button on screen: its actor, OAM grid and bitmap plus label state. */
struct BrButton {
    void *actor;                 /* 0x00 CLACT actor */
    void *grid;                  /* 0x04 OAM grid */
    void *bmp;                   /* 0x08 bitmap */
    u32 unusedC;                 /* 0x0C zeroed, never read */
    u32 surface;                 /* 0x10 actor surface selector */
    u32 paramA;                  /* 0x14 width source (a>>3) and actor arg */
};

/* Placement of a button object: screen position, caller value, flag and attribute bytes. */
typedef struct BrBtnPlacement {
    s16 x;
    s16 y;
    u16 value;
    u8 flag;
    u8 attr;
} BrBtnPlacement;

/* Three sprite resource ids handed to BR_BTN_CreateObject. */
typedef struct BrBtnSpriteIds {
    u32 x;
    u32 y;
    u32 z;
} BrBtnSpriteIds;

#endif
