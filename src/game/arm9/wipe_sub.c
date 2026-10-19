/*
 * file:     wipe_sub.c
 * unit:     yes
 * function: WIPE_SUB_ResolveColor, WIPE_SUB_GetEndColor, WIPE_SUB_ResetBrightnessTask, WIPE_SUB_RequestBrightnessReset, WIPE_SUB_ApplyEndBrightness, WIPE_SUB_ClearSys, WIPE_SUB_PatternFadeOut, WIPE_SUB_PatternFadeIn, WIPE_SUB_PatternShutterDownOut, WIPE_SUB_PatternShutterDownIn, WIPE_SUB_PatternShutterUpOut, WIPE_SUB_PatternShutterUpIn, WIPE_SUB_PatternBoxOpenOut, WIPE_SUB_PatternBoxOpenIn, WIPE_SUB_PatternCircleOut, WIPE_SUB_PatternCircleIn, WIPE_SUB_PatternBoxSlideOut, WIPE_SUB_PatternBoxSlideIn, WIPE_SUB_CalcStep, WIPE_SUB_AddRect, WIPE_SUB_InitRectInterp, WIPE_SUB_FadeStart, WIPE_SUB_FadeMain, WIPE_SUB_FadeStep, WIPE_SUB_FadeVTask, WIPE_SUB_WindowRectHBlank, WIPE_SUB_CreateLineBuffers, WIPE_SUB_DeleteLineBuffers, WIPE_SUB_FreeLineBuffers, WIPE_SUB_GetLineBuffer, WIPE_SUB_FlipLineBuffersTask, WIPE_SUB_RequestWindowEnd, WIPE_SUB_SetupWindow, WIPE_SUB_SetWindowVisibleMode, WIPE_SUB_InitLineMask, WIPE_SUB_RequestLineMaskFlip, WIPE_SUB_RequestLineMaskHBlank, WIPE_SUB_RequestLineMaskHBlankEnd, WIPE_SUB_FlipLineMaskTask, WIPE_SUB_LineMaskHBlank, WIPE_SUB_BoxStart, WIPE_SUB_BoxMain, WIPE_SUB_BoxInit, WIPE_SUB_BoxStep, WIPE_SUB_CircleStart, WIPE_SUB_CircleMain, WIPE_SUB_CircleInit, WIPE_SUB_CircleStep, WIPE_SUB_CalcCircleSpan, WIPE_SUB_CalcCircleLines, WIPE_SUB_ShutterStart, WIPE_SUB_ShutterMain, WIPE_SUB_ShutterInit, WIPE_SUB_ShutterStep, WIPE_SUB_ShutterExit, WIPE_SUB_CalcShutterRows, WIPE_SUB_CalcShutterBand, WIPE_SUB_SetWindowVisible, WIPE_SUB_SetWindowInside, WIPE_SUB_SetWindowOutside, WIPE_SUB_SetWindowRect, WIPE_SUB_RequestWindowVisible, WIPE_SUB_RequestWindowInside, WIPE_SUB_RequestWindowOutside, WIPE_SUB_RequestWindowRect, WIPE_SUB_WindowVisibleTask, WIPE_SUB_WindowInsideTask, WIPE_SUB_WindowOutsideTask, WIPE_SUB_WindowRectTask
 * address:  0x020225F4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   TCB_DeleteTask   0x02030EAC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_0209F570     0x0209F570  data
 *   g_020A73D0     0x020A73D0  data
 *   g_wipe_slot0   0x020A73D0  data
 *   d_0209F56C     0x0209F56C  data
 *   d_0209F574     0x0209F574  data
 *   d_0209F568     0x0209F568  data
 *   _s32_div_f  0x0209C0A4  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02023464_File  0x020A7450  data
 *   FX_Sqrt   0x0207C7B4  arm
 *   d_0209F61C  0x0209F61C  data
 *   d_0209F628  0x0209F628  data
 *   d_0209F5EC  0x0209F5EC  data
 *   d_0209F640  0x0209F640  data
 *   d_0209F6B8  0x0209F6B8  data
 *   d_0209F6C4  0x0209F6C4  data
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   WIPE_SetBackColor  0x020222A8  thumb
 *   WIPE_SetBrightness  0x020222CC  thumb
 *   WIPE_RequestSetHBlankSlot  0x02022518  thumb
 *   WIPE_RequestClearHBlankSlot  0x02022568  thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 */
/* Hardware registers (display engine A, engine B and the double-buffer aliases). */
#define REG_VCOUNT  (*(volatile u16 *)0x04000006)
#define REG_DISPSTAT  (*(volatile u16 *)0x04000004)
#define REG_WININ     (*(volatile u16 *)0x04000048)
#define REG_WINOUT    (*(volatile u16 *)0x0400004A)
#define REG_DB_WININ  (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT (*(volatile u16 *)0x0400104A)
#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)

/*
 * The per-line window handler reaches WIN0H/WIN0V/WIN1H/WIN1V of engine A
 * as halfword offsets from the DISPSTAT address it already holds in a
 * register (that is what the original code compiles to), and the same four
 * registers of engine B through their own base pointers.
 */
#define DISPSTAT_BASE            ((volatile u16 *)0x04000004)
#define WIN0H_OFFSET             ((0x04000040 - 0x04000004) / 2)
#define WIN1H_OFFSET             ((0x04000042 - 0x04000004) / 2)
#define WIN0V_OFFSET             ((0x04000044 - 0x04000004) / 2)
#define WIN1V_OFFSET             ((0x04000046 - 0x04000004) / 2)
#define REG_DB_WIN0H_PTR         ((volatile u16 *)0x04001040)
#define REG_DB_WIN1H_PTR         ((volatile u16 *)0x04001042)

/* Update one window-control halfword during HBlank only (DISPSTAT bit 1). */
#define UPDATE_WINDOW_REG(reg, keepMask, bits, effectBit) \
    if (REG_DISPSTAT & 2) {                               \
        value = (reg & keepMask) | (bits);                \
        reg = value | effectBit;                          \
    }

/* Plane mask outside all windows. */
#define SET_OUTSIDE_PLANES(screen, planes)                                   \
    if ((screen) == 0) { UPDATE_WINDOW_REG(REG_WINOUT, ~0x3F, planes, 0x20) } \
    else { UPDATE_WINDOW_REG(REG_DB_WINOUT, ~0x3F, planes, 0x20) }

/* Plane mask inside window 0 or window 1. */
#define SET_INSIDE_PLANES(screenExpr, window, planes)                                      \
    screen = (screenExpr);                                                                 \
    if ((window) == 0) {                                                                   \
        if (screen == 0) { UPDATE_WINDOW_REG(REG_WININ, ~0x3F, planes, 0x20) }             \
        else { UPDATE_WINDOW_REG(REG_DB_WININ, ~0x3F, planes, 0x20) }                      \
    } else {                                                                               \
        if (screen == 0) { UPDATE_WINDOW_REG(REG_WININ, ~0x3F00, (planes) << 8, 0x2000) }  \
        else { UPDATE_WINDOW_REG(REG_DB_WININ, ~0x3F00, (planes) << 8, 0x2000) }           \
    }

struct Node;
typedef signed long long s64;

#include "wipe_types.h"

/* Brightness fade work object (0x24 bytes), updated once per frame. */
struct FadeState {
    s32 stepsLeft;
    s32 frameLimit;
    s32 frame;
    s32 value;       /* current brightness, 7 fractional bits */
    s32 target;      /* final brightness, 7 fractional bits */
    s32 delta;       /* added to value on every step */
    s32 screen;
    s32 brightness;  /* value / 128, what is written to the screen */
    void *task;
};

/* A rectangle of window edges; the Box wipe keeps them with 7 fractional bits. */
struct FixedRect {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
};

/*
 * Line buffers.  The Circle wipe computes the left and right edge of the
 * window for each of the 192 lines into the staged arrays, a task copies
 * them to the live arrays, and the HBlank handler programs one window
 * register pair per line from the live arrays.
 */
struct LineBuffer {
    s16 liveLeft[0xC0];
    s16 liveRight[0xC0];
    s16 stagedLeft[0xC0];
    s16 stagedRight[0xC0];
    u32 window;             /* which hardware window this buffer drives */
};

/* Header shared by every work object that owns line buffers. */
struct LineBuffers {
    struct LineBuffer *buffers;
    s32 count;              /* 1 or 2 */
    u32 screen;
};

/* Box wipe work object (0x4C bytes). */
struct BoxWork {
    struct FixedRect rect;      /* 0x00 current window rectangle */
    struct FixedRect step;      /* 0x10 added to rect on every step */
    struct FixedRect target;    /* 0x20 final window rectangle, whole pixels */
    u32 screen;                 /* 0x30 */
    u32 window;                 /* 0x34 */
    s32 stepsLeft;              /* 0x38 */
    s32 period;                 /* 0x3C frames per step */
    s32 tick;                   /* 0x40 */
    u32 closing;                /* 0x44 */
    struct WindowRequests *windowRequests; /* 0x48 */
};

/* Box wipe parameter table (rodata, 12 bytes). */
struct BoxParam {
    u8 from[4];         /* start rectangle: left, top, right, bottom */
    u8 to[4];           /* end rectangle */
    u8 window;
    u8 insidePlanes;
    u8 outsidePlanes;
    u8 closing;         /* 1 = covers the screen, 0 = uncovers it */
};

/* Circle wipe work object (0x38 bytes). */
struct CircleWork {
    struct LineBuffers lines;   /* 0x00 */
    s32 radius;                 /* 0x0C 7 fractional bits */
    s32 centerX;                /* 0x10 */
    s32 centerY;                /* 0x14 */
    s32 radiusStep;             /* 0x18 */
    s32 stepsLeft;              /* 0x1C */
    s32 frameLimit;             /* 0x20 frames per step */
    s32 frame;                  /* 0x24 */
    u32 heapId;                 /* 0x28 */
    u32 closing;                /* 0x2C */
    struct WindowRequests *windowRequests; /* 0x30 */
    u32 hblank;                 /* 0x34 */
};

/* Circle wipe parameter table (rodata, 12 bytes). */
struct CircleParam {
    s16 startRadius;
    s16 endRadius;
    s16 centerX;
    s16 centerY;
    u8  window;
    u8  insidePlanes;
    u8  outsidePlanes;
    u8  closing;
};

/*
 * Line mask: two 192-entry tables of hidden/visible flags per half (front
 * is what the HBlank handler shows, back is what the pattern paints and the
 * flip task copies over front), and the window each half drives.
 */
struct LineMaskHalf {
    u8  front[0xC0];
    u8  back[0xC0];
    u32 window;
};

struct LineMask {
    struct LineMaskHalf half[2];
    u8 halfCount;       /* 1 = only half[0] is used */
    u8 screen;
};

/* One band of a shutter table: rows from start to end, painted in two tones. */
struct ShutterBand {
    u8  start;
    u8  end;
    u16 firstTone;
};

/* Shutter descriptor in RAM (the table pointer is filled in by the pattern). */
struct ShutterDesc {
    const struct ShutterBand *bands;
    u16 bandCount;
    u16 closing;        /* 1 = covers the screen, 0 = uncovers it */
};

struct ShutterDescTable {
    struct ShutterDesc descs[6];
};

