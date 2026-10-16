/*
 * function: DWCi_GetMathRand32
 * address:  0x021685CC
 * packet:   pkt_ov009_021685CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * lane18 (2026-10-01): EXACT. dwc_common.o's stRandContext32 is a data-local static:
 *   declared as a function-local static (non-aliasing in 1.1p1) with the SDK inlines
 *   MATH_InitRand32/MATH_Rand32, the .bss pool word and the fresh x-store word both fall out.
 *
 * sdk:      DWCi_GetMathRand32 (libdwcmatch.TWL.HYB.a(dwc_common.o))
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_GetTick        0x020870D0  arm
 *   _ZZ18DWCi_GetMathRand32mE15stRandContext32  0x021AA848  data
 *
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

extern void OS_GetMacAddress(u8 *macAddress);
extern u64 OS_GetTick(void);

static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->add = 2531011;
}

static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (u32)(context->x >> 32);
    } else {
        return (u32)(((context->x >> 32) * max) >> 32);
    }
}

u32 DWCi_GetMathRand32(u32 max)
{
    static MATHRandContext32 stRandContext32;
    u64 seed;

    if (stRandContext32.x == 0 && stRandContext32.mul == 0 && stRandContext32.add == 0) {
        OS_GetMacAddress((u8 *)&seed);
        seed = ((seed >> 24) & 0xFFFFFF) | (OS_GetTick() << 24);
        MATH_InitRand32(&stRandContext32, seed);
    }
    return MATH_Rand32(&stRandContext32, max);
}
