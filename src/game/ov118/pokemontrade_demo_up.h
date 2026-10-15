/*
 * pokemontrade_demo_up.h: the work object shared by the pokemontrade demo
 * files of ov117 and ov118 (pokemontrade_demo_common.c, pokemontrade_ircdemo.c
 * in ov117; pokemontrade_demo_common.c, pokemontrade_demo_middle.c and
 * pokemontrade_demo_up.c in ov118). One struct per object, fields by offset.
 */
#ifndef POKEMONTRADE_DEMO_UP_H
#define POKEMONTRADE_DEMO_UP_H

typedef struct {
    int x, y, z;
} Vec;

/* Animation work block (0xBC bytes) reached through the demo work's animWork
 * pointer at 0xC. It holds the particle ids, the slot-3 transform, the CLACT
 * actor handle and the heap id used to build the block. */
typedef struct PokeTradeAnimWork {
    unsigned int   particleId[6];        /* 0x00 */
    unsigned char  pad_18[0x48 - 0x18];
    Vec            position;             /* 0x48 */
    Vec            scale;                /* 0x54 */
    unsigned char  pad_60[0xB0 - 0x60];
    void          *actor;                /* 0xB0 */
    unsigned char  pad_B4[0xBA - 0xB4];
    unsigned short heapId;               /* 0xBA */
} PokeTradeAnimWork;

/* Work area of the pokemontrade demo scene. */
typedef struct PokeTradeDemoWork {
    unsigned char       pad_0[0xC];
    void               *animWork;        /* 0x00C */
    unsigned char       pad_10[0x5F4 - 0x10];
    unsigned short      heapId;          /* 0x5F4 */
    unsigned char       pad_5F6[0x720 - 0x5F6];
    void               *msgBank;         /* 0x720 */
    void               *wordSet;         /* 0x724 */
    unsigned char       pad_728[0x738 - 0x728];
    unsigned int        stringDst;       /* 0x738 */
    unsigned int        stringSrc;       /* 0x73C */
    unsigned char       pad_740[0x818 - 0x740];
    signed char        *fade;            /* 0x818 */
    unsigned char       pad_81C[0x830 - 0x81C];
    unsigned int        ownMonKey;       /* 0x830 */
    unsigned int        enemyMonKey;     /* 0x834 */
    unsigned char       pad_838[0x844 - 0x838];
    void               *mcssObj[4];      /* 0x844 */
    unsigned int        sceneStarted;    /* 0x854 */
    unsigned char       pad_858[4];
    void               *slideOwn;        /* 0x85C */
    void               *slidePeer;       /* 0x860 */
    void               *slideExtra;      /* 0x864 */
    void               *slidePtr;        /* 0x868 */
    unsigned char       pad_86C[0x88C - 0x86C];
    unsigned int        paletteHandle;   /* 0x88C */
    unsigned char       pad_890[0x8A8 - 0x890];
    unsigned int        characterHandle; /* 0x8A8 */
    unsigned char       pad_8AC[0x8BC - 0x8AC];
    unsigned int        cellAnimHandle;  /* 0x8BC */
    unsigned char       pad_8C0[0x9C4 - 0x8C0];
    int                 clactSystem;     /* 0x9C4 */
    unsigned char       pad_9C8[0xF2C - 0x9C8];
    int                 frame;           /* 0xF2C */
    unsigned char       pad_F30[0x1094 - 0xF30];
    unsigned int        finishFlag;      /* 0x1094 */
    unsigned char       pad_1098[0x118C - 0x1098];
    unsigned int        sceneMode;       /* 0x118C */
    unsigned char       pad_1190[0x11ED - 0x1190];
    unsigned char       enemySameMon;    /* 0x11ED */
    unsigned char       ownSameMon;      /* 0x11EE */
    unsigned char       enemySpecialMon; /* 0x11EF */
    unsigned char       ownSpecialMon;   /* 0x11F0 */
} PokeTradeDemoWork;

#endif
