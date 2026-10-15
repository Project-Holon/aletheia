#ifndef WF2DMAP_UI_TYPES_H
#define WF2DMAP_UI_TYPES_H

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
    unsigned int textHandle;        /* 0x01C: text handle for TOUCHBAR_PrintAligned */
    void *formatArg;                /* 0x020: WORDSET_CopyTaggedText source */
    unsigned char pad_024[4];
    void *tcbl;                     /* 0x028 */
    void *printStream;              /* 0x02C */
    unsigned char pad_030[4];
    void *printWin;                 /* 0x034: TOUCHBAR_PrintAligned target */
    void *slotArray[0x40];          /* 0x038: 64-entry window-record list */
    unsigned int actorBank;         /* 0x138 */
    unsigned int actorBank2;        /* 0x13C */
    unsigned int renderer;          /* 0x140 */
    unsigned int character[2];      /* 0x144 */
    unsigned int palette[2];        /* 0x14C */
    unsigned int cellAnim[2];       /* 0x154 */
    void *actorSlot[2];             /* 0x15C */
    void *actorA;                   /* 0x164: friend-key confirm actor */
    void *actorB;                   /* 0x168: friend-key cancel actor */
    void *bmpHandle[2];             /* 0x16C */
    void *bmpDesc[2];               /* 0x174 */
    void *palWin;                   /* 0x17C: TOUCHBAR_PrintAligned palette target */
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
    void *saveData;                 /* 0x04: save control object */
    unsigned char state;            /* 0x08: screen state byte */
    unsigned char stateArgA;        /* 0x09: first state argument byte */
    unsigned char stateArgB;        /* 0x0A: second state argument byte */
    signed char index;              /* 0x0B: current entry index */
    signed char speed;              /* 0x0C: message speed */
    unsigned char pad_00D;          /* 0x0D */
    unsigned char nameReady;        /* 0x0E */
    unsigned char pad_00F;          /* 0x0F */
    unsigned int count;             /* 0x10: number of valid entries */
    int nextColor;                  /* 0x14: next entry colour index */
    unsigned char entryIndex[32];   /* 0x18: entry slot -> friend index */
    unsigned char entryColor[32];   /* 0x38: entry slot -> colour index */
    void *textBufA;                 /* 0x58 */
    void *textBufB;                 /* 0x5C */
    void *nameText;                 /* 0x60: pending name-entry string */
    int nameFlag;                   /* 0x64: pending name-entry flag */
} Wf2dmapTouchFriendData;

/* One widget slot: a BMP window handle and its bitmap. */
typedef struct Wf2dmapTouchWidget {
    void *handle;                   /* 0x00 */
    void *bitmap;                   /* 0x04 */
} Wf2dmapTouchWidget;

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
    unsigned char pad_014[0xE4];       /* 0x014: three tile records (Record, 0x4C each) */
    Wf2dmapTouchWidget widget[4];      /* 0x0F8: per-entry widget handles */
    Wf2dmapTouchWidget editWindow[2];  /* 0x118 */
    Wf2dmapTouchWidget trainerWindow[10]; /* 0x128 */
    void *cursorBmp;                   /* 0x178 */
    unsigned int cgr;                  /* 0x17C */
    unsigned int palette;              /* 0x180 */
    unsigned int cellAnim;             /* 0x184 */
} Wf2dmapTouchEdit;

#endif
