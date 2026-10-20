#ifndef GAME_ARM9_BMP_MENU_TYPES_H
#define GAME_ARM9_BMP_MENU_TYPES_H

#include "../types.h"
#include "../arm9/bmp_menuwork_shared_types.h"

struct BmpWin;

/* Print state of one window: the window and a flag set after an item was printed. */
typedef struct PrintUtil {
    struct BmpWin *win;     /* +0x00 */
    u8    transReq;         /* +0x04  1: transfer once the print queue is done */
} PrintUtil;

/* Where a menu window goes: BG layer, tile position, palette and first character. */
typedef struct WinDat {
    u8  bgFrame;            /* +0x00 */
    u8  x;                  /* +0x01 */
    u8  y;                  /* +0x02 */
    u8  palette;            /* +0x03 */
    u16 charBase;           /* +0x04  callers pass it as base */
} WinDat;


struct BmpCursor;

struct GfFont;

typedef struct BmpMenuHeader {
    BmpMenuWork *items;     /* +0x00 */
    struct BmpWin *win;     /* +0x04 */
    u8   fontId;            /* +0x08 */
    u8   numColumns;        /* +0x09 */
    u8   itemsPerColumn;    /* +0x0A */
    u8   lineSpacing : 4;   /* +0x0B */
    u8   cursorMode  : 2;   /* 1 = no cursor drawn */
    u8   wrap        : 2;   /* nonzero = cursor wraps at the ends */
    u16  xPad;              /* +0x0C */
    u16  lineHeight;        /* +0x0E */
    u32  reserved10;        /* +0x10  zero, never read */
    PrintUtil *util;        /* +0x14 */
    void *que;              /* +0x18  print queue */
    struct GfFont *fontH;   /* +0x1C */
    u32  committed;         /* +0x20  window committed to VRAM */
} BmpMenuHeader;

typedef struct BmpMenu {
    BmpMenuHeader header;   /* +0x00 */
    struct BmpCursor *cursor; /* +0x24 */
    u32 cancelMask;         /* +0x28 */
    u8  reserved2C;
    u8  selected;           /* +0x2D */
    u8  colWidth;           /* +0x2E */
    u8  originX;            /* +0x2F */
    u8  originY;            /* +0x30 */
    u8  xPad;               /* +0x31 */
    u8  lineHeight;         /* +0x32 */
    u8  movedDir;           /* +0x33  direction accepted this frame, 1..4 */
    u16 heapId;             /* +0x34 */
    u16 reserved36;
} BmpMenu;

#endif
