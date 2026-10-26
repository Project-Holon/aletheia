#ifndef FIELD_MSGBG_TYPES_H
#define FIELD_MSGBG_TYPES_H

/*
 * Field message windows (field_msgbg.c): the message BG system, its print
 * slots and the window kinds built on it (message, menu, system, talk
 * balloon, plain, sub, BG and frame windows).
 */

#include "../types.h"
#include "../arm9/bmp_menuwork_shared_types.h"
#include "../arm9/nns_g2d_res_types.h"
#include "../arm9/bmp_menu_types.h"

struct BmpWin;
struct Bmp;
struct Strbuf;
struct MsgBank;
struct PrintQue;
struct TextPrinter;
struct GfFont;
struct Tcbl;
struct BmpMenuList;
struct TalkMsgWinSys;
struct G3dCamera;
struct FieldMsgBg;

#include "../sdk_fx.h"

/* Blinking "more text" cursor at the bottom right of a window (8 bytes). */
typedef struct FieldMsgCursor {
    u8 isDrawn;                   /* 0x00 */
    u8 animFrame;                 /* 0x01, index into the y offset table (0..2) */
    u8 animWait;                  /* 0x02, frames on the current animFrame (0..3) */
    struct Bmp *bmp;              /* 0x04, 8x8 cursor image */
} FieldMsgCursor;

/* Key control of streamed messages (4 bytes, FieldMsgBg+0x160). */
typedef struct FieldMsgKeyWait {
    u8 autoMode;                  /* 0x00, 1: no key wait and no cursor */
    u8 waitState;                 /* 0x01 */
    u8 skipHeld;                  /* 0x02, A or B held since the stream started */
    u8 reserved;                  /* 0x03 */
} FieldMsgKeyWait;

/* One print slot of the message BG system (0x24 bytes). */
typedef struct FieldMsgPrint {
    struct FieldMsgBg *msgBg;     /* 0x00 */
    u32 transDone;                /* 0x04, 1: no transfer pending */
    struct GfFont *font;          /* 0x08 */
    struct PrintQue *printQue;    /* 0x0C, 0: slot free */
    struct MsgBank *msgData;      /* 0x10 */
    struct BmpWin *bmpWin;        /* 0x14 */
    struct Strbuf *strBuf;        /* 0x18, 0xA0 characters */
    PrintUtil printUtil;          /* 0x1C */
} FieldMsgPrint;

/* Talk balloon window (0x34 bytes, three of them in FieldMsgBg). */
typedef struct FieldTalkWin {
    u8 reserved;                  /* 0x00, not accessed by field_msgbg.c */
    u8 index;                     /* 0x01, balloon slot and kind (0..2) */
    s16 shakeOffset;              /* 0x02, BG y offset of the shout shake */
    struct Strbuf *strBuf;        /* 0x04 */
    struct TalkMsgWinSys *talkSys; /* 0x08, 0: slot free */
    FieldMsgCursor cursor;        /* 0x0C */
    struct FieldMsgBg *msgBg;     /* 0x14 */
    VecFx32 *targetPos;           /* 0x18 */
    VecFx32 pos;                  /* 0x1C, position when the balloon opened */
    u8 reserved28[0xC];           /* 0x28, not accessed by field_msgbg.c */
} FieldTalkWin;

struct FieldSubMsgWin;

/* Message BG system of the field (0x17C bytes, FIELD_MSGBG_Create). */
typedef struct FieldMsgBg {
    u16 heapId;                   /* 0x000 */
    u16 bgFrame;                  /* 0x002, message frame, 0xFF: none */
    u16 bgFrameSys;               /* 0x004, system window frame, 0xFF: none */
    u16 windowKind;               /* 0x006, palette of the last window: 0xE system, 0xB talk */
    struct GfFont *font;          /* 0x008 */
    struct PrintQue *printQue;    /* 0x00C */
    FieldMsgPrint msgPrint[4];    /* 0x010 */
    struct FieldSubMsgWin *subMsgWin[8]; /* 0x0A0 */
    FieldTalkWin talkWin[3];      /* 0x0C0 */
    struct TalkMsgWinSys *talkSys; /* 0x15C */
    FieldMsgKeyWait keyWait;      /* 0x160 */
    struct Tcbl *tcbl;            /* 0x164 */
    struct G3dCamera *g3dCamera;  /* 0x168, 0: no talk balloons */
    void *vblankTask;             /* 0x16C, pending talk system setup */
    u8 sysFrameReq;               /* 0x170, 1: set up bgFrameSys before the next window */
    void *cursorCharFile;         /* 0x174 */
    NNSG2dCharacterData *cursorCharData; /* 0x178 */
} FieldMsgBg;

