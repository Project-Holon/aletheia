/*
 * function: func_02095F40
 * address:  0x02095F40
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 32-bit member of the decimal-to-integer family (func_02095EAC,
 * func_020963F8 are its siblings and differ only in their callee and in the
 * width of the clamped result).  It runs the parser at 0x02095B3C over a
 * five-word working buffer with the sign flag 0x7FFFFFFF and the default
 * radix, stores the end-of-digits pointer through the optional out parameter,
 * and clamps the parsed magnitude to the s32 range: with a cleared sign a
 * magnitude above 0x7FFFFFFF does not fit and with a set sign the magnitude
 * may reach 0x80000000, after which the result is negated.
 *
 * Two things pin the source shape:
 *
 *  - The three range conditions have to be ONE disjunction.  Written as an
 *    if/else the shared error block is laid out after the final return and
 *    the whole tail shifts; as `||` the block lands exactly where the
 *    original has it, between the second range test and the negation, and
 *    the second test's branch inverts to `bls` over the error block.
 *  - The saturating values are INT_MIN for a set sign and INT_MAX for a
 *    cleared one.  mwcc materialises the pair as `movne r0, #0x80000000` /
 *    `mvneq r0, #0x80000000`, and the second is a `mvn` of 0x80000000, i.e.
 *    0x7FFFFFFF, not the same value written twice: a source whose two arms
 *    are equal is folded to a single `mov` and loses both the compare and
 *    twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02095F40.c \
 *       --func func_02095F40 --addr 0x02095F40 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 3 relocation sites, all resolved.
 *
 * symbols:
 *   func_02095B3C  0x02095B3C  arm
 *   func_020946D8  0x020946D8  arm
 *   g_02153FAC     0x02153FAC  data
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 func_02095B3C(u32 a, u32 b, u32 cb, u32 *buf, u32 *p4, u32 *p3,
                         u32 *p2);
extern u32 func_020946D8(u32 a, u32 b, u32 c);
extern u32 g_02153FAC;

s32 func_02095F40(u32 a0, u32 *a1, u32 a2)
{
    u32 buf[5];
    s32 r;
    s32 v;

    buf[0] = a0;
    buf[1] = 0;
    r = (s32)func_02095B3C(a2, 0x7FFFFFFFu, (u32)func_020946D8, buf,
                           &buf[4], &buf[3], &buf[2]);
    if (a1 != 0)
        *a1 = a0 + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u32)r > 0x7FFFFFFFu) ||
        (buf[3] != 0 && (u32)r > 0x80000000u)) {
        v = (buf[3] != 0) ? (s32)0x80000000 : (s32)0x7FFFFFFF;
        g_02153FAC = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}
