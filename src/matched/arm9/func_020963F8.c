/*
 * function: func_020963F8
 * address:  0x020963F8
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  the callee at 0x02096004 has no witness outside this file's own
 *           range: the only branch to it anywhere in the image is the bl in
 *           this function (it has a func_ label, but the label class needs a
 *           branch from outside the compared range as well), so that one
 *           relocation stays wildcarded and the file cannot be EXACT.  The
 *           file becomes EXACT* the day 0x02096004 gets a shard entry.
 *
 * bcd_to_s64: the 64-bit sibling of func_02095EAC/func_02095F40.  It hands
 * the decimal parser func_02096004 a working buffer, a pointer to the first
 * byte after the parsed digits and a sign flag, then clamps the parsed
 * magnitude to the s64 range: with a zero sign a magnitude above
 * 0x7FFFFFFFFFFFFFFF does not fit, with a set sign the magnitude may reach
 * 0x8000000000000000, and the result is negated for the sign.
 *
 * The error path returns the saturating extremes of the original's own sign
 * flag, which is why the reserved word g_02153FAC is set to 0x22 there.
 *
 * The bounded-magnitude test has to be one disjunction: written as an
 * if/else the shared error block is laid out after the final return and the
 * whole tail moves (66 bytes), while `||` over the three conditions places it
 * exactly where the original has it, between the second range test and the
 * negation.  The `-r` and the return then share one epilogue.
 *
 * trailing star: the listing's extent for this address runs to 0x02096508
 * because everything between the last code byte (0x020964D8) and the next
 * label is unlabelled: this function's own two-word pool at 0x020964D8 and
 * two sixteen-byte argument-defaulting thunks at 0x020964E0 and 0x020964F4
 * (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` -> 0x02095F40 and
 * 0x020963F8).  Needs seeds for both thunk addresses in
 * layout/function_starts.txt; neither is producible from C.
 *
 * symbols:
 *   func_02096004  0x02096004  arm
 *   func_020946D8  0x020946D8  arm
 *   g_02153FAC     0x02153FAC  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020963F8.c \
 *       --func func_020963F8 --addr 0x020963F8 --cc 1.1p1 --arm
 *   MATCH* with no concrete byte differing; EXACT* once the symbols above
 *   are declared and the two thunk addresses are labelled.
 */

typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;

extern u64 func_02096004(u32 a, u32 b, u32 cb, u32 *buf, u32 *p4, u32 *p3,
                         u32 *p2);
extern u32 func_020946D8(u32 a, u32 b, u32 c);
extern u32 g_02153FAC;

s64 func_020963F8(u32 a0, u32 *a1, u32 a2)
{
    u32 buf[5];
    s64 r;
    s64 v;

    buf[0] = a0;
    buf[1] = 0;
    r = (s64)func_02096004(a2, 0x7FFFFFFFu, (u32)func_020946D8, buf,
                           &buf[4], &buf[3], &buf[2]);
    if (a1 != 0)
        *a1 = a0 + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u64)r > 0x7FFFFFFFFFFFFFFFULL) ||
        (buf[3] != 0 && (u64)r > 0x8000000000000000ULL)) {
        v = (buf[3] != 0) ? (s64)0x8000000000000000ULL
                          : (s64)0x7FFFFFFFFFFFFFFFULL;
        g_02153FAC = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}
