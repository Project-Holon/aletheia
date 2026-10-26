#ifndef WF2DMAP_UI_TYPES_H
#define WF2DMAP_UI_TYPES_H

#include "../types.h"
#include "../arm9/clact.h"

/*
 * Real struct types for the ov128 friend-list UI objects of
 * wf2dmap_friend.c and wf2dmap_touch.c. These replace the address-named
 * stand-in views (struct ObjNNNNN) that the matcher generated per cast site.
 *
 * Offsets are fixed by the original build; do not reorder the fields.
 */

/* Bitmap header: the first two halfwords are the pixel size. */
typedef struct Wf2dmapBitmapHeader {
    unsigned short width;           /* 0x00: pixel width, read as >>3 */
    unsigned short height;          /* 0x02: pixel height, read as >>3 */
} Wf2dmapBitmapHeader;

/*
 * The friend-key / friend-edit screen window set (root+0x404): two BMP
 * windows, the archive handle they were loaded from, and the loaded bitmap.
 */
typedef struct Wf2dmapTouchWindowSet {
    void *windowA;                  /* 0x00: first BMP window */
    unsigned char pad_004[4];
    void *windowB;                  /* 0x08: second BMP window */
    unsigned char pad_00C[4];
    void *archive;                  /* 0x10: archive handle */
    void *bitmap;                   /* 0x14: bitmap loaded into the archive */
} Wf2dmapTouchWindowSet;

/*
 * The friend-list graphics context (root+0x04): fonts, windows, actor
 * banks, palette animations and the slot list. Passed as the second
 * object through the whole wf2dmap_friend / wf2dmap_touch flow.
 */
typedef struct Wf2dmapTouchGfx {
    void *wordSet;                  /* 0x000 */
    void *msgBank;                  /* 0x004 */
    void *archive;                  /* 0x008 */
    void *window;                   /* 0x00C: single BMP window */
    unsigned char pad_010[4];
    void *textBufA;                 /* 0x014 */
    void *textBufB;                 /* 0x018 */
    union {                         /* 0x01C: text handle for TOUCHBAR_PrintAligned */
        void *textHandle;
        void *textHandleStrbuf;
    };
    void *formatArg;                /* 0x020: WORDSET_CopyTaggedText source */
    unsigned char pad_024[4];
    void *tcbl;                     /* 0x028 */
    void *printStream;              /* 0x02C */
    int printState;                 /* 0x030: result slot of the print stream update */
    union { void *printWin; unsigned int printWinU32; }; /* 0x034: TOUCHBAR_PrintAligned target */
    void *slotArray[0x40];          /* 0x038: 64-entry window-record list */
    struct Unit *actorBank;         /* 0x138 */
    struct Unit *actorBank2;        /* 0x13C */
    struct Renderer *renderer;      /* 0x140 */
    unsigned int character[2];      /* 0x144 */
    unsigned int palette[2];        /* 0x14C */
    unsigned int cellAnim[2];       /* 0x154 */
    struct ClactActor *actorSlot[2]; /* 0x15C */
    struct ClactActor *actorA;      /* 0x164: friend-key confirm actor */
    struct ClactActor *actorB;      /* 0x168: friend-key cancel actor */
    void *bmpHandle[2];             /* 0x16C */
    void *bmpDesc[2];               /* 0x174 */
    union { void *palWin; unsigned int palWinU32; };         /* 0x17C */
    unsigned short heapId;          /* 0x180 */
    void *palAnimA;                 /* 0x184 */
    void *palAnimB;                 /* 0x188 */
} Wf2dmapTouchGfx;

/*
 * The friend-data record (root+0x190): the save object, the entry index
 * list, the current selection and the name-entry buffers.
 */
typedef struct Wf2dmapTouchFriendData {
    unsigned int textSpeed;         /* 0x00 */
    union { void *saveData; unsigned int saveWord; }; /* 0x04: save control object */
    unsigned char state;            /* 0x08: screen state byte */
    unsigned char stateArgA;        /* 0x09: first state argument byte */
    unsigned char stateArgB;        /* 0x0A: second state argument byte */
    signed char index;              /* 0x0B: current entry index */
    signed char speed;              /* 0x0C: message speed */
    unsigned char windowFrame;      /* 0x0D: window frame style */
    unsigned char nameReady;        /* 0x0E */
    unsigned char pad_00F;          /* 0x0F */
    unsigned int count;             /* 0x10: number of valid entries */
    int nextColor;                  /* 0x14: next entry colour index */
    unsigned char entryIndex[32];   /* 0x18: entry slot -> friend index */
    unsigned char entryColor[32];   /* 0x38: entry slot -> colour index */
    void *textBufA;                 /* 0x58 */
    void *textBufB;                 /* 0x5C */
    union { void *nameText; int nameTextInt; }; /* 0x60: pending name-entry string */
    int nameFlag;                   /* 0x64: pending name-entry flag */
} Wf2dmapTouchFriendData;

