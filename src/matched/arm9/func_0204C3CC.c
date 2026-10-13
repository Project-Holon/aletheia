/*
 * function: CLACT_IsRectInView
 * address:  0x0204C3CC
 * packet:   pkt_0204C2C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 2x2-matrix cull test behind CLACT_CullOam (its only caller): transform
 * the four corners (x0,y0) (x0,y1) (x1,y0) (x1,y1) of an OAM rectangle through
 * the matrix m (20.12, rounded +0x800), take min/max per axis, translate by the
 * camera delta (dx, dy) and test against the viewport c->f08 / c->f0c.  Eight
 * arguments: dx, dy, x0, x1 in r0-r3; y0, y1, m, c on the stack.
 *
 * Levers, all measured (wave 10):
 *  - the four translated bounds are added EAGERLY as statements
 *    (`minx += dx; maxx += dx; miny += dy; maxy += dy;`) before the `&&`
 *    chain, same lever as CLACT_IsCellInView; inline in the chain: 41-66 out.
 *  - declaration order `maxx, minx, maxy, miny` and the seed order
 *    `min = p; max = p;` put the minimum in p's register and the maximum in
 *    the copy (r4/lr, sb/r7), as the image has it; any other order swaps the
 *    pair (25-37 out).  Found by tools/permuter.py (decl-order + reorder),
 *    then closed by sweeping all 240 decl/seed orders.
 *  - the umull/mla (not smull) products from the second use of each
 *    coordinate on are the CSE'd `(s64)` sign halves, not a different macro.
 */

typedef unsigned int u32;
typedef int s32;
typedef long long s64;

struct M { s32 f00; s32 f04; s32 f08; s32 f0c; s32 f10; s32 f14; };
struct C { s32 f00; s32 f04; s32 f08; s32 f0c; };

#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))

int CLACT_IsRectInView(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
                  const struct M *m, const struct C *c)
{
    s32 maxx, minx, maxy, miny;
    s32 p;

    p = fxmul(x0, m->f00) + fxmul(y0, m->f08);
    minx = p;
    maxx = p;
    p = fxmul(x0, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y0, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;

    p = fxmul(x0, m->f04) + fxmul(y0, m->f0c);
    miny = p;
    maxy = p;
    p = fxmul(x0, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y0, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;

    minx += dx; maxx += dx; miny += dy; maxy += dy;
    if (maxy > 0 && miny < c->f0c && maxx > 0 && minx < c->f08)
        return 1;
    return 0;
}