/* Shutter wipe work object (0x334 bytes). */
struct ShutterWork {
    struct LineMask mask;       /* 0x000 */
    const struct ShutterBand *bands; /* 0x30C */
    s32 bandCount;              /* 0x310 */
    s32 stepBound;              /* 0x314 number of steps */
    s32 step;                   /* 0x318 */
    s32 frameLimit;             /* 0x31C frames per step */
    s32 frame;                  /* 0x320 */
    u32 closing;                /* 0x324 */
    u32 heapId;                 /* 0x328 */
    struct WindowRequests *windowRequests; /* 0x32C */
    u32 hblank;                 /* 0x330 */
};

/* Zero for the Box tick counter; an enum-typed zero keeps its own register web. */
typedef enum { BOX_TICK_ZERO } BoxTickInit;

extern void *GFL_USE_AddMainTask(void *fn, void *arg, u32 prio);
extern u32 TCB_DeleteTask(struct Node *n);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern void MI_CpuFill8(void *dst, u8 data, u32 size);
extern s32 _s32_div_f(s32 shifted, s32 c);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern s32 FX_Sqrt(s32 x);
void WIPE_ResetWndMask(void *win);
void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
void WIPE_SetBackColor(u32 a);
void WIPE_SetBrightness(u32 which, int brightness);
void WIPE_RequestSetHBlankSlot(u32 slots, u32 ctx, u32 fn, u32 slotIdx, u32 heapId);
void WIPE_RequestClearHBlankSlot(u32 slots, u32 slotIdx, u32 heapId);
u16 WIPE_SUB_ResolveColor(struct WipeSys *sys, u16 color);
u16 WIPE_SUB_GetEndColor(struct WipeSys *sys);
void WIPE_SUB_ResetBrightnessTask(void *task, struct WipePanel *panel);
void WIPE_SUB_RequestBrightnessReset(struct WipePanel *panel);
void WIPE_SUB_ApplyEndBrightness(struct WipePanel *panel);
void WIPE_SUB_ClearSys(struct WipeSys *sys);
u32 WIPE_SUB_PatternFadeOut(struct WipePanel *panel);
u32 WIPE_SUB_PatternFadeIn(struct WipePanel *panel);
void WIPE_SUB_PatternShutterDownOut(struct WipePanel *panel);
void WIPE_SUB_PatternShutterDownIn(struct WipePanel *panel);
void WIPE_SUB_PatternShutterUpOut(struct WipePanel *panel);
void WIPE_SUB_PatternShutterUpIn(struct WipePanel *panel);
void WIPE_SUB_PatternBoxOpenOut(struct WipePanel *panel);
void WIPE_SUB_PatternBoxOpenIn(struct WipePanel *panel);
void WIPE_SUB_PatternCircleOut(struct WipePanel *panel);
void WIPE_SUB_PatternCircleIn(struct WipePanel *panel);
void WIPE_SUB_PatternBoxSlideOut(struct WipePanel *panel);
void WIPE_SUB_PatternBoxSlideIn(struct WipePanel *panel);
s32 WIPE_SUB_CalcStep(s32 start, s32 end, s32 frames);
void WIPE_SUB_AddRect(struct FixedRect *dst, struct FixedRect *src);
void WIPE_SUB_InitRectInterp(struct FixedRect *current, struct FixedRect *target, struct FixedRect *step, const u8 *from, const u8 *to, s32 frames);
void WIPE_SUB_FadeStart(struct WipePanel *panel, u32 closing);
u32 WIPE_SUB_FadeMain(struct WipePanel *panel);
int WIPE_SUB_FadeStep(struct FadeState *fade);
void WIPE_SUB_FadeVTask(void *task, struct FadeState *fade);
void WIPE_SUB_WindowRectHBlank(struct LineBuffers *lines);
void WIPE_SUB_CreateLineBuffers(struct LineBuffers *lines, u32 windowSelect, u32 screen, u32 heapId);
void WIPE_SUB_DeleteLineBuffers(struct LineBuffers *lines);
void WIPE_SUB_FreeLineBuffers(struct LineBuffers *lines);
struct LineBuffer *WIPE_SUB_GetLineBuffer(struct LineBuffers *lines, u32 index);
void WIPE_SUB_FlipLineBuffersTask(void *task, struct LineBuffers *lines);
void WIPE_SUB_RequestWindowEnd(u32 closing, struct WindowRequests *requests, u32 screen);
void WIPE_SUB_SetupWindow(struct WindowRequests *requests, u32 insidePlanes, u32 outsidePlanes, u32 window, u32 screen, u32 left, u32 top, u32 right, u32 bottom, u32 queued);
void WIPE_SUB_SetWindowVisibleMode(struct WindowRequests *requests, u32 value, u32 screen, u32 queued);
void WIPE_SUB_InitLineMask(struct LineMask *mask, u32 screen, u32 halfCount, u32 window0, u32 window1);
void *WIPE_SUB_RequestLineMaskFlip(struct LineMask *mask);
void WIPE_SUB_RequestLineMaskHBlank(u32 hblank, struct LineMask *mask, u32 heapId);
void WIPE_SUB_RequestLineMaskHBlankEnd(u32 hblank, struct LineMask *mask, u32 heapId);
void WIPE_SUB_FlipLineMaskTask(void *task, struct LineMask *mask);
void WIPE_SUB_LineMaskHBlank(struct LineMask *mask);
void WIPE_SUB_BoxStart(struct WipePanel *panel, const struct BoxParam *param);
u32 WIPE_SUB_BoxMain(struct WipePanel *panel);
void WIPE_SUB_BoxInit(struct BoxWork *box, const struct BoxParam *param, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests);
u32 WIPE_SUB_BoxStep(struct BoxWork *box);
void WIPE_SUB_CircleStart(struct WipePanel *panel, const struct CircleParam *param);
u32 WIPE_SUB_CircleMain(struct WipePanel *panel);
void WIPE_SUB_CircleInit(struct CircleWork *circle, const struct CircleParam *param, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests, u32 hblank, u32 heapId);
u32 WIPE_SUB_CircleStep(struct CircleWork *circle);
void WIPE_SUB_CalcCircleSpan(s32 radius, s32 centerX, s32 centerY, s32 y, s32 *left, s32 *right);
void WIPE_SUB_CalcCircleLines(struct CircleWork *circle);
void WIPE_SUB_ShutterStart(struct WipePanel *panel, struct ShutterDesc *desc);
u32 WIPE_SUB_ShutterMain(struct WipePanel *panel);
void WIPE_SUB_ShutterInit(struct ShutterWork *shutter, struct ShutterDesc *desc, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests, u32 hblank, u32 heapId);
u32 WIPE_SUB_ShutterStep(struct ShutterWork *shutter);
void WIPE_SUB_ShutterExit(struct ShutterWork *shutter);
void WIPE_SUB_CalcShutterRows(struct ShutterWork *shutter);
void WIPE_SUB_CalcShutterBand(const struct ShutterBand *band, struct LineMask *mask, s32 num, s32 den);
void WIPE_SUB_SetWindowVisible(u32 value, u32 screen);
void WIPE_SUB_SetWindowInside(u32 planes, u32 effect, u32 window, u32 screen);
void WIPE_SUB_SetWindowOutside(u32 planes, u32 effect, u32 screen);
void WIPE_SUB_SetWindowRect(u32 left, u32 top, u32 right, u32 bottom, int window, int screen);
void WIPE_SUB_RequestWindowVisible(struct WindowRequests *requests, u32 value, u32 screen);
void WIPE_SUB_RequestWindowInside(struct WindowRequests *requests, u32 planes, u32 effect, u32 window, u32 screen);
void WIPE_SUB_RequestWindowOutside(struct WindowRequests *requests, u32 planes, u32 effect, u32 screen);
void WIPE_SUB_RequestWindowRect(struct WindowRequests *requests, u32 left, u32 top, u32 right, u32 bottom, u32 window, u32 screen);
u32 WIPE_SUB_WindowVisibleTask(void *task, struct WindowVisibleRequest *request);
u32 WIPE_SUB_WindowInsideTask(void *task, struct WindowInsideRequest *request);
u32 WIPE_SUB_WindowOutsideTask(void *task, struct WindowOutsideRequest *request);
void WIPE_SUB_WindowRectTask(void *task, struct WindowRectRequest *request);

extern const struct ShutterBand d_0209F570[];
extern struct ShutterDescTable g_020A73D0;
extern struct ShutterDesc g_wipe_slot0;
extern const struct ShutterBand d_0209F56C[];
extern const struct ShutterBand d_0209F574[];
extern const struct ShutterBand d_0209F568[];
extern const char func_02023464_File[];
extern const struct BoxParam d_0209F61C;
extern const struct BoxParam d_0209F628;
extern const struct BoxParam d_0209F5EC;
extern const struct BoxParam d_0209F640;
extern const struct CircleParam d_0209F6B8;
extern const struct CircleParam d_0209F6C4;

/* Program the window registers of one line buffer for the next scanline. */
static inline void SetLineWindow(struct LineBuffers *lines, u32 index, s32 next)
{
    struct LineBuffer *buffer;
    s32 left;
    s32 right;
    u32 window;
    u32 screen;

    buffer = WIPE_SUB_GetLineBuffer(lines, index);
    screen = lines->screen;
    right = buffer->liveRight[next];
    left = buffer->liveLeft[next];
    window = buffer->window;
    if (window == 0) {
        if (screen == 0) {
            if ((DISPSTAT_BASE[0] & 2) != 0) {
                DISPSTAT_BASE[WIN0H_OFFSET] = ((left << 8) & 0xff00) | (u32)(u8)right;
                DISPSTAT_BASE[WIN0V_OFFSET] = 0xc0;
            }
        } else {
            if ((DISPSTAT_BASE[0] & 2) != 0) {
                REG_DB_WIN0H_PTR[0] = ((left << 8) & 0xff00) | (u32)(u8)right;
                REG_DB_WIN0H_PTR[2] = 0xc0;
            }
        }
    } else {
        if (screen == 0) {
            if ((DISPSTAT_BASE[0] & 2) != 0) {
                DISPSTAT_BASE[WIN1H_OFFSET] = ((left << 8) & 0xff00) | (u32)(u8)right;
                DISPSTAT_BASE[WIN1V_OFFSET] = 0xc0;
            }
        } else {
            if ((DISPSTAT_BASE[0] & 2) != 0) {
                REG_DB_WIN1H_PTR[0] = ((left << 8) & 0xff00) | (u32)(u8)right;
                REG_DB_WIN1H_PTR[2] = 0xc0;
            }
        }
    }
}

/* Set the plane masks of one window half for one scanline of the line mask. */
static inline void ApplyLineMaskRow(struct LineMask *mask, struct LineMaskHalf *half, int line)
{
    int value;
    int screen;

    if (half->back[line] == 0) {
        SET_OUTSIDE_PLANES(mask->screen, 0x3F)
        SET_INSIDE_PLANES(mask->screen, half->window, 0x20)
    } else {
        SET_OUTSIDE_PLANES(mask->screen, 0x20)
        SET_INSIDE_PLANES(mask->screen, half->window, 0x3F)
    }
}

/*
 * Sentinel resolver for the dual-screen text cluster: 0xFFFF in the caller's
 * value means "use the object's own default", which lives in the u16 at
 * +0x150, the same sentinel colour slot WIPE_SetBrightnessFadeOut and WIPE_SetMstBrightColor read.
 * Any other value passes through untouched.  Value and result are both u16:
 * a u16 result needs no re-truncation by the caller that feeds it on as u16.
 *
 * The 0xFFFF compare constant costs a pool word rather than a movs/lsls pair
 * because it is compared, not materialised into a store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_ResolveColor.c \
 *       --func WIPE_SUB_ResolveColor --addr 0x020225F4 --cc 1.1p1 --thumb
 */
