#ifndef MYSTERY_UTIL_SHARED_TYPES_H
#define MYSTERY_UTIL_SHARED_TYPES_H

#include "mystery_net_types.h"

/* One entry of the descriptor table read by MYSTERY_UTIL_CreateWindowList / MYSTERY_UTIL_DrawBmpList. */
typedef struct MysteryUtilMenuEntry {
    union {
        unsigned int flags;     /* 0x00 read as a u32 by MYSTERY_UTIL_DrawBmpList */
        unsigned char bytes[4]; /* 0x00 four u8 BMP parameters by MYSTERY_UTIL_CreateWindowList */
    } u0;
    int messageId;              /* 0x04 MSGDATA_ReadString index */
    union {
        int stringId;           /* 0x08 STRBUF source id */
        void *stringPtr;        /* 0x08 STRBUF handle (album view descriptor) */
    } str;
    int layoutMode;             /* 0x0C mode for MYSTERY_UTIL_AlignText */
    short posX;                 /* 0x10 */
    short posY;                 /* 0x12 */
    unsigned short color;       /* 0x14 palette slot */
} MysteryUtilMenuEntry;

/* Read-only menu definition passed to MYSTERY_UTIL_CreateMenu. */
typedef struct MysteryUtilMenuDef {
    unsigned int menuTable;    /* 0x00 */
    unsigned int messageTable;    /* 0x04 */
    unsigned int printOwner;    /* 0x08 */
    unsigned int menuItems[3]; /* 0x0C message ids passed to BMP_MENUWORK_AddMsgItem */
    unsigned int count;     /* 0x18 number of message items */
    unsigned short bgLayer; /* 0x1C */
    unsigned short palette; /* 0x1E */
    unsigned short windowX; /* 0x20 */
    unsigned short windowY; /* 0x22 */
} MysteryUtilMenuDef;

struct Bmp;

struct Ctx;

struct Vec2;

typedef signed int     s32;

typedef signed short s16;

typedef unsigned long long u64;

/* 2D position in pixels (MYSTERY_UTIL_AlignText, CLACT actor surface). */
typedef struct {s16 x,y;} MysteryUtilVec2;

struct Ctx {
    u32 mode;
    u32 reserved04;
    u32 clactUnit;
    u32 cardList;
    u32 font;
    u32 printQueue;
    u32 wordSet;
    u32 msgBank;
    u32 gameData;
};

#endif