/* Message window (0xC bytes). */
typedef struct FieldMsgWin {
    struct BmpWin *bmpWin;        /* 0x00 */
    FieldMsgPrint *msgPrint;      /* 0x04 */
    FieldMsgBg *msgBg;            /* 0x08 */
} FieldMsgWin;

/* Streamed print with key wait (0xC bytes). */
typedef struct FieldMsgStream {
    u16 reserved;                 /* 0x00 */
    u16 wait;                     /* 0x02, frames per character */
    struct TextPrinter *stream;   /* 0x04 */
    FieldMsgBg *msgBg;            /* 0x08 */
} FieldMsgStream;

/* System window: bitmap window, stream and cursor (0x20 bytes). */
typedef struct FieldSysWin {
    struct BmpWin *bmpWin;        /* 0x00 */
    FieldMsgStream *stream;       /* 0x04 */
    FieldMsgPrint *msgPrint;      /* 0x08 */
    struct MsgBank *msgData;      /* 0x0C */
    struct Strbuf *strBuf;        /* 0x10 */
    FieldMsgBg *msgBg;            /* 0x14 */
    FieldMsgCursor cursor;        /* 0x18 */
} FieldSysWin;

/* Talk system window without a balloon tail (0x2C bytes). */
typedef struct FieldPlainWin {
    FieldMsgCursor cursor;        /* 0x00 */
    struct Strbuf *strBuf;        /* 0x08 */
    FieldMsgBg *msgBg;            /* 0x0C */
    struct TalkMsgWinSys *talkSys; /* 0x10 */
    struct MsgBank *msgData;      /* 0x14 */
    struct BmpWin *bmpWin;        /* 0x18 */
    FieldMsgStream *stream;       /* 0x1C */
    FieldMsgPrint *msgPrint;      /* 0x20 */
    int streamState;              /* 0x24 */
    s16 shakeOffset;              /* 0x28 */
} FieldPlainWin;

/* Small talk system window with an id (0x18 bytes, up to 8 in FieldMsgBg). */
typedef struct FieldSubMsgWin {
    struct Strbuf *strBuf;        /* 0x00 */
    u32 id;                       /* 0x04 */
    u32 talkIndex;                /* 0x08, talk system window index (3 + slot) */
    struct TalkMsgWinSys *talkSys; /* 0x0C */
    u8 reserved10[8];             /* 0x10, not accessed by field_msgbg.c */
} FieldSubMsgWin;

/* Menu list header as the field code fills it (0x20 bytes). */
typedef struct FieldMenuHeader {
    u16 itemCount;                /* 0x00 */
    u16 maxLines;                 /* 0x02 */
    u8 labelX;                    /* 0x04 */
    u8 dataX;                     /* 0x05 */
    u8 cursorX;                   /* 0x06 */
    u8 lineY : 4;                 /* 0x07 */
    u8 textColor : 4;
    u8 bgColor : 4;               /* 0x08 */
    u8 shadowColor : 4;
    u8 reserved09;                /* 0x09 */
    u16 cursorMargin : 3;         /* 0x0A, added to the text width */
    u16 lineSpacing : 4;          /* 0x0A, added to the font height */
    u16 reserved0A : 9;
    int pageSkip : 2;             /* 0x0C */
    int reserved0C : 30;
    u16 fontId;                   /* 0x10 */
    u16 fontHeight;               /* 0x12 */
    u16 posX;                     /* 0x14 */
    u16 posY;                     /* 0x16 */
    u16 width;                    /* 0x18, in characters */
    u16 height;                   /* 0x1A, in characters */
    u32 lineCallback;             /* 0x1C */
} FieldMenuHeader;

