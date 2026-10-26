#ifndef MYSTERY_UTIL_SHARED_TYPES_H
#define MYSTERY_UTIL_SHARED_TYPES_H

#include "../ov121/mystery_net_types.h"

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
    struct MsgBank *menuTable;    /* 0x00 */
    struct GfFont *messageTable;    /* 0x04 */
    struct PrintQueue *printOwner;    /* 0x08 */
    unsigned int menuItems[3]; /* 0x0C message ids passed to BMP_MENUWORK_AddMsgItem */
    unsigned int count;     /* 0x18 number of message items */
    unsigned short bgLayer; /* 0x1C */
    unsigned short palette; /* 0x1E */
    unsigned short windowX; /* 0x20 */
    unsigned short windowY; /* 0x22 */
} MysteryUtilMenuDef;

/* Current palette and the two palettes it is blended between (0x60 bytes), used by the album icons and the clact actors. */
typedef struct MysteryUtilBlendPalettes {
    unsigned short current[16];
    unsigned short blendFrom[16];
    unsigned short blendTo[16];
} MysteryUtilBlendPalettes;

/* Input record for MYSTERY_UTIL_CreateDetailWindow (0x40 bytes on the DS). */
struct MysteryUtilDetailDef {
    struct MsgBank *bank;          /* 0x00 message bank, or 0 when ids hold STRBUF handles */
    struct GfFont *font;           /* 0x04 */
    struct PrintQueue *printQueue; /* 0x08 */
    struct ClactActor *actor;      /* 0x0C cursor actor */
    union {
        unsigned int id;           /* message id (bank set) */
        struct Strbuf *str;        /* STRBUF to clone (bank clear) */
    } ids[4];                      /* 0x10 */
    unsigned int count;            /* 0x20 number of entries */
    unsigned short bgLayer;        /* 0x24 */
    unsigned short windowPalette;  /* 0x26 */
    unsigned short windowPalette2; /* 0x28 */
    unsigned short paletteBank;    /* 0x2A */
    short rowOffset;               /* 0x2C */
    short colOffset;               /* 0x2E */
    unsigned short animSeq;        /* 0x30 */
    unsigned short pad32;          /* 0x32 */
    void (*callback)(void *);      /* 0x34 */
    void *callbackArg;             /* 0x38 */
    unsigned int *outIndex;        /* 0x3C written back on a selection change */
};

struct Bmp;

struct Vec2;

#include "../types.h"

/* 2D position in pixels (MYSTERY_UTIL_AlignText, CLACT actor surface). */
typedef struct {s16 x,y;} MysteryUtilVec2;


#endif
