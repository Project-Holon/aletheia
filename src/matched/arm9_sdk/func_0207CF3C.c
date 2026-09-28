/*
 * function: func_0207CF3C
 * address:  0x0207CF3C
 * packet:   pkt_0207CF3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_Distance (libfx.TWL.HYB.a fx_vec.o)
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
