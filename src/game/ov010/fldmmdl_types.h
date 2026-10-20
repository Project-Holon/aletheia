#ifndef ALETHEIA_OV010_FLDMMDL_TYPES_H
#define ALETHEIA_OV010_FLDMMDL_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"

/*
 * Field model (MMDL) system and field model layouts, built by offset from
 * every view in fldmmdl.c. The system is a 0x48-byte block (fldmmdl.c line
 * 0xC3 allocation); it owns an array of 0x100-byte models (line 0xC4
 * allocation, maxCount << 8) and a 0x310-byte object code parameter cache.
 */

typedef struct MmdlSys MmdlSys;
typedef struct Mmdl Mmdl;

/* Grid position in a field model header (MmdlHeader.pos when posType is 0). */
typedef struct MmdlHeaderGridPos {
    unsigned short gridX; /* 0x1C */
    unsigned short gridZ; /* 0x1E */
    int posY; /* 0x20 */
} MmdlHeaderGridPos;

/* Current grid position of a field model, as copied out by FLDMMDL_GetGridNowPos. */
typedef struct MmdlGridVec {
    s16 x;
    s16 y;
    s16 z;
} MmdlGridVec;

/* Object code parameter record (0x1C bytes), one per object code. */
typedef struct MmdlObjCodeParam {
    unsigned short code;        /* 0x00 */
    unsigned char drawType;     /* 0x02 */
    unsigned char drawProcNo;   /* 0x03 */
    unsigned char shadowSize;   /* 0x04 */
    unsigned char footMarkType; /* 0x05 */
    unsigned char reflectType;  /* 0x06 */
    unsigned char mdlSize;      /* 0x07 */
    unsigned char texSize;      /* 0x08 */
    unsigned char animId;       /* 0x09 */
    unsigned char sex;          /* 0x0A */
    unsigned char sizeWidth;    /* 0x0B */
    unsigned char sizeDepth;    /* 0x0C */
    signed char offsetX;        /* 0x0D */
    signed char offsetY;        /* 0x0E */
    signed char offsetZ;        /* 0x0F */
    unsigned char resource[12]; /* 0x10 */
} MmdlObjCodeParam;

/* Placement record of one field model in the zone event data (0x24 bytes). */
typedef struct MmdlHeader {
    unsigned short objId;       /* 0x00 */
    unsigned short objCode;     /* 0x02 */
    unsigned short moveCode;    /* 0x04 */
    unsigned short eventType;   /* 0x06 */
    unsigned short eventFlag;   /* 0x08 */
    unsigned short eventId;     /* 0x0A */
    unsigned short dirHeader;   /* 0x0C */
    unsigned short param0;      /* 0x0E */
    unsigned short param1;      /* 0x10 */
    unsigned short param2;      /* 0x12 */
    short moveLimitX;           /* 0x14 */
    short moveLimitZ;           /* 0x16 */
    int posType;                /* 0x18: 0 grid, else rail */
    unsigned short pos[4];      /* 0x1C */
} MmdlHeader;

/* Move procedure table selected by the move code. */
typedef struct MmdlMoveProcList {
    unsigned int moveCode;
    void (*init)(Mmdl *mmdl);
    void (*move)(Mmdl *mmdl);
    void (*remove)(Mmdl *mmdl);
    void (*recover)(Mmdl *mmdl);
} MmdlMoveProcList;

/* Draw procedure table selected by the object code's draw procedure. */
typedef struct MmdlDrawProcList {
    void (*init)(Mmdl *mmdl);
    void (*draw)(Mmdl *mmdl);
    void (*remove)(Mmdl *mmdl);
    void (*push)(Mmdl *mmdl);
    void (*pop)(Mmdl *mmdl);
    int (*getParam)(Mmdl *mmdl, unsigned int kind);
} MmdlDrawProcList;

struct MmdlSys {
    unsigned int statusBit;     /* 0x00 */
    unsigned short mmdlMax;     /* 0x04 */
    short mmdlCount;            /* 0x06 */
    unsigned short sysHeapId;   /* 0x08 */
    unsigned short heapId;      /* 0x0A */
    unsigned short tcbPriority; /* 0x0C */
    unsigned char pad_0E[2];
    void *resArcHandle;         /* 0x10: archive 0x31 */
    void *objCodeArcHandle;     /* 0x14: archive 0x30, 0x1C-byte records */
    Mmdl *mmdlBuf;              /* 0x18 */
    void *tcbSysWork;           /* 0x1C */
    void *tcbSys;               /* 0x20 */
    void *blActCont;            /* 0x24 */
    void *g3dObjCont;           /* 0x28 */
    void *saveData;             /* 0x2C */
    void *gameData;             /* 0x30 */
    void *g3dMapper;            /* 0x34 */
    void *nogridMapper;         /* 0x38 */
    void *fieldMap;             /* 0x3C */
    const unsigned short *areaIdRef; /* 0x40 */
    unsigned short *objCodeParamCache; /* 0x44: 0x310 bytes */
};

