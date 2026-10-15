/*
 * file:     fx_vec.c
 * unit:     yes
 * function: VEC_Add, VEC_Subtract, VEC_Fx16Add, VEC_DotProduct, VEC_Fx16DotProduct, VEC_CrossProduct, VEC_Fx16CrossProduct, VEC_Mag, VEC_Fx16Mag, VEC_Normalize, VEC_Fx16Normalize, VEC_MultAdd, VEC_Distance
 * address:  0x0207C9D0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)
#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT   (*(u64 *)0x040002A0)
#define reg_CP_SQRT_PARAM   (*(u64 *)0x040002B8)
typedef long fx32;

typedef short fx16;

typedef long long fx64;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef long long s64;

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Fx16Add(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab);
fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b);
void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
fx32 VEC_Mag(const VecFx32 *pSrc);
fx32 VEC_Fx16Mag(const VecFx16 *pSrc);
void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
void VEC_Fx16Normalize(const VecFx16 *pSrc, VecFx16 *pDst);
void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2);


/*
 * sdk:      VEC_Add (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab)
{
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}


/*
 * sdk:      VEC_Subtract (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab)
{
    ab->x = a->x - b->x;
    ab->y = a->y - b->y;
    ab->z = a->z - b->z;
}


/*
 * sdk:      VEC_Fx16Add (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_Fx16Add(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab)
{
    ab->x = (fx16)(a->x + b->x);
    ab->y = (fx16)(a->y + b->y);
    ab->z = (fx16)(a->z + b->z);
}


/*
 * sdk:      VEC_DotProduct (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b)
{
    return (fx32)(((fx64)a->x * b->x + (fx64)a->y * b->y + (fx64)a->z * b->z + (1 << 11)) >> 12);
}


/*
 * sdk:      VEC_Fx16DotProduct (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b)
{
    fx32 tmp1, tmp2;

    tmp1 = (a->x * b->x) + (a->y * b->y);
    tmp2 = (a->z * b->z) + (1 << 11);
    return (fx32)(((fx64)tmp1 + tmp2) >> 12);
}



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


/*
 * sdk:      VEC_CrossProduct (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb)
{
    fx32 x, y, z;

    x = (fx32)(((fx64)a->y * b->z - (fx64)a->z * b->y + (1 << 11)) >> 12);
    y = (fx32)(((fx64)a->z * b->x - (fx64)a->x * b->z + (1 << 11)) >> 12);
    z = (fx32)(((fx64)a->x * b->y - (fx64)a->y * b->x + (1 << 11)) >> 12);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}


/*
 * sdk:      VEC_Fx16CrossProduct (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb)
{
    fx32 x, y, z;

    x = (a->y * b->z - a->z * b->y + (1 << 11)) >> 12;
    y = (a->z * b->x - a->x * b->z + (1 << 11)) >> 12;
    z = (a->x * b->y - a->y * b->x + (1 << 11)) >> 12;
    axb->x = (fx16)x;
    axb->y = (fx16)y;
    axb->z = (fx16)z;
}


/*
 * sdk:      VEC_Mag (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 VEC_Mag(const VecFx32 *pSrc)
{
    fx64 t;

    t = (fx64)pSrc->x * pSrc->x;
    t += (fx64)pSrc->y * pSrc->y;
    t += (fx64)pSrc->z * pSrc->z;
    t <<= 2;
    CP_SetSqrt64((u64)t);
    CP_WaitSqrt();
    return ((fx32)CP_GetSqrtResult32() + 1) >> 1;
}


/*
 * sdk:      VEC_Fx16Mag (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 VEC_Fx16Mag(const VecFx16 *pSrc)
{
    fx64 t;

    t = pSrc->x * pSrc->x;
    t += pSrc->y * pSrc->y;
    t += pSrc->z * pSrc->z;
    t <<= 2;
    CP_SetSqrt64((u64)t);
    CP_WaitSqrt();
    return ((fx32)CP_GetSqrtResult32() + 1) >> 1;
}


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


/*
 * sdk:      VEC_Normalize (libfx.TWL.HYB.a fx_vec.o)
 * notes:    the 64-bit CP registers (NUMER, DENOM, RESULT, SQRT_PARAM) are plain (non-volatile)
 *           u64 lvalues; a volatile SQRT_PARAM moves one ALU instruction of the first block.
 */
void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst)
{
    fx64 t;
    fx32 sqrt;

    t = (fx64)pSrc->x * pSrc->x;
    t += (fx64)pSrc->y * pSrc->y;
    t += (fx64)pSrc->z * pSrc->z;
    CP_SetDiv64_64((u64)1 << 56, (u64)t);
    CP_SetSqrt64((u64)(t << 2));
    CP_WaitSqrt();
    sqrt = (fx32)CP_GetSqrtResult32();
    CP_WaitDiv();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx32)((t * pSrc->x + ((fx64)1 << 44)) >> 45);
    pDst->y = (fx32)((t * pSrc->y + ((fx64)1 << 44)) >> 45);
    pDst->z = (fx32)((t * pSrc->z + ((fx64)1 << 44)) >> 45);
}


/*
 * sdk:      VEC_Fx16Normalize (libfx.TWL.HYB.a fx_vec.o)
 * notes:    the 64-bit CP registers (NUMER, DENOM, RESULT, SQRT_PARAM) are plain (non-volatile)
 *           u64 lvalues; a volatile SQRT_PARAM moves one ALU instruction of the first block.
 */
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
    sqrt = (fx32)CP_GetSqrtResult32();
    CP_WaitDiv();
    t = CP_GetDivResult64();
    t = t * sqrt;
    pDst->x = (fx16)((t * pSrc->x + ((fx64)1 << 44)) >> 45);
    pDst->y = (fx16)((t * pSrc->y + ((fx64)1 << 44)) >> 45);
    pDst->z = (fx16)((t * pSrc->z + ((fx64)1 << 44)) >> 45);
}


/*
 * sdk:      VEC_MultAdd (libfx.TWL.HYB.a fx_vec.o)
 */
void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest)
{
    pDest->x = (fx32)(((fx64)a * v1->x) >> 12) + v2->x;
    pDest->y = (fx32)(((fx64)a * v1->y) >> 12) + v2->y;
    pDest->z = (fx32)(((fx64)a * v1->z) >> 12) + v2->z;
}


/*
 * sdk:      VEC_Distance (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2)
{
    fx32 diff;
    fx64 tmp;

    diff = v1->x - v2->x;
    tmp = (fx64)diff * diff;
    diff = v1->y - v2->y;
    tmp += (fx64)diff * diff;
    diff = v1->z - v2->z;
    tmp += (fx64)diff * diff;
    tmp <<= 2;
    CP_SetSqrt64((u64)tmp);
    CP_WaitSqrt();
    return ((fx32)CP_GetSqrtResult32() + 1) >> 1;
}
