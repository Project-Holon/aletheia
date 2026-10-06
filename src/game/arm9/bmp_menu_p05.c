/*
 * file:     bmp_menu_p05.c
 * unit:     yes
 * function: func_0201FB30, func_0201FC1C, func_0201FC5C, func_0201FD18, func_0201FD54, func_0201FDA0, func_0201FEBC, func_0201FEF4
 * address:  0x0201FB30
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
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_0201C6FC   0x0201C6FC  thumb
 *   func_02020D5C   0x02020D5C  thumb
 *   func_02045B38   0x02045B38  arm
 *   func_0201F81C   0x0201F81C  thumb
 *   func_0201F878   0x0201F878  thumb
 *   func_02045C04   0x02045C04  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02030734   0x02030734  arm
 *   sBmpMenuFile    0x020A7384  data
 *   func_0201D7EC   0x0201D7EC  thumb
 *   func_0201DC80   0x0201DC80  thumb
 *   func_0201C440   0x0201C440  thumb
 *   func_0201F9D0   0x0201F9D0  thumb
 *   func_02045374   0x02045374  arm
 *   func_0201F73C   0x0201F73C  thumb
 *   func_02045730   0x02045730  arm
 *   func_020409B4   0x020409B4  arm
 *   func_02045334   0x02045334  arm
 */
#include "../../matched/include/Obj02590.h"
#include "../../matched/include/Obj02993.h"

struct StrObj;
struct CharBuf;
struct Descriptor;
struct Desc;
struct Handle;
struct PrintSys;
struct Cfg;
struct Font;
struct GfFont;
struct MsgBank;
struct Rec;
struct Slot;
struct Obj;
typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned int   u32;

typedef int            s32;

struct Elem_0201FB30 {
    u32 f0;
    s32 f4;
};

struct Obj_0201FB30 {
    struct Elem_0201FB30 *arr;
    u8  pad_04[5];
    u8  rows;
    u8  cols;
    u8  flags;
    u8  pad_0C[0x21];
    u8  cursor;
};

struct Elem_0201FC1C {
    u32 f0;
    u32 f4;
};

struct Obj_0201FC1C {
    struct Elem_0201FC1C *arr;
    u8   pad[5];
    u8   unk09;
    u8   unk0a;
    u8   pad2[0x11];
    u32  unk1c;
};

typedef unsigned short u16;

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

typedef struct {
    u8  frame;   /* +0 */
    u8  x;       /* +1 */
    u8  y;       /* +2 */
    u8  pal;     /* +3 */
    u16 chr;     /* +4  callers pass it as base */
} WinDat;

typedef signed short s16;

