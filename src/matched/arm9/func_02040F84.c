/*
 * unit:     no
 * function: func_02040F84
 * address:  0x02040F84
 * packet:   pkt_02040F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The arbitrary-size cousin of src/matched/func_02040EE0.c: linear screen
 * entry index for (x, y) in a map that is `w` by `h` tiles, laid out as up to
 * four 32-wide/32-tall blocks.  The block is selected by `(x >> 5)` and
 * `(y >> 5)` folded into a single u8 selector, and the switch has cases 0..3
 * only, so the out-of-range dispatch falls straight through to `return base`
 * with base still zero.
 *
 * `w - 32` and `h - 32` are s16 locals, and they double as both the guard and
 * the stride of the right-hand and bottom blocks: a negative value means the
 * map is narrower (shorter) than one block, so block 0 uses `w` (`h`) as its
 * stride and the trailing blocks never exist.  Everything accumulates through
 * u16, which is what every `lsl #16` / `lsr #16` pair in the original is.
 *
 * Three shape notes, each of which cost bytes to find:
 *
 *  - `base += idx;` has to be written out inside both arms of the if/else in
 *    cases 0 and 2 (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *    Factored out after the if/else, the arms become one instruction each and
 *    the compiler if-converts them to `addge`/`mlalt`, which is four bytes
 *    shorter than the original's real branches.  Case 1's if/else really is
 *    predicated, and that is the contrast that names the shape.
 *  - `base` must be the first declaration, or it does not get ip
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 *    with w2 first the whole function comes out with ip, lr and r4 rotated.
 *  - but `base` must be *assigned* zero after `sel`, as a statement rather
 *    than an initialiser, because the original materialises the zero into
 *    sel's register and copies it into base's (`mov r6, #0` then
 *    `mov ip, r6`), not the other way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040F84.c \
 *       --func func_02040F84 --addr 0x02040F84 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

u16 func_02040F84(u32 x, u32 y, u8 w, u32 h)
{
    u16 base;
    s16 w2 = w - 32;
    s16 h2 = h - 32;
    u8  sel = 0;
    u16 idx;

    base = 0;

    if (x >> 5) {
        sel += 1;
    }
    if (y >> 5) {
        sel += 2;
    }

    switch (sel) {
    case 0:
        if (w2 >= 0) {
            idx = x + y * 32;
            base += idx;
        } else {
            idx = x + y * w;
            base += idx;
        }
        break;
    case 1:
        if (h2 >= 0) {
            base += 32 * 32;
        } else {
            base += h * 32;
        }
        idx = (x & 0x1f) + y * w2;
        base += idx;
        break;
    case 2:
        base += w * 32;
        if (w2 >= 0) {
            idx = x + (y & 0x1f) * 32;
            base += idx;
        } else {
            idx = x + (y & 0x1f) * w;
            base += idx;
        }
        break;
    case 3:
        base += (w + h2) * 32;
        idx = (x & 0x1f) + (y & 0x1f) * w2;
        base += idx;
        break;
    }
    return base;
}
