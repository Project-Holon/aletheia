#ifndef OV099_WIFI_CLUB_ACTOR_TYPES_H
#define OV099_WIFI_CLUB_ACTOR_TYPES_H

/* Shared types of the Wi-Fi club actor module (people walking on the tile map
 * and the cursor that picks one). Module name is a guess from the callees. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef int BOOL;

typedef struct { short x, y; } TilePos;
typedef struct { u16 w, h; } MapSize;

/* Palette file loaded for the cursor blink. */
typedef struct WifiClubPaletteData {
    u8 pad00[0xC];
    u16 *colors;                   /* 0x0C */
} WifiClubPaletteData;

struct WifiClubActorSys;

/* One person on the map: 0x1C bytes, 0x30 of them in the system object. */
typedef struct WifiClubActor {
    void *entity;                  /* 0x00: map entity, zero while the slot is free */
    void *sprite;                  /* 0x04: sprite animation object */
    union {
        s16 timer;
        u16 phase;
    } counter;                     /* 0x08: countdown or sine phase, per state */
    u8 pickResult;                  /* 0x0A: id of the actor the cursor picked, set by the A button */
    u8 savedMode;                  /* 0x0B: mode last requested for the actor */
    u16 state;                     /* 0x0C: 0 and 3 and 4 let the cursor pick it */
    u16 prevState;                 /* 0x0E */
    int (*updateFn)();             /* 0x10: returns 1 to free the slot */
    int (*prevUpdateFn)();         /* 0x14 */
    void (*animFn)();              /* 0x18 */
} WifiClubActor;

/* Palette blink of the cursor: flips between two frames and rewrites colours. */
typedef struct WifiClubPaletteBlink {
    void *paletteHandle;           /* 0x00 */
    WifiClubPaletteData *paletteData; /* 0x04: filled by the loader */
    u8 colorMask;                  /* 0x08: one bit per colour that blinks */
    u8 frame;                      /* 0x09 */
    s16 frameTimer;                /* 0x0A */
    u8 stepColor;                  /* 0x0C: colour index of the step script */
    u8 stepIndex;                  /* 0x0D: position in the step script, 0 = idle */
    s16 stepTimer;                 /* 0x0E */
    u8 stepRestart;                /* 0x10 */
    u8 pad11[3];
} WifiClubPaletteBlink;

/* Sprite system handle and the resources/actors of the cursor. */
typedef struct WifiClubSpriteSet {
    void *clactSys;                /* 0x00 */
    void *gfxArchive;              /* 0x04 */
    s32 charRes;                   /* 0x08 */
    s32 palRes;                    /* 0x0C */
    s32 cellRes;                   /* 0x10 */
    void *cursorActor;             /* 0x14 */
    void *markerActor;             /* 0x18 */
} WifiClubSpriteSet;

typedef struct WifiClubActorSys {
    u32 ready;                     /* 0x00 */
    u32 heapId;                    /* 0x04 */
    u8 pad08[4];
    u32 mode;                      /* 0x0C */
    void *reserved10;              /* 0x10: never written by the init */
    WifiClubSpriteSet sprites;     /* 0x14 */
    WifiClubActor actors[0x30];    /* 0x30 */
    WifiClubActor *selected;       /* 0x570 */
    WifiClubPaletteBlink blink;    /* 0x574 */
    void *tileMap;                 /* 0x588 */
    void *entityMgr;               /* 0x58C */
    void *spriteMgr;               /* 0x590 */
    u32 layerState;                /* 0x594 */
    void *layer;                   /* 0x598 */
    void *cmdQueue;                /* 0x59C */
} WifiClubActorSys;

#endif
