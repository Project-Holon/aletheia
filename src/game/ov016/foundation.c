/*
 * file:     foundation.c
 * unit:     yes
 * function: func_021D5FE8, func_021D5FF4, func_021D600C
 * address:  0x021D5FE8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

void func_021D5FE8(int a, int b, unsigned short *p);
void func_021D5FF4(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short *p);
void func_021D600C(const COORD *coord, const COORD *size, RECT *rect);

void func_021D5FE8(int a, int b, unsigned short *p)
{
    p[0] = a;
    p[1] = b;
}

/*
 * Write four halfwords through the out pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D5FF4.c \
 *       --func func_021D5FF4 --addr 0x021D5FF4 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D5FF4(unsigned short a, unsigned short b, unsigned short c,
                   unsigned short d, unsigned short *p)
{
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
}


/*
 * sdk:      DWCi_Coord2Rect (libdwcutil.TWL.HYB.a foundation.o)
 *
 * notes:    const inputs let all four halfwords load before the first store.
 */
void func_021D600C(const COORD *coord, const COORD *size, RECT *rect)
{
    rect->l = coord->x;
    rect->t = coord->y;
    rect->r = coord->x + size->x;
    rect->b = coord->y + size->y;
}
