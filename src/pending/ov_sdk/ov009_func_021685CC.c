/*
 * function: func_021685CC
 * address:  0x021685CC
 * packet:   pkt_ov009_021685CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  276/276 bytes, 18 concrete bytes; the dsi/1.1p1 list scheduler
 *           hoists the mul-lo pool load into the slot the image gives to the
 *           x-store address load (+0x98..+0xA8).  Same instruction multiset
 *           and same pool words in the same order; no source order moves it.
 *
 * sdk:      DWCi_GetMathRand32 (libdwcmatch.TWL.HYB.a(dwc_common.o))
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_GetTick        0x020870D0  arm
 *   g_021AA848        0x021AA848  data
 *   g_021AA848_x      0x021AA848  data
 *
 * notes: the image's pool carries 0x021AA848 twice, and the two words are used
 * by different statements: r6 (word 0xd0) for the x==0/mul==0/add==0 checks,
 * the mul/add stores and MATH_Rand32, and a fresh r0 (word 0xd4) for the
 * `rand->x = seed` block copy only (docs/idioms/
 * a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md).
 * Hand-inlining MATH_InitRand32 with a second extern on the x store only gives
 * the exact size (276) and every register home the image has (ctx r6, max r5,
 * &seed r4, zero r7, and the 64-bit seed step byte for byte through +0x90).
 * Residue is +0x98..+0xA8: the image loads the x base into r0 then the seed
 * and stm, then loads the mul constants; 1.1p1 hoists the mul-lo load above
 * the ldm/stm and so the base lands in r1.  Statement order (x first/mid/last),
 * an inlined mul/add setter, a two-pointer inline helper, a u64* binding and
 * named constant locals all measure the same 18 bytes.  See
 * docs/notes/func_021685CC.c.txt.
 * opus (2026-10-01): the vendor body calls the inline MATH_InitRand32(&ctx, seed).
 *           Inlined with &g_021AA848_x it gives the image's instruction order
 *           (seed copy, then mul/add constants) but no longer keeps &g live in
 *           r6 across the calls (push r4-r6, 14 blocks); with &g_021AA848 the
 *           duplicate pool load folds away (268 B). Inert on the current body:
 *           u64-typed alias, pointer local for the x store, SDK-spelled
 *           constants, `*(u64 *)&seed`; mul before x is worse.
 * 2026-10-01 lane08: inline MATH_InitRand32(&g, seed) gives the image's
 *   order (stm, then constants) but stores x through the CSE'd base (268 B);
 *   the image is that plus a fresh pool load for x only.  Inert (18): split
 *   inline setters, int-cast/u64* x-store pointers, goto label between x and
 *   mul.  A memcpy-style inline copy is worse (272 B).
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

extern MATHRandContext32 g_021AA848;
extern MATHRandContext32 g_021AA848_x;
extern void OS_GetMacAddress(u8 *macAddress);
extern u64 OS_GetTick(void);

static inline u32 MATH_Rand32(MATHRandContext32 *rand, u32 max)
{
    u64 x = rand->x;
    x = rand->mul * x + rand->add;
    rand->x = x;
    if (max == 0)
        return (u32)(x >> 32);
    return (u32)(((x >> 32) * max) >> 32);
}

u32 func_021685CC(u32 max)
{
    u64 seed;

    if (g_021AA848.x == 0 && g_021AA848.mul == 0 && g_021AA848.add == 0) {
        OS_GetMacAddress((u8 *)&seed);
        seed = ((seed >> 24) & 0xFFFFFF) | (OS_GetTick() << 24);
        g_021AA848_x.x = seed;
        g_021AA848.mul = 0x5D588B656C078965ULL;
        g_021AA848.add = 0x0000000000269EC3ULL;
    }
    return MATH_Rand32(&g_021AA848, max);
}
