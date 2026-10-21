/*
 * Object layouts of the town map screen (ov072): the screen work, the
 * parameter block the caller passes in, and the step function slot.
 */
#ifndef TOWNMAP_TYPES_H
#define TOWNMAP_TYPES_H

#include "../types.h"

/* Parameter block of the town map screen, filled in by the caller. */
typedef struct TownMapArgs {
    int mode;               /* 1 = view only, 2 = pick a town */
    int result;             /* 0 = cancelled, 1 = back, 2 = town picked */
    u16 townId;             /* start town in, picked town out */
    u16 townSubId;
    int pickedX;
    int pickedY;
    void *gameCtx;          /* 0x14 game context of the caller */
} TownMapArgs;

/* A point in screen or scroll coordinates. */
typedef struct TownMapPoint {
    int x;
    int y;
} TownMapPoint;

/* A screen position. */
typedef struct TownmapScreenPos {
    s16 x;
    s16 y;
} TownmapScreenPos;

/* Initial position and animation of a sprite. */
typedef struct SpriteInit {
    s16 x;
    s16 y;
    s16 animSeq;
    s16 reserved;
} SpriteInit;

/* Step function slot: call(this, &stepState, arg) runs until finished is set. */
struct TownMapWork;
typedef struct TownMapProc TownMapProc;
typedef void (*TownMapStepFunc)(TownMapProc *, int *, struct TownMapWork *);
struct TownMapProc {
    TownMapStepFunc call;
    int finished;
    int stepState;
    struct TownMapWork *arg;
};

/* One town on the map, 0x44 bytes. info is the town data source; the town
   record fields (see TOWNMAP_TownGetField) start at index. */
typedef struct TownMapTown {
    void *sprite;           /* 0x00 marker sprite, 0 for the player's town */
    char *info;             /* 0x04 town data source */
    int index;              /* 0x08 town number */
    int values[9];          /* 0x0C record fields 2..10: spriteX, spriteY, centerX, centerY,
                               lineX0, lineY0, lineX1, lineY1, lineWidth (scaled by zoom) */
    u8 frameHighlight;      /* 0x30 sprite frame when highlighted */
    u8 frameNormal;         /* 0x31 sprite frame when not highlighted */
    u8 frameShown;          /* 0x32 sprite frame now shown, 0xFF = none */
    int scale;              /* 0x34 zoom factor, 0x1000 = 1.0 */
    int visited;            /* 0x38 */
    int selectable;         /* 0x3C */
    int locked;             /* 0x40 hit tests and highlights skip it */
} TownMapTown;

/* Sprite that marks the current town on the map. */
typedef struct TownMapMarker {
    void *sprite;
    TownMapTown *town;
} TownMapMarker;

/* Map of the towns, 0x28 bytes. */
typedef struct TownMapMap {
    void *gameData;
    int pad04;
    TownMapTown *towns;
    u32 townCount;
    int scrollX;
    int scrollY;
    s16 minScrollY;
    s16 minScrollX;
    s16 maxScrollX;
    s16 maxScrollY;
    TownMapMarker marker;   /* 0x20 */
} TownMapMap;

/* Pointer cursor (two sprites) and the town under it, 0x18 bytes. */
typedef struct TownMapCursor {
    void *arrowSprite;      /* 0x00 */
    void *hoverSprite;      /* 0x04 sprite shown on the hovered town */
    s16 x;                  /* 0x08 */
    s16 y;                  /* 0x0A */
    int pressed;            /* 0x0C set for one update when the A button or touch confirms */
    int snapToTown;         /* 0x10 key mode: pull the cursor to the nearest town */
    TownMapTown *hoverTown; /* 0x14 */
} TownMapCursor;

/* Opaque library objects used by the graphics file. */
struct BmpWin;
struct Strbuf;
struct MsgBank;
struct ClactActor;
struct ClactUnit;
#include "../arm9/bg_sys_types.h"

/* Fixed point (fx32) vector. */
typedef struct TownMapVec {
    int x;
    int y;
    int z;
} TownMapVec;

