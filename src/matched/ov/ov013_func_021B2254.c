/*
 * function: func_021B2254
 * address:  0x021B2254
 * packet:   pkt_ov013_021B2254
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   func_021B2A20  0x021B2A20  arm  ov013
 */

typedef struct Ctx {
    int f0;
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} Ctx;

extern Ctx d_021B60D8;
extern int d_021B4BD0;
extern int func_021B2A20(int);

int func_021B2254(int a)
{
    int r;

    if (d_021B60D8.state != 3)
        return -2;
    r = func_021B2A20(a);
    if (r == 0)
        return -1;
    d_021B60D8.cb(a, 9, r, d_021B60D8.arg);
    d_021B4BD0--;
    return 0;
}
