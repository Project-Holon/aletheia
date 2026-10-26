#ifndef GAME_OV194_NAMEIN_GRAPHIC_SHARED_TYPES_H
#define GAME_OV194_NAMEIN_GRAPHIC_SHARED_TYPES_H

/* Types of the name entry screen (ov194), shared by namein_graphic.c, namein_graphic_field.c and
 * namein_graphic_main.c. The screen work embeds the input field, the grid, the message box, the
 * text-control block, the icon and the callback block as objects of their own types. */
#include "../types.h"
#include "../ov010/namein_args.h"

struct ClactActor;
struct Strbuf;
struct BmpOam;
struct Bmp;
struct PrintQueue;
struct GfFont;
struct MsgBank;
struct WordSet;
struct U16Vec;

typedef struct { int x, y; } NameinGraphicPair;

typedef struct { int x, y, z, w; } NameinGraphicBox;

typedef struct NameinGraphicMainRect { int left, top, right, bottom; } NameinGraphicMainRect;

typedef struct NameinGraphicMainVec2 { s16 x, y; } NameinGraphicMainVec2;

/* A step of the screen callback: step(callback, &callback->arg, callback->owner). The owner type differs per step, so the parameter list is left open. */
typedef void (*NameinGraphicStep)();

/* The callback block (the 0x10 block at work+0x2A0). */
typedef struct NameinGraphicCallback {
    NameinGraphicStep fn;            /* 0x00 */
    unsigned int state;              /* 0x04 */
    unsigned int arg;                /* 0x08 */
    void *owner;                     /* 0x0C */
} NameinGraphicCallback;

/* The icon actor work (the 0x3C block at work+0x264). */
typedef struct NameinGraphicIcon {
    struct ClactActor *actor;        /* 0x00 */
    unsigned int reserved04;             /* 0x04 */
    unsigned int palette;            /* 0x08 */
    unsigned int character;          /* 0x0C */
    unsigned int cellAnim;           /* 0x10 */
    int state;                       /* 0x14 */
    int touchMode;                   /* 0x18 */
    int animActive;                  /* 0x1C */
    unsigned short animTick;         /* 0x20 */
    unsigned char pad_22[2];
    unsigned int palette2;           /* 0x24 */
    struct Strbuf *text;             /* 0x28 */
    struct BmpOam *oam;              /* 0x2C */
    struct Bmp *bmp;                 /* 0x30 */
    int oamDirty;                    /* 0x34 */
    struct PrintQueue *printSys;     /* 0x38 */
} NameinGraphicIcon;

/* The name-entry input field (the 0x94 block at work+0x68). */
typedef struct NameinGraphicInputField {
    unsigned short primary[11];    /* 0x00 primary text, up to maxLength code units */
    unsigned short secondary[3];   /* 0x16 candidate text */
    unsigned char pad_1C[2];
    unsigned short primaryLength;  /* 0x1E */
    unsigned short secondaryLength;/* 0x20 */
    unsigned short maxLength;      /* 0x22 */
    unsigned char pad_24[4];
    int needsRefresh;              /* 0x28 */
    void *win;                     /* 0x2C window handle */
    unsigned char drawDone;        /* 0x30 */
    unsigned char pad_31[3];
    struct GfFont *font;           /* 0x34 */
    void *printSys;                /* 0x38 */
    void *strbuf;                  /* 0x3C scratch string buffer */
    void *bmpWin;                  /* 0x40 bmp window */
    void *actors[16];              /* 0x44 character actor handles */
    void *charMember[3];           /* 0x84 character tables used as conversion tables */
    void *pairMember;              /* 0x90 pair table */
} NameinGraphicInputField;

/* Operations of the kana/symbol picker. The parameter lists differ between the kana and the symbol variant, so they are left open. */
typedef int (*NameinPickerBoxFn)();
typedef void (*NameinPickerMoveFn)();
typedef int (*NameinPickerValueFn)();

/* The kana/symbol picker embedded at the start of the grid. */
typedef struct NameinGraphicPicker {
    void *table;                   /* 0x00 grid table */
    unsigned char map[13];         /* 0x04 mode map copied from d_021F555C */
    unsigned char pad_11[3];
    NameinPickerBoxFn getBox;      /* 0x14 int (*)(Pair *, Box *) */
    NameinPickerMoveFn move;       /* 0x18 void (*)(int, int, char *) */
    NameinPickerValueFn getValue;  /* 0x1C unsigned (*)(int *, int *) */
    unsigned short width;          /* 0x20 */
    unsigned short height;         /* 0x22 */
} NameinGraphicPicker;

