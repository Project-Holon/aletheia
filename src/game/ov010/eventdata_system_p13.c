/*
 * file:     eventdata_system_p13.c
 * unit:     yes
 * function: func_021639C0, func_02163A08, func_02163A40
 * address:  0x021639C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_0216D91C 0x0216D91C thumb ov010
 *   func_0216D924 0x0216D924 thumb ov010
 */
typedef short s16;

typedef unsigned char  u8;

typedef struct { s16 x0, y0, x1, y1; } Rect;

extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern int func_021641F8(int a);
extern void func_02163994();
extern u8 func_0216D91C(int a0);
extern u8 func_0216D924(int a0);
void func_021639C0(int a, int b);
void func_02163A08(int p, int x, int y, Rect *out);
int func_02163A40(s16 *a, s16 *b);


void func_021639C0(int a, int b)
{
    s16 x, z;
    int y;

    x = func_0216D83C((void *)a) + func_021641E8(b);
    y = func_0216D854((void *)a);
    z = func_0216D86C((void *)a) + func_021641F8(b);
    func_02163994(a, x, y, z, b);
}

/*
 * Builds a rectangle (s16 x0, y0, x1, y1) from a map object's width and
 * height getters: x spans x .. x + (w - 1), y spans y - (h - 1) .. y, each
 * size clamped at 0. EXACT* only for the 2-byte pad after the function
 * (54 of 56).
 *
 * pass 3 2026-10-06 P3L05: closed. Key: out->x0 = x is written before
 * out->x1 = x + w. Then x is dead at the add and does not interfere with
 * the sum temp, so x and y simplify in one pass and take r6 / r5 in
 * parameter order. With x1 stored first, x and y swapped registers (6 B).
 */
void func_02163A08(int p, int x, int y, Rect *out)
{
    s16 w;
    s16 h;
    w = func_0216D91C(p) - 1;
    if (w < 0) w = 0;
    out->x0 = x;
    out->x1 = x + w;
    h = func_0216D924(p) - 1;
    if (h < 0) h = 0;
    out->y0 = y - h;
    out->y1 = y;
}

/*
 * Tests whether two rectangles (s16 x0, y0, x1, y1) overlap: per axis the
 * longer interval comes first, then either end of the shorter one must lie
 * inside it. Leaf, no calls. EXACT* only for the 2-byte pad after the
 * function (174 of 176).
 *
 * Key: each axis is a block with its own locals, and the second block
 * declares them in a different order (big0, big1, sm0, sm1, lo1, hi1, lo2,
 * hi2, d1, d2). Declaration order sets the colouring order of the second
 * axis (d1 after lo2); the first block keeps d1, d2, lo1, ... order.
 * Earlier 15 B residue (shared locals) was only the d1/lo2 register swap.
 */
int func_02163A40(s16 *a, s16 *b)
{
    {
        s16 d1, d2, lo1, hi1, lo2, hi2, big0, big1, sm0, sm1;
        lo1 = a[0]; hi1 = a[2]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[0]; hi2 = b[2]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    {
        s16 big0, big1, sm0, sm1, lo1, hi1, lo2, hi2, d1, d2;
        lo1 = a[1]; hi1 = a[3]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[1]; hi2 = b[3]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    return 1;
fail:
    return 0;
}
