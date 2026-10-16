#ifndef ALETHEIA_OV133_DUP_FITTING_TYPES_H
#define ALETHEIA_OV133_DUP_FITTING_TYPES_H

/*
 * Types for ov133 dup_fitting.c (the fitting-room screen work object).
 * Replaces the address-named Obj views that used to describe the object
 * through one field at a time.
 */

struct DupFittingWork {
    unsigned short heapId;        /* 0x0000 heap the work object was allocated from */
    unsigned char  pad_2[2];
    void          *parent;        /* 0x0004 owning screen object */
    void          *task;          /* 0x0008 GFL_USE_AddMainTask task handle */
    int            state;         /* 0x000C screen state */
    int            progress;      /* 0x0010 panel slide progress 0..192 */
    int            touchTrg;      /* 0x0014 TOUCHPANEL_GetTrg edge */
    int            touchCont;     /* 0x0018 TOUCHPANEL_GetPointCont hold */
    int            cursorX;       /* 0x001C touch cursor x 0..255 */
    unsigned int   cursorY;       /* 0x0020 touch cursor y 16..176 */
    unsigned int   prevX;         /* 0x0024 previous cursor x */
    unsigned int   prevY;         /* 0x0028 previous cursor y */
    unsigned short f2C;           /* 0x002C */
    unsigned char  pad_2E[2];
    int            dragActive;    /* 0x0030 drag in progress */
    int            frameIndex;    /* 0x0034 selected frame index 0..10 */
    void          *heldElem;      /* 0x0038 element currently held */
    int            holdState;     /* 0x003C hold state 0/1/2 */
    int            holdKind;      /* 0x0040 hold kind 0..3 */
    int            holdDx;        /* 0x0044 held element x */
    int            holdDy;        /* 0x0048 held element y */
    void          *elemPool;      /* 0x004C pool the held element came from */
    unsigned short f50;           /* 0x0050 */
    unsigned char  pad_52[2];
    int            bmpKeyA;       /* 0x0054 billboard image key */
    int            bmpKeyB;       /* 0x0058 billboard image key */
    unsigned int   bmpHandles[14];/* 0x005C freed billboard element handles */
    unsigned short timer;         /* 0x0094 frame counter 0..90 */
    unsigned char  pad_96[2];
    int            subMode;       /* 0x0098 1 while the sub-screen path runs */
    unsigned int   f9C;           /* 0x009C */
    unsigned int   fA0;           /* 0x00A0 */
    int            fA4;           /* 0x00A4 */
    unsigned short frameCount;    /* 0x00A8 number of frames */
    unsigned char  pad_AA[2];
    unsigned char  frameRecords[0x1434 - 0x00AC]; /* 0x00AC per-frame records */
    void          *frameOrder[1]; /* 0x1434 frame pointer array */
    unsigned char  pad_1438[0x181C - 0x1438];
    void          *itemList;      /* 0x181C item element list head */
    void          *listA;         /* 0x1820 worn element list */
    void          *listB;         /* 0x1824 spare element list */
    void          *listC;         /* 0x1828 spare element list */
    unsigned short rotation;      /* 0x182C model rotation 0..0xFFFF */
    short          rotationVel;   /* 0x182E model rotation velocity */
    unsigned short turnAccum;     /* 0x1830 accumulated turn */
    unsigned char  pad_1832[2];
    unsigned int   f1834;         /* 0x1834 */
    short          f1838;         /* 0x1838 */
    short          f183A;         /* 0x183A */
    int            firstTouch;    /* 0x183C touch released this frame */
    unsigned int   f1840;         /* 0x1840 fitting-setting flag */
    unsigned short animStep;      /* 0x1844 pose animation step */
    unsigned char  animPhase;     /* 0x1846 pose animation phase */
    unsigned char  animSlot;      /* 0x1847 pose animation slot */
    void          *clactUnit;     /* 0x1848 CLACT unit */
    void          *actorA;        /* 0x184C actor A */
    void          *actorB;        /* 0x1850 actor B */
    void          *actorC;        /* 0x1854 actor C */
    unsigned int   clactRes[9];   /* 0x1858 3 palettes, 3 characters, 3 cell anims */
    unsigned int   renderObj;     /* 0x187C MCSS render object id */
    int            renderParam;   /* 0x1880 MCSS render object parameter */
    void          *elemSet;       /* 0x1884 MCSS element set */
    void          *camera;        /* 0x1888 G3D camera */
    void          *billboard;     /* 0x188C billboard */
    void          *actors[8];     /* 0x1890 background actors */
    void          *actorX;        /* 0x18B0 base actor */
    void          *actorY;        /* 0x18B4 base actor */
    unsigned char  actorTimers[8];/* 0x18B8 actor respawn timers */
    unsigned char  f18C0;         /* 0x18C0 */
    unsigned char  counter;       /* 0x18C1 frame counter 0..1 */
    unsigned short f18C2;         /* 0x18C2 */
    short          f18C4;         /* 0x18C4 */
    unsigned char  brightness;    /* 0x18C6 screen brightness 0..128 */
    unsigned char  pad_18C7[1];
    unsigned int   mode;          /* 0x18C8 screen mode */
    unsigned int   busy;          /* 0x18CC print queue busy */
    unsigned int   flag;          /* 0x18D0 window shown */
    unsigned short sentinel;      /* 0x18D4 cached text key */
    unsigned char  pad_18D6[2];
    void          *msgBankA;      /* 0x18D8 message bank */
    void          *msgBankB;      /* 0x18DC message bank */
    void          *msgBankC;      /* 0x18E0 message bank */
    void          *font;          /* 0x18E4 EC64 font */
    void          *printSys;      /* 0x18E8 print queue */
    void          *window;        /* 0x18EC BMP window */
};

