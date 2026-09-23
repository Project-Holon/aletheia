/*
 * function: func_0204E180
 * address:  0x0204E180
 * packet:   pkt_0204E180
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A78     0x02146A78  data
 *   func_020463C0  0x020463C0  arm
 *   func_020463D8  0x020463D8  arm
 *   func_020463E0  0x020463E0  arm
 *   func_020436FC  0x020436FC  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02046300  0x02046300  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *
 * textprint.c: draw a u16 string with the fixed 8x8 debug font into
 * pp->bmp at pp->x/pp->y.  Control codes: 1 newline (x back to pp->x, y
 * down by font height + line space), 2 a full-width space (7), 3 a half
 * space; every other code c renders glyph c - 4 into the 0x26-byte context
 * at g_02146A78 and blits it.  The cursor is written back to pp at the end.
 *
 * Shape facts: case 2 is `x = x + width` (the compound form truncates
 * width to u16 first); the loop test is `eom != *str` (cmp operand order);
 * locals declared eom, glyph, width, height so the callee-saved registers
 * land as in the image.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pixels[0x20];
    u8  width;
    u8  pad21;
    u16 x;
    u16 y;
} TextCtx;

typedef struct {
    void *bmp;
    u16 x;
    u16 y;
    u8  letterSpace;
    u8  lineSpace;
    u8  fg : 4;
    u8  bg : 4;
} TextParam;

extern TextCtx *g_02146A78;

extern u32   func_020463C0(void);
extern u32   func_020463D8(void);
extern void  func_020463E0(u32 fg, u32 bg);
extern void *func_020436FC(void *pixels, u32 w, u32 h, u32 depth, u32 heap);
extern u16   func_02045A98(void);
extern void  func_02046300(u32 idx, TextCtx *out);
extern void  func_020439A0(void *src, void *dst, u32 sx, u32 sy, u32 dx, u32 dy,
                           u32 w, u32 h, u32 col);
extern void  func_020437AC(void *bmp);

void func_0204E180(const u16 *str, TextParam *pp)
{
    u16 eom;
    void *glyph;
    u32 width;
    u32 height;
    u16 c;

    height = func_020463C0();
    width = func_020463D8();
    g_02146A78->x = pp->x;
    g_02146A78->y = pp->y;
    func_020463E0(pp->fg, pp->bg);
    glyph = func_020436FC(g_02146A78, 1, 1, 0x20, 0);
    eom = func_02045A98();
    while (eom != *str) {
        c = *str;
        str++;
        switch (c) {
        case 1:
            g_02146A78->x = pp->x;
            g_02146A78->y += (u16)(height + pp->lineSpace);
            break;
        case 2:
            g_02146A78->x = g_02146A78->x + width;
            break;
        case 3:
            g_02146A78->x += (u16)(width / 2);
            break;
        default:
            func_02046300((u16)(c - 4), g_02146A78);
            func_020439A0(glyph, pp->bmp, 0, 0, g_02146A78->x, g_02146A78->y,
                          g_02146A78->width, height, 0);
            g_02146A78->x += (u16)(g_02146A78->width + pp->letterSpace);
            break;
        }
    }
    pp->x = g_02146A78->x;
    pp->y = g_02146A78->y;
    func_020437AC(glyph);
}
