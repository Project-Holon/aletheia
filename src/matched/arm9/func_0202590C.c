/*
 * function: BMP_OAM_SetPos
 * address:  0x0202590C
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * bmp_oam.c.  The x/y parameters are s16, not int: only the narrow
 * parameter type puts the two spills ahead of the object copy in the
 * prologue.
 * Repositions every cell of the rows x cols grid: each cell
 * gets the base position offset by its column (x, step 32) and its row
 * (y, step 16), passed as a packed s16 pair.
 *
 * symbols:
 *   func_0204B404  0x0204B404  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Point {
    s16 x;
    s16 y;
};

struct Grid {
    u32   pad_0;
    void *a[25];
    void *b[24];
    u16   flags;
    u8    cols;
    u8    rows;
};

struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y)
{
    struct Point pt;
    int i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            pt.x = (s16)(x + (j << 5));
            pt.y = (s16)(y + (i << 4));
            func_0204B404(g->a[j + i * g->cols], (const struct Vec2 *)(&pt), g->flags);
        }
    }
}
