#ifndef TALKMSGWIN_TYPES_H
#define TALKMSGWIN_TYPES_H

/*
 * Talk message balloons (talkmsgwin.c): up to 32 text windows on a BG layer.
 * A balloon has a pointer-shaped tail drawn as a textured 3D polygon, so the
 * system keeps the field camera state and sets its own camera while it draws.
 */

#include "field_msgbg_types.h"

#define TALKMSGWIN_MAX 32

#include "../sdk_fx.h"

/* Window state, TalkMsgWin.state */
enum {
    TALKMSGWIN_STATE_FREE = 0,
    TALKMSGWIN_STATE_READY = 1,          /* set up, waits for the open request */
    TALKMSGWIN_STATE_OPEN_REQUEST = 2,
    TALKMSGWIN_STATE_OPENING = 3,        /* balloon grows in 8 steps */
    TALKMSGWIN_STATE_SHOWN = 4,          /* text is printing or printed */
    TALKMSGWIN_STATE_CLOSE_REQUEST = 5,  /* balloon shrinks, then is released */
    TALKMSGWIN_STATE_CLOSED = 6
};

/* Tail placement mode, TalkMsgWin.tailMode */
enum {
    TALKMSGWIN_TAIL_MODE_AUTO = 0,       /* tail side follows the target point */
    TALKMSGWIN_TAIL_MODE_LOWER_EDGE = 1, /* tail leaves the bottom edge */
    TALKMSGWIN_TAIL_MODE_UPPER_EDGE = 2  /* tail leaves the top edge */
};

/* Tail side, TalkMsgWinShape.tailSide; also selects the notch in the frame */
enum {
    TALKMSGWIN_TAIL_SIDE_NONE = 0,
    TALKMSGWIN_TAIL_SIDE_TOP = 1,
    TALKMSGWIN_TAIL_SIDE_BOTTOM = 2,
    TALKMSGWIN_TAIL_SIDE_LEFT = 3,
    TALKMSGWIN_TAIL_SIDE_RIGHT = 4,
    TALKMSGWIN_TAIL_SIDE_TOP_LEFT = 5,
    TALKMSGWIN_TAIL_SIDE_TOP_RIGHT = 6,
    TALKMSGWIN_TAIL_SIDE_BOTTOM_LEFT = 7,
    TALKMSGWIN_TAIL_SIDE_BOTTOM_RIGHT = 8
};

/* Frame type, TalkMsgWin.frameType */
enum {
    TALKMSGWIN_FRAME_SIMPLE = 0,
    TALKMSGWIN_FRAME_CORNERED = 1
};

/* Creation parameters (0x18); copied to the head of TalkMsgWinSys. */
typedef struct TalkMsgWinParam {
    u16 heapId;                 /* 0x00 */
    struct G3dCamera *camera;   /* 0x04, field camera */
    struct GfFont *font;        /* 0x08 */
    u16 frameBaseTile;          /* 0x0C, first BG tile of the frame graphics */
    u32 bgLayer;                /* 0x10 */
    u8 framePalette;            /* 0x14, palette slot of the frame graphics */
    u8 bmpWinPalette;           /* 0x15, palette of the text windows */
} TalkMsgWinParam;

/* Balloon polygon in model space around origin; vertices are relative to it. */
typedef struct TalkMsgWinShape {
    VecFx32 origin;             /* 0x00, world position the tail points at */
    s32 scale;                  /* 0x0C, largest vertex distance */
    VecFx16 tip;                /* 0x10, always 0,0,0 */
    VecFx16 tailBaseA;          /* 0x16 */
    VecFx16 tailBaseB;          /* 0x1C */
    VecFx16 cornerTopLeft;      /* 0x22 */
    VecFx16 cornerTopRight;     /* 0x28 */
    VecFx16 cornerBottomLeft;   /* 0x2E */
    VecFx16 cornerBottomRight;  /* 0x34 */
    s32 tailSide;               /* 0x3C, 0: no tail polygon */
} TalkMsgWinShape;

/* One text window with its balloon (0x64). */
typedef struct TalkMsgWin {
    u16 state;                  /* 0x00 */
    u8 isPlain;                 /* 0x02, 1: no balloon polygon */
    u8 frameType;               /* 0x03 */
    u32 tailMode;               /* 0x04 */
    struct PrintStream *printStream;  /* 0x08 */
    struct BmpWin *bmpWin;      /* 0x0C */
    const VecFx32 *targetPos;   /* 0x10, 0: tail points at the anchor window */
    struct Strbuf *str;         /* 0x14 */
    u16 color;                  /* 0x18 */
    u16 anchorIndex;            /* 0x1A, window the tail points at */
    TalkMsgWinShape shape;      /* 0x1C */
    u8 textX;                   /* 0x5C */
    u8 textY;                   /* 0x5D */
    u16 scaleEighths;           /* 0x5E, balloon size in eighths */
    u32 printWait;              /* 0x60 */
} TalkMsgWin;

/* Window setup values handed to TALKMSGWIN_SetupEntry (0x14). */
typedef struct TalkMsgWinConfig {
    u32 tailMode;               /* 0x00 */
    u32 tailSide;               /* 0x04 */
    u8 x;                       /* 0x08, tiles */
    u8 y;                       /* 0x09 */
    u8 width;                   /* 0x0A */
    u8 height;                  /* 0x0B */
    u16 color;                  /* 0x0C */
    u16 frameType;              /* 0x0E */
    u32 printWait;              /* 0x10 */
} TalkMsgWinConfig;

/* The system (0xCD0). */
typedef struct TalkMsgWinSys {
    TalkMsgWinParam param;                  /* 0x000 */
    TalkMsgWin windows[TALKMSGWIN_MAX];     /* 0x018 */
    struct Tcbl *tcbl;                      /* 0xC98, print tasks */
    u16 frameTileCount;                     /* 0xC9C */
    u8 padC9E[2];
    VecFx32 savedEye;                       /* 0xCA0, field camera state */
    VecFx32 savedUp;                        /* 0xCAC */
    VecFx32 savedTarget;                    /* 0xCB8 */
    s32 savedScale;                         /* 0xCC4 */
    u32 texKey;                             /* 0xCC8, VRAM key of the balloon texture */
    u32 plttKey;                            /* 0xCCC, VRAM key of its palette */
} TalkMsgWinSys;

#endif
