#ifndef LOCAL_TVT_SYS_SHARED_TYPES_H
#define LOCAL_TVT_SYS_SHARED_TYPES_H

struct Obj;

struct Cfg;

struct Sub0200852CObj;

struct Actor;

struct MsgBank;

struct Descriptor;

struct PrintSys;

struct U16Vec;

struct WordSet;

struct CharBuf;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct { u8 x, y; } LocalTvtTilePos;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad00[0x0C];
    unsigned char state;
    unsigned char pad0D[0x34 - 0x0D];
    int pending;
    unsigned char pad38[0x40 - 0x38];
    unsigned char *steps;
    unsigned char pad44[0x89 - 0x44];
    unsigned char stepIdx;
};

typedef unsigned int u32;

/* One entry of the menu step table pointed at by LocalTvtSys.stepTable. */
struct StepEntry {
    unsigned char stepId;      /* 0x00 read by LOCAL_TVT_SYS_RunStep */
    unsigned char charaIndex;  /* 0x01 chara this step positions */
    unsigned short messageId;  /* 0x02 passed to LOCAL_TVT_SYS_PrintMessage */
};

/* The 8-byte game-mode record LocalTvtSys.modeData points at, created by
 * func_02030734 in LOCAL_TVT_SYS_ProcInit. */
struct LocalTvtSysMode {
    unsigned short mode;       /* 0x00 1, or 5 when the Select key is held */
    unsigned char pad_02[2];   /* 0x02 */
    void *gameData;            /* 0x04 GAME_DATA_Create result */
};

/* The 0x8C-byte LOCAL_TVT_SYS work object allocated by PROCSYS_AllocProcWork in
 * LOCAL_TVT_SYS_ProcInit. Fields the original views read as both a 32-bit integer
 * and a pointer keep both types in a union. Canonical owner of the record used by
 * both local_tvt_sys.c and local_tvt_chara.c. */
struct LocalTvtSys {
    unsigned short heapId;                 /* 0x00 heap id, 0x55 */
    unsigned char pad_02[2];               /* 0x02 */
    void *vblankTask;                      /* 0x04 func_020056A0 task */
    int charaCount;                        /* 0x08 2 or 4 */
    unsigned char state;                   /* 0x0C main state machine */
    unsigned char highBase;                /* 0x0D 0 selects the low VRAM/palette base set, 1 the high */
    unsigned char frameTimer;              /* 0x0E frames since the last toggle, capped at 20 */
    unsigned char pad_0F[1];               /* 0x0F */
    int timeSlot;                          /* 0x10 0, 1 or 2 from the clock */
    int charaCursor;                       /* 0x14 chara selection step */
    void *arcHandle;                       /* 0x18 archive handle */
    void *chara[4];                        /* 0x1C..0x2B LOCAL_TVT_CHARA objects */
    union { int asInt; void *ptr; } activeChara;  /* 0x2C active chara, or 0 */
    void *modeData;                        /* 0x30 struct LocalTvtSysMode */
    int pending;                           /* 0x34 step restart flag */
    void *menuHandle;                      /* 0x38 loaded menu data, freed by func_020307B0 */
    void *menuCharaTable;                       /* 0x3C menu data */
    union { unsigned char *bytes; struct StepEntry *entries; } stepTable; /* 0x40 */
    union { unsigned int value; void *ptr; } palette;    /* 0x44 CLACT palette */
    union { unsigned int value; void *ptr; } character;  /* 0x48 CLACT character */
    union { unsigned int value; void *ptr; } cellAnim;   /* 0x4C CLACT cell anim */
    union { unsigned int value; void *ptr; } unit;       /* 0x50 CLACT unit */
    void *actor;                           /* 0x54 CLACT actor */
    union { unsigned int value; void *ptr; } textCtl;    /* 0x58 TCBL handle */
    union { unsigned int value; void *ptr; } window;     /* 0x5C BMP window */
    union { unsigned int value; void *ptr; } font;       /* 0x60 GF_FONT */
    union { unsigned int value; void *ptr; } printStream;/* 0x64 print stream */
    union { unsigned int value; void *ptr; } msgBankA;   /* 0x68 message bank */
    union { unsigned int value; void *ptr; } msgBankB;   /* 0x6C message bank */
    union { unsigned int value; void *ptr; } textBuf;    /* 0x70 text buffer */
    union { unsigned int value; void *ptr; } wordSet;    /* 0x74 word set */
    union { unsigned int value; void *ptr; } printQueue; /* 0x78 print queue */
    union { unsigned int value; void *ptr; } keyCursor;  /* 0x7C key cursor */
    unsigned char printCtrl[8];            /* 0x80..0x87 PRINTSYS control block */
    unsigned char charaIndex;              /* 0x88 selected chara index */
    unsigned char stepIndex;               /* 0x89 current step index */
    unsigned short timer;                  /* 0x8A message timer */
};

typedef char LocalTvtSysSizeCheck[(sizeof(struct LocalTvtSys) == 0x8C) ? 1 : -1];

#endif
