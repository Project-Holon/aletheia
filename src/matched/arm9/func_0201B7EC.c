/*
 * function: NATSUKI_CalcWalk
 * address:  0x0201B7EC
 * packet:   pkt_0201B7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   NATSUKI_Apply  0x0201B850  thumb
 *   _NatsukiWalkDeltas     0x0209E465  data  a1
 *
 * shinka_check.c.  The coin-flip sibling of NATSUKI_Calc / NATSUKI_CalcParty:
 * on an even draw below 2, hand the fixed row _NatsukiWalkDeltas to NATSUKI_Apply.
 *
 * The `movs r1,#0 / lsls r1,r1,#1 / lsrs r0,r0,#31 / orrs` run that four
 * waves read as a scheduling tie of two u32 shifts is the high word of a
 * 64-bit product: the draw widened to u64, times 2, shifted right 32 (the
 * random-below-N idiom, docs/idioms/random-below-n-is-a-64-bit-multiply-high.md,
 * with N = 2).  The zero high half is shifted left by one and ORed with the
 * low half's carry-out bit; the compiler emits the two halves in that order,
 * which is the order no u32 spelling could reach.  `% 2 == 0` gives the
 * `tst` against 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcWalk.c \
 *       --func NATSUKI_CalcWalk --addr 0x0201B7EC --cc 1.1p1 --thumb
 */

typedef signed char        s8;
typedef unsigned int       u32;
typedef unsigned long long u64;

extern u32  GF_STANDARD_Rand(void);
extern void NATSUKI_Apply(void *mon, const s8 *tbl, int a2, u32 a3);
extern const s8 _NatsukiWalkDeltas[];

void NATSUKI_CalcWalk(void *a0, int a1, int a2)
{
    if ((u32)((u64)GF_STANDARD_Rand() * 2 >> 32) % 2 == 0) {
        NATSUKI_Apply(a0, _NatsukiWalkDeltas, a1, a2);
    }
}