u16 WIPE_SUB_ResolveColor(struct WipeSys *sys, u16 color)
{
    if (color == 0xFFFF)
        color = sys->color;
    return color;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * WIPE_SUB_GetEndColor picks one of two sub-objects at fixed offsets (0x14, 0x44)
 * of its argument depending on a mode field at +0xc, then returns a
 * halfword out of that sub-object when its own flag at +0x28 is 1, or
 * else falls back to a halfword 0x150 bytes into the *original* argument
 * (0x15 << 4), untouched by the sub-object selection.
 *
 * WIPE_SUB_GetEndColor alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of WIPE_SUB_ResetBrightnessTask, a
 * real, separately meaningful function.  Pairing the two in one
 * translation unit lets `tu` lay out both sections with that fill in
 * between, which reproduces cleanly.
 *
 * WIPE_SUB_ResetBrightnessTask reads a field 0x10 bytes into its second argument and
 * forwards it, with a fixed 0, to WIPE_SetBrightness (whose own second
 * argument it never reads: see src/matched/WIPE_SetBrightness.c), then calls
 * TCB_DeleteTask on the first argument.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02022608.c \
 *       --addr 0x02022608 --thumb
 */
u16 WIPE_SUB_GetEndColor(struct WipeSys *sys)
{
    struct WipePanel *panel;

    if (sys->mainUsed == 1) {
        panel = &sys->mainPanel;
    } else {
        panel = &sys->subPanel;
    }
    if (panel->fadeOut == 1) {
        return panel->color;
    }
    return sys->color;
}

void WIPE_SUB_ResetBrightnessTask(void *task, struct WipePanel *panel)
{
    WIPE_SetBrightness(panel->screen, 0);
    TCB_DeleteTask(task);
}

/*
 * Arms the deferred screen task for one of the two sub-objects WIPE_SYS_Start
 * built, but only for a screen that is still idle: the task handle at +0x28
 * must be null, the resolved sentinel value at +0x24 must be either the
 * pass-through 0x7FFF or zero, and the second handle at +0x2C must be null
 * too.  All three rejections share one epilogue, so the guard is written as a
 * single conjunction rather than a chain of early returns; see
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_RequestBrightnessReset.c \
 *       --func WIPE_SUB_RequestBrightnessReset --addr 0x02022640 --cc 1.1p1 --thumb
 */
void WIPE_SUB_RequestBrightnessReset(struct WipePanel *panel)
{
    if (panel->fadeOut == 0 && (panel->color == 0x7FFF || panel->color == 0) && panel->usesBrightness == 0)
        GFL_USE_AddMainTask((void *)WIPE_SUB_ResetBrightnessTask, panel, 1 << 10);
}

/*
 * Per-screen finaliser, the mirror of the arming path in WIPE_SUB_RequestBrightnessReset: it
 * runs only while the screen is in state 1, its resolved sentinel value at
 * +0x24 is the pass-through 0x7FFF or zero, and the second handle at +0x2C is
 * still null.  It then closes the screen's window through the pointer at
 * +0x10, first the flush at 0x0202223C and then the release thunk at
 * 0x02022224.
 *
 * The +0x10 field is re-read for the second call rather than kept in a
 * register, because the first call can alias it; a cached local would drop
 * the second `ldr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_ApplyEndBrightness.c \
 *       --func WIPE_SUB_ApplyEndBrightness --addr 0x02022670 --cc 1.1p1 --thumb
 */
void WIPE_SUB_ApplyEndBrightness(struct WipePanel *panel)
{
    if (panel->fadeOut == 1 && (panel->color == 0x7FFF || panel->color == 0) && panel->usesBrightness == 0) {
        WIPE_SetBrightnessFadeOut(panel->screen, panel->color);
        WIPE_ResetWndMask((void *)panel->screen);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * WIPE_SUB_ClearSys is five back-to-back MI_CpuFill8 zero-fills over five
 * sub-ranges of one object (sizes 0x14, 0x30, 0x30, 0x18, 0xC0 at offsets
 * 0, 0x14, 0x44, 0x74, 0x8C); it is one of the "0x0209F5xx/0x0209F6xx"
 * cluster's neighbours and clears the object the setup functions in
 * src/matched/WIPE_SUB_PatternBoxOpenOut.c and siblings configure.
 *
 * WIPE_SUB_PatternFadeOut checks a delegate pointer at +0xc, the same guard shape as
 * that cluster: when set, the call forwards to WIPE_SUB_FadeMain and returns
 * its result; the fall-through has to be written on the guard's
 * complement (`== 0`) with the delegate call left unconditional after it,
 * or the two blocks come out in the wrong order.  The fall-through sets
 * the flag pair at +0x28 and +0x2c to (1, 1) and calls WIPE_SUB_FadeStart(p, 1).
 *
 * WIPE_SUB_PatternFadeIn, immediately after this range, is the same shape again
 * with (0, 1) and mode 0 (src/matched/WIPE_SUB_PatternFadeIn.c); it is kept in its
 * own file specifically so that its calls to WIPE_SUB_FadeStart and
 * WIPE_SUB_FadeMain stay outside this range and keep attesting them, and vice
 * versa (docs/MATCHING.md, "the label class" and "the pairwise case across
 * two files").  Bundling all three into one file drops both relocations to
 * MATCH, because each one's only other witness is then inside the same
 * compared range.
 *
 * WIPE_SUB_ClearSys alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of WIPE_SUB_PatternFadeOut, which
 * is a real, separately-matched function and not an unlabelled follower.
 * Pairing the two in one translation unit lets `tu` lay out both sections
 * with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020226A0.c \
 *       --addr 0x020226A0 --thumb
 */
void WIPE_SUB_ClearSys(struct WipeSys *sys)
{
    MI_CpuFill8(sys, 0, 0x14);
    MI_CpuFill8(&sys->mainPanel, 0, 0x30);
    MI_CpuFill8(&sys->subPanel, 0, 0x30);
    MI_CpuFill8(&sys->hblank, 0, 0x18);
    MI_CpuFill8(&sys->windowRequests, 0, 0xC0);
}

/* Fade pattern that covers the screen (brightness goes to white or black; fadeOut = 1). */
u32 WIPE_SUB_PatternFadeOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        panel->fadeOut = 1;
        panel->usesBrightness = 1;
        WIPE_SUB_FadeStart(panel, 1);
        return 0;
    }
    return WIPE_SUB_FadeMain(panel);
}

/*
 * Same shape as WIPE_SUB_PatternFadeOut in src/matched/unit_020226A0.c, and kept in
 * its own file for the same reason: its calls to WIPE_SUB_FadeStart and
 * WIPE_SUB_FadeMain have to stay outside that unit's compared range to attest
 * its calls, and vice versa.  Sets the flag pair at +0x28 and +0x2c to
 * (0, 1) instead of (1, 1) and calls WIPE_SUB_FadeStart(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternFadeIn.c \
 *       --func WIPE_SUB_PatternFadeIn --addr 0x020226FC --cc 1.1p1 --thumb
 */
/* Fade pattern that uncovers the screen (brightness comes back from white or black; fadeOut = 0). */
u32 WIPE_SUB_PatternFadeIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        panel->fadeOut = 0;
        panel->usesBrightness = 1;
        WIPE_SUB_FadeStart(panel, 0);
        return 0;
    }
    return WIPE_SUB_FadeMain(panel);
}

/*
 * wipe.c (docs/families/wipe.h): the slot-0 member of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC (template: WIPE_SUB_PatternShutterDownIn).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 9 out under 1.1p1 and 1 out
 * under every 2.0 build, docs/notes/pkt_0202271C.c.txt): the pool carries
 * 0x020A73D0 TWICE (0x02022750 for the store, 0x02022754 for the argument),
 * so two source-level names were in play. The slot store goes through
 * g_020A73D0 and the argument is a second extern, g_wipe_slot0, at the same
 * address. With one name 1.1p1 CSEs both uses into r5 (push {r3, r4, r5,
 * lr}); with two it reloads each from its own pool word under push {r4, lr}.
 * Same finding as src/matched/BRIGHTNESS_ChangeReset.c in the same module, whose
 * header explains why the bytes fix the number of names but not whether the
 * original had one object or two declarations of it. For the other three
 * slots the two uses differ by the slot offset, so one name suffices there.
 */
/* Shutter pattern, edge moves down, covers the screen (descriptor 0 of g_020A73D0, closing = 1). */
void WIPE_SUB_PatternShutterDownOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        g_020A73D0.descs[0].bands = d_0209F570;
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_ShutterStart(panel, &g_wipe_slot0);
        panel->fadeOut = 1;
        panel->usesBrightness = 0;
    } else {
        WIPE_SUB_ShutterMain(panel);
    }
}

/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to WIPE_SUB_ShutterStart.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternShutterDownIn.c  *       --func WIPE_SUB_PatternShutterDownIn --addr 0x02022758 --thumb --cc 1.1p1
 */
/* Shutter pattern, edge moves down, uncovers the screen (descriptor 2, closing = 0). */
void WIPE_SUB_PatternShutterDownIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        g_020A73D0.descs[2].bands = d_0209F56C;
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_ShutterStart(panel, &g_020A73D0.descs[2]);
        panel->fadeOut = 0;
        panel->usesBrightness = 0;
    } else {
        WIPE_SUB_ShutterMain(panel);
    }
}

/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to WIPE_SUB_ShutterStart.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternShutterUpOut.c  *       --func WIPE_SUB_PatternShutterUpOut --addr 0x02022790 --thumb --cc 1.1p1
 */
/* Shutter pattern, edge moves up, covers the screen (descriptor 4, closing = 1). */
void WIPE_SUB_PatternShutterUpOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        g_020A73D0.descs[4].bands = d_0209F574;
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_ShutterStart(panel, &g_020A73D0.descs[4]);
        panel->fadeOut = 1;
        panel->usesBrightness = 0;
    } else {
        WIPE_SUB_ShutterMain(panel);
    }
}

/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to WIPE_SUB_ShutterStart.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternShutterUpIn.c  *       --func WIPE_SUB_PatternShutterUpIn --addr 0x020227CC --thumb --cc 1.1p1
 */
/* Shutter pattern, edge moves up, uncovers the screen (descriptor 5, closing = 0). */
void WIPE_SUB_PatternShutterUpIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        g_020A73D0.descs[5].bands = d_0209F568;
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_ShutterStart(panel, &g_020A73D0.descs[5]);
        panel->fadeOut = 0;
        panel->usesBrightness = 0;
    } else {
        WIPE_SUB_ShutterMain(panel);
    }
}

/*
 * One of a run of near-identical setup functions on one object
 * (WIPE_SUB_PatternBoxOpenOut, WIPE_SUB_PatternBoxOpenIn, WIPE_SUB_PatternCircleOut, WIPE_SUB_PatternCircleIn,
 * WIPE_SUB_PatternBoxSlideOut, WIPE_SUB_PatternBoxSlideIn, each its own file so that the sibling
 * calls to the shared helpers stay outside the compared range and keep
 * attesting them; see docs/MATCHING.md, "the label class").
 *
 * Checks a delegate pointer at +0xc: when set, the whole call forwards to
 * WIPE_SUB_BoxMain and returns.  That arm has to be written as the
 * fall-through (the guard on the complement, `== 0`, with the delegate
 * call left unconditional after it): the mirror phrasing, guarding
 * `!= 0` with the delegate inside the guarded block, lays the blocks out
 * in the opposite order and does not reproduce.  The fall-through calls
 * WIPE_SetBackColor with the object's id field at +0x24, then WIPE_SUB_BoxStart
 * with the object pointer and a second, unattested pool constant
 * (0x0209F61C, written as a plain integer literal since nothing in this
 * function's own range names it as a symbol), and finally sets the pair
 * of flag words at +0x28 (to 1) and +0x2c (to 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxOpenOut.c \
 *       --func WIPE_SUB_PatternBoxOpenOut --addr 0x02022804 --cc 1.1p1 --thumb
 */
