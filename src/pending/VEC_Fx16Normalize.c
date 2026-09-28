/*
 * function: VEC_Fx16Normalize
 * address:  0x0207CDB8
 * packet:   pkt_0207CDB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libfx fx_vec.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Normalises a 16-bit fixed-point vector with the hardware divider and square
 * root unit: starts 2^56 / |v|^2 and sqrt(4|v|^2) together, scales each
 * component by their product and rounds it back to fx16.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef short fx16;
typedef long fx32;
typedef long long fx64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef struct {
    fx16 x;
    fx16 y;
    fx16 z;
} VecFx16;

#define reg_CP_DIVCNT         (*(vu16 *)0x04000280)
#define reg_CP_DIV_NUMER      (*(vu64 *)0x04000290)
#define reg_CP_DIV_DENOM      (*(vu64 *)0x04000298)
#define reg_CP_DIV_RESULT     (*(vu64 *)0x040002A0)
#define reg_CP_SQRTCNT        (*(vu16 *)0x040002B0)
#define reg_CP_SQRT_RESULT    (*(vu32 *)0x040002B4)
#define reg_CP_SQRT_PARAM     (*(vu64 *)0x040002B8)

#define CP_DIV_64_64BIT_MODE  2
#define CP_SQRT_64BIT_MODE    1
#define REG_CP_DIVCNT_BUSY_MASK  0x8000
#define REG_CP_SQRTCNT_BUSY_MASK 0x8000

static inline void CP_SetDiv64_64(u64 numer, u64 denom)
{
    reg_CP_DIVCNT = CP_DIV_64_64BIT_MODE;
    reg_CP_DIV_NUMER = numer;
    reg_CP_DIV_DENOM = denom;
}

static inline void CP_SetSqrt64(u64 param)
{
    reg_CP_SQRTCNT = CP_SQRT_64BIT_MODE;
    reg_CP_SQRT_PARAM = param;
}

static inline void CP_WaitDiv(void)
{
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
}

static inline void CP_WaitSqrt(void)
{
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
}

void VEC_Fx16Normalize(const VecFx16 *pSrc, VecFx16 *pDst)
{
    fx64 t;
    fx32 sqrt;

    t = pSrc->x * pSrc->x;
    t += pSrc->y * pSrc->y;
    t += pSrc->z * pSrc->z;

    CP_SetDiv64_64((u64)1 << 56, (u64)t);
    CP_SetSqrt64((u64)(t << 2));

    CP_WaitSqrt();
    sqrt = (fx32)reg_CP_SQRT_RESULT;
    CP_WaitDiv();
    t = (fx64)reg_CP_DIV_RESULT;

    t = t * sqrt;
    pDst->x = (fx16)((t * pSrc->x + (1LL << 44)) >> 45);
    pDst->y = (fx16)((t * pSrc->y + (1LL << 44)) >> 45);
    pDst->z = (fx16)((t * pSrc->z + (1LL << 44)) >> 45);
}
