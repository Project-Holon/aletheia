#ifndef GAME_ARM9_WIPE_TYPES_H
#define GAME_ARM9_WIPE_TYPES_H

/* Screen wipe system shared by wipe.c (the system and its entry points) and
 * wipe_sub.c (the patterns). */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed short   s16;

/*
 * Window requests.  The wipes drive the DS hardware windows (the two window
 * rectangles, the plane masks inside and outside them and the window enable
 * bits of DISPCNT) of engine A and engine B.  A request is a small record in
 * the WindowRequests block of the wipe system plus a priority-1 task that
 * applies it and deletes itself, so the registers are written at a fixed
 * point of the frame.  Every request carries the screen (0 = engine A,
 * 1 = engine B) it is for.
 */
struct WindowVisibleRequest {
    u32 value;   /* DISPCNT bits 13..15: window 0, window 1, object window */
    u32 screen;
};

struct WindowInsideRequest {
    u32 planes;  /* plane mask inside the window */
    u32 effect;  /* colour effect bit of that mask */
    u32 window;  /* 0 or 1 */
    u32 screen;
};

struct WindowOutsideRequest {
    u32 planes;  /* plane mask outside all windows */
    u32 effect;
    u32 screen;
};

struct WindowRectRequest {
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    u32 window;  /* 0 or 1 */
    u32 screen;
};

struct WindowRequests {
    struct WindowVisibleRequest visible[2];      /* 0x00, by screen */
    struct WindowInsideRequest  inside[2][2];    /* 0x10, by screen then window */
    u8                          reserved[0x18];  /* 0x50, nothing reads or writes it */
    struct WindowOutsideRequest outside[2];      /* 0x68, by screen */
    struct WindowRectRequest    rect[2][2];      /* 0x80, by screen then window */
};

/* One screen's slot of the wipe system. */
struct WipePanel {
    u32   pattern;
    u32   frames;       /* number of steps of the wipe */
    s32   wait;         /* frames per step */
    u32   phase;        /* 0 = not started, 1 = running, 2 = release, 3 = done */
    u32   screen;       /* 0 = engine A, 1 = engine B */
    void *work;         /* pattern work object */
    struct WindowRequests *windowRequests;
    u32   hblank;       /* HBlank handler slots, passed on to the slot calls */
    u32   heapId;
    u16   color;        /* 0x7FFF = white, 0 = black */
    u16   pad26;
    u32   fadeOut;      /* 1 = the wipe covers the screen, 0 = it uncovers it */
    u32   usesBrightness; /* 1 = the pattern is the brightness fade */
};

typedef void (*Handler)(void *ctx);

struct WipeHBlankSlots {
    void   *work[2];
    Handler func[2];
    u32     active[2];
};

struct WipeSys {
    u32            division;
    u32            mainActive;
    u32            subActive;
    u32            mainUsed;
    u32            subUsed;
    struct WipePanel mainPanel;
    struct WipePanel subPanel;
    struct WipeHBlankSlots   hblank;
    struct WindowRequests    windowRequests;
    u16            active;
    u8             mainResetPending;
    u8             subResetPending;
    u16            color;
    u16            pad152;
    void          *hblankTask;
};

#endif
