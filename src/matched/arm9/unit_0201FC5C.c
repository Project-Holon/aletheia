/*
 * unit:     yes
 * address:  0x0201FC5C
 * packet:   pkt_0201FC5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BMP_MENU_DrawItems, BMP_MENU_DrawCursor, BMP_MENU_GetItemPixelPos
 * symbols:
 *   func_02045770   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   func_0201C6FC   0x0201C6FC  thumb
 *   BMP_CURSOR_Draw   0x02020D5C  thumb
 *   _s32_div_f      0x0209C0A4  arm
 *
 * bmp_menu.c: the three drawing helpers the constructor BMP_MENU_Create calls.
 *   BMP_MENU_DrawItems  clear the window bitmap to 0xFF and print every item of
 *                  the xmax * ymax grid (column-major index j + i * ymax)
 *                  through the print-util inline (the BMP_CURSOR_Draw shape:
 *                  print via func_0201C6FC, then util->drawn = 1).
 *   BMP_MENU_DrawCursor  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   BMP_MENU_GetItemPixelPos  item index -> pixel position: column = pos / ymax, row =
 *                  pos % ymax.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in BMP_MENU_GetItemPixelPos is `pos % ymax`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (BMP_MENU_CreateYesNo
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` BMP_MENU_DrawCursor needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in BMP_MENU_DrawItems.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct {
    const void *str;    /* +0x00 */
    u32         param;  /* +0x04 */
} BmpMenuWork;

typedef struct {
    void *cell;         /* +0x00 */
    u8    drawn;        /* +0x04 */
} PrintUtil;

typedef struct {
    BmpMenuWork *items; /* +0x00 */
    void *win;          /* +0x04 */
    u8   font;          /* +0x08 */
    u8   xmax;          /* +0x09  columns */
    u8   ymax;          /* +0x0A  rows    */
    u8   lineSpc : 4;   /* +0x0B */
    u8   cDisp   : 2;
    u8   bf0b6   : 2;
    u16  unk0c;         /* +0x0C */
    u16  unk0e;         /* +0x0E */
    u32  unk10;         /* +0x10 */
    PrintUtil *util;    /* +0x14 */
    void *que;          /* +0x18 */
    void *fontH;        /* +0x1C */
    u32  unk20;         /* +0x20 */
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24 */
    u32 cancel;         /* +0x28 */
    u8  pad2c;
    u8  pos;            /* +0x2D */
    u8  width;          /* +0x2E */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xspc;           /* +0x31 */
    u8  yspc;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Desc;
struct Handle;
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void BMP_CURSOR_Draw(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);

static inline void PrintUtil_Print(PrintUtil *util, void *que, s32 x, s32 y, const void *str, void *font)
{
    func_0201C6FC(que, (u32)func_02045770(util->cell), x, y, (void *)str, (u32)font);
    util->drawn = 1;
}

void BMP_MENU_GetItemPixelPos(BmpMenu *m, u8 *x, u8 *y, u8 pos);

void BMP_MENU_DrawItems(BmpMenu *m)
{
    u8 i, j;
    u8 x, step;

    BMP_Clear(func_02045770(m->hdr.win), 0xFF);
    x = m->px;
    step = m->width + m->xspc * 2;
    for (i = 0; i < m->hdr.xmax; i++) {
        for (j = 0; j < m->hdr.ymax; j++) {
            PrintUtil_Print(m->hdr.util, m->hdr.que, x,
                            (u8)(m->py + j * (m->yspc + m->hdr.lineSpc)),
                            m->hdr.items[j + i * m->hdr.ymax].str, m->hdr.fontH);
        }
        x += step;
    }
}

void BMP_MENU_DrawCursor(BmpMenu *m)
{
    u8 x, y;

    if (m->hdr.cDisp != 1) {
        BMP_MENU_GetItemPixelPos(m, &x, &y, m->pos);
        BMP_CURSOR_Draw(m->cursor, x, y, (struct Handle *)m->hdr.util, m->hdr.que, (u32)m->hdr.fontH);
    }
}

void BMP_MENU_GetItemPixelPos(BmpMenu *m, u8 *x, u8 *y, u8 pos)
{
    *x = (pos / m->hdr.ymax) * (m->width + m->xspc * 2);
    *y = m->py + (pos % m->hdr.ymax) * (m->yspc + m->hdr.lineSpc);
}
