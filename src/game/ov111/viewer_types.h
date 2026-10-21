#ifndef VIEWER_TYPES_H
#define VIEWER_TYPES_H

/*
 * Shared types for the ov111 viewer feature (viewer_main.c, viewer_text.c,
 * viewer_actor.c).
 *
 * Two work objects live here:
 *
 *   ViewerWork      the main viewer work, allocated once in VIEWER_MAIN_Create
 *                   with PROCSYS_AllocProcWork(man, sizeof(ViewerWork), 0x27)
 *                   and sizeof == 0x3310. viewer_main.c, the drawing half of
 *                   viewer_text.c and the embedded anim all view it.
 *
 *   ViewerTextWork  the actor work, allocated once in VIEWER_TEXT_Create with
 *                   PROCSYS_AllocProcWork(proc, 0x1C8, 0x27) and
 *                   sizeof == 0x1C8. viewer_actor.c and the actor half of
 *                   viewer_text.c view it.
 *
 * Both were previously carried as one address-named stand-in struct per
 * function. Every field is a real field of one of these two objects.
 */

#include "../types.h"

/*
 * The info block pointed to by ViewerWork.info and ViewerArgs.info. It is the
 * save-block record the viewer displays (trainer name, play time, rows, badge
 * data) followed by a 0x600 byte signature bitmap. Size 0x674.
 */
typedef struct {
    u8 kind;                 /* 0x00 selection kind (0x14/0x15 select the bg set) */
    u8 pad1[2];
    u8 bgSlot;               /* 0x03 bg slot base */
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
    u8 pad5;
    u8 rowIndex;             /* 0x06 selected row */
    u8 pad7;
    u16 rowMask;             /* 0x08 row-present mask (16 bits) */
    u16 name[9];             /* 0x0A trainer name string */
    void *playTime;          /* 0x1C PlayTime, read by PLAYTIME_GetHours/650 */
    u32 topValue;            /* 0x20 printed with 7 digits */
    u32 topPadValue;         /* 0x24 formatted into a padded string */
    u16 row0Value;           /* 0x28 row 0 number */
    u16 row1Value;           /* 0x2A row 1 wrapped number */
    u16 row2Value;           /* 0x2C clipped row number */
    u8 row1Pad;              /* 0x2E row 1 wrapped number */
    u8 year1;                /* 0x2F year + 2000 */
    u8 month1;               /* 0x30 */
    u8 day1;                 /* 0x31 */
    u8 year2;                /* 0x32 year + 2000 */
    u8 month2;               /* 0x33 (also the "date 2 present" test) */
    u8 day2;                 /* 0x34 */
    u8 row5Value;            /* 0x35 */
    u8 pad36[2];
    u32 row6Value;           /* 0x38 row 6 number */
    u32 row7Value;           /* 0x3C row 7 number */
    u32 row8Value;           /* 0x40 row 8 number */
    u32 row9Value;           /* 0x44 row 9 number */
    u32 listIndex;           /* 0x48 DrawList cursor (0..0x18) */
    u32 row10Value;          /* 0x4C row 10 number */
    u32 row11Value;          /* 0x50 row 11 number */
    u32 row12Value;          /* 0x54 row 12 number */
    u32 row13Value;          /* 0x58 row 13 number */
    u16 row14Value;          /* 0x5C row 14 number */
    u16 row15Value;          /* 0x5E row 15 number */
    u16 row16Value;          /* 0x60 row 16 number */
    u16 row17Value;          /* 0x62 row 17 number */
    u16 row18Value;          /* 0x64 row 18 number */
    u8 pad66[2];
    u32 hasRow14 : 1;        /* 0x68 optional rows appended by SetScrollParam */
    u32 hasRow15 : 1;
    u32 hasRow16 : 1;
    u32 hasRow17 : 1;
    u32 hasRow18 : 1;
    u32 padBits : 27;
    u8 decoData[8];          /* 0x6C PMS_DRAW_Print source (address is passed) */
    u8 bitmap[0x600];        /* 0x74 signature bitmap */
} ViewerInfo;

/* Character graphics data, written by ARC_UTIL_LoadBgCharDataFromArchive into work->chr. */
typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} ViewerCharData;

/* Screen cell data, written into work->scrn. */
typedef struct {
    u16 w;
    u16 h;
} ViewerScrnData;

/* Palette data, written into work->pltt. */
typedef struct {
    u8 pad0[0xC];
    u16 *data;
} ViewerPlttData;

/* A palette/character/cell-anim id triple, one per registered row set. */
typedef struct {
    u32 palette;
    u32 chr;
    u32 cellAnim;
} ViewerRes;

/*
 * The animation sub-object embedded in ViewerWork at 0x3070. Holds the clact
 * unit, the eight actor objects and the two registered resource sets. Size 0xD0.
 */
