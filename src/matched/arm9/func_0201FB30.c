/*
 * function: BMP_MENU_StepSelection
 * address:  0x0201FB30
 * packet:   pkt_0201FA04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Grid cursor step.  The menu is cols x rows (unk0A wide, unk09 tall) with a
 * one-byte cursor at +0x2d; unk0B bits 2..3 are the wrap flag.  Each of the
 * four directions computes the candidate cell, wraps only when the flag is
 * set, and commits the move only when the entry's second word is not -3.
 * The row/column split needs the real quotient AND remainder, so it reads as
 * one _s32_div_f call per direction, not a division and a modulo.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_StepSelection.c \
 *       --func BMP_MENU_StepSelection --addr 0x0201FB30 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned int   u32;
typedef int            s32;

struct Elem {
    u32 f0;
    s32 f4;
};

struct Obj {
    struct Elem *arr;
    u8  pad_04[5];
    u8  rows;
    u8  cols;
    u8  flags;
    u8  pad_0C[0x21];
    u8  cursor;
};

extern s32 _s32_div_f(s32 num, s32 den);

int BMP_MENU_StepSelection(struct Obj *o, u32 dir)
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
