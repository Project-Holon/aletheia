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
 *
 * sdk:      DWCi_GetMathRand32 (libdwcmatch.TWL.HYB.a(dwc_common.o))
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_GetTick        0x020870D0  arm
 *   g_021AA848        0x021AA848  data
 *
 * notes: the Rand32 half matches the image exactly. Residue: the image keeps
 * ctx in r6, &seed in r4, max in r5 and reloads the ctx literal (second pool
 * word) for the x stm; ours allocates ctx r4, &seed r5, max r6 and has one
 * pool word. About 20 spellings tried.
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
extern void OS_GetMacAddress(u8 *macAddress);
extern u64 OS_GetTick(void);

static inline void MATH_InitRand32(MATHRandContext32 *rand, u64 seed)
{
    rand->x = seed;
    rand->mul = 0x5D588B656C078965ULL;
    rand->add = 0x0000000000269EC3ULL;
}

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
        MATH_InitRand32(&g_021AA848, seed);
    }
    return MATH_Rand32(&g_021AA848, max);
}
