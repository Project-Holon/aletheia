/*
 * file:     bmp_menu_p02.c
 * unit:     yes
 * function: func_0201F5DC, func_0201F614, func_0201F628
 * address:  0x0201F5DC
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
 *   func_0203FB44  0x0203FB44  arm
 *   func_02041300  0x02041300  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

extern u8 func_0201F53C(int i);
extern void *func_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6);
extern void func_0201F57C(u32 a, u32 b, u32 c, u32 d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5,
                          u32 a6);
void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
void func_0201F614(int a, u32 x);
void func_0201F628(u16 id, u8 x, u8 y, u8 w, u8 h, u32 pal, u16 base);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5DC.c \
 *       --func func_0201F5DC --addr 0x0201F5DC --cc 1.1p1 --thumb
 */
void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3)
{
    void *r = func_020496E4(5, func_0201F53C(a2), (u32)a0, 0, 0, a3);

    func_0201F57C((u32)a0, a1, a2, a3);
    return r;
}



void func_0201F614(int a, u32 x)
{
    func_0203FB44((int)a, (u16)x, (u16)(x >> 16));
}



/*
 * A nine-slice window frame draw, the worker behind func_0201F73C
 * (src/matched/func_0201F73C.c).  Eight calls to func_02041300 place tiles
 * base+0, +1, +2, +3, +5, +6, +7, +8 around the rectangle (x, y, w, h); the
 * centre tile base+4 is never emitted, which is why the sequence skips 4.
 * The four corners are 1x1, the top and bottom edges are w x 1, the left and
 * right edges are 1 x h, and every call carries the same palette word.
 *
 * SIGNATURE, pinned by the load widths.  The fifth argument is re-read with
 * `ldrb` from its home slot at sp+0x38 and the sixth with `ldr` from sp+0x3c,
 * so `h` is a byte and `pal` a full word; the seventh is read with `ldrh`
 * from sp+0x40, so `base` is u16.  Declaring `pal` as u8 costs fourteen bytes
 * (262 instead of 276).
 *
 * THREE LEVERS, the last of which closed it:
 *
 *  - **func_02041300's second and third parameters are declared u8 here**,
 *    not u32 as src/pending/func_02041300.c declares them.  With u32 the
 *    truncation of `x - 1` becomes a source-level expression, mwccarm CSEs
 *    the whole `(u8)(x - 1)` and spills the truncated byte to a stack slot;
 *    the image keeps the untruncated `x - 1` in r7 and re-runs the
 *    `lsls #24 / lsrs #24` pair at each of its four uses, which is the
 *    argument-conversion form.  That change alone moves the residue from 228
 *    bytes to 86.  Same tell as
 *    docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 *    seen through the prototype rather than through the call.
 *
 *  - **`x1` and `y1` are computed between the calls that first need them**,
 *    not hoisted to the top: the image interleaves the two `adds` with the
 *    call sequence exactly where the source order puts them.
 *
 *  - **`id` is `u16`, not `u32`.**  This is what the earlier write-up in
 *    docs/notes/func_0201F628.c.txt read as a closed scheduler residue and
 *    told the next reader not to re-attempt.  It is not the scheduler: the
 *    remaining 86 bytes were three `str r5, [sp, #8]` palette stores and the
 *    top-of-function argument spill issued one slot late, and narrowing the
 *    first parameter moves all four.  The narrowing is real, not a trick --
 *    func_0201F73C hands this the result of func_02045730, which
 *    src/matched/func_0201F7A8.c (the sibling that calls func_02041300
 *    directly) already declares as a narrow byte accessor, so the caller
 *    side agrees.  With u32 the value is a fresh full-word value in mwccarm's
 *    value numbering and is created before the three stack-argument stores;
 *    with u16 it is created after them, which is the image's order.
 *    `--explain` reports the whole u32 residue as `r5 -> r0 x2` -- a single
 *    swapped pair, the declaration-level signature of this class.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(id:u32->u16)` at compile 249 of 800:
 *      baseline  DIFF   asm=1220  bytes-out=86  size=276/276
 *      249       EXACT  asm=0     bytes-out=0   size=276/276
 *
 * CONSEQUENCE.  0x0201F628 has exactly one caller image-wide,
 * func_0201F73C, so it could never be attested by the `label` class and no
 * cut creates a witness; now that this file is EXACT the `matched` class
 * carries that site, which is what src/matched/func_0201F73C.c was waiting
 * on.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F628.c \
 *       --func func_0201F628 --addr 0x0201F628 --cc 1.1p1 --thumb
 */
void func_0201F628(u16 id, u8 x, u8 y, u8 w, u8 h, u32 pal, u16 base)
{
    u32 y0;
    u32 x0;
    u32 x1;
    u32 y1;

    y0 = y - 1;
    x0 = x - 1;
    func_02041300(id, base,            x0, y0, 1, 1, pal);
    func_02041300(id, (u16)(base + 1), x,      y0, w, 1, pal);
    x1 = x + w;
    func_02041300(id, (u16)(base + 2), x1, y0, 1, 1, pal);
    func_02041300(id, (u16)(base + 3), x0, y,      1, h, pal);
    func_02041300(id, (u16)(base + 5), x1, y,      1, h, pal);
    y1 = y + h;
    func_02041300(id, (u16)(base + 6), x0, y1, 1, 1, pal);
    func_02041300(id, (u16)(base + 7), x,      y1, w, 1, pal);
    func_02041300(id, (u16)(base + 8), x1, y1, 1, 1, pal);
}