typedef char DupFittingWork_size_check[(sizeof(struct DupFittingWork) == 0x18F0) ? 1 : -1];

/* The owning screen object: work->parent. */
struct DupFittingOwner {
    unsigned char pad_0[4];
    void          *outfitTable;  /* 0x4 table of owned outfits */
    void          *saveData;     /* 0x8 MUSICAL_SAVE data block */
};

/* The table pointed at by DupFittingOwner.outfitTable. */
struct DupFittingOutfitTable {
    unsigned char pad_0[4];
    void          *monSpecies;   /* 0x4 species the outfit belongs to */
};

/* Head of a singly linked element list. */
struct DupFittingItemList {
    unsigned short heapId;       /* 0x0 */
    unsigned char  pad_2[2];
    unsigned short count;        /* 0x4 elements in the list */
    unsigned short max;          /* 0x6 capacity */
    void          *head;         /* 0x8 first element */
    void          *tail;         /* 0xC last element */
};

/* One element of a DupFittingItemList. */
struct DupFittingItemElem {
    unsigned char  pad_0[4];
    void          *data;         /* 0x4 item descriptor */
    unsigned int   sprite;       /* 0x8 copied sprite */
    void          *renderElem;   /* 0xC MCSS render element */
    int            posX;         /* 0x10 */
    int            posY;         /* 0x14 */
    unsigned int   f18;          /* 0x18 */
    unsigned short f1C;          /* 0x1C */
    unsigned char  pad_1E[2];
    unsigned int   f20;          /* 0x20 */
    unsigned char  pad_24[8];
    unsigned int   f2C;          /* 0x2C */
    void          *next;         /* 0x30 next element */
};

/* Item descriptor pointed at by DupFittingItemElem.data. */
struct DupFittingItemData {
    unsigned short id;           /* 0x0 item id */
    unsigned char  pad_2[2];
    unsigned int   f4;           /* 0x4 image parameter */
    int            f8;           /* 0x8 image parameter */
    int            fC;           /* 0xC worn flag */
};

/* MCSS render element returned by MUSICAL_MCSS_GetRenderElem. */
struct DupFittingRenderElem {
    int            f0;           /* 0x0 */
    int            f4;           /* 0x4 x */
    int            f8;           /* 0x8 y */
    unsigned char  pad_C[4];
    int            f10;          /* 0x10 offset x */
    int            f14;          /* 0x14 offset y */
    unsigned char  pad_18[0x36 - 0x18];
    unsigned short f36;          /* 0x36 base rotation */
};

/* One per-frame record inside DupFittingWork. */
struct DupFittingFrame {
    unsigned short f0;           /* 0x0 */
    unsigned char  pad_2[0xE];
    int            f10;          /* 0x10 owned flag */
};


struct Object;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { u32 x,y; } DupFittingPairU32;

typedef struct {int x,y;} DupFittingPair;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;

#endif