/* The kana/symbol cursor work (the 0xB4 block at grid+0x24). */
typedef struct NameinGraphicCursor {
    unsigned short colorFrom[16]; /* 0x00 start colours copied from the glyph table */
    unsigned short colorTo[16];   /* 0x20 end colours copied from the glyph table */
    unsigned short fadeCell[16];  /* 0x40 fade output cells */
    unsigned short phase[16];     /* 0x60 fade phase accumulators */
    unsigned short blinkTimer;    /* 0x80 */
    unsigned char pad_82[2];
    NameinGraphicMainRect rect;                    /* 0x84 selection rectangle */
    int mode;                     /* 0x94 */
    int active;                   /* 0x98 */
    int flag;                     /* 0x9C */
    int selected;                 /* 0xA0 */
    void *actorA;                 /* 0xA4 top cursor actor */
    void *actorB;                 /* 0xA8 bottom cursor actor */
    unsigned short actorAX;       /* 0xAC */
    short actorAY;                     /* 0xAE */
    unsigned short actorBX;       /* 0xB0 */
    short actorBY;                     /* 0xB2 */
} NameinGraphicCursor;

/* The kana/symbol grid work (the 0x130 block at work+0xFC). */
typedef struct NameinGraphicGrid {
    NameinGraphicPicker picker;      /* 0x00 picker, see NAMEIN_GRAPHIC_InitPicker */
    NameinGraphicCursor cursor;      /* 0x24 kana/symbol cursor */
    int selectionX;                  /* 0xD8 selected cell x */
    int selectionY;                  /* 0xDC selected cell y */
    void *bmpWin;                    /* 0xE0 cell-tip bmp window */
    int state;                       /* 0xE4 input state (kana, symbol, commit) */
    int action;                      /* 0xE8 action returned by NAMEIN_GRAPHIC_GetGridAction */
    void *tipBmp;                    /* 0xEC cell-tip bmp, same window as bmpWin */
    unsigned char tipDirty;          /* 0xF0 */
    unsigned char pad_F1[3];
    void *font;                      /* 0xF4 */
    void *printSys;                  /* 0xF8 */
    unsigned short actionValue;      /* 0xFC */
    unsigned short heap;             /* 0xFE */
    int mode;                        /* 0x100 */
    int index;                       /* 0x104 */
    unsigned char variant;           /* 0x108 */
    unsigned char pad_109[1];
    unsigned short animTick;         /* 0x10A */
    unsigned short animPhase;        /* 0x10C */
    unsigned char pad_10E[2];
    int animActive;                  /* 0x110 */
    int targetMode;                  /* 0x114 */
    int extraLayer;                  /* 0x118 */
    void *paletteHandleA;            /* 0x11C */
    void *paletteHandleB;            /* 0x120 */
    void *paletteDataA;              /* 0x124 */
    void *paletteDataB;              /* 0x128 */
    void **data;                     /* 0x12C the loaded member table */
} NameinGraphicGrid;

/* The name-entry message box (the 0x24 block at work+0x230). */
typedef struct NameinGraphicMsgBox {
    void *bank;                      /* 0x00 message bank */
    struct GfFont *font;             /* 0x04 font */
    void *bmp;                       /* 0x08 bmp used by the printer */
    unsigned char dirty;             /* 0x0C */
    unsigned char pad_0D[3];
    void *printSys;                  /* 0x10 */
    void *win;                       /* 0x14 bmp window */
    void *wordSet;                   /* 0x18 word set */
    void *strbuf;                    /* 0x1C scratch string buffer */
    unsigned short color;            /* 0x20 fill colour */
    unsigned char pad_22[2];
} NameinGraphicMsgBox;

/* The text-control block (the 0x10 block at work+0x254). */
typedef struct NameinGraphicTcbl {
    void *stream;                    /* 0x00 print stream */
    void *handle;                    /* 0x04 tcbl handle */
    NameinGraphicStep callback;      /* 0x08 callback step */
    unsigned short counter;          /* 0x0C */
    unsigned short flag;             /* 0x0E */
} NameinGraphicTcbl;

/* The CLACT actor handles for the kana/symbol cursor row. */
typedef struct NameinGraphicActors {
    unsigned int palette;       /* 0x00 palette registration */
    unsigned int character;     /* 0x04 character registration */
    unsigned int cellAnim;      /* 0x08 cell-animation registration */
    void *list[21];             /* 0x0C actor handles, index 17 is the selected cursor actor */
} NameinGraphicActors;

/* The name-entry screen work, 0x2D4 bytes on the DS. */
typedef struct NameinGraphicWork {
    unsigned char *display;       /* 0x00 */
    NameinGraphicActors actors;   /* 0x04 */
    unsigned int paletteTag;      /* 0x64 */
    NameinGraphicInputField inputField; /* 0x68 */
    NameinGraphicGrid grid;       /* 0xFC */
    void **members;               /* 0x22C */
    NameinGraphicMsgBox msgBox;   /* 0x230 */
    NameinGraphicTcbl tcbl;       /* 0x254 */
    NameinGraphicIcon icon;       /* 0x264 */
    NameinGraphicCallback callback; /* 0x2A0 */
    void *font;                   /* 0x2B0 */
    void *printSys;               /* 0x2B4 */
    void *msgBank;                /* 0x2B8 */
    void *wordSet;                /* 0x2BC */
    void *oamSys;                 /* 0x2C0 */
    NameInArgs *args;             /* 0x2C4 */
    int pendingMsg;               /* 0x2C8 */
    void *profWord;               /* 0x2CC */
    void *nameStrbuf;             /* 0x2D0 */
} NameinGraphicWork;

#endif