/* Box pattern, visible window shrinks from the right edge to nothing (covers the screen). */
void WIPE_SUB_PatternBoxOpenOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_BoxStart(panel, &d_0209F61C);
        panel->fadeOut = 1;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_BoxMain(panel);
}

/*
 * Same shape as src/matched/WIPE_SUB_PatternBoxOpenOut.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F628.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxOpenIn.c \
 *       --func WIPE_SUB_PatternBoxOpenIn --addr 0x02022830 --cc 1.1p1 --thumb
 */
/* Box pattern, visible window grows from nothing to the full screen (uncovers the screen). */
void WIPE_SUB_PatternBoxOpenIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_BoxStart(panel, &d_0209F628);
        panel->fadeOut = 0;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_BoxMain(panel);
}

/*
 * Same shape as src/matched/WIPE_SUB_PatternBoxOpenOut.c, but the helper pair is
 * WIPE_SUB_CircleStart / WIPE_SUB_CircleMain instead of WIPE_SUB_BoxStart / WIPE_SUB_BoxMain;
 * kept in its own file for the same reason (the sibling calls to the
 * shared helpers have to stay outside the compared range to attest them).
 * Sets the flag pair to (1, 0) and stashes the constant 0x0209F6B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternCircleOut.c \
 *       --func WIPE_SUB_PatternCircleOut --addr 0x0202285C --cc 1.1p1 --thumb
 */
/* Circle pattern, visible circle shrinks from radius 256 to nothing (covers the screen). */
void WIPE_SUB_PatternCircleOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_CircleStart(panel, &d_0209F6B8);
        panel->fadeOut = 1;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_CircleMain(panel);
}

/*
 * Same shape as src/matched/WIPE_SUB_PatternCircleOut.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F6C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternCircleIn.c \
 *       --func WIPE_SUB_PatternCircleIn --addr 0x02022888 --cc 1.1p1 --thumb
 */
/* Circle pattern, visible circle grows from nothing to radius 256 (uncovers the screen). */
void WIPE_SUB_PatternCircleIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_CircleStart(panel, &d_0209F6C4);
        panel->fadeOut = 0;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_CircleMain(panel);
}

/*
 * Same shape as src/matched/WIPE_SUB_PatternBoxOpenOut.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (1, 0) and stashes the constant 0x0209F5EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxSlideOut.c \
 *       --func WIPE_SUB_PatternBoxSlideOut --addr 0x020228B4 --cc 1.1p1 --thumb
 */
/* Box pattern, hiding curtain grows from the left edge across the screen (covers the screen). */
void WIPE_SUB_PatternBoxSlideOut(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_BoxStart(panel, &d_0209F5EC);
        panel->fadeOut = 1;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_BoxMain(panel);
}

/*
 * Same shape as src/matched/WIPE_SUB_PatternBoxSlideOut.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F640.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxSlideIn.c \
 *       --func WIPE_SUB_PatternBoxSlideIn --addr 0x020228E0 --cc 1.1p1 --thumb
 */
/* Box pattern, hiding curtain shrinks back to the left edge (uncovers the screen). */
void WIPE_SUB_PatternBoxSlideIn(struct WipePanel *panel)
{
    if (panel->phase == 0) {
        WIPE_SetBackColor(panel->color);
        WIPE_SUB_BoxStart(panel, &d_0209F640);
        panel->fadeOut = 0;
        panel->usesBrightness = 0;
        return;
    }
    WIPE_SUB_BoxMain(panel);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * WIPE_SUB_CalcStep is a 16-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): it computes
 * (b - a) << 7 and forwards it with the third argument straight to
 * _s32_div_f.  The pool word carries no Thumb bit and the branch is a
 * plain `bx` rather than `blx`, so the callee is declared `arm`; the image
 * labels it as a real function reached from 161 other call sites.
 *
 * WIPE_SUB_AddRect is a plain four-word running-sum accumulator.  It does not
 * fold into an ldm/stm pair the way a whole-object assignment would
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), because each field is
 * added rather than copied.
 *
 * Compiling WIPE_SUB_AddRect on its own comes out EXACT* against `one`: its
 * own extent runs to the 2-byte linker fill in front of WIPE_SUB_InitRectInterp,
 * which is a real function and not an unlabelled follower.  Pairing it
 * with WIPE_SUB_CalcStep in one translation unit lets `tu` lay out both
 * sections with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202290C.c \
 *       --addr 0x0202290C --thumb
 */
s32 WIPE_SUB_CalcStep(s32 start, s32 end, s32 frames)
{
    return _s32_div_f((end - start) << 7, frames);
}

void WIPE_SUB_AddRect(struct FixedRect *dst, struct FixedRect *src)
{
    dst->left += src->left;
    dst->top += src->top;
    dst->right += src->right;
    dst->bottom += src->bottom;
}

/*
 * wipe.c: seeds a four-channel fade.  cur = from << 7 (fixed point), end =
 * to, step = WIPE_SUB_CalcStep(from, to, frames) per channel; called from
 * WIPE_SUB_BoxInit with (obj, &obj->f20, &obj->f10, cfg, cfg + 4, frames).
 * WIPE_SUB_CalcStep returns its tail callee's value here (the unit that
 * matched it declares it void; the caller stores r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_InitRectInterp.c  *       --func WIPE_SUB_InitRectInterp --addr 0x02022940 --thumb --cc 1.1p1
 */
void WIPE_SUB_InitRectInterp(struct FixedRect *current, struct FixedRect *target, struct FixedRect *step,
                   const u8 *from, const u8 *to, s32 frames)
{
    current->left = from[0] << 7;
    current->top = from[1] << 7;
    current->right = from[2] << 7;
    current->bottom = from[3] << 7;
    target->left = to[0];
    target->top = to[1];
    target->right = to[2];
    target->bottom = to[3];
    step->left = WIPE_SUB_CalcStep(from[0], to[0], frames);
    step->top = WIPE_SUB_CalcStep(from[1], to[1], frames);
    step->right = WIPE_SUB_CalcStep(from[2], to[2], frames);
    step->bottom = WIPE_SUB_CalcStep(from[3], to[3], frames);
}

/*
 * The constructor of the wipe task whose per-frame step is WIPE_SUB_FadeMain:
 * it allocates and zeroes the 0x24-byte sub-object, picks the pair of
 * start/end extents from the task's direction flag and the sentinel in
 * +0x24, fills the sub-object's eight words and registers the per-frame
 * callback WIPE_SUB_FadeVTask with GFL_USE_AddMainTask at priority 0x80.
 *
 * The 0x7FFF in +0x24 is a "no explicit extent" sentinel: when it is
 * present the moving edge starts at 0x10 (or ends there, depending on the
 * direction flag) and the other edge starts at 0; when it is absent both
 * edges start at 0 and the moving one is biased by -0x10.  The four arms
 * are written out separately, which is what gives four `b` to the shared
 * continuation rather than a computed pair
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Both extents reach the sub-object scaled by 128 (`lsls #7`), i.e. as
 * 24.7 fixed point, while the unscaled values stay in r7/r6 for the
 * WIPE_SUB_CalcStep call and the +0x1c store.
 *
 * The direction test is written `dir == 0` first: the image's `bne` at
 * +0x2e takes the SECOND arm, so the zero case is the fall-through and
 * therefore the source's first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  Written the
 * other way round every byte from +0x2e to +0x4a is wrong -- the four arm
 * bodies come out in the mirrored order and r6/r7 trade roles -- while
 * everything before and after stays identical, which is exactly the
 * signature that says polarity rather than shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_FadeStart.c \
 *       --func WIPE_SUB_FadeStart --addr 0x020229A4 --cc 1.1p1 --thumb
 */
void WIPE_SUB_FadeStart(struct WipePanel *panel, u32 closing)
{
    struct FadeState *fade;
    s32 startBrightness;
    s32 endBrightness;

    panel->work = GFL_HEAP_Alloc((u16)panel->heapId, 0x24, 0, func_02023464_File,
                                0x09AC);
    MI_CpuFill8(panel->work, 0, 0x24);
    fade = panel->work;

    endBrightness = 0;
    if (closing == 0) {
        if (panel->color == 0x7FFF) {
            startBrightness = 0x10;
        } else {
            startBrightness = endBrightness;
            startBrightness = startBrightness - 0x10;
        }
    } else {
        if (panel->color == 0x7FFF) {
            startBrightness = endBrightness;
            endBrightness = 0x10;
        } else {
            startBrightness = endBrightness;
            endBrightness = endBrightness - 0x10;
        }
    }

    WIPE_SetBrightness(panel->screen, startBrightness);

    fade->stepsLeft = panel->frames;
    fade->frameLimit = panel->wait;
    fade->frame = 0;
    fade->value = startBrightness << 7;
    fade->target = endBrightness << 7;
    fade->delta = WIPE_SUB_CalcStep(startBrightness, endBrightness, panel->frames);
    fade->screen = panel->screen;
    fade->brightness = startBrightness;
    panel->phase = panel->phase + 1;
    fade->task = GFL_USE_AddMainTask((void *)WIPE_SUB_FadeVTask, fade, 0x80);
}

/*
 * The per-frame step of a wipe task, the sibling of WIPE_SUB_BoxMain at the
 * other end of the family: the same four-phase switch over the task's
 * +0x0c, the same sub-object slot at +0x14, and the same terminal phase 3
 * that is the only one to answer 1.  Phase 1 polls WIPE_SUB_FadeStep and
 * advances when it answers 1; phase 2 releases the sub-object's +0x20
 * handle through TCB_DeleteTask, frees the object itself, clears the slot
 * and advances.
 *
 * THE LEVER, and it is shared with WIPE_SUB_FadeMain, WIPE_SUB_ShutterMain and
 * WIPE_SUB_BoxMain (all three sat at exactly two bytes out until it was
 * found; WIPE_SUB_CircleMain in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_FadeMain.c \
 *       --func WIPE_SUB_FadeMain --addr 0x02022A44 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_FadeMain(struct WipePanel *panel)
{
    struct FadeState *fade;
    u32         ret;

    ret = 0;
    fade = panel->work;

    switch (panel->phase) {
    case 1:
        if (WIPE_SUB_FadeStep(fade) == 1) {
            panel->phase = panel->phase + 1;
        }
        break;
    case 2:
        TCB_DeleteTask(fade->task);
        GFL_HEAP_Free(panel->work);
        panel->phase = panel->phase + 1;
        panel->work = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}

int WIPE_SUB_FadeStep(struct FadeState *fade)
{
    int done = 0;

    fade->frame++;
    if (fade->frame >= fade->frameLimit) {
        fade->frame = 0;
        if (fade->stepsLeft - 1 > 0) {
            fade->stepsLeft--;
            fade->value += fade->delta;
        } else {
            fade->value = fade->target;
            done = 1;
        }

        fade->brightness = fade->value / 128;
    }

    return done;
}

/*
 * Re-verified 2026-09-23: the MATCH park had turned DIFF (one byte) under
 * the new extents because its header named the callee 0x020202CC.  The
 * pool word at 0x02022ACC is 0x020222CD: the callee is 0x020222CC
 * (src/matched/WIPE_SetBrightness.c, labelled with sixteen outside branches),
 * so the old "unlabelled leaf, sole reference" blocker was a digit slip.
 * With the address corrected the site resolves `label` and the file is
 * EXACT.
 *
 * An unlabelled leaf forwarder: it drops its own first argument and calls
 * WIPE_SetBrightness with the two pointer fields at +0x18 and +0x1c of its
 * second.  The ordinary tail-call form, a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_FadeVTask.c \
 *       --func WIPE_SUB_FadeVTask --addr 0x02022AC4 --cc 1.1p1 --thumb
 */