struct Mmdl {
    unsigned int statusBit;     /* 0x00 */
    unsigned int moveBit;       /* 0x04 */
    unsigned short objId;       /* 0x08 */
    unsigned short zoneId;      /* 0x0A */
    unsigned short objCode;     /* 0x0C */
    unsigned short moveCode;    /* 0x0E */
    unsigned short eventType;   /* 0x10 */
    unsigned short eventFlag;   /* 0x12 */
    unsigned short eventId;     /* 0x14 */
    unsigned short dirHeader;   /* 0x16 */
    unsigned short dirDisp;     /* 0x18 */
    unsigned short dirMove;     /* 0x1A */
    unsigned short dirDispOld;  /* 0x1C */
    unsigned short dirMoveOld;  /* 0x1E */
    unsigned short param0;      /* 0x20 */
    unsigned short param1;      /* 0x22 */
    unsigned short param2;      /* 0x24 */
    unsigned short acmdCode;    /* 0x26 */
    unsigned short acmdSeq;     /* 0x28 */
    unsigned short drawStatus;  /* 0x2A */
    short moveLimitX;           /* 0x2C */
    short moveLimitZ;           /* 0x2E */
    short gridInitX;            /* 0x30 */
    short gridInitY;            /* 0x32 */
    short gridInitZ;            /* 0x34 */
    short gridOldX;             /* 0x36 */
    short gridOldY;             /* 0x38 */
    short gridOldZ;             /* 0x3A */
    short gridNowX;             /* 0x3C */
    short gridNowY;             /* 0x3E */
    short gridNowZ;             /* 0x40 */
    unsigned char pad_42[2];
    VecFx32 pos;                /* 0x44 */
    VecFx32 drawOffset;         /* 0x50 */
    VecFx32 drawOffsetOutside;  /* 0x5C */
    VecFx32 attrOffset;         /* 0x68 */
    unsigned int nowAttr;       /* 0x74 */
    unsigned int oldAttr;       /* 0x78 */
    unsigned char sizeWidth;    /* 0x7C */
    unsigned char sizeDepth;    /* 0x7D */
    signed char offsetX;        /* 0x7E */
    signed char offsetY;        /* 0x7F */
    signed char offsetZ;        /* 0x80 */
    unsigned char pad_81[3];
    void *moveTcb;              /* 0x84: move task */
    MmdlSys *mmdlSys;           /* 0x88 */
    const MmdlMoveProcList *moveProcList; /* 0x8C */
    const MmdlDrawProcList *drawProcList; /* 0x90 */
    unsigned char moveProcWork[0x10];     /* 0x94 */
    unsigned char moveSubProcWork[0x10];  /* 0xA4 */
    unsigned char moveCmdWork[0x10];      /* 0xB4 */
    unsigned char drawProcWork[0x20];     /* 0xC4 */
    MmdlObjCodeParam objCodeParam;        /* 0xE4 */
};

/* Mmdl.statusBit flags (meaning from the users in ov010 and ov021). */
#define MMDL_STABIT_USE              0x0001
#define MMDL_STABIT_MOVE_INIT        0x0002 /* move procedure set up */
#define MMDL_STABIT_VANISH           0x0004
#define MMDL_STABIT_PAUSE_DIR        0x0008
#define MMDL_STABIT_ZONE_DEL_OFF     0x0020 /* kept on zone change */
#define MMDL_STABIT_FELLOW_HIT_OFF   0x0080
#define MMDL_STABIT_HEIGHT_GET_OFF   0x0200
#define MMDL_STABIT_ATTR_GET_OFF     0x0400
#define MMDL_STABIT_ALIAS            0x0800 /* header event id 0xFFFF */
#define MMDL_STABIT_ATTR_OFFSET_OFF  0x1000
#define MMDL_STABIT_RAIL_MOVE        0x2000

/* Mmdl.moveBit flags. */
#define MMDL_MOVEBIT_MOVE_PUSH       0x000001 /* move procedure pushed */
#define MMDL_MOVEBIT_DRAW_INIT_COMP  0x000002
#define MMDL_MOVEBIT_DRAW_PUSH       0x000004
#define MMDL_MOVEBIT_MOVE_PAUSE      0x000008
#define MMDL_MOVEBIT_MOVE            0x000010
#define MMDL_MOVEBIT_MOVE_START      0x000020
#define MMDL_MOVEBIT_MOVE_END        0x000040
#define MMDL_MOVEBIT_JUMP_START      0x000080
#define MMDL_MOVEBIT_JUMP_END        0x000100
#define MMDL_MOVEBIT_ACMD            0x000200
#define MMDL_MOVEBIT_ACMD_END        0x000400
#define MMDL_MOVEBIT_ATTR_GET_ERROR  0x000800
#define MMDL_MOVEBIT_HEIGHT_GET_ERROR 0x001000
#define MMDL_MOVEBIT_SHADOW_SET      0x004000
#define MMDL_MOVEBIT_SHOAL_SET       0x008000 /* cleared with the other effect-set bits */
#define MMDL_MOVEBIT_REFLECT_SET     0x020000
#define MMDL_MOVEBIT_SPLASH_SET      0x040000
#define MMDL_MOVEBIT_SYS_PAUSE_OFF   0x080000
#define MMDL_MOVEBIT_ATTR_EFFECT_OFF 0x100000
#define MMDL_MOVEBIT_SHADOW_VANISH   0x200000

/* MmdlSys.statusBit flags. */
#define MMDLSYS_STABIT_DRAW_INIT     0x0001
#define MMDLSYS_STABIT_DRAW_OFF      0x0008
#define MMDLSYS_STABIT_MOVE_INIT     0x0010
#define MMDLSYS_STABIT_MOVE_PAUSE    0x0020

/* Identity of one field model, saved and compared by callers. */
typedef struct MmdlCheckInfo {
    unsigned short objId;   /* 0x00 */
    unsigned short objCode; /* 0x02 */
    unsigned short zoneId;  /* 0x04 */
} MmdlCheckInfo;

#endif
