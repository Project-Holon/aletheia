/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02025BEC
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02025BEC, sub_02025C1C, sub_02025C30
 *
 * func_02025BEC is a three-argument predicate: out of range (`a >= 0xE9`)
 * fails immediately; otherwise it looks `a` up through sub_02025B64
 * (src/pending/sub_02025B64.c, parked at MATCH) and fails if the result
 * is below `b`; otherwise, when `c == 1`, it fails unless `a` is one of
 * two special-cased values (0x69 or 0). Every early exit is a direct
 * `return`, not a shared tail, because each guard sits right after the
 * comparison that produces it with nothing in between
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-
 * conjunction.md does not apply here: the guards are not adjacent, they
 * are separated by the calls and comparisons that feed the next one).
 *
 * sub_02025C1C and sub_02025C30 both wrap the predicate with the same
 * shape, "return the value on success, 0 on failure", differing only in
 * which argument is guarded: the first, or the second. Both forward all
 * three arguments to func_02025BEC unchanged; the wrapped argument is
 * kept in its own register (r4) only for the return, which is why the
 * call still carries the original registers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02025BEC.c \
 *       --addr 0x02025BEC --thumb
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u8 sub_02025B64(u32 v);

u32 func_02025BEC(u32 a, u32 b, u32 c)
{
    if (a >= 0xE9) {
        return 0;
    }
    if (sub_02025B64(a) < b) {
        return 0;
    }
    if (c == 1) {
        if (a != 0x69 && a != 0) {
            return 0;
        }
    }
    return 1;
}

u32 sub_02025C1C(u32 a, u32 b, u32 c)
{
    u32 r = a;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}

u32 sub_02025C30(u32 a, u32 b, u32 c)
{
    u32 r = b;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}
