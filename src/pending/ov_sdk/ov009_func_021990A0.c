/*
 * function: func_021990A0
 * address:  0x021990A0
 * packet:   pkt_ov009_021990A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (one instruction: mvn r1,#0x80000000 vs compiled sub r1,r0,#0x80000002)
 * u21: the defining object natneg.o is .comment 4.0.0.1025. The object materialises the second
 *      argument with `mvn r1, #0x80000000`; 1.1p1 rematerialises 0x7fffffff from the r0 == 1 it has
 *      just built for the first argument, `sub r1, r0, #0x80000002` (same value, 3 bytes differ).
 *      Ten more spellings (named locals, casts, long/unsigned, arithmetic and complement forms)
 *      all keep the subtraction. First divergence +0020 image `mvn r1, #0x80000000` |
 *      ours `sub r1, r0, #0x80000002`. Size already exact at 52 B.
 * u1: family check done - ../2.0/base + ../2.0/sp1p2 56 B / 23 B; ../1.2/sp3 DOES emit `mvn r1,#0x80000000` but in its own stmdb/ldm codegen family (68 B), so it is not the build. Parked: the constant-from-register peephole.
 *
 * w9_nm: not retried (w8 covered every build and -opt switch).
 *
 * u31: five more spellings of the high bound -- (1 << 31) - 1, 0x80000000u - 1,
 * a named `int id` temp with the store and return split, the assignment-expression
 * return `return g.clientID = f(...)`, and an explicit (int) cast -- all keep
 * `sub r1, r0, #0x80000002` (1 - 0x80000002, both the value and an encodable
 * immediate) at 52 B / 3 B. The 4.0.0.1025 object alone materialises the bound
 * with `mvn r1, #0x80000000`. The rest of the row is byte-exact.
 *
 * lane W7 (2026-09-30): re-measured 52/52, 4/4 relocations, 3 concrete bytes
 * (`sub r1,r0,#0x80000002` vs `mvn r1,#0x80000000`).  Both permuters were run
 * briefly on this 3-byte row: permute.py reported 0 available mutations, and
 * permuter.py tried 32 single-mutation candidates with no improvement.  The
 * constant is materialised from the live r0 == 1, so the mvn is a 4.0.0.1025
 * codegen decision, not a source shape.
 *
 * lane W8 (2026-09-30): the mvn IS reachable from source.  Typing the high bound as an enum
 *      local (`typedef enum { HIGH_MAX = 0x7fffffff } HighMax; HighMax hi = HIGH_MAX;`) stops
 *      mwcc folding it and emits the exact `mvn r1, #0x80000000` (a bare enum constant or an
 *      int local still folds to the `sub`).  Remaining blocker is argument order: the enum
 *      local is materialised BEFORE the low literal, `mvn r1; mov r0`, where the image emits
 *      `mov r0, #1; mvn r1` (6 bytes).  With both args as enum locals the order is right but
 *      the compiler re-derives 0x7fffffff from the adjacent r0 == 1 again (`sub`).  See
 *      docs/idioms/an-enum-local-materialises-a-large-complement-constant.md.
 *
 * lane4 (w10): more enum-local spellings measured, none reach both instructions:
 *   `LowOne lo; HighMax hi;` (both enum locals, either declaration order) -> right
 *   order but `sub` (3 B); `int lo = 1; HighMax hi` in a block -> `mvn` first then
 *   `mov` (6 B); `HighMax hi` hoisted to function scope -> hi pinned in r5 (47 B);
 *   `(int)(HighMax)HIGH_MAX` and `(LowOne)1, (HighMax)` casts -> fold back to `sub`.
 *
 * sdk:      GetClientUniqueID (natify.o)
 *
 * w4_nm tried: K&R and unsigned prototypes, 0x7fffffffu, ~0x80000000, ~0u>>1, long
 * args: the high bound is always built from r0 == 1 (sub) instead of mvn.
 *
 * w6_nm tried: a result local, hi/lo locals, -(int)0x80000001, the store in an
 * if block, a function-pointer call, cc 1.1, lang c++: always `sub r1,r0,#0x80000002`.
 *
 * w8_nm tried: cc 1.1, 1.2, 1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, 1.6sp2, mwcc 1.2;
 * -O4,s, -O3,p, -O2, -O1, and -opt nopeephole/noschedule/nocse/nopropagation/
 * nostrength: always `sub r1,r0,#0x80000002` (even at -O1, so it is in code
 * generation). natneg.o is stamped 4.0.0.1025, which no build here writes.
 *
 * symbols:
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217F790  0x0217F790  arm  ov009
 *   func_0217F7AC  0x0217F7AC  arm  ov009
 *   g_021AE698  0x021AE698  data
 */

typedef struct {
    int pad0[5];
    int clientID;
} NegotiateState;

extern NegotiateState g_021AE698;
extern unsigned int func_0217F264(void);
extern void func_0217F790(unsigned long seed);
extern int func_0217F7AC(int low, int high);

int func_021990A0(void)
{
    if (g_021AE698.clientID)
        return g_021AE698.clientID;
    func_0217F790(func_0217F264());
    g_021AE698.clientID = func_0217F7AC(1, 0x7fffffff);
    return g_021AE698.clientID;
}