void WIPE_SUB_FadeVTask(void *task, struct FadeState *fade)
{
    WIPE_SetBrightness(fade->screen, fade->brightness);
}

/*
 * The four pool words at 0x02022CDC are 0x04000006, 0x04000004,
 * 0x04001040 and 0x04001042: I/O register addresses, written as cast
 * constants, not relocations.
 *
 * The 8-byte residue docs/notes/WIPE_SUB_WindowRectHBlank.c.txt records at +0x00CC
 * is closed by ONE statement order: block two must read ctl->sel BEFORE
 * its three array reads, exactly as blocks one and three do.  With
 * sel read last (the note's C) the 0x180 constant is hoisted one slot
 * early and the y[] address lands in r0 instead of r1; with sel first
 * the block is byte-identical to its two neighbours.
 */
void WIPE_SUB_WindowRectHBlank(struct LineBuffers *lines)
{
    s32 line;
    s32 next;

    line = REG_VCOUNT;
    if (line >= 0xc0) {
        return;
    }
    next = line + 1;
    if (next > 0xbf) {
        next -= 0xc0;
    }

    if (lines->count == 1) {
        SetLineWindow(lines, 0, next);
        return;
    }

    SetLineWindow(lines, 0, next);
    SetLineWindow(lines, 1, next);
}

/*
 * Allocates the line buffers of a work object and fills in its header.
 * windowSelect 0 or 1 gives one 0x604-byte buffer that drives hardware
 * window 0 or 1; windowSelect 2 gives two buffers (0xC08 bytes) that drive
 * window 0 and window 1.  Any other value does nothing.
 */
void WIPE_SUB_CreateLineBuffers(struct LineBuffers *lines, u32 windowSelect, u32 screen, u32 heapId)
{
    int i;
    struct LineBuffer *buffer;

    switch (windowSelect) {
    case 0:
    case 1:
        buffer = GFL_HEAP_Alloc((u16)heapId, 0x604, 0, func_02023464_File, 0xA9B);
        lines->count = 1;
        lines->buffers = buffer;
        lines->screen = screen;
        buffer->window = windowSelect;
        break;
    case 2:
        buffer = GFL_HEAP_Alloc((u16)heapId, 0xC08, 0, func_02023464_File, 0xAA3);
        lines->buffers = buffer;
        lines->count = 2;
        lines->screen = screen;
        for (i = 0; i < 2; i++) {
            lines->buffers[i].window = i;
        }
        break;
    }
}

/*
 * Blocked: 02022D78 (thumb, from header) has no witness outside 02022D70..02022D78. Every concrete byte reproduces.
 * closed:   blocker FIELD_SOUND_SYSTEM_StartFadeInTask.c is now a manifest entry (matched class)
 */
void WIPE_SUB_DeleteLineBuffers(struct LineBuffers *lines)
{
    WIPE_SUB_FreeLineBuffers(lines);
}

/*
 * closed:   blocker FIELD_SOUND_SYSTEM_FadeInTask.c is now a manifest entry (matched class)
 *
 * Releases the object the node's first word points at and clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIPE_SUB_FreeLineBuffers.c \
 *       --func WIPE_SUB_FreeLineBuffers --addr 0x02022D78 --thumb --cc 1.1p1
 */
void WIPE_SUB_FreeLineBuffers(struct LineBuffers *lines)
{
    GFL_HEAP_Free(lines->buffers);
    lines->buffers = 0;
}

/*
 * Index into a flat array whose base pointer is the first field of
 * `obj`, with a fixed 0x604-byte stride.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_GetLineBuffer.c \
 *       --func WIPE_SUB_GetLineBuffer --addr 0x02022D88 --cc 1.1p1 --thumb
 */
struct LineBuffer *WIPE_SUB_GetLineBuffer(struct LineBuffers *lines, u32 index)
{
    return &lines->buffers[index];
}

void WIPE_SUB_FlipLineBuffersTask(void *task, struct LineBuffers *lines)
{
    s32 i;

    for (i = 0; i < lines->count; i++) {
        struct LineBuffer *buffer = WIPE_SUB_GetLineBuffer(lines, i);
        MI_CpuCopy8(buffer->stagedLeft, buffer->liveLeft, 0x300);
    }
    TCB_DeleteTask(task);
}

/*
 * End of a wipe.  Without the closing flag (the screen is uncovered again)
 * the window enable bits are switched off.  With it (the screen stays
 * covered) the window is left on with an empty rectangle, the plane mask 0x3F
 * inside window 0 and only the backdrop plane (0x20) outside, so the whole
 * screen stays hidden.  Every change goes through a request task.
 */
void WIPE_SUB_RequestWindowEnd(u32 closing, struct WindowRequests *requests, u32 screen)
{
    if (closing == 0) {
        WIPE_SUB_RequestWindowVisible(requests, 0, screen);
        return;
    }
    WIPE_SUB_RequestWindowVisible(requests, 1, screen);
    WIPE_SUB_RequestWindowInside(requests, 0x3f, 0, 0, screen);
    WIPE_SUB_RequestWindowRect(requests, 0, 0, 0, 0, 0, screen);
    WIPE_SUB_RequestWindowOutside(requests, 0x20, 0, screen);
}

/*
 * Programs one hardware window: the plane mask inside it, the plane mask
 * outside all windows and its rectangle.  With queued == 0 the registers are
 * written now; otherwise the three parts go through request tasks that write
 * them at a fixed point of the frame.  Called with the pattern's parameters
 * once, when the wipe starts.
 *
 * The two arms are written out in full rather than factored, which is
 * what keeps them as two separate three-call sequences with their own
 * epilogues rather than one tail-merged tail
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
void WIPE_SUB_SetupWindow(struct WindowRequests *requests, u32 insidePlanes, u32 outsidePlanes, u32 window, u32 screen,
                   u32 left, u32 top, u32 right, u32 bottom, u32 queued)
{
    if (queued == 0) {
        WIPE_SUB_SetWindowInside(insidePlanes, 0, window, screen);
        WIPE_SUB_SetWindowOutside(outsidePlanes, 0, screen);
        WIPE_SUB_SetWindowRect(left, top, right, bottom, window, screen);
    } else {
        WIPE_SUB_RequestWindowInside(requests, insidePlanes, 0, window, screen);
        WIPE_SUB_RequestWindowOutside(requests, outsidePlanes, 0, screen);
        WIPE_SUB_RequestWindowRect(requests, left, top, right, bottom, window, screen);
    }
}

void WIPE_SUB_SetWindowVisibleMode(struct WindowRequests *requests, u32 value, u32 screen, u32 queued)
{
    if (queued == 0) {
        WIPE_SUB_SetWindowVisible(value, screen);
    } else {
        WIPE_SUB_RequestWindowVisible(requests, value, screen);
    }
}

/*
 * Clears a line mask (0x30c bytes) and sets which hardware window each half
 * drives, how many halves are used (1 or 2) and the screen it is for.
 */
void WIPE_SUB_InitLineMask(struct LineMask *mask, u32 screen, u32 halfCount, u32 window0, u32 window1)
{
    MI_CpuFill8(mask, 0, 0x30c);
    if (halfCount == 1) {
        mask->half[0].window = window0;
        mask->halfCount = halfCount;
        mask->screen = screen;
        return;
    }
    mask->half[0].window = window0;
    mask->half[1].window = window1;
    mask->halfCount = halfCount;
    mask->screen = screen;
}

void *WIPE_SUB_RequestLineMaskFlip(struct LineMask *mask)
{
    return GFL_USE_AddMainTask(WIPE_SUB_FlipLineMaskTask, mask, 0x3FF);
}

void WIPE_SUB_RequestLineMaskHBlank(u32 hblank, struct LineMask *mask, u32 heapId)
{
    WIPE_RequestSetHBlankSlot(hblank, (u32)mask, (u32)WIPE_SUB_LineMaskHBlank, mask->screen, heapId);
}

void WIPE_SUB_RequestLineMaskHBlankEnd(u32 hblank, struct LineMask *mask, u32 heapId)
{
    WIPE_RequestClearHBlankSlot(hblank, mask->screen, heapId);
}

void WIPE_SUB_FlipLineMaskTask(void *task, struct LineMask *mask)
{
    int i;

    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(mask->half[i].back, mask->half[i].front, 0xC0);
    }
    TCB_DeleteTask(task);
}


/*
 * The per-scanline window programmer of the wipe family (1284 bytes with
 * both literal pools; no relocations at all, every pool word is a
 * hardware register address or a mask).  It reads VCOUNT, steps to the
 * next line (wrapping at 0xC0) and, for one or both of the two 0x184-byte
 * halves of the object, sets the outside-window plane mask (0x3F on a
 * clear row, 0x20 on a set one) and then the window-0 or window-1 inside
 * mask (chosen by the half's +0x180 word) on the MAIN engine when the
 * byte at +0x309 is 0 and on the SUB engine otherwise.
 *
 * Four facts closed it (the 2026-09-21 note was 140 bytes short):
 *  - The +0x309 arms are NOT identical: the zero arm writes the main
 *    engine's WININ/WINOUT at 0x04000048/0x0400004A, reached as
 *    0x04000004 + 0x44/0x46 off the already-loaded DISPSTAT address, and
 *    the other arm the sub engine's 0x04001048/0x0400104A.  With both
 *    arms spelled the same mwcc cross-jumps them, which was the whole
 *    deficit.
 *  - The +0x309 byte is read BEFORE the +0x180 word at every WININ
 *    leaf, so the engine is bound to a local ahead of the window test.
 *  - The second half's base is a NAMED local `h = &p->h[1]`: passed
 *    inline, mwcc folds p + 0x184 + n + 0xC0 into one offset and the
 *    +0x180 word into p + 0x304; the image materialises p + 0x184 once.
 *  - The body is wrapped in `if (n < 0xC0)`, which lets the exit branch
 *    reuse a leaf's branch island (`bge` to 0x02022FE6) instead of a
 *    blt/b pair; and the window-1 mask is `~0x3F00` (pool word
 *    0xFFFFC0FF), not 0xC0FF.
 */
void WIPE_SUB_LineMaskHBlank(struct LineMask *mask)
{
    int line;
    struct LineMaskHalf *half;

    line = REG_VCOUNT;
    if (line < 0xC0) {
        line = line + 1;
        if (line > 0xBF)
            line -= 0xC0;

        if (mask->halfCount == 1) {
            ApplyLineMaskRow(mask, &mask->half[0], line);
        } else {
            ApplyLineMaskRow(mask, &mask->half[0], line);
            half = &mask->half[1];
            ApplyLineMaskRow(mask, half, line);
        }
    }
}