/* Scroll and zoom state of the map layers, 0x38 bytes. */
typedef struct TownMapScroll {
    u8 bgId[2];             /* 0x00 the two map layers that scroll together */
    u16 step;               /* 0x02 zoom animation step, 0..10 */
    s16 minY;               /* 0x04 scroll limits */
    s16 minX;               /* 0x06 */
    s16 maxX;               /* 0x08 */
    s16 maxY;               /* 0x0A */
    int zoomDone;           /* 0x0C set on the step that ends a zoom */
    int zooming;            /* 0x10 */
    int scale;              /* 0x14 current scale, 0x1000 = 1.0 */
    int scaleTo;            /* 0x18 */
    int scaleFrom;          /* 0x1C */
    TownMapPoint pos;       /* 0x20 scroll position */
    TownMapPoint dst;       /* 0x28 zoom target position */
    TownMapPoint src;       /* 0x30 zoom start position */
} TownMapScroll;

/* Text window with a string buffer, 0x10 bytes. */
typedef struct TownMapTextBox {
    struct BmpWin *win;
    struct Strbuf *text;
    void *font;
    struct MsgBank *msg;
} TownMapTextBox;

/* Bottom screen town description, 0x14 bytes. */
typedef struct TownMapSelection {
    TownMapTextBox box;
    struct MsgBank *detailMsg;  /* 0x10 message bank of the detail lines */
} TownMapSelection;

/* Hover label: a text box plus its marker sprite, 0x20 bytes. */
typedef struct TownMapLabel {
    TownMapTextBox box;
    struct ClactActor *marker;  /* 0x10 */
    TownMapTown *town;          /* 0x14 town to show */
    int animating;              /* 0x18 marker animation runs, text not drawn yet */
    int requested;              /* 0x1C a new town was set */
} TownMapLabel;

/* Touch drag tracker, 0x30 bytes. */
typedef struct TownMapTouch {
    TownMapVec prev;        /* 0x00 previous touch point */
    TownMapVec cur;         /* 0x0C current touch point */
    u32 dragState;          /* 0x18 */
    int dragged;            /* 0x1C the point moved at least one pixel */
    int reanchor;           /* 0x20 take the next point as the new start */
    TownMapVec delta;       /* 0x24 cur - prev */
} TownMapTouch;

/* Sprite unit, sprite actors and their resource ids, 0x24 bytes. */
typedef struct TownMapSprites {
    union {
        struct {
            struct ClactUnit *unit;
            struct ClactActor *actor[4];
        };
        u32 handle[5];
    };
    u32 reserved14;
    union {
        struct {
            u32 charId;
            u32 cellId;
            u32 palId;
        };
        u32 resourceId[3];
    };
} TownMapSprites;

/* Graphics set of the town map, 0x2C bytes. */
typedef struct TownMapGfx {
    u32 bgReady;                /* 0x00 */
    TownMapSprites sprites;     /* 0x04 */
    struct TcbTask *task;                   /* 0x28 per frame task handle */
} TownMapGfx;

/* Back button, 0x20 bytes. */
typedef struct TownMapButtonBar {
    u32 charRes;            /* 0x00 */
    u32 plttRes;            /* 0x04 */
    u32 cellRes;            /* 0x08 */
    u32 buttonMan;          /* 0x0C button manager (TOUCHBAR_Create) */
    u32 ctx;                /* 0x10 */
    void *sprite;           /* 0x14 back button sprite */
    int pressed;            /* 0x18 pressed button id, -1 = none */
    int animState;          /* 0x1C 0 = idle, 1 = press animation running */
} TownMapButtonBar;

/* Work of the town map screen, 0x144 bytes. */
typedef struct TownMapWork {
    TownMapGfx *gfx;        /* 0x00 graphics set (townmap_grh.c) */
    TownMapProc proc;       /* 0x04 */
    TownMapButtonBar buttonBar;     /* 0x14 */
    struct TownMapInfoRow *mapInfo;            /* 0x34 */
    TownMapCursor cursor;            /* 0x38 */
    TownMapMap map;         /* 0x50 */
    TownMapScroll scroll;   /* 0x78 */
    TownMapSelection selection;     /* 0xB0 */
    TownMapTextBox panel;   /* 0xC4 */
    TownMapLabel label;     /* 0xD4 */
    TownMapTouch touch;     /* 0xF4 */
    void *fontSystem;       /* 0x124 */
    struct MsgBank *nameMsg;        /* 0x128 */
    struct MsgBank *detailMsg;      /* 0x12C */
    TownMapArgs *args;      /* 0x130 */
    TownMapTown *hoverTown;  /* 0x134 */
    int zooming;            /* 0x138 */
    struct TcbTask *vblankTask;         /* 0x13C */
    u8 pad140[4];
} TownMapWork;

#endif