typedef struct {
    u16 heap;                /* 0x00 */
    u8 pad2[2];
    struct Unit *unit;                /* 0x04 CLACT unit */
    u8 pad8[0x90];
    void *obj[8];            /* 0x98 CLACT actors */
    ViewerRes res[2];        /* 0xB8 registered resource sets */
} ViewerAnim;

/* A touch point (x, y, brush size, active flag). */
typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} ViewerTouchPos;

/* Options block read through ViewerArgs.info (bit flags at 0x4). */
typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 padBits : 1;
} ViewerCfg;

/* The args block passed to VIEWER_MAIN_Create / VIEWER_TEXT_Create. */
typedef struct {
    ViewerInfo *info;
    void *gameData;
    u32 editMode;
    u32 exitCode;
    u32 nextScreen;
    u32 decoMode;
} ViewerArgs;

/*
 * The main viewer work object. Allocated once with
 * PROCSYS_AllocProcWork(man, sizeof(ViewerWork), 0x27) in VIEWER_MAIN_Create.
 * The size must stay 0x3310.
 */
typedef struct {
    u16 heap;                /* 0x0000 */
    u8 pad2[2];
    void *bg[8];             /* 0x0004 bmp windows */
    ViewerArgs *args;        /* 0x0024 */
    ViewerInfo *info;        /* 0x0028 */
    u8 pix[0x3000];          /* 0x002C canvas (0xC0 * 0x40) */
    void *chrHandle;         /* 0x302C character data handle */
    ViewerCharData *chr;     /* 0x3030 */
    u32 decoVisible;         /* 0x3034 */
    u8 pad3038[4];
    fx32 scaleX;             /* 0x303C */
    fx32 scaleY;             /* 0x3040 */
    u8 pad3044[4];
    int angle;               /* 0x3048 */
    u32 cx;                  /* 0x304C */
    u32 cy;                  /* 0x3050 */
    u32 x;                   /* 0x3054 */
    u32 y;                   /* 0x3058 */
    u16 pane;                /* 0x305C 0 left half, 1 right half */
    u16 inputMode;           /* 0x305E 0 touch, 1 key */
    int mode;                /* 0x3060 */
    u8 pad3064[0xC];
    ViewerAnim anim;         /* 0x3070 size 0xD0 */
    u8 pad3140[0x84];
    u32 counter;             /* 0x31C4 */
    u8 pad31C8[0x10];
    void *scrnRes;           /* 0x31D8 screen cell resource handle */
    ViewerScrnData *scrn;    /* 0x31DC */
    u8 pad31E0[8];
    void *plttRes;           /* 0x31E8 palette resource handle */
    ViewerPlttData *pltt;    /* 0x31EC */
    int frame;               /* 0x31F0 */
    void *vblankTask;        /* 0x31F4 */
    void *tcbl;              /* 0x31F8 */
    void *font;              /* 0x31FC */
    void *msgBank;           /* 0x3200 */
    void *wordSet;           /* 0x3204 */
    void *strbuf0;           /* 0x3208 */
    void *strbuf1;           /* 0x320C */
    void *strbuf2;           /* 0x3210 */
    void *strbuf3;           /* 0x3214 */
    void *headerText[3];     /* 0x3218 messages 0x1A..0x1C */
    void *footerText[2];     /* 0x3224 messages 0x1D..0x1E */
    void *msgText[26];       /* 0x322C messages 0x00..0x19 (DrawRow labels) */
    void *taggedText[5];     /* 0x3294 messages 0x38..0x3C */
    u8 pad32A8[8];
    void *pmsDraw;           /* 0x32B0 */
    u8 flags[16];            /* 0x32B4 expanded info->h8 mask */
    u8 keyRepeat;            /* 0x32C4 */
    u8 pad32C5;
    u8 state;                /* 0x32C6 */
    u8 blink;                /* 0x32C7 */
    u8 phase;                /* 0x32C8 */
    u8 pad32C9;
    u8 hasInfo : 1;          /* 0x32CA set from info->b33 */
    u8 netActive : 1;        /* 0x32CA set when negotiation > 0 */
    u8 dirty : 1;            /* 0x32CA bg redraw pending */
    u8 padBits : 5;
    u8 pad32CB;
    void *printQue;          /* 0x32CC PRINTSYS queue */
    u8 pad32D0[4];
    u8 charVariant;          /* 0x32D4 passed to BMP_MENUWORK_LoadCharAndPltt */
    u8 msgSpeed;             /* 0x32D5 */
    u8 shake;                /* 0x32D6 */
    u8 pad32D7;
    u32 touchX;              /* 0x32D8 */
    u32 touchY;              /* 0x32DC */
    u8 pad32E0[2];
    s16 scroll;              /* 0x32E2 */
    s16 prevScroll;          /* 0x32E4 */
    s16 grabY;               /* 0x32E6 */
    s16 grabScroll;          /* 0x32E8 */
    ViewerTouchPos raw;      /* 0x32EA */
    ViewerTouchPos cur;      /* 0x32EE */
    ViewerTouchPos prev;     /* 0x32F2 */
    u8 size;                 /* 0x32F6 */
    u8 pageDirty;            /* 0x32F7 page needs redraw */
    u8 pageDirty2;           /* 0x32F8 */
    u8 cooldown;             /* 0x32F9 */
    u8 rowList[0x13];        /* 0x32FA DrawPage row list */
    u8 rowCount;             /* 0x330D */
    u8 pageInputArmed;       /* 0x330E */
    u8 scrollTouchArmed;     /* 0x330F */
} ViewerWork;

