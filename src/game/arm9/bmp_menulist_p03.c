/*
 * file:     bmp_menulist_p03.c
 * unit:     yes
 * function: func_0202055C, func_020206C0, func_0202071C, func_02020780
 * address:  0x0202055C
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
 *   func_02045770  0x02045770  arm
 *   func_02045738  0x02045738  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020437DC  0x020437DC  arm
 *   func_02020408  0x02020408  thumb
 *   func_02020CA0  0x02020CA0  thumb
 */
struct Obj_0202055C;
struct Descriptor;
struct Bmp;
struct Desc;
struct Handle;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Elem_0202055C {
    const void *text;
    u32 value;
};

typedef void (*Hook)(struct Obj_0202055C *obj, u32 value, u8 y);

struct Obj_0202055C {
    struct Elem_0202055C *arr;
    u32 unk04;
    Hook hook;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
};

typedef signed short   s16;

struct Obj_020206C0 {
    void *arr;
    void *unk04;
    void *unk08;
    void *unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
    u8 pad24[0x28 - 0x24];
    void *f28;
    void *f2C;
    void *f30;
    u8 pad34[0x3C - 0x34];
    void *f3C;
    u16 f40;
    u16 f42;
};

struct Elem_02020780 {
    u32 unk00;
    u32 unk04;
};

struct Obj_02020780 {
    struct Elem_02020780 *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 pad14[0x40 - 0x14];
    u16 f40;
    u16 f42;
};

extern void *func_02045770(struct Descriptor *win);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_02020408(struct Obj_0202055C *obj, const void *text, u32 x, u32 y, u32 sel);
extern void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
extern void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202055C.c \
 *       --func func_0202055C --addr 0x0202055C --thumb
 *
 * Redraw n + 1 rows of the menu list from item `row`, starting at window
 * row `col`.  When flag is set and row > 0 the window is first scrolled by
 * one row: the band is cleared with func_02043AF4, the item above is
 * redrawn and func_02020CA0 moves the pixels.  Every item goes through the
 * optional per-item hook at +0x08 (obj, item value, y) and then
 * func_02020408 at x = f15, or f14 for a separator (value -3).
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_0202055C.c.txt,
 * 96 out).  That source misread three things, all fixed here from the image:
 * the hook's second argument inside the loop is the item's value word (still
 * live in r1 from the separator test), not 0; func_02020CA0's last argument
 * is (step*2/8) * (func_020437DC(bitmap) / 8), the bitmap's width in tiles,
 * not step >> 3; and the x colour is an int (no truncation after the
 * ternary).  Then the permuter's type:l(step:u8->int) (the value is still
 * (u8)-truncated at its one assignment) swapped the last two stack slots.
 * EXACT* only because the extent includes 2 bytes of padding.
 */
void func_0202055C(struct Obj_0202055C *obj, u16 row, u16 col, u16 n, u32 flag)
{
    int step;
    int x;
    u8 y;
    int i;
    int lim;

    step = (u8)(obj->f22 + obj->f1Amid);
    if (row != 0 && flag != 0) {
        u32 bmp;
        u8 w;
        u8 k;
        x = (obj->arr[row - 1].value != (u32)-3) ? obj->f15 : obj->f14;
        bmp = (u32)func_02045770((struct Descriptor *)obj->unk0C);
        w = func_02045738((struct Descriptor *)obj->unk0C);
        func_02043AF4((struct Bmp *)bmp, 0, 0, (u16)(w * 8),
                      (u16)(obj->f17lo + (col + 1) * step * 2), obj->f18lo);
        y = (u8)(obj->f17lo + col * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row - 1].value, y);
        func_02020408(obj, obj->arr[row - 1].text, x, y, 0);
        k = obj->f18lo;
        func_02020CA0((void *)obj->unk0C, 0, step, (u8)((k << 4) | k),
                      (u16)((step * 2 / 8) * (func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C))) / 8)));
    }
    lim = (u16)(n + 1);
    for (i = 0; i < lim; i++) {
        x = (obj->arr[row].value != (u32)-3) ? obj->f15 : obj->f14;
        y = (u8)(obj->f17lo + (i + col) * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row].value, y);
        func_02020408(obj, obj->arr[row].text, x, y, 1);
        row++;
        if (row >= obj->count)
            return;
    }
}


/*
 * The two redraw entry points of the menu-cursor block, func_020206C0 and
 * func_0202071C, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, f17lo + <row> * (u8)(f22 + f1Amid), to
 * their callee; in func_020206C0 the row is the cursor's own f42 and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * f16), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In func_0202071C the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */
void func_020206C0(struct Obj_020206C0 *obj)
{
    u8 a = obj->f17lo;
    u8 b = obj->f16;
    u8 v = (u8)(a + obj->f42 * (u8)(obj->f22 + obj->f1Amid));

    switch (obj->f1Atop) {
    case 0:
        func_02020D5C(obj->f3C, b, v, obj->f28, obj->f2C, (u32)obj->f30);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

/*
 * The two redraw entry points of the menu-cursor block, func_020206C0 and
 * func_0202071C, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, f17lo + <row> * (u8)(f22 + f1Amid), to
 * their callee; in func_020206C0 the row is the cursor's own f42 and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * f16), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In func_0202071C the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */
void func_0202071C(struct Obj_020206C0 *obj, u32 n)
{
    switch (obj->f1Atop) {
    case 0:
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C)),
                      obj->f16,
                      (s16)(u16)(obj->f17lo + n * (u8)(obj->f22 + obj->f1Amid)),
                      obj->f20,
                      obj->f22,
                      obj->f18lo);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020780.c \
 *       --func func_02020780 --addr 0x02020780 --thumb
 *
 * One cursor step of the scrolling menu list, dir 0 = up, else down.  The
 * cursor row (f42) moves inside the window, skipping items whose value word
 * is -3 (separators), and answers 1; at the window's middle row the list
 * scrolls instead (f40 -= 1 / += 1, cursor parked on the middle row) and it
 * answers 2; at either end of the list it answers 0.  The middle row is
 * rows - (rows/2 + rows%2) - 1 going up and rows/2 + rows%2 going down, 0
 * for a one-row window.
 *
 * Re-derived in wave 13 (the 2026-09-21 note, docs/notes/func_02020780.c.txt,
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
u8 func_02020780(struct Obj_02020780 *obj, u8 dir)
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
