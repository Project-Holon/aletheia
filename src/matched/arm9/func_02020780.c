/*
 * function: BMP_MENULIST_StepCursor
 * address:  0x02020780
 * packet:   pkt_02020780
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_StepCursor.c \
 *       --func BMP_MENULIST_StepCursor --addr 0x02020780 --thumb
 *
 * One cursor step of the scrolling menu list, dir 0 = up, else down.  The
 * cursor row (f42) moves inside the window, skipping items whose value word
 * is -3 (separators), and answers 1; at the window's middle row the list
 * scrolls instead (f40 -= 1 / += 1, cursor parked on the middle row) and it
 * answers 2; at either end of the list it answers 0.  The middle row is
 * rows - (rows/2 + rows%2) - 1 going up and rows/2 + rows%2 going down, 0
 * for a one-row window.
 *
 * Re-derived in wave 13 (the 2026-09-21 note, docs/notes/BMP_MENULIST_StepCursor.c.txt,
 * kept no source).  What pinned the register map obj=r0 row=r4 col=r3
 * rows=r2, which that note could not reach:
 *   - col (f40) is an int local, not u16 (u16 keeps obj out of r0);
 *   - rows is read into its local INSIDE each arm, not before the test
 *     (the image loads +0x12 after `cmp r1, #0`);
 *   - declaration order ncol, col, rows, mid, row (the permuter's
 *     decl-order row<->ncol; row declared first swaps r3/r4).
 * EXACT* only because the listing's extent includes the two bytes of
 * alignment padding after the function.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    u32 unk00;
    u32 unk04;
};

struct Obj {
    struct Elem *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 pad14[0x40 - 0x14];
    u16 f40;
    u16 f42;
};

u8 BMP_MENULIST_StepCursor(struct Obj *obj, u8 dir)
{
    int ncol;
    int col;
    u16 rows;
    u16 mid;
    u16 row;

    row = obj->f42;
    col = obj->f40;
    if (dir == 0) {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows - (rows / 2 + rows % 2) - 1;
        }
        if (col == 0) {
            while (row != 0) {
                row--;
                if (obj->arr[col + row].unk04 != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row > mid) {
            row--;
            if (obj->arr[col + row].unk04 != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col - 1;
    } else {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows / 2 + rows % 2;
        }
        if (col == obj->count - rows) {
            while ((int)row < rows - 1) {
                row++;
                if (obj->arr[col + row].unk04 != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row < mid) {
            row++;
            if (obj->arr[col + row].unk04 != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col + 1;
    }
    obj->f40 = ncol;
    return 2;
}
