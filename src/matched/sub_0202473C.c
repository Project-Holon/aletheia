/*
 * function: func_0202473C
 * address:  0x0202473C
 * packet:   pkt_02024344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clamp a counter to the range 1..10, with a mode argument that changes
 * only the zero case: called with `a == 0` and a zero field, the field is
 * reset to 1 and 0 is returned; called with `a != 0` a zero field is left
 * alone and 1 is returned outright, skipping the range check entirely.
 * Every other value goes through the same range test regardless of `a`.
 *
 * The `result` local has to be initialised before either branch reads
 * `*p` (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md): that ordering, not the declaration order, is
 * what keeps the constant 1 resident in one register across both early
 * returns and the range check's shared exit, instead of each arm
 * rematerialising its own `movs r0, #k; bx lr`. The two early returns
 * (the `a != 0` zero case and the `a == 0` zero case) are written as
 * direct `return` statements and stay as separate tails; only the range
 * check's in-range case and the clamp's fallthrough share one exit block,
 * reached by a `goto` from the first and by falling into it from the
 * second, exactly as the original's single `blt` past the clamp and the
 * clamp's own fallthrough both land on one `adds r0, r2, #0; bx lr`.
 *
 * This is wordset.c's normaliser: src/pending/sub_0201EFFC.c calls it and
 * is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202473C.c \
 *       --func func_0202473C --addr 0x0202473C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int           s32;

u32 func_0202473C(u32 *p, u32 a)
{
    u32 result = 1;
    s32 v;

    if (a != 0) {
        v = (s32)*p;
        if (v != 0) {
            goto range;
        }
        return result;
    }
    v = (s32)*p;
    if (v != 0) {
        goto range;
    }
    *p = result;
    return 0;

range:
    if (v < 1) {
        goto clamp;
    }
    if (v < 0xb) {
        goto end;
    }

clamp:
    *p = 1;
    result = 0;

end:
    return result;
}
