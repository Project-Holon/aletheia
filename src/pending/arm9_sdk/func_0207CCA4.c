/*
 * function: func_0207CCA4
 * address:  0x0207CCA4
 * packet:   pkt_0207CCA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      VEC_Normalize (libfx.TWL.HYB.a fx_vec.o)
 * notes:    24 bytes differ, scheduling only: the image computes the high word of t<<2 after the denominator low-word store, this C hoists it above the DIVCNT write. Permuter seed 12601 did not close it. Pass 2 (sdk9w2_fxmisc): split setters (control / imm64 / denom), DIVCNT+NUMER before the sum, u32 halves for DENOM or SQRT_PARAM, s64 setter params, direct register writes, other -O levels (all 24 bytes) and permuter seed 13604 did not move the lsl. Pass 3 (sdk9w3_fx): the residue is one instruction, `lsl r2, r7, #2` issued before the DIVCNT store instead of after the DENOM-low store; shift spellings (<<=, *4, (u64)t<<2, two shifts), divider setup before the sum, all eight u32-half combinations of NUMER/DENOM/SQRT_PARAM, dot-product inlines, other dsi compilers and permuter seeds 13612 and 13614 all flat at 24 or worse.
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef short fx16;
typedef long long fx64;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef long long s64;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16;

#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)
#define reg_CP_SQRT_PARAM   (*(volatile u64 *)0x040002B8)

static inline void CP_SetSqrt64(u64 param)
{
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = param;
}

static inline void CP_WaitSqrt(void)
{
    while (reg_CP_SQRTCNT & 0x8000) {
    }
}

static inline u32 CP_GetSqrtResult32(void)
{
    return reg_CP_SQRT_RESULT;
}

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(volatile u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(volatile u64 *)0x04000298)
#define reg_CP_DIV_RESULT   (*(volatile u64 *)0x040002A0)

static inline void CP_SetDiv64_64(u64 numer, u64 denom)
{
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = numer;
    reg_CP_DIV_DENOM = denom;
}

static inline void CP_WaitDiv(void)
{
    while (reg_CP_DIVCNT & 0x8000) {
    }
}

static inline s64 CP_GetDivResult64(void)
{
    return (s64)reg_CP_DIV_RESULT;
}

void func_0207CCA4(const VecFx32 *pSrc, VecFx32 *pDst)
{
    fx64 t;
    fx32 sqrt;

    t = (fx64)pSrc->x * pSrc->x;
    t += (fx64)pSrc->y * pSrc->y;
    t += (fx64)pSrc->z * pSrc->z;
    CP_SetDiv64_64((u64)1 << 56, (u64)t);
    t <<= 2;
    CP_SetSqrt64((u64)t);
    CP_WaitSqrt();
    sqrt = (fx32)CP_GetSqrtResult32();
    CP_WaitDiv();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx32)((t * pSrc->x + ((fx64)1 << 44)) >> 45);
    pDst->y = (fx32)((t * pSrc->y + ((fx64)1 << 44)) >> 45);
    pDst->z = (fx32)((t * pSrc->z + ((fx64)1 << 44)) >> 45);
}
