/*
 * function: VEC_CrossProduct
 * address:  0x0207CAE8
 * packet:   pkt_0207CAE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_CrossProduct (libfx.TWL.HYB.a fx_vec.o)
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