/*
 * Starts one countdown wipe: allocates the 0x4c-byte object on the heap
 * named by the low half of the task's +0x20 word, parks it at +0x14, hands
 * the task's saved parameters to WIPE_SUB_BoxInit, opens the display side
 * through WIPE_SUB_SetWindowVisibleMode with mode 1 or 2 by the caller's cfg[8], and
 * advances the task's phase.  __FILE__ is "wipe_sub.c" at 0x020A7450,
 * __LINE__ 0xc7c.
 *
 * The notes carried an r4/r6 tie (o against cfg) that 3800 permuter
 * compiles never moved.  It was not an allocation tie: the WIPE_SUB_SetWindowVisibleMode
 * call is written out in BOTH arms of the cfg[8] test, with 1 and 2 as
 * literals, and mwcc cross-jumps the two calls, leaving `movs r1,#1 / b /
 * movs r1,#2` in front of one shared call.  A `mode` local assigned in
 * the if/else puts the test value in r1 and swaps r4/r6 for the whole
 * function (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
void WIPE_SUB_BoxStart(struct WipePanel *panel, const struct BoxParam *param)
{
    struct BoxWork *box;

    box = GFL_HEAP_Alloc((u16)panel->heapId, 0x4c, 0, func_02023464_File, 0xc7c);
    panel->work = box;

    WIPE_SUB_BoxInit(box, param, panel->frames, panel->wait, panel->screen, panel->windowRequests);

    if (param->window == 0) {
        WIPE_SUB_SetWindowVisibleMode(panel->windowRequests, 1, box->screen, box->closing);
    } else {
        WIPE_SUB_SetWindowVisibleMode(panel->windowRequests, 2, box->screen, box->closing);
    }

    panel->phase = panel->phase + 1;
}

/*
 * The per-frame step of the wipe/transition task set up at 0x02023464.
 * The task block keeps its phase at +0x0c and the sub-object it allocated
 * at +0x14.  Phase 1 polls WIPE_SUB_BoxStep and, once that answers 1, hands
 * the sub-object's +0x44 field to WIPE_SUB_RequestWindowEnd and advances; phase 2
 * frees the sub-object (GFL_HEAP_Free), clears the slot and advances;
 * phase 3 is the terminal phase and is the only one that answers 1, which
 * is how the caller learns the transition has finished.  Phase 0 and any
 * other value answer 0 and do nothing.
 *
 * THE LEVER, and it is shared with WIPE_SUB_FadeMain, WIPE_SUB_ShutterMain and
 * WIPE_SUB_BoxMain (all three sat at exactly two bytes out until it was
 * found; WIPE_SUB_CircleMain in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_BoxMain.c \
 *       --func WIPE_SUB_BoxMain --addr 0x020234C0 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_BoxMain(struct WipePanel *panel)
{
    struct BoxWork *box;
    u32   ret;

    ret = 0;
    box = panel->work;

    switch (panel->phase) {
    case 1:
        if (WIPE_SUB_BoxStep(box) == 1) {
            WIPE_SUB_RequestWindowEnd(box->closing, panel->windowRequests, panel->screen);
            panel->phase = panel->phase + 1;
        }
        break;
    case 2:
        GFL_HEAP_Free(box);
        panel->phase = panel->phase + 1;
        panel->work = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}

/*
 * wipe_sub.  Closed 2026-09-24 (wave 21, lane E2) from the DIFF 2 recorded
 * in docs/notes/WIPE_SUB_BoxInit.c.txt.  Two matching levers carry it:
 *   - the zero is an enum-typed local (docs/idioms/an-enum-typed-zero-keeps-
 *     its-own-web-where-a-u32-zero-is-folded.md), read in image order k8, z,
 *     kb;
 *   - a5 is read through a volatile access placed after the f40 store and
 *     before the f44 store.  That puts a5's load (r0, the call's first
 *     argument) inside kb's live range, so kb can no longer take r0 and the
 *     zero does, while the f48 store stays last.  A plain copy of a5 is
 *     propagated back to the f48 store and does nothing (12 out).
 */
void WIPE_SUB_BoxInit(struct BoxWork *box, const struct BoxParam *param, u32 frames, u32 wait, u32 screen,
                   struct WindowRequests *windowRequests)
{
    u32 window;
    u32 closing;
    BoxTickInit zero;
    struct WindowRequests *requests;
    WIPE_SUB_InitRectInterp(&box->rect, &box->target, &box->step, param->from, param->to, frames);
    window = param->window;
    zero = BOX_TICK_ZERO;
    closing = param->closing;
    box->screen = screen;
    box->tick = zero;
    requests = *(struct WindowRequests * volatile *)&windowRequests;
    box->closing = closing;
    box->window = window;
    box->stepsLeft = frames;
    box->period = wait;
    box->windowRequests = requests;
    WIPE_SUB_SetupWindow(requests, param->insidePlanes, param->outsidePlanes, param->window, screen, param->from[0], param->from[1],
                  param->from[2], param->from[3], box->closing);
}

/*
 * One tick of the wipe object.  +0x40 is a frame counter compared against
 * the step length at +0x3c: until it reaches the step, nothing happens
 * and the answer is 0.  On a step boundary the counter resets and the
 * remaining-step count at +0x38 is decremented; while steps remain the
 * interpolator at +0x10 is advanced (WIPE_SUB_AddRect) and the current
 * position is pushed to WIPE_SUB_RequestWindowRect with each of the three 1/128
 * fixed-point coordinates at +0x00, +0x04, +0x08 rounded toward zero
 * (`(v + (v >> 6 >> 25)) >> 7`, the compiler's signed /128), plus the
 * 1/128 scalar at +0x0c.  When the last step is used up the object jumps
 * straight to its final values (+0x2c, +0x20, +0x24, +0x28) and answers
 * 1, which is what WIPE_SUB_BoxMain waits for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_BoxStep.c \
 *       --func WIPE_SUB_BoxStep --addr 0x02023568 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_BoxStep(struct BoxWork *box)
{
    s32 tick;

    tick = box->tick + 1;
    box->tick = tick;
    if (tick >= box->period) {
        box->tick = 0;
        tick = box->stepsLeft - 1;
        if (tick > 0) {
            box->stepsLeft = tick;
            WIPE_SUB_AddRect(&box->rect, &box->step);
            goto step;
        }

        WIPE_SUB_RequestWindowRect(box->windowRequests, box->target.left, box->target.top, box->target.right, box->target.bottom, box->window,
                      box->screen);
        return 1;

    step:
        WIPE_SUB_RequestWindowRect(box->windowRequests, box->rect.left / 128, box->rect.top / 128, box->rect.right / 128,
                      box->rect.bottom / 128, box->window, box->screen);
    }

    return 0;
}

/*
 * cap: the call at +0036 to WIPE_SUB_CircleInit (0x0202368C) is the only reference
 *      to that address outside its own body, and it is inside this range, so
 *      the `label` class refuses it.  All 76 bytes and the other relocation
 *      site (GFL_HEAP_Alloc) reproduce exactly.  Promotes to EXACT the moment
 *      WIPE_SUB_CircleInit has its own manifest entry.
 */
void WIPE_SUB_CircleStart(struct WipePanel *panel, const struct CircleParam *param)
{
    panel->work = GFL_HEAP_Alloc((u16)panel->heapId, 0x38, 0, func_02023464_File, 0x0D63);
    WIPE_SUB_CircleInit(panel->work, param, panel->frames, panel->wait, panel->screen, panel->windowRequests, panel->hblank, panel->heapId);
    panel->phase = panel->phase + 1;
}

/*
 *           reproduces (verified with match.py one), the sole unresolved
 *           relocation is the THM_CALL to WIPE_SUB_CircleStep ((struct Wipe_02022E20 *)(0202363C..0202368C
 *           has no outside witness for it)). WIPE_SUB_CircleStep itself is a real
 *           DIFF near miss (see docs/notes/WIPE_SUB_CircleStep.c.txt), not an
 *           EXACT/MATCH file, so it cannot supply a "matched" witness and
 *           the two cannot be folded into one tu unit yet.
 *
 * Dispatch on the +0xc mode word of a record: mode 1 closes the record's
 * +0x14 entry (via WIPE_SUB_CircleStep) and, once it reports the entry now empty,
 * frees the pair at entry+0x2c/entry+0x30 through WIPE_SUB_RequestWindowEnd (with the
 * record's own +0x10 as the third argument) and bumps +0xc, returning 0;
 * mode 2 tears the +0x14 entry down through WIPE_SUB_DeleteLineBuffers/GFL_HEAP_Free,
 * clears +0x14, bumps +0xc and falls into the same "return 1" tail as mode
 * 3 (mode 3 alone has no other side effect); anything else, and mode 1
 * without the entry becoming empty, returns 0.
 */
u32 WIPE_SUB_CircleMain(struct WipePanel *panel)
{
    struct CircleWork *circle = panel->work;
    u32 result = 0;

    switch (panel->phase) {
    case 1:
        if (WIPE_SUB_CircleStep(circle) == 1) {
            WIPE_SUB_RequestWindowEnd(circle->closing, circle->windowRequests, panel->screen);
            panel->phase = panel->phase + 1;
        }
        break;
    case 2:
        WIPE_SUB_DeleteLineBuffers(&circle->lines);
        GFL_HEAP_Free(panel->work);
        panel->phase = panel->phase + 1;
        panel->work = 0;
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    default:
        break;
    }

    return result;
}

void WIPE_SUB_CircleInit(struct CircleWork *circle, const struct CircleParam *param, u32 frames, u32 wait,
                   u32 screen, struct WindowRequests *windowRequests, u32 hblank, u32 heapId)
{
    s32 radiusStep;
    struct LineBuffer *buffer;
    s32 leftEdge;
    s32 rightEdge;

    radiusStep = WIPE_SUB_CalcStep(param->startRadius, param->endRadius, frames);
    WIPE_SUB_CreateLineBuffers(&circle->lines, param->window, screen, heapId);
    circle->radius = param->startRadius << 7;
    circle->windowRequests = windowRequests;
    circle->centerX = param->centerX;
    circle->centerY = param->centerY;
    circle->radiusStep = radiusStep;
    circle->stepsLeft = frames;
    circle->frameLimit = wait;
    circle->frame = 0;
    circle->hblank = hblank;
    circle->heapId = heapId;
    circle->closing = param->closing;
    WIPE_SUB_CalcCircleLines(circle);
    GFL_USE_AddMainTask(WIPE_SUB_FlipLineBuffersTask, circle, 0x3ff);
    buffer = WIPE_SUB_GetLineBuffer(&circle->lines, 0);
    leftEdge = buffer->stagedLeft[0];
    rightEdge = buffer->stagedRight[0];
    WIPE_SUB_SetupWindow(windowRequests, param->insidePlanes, param->outsidePlanes, param->window,
                  screen, leftEdge, 0, rightEdge, 0xc0, circle->closing);
    if (param->window == 0) {
        WIPE_SUB_SetWindowVisibleMode(windowRequests, 1, screen, circle->closing);
    } else {
        WIPE_SUB_SetWindowVisibleMode(windowRequests, 2, screen, circle->closing);
    }
    WIPE_RequestSetHBlankSlot(circle->hblank, (u32)circle, (u32)WIPE_SUB_WindowRectHBlank, screen, heapId);
}

