/*
 * unit:     no
 * function: sub_0202CB4C
 * address:  0x0202CB4C
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020410D0  0x020410D0  arm
 *   g_020A0058     0x020A0058  data
 *
 * The clipped blit of one window record. `mgr->wins` is an array of 16-byte
 * records; the record carries its size as two 6-bit bitfields at +4 and its
 * clip rectangle as four `s8` bounds at +0xc..+0xf. The function parks the
 * requested position in the record, rejects the four fully-outside cases,
 * then narrows the copy on each of the four edges before handing the result
 * to src/matched/func_020410D0.c with its ten arguments (destination x/y,
 * width/height, source pointer, source x/y offset, source width/height).
 * The trailing indirect call dispatches on `mgr->mode` through the table at
 * 0x020A0058; the pool word for that table is attested by the second copy of
 * it at 0x0202CD60, outside this range.
 *
 * Two shape notes, both worth more than they look:
 *
 * 1. The window's own x/y at +6 and +7 must be declared `s8`, not `u8`. With
 *    `u8` fields the compiler notices that `win->x = x` and the later
 *    `sx = x` (sx is `u8`) share the truncation `(u8)x`, computes it once
 *    before the two `strb`s and stores the truncated register, which moves
 *    212 of 268 bytes. With `s8` fields the conversion nodes differ, no CSE
 *    happens, `strb r0` uses the argument register directly and the `(u8)x`
 *    is recomputed at 0x0202CB98 exactly as the original does. See
 *    docs/idioms/signed-and-unsigned-byte-fields-do-not-share-a-truncation.md.
 *
 * 2. None of the four clip bounds or the two bitfield sizes is a named local:
 *    every one of them is spelled as the field expression at each use and
 *    left to CSE. The six spill slots then come out as 0x30 sx, 0x2c ox,
 *    0x28 win->w, 0x24 win->xmax, 0x20 win->h, 0x1c win->ymax. Naming any of
 *    the four costs five to ten bytes of slot renumbering, and no
 *    declaration order recovers it: all 24 orderings of the four names were
 *    tried and the best is five bytes wrong. Only `x + win->w` and
 *    `y + win->h` are named (`x1`, `y1`), and those two stay in registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202CB4C.c \
 *       --func sub_0202CB4C --addr 0x0202CB4C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

struct Win {
    u32 tiles;
    u16 w:6;
    u16 h:6;
    u16 dirty:1;
    u16 unk04_13:3;
    s8 x;
    s8 y;
    u8 pad_08[2];
    u8 bg;
    u8 pad_0b;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
    u16 pad_04;
    u16 mode:15;
    u16 unk06_15:1;
};

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);
extern void (*g_020A0058[])(u32);

void sub_0202CB4C(struct WinMgr *mgr, u32 idx, s32 x, s32 y)
{
    struct Win *win = &mgr->wins[idx];
    u8 sx, ow, ox;
    u8 sy, oh, oy;
    s32 x1, y1;

    win->x = x;
    win->y = y;
    if (x >= win->xmax) {
        return;
    }
    if (y >= win->ymax) {
        return;
    }
    x1 = x + win->w;
    if (x1 < win->xmin) {
        return;
    }
    y1 = y + win->h;
    if (y1 < win->ymin) {
        return;
    }

    sx = x;
    ow = win->w;
    ox = 0;
    if (x < win->xmin) {
        sx = win->xmin;
        ox = win->xmin - x;
        ow = ow - ox;
    }
    if (x1 >= win->xmax) {
        ow = ow - (u8)(x1 - win->xmax);
    }

    sy = y;
    oh = win->h;
    oy = 0;
    if (y < win->ymin) {
        sy = win->ymin;
        oy = win->ymin - y;
        oh = oh - oy;
    }
    if (y1 >= win->ymax) {
        oh = oh - (u8)(y1 - win->ymax);
    }

    func_020410D0(win->bg, sx, sy, ow, oh, win->tiles, ox, oy, win->w, win->h);
    g_020A0058[mgr->mode](win->bg);
    win->dirty = 0;
}
