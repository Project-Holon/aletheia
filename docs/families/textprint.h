/*
 * docs/families/textprint.h -- shared declarations for the textprint.c
 * family (0x0204E130..0x0204E4C0 in the ARM9 image, ARM, dsi/1.1p1 -O4,p).
 * Anchor: __FILE__ "textprint.c" at 0x020A7F80 (func_0204E130, 0x0204E328).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Evidence:
 * src/matched/func_0204E130.c, func_0204E180.c (wave 15), func_0204E328.c,
 * func_0204E388.c.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The 0x26-byte singleton at g_02146A78 (allocated by func_0204E130). */
typedef struct {
    u8  pixels[0x20];   /* one 8x8 4bpp glyph, filled by func_02046300 */
    u8  width;          /* +0x20 glyph advance, also from func_02046300 */
    u8  pad21;
    u16 x;              /* +0x22 cursor */
    u16 y;              /* +0x24 */
} TextCtx;
extern TextCtx *g_02146A78;

/* The caller's print parameters (func_0204E180). */
typedef struct {
    void *bmp;          /* +0x00 destination bitmap */
    u16 x;              /* +0x04 in: start, out: final cursor */
    u16 y;              /* +0x06 */
    u8  letterSpace;    /* +0x08 */
    u8  lineSpace;      /* +0x09 */
    u8  fg : 4;         /* +0x0A low nibble */
    u8  bg : 4;         /*       high nibble */
} TextParam;

void func_0204E130(u32 a);                         /* create the context */
void func_0204E180(const u16 *str, TextParam *pp); /* draw a string */
void func_0204E328(u32 a0, u32 a1);                /* format, then draw */

/* Font helpers (0x020461F4.., the fixed debug font at g_02146A58). */
u32  func_020463C0(void);                      /* font height */
u32  func_020463D8(void);                      /* full-width advance, 7 */
void func_020463E0(u32 fg, u32 bg);            /* colour masks */
void func_02046300(u32 idx, TextCtx *out);     /* render glyph idx */
