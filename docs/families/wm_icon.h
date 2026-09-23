/*
 * docs/families/wm_icon.h -- shared declarations for the wm_icon.c family
 * (the wireless-connection icon), 0x02036BD4..0x020371AC in the ARM9 image.
 * The __FILE__ anchor is "wm_icon.c" at 0x020A79F0 (layout/file_anchors.txt,
 * pool sites 0x02036CA0 in func_02036BD4 and 0x02036E6C in func_02036DC8).
 * The run 0x020366C0..0x02036BD4 ahead of it is the net send queue and
 * ring buffer (NetSendItem, Queue020368C0) and is NOT this file.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is derived from an EXACT file in src/matched,
 * named beside it.  Addresses are Black-image addresses.
 *
 * ISA: ARM throughout.  COMPILER: dsi/1.1p1, no pins.
 *
 * ============================================================================
 * THE TWO SDK SHAPES THAT CLOSED WAVE 14 (read before writing C here)
 * ============================================================================
 *  1. OAM writes are the NitroSDK G2_SetOBJAttr inline, not hand-expanded
 *     shifts.  attr01 = (y & 0xff) | mode<<10 | mosaic<<12 | effect |
 *     color<<13 | shape | (x & 0x1ff)<<16 | rs<<25; attr2 = name |
 *     prio<<10 | cparam<<12.  The icon is two 16x16 entries (shape
 *     0x40000000), palette 14 (0xE000); a hidden entry is effect NODISPLAY
 *     0x200 with attr2 0 (the 0x40000200 word).  Hand-expanded, 1.1p1
 *     schedules the x shift differently (31 bytes out); through the inline
 *     it is exact (func_02036CA8).
 *  2. A switch over GXOBJVRamModeChar needs all four 1D labels (0x10,
 *     0x00100010, 0x00200010, 0x00300010) even when 256K shares the
 *     default; with three, mwcc emits a linear chain instead of the
 *     image's binary search pivoted on 0x00100010 (func_02036DC8).
 * ------------------------------------------------------------------------- */

#ifndef WM_ICON_H
#define WM_ICON_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

/* NitroSDK GXOamAttr; func_02036CA8. */
typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

/* ------------------------------------------------------------------ *
 * THE ICON RECORD (0x14 bytes, func_02036BD4 allocates it from heap
 * (b & 0x7fff) | 0x8000 when the caller passes none).
 * ------------------------------------------------------------------ */
struct WmIcon {
    u32 f00;          /* +0x00 char base handed to func_02036DC8; func_02036BD4 */
    u16 x;            /* +0x04 OAM x; func_02036BD4, func_02036CA8 */
    u16 y;            /* +0x06 OAM y */
    u8  pad08[4];
    u8  f0c;          /* +0x0C passed to func_02036F24; func_02036EC8 */
    u8  kind;         /* +0x0D 1 = main-screen rule, 2 = inverted; func_02036D64 */
    u8  busy;         /* +0x0E nonzero: also blank sub OAM; func_02036E80 */
    u8  objWnd;       /* +0x0F ==1: entry 0 is an OBJ-window sprite; func_02036CA8 */
    GXOamAttr *oam;   /* +0x10 where the pair was last written (0x07000000 or
                       *       0x07000400); func_02036BD4 seeds 0x07000000 */
};

/* The override pair and current icon at 0x021469C8; func_02036BD4,
 * func_02037010.  +0x02 is a 14-bit field under a 2-bit mode. */
struct WmIconNotifier {
    u16 x;
    u16 y    : 14;
    u16 mode : 2;
    struct WmIcon *icon;
};
extern struct WmIconNotifier g_021469C8;
extern const char wm_icon_File[];   /* 0x020A79F0 "wm_icon.c" */

/* ------------------------------------------------------------------ *
 * FUNCTIONS (all arm; EXACT file named)
 * ------------------------------------------------------------------ */
struct WmIcon *func_02036BD4(u32 unused, u32 heap, u32 x, u32 y, u32 f0c,
                             struct WmIcon *h, u32 kind, u32 busy, u32 f00);
void func_02036CA8(struct WmIcon *c);     /* write the OAM pair, hide the old one */
u32  func_02036D64(struct WmIcon *c);     /* engine: POWCNT bit 15 vs kind -> 1 or 2 */
u32  func_02036DC8(u32 engine, u32 b);    /* b scaled by the OBJ 1D char mode, fatal
                                           * on 256K via func_02034714(file, 0xfb, ...) */
void func_02036E74(int *p, int v);        /* store v if v < 4 */
void func_02036E80(struct WmIcon *c);     /* blank both OAM pairs, free */
void func_02036EC8(struct WmIcon *c, u32 a, u32 b);
u32  func_02036F04(u32 engine);           /* GX_GetBankForOBJ / SubOBJ */
void func_02036F24(int engine, int b, int heap); /* load the icon graphics */
void func_02036FD8(void);
void func_02037010(u32 a, u32 b, u32 c, u32 d);
void func_020370C8(void);

/* SDK callees (layout/symbols_sdk.txt) */
u32 GX_GetBankForOBJ(void);               /* 0x02080C24 arm */
u32 GX_GetBankForSubOBJ(void);            /* 0x02080C64 arm */

#endif /* WM_ICON_H */
