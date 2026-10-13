#ifndef P_STATUS_TYPES_H
#define P_STATUS_TYPES_H

/*
 * Pokemon status screen (ov131): the caller's parameter block, the screen
 * work, and the types that more than one file of the screen uses
 * (p_status.c, p_sta_sub.c, p_sta_info.c, p_sta_skill.c, p_sta_ribbon.c,
 * p_sta_oam.c). Each sub-screen work struct is defined in its own file.
 */

struct Actor;
struct Bmp;

/* Work of each sub-screen; the layout is private to the file named. */
typedef struct PStaSubWork PStaSubWork;       /* p_sta_sub.c: Pokemon sprite, marks, petting */
typedef struct PStaInfoWork PStaInfoWork;     /* p_sta_info.c: page 0 */
typedef struct PStaSkillWork PStaSkillWork;   /* p_sta_skill.c: pages 1 and 3 */
typedef struct PStaRibbonWork PStaRibbonWork; /* p_sta_ribbon.c: page 2 */

/* Start of a palette or screen file loaded from the status archive: 12 bytes of header, then the data. */
typedef struct StaGraphicsFile {
    unsigned char pad_0[8];
    unsigned int dataSize;      /* 0x08: size of the data */
    unsigned char data[1];      /* 0x0C */
} StaGraphicsFile;

/* 36-byte sprite resource record: CLACT_GetCharacterProxy fills it, CLACT_SetActorImageProxy gives it to an actor. */
typedef struct StaSpriteRes {
    unsigned int word[9];
} StaSpriteRes;

/* Offset passed to the actor move function func_0204B404. */
typedef struct StaOamPoint {
    short x, y;
} StaOamPoint;

/* Manager of the cell resources and the cell actor unit that the bitmap actors use (0x14 bytes). */
typedef struct StaOamManager {
    void *clunit;                       /* 0x00 */
    unsigned short heapId;              /* 0x04 */
    unsigned char pad_6[2];
    int cellRes[3];                     /* 0x08: cell resource id per OBJ tile mapping mode, -1 = not loaded */
} StaOamManager;

/* What a caller gives to build the actors of one bitmap (0x18 bytes). */
typedef struct StaOamBitmapDesc {
    struct Bmp *bmp;                    /* 0x00 */
    short x;                            /* 0x04 */
    short y;                            /* 0x06 */
    unsigned int plttRes;               /* 0x08 */
    unsigned int animSeq;               /* 0x0C */
    unsigned char drawPriority;         /* 0x10 */
    unsigned char bgPriority;           /* 0x11 */
    unsigned short space;               /* 0x12: main or sub OBJ space of the actors */
    unsigned int screen;                /* 0x14: 0 main, 1 sub */
} StaOamBitmapDesc;

/* Actors that show one bitmap: the bitmap is cut into cells of 64 by 32 pixels, one actor each (at most 3). */
typedef struct StaOamBitmapActors {
    struct Bmp *bmp;                    /* 0x00 */
    struct Actor *actor[3];             /* 0x04: row by row */
    unsigned int screen;                /* 0x10 */
    int charRes[3];                     /* 0x14 */
    unsigned short space;               /* 0x20 */
    unsigned char cols;                 /* 0x22 */
    unsigned char rows;                 /* 0x23 */
} StaOamBitmapActors;

/* Position record read by the cell actor creator func_0204B294. */
typedef struct StaOamActorPos {
    short x, y;
    unsigned short animSeq;
    unsigned char drawPriority, bgPriority;
} StaOamActorPos;

/* Touch hit rectangle in pixels. */
typedef struct StaTouchRect {
    unsigned char top, bottom, left, right;
} StaTouchRect;

/* Row of the ribbon table P_STA_RIBBON_InfoTable (16 bytes). */
typedef struct StaRibbonInfo {
    unsigned int paramId;               /* 0x00: Pokemon parameter that holds the ribbon */
    unsigned short fileId;              /* 0x04: character data file */
    unsigned short animSeq;             /* 0x06 */
    unsigned short nameMsg;             /* 0x08 */
    unsigned short descMsg;             /* 0x0A: description message */
    unsigned char selector;             /* 0x0C */
    unsigned char pad_D[3];
} StaRibbonInfo;