/* Header the arm9 menu list code takes (0x34 bytes). */
typedef struct BmpMenuListHeader {
    struct BmpMenuWork *items;    /* 0x00 */
    u32 moveCallback;             /* 0x04 */
    u32 lineCallback;             /* 0x08 */
    struct BmpWin *bmpWin;        /* 0x0C */
    u16 itemCount;                /* 0x10 */
    u16 maxLines;                 /* 0x12 */
    u8 labelX;                    /* 0x14 */
    u8 dataX;                     /* 0x15 */
    u8 cursorX;                   /* 0x16 */
    u8 lineY : 4;                 /* 0x17 */
    u8 textColor : 4;
    u8 bgColor : 4;               /* 0x18 */
    u8 shadowColor : 4;
    u8 reserved19;                /* 0x19 */
    u16 cursorMargin : 3;         /* 0x1A */
    u16 lineSpacing : 4;
    u16 pageSkip : 2;
    u16 reserved1A : 7;
    void *work;                   /* 0x1C */
    u16 fontId;                   /* 0x20 */
    u16 fontHeight;               /* 0x22 */
    u32 reserved24;               /* 0x24, set to 0 here, read by the arm9 list code */
    PrintUtil *printUtil;         /* 0x28 */
    struct PrintQue *printQue;    /* 0x2C */
    struct GfFont *font;          /* 0x30 */
} BmpMenuListHeader;

/* Menu: header items, list and the window it draws in (0x14 bytes). */
typedef struct FieldMenuFunc {
    FieldMsgBg *msgBg;            /* 0x00 */
    FieldMsgPrint *msgPrint;      /* 0x04 */
    struct BmpWin *bmpWin;        /* 0x08 */
    struct BmpMenuWork *items;    /* 0x0C */
    struct BmpMenuList *menuList; /* 0x10 */
} FieldMenuFunc;

/* One row of a menu item table: message id and the value it returns. */
typedef struct FieldMenuItemData {
    u32 msgId;
    u32 param;
} FieldMenuItemData;

typedef struct FieldYesNoItems {
    FieldMenuItemData item[2];
} FieldYesNoItems;

/* Window that slides in from the top and rolls two text lines (0x34 bytes). */
typedef struct FieldBgWin {
    FieldMsgBg *msgBg;            /* 0x00 */
    struct BmpWin *bmpWin;        /* 0x04 */
    struct Bmp *nextBmp;          /* 0x08, lines rolling in */
    struct Bmp *prevBmp;          /* 0x0C, lines rolling out */
    struct Strbuf *str;           /* 0x10 */
    struct Strbuf *lineStr;       /* 0x14 */
    u32 seq;                      /* 0x18 */
    s32 scrollY;                  /* 0x1C, BG y offset, -48 when hidden */
    u32 rollOffset;               /* 0x20 */
    u32 lineIndex;                /* 0x24 */
    FieldMsgCursor cursor;        /* 0x28 */
    struct GfFont *font;          /* 0x30 */
} FieldBgWin;

/* Window with a frame drawn into its own bitmap (0x18 bytes). */
typedef struct FieldSpWin {
    struct BmpWin *bmpWin;        /* 0x00 */
    u32 reserved;                 /* 0x04 */
    FieldMsgBg *msgBg;            /* 0x08 */
    struct Bmp *frameBmp;         /* 0x0C, 8x8 frame centre tile */
    FieldMsgCursor cursor;        /* 0x10 */
} FieldSpWin;

/* The DS code declares the stream callback as int (int); the SDK callback type is u8 (u32). */
#ifdef __MWERKS__
typedef int FieldMsgStreamCbRet;
typedef int FieldMsgStreamCbArg;
#else
typedef u8 FieldMsgStreamCbRet;
typedef u32 FieldMsgStreamCbArg;
#endif

#endif