/*
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of WIPE_SUB_ShutterStep at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through WIPE_SUB_CalcCircleLines
 * and re-arms the callback WIPE_SUB_FlipLineBuffersTask at priority 0x3FF; a countdown
 * that has reached zero finishes through WIPE_RequestClearHBlankSlot and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like WIPE_SUB_ShutterStep this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_CircleStep.c \
 *       --func WIPE_SUB_CircleStep --addr 0x02023768 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_CircleStep(struct CircleWork *circle)
{
    s32 frame;
    s32 stepsLeft;

    frame = circle->frame + 1;
    circle->frame = frame;
    if (frame >= circle->frameLimit) {
        circle->frame = 0;
        stepsLeft = circle->stepsLeft - 1;
        if (stepsLeft > 0) {
            circle->stepsLeft = stepsLeft;
            circle->radius = circle->radius + circle->radiusStep;
            WIPE_SUB_CalcCircleLines(circle);
            GFL_USE_AddMainTask((void *)WIPE_SUB_FlipLineBuffersTask, circle, 0x3FF);
        } else {
            WIPE_RequestClearHBlankSlot(circle->hblank, circle->lines.screen, circle->heapId);
            return 1;
        }
    }

    return 0;
}

/*
 * Compiled to 146 bytes; the listing's inferred 148-byte extent (to
 * 0x0202384C, the next labelled function) runs 2 bytes past what the
 * compiler actually emits here, never a byte difference: EXACT*.
 *
 * Fixed-point vertical-band test: a0/128 (signed division, the classic
 * sign-spread rounding-toward-zero idiom) is a limit compared against the
 * absolute difference of two row indices a2/a3. If the row distance
 * reaches or exceeds the limit, both outputs are zeroed and the function
 * returns immediately (void; the original never sets a return value on
 * either path). If the row distance is inside the limit, the function
 * computes
 * sqrt(round(limit'^2) - round(dist'^2)) where limit' = limit<<12 and
 * dist' = |a3-a2|<<12, each square taken in 64 bit through the compiler's
 * signed multiply helper _ll_mul (contract r0:r1 * r2:r3 -> r0:r1, see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md)
 * and each rounded by +0x800 before its own >>12 splice. FX_Sqrt of the
 * difference gives a radius r (already >>12'd back to a plain s32 by the
 * asrs after the call); *out0 = a1 - r (clamped to 0) and
 * *out1 = *out0 + 2*r (clamped to 0xff).
 */
void WIPE_SUB_CalcCircleSpan(s32 radius, s32 centerX, s32 centerY, s32 y, s32 *left, s32 *right)
{
    s32 limit = radius / 128;
    s32 dist = y - centerY;
    s32 halfWidth;

    if (dist < 0) {
        dist = -dist;
    }

    if (dist >= limit) {
        *left = 0;
        *right = 0;
        return;
    }

    {
        s64 limitSquared = (s64)(limit << 12) * (s64)(limit << 12);
        s64 distSquared  = (s64)(dist  << 12) * (s64)(dist  << 12);
        s32 limitRounded = (s32)((limitSquared + 0x800) >> 12);
        s32 distRounded = (s32)((distSquared  + 0x800) >> 12);

        halfWidth = FX_Sqrt(limitRounded - distRounded) >> 12;
    }

    *left = centerX - halfWidth;
    if (*left < 0) {
        *left = 0;
    }
    *right = *left + halfWidth * 2;
    if (*right > 0xff) {
        *right = 0xff;
    }
}

/*
 * Rebuilds the wipe's per-scanline window table, one row for each of the
 * screen's 0xC0 lines.  WIPE_SUB_GetLineBuffer hands back the buffer whose two s16
 * arrays live at +0x300 (left edge) and +0x480 (right edge).  Inside the
 * band (f14, 2*f14] the pair is mirrored from row 2*f14 - y; everywhere
 * else it is computed through WIPE_SUB_CalcCircleSpan.
 *
 * Two facts closed it (the notes stood at 98 bytes against 104):
 *  - WIPE_SUB_CalcCircleSpan's THIRD argument is w->f14, the value still live in r2
 *    from the band test, not 0.  That was the "re-load" the notes chased.
 *  - The guard is an if / else-if / else chain with the call written out
 *    in BOTH outer arms; mwcc cross-jumps the two copies, leaving the
 *    `bgt` over a `b` at +0x16 and hoisting &l into r7
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * EXACT* only because the 102-byte body is followed by two bytes of
 * alignment padding before WIPE_SUB_ShutterStart.
 */
void WIPE_SUB_CalcCircleLines(struct CircleWork *circle)
{
    struct LineBuffer *buffer;
    s32 y;
    s32 left;
    s32 right;

    y = 0;
    buffer = WIPE_SUB_GetLineBuffer(&circle->lines, 0);

    do {
        if (y <= circle->centerY) {
            WIPE_SUB_CalcCircleSpan(circle->radius, circle->centerX, circle->centerY, y, &left, &right);
        } else if (y <= circle->centerY * 2) {
            left = buffer->stagedLeft[circle->centerY * 2 - y];
            right = buffer->stagedRight[circle->centerY * 2 - y];
        } else {
            WIPE_SUB_CalcCircleSpan(circle->radius, circle->centerX, circle->centerY, y, &left, &right);
        }
        buffer->stagedLeft[y] = (s16)left;
        buffer->stagedRight[y] = (s16)right;
        y = y + 1;
    } while (y < 0xC0);
}

/*
 * The constructor of the wipe task whose per-frame step is WIPE_SUB_ShutterMain:
 * it allocates the 0x334-byte sub-object from the task's own heap id,
 * zeroes it, hands the task's five parameter words to WIPE_SUB_ShutterInit and
 * advances the phase.  The sibling of WIPE_SUB_BoxStart (which builds the
 * 0x4c-byte object at the other end of the family) and of WIPE_SUB_CircleStart.
 *
 * 0x334 is past every Thumb immediate, and it is needed TWICE (the
 * allocation size and the memset length), so it is materialised once into
 * a callee-saved register (movs #0xcd / lsls #2) and reused rather than
 * spelled at each site; writing it as a literal at both sites costs a pool
 * word.  That is what makes r6 live across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_ShutterStart.c \
 *       --func WIPE_SUB_ShutterStart --addr 0x020238B4 --cc 1.1p1 --thumb
 */
void WIPE_SUB_ShutterStart(struct WipePanel *panel, struct ShutterDesc *desc)
{
    panel->work = GFL_HEAP_Alloc((u16)panel->heapId, 0x334, 0, func_02023464_File, 0x1354);
    MI_CpuFill8(panel->work, 0, 0x334);
    WIPE_SUB_ShutterInit(panel->work, desc, panel->frames, panel->wait, panel->screen, panel->windowRequests, panel->hblank,
                  panel->heapId);
    panel->phase = panel->phase + 1;
}

/*
 * The per-frame step of a wipe task, the third of the family's four
 * identical phase machines (WIPE_SUB_FadeMain, WIPE_SUB_BoxMain, this one and
 * WIPE_SUB_ShutterStart): the same switch over the task's +0x0c, the same
 * sub-object slot at +0x14, the same terminal phase 3.
 *
 * The two far fields at +0x324 and +0x32c are past every Thumb immediate
 * reach, so both are addressed with a register offset built once
 * (movs #0xc9 / lsls #2 = 0x324) and then bumped by 8 for the second
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); reading them as
 * two separate far offsets would cost a second pool word.
 *
 * THE LEVER, and it is shared with WIPE_SUB_FadeMain, WIPE_SUB_ShutterMain and
 * WIPE_SUB_BoxMain (all three sat at exactly two bytes out until it was
 * found; WIPE_SUB_CircleMain in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_ShutterMain.c \
 *       --func WIPE_SUB_ShutterMain --addr 0x0202390C --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_ShutterMain(struct WipePanel *panel)
{
    struct ShutterWork *shutter;
    u32         ret;

    ret = 0;
    shutter = panel->work;

    switch (panel->phase) {
    case 1:
        if (WIPE_SUB_ShutterStep(shutter) == 1) {
            WIPE_SUB_RequestWindowEnd(shutter->closing, shutter->windowRequests, panel->screen);
            panel->phase = panel->phase + 1;
        }
        break;
    case 2:
        WIPE_SUB_ShutterExit(shutter);
        GFL_HEAP_Free(panel->work);
        panel->phase = panel->phase + 1;
        panel->work = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}

/*
 * The setup of the 0x334-byte scanline wipe object (struct ShutterWork): clears it through WIPE_SUB_InitLineMask, fills both
 * 0xC0-row tables with 1 or 0 by the descriptor's +6 halfword, stamps ten
 * words at +0x30c..+0x330 in the image's (non-ascending) order, installs
 * the scanline callback through WIPE_SUB_RequestLineMaskHBlank and arms the window.
 *
 * The 2026-09-20 note was two bytes long because it called
 * WIPE_SUB_RequestLineMaskHBlank(a0, desc, a3): the image passes (a6, w, a7) -- the
 * sp+0x40 and sp+0x44 stack arguments around the object, matching
 * WIPE_SUB_RequestLineMaskHBlank's own (u32, u8 *, u32) parameter list.  With that call
 * corrected the rest of the note's body compiles byte for byte.
 */
void WIPE_SUB_ShutterInit(struct ShutterWork *shutter, struct ShutterDesc *desc, u32 frames, u32 wait, u32 screen,
                   struct WindowRequests *windowRequests, u32 hblank, u32 heapId)
{
    WIPE_SUB_InitLineMask(&shutter->mask, screen, 1, 0, 0);

    if (desc->closing == 0) {
        MI_CpuFill8(shutter->mask.half[0].front, 1, 0xC0);
        MI_CpuFill8(shutter->mask.half[0].back, 1, 0xC0);
    } else {
        MI_CpuFill8(shutter->mask.half[0].front, 0, 0xC0);
        MI_CpuFill8(shutter->mask.half[0].back, 0, 0xC0);
    }

    shutter->bands = desc->bands;
    shutter->bandCount = desc->bandCount;
    shutter->closing = desc->closing;
    shutter->heapId = heapId;
    shutter->stepBound = frames;
    shutter->step = 0;
    shutter->frameLimit = wait;
    shutter->frame = 0;
    shutter->windowRequests = windowRequests;
    shutter->hblank = hblank;

    WIPE_SUB_RequestLineMaskHBlank(hblank, &shutter->mask, heapId);

    if (desc->closing == 1) {
        WIPE_SUB_SetupWindow(windowRequests, 0x20, 0x3F, 0, screen, 0, 0, 0, 0, desc->closing);
    } else {
        WIPE_SUB_SetupWindow(windowRequests, 0x3F, 0x20, 0, screen, 0, 0, 0, 0, desc->closing);
    }

    WIPE_SUB_SetWindowVisibleMode(windowRequests, 1, screen, shutter->closing);
}

