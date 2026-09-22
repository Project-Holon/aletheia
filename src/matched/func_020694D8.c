/*
 * function: func_020694D8
 * address:  0x020694D8
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02068EA0    0x02068EA0  arm
 *
 * The innermost draw step of the text renderer, the function
 * src/matched/func_0206958C.c calls once per line as
 * `func_020694D8(ctx, px, py, w2, cur, &cur, st)`.  It walks one LINE of the
 * string: a character iterator is fetched out of the font object
 * (`ctx->f04`, callback at +4, taking a `const void **` cursor and returning
 * the character code), each character is drawn with func_02068EA0, and the
 * pen is stepped along the step vector by the glyph's advance plus the
 * inter-character gap `ctx->f08`.  The walk stops at NUL or at '\n' (0xa),
 * and the `last` out-parameter receives the cursor position when the stop was
 * a newline and 0 when it was the end of the string -- the identical tail
 * func_02068030 (the measure-one-line sibling at 0x02068030) carries at
 * 0x020680AC..0x020680C0, which is what fixes the polarity here.
 *
 * TWO C LEVERS, both needed, both found by measurement:
 *
 * 1. DECLARATION ORDER `gap` BEFORE `fnt`
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *    The image opens `ldr r4, [fp, #8]` / `ldr r5, [fp, #4]` -- the two
 *    context fields loaded as SEPARATE instructions in DESCENDING offset
 *    order, which is the one order mwccarm's ldm coalescer cannot merge.
 *    Declared the other way round the same two loads fold to a single
 *    `ldmib fp, {r4, r5}`, the whole body shifts one slot earlier and 94 of
 *    180 bytes differ.  Re-ordering the two ASSIGNMENTS does not help (every
 *    permutation was measured: 94, 95 and 97 bytes out); it is the
 *    declaration order that picks r4 for the gap and r5 for the font, and
 *    having picked them the scheduler emits the loads in that order.
 *
 * 2. THE LOOP MUST BE AN EXPLICIT `goto`, NOT A `while`
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *    The image's back edge is `bne #0x206951c` at 0x02069554: it tests only
 *    `c != 0` and jumps back to the `cmp r0, #0xa` at 0x0206951C, so the
 *    newline test is the LOOP TOP and the NUL test is the BOTTOM.  Written as
 *    `while (c != 0xa) { ...; c = next(&cur); if (c == 0) break; }` the
 *    compiler fuses the bottom pair into `cmp r0, #0 / cmpne r0, #0xa`, which
 *    is one instruction and four bytes too many (184 bytes, 59 out) and moves
 *    the `ldrsb r7, [sp, #0x40]` load of st.dx from between the two compares
 *    to after them.  The explicit two-label form below keeps them apart.
 *
 * The compiler pin is the cluster's, `../2.0/sp2`, shared with its packet
 * mates func_0206958C, func_020696F4 and func_02069AC4; see the "kept
 * branches" tell in docs/FRONTEND-PINS.md.  Under dsi/1.1p1 this same source
 * loses the 0x10 frame and the ten-register push.
 *
 * The two trailing `signed char`s are ONE 2-byte struct passed by value, the
 * same Step the whole cluster forwards (see func_02069818's header).
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    void *f00;
    void *f04;
    s32 f08;
    s32 f0C;
} Ctx;

typedef struct {
    signed char dx;
    signed char dy;
} Step;

typedef s32 (*NextFn)(const void **cursor);

extern s32 func_02068EA0(void *a, void *b, s32 x, s32 y, s32 w2, s32 c);

void func_020694D8(Ctx *ctx, s32 x, s32 y, s32 w2,
                   const void *s, const void **last, Step st)
{
    const void *cur;
    s32 gap;
    void *fnt;
    NextFn next;
    s32 c;
    s32 adv;
    s32 dx;
    s32 dy;

    gap = ctx->f08;
    fnt = ctx->f04;
    cur = s;
    next = ((NextFn *)fnt)[1];
    dy = st.dy;
    c = next(&cur);
    if (c == 0) goto done;
    dx = st.dx;
loop:
    if (c == 0xa) goto done;
    adv = gap + func_02068EA0(ctx->f00, fnt, x, y, w2, c);
    x = x + adv * dx;
    y = y + adv * dy;
    c = next(&cur);
    if (c != 0) goto loop;
done:
    if (last != 0) {
        *last = (c == 0xa) ? cur : 0;
    }
}