/* What the caller passes in (0x28 bytes, see P_STATUS_ProcInit). */
typedef struct PStatusParam {
    void *ppd;                  /* 0x00: one Pokemon, a party, or a Pokemon array (ppt) */
    void *callerData;           /* 0x04: kept for the caller (the field link stores the mail box here); the status screen does not read it */
    void *config;               /* 0x08: option flags; ids 7..9 hold the per-page toggles */
    unsigned char ppt;          /* 0x0C: kind of ppd: 0 one Pokemon, 1 party, 2 array */
    unsigned char mode;         /* 0x0D: 2 = choose a move to forget */
    unsigned char max;          /* 0x0E: number of Pokemon in ppd */
    unsigned char pos;          /* 0x0F: Pokemon shown first, and on return */
    unsigned char page;         /* 0x10: page shown first */
    unsigned char retMovePos;   /* 0x11: move slot picked in mode 2 */
    unsigned char retSel;       /* 0x12: how the screen closed: 1 B button, 2 X button */
    unsigned char pad_13[1];
    unsigned short newMove;     /* 0x14: move to learn in mode 2 */
    unsigned char pad_16[2];
    unsigned int isNationalDex; /* 0x18: 0 = show the regional dex number */
    unsigned char pad_1C[4];
    int canUseButtons;          /* 0x20: X and Y buttons are available */
    int forceExit;              /* 0x24: 1 = caller asks the screen to close */
} PStatusParam;

/* Index ranges of PStatusWork.objRes; P_STATUS_DeleteObjResource frees each range with its own call. */
enum {
    PSTATUS_RES_PLTT_START = 0,     /* palettes */
    PSTATUS_RES_PLTT_END = 11,
    PSTATUS_RES_CHR_START = 12,     /* character data */
    PSTATUS_RES_CHR_END = 24,
    PSTATUS_RES_CELL_START = 25,    /* cells and animations */
    PSTATUS_RES_CELL_END = 37,
    PSTATUS_RES_MAX = 38
};

#define PSTATUS_TYPE_MAX 17

typedef struct PStatusWork {
    unsigned short heapId;              /* 0x000 */
    unsigned char pad_2[2];
    void *vblankTask;                   /* 0x004 */
    PStatusParam *param;                /* 0x008 */
    int refreshReq;                     /* 0x00C: 1 = redraw the page and Pokemon */
    int playCryReq;                     /* 0x010 */
    int restoreModeAll;                 /* 0x014: param mode was 3, turned into 2 until exit */
    unsigned short pos;                 /* 0x018: Pokemon shown */
    unsigned char dispPos;              /* 0x01A: Pokemon drawn on the sub screen, 255 = none */
    unsigned char vblankCount;          /* 0x01B */
    unsigned char inputType;            /* 0x01C: 0 keys, 1 touch */
    unsigned char pad_1D[3];
    unsigned int lastTick;              /* 0x020 */
    int tpHit;                          /* 0x024: touched button */
    unsigned int tpX;                   /* 0x028 */
    unsigned int tpY;                   /* 0x02C */
    unsigned int prevTpX;               /* 0x030 */
    unsigned int prevTpY;               /* 0x034 */
    unsigned int isEgg;                 /* 0x038 */
    unsigned int friendship;            /* 0x03C */
    int hasRibbon;                      /* 0x040 */
    int isInputEnabled;                 /* 0x044 */
    int prevButtonAnim;                 /* 0x048 */
    int nextButtonAnim;                 /* 0x04C */
    int seq;                            /* 0x050 */
    int retCode;                        /* 0x054 */
    int page;                           /* 0x058 */
    unsigned int dispPage;              /* 0x05C */
    int pageToggle[3];                  /* 0x060: Y button state per page */
    unsigned char pad_6C[4];
    void *camera;                       /* 0x070 */
    unsigned char pad_74[4];
    void *mcssSys;                      /* 0x078 */
    void *msgData;                      /* 0x07C */
    void *font;                         /* 0x080 */
    void *printQue;                     /* 0x084 */
    PStaSubWork *subWork;               /* 0x088 */
    PStaInfoWork *infoWork;             /* 0x08C: page 0 */
    PStaSkillWork *skillWork;           /* 0x090: pages 1 and 3 */
    PStaRibbonWork *ribbonWork;         /* 0x094: page 2 */
    unsigned int objRes[PSTATUS_RES_MAX];       /* 0x098 */
    unsigned int typeChrRes[PSTATUS_TYPE_MAX];  /* 0x130 */
    void *clunit;                       /* 0x174 */
    void *buttonActor[8];               /* 0x178: page tabs 0..2, Y 3, up 4, down 5, X 6, B 7 */
    void *typeIconActor[2];             /* 0x198 */
    void *pushedButton;                 /* 0x1A0: button whose press animation ends the screen */
    unsigned short blinkAngle;          /* 0x1A4 */
    unsigned short savedCursorPal[4];   /* 0x1A6 */
    unsigned short cursorPal[4];        /* 0x1AE */
    unsigned short glowPalBase[16];     /* 0x1B6 */
    unsigned short glowPalTarget[16];   /* 0x1D6 */
    unsigned short glowPal[16];         /* 0x1F6 */
    unsigned short markPal[16];         /* 0x216 */
    unsigned short markPalBase[16];     /* 0x236 */
    unsigned char pad_256[2];
    void *tempPP;                       /* 0x258: full Pokemon built from an array entry */
    unsigned int mosaicSeq;             /* 0x25C */
    unsigned char mosaicLevel;          /* 0x260 */
} PStatusWork;

#endif
