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
 *
 * lane U22 (2026-09-30): the register file above is set by the ORDER of the
 * three stores in MATH_InitRand32.  Written mul, add, x the front end
 * reproduces the image's whole head byte for byte -- ctx r6, &seed r4, max r5,
 * `add r4,sp,#0` / `mov r0,r4` around OS_GetMacAddress and every 64-bit seed
 * step identical to +0088 (measured: only the tail differs).  What is left:
 * the image emits the x block copy FIRST and with a REMATERIALISED ctx
 * literal (ldr r0,pool_021686D0; ldm r4,{r2,r3}; stm r0,{r2,r3}), then mul
 * lo/hi and add lo/hi via r6; the mul-first source keeps our x copy last and
 * reuses r6 for the stm, which is 8 bytes short (268 of 276).  Written x
 * first the instruction order matches the image but the register file rolls
 * back to ctx r4 / &seed r5 / max r6.  So the two halves are each reachable
 * from a different statement order and not both at once; a second ctx literal
 * plus a stm through it is what the image wants.
 *
 * `unsigned char seed[8]`, a pointer-seed helper and a plain (non-inline)
 * helper were measured: no configuration moves the tail.
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