/*
 * The per-frame poll of the 0x334-byte wipe object built by
 * WIPE_SUB_ShutterStart: it ticks the frame counter at +0x320 against the frame
 * limit at +0x31c, and on expiry advances the step index at +0x318
 * against the bound at +0x314.
 *
 * THE COMPARISON IS `<=`, NOT `>`, and it is the function's only real
 * decision.  Written `if (w->step + 1 > w->step_bound)` the function is
 * 92 bytes with every other byte right and ONE wrong: the branch at
 * +0x2a comes out `ble` where the image has `bgt`.  The image branches to
 * the redraw block when step+1 is GREATER than the +0x314 bound, so the
 * fall-through -- the source's first arm -- is the `<=` case, which is
 * the one that calls WIPE_SUB_CalcShutterRows/WIPE_SUB_RequestLineMaskFlip and answers 0
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That makes
 * +0x314 a floor rather than a ceiling: the object is retired while the
 * step index is still inside it and keeps redrawing once it is past,
 * which reads backwards until you notice WIPE_SUB_CalcShutterRows is what pushes
 * the NEXT step in, so "inside the bound" here means "there is another
 * step to load".
 *
 * Every field is past the Thumb immediate reach, so the whole group is
 * addressed off ONE register offset (movs #0x32 / lsls #4 = 0x320) that
 * the compiler then bumps by -4, -8, -0xc and +0x10 per access
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Declaring the
 * fields as members of one struct is what keeps that single base; four
 * separate far offsets would each cost their own pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_ShutterStep.c \
 *       --func WIPE_SUB_ShutterStep --addr 0x02023A50 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_ShutterStep(struct ShutterWork *shutter)
{
    s32 frame;

    frame = shutter->frame + 1;
    shutter->frame = frame;
    if (frame >= shutter->frameLimit) {
        shutter->frame = 0;
        if (shutter->step + 1 <= shutter->stepBound) {
            shutter->step = shutter->step + 1;
            WIPE_SUB_CalcShutterRows(shutter);
            WIPE_SUB_RequestLineMaskFlip(&shutter->mask);
        } else {
            WIPE_SUB_RequestLineMaskHBlankEnd(shutter->hblank, &shutter->mask, shutter->heapId);
            return 1;
        }
    }

    return 0;
}

void WIPE_SUB_ShutterExit(struct ShutterWork *shutter){ }

/*
 * cap: the only call site of WIPE_SUB_CalcShutterBand (0x02023AF4) inside the image is at
 *      0x02023ADA, which is inside this function, so the `label` class refuses
 *      it (no witness outside 02023AB0..02023AF2).  Every byte reproduces:
 *      the listing extent reads 68 only because of two bytes of 00 00 padding
 *      at 0x02023AF2; the code is 66.  Promotes to EXACT the moment
 *      WIPE_SUB_CalcShutterBand has its own manifest entry.
 */
void WIPE_SUB_CalcShutterRows(struct ShutterWork *shutter)
{
    int i;

    for (i = 0; i < shutter->bandCount; i++) {
        WIPE_SUB_CalcShutterBand(&shutter->bands[i], &shutter->mask,
                      shutter->step,
                      shutter->stepBound);
    }
}

/*
 * Paints the run [min(lo,hi), max(lo,hi)) of the 0xC0-byte row table at
 * out+0xC0 with a two-tone pattern: the starting value is the descriptor's
 * +2 halfword when lo <= hi and its logical inverse when the bounds are
 * swapped, and the value flips once at split = (hi - lo) * num / den + lo.
 *
 * The notes' four-register rotation (near in r2 against the image's r7,
 * 13 bytes over eleven spellings and both compilers) came from writing the
 * flip with two HAND-HOISTED constant locals `one`/`zero` and a while
 * loop.  Written plainly -- `near = near == 0` in a for loop, the else
 * arm as `flag == 0` -- mwcc hoists the two constants itself, numbers
 * `near` after the loop's address temporary, and the whole function is
 * byte-exact.  The inline-helper spelling (`if (v == 0) return 1;
 * return 0;`) and `v ? 0 : 1` compile identically.  The bounds are still
 * unsigned (`bhi`), the lo <= hi arm still comes first, and the split is
 * still `q + lo` with q a named local.
 *
 * EXACT* only because the 82-byte body is followed by a two-byte pad.
 */
void WIPE_SUB_CalcShutterBand(const struct ShutterBand *band, struct LineMask *mask, s32 num, s32 den)
{
    u32 start = band->start;
    u32 end = band->end;
    s32 offset = (s32)(end - start) * num / den;
    s32 split = offset + start;
    s32 row;
    s32 limit;
    s32 tone;

    if (start <= end) {
        row = start;
        limit = end;
        tone = band->firstTone;
    } else {
        row = end;
        limit = start;
        tone = band->firstTone == 0;
    }

    for (; row < limit; row++) {
        if (row == split)
            tone = tone == 0;
        mask->half[0].back[row] = tone;
    }
}

void WIPE_SUB_SetWindowVisible(u32 value, u32 screen)
{
    if (screen == 0) {
        REG_DISPCNT = (REG_DISPCNT & 0xffff1fff) | (value << 13);
    } else {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffff1fff) | (value << 13);
    }
}

/*
 * Sets the plane mask inside window 0 or window 1 (WININ of engine A or B).
 * window 0 uses the low six bits and the colour effect bit 0x20; window 1
 * uses bits 8..13 and the colour effect bit 0x2000.  The register is
 * read-modify-written as a volatile halfword.
 */
void WIPE_SUB_SetWindowInside(u32 planes, u32 effect, u32 window, u32 screen)
{
    if (window == 0) {
        if (screen == 0) {
            u32 value = REG_WININ;

            value = (value & ~0x3f) | planes;
            if (effect != 0) {
                value |= 0x20;
            }
            REG_WININ = value;
        } else {
            u32 value = REG_DB_WININ;

            value = (value & ~0x3f) | planes;
            if (effect != 0) {
                value |= 0x20;
            }
            REG_DB_WININ = value;
        }
    } else {
        if (screen == 0) {
            u32 value = REG_WININ;

            value = (value & ~0x3f00) | (planes << 8);
            if (effect != 0) {
                value |= 0x2000;
            }
            REG_WININ = value;
        } else {
            u32 value = REG_DB_WININ;

            value = (value & ~0x3f00) | (planes << 8);
            if (effect != 0) {
                value |= 0x2000;
            }
            REG_DB_WININ = value;
        }
    }
}

void WIPE_SUB_SetWindowOutside(u32 planes, u32 effect, u32 screen)
{
    u32 value;

    if (screen == 0) {
        value = (REG_WINOUT & ~0x3f) | planes;
        if (effect != 0) {
            value |= 0x20;
        }
        REG_WINOUT = (u16)value;
    } else {
        value = (REG_DB_WINOUT & ~0x3f) | planes;
        if (effect != 0) {
            value |= 0x20;
        }
        REG_DB_WINOUT = (u16)value;
    }
}

/*
 * Window-bounds setter: picks one of the four window-bounds register
 * pairs (WIN0H/WIN0V and WIN1H/WIN1V, each in the main or the sub
 * engine) and writes the packed horizontal and vertical limits.
 *
 * The four bodies are textually identical in the original, which is why
 * the value expressions are repeated in each arm rather than hoisted:
 * a shared pair of locals computes once and costs 24 bytes less than the
 * image.  The second halfword is one register plus #4, so each arm holds
 * a pointer to the base register and indexes it [0] and [2]; spelling
 * both addresses absolutely puts two pool words per arm in the image
 * where the original has one.
 *
 * The leading argument shuffle (r4 <- r2, r2 <- r3) is the fourth
 * argument's register being recycled for the fifth.
 */
void WIPE_SUB_SetWindowRect(u32 left, u32 top, u32 right, u32 bottom, int window, int screen)
{
    if (window == 0) {
        if (screen == 0) {
            u16 *reg = (u16 *)0x04000040;
            reg[0] = (left << 8 & 0xff00) | (right & 0xff);
            reg[2] = (top << 8 & 0xff00) | (bottom & 0xff);
        } else {
            u16 *reg = (u16 *)0x04001040;
            reg[0] = (left << 8 & 0xff00) | (right & 0xff);
            reg[2] = (top << 8 & 0xff00) | (bottom & 0xff);
        }
    } else {
        if (screen == 0) {
            u16 *reg = (u16 *)0x04000042;
            reg[0] = (left << 8 & 0xff00) | (right & 0xff);
            reg[2] = (top << 8 & 0xff00) | (bottom & 0xff);
        } else {
            u16 *reg = (u16 *)0x04001042;
            reg[0] = (left << 8 & 0xff00) | (right & 0xff);
            reg[2] = (top << 8 & 0xff00) | (bottom & 0xff);
        }
    }
}

void WIPE_SUB_RequestWindowVisible(struct WindowRequests *requests, u32 value, u32 screen)
{
    struct WindowVisibleRequest *request = &requests->visible[screen];

    request->value = value;
    request->screen = screen;
    GFL_USE_AddMainTask(WIPE_SUB_WindowVisibleTask, request, 1);
}

void WIPE_SUB_RequestWindowInside(struct WindowRequests *requests, u32 planes, u32 effect, u32 window, u32 screen)
{
    struct WindowInsideRequest *request = &requests->inside[screen][window];

    request->planes = planes;
    request->effect = effect;
    request->window = window;
    request->screen = screen;
    GFL_USE_AddMainTask(WIPE_SUB_WindowInsideTask, request, 1);
}

void WIPE_SUB_RequestWindowOutside(struct WindowRequests *requests, u32 planes, u32 effect, u32 screen)
{
    struct WindowOutsideRequest *request = &requests->outside[screen];

    request->planes = planes;
    request->effect = effect;
    request->screen = screen;
    GFL_USE_AddMainTask(WIPE_SUB_WindowOutsideTask, request, 1);
}

void WIPE_SUB_RequestWindowRect(struct WindowRequests *requests, u32 left, u32 top, u32 right, u32 bottom, u32 window, u32 screen)
{
    struct WindowRectRequest *request = &requests->rect[screen][window];

    request->left = left;
    request->top = top;
    request->right = right;
    request->bottom = (u16)bottom;
    request->window = window;
    request->screen = screen;
    GFL_USE_AddMainTask(WIPE_SUB_WindowRectTask, request, 1);
}

/*
 * The two-field member of the WIPE_SUB_WindowOutsideTask/WIPE_SUB_WindowInsideTask forwarder family:
 * unpack the two words of `args` as positional arguments to
 * WIPE_SUB_SetWindowVisible, then tail-call TCB_DeleteTask on the first argument and
 * return its result. `ldm r1, {r0, r1}` is the two-word load; a plain
 * struct-by-value copy or two separate field reads through the pointer
 * both produce the same pair of loads once the fields are consecutive
 * words read in order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_WindowVisibleTask.c \
 *       --func WIPE_SUB_WindowVisibleTask --addr 0x02023D94 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_WindowVisibleTask(void *task, struct WindowVisibleRequest *request)
{
    WIPE_SUB_SetWindowVisible(request->value, request->screen);
    return TCB_DeleteTask(task);
}

/*
 * The four-field member of the WIPE_SUB_WindowOutsideTask/WIPE_SUB_WindowVisibleTask forwarder
 * family: unpack the four words of `args` as positional arguments to
 * WIPE_SUB_SetWindowInside, then tail-call TCB_DeleteTask on the first argument and
 * return its result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_WindowInsideTask.c \
 *       --func WIPE_SUB_WindowInsideTask --addr 0x02023DA8 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_WindowInsideTask(void *task, struct WindowInsideRequest *request)
{
    WIPE_SUB_SetWindowInside(request->planes, request->effect, request->window, request->screen);
    return TCB_DeleteTask(task);
}

/*
 * A three-field struct forwarder: unpack the three words of `args` as
 * positional arguments to WIPE_SUB_SetWindowOutside, then tail-call the ARM function
 * TCB_DeleteTask on the first argument and return its result. The `blx`
 * is the interworking call the linker rewrites a Thumb `bl` into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_WindowOutsideTask.c \
 *       --func WIPE_SUB_WindowOutsideTask --addr 0x02023DC4 --cc 1.1p1 --thumb
 */
u32 WIPE_SUB_WindowOutsideTask(void *task, struct WindowOutsideRequest *request)
{
    WIPE_SUB_SetWindowOutside(request->planes, request->effect, request->screen);
    return TCB_DeleteTask(task);
}

void WIPE_SUB_WindowRectTask(void *task, struct WindowRectRequest *request)
{
    WIPE_SUB_SetWindowRect(request->left, request->top, request->right, request->bottom, request->window, request->screen);
    TCB_DeleteTask(task);
}