extern s32 _s32_div_f(s32 num, s32 den);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern BmpMenuWork *func_0201F81C(u32 n, u16 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_02045C04(struct Rec *rec);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201DC80(struct Font *p);
extern u32 func_0201C440(void *p);
extern BmpMenu *func_0201F9D0(const BmpMenuHeader *hdr, u32 px, u32 py, u32 pos, u16 heap, u32 cancel);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u8 func_02045730(struct Descriptor *p);
extern void  func_020409B4(u32 layer);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201FA04(struct Obj *o);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020307B0(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201F868(void *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F9E8(struct Obj *o, u8 *out);
void func_0201FC5C(BmpMenu *m);
void func_0201FD18(BmpMenu *m);
void func_0201FD54(BmpMenu *m, u8 *x, u8 *y, u8 pos);
BmpMenu *func_0201FDA0(const WinDat *winDat, u16 base, u8 pal, u8 pos, u16 heap);
u32 func_0201FEBC(u8 *p);
void func_0201FEF4(u8 *o);
extern char  sBmpMenuFile[];



/*
 * Grid cursor step.  The menu is cols x rows (unk0A wide, unk09 tall) with a
 * one-byte cursor at +0x2d; unk0B bits 2..3 are the wrap flag.  Each of the
 * four directions computes the candidate cell, wraps only when the flag is
 * set, and commits the move only when the entry's second word is not -3.
 * The row/column split needs the real quotient AND remainder, so it reads as
 * one _s32_div_f call per direction, not a division and a modulo.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201FB30.c \
 *       --func func_0201FB30 --addr 0x0201FB30 --cc 1.1p1 --thumb
 */
int func_0201FB30(struct Obj_0201FB30 *o, u32 dir)
{
    s8 next;
    u8 cols;
    u8 cur;

    if (dir == 0) {
        cols = o->cols;
        if (cols <= 1) {
            return 0;
        }
        cur = o->cursor;
        if (cur % cols == 0) {
            if ((((u32)o->flags << 24) >> 30) == 0) {
                return 0;
            }
            next = (s8)(cur + (cols - 1));
        } else {
            next = (s8)(cur - 1);
        }
    } else if (dir == 1) {
        cols = o->cols;
        if (cols <= 1) {
            return 0;
        }
        cur = o->cursor;
        if (cur % cols == cols - 1) {
            if ((((u32)o->flags << 24) >> 30) == 0) {
                return 0;
            }
            next = (s8)(cur - (cols - 1));
        } else {
            next = (s8)(cur + 1);
        }
    } else if (dir == 2) {
        u8 rows = o->rows;

        if (rows <= 1) {
            return 0;
        }
        cols = o->cols;
        cur = o->cursor;
        if (cur < cols) {
            if ((((u32)o->flags << 24) >> 30) == 0) {
                return 0;
            }
            next = (s8)(cur + cols * (rows - 1));
        } else {
            next = (s8)(cur - cols);
        }
    } else {
        u8 rows = o->rows;

        if (rows <= 1) {
            return 0;
        }
        cur = o->cursor;
        cols = o->cols;
        if (cur >= cols * (rows - 1)) {
            if ((((u32)o->flags << 24) >> 30) == 0) {
                return 0;
            }
            next = (s8)(cur % cols);
        } else {
            next = (s8)(cur + cols);
        }
    }

    if (o->arr[next].f4 == -3) {
        return 0;
    }
    o->cursor = (u8)next;
    return 1;
}


u32 func_0201FC1C(struct Obj_0201FC1C *o)
{
    u32 best = 0;
    u8 i;

    for (i = 0; i < o->unk09 * o->unk0a; i++) {
        u32 r = (u8)func_0201D304((struct StrObj *)o->arr[i].f0, o->unk1c, 0);

        if (best < r) {
            best = r;
        }
    }
    return best;
}



static inline void PrintUtil_Print(PrintUtil *util, void *que, s32 x, s32 y, const void *str, void *font)
{
    func_0201C6FC(que, (u32)func_02045770(util->cell), x, y, (void *)str, (u32)font);
    util->drawn = 1;
}



/*
 * bmp_menu.c: the three drawing helpers the constructor func_0201F93C calls.
 *   func_0201FC5C  clear the window bitmap to 0xFF and print every item of
 *                  the xmax * ymax grid (column-major index j + i * ymax)
 *                  through the print-util inline (the func_02020D5C shape:
 *                  print via func_0201C6FC, then util->drawn = 1).
 *   func_0201FD18  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   func_0201FD54  item index -> pixel position: column = pos / ymax, row =
 *                  pos % ymax.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in func_0201FD54 is `pos % ymax`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (func_0201FDA0
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` func_0201FD18 needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in func_0201FC5C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void func_0201FC5C(BmpMenu *m)
{
    u8 i, j;
    u8 x, step;

    func_02043B5C(func_02045770(m->hdr.win), 0xFF);
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



/*
 * bmp_menu.c: the three drawing helpers the constructor func_0201F93C calls.
 *   func_0201FC5C  clear the window bitmap to 0xFF and print every item of
 *                  the xmax * ymax grid (column-major index j + i * ymax)
 *                  through the print-util inline (the func_02020D5C shape:
 *                  print via func_0201C6FC, then util->drawn = 1).
 *   func_0201FD18  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   func_0201FD54  item index -> pixel position: column = pos / ymax, row =
 *                  pos % ymax.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in func_0201FD54 is `pos % ymax`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (func_0201FDA0
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` func_0201FD18 needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in func_0201FC5C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void func_0201FD18(BmpMenu *m)
{
    u8 x, y;

    if (m->hdr.cDisp != 1) {
        func_0201FD54(m, &x, &y, m->pos);
        func_02020D5C(m->cursor, x, y, (struct Handle *)m->hdr.util, m->hdr.que, (u32)m->hdr.fontH);
    }
}



/*
 * bmp_menu.c: the three drawing helpers the constructor func_0201F93C calls.
 *   func_0201FC5C  clear the window bitmap to 0xFF and print every item of
 *                  the xmax * ymax grid (column-major index j + i * ymax)
 *                  through the print-util inline (the func_02020D5C shape:
 *                  print via func_0201C6FC, then util->drawn = 1).
 *   func_0201FD18  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   func_0201FD54  item index -> pixel position: column = pos / ymax, row =
 *                  pos % ymax.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in func_0201FD54 is `pos % ymax`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (func_0201FDA0
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` func_0201FD18 needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in func_0201FC5C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void func_0201FD54(BmpMenu *m, u8 *x, u8 *y, u8 pos)
{
    *x = (pos / m->hdr.ymax) * (m->width + m->xspc * 2);
    *y = m->py + (pos % m->hdr.ymax) * (m->yspc + m->hdr.lineSpc);
}



static inline void PrintUtil_Init(PrintUtil *util, void *cell)
{
    util->cell = cell;
    util->drawn = 0;
}



/*
 * bmp_menu.c: the yes/no menu builder (message archive 2 entry 0xE9, a
 * two-item BmpMenuWork list, a BmpMenuHeader filled on the stack, then
 * func_0201F9D0 and the window upload).  docs/notes/pkt_0201FC5C.c.txt.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 284/284, 2 bytes out for
 * five waves: the r3 home store `str r3, [sp, #0x14]` scheduled after
 * `ldr r4, [sp, #0x50]` / `adds r5, r0, #0`): the fifth (stack) parameter
 * is a heap id and is u16, with u16 on the heap parameter of every callee
 * it is passed to.  docs/idioms/a-u16-stack-parameter-passed-to-a-u16-
 * callee-stays-behind-a-spill-store.md is the same lever; with u16 heap
 * and the old u32 prototypes the body narrows at every call.
 */
BmpMenu *func_0201FDA0(const WinDat *winDat, u16 base, u8 pal, u8 pos, u16 heap)
{
    BmpMenuHeader hdr;
    void *msg;
    BmpMenuWork *list;
    BmpMenu *m;

    msg = func_02045B38(0, 2, 0xE9, heap);
    list = func_0201F81C(2, heap);
    func_0201F878((struct Slot *)list, (u32)msg, 0, 0, heap);
    func_0201F878((struct Slot *)list, (u32)msg, 1, -2, heap);
    func_02045C04(msg);

    MI_CpuFill8(&hdr, 0, sizeof(hdr));
    hdr.items = list;
    hdr.win = (void *)func_020450F0(winDat->frame, winDat->x, winDat->y, 7, 4, winDat->pal, 1);
    hdr.xmax = 1;
    hdr.ymax = 2;
    hdr.lineSpc = 1;
    hdr.cDisp = 0;
    hdr.bf0b6 = 0;
    hdr.util = func_02030734(heap, sizeof(PrintUtil), 1, sBmpMenuFile, 0x263);
    hdr.fontH = func_0201D7EC(0x17, 0, 0, 0, heap);
    hdr.unk0e = func_0201DC80(hdr.fontH);
    hdr.unk0c = 10;
    PrintUtil_Init(hdr.util, hdr.win);
    hdr.que = (void *)func_0201C440((void *)heap);
    hdr.unk20 = 0;

    m = func_0201F9D0(&hdr, 0xE, 0, pos, heap, 2);
    func_02045374(hdr.win);
    func_0201F73C(hdr.win, 0, base, pal);
    func_020409B4(func_02045730(hdr.win));
    func_02045334(hdr.win);
    return m;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201FEBC.c \
 *       --func func_0201FEBC --addr 0x0201FEBC --cc 1.1p1 --thumb
 */
u32 func_0201FEBC(u8 *p)
{
    u32 r = func_0201FA04((struct Obj *)p);
    u32 t = func_0201C4E4((struct PrintSys *)(((struct Obj02590 *)p)->f18));

    if (((struct Obj02590 *)p)->f20 == 0 && t != 0) {
        func_02045334((struct Descriptor *)((struct Obj02590 *)p)->f4);
        ((struct Obj02590 *)p)->f20 = 1;
    }
    if (r != 0xffffffff) {
        func_0201FEF4(p);
    }
    return r;
}



void func_0201FEF4(u8 *o)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    func_0201C4C0((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    func_020307B0(((struct Obj02993 *)o)->f14);
    func_0201F7A8(((struct Obj02993 *)o)->f4, 0);
    func_0201D83C(((struct Obj02993 *)o)->f1C);
    func_0201F868(((struct Obj02993 *)o)->f0);
    func_020452E8(((struct Obj02993 *)o)->f4);
    func_0201F9E8((struct Obj *)o, 0);
}
