/*
 * function: func_0201B7EC
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
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_0201B850  0x0201B850  thumb
 *   g_0209E465     0x0209E465  data  a1
 *
 * shinka_check.c.  The coin-flip sibling of func_0201B7A0 / func_0201B818:
 * on an even draw below 2, hand the fixed row g_0209E465 to func_0201B850.
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
 *   python tools/match.py one --src src/matched/func_0201B7EC.c \
 *       --func func_0201B7EC --addr 0x0201B7EC --cc 1.1p1 --thumb
 */

typedef signed char        s8;
typedef unsigned int       u32;
typedef unsigned long long u64;

extern u32  func_0203F0A8(void);
extern void func_0201B850(void *a0, const s8 *tbl, int a2, int a3);
extern const s8 g_0209E465[];

void func_0201B7EC(void *a0, int a1, int a2)
{
    if ((u32)((u64)func_0203F0A8() * 2 >> 32) % 2 == 0) {
        func_0201B850(a0, g_0209E465, a1, a2);
    }
}
