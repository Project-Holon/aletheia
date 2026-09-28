/*
 * function: func_0207CC30
 * address:  0x0207CC30
 * packet:   pkt_0207CC30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_Fx16Mag (libfx.TWL.HYB.a fx_vec.o)
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

fx32 func_0207CC30(const VecFx16 *pSrc)
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
