#ifndef ZUKAN_DETAIL_SHARED_TYPES_H
#define ZUKAN_DETAIL_SHARED_TYPES_H

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

/* Forward declarations shared across the zukan detail overlay files. */
struct Blk37;
struct Ctx;
struct GfFont;
struct Ov208Icon;
struct PrintSys;
struct Node;
struct WordSet;
struct StrObj;
struct Cfg;
struct Bank;
struct DispVram;
struct DispConfig;
struct Light;
struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Obj;
struct Vec2;
struct Actor;
struct Ov208Buf;
struct Ov208Blend;
struct Ov208Ctx;

/* Integer point used by the common helper tables. */
struct Pair { int x; int y; };

/*
 * Palette animation object, 0x14 bytes, created by
 * ZUKAN_DETAIL_COMMON_CreatePaletteAnim. memory is the TCB buffer, tcb the
 * task created over it, slots the PALANM handle, slotMask the buffer mask and
 * fadeState the fade transition (0 idle, 1 fading in, 2 fading out, 3 fading
 * out to the alternate palette).
 */
struct Ov208PalFade {
    struct Ctx *tcb;
    void *memory;
    void *slots;
    unsigned short slotMask;
    unsigned short padE;
    unsigned int fadeState;
};

/*
 * Context shared by every zukan detail screen, 0x24 bytes, built by
 * ZUKAN_DETAIL_COMMON_CreateContext from the screen arguments. cursorPtr points
 * into the caller's cursor word; speciesTable and entryCount describe the seen
 * species ring the cursor walks.
 */
struct Ov208Ctx {
    void *blk;
    void *display;
    void *font;
    void *graphics;
    void *work;
    void *headbar;
    unsigned short *speciesTable;
    unsigned short entryCount;
    unsigned short pad1e;
    unsigned short *cursorPtr;
};

/*
 * State node used by the procsys helpers. The five words are, in order, the
 * handler table, the current state, a free-running counter, the value passed to
 * the handlers and the work buffer allocated by ZUKAN_DETAIL_PROCSYS_AllocBuffer.
 */
struct Ov208Fsm;

typedef int (*Ov208FsmCallback)(struct Ov208Fsm *node, int *counter, int a, void *work, int arg);

struct Ov208Fsm {
    Ov208FsmCallback *callbacks;
    int state;
    int counter;
    int a;
    void *work;
};

/* One BG template entry of the 8-row table d_021C81B4. */
struct BgTemplate {
    u32 w[8];
};

/* One row of a background template table: bg number, template, type and enable. */
struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

/* 3-component fixed-point vector. */
struct Vec3 {
    int x;
    int y;
    int z;
};

/*
 * Background graphics object built by ZUKAN_DETAIL_GRAPHIC_InitBgGraphics,
 * 0x14 bytes: window is the BMP window descriptor, actorUnit the CLACT unit,
 * camera the G3D camera/system pointer, task the vblank task and has3d the
 * lazy 3d flag.
 */
struct Ov208BgGfx {
    unsigned window;
    void *actorUnit;
    void *camera;
    void *task;
    int has3d;
};

/* CLACT actor renderer base embedded at +4 of the background object. */
struct Ov208ActorSystem {
    void *unit;
};

/*
 * Head bar work object, 0x34 bytes. state drives the icon animation
 * (0 none, 1 fade-in, 2 shown, 3 fade-out) and count the per-frame delay.
 * window/bmp/tile/size describe the icon graphics, msg is the message bank,
 * task/queue the vblank task and print queue, dirty marks a pending upload and
 * font the printsys font handle passed by ZUKAN_DETAIL_MAIN_Init.
 */
struct Ov208Icon {
    u16 heap;
    u16 pad2;
    unsigned font;
    unsigned state;
    int kind;
    unsigned char count;
    unsigned char pad11[3];
    unsigned window;
    void *bmp;
    unsigned tile;
    unsigned size;
    struct MsgBank *msg;
    void *task;
    unsigned queue;
    unsigned dirty;
};

/* Palette transfer descriptor used by the touch bar (data at +0xC). */
struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

/* Screen point used by the area screen's touch hit test. */
typedef signed short s16;

struct PtS { s16 x, y; };

/* Word-size alias kept so the touch bar palette/handle casts stay one line. */
typedef signed int s32;

/* Signed short alias kept so the touch bar palette casts stay one line. */
typedef short s16;

typedef signed short s16;

/* Unsigned point/actor stand-ins of the touch bar actors. */
struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

/*
 * Screen state tail shared by the info and area screens (0x438 bytes, read
 * from +0x424). mode selects what the D-pad does, keyFlag records a handled
 * key and overlayPending/overlayReady/overlayCommitted drive the town overlay
 * transition.
 */
struct Ov208AreaState {
    u8 pad0[0x424];
    int mode;
    u32 keyFlag;
    u32 overlayPending;
    u32 overlayReady;
    u32 overlayCommitted;
};

/*
 * Town marker table of the area screen: 0x3d entries from +0x1e0, each a
 * state word and the CLACT actor pointer.
 */
typedef struct {
    u8 pad0[0x1e0];
    struct { int state; int obj; } markers[0x3d];
} Ov208MarkerTable;

#endif
