/*
 * file:     unit_0207C9D0_p03.c
 * unit:     yes
 * function: func_0207CEE4, func_0207CF3C
 * address:  0x0207CEE4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
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

void func_0207CEE4(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
fx32 func_0207CF3C(const VecFx32 *v1, const VecFx32 *v2);


/*
 * sdk:      VEC_MultAdd (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207CEE4(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest)
{
    pDest->x = (fx32)(((fx64)a * v1->x) >> 12) + v2->x;
    pDest->y = (fx32)(((fx64)a * v1->y) >> 12) + v2->y;
    pDest->z = (fx32)(((fx64)a * v1->z) >> 12) + v2->z;
}


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


/*
 * sdk:      VEC_Distance (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 func_0207CF3C(const VecFx32 *v1, const VecFx32 *v2)
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
