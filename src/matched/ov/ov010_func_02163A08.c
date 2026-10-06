/*
 * function: func_02163A08
 * address:  0x02163A08
 * packet:   pkt_ov010_02163A08
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a rectangle (s16 x0, y0, x1, y1) from a map object's width and
 * height getters: x spans x .. x + (w - 1), y spans y - (h - 1) .. y, each
 * size clamped at 0. EXACT* only for the 2-byte pad after the function
 * (54 of 56).
 *
 * pass 3 2026-10-06 P3L05: closed. Key: out->x0 = x is written before
 * out->x1 = x + w. Then x is dead at the add and does not interfere with
 * the sum temp, so x and y simplify in one pass and take r6 / r5 in
 * parameter order. With x1 stored first, x and y swapped registers (6 B).
 * symbols:
 *   func_0216D91C 0x0216D91C thumb ov010
 *   func_0216D924 0x0216D924 thumb ov010
 */
typedef short s16;
extern int func_0216D91C(int p);
extern int func_0216D924(int p);
typedef struct { s16 x0, y0, x1, y1; } Rect;
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