/* One widget slot: a BMP window handle and its bitmap. */
typedef struct Wf2dmapTouchWidget {
    void *handle;                   /* 0x00 */
    void *bitmap;                   /* 0x04 */
} Wf2dmapTouchWidget;

/*
 * One tile record: the tile origin, a value word, then eight window
 * pointers and their eight per-entry counts (0x4C bytes).
 */
typedef struct Wf2dmapTouchTileRecord {
    short x;                           /* 0x00 */
    short y;                           /* 0x02 */
    unsigned short z;                  /* 0x04 */
    unsigned short pad_006;
    unsigned int value;                /* 0x08 */
    void *items[8];                    /* 0x0C: per-entry window pointers */
    volatile unsigned int count[8];    /* 0x2C: per-entry window counts */
} Wf2dmapTouchTileRecord;

/*
 * The friend-edit screen object (root+0x420): the edit value, the slide
 * animation state, the three tile records and the widget slots.
 */
typedef struct Wf2dmapTouchEdit {
    short value;                       /* 0x000 */
    unsigned char pad_002[2];
    int slideStep;                     /* 0x004 */
    int variant;                       /* 0x008 */
    unsigned short timer;              /* 0x00C */
    unsigned short flagE;              /* 0x00E */
    int direction;                     /* 0x010 */
    Wf2dmapTouchTileRecord tile[3];    /* 0x014: three 0x4C-byte tile records */
    Wf2dmapTouchWidget widget[4];      /* 0x0F8: per-entry widget handles */
    Wf2dmapTouchWidget editWindow[2];  /* 0x118 */
    Wf2dmapTouchWidget trainerWindow[10]; /* 0x128 */
    union {                            /* 0x178 */
        struct ClactActor *actor;      /* trainer CLACT actor */
        unsigned int cursorBmp;        /* cursor bitmap pointer (DrawCursorBg) */
    };
    unsigned int cgr;                  /* 0x17C: trainer character */
    unsigned int palette;              /* 0x180: trainer palette */
    unsigned int cellAnim;             /* 0x184: trainer cell animation */
} Wf2dmapTouchEdit;

/*
 * One of the three 0x4C-byte entry pages inside the item screen. The two
 * pointer arrays hold the wifi-2dchar actors and the CLACT actors of the
 * page's eight entry slots.
 */
typedef struct Wf2dmapFriendEntryPage {
    short x;                           /* 0x00 */
    short y;                           /* 0x02 */
    unsigned char tileW;               /* 0x04 */
    unsigned char tileH;               /* 0x05 */
    unsigned char pad_006[2];
    void *window;                      /* 0x08: page BMP window */
    void *wifiActor[8];                /* 0x0C */
    void *clactActor[8];               /* 0x2C */
} Wf2dmapFriendEntryPage;

/* One item widget: a message text handle, its colour and a flag word. */
typedef struct Wf2dmapFriendWidget {
    void *text;                        /* 0x00 */
    unsigned short color;              /* 0x04 */
    unsigned short pad_006;
    unsigned int flag;                 /* 0x08 */
} Wf2dmapFriendWidget;

/*
 * The friend-list item screen object (root+0x24C, 0x1AC bytes): the cursor,
 * the three entry pages, the widgets, the task menus and the entry actor.
 */
