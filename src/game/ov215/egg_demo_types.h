#ifndef EGG_DEMO_TYPES_H
#define EGG_DEMO_TYPES_H

/* Owner header for the ov215 egg demo work structures.
 * One real struct per object: the process work and the process arguments. */

/* Arguments handed to the egg demo process: the game data and the hatched mon. */
struct EggDemoArgs {
    void *gameData;              /* 0x00 */
    void *mon;                   /* 0x04 */
};

/* The egg demo process work, 140 bytes, allocated by EGG_DEMO_MAIN_Create.
 * The menu state shares this block from 0x50 onward. */
struct EggDemoWork {
    unsigned short heapId;       /* 0x00 */
    unsigned char pad2[2];       /* 0x02 */
    void *graphic;               /* 0x04 EGG_DEMO_GRAPHIC work */
    void *font;                  /* 0x08 GF_FONT handle */
    unsigned int printQue;       /* 0x0C print queue */
    int state;                   /* 0x10 process step */
    unsigned char fadeDelay;     /* 0x14 frames left before the fade out */
    unsigned char pad15[3];      /* 0x15 */
    int bgmState;                /* 0x18 BGM state machine step */
    int bgmTimer;                /* 0x1C zeroed at init, never read here */
    int dialogState;             /* 0x20 yes/no dialog state (0 none, 1 open, 2 done) */
    int bgmLoadState;            /* 0x24 GFL_USE_StepBgmLoad state word */
    void *vblankTask;            /* 0x28 vblank handler task */
    unsigned int charId;         /* 0x2C CLACT character id */
    unsigned int paletteId;      /* 0x30 CLACT palette id */
    unsigned int cellAnimId;     /* 0x34 CLACT cell animation id */
    void *actors[6];             /* 0x38 CLACT actors */
    void *printStream;           /* 0x50 menu print stream */
    void *tcbl;                  /* 0x54 menu text control block */
    void *window;                /* 0x58 menu frame window */
    void *windowSub;             /* 0x5C menu fill window */
    unsigned int frameGfx;       /* 0x60 menu frame graphics */
    void *msgBank;               /* 0x64 menu message bank */
    void *textBuf;               /* 0x68 menu text buffer */
    unsigned int vblankFlag;     /* 0x6C set on vblank, cleared by OnVBlank */
    unsigned char winDat[4];     /* 0x70 dialog window descriptor */
    unsigned short bgLayerId;    /* 0x74 dialog BG layer run id */
    unsigned char pad76[2];      /* 0x76 */
    void *bmpMenu;               /* 0x78 yes/no dialog */
    int dialogResult;            /* 0x7C dialog result */
    void *view;                  /* 0x80 EGG_DEMO_VIEW work */
    int *nameChild;              /* 0x84 NAMEIN_SETUP arguments */
    unsigned int proc;           /* 0x88 process created for the name entry */
};

struct Node;

#include "../types.h"

#endif
