/*
 * function: func_0207CDB8
 * address:  0x0207CDB8
 * packet:   pkt_0207CDB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      VEC_Fx16Normalize (libfx.TWL.HYB.a fx_vec.o)
 * notes:    19 bytes differ, scheduling only (same residue as VEC_Normalize at 0x0207CCA4: z*z and the t<<2 high word placed later in the image).
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

void func_0207CDB8(const VecFx16 *pSrc, VecFx16 *pDst)
{
    fx64 t;
    fx32 sqrt;

    t = pSrc->x * pSrc->x;
    t += pSrc->y * pSrc->y;
    t += pSrc->z * pSrc->z;
    CP_SetDiv64_64((u64)1 << 56, (u64)t);
    CP_SetSqrt64((u64)(t << 2));
    CP_WaitSqrt();
    sqrt = (fx32)CP_GetSqrtResult32();
    CP_WaitDiv();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx16)((t * pSrc->x + ((fx64)1 << 44)) >> 45);
    pDst->y = (fx16)((t * pSrc->y + ((fx64)1 << 44)) >> 45);
    pDst->z = (fx16)((t * pSrc->z + ((fx64)1 << 44)) >> 45);
}