typedef struct Wf2dmapFriendItemScreen {
    short page;                        /* 0x000 */
    short prevPage;                    /* 0x002 */
    short cursor;                      /* 0x004 */
    short prevCursor;                  /* 0x006 */
    unsigned short blinkState;         /* 0x008: item-bar blink state */
    unsigned short blinkTimer;         /* 0x00A: item-bar blink timer */
    Wf2dmapFriendEntryPage pages[3];   /* 0x00C */
    Wf2dmapTouchWidget entryWindow[2]; /* 0x0F0: the two entry BMP windows */
    short openCounter;                 /* 0x100: item-open animation counter */
    unsigned short openMode;           /* 0x102: item-open direction */
    void *wifiActor;                   /* 0x104 */
    void *window;                      /* 0x108: detail BMP window */
    unsigned char pad_10C[4];
    void *strbuf;                      /* 0x110 */
    unsigned char pad_114[4];
    Wf2dmapFriendWidget widget[4];     /* 0x118 */
    Wf2dmapFriendWidget widgetKey[4];  /* 0x148 */
    void *textA;                       /* 0x178 */
    unsigned short colorA;             /* 0x17C */
    unsigned int flagA;                /* 0x180 */
    void *textB;                       /* 0x184 */
    unsigned short colorB;             /* 0x188 */
    unsigned int flagB;                /* 0x18C */
    void *menu;                        /* 0x190: task-menu resource */
    void *taskMenu;                    /* 0x194 */
    int menuFlag;                      /* 0x198 */
    int countdown;                     /* 0x19C: close countdown */
    struct ClactActor *actor;          /* 0x1A0 */
    struct ClactActor *actor2;         /* 0x1A4 */
    unsigned int animFrame;            /* 0x1A8 */
} Wf2dmapFriendItemScreen;

/*
 * The friend-list / top-bar screen object (root+0x1FC, 0x50 bytes): the
 * highlight, the top-bar blink state and the list windows.
 */
typedef struct Wf2dmapFriendListScreen {
    unsigned int highlight;            /* 0x00: highlighted row */
    unsigned char pad_004[4];
    unsigned short blinkState;         /* 0x08 */
    unsigned short blinkTimer;         /* 0x0A */
    void *windowA;                     /* 0x0C */
    unsigned char pad_010[4];
    void *bitmap;                      /* 0x14 */
    void *bmpDesc;                     /* 0x18 */
    void *windowB;                     /* 0x1C */
    unsigned char pad_020[0x0C];
    void *buf;                         /* 0x2C */
    void *text1;                       /* 0x30 */
    unsigned short color1;             /* 0x34 */
    unsigned short pad_036;
    unsigned int flag1;                /* 0x38 */
    void *text2;                       /* 0x3C */
    unsigned short color2;             /* 0x40 */
    unsigned short pad_042;
    unsigned int flag2;                /* 0x44 */
    void *menu;                        /* 0x48 */
    void *taskMenu;                    /* 0x4C */
} Wf2dmapFriendListScreen;

/*
 * The whole friend screen work object (0x5B0 bytes). It embeds the graphics
 * context, the friend data, the list screen, the item screen, the window set
 * and the edit screen at the offsets the original reads them from.
 */
typedef struct Wf2dmapFriendRoot {
    int screenMode;                    /* 0x000 */
    Wf2dmapTouchGfx gfx;               /* 0x004 */
    Wf2dmapTouchFriendData friendData; /* 0x190 */
    void *saveData;                    /* 0x1F8 */
    Wf2dmapFriendListScreen listScreen;/* 0x1FC */
    Wf2dmapFriendItemScreen itemScreen;/* 0x24C */
    void *nameEntry[3];                /* 0x3F8 */
    Wf2dmapTouchWindowSet windowSet;   /* 0x404 */
    unsigned char pad_41C[4];
    Wf2dmapTouchEdit edit;             /* 0x420 */
    void *procHandle;                  /* 0x5A8 */
    int counter;                       /* 0x5AC */
} Wf2dmapFriendRoot;

/* A slot record pointed to by Wf2dmapTouchGfx.slotArray. */
typedef struct Wf2dmapTouchSlot {
    void *window;                      /* 0x00 */
    unsigned char dirty;               /* 0x04 */
} Wf2dmapTouchSlot;

/* The bmpHandle / bmpDesc pair at gfx+0x16C. */
typedef struct Wf2dmapTouchBmp {
    void *handle[2];                   /* 0x00 */
    void *desc[2];                     /* 0x08 */
} Wf2dmapTouchBmp;

/*
 * The entry index table header: an overlay of Wf2dmapTouchFriendData
 * starting at its count word (friendData+0x10).
 */
typedef struct Wf2dmapFriendEntryTable {
    unsigned int count;                /* 0x00: friendData.count */
    unsigned char pad_004[4];
    unsigned char index[32];           /* 0x08: friendData.entryIndex */
} Wf2dmapFriendEntryTable;

/* The save control object (GAME_DATA_GetSaveControl result); only the mode word. */
typedef struct Wf2dmapSaveControl {
    unsigned char pad_000[4];
    int mode;                          /* 0x04 */
} Wf2dmapSaveControl;

#endif