/*
 * The data block pointed to by ViewerTextWork.res158/res170 entries. Size 0x10.
 */
typedef struct {
    u8 pad0[0xC];
    u8 *data;
} ViewerResData;

/*
 * The actor work object. Allocated once with
 * PROCSYS_AllocProcWork(proc, 0x1C8, 0x27) in VIEWER_TEXT_Create.
 * The size must stay 0x1C8.
 */
typedef struct {
    void *arc;               /* 0x000 archive handle (ARC_TOOL_CreateHandle) */
    void *font;              /* 0x004 GfFont */
    void *bgWindow;          /* 0x008 bmp window (VIEWER_ACTOR_InitBgWindow) */
    void *printWindow;       /* 0x00C window used for printing (= bgWindow) */
    u8 queDirty;             /* 0x010 print queue holds pending text */
    u8 pad11[3];
    void *printQue;          /* 0x014 PRINTSYS queue */
    u8 pad18[8];             /* 0x018 */
    void *msgBank;           /* 0x020 */
    void *wordSet;           /* 0x024 */
    void *strbuf;            /* 0x028 scratch strbuf */
    void *rowText[7];        /* 0x02C messages 0x00..0x06 */
    void *unit;              /* 0x048 CLACT unit */
    union {
        void *obj[36];       /* 0x04C flat actor array (CreateObjects view) */
        struct {
            void *actorA;        /* 0x04C */
            void *actorB;        /* 0x050 */
            void *actorC;        /* 0x054 */
            void *actorD;        /* 0x058 */
            void *rowActor[8];   /* 0x05C one actor per row */
            void *rowSubActor[24];/* 0x07C 8 rows x 3 sub-actors (row*3+i) */
        } named;
    } actors;                /* 0x04C */
    union {
        void *set[6];        /* 0x0DC flat resource set (CreateObjects view) */
        struct {
            void *palette;       /* 0x0DC */
            void *chr;           /* 0x0E0 */
            void *cellAnim;      /* 0x0E4 */
            void *palette2;      /* 0x0E8 */
            void *chr2;          /* 0x0EC */
            void *cellAnim2;     /* 0x0F0 */
        } named;
    } resSet;                /* 0x0DC */
    void *vblankTask;        /* 0x0F4 */
    void *g3dUtil;           /* 0x0F8 */
    u16 g3dUnit;             /* 0x0FC */
    u8 padFE[2];
    void *lightSlot;         /* 0x100 */
    void *camera;            /* 0x104 */
    ViewerArgs *parent;      /* 0x108 */
    int state;               /* 0x10C dispatch state */
    int action;              /* 0x110 selected action */
    u16 page;                /* 0x114 current page */
    u16 pageCount;           /* 0x116 */
    int rowCount;            /* 0x118 */
    int vblankCount;         /* 0x11C */
    u8 pad120[2];
    u16 touchState;          /* 0x122 drag touch state */
    u8 pad124[4];
    int dragX;               /* 0x128 last touch x */
    int dragPrevX;           /* 0x12C previous last touch x */
    int dragStartX;          /* 0x130 drag start x */
    u8 pad134[4];
    int dragStartAngle;      /* 0x138 angle at drag start */
    int angle;               /* 0x13C model angle */
    int spin;                /* 0x140 bounce/spin speed */
    int snap;                /* 0x144 snap pending (-1 none) */
    int snapAngle;           /* 0x148 snap target angle */
    void *res14C[3];         /* 0x14C */
    ViewerResData *res158[3];/* 0x158 */
    void *res164[3];         /* 0x164 */
    ViewerResData *res170[3];/* 0x170 */
    u8 rowEnabled[8];        /* 0x17C */
    void *saveBlock;         /* 0x184 GAME_DATA save block */
    int badgeTimer[8];       /* 0x188 */
    u8 paletteIndex[8];      /* 0x1A8 */
    u8 lastPaletteIndex[8];  /* 0x1B0 */
    u8 scrollRepeat[2];      /* 0x1B8 */
    s8 dragDirX;             /* 0x1BA */
    s8 dragDirY;             /* 0x1BB */
    u8 pad1BC[4];
    u32 prevX;               /* 0x1C0 */
    u32 prevY;               /* 0x1C4 */
} ViewerTextWork;

#endif
