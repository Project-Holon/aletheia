/*
 * file:     unit_0207C9D0_p01.c
 * unit:     yes
 * function: func_0207C9D0, func_0207CA00, func_0207CA30, func_0207CA68, func_0207CAA4, func_0207CAE8, func_0207CB68, func_0207CBD0, func_0207CC30
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

void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void func_0207CA30(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab);
fx32 func_0207CA68(const VecFx32 *a, const VecFx32 *b);
fx32 func_0207CAA4(const VecFx16 *a, const VecFx16 *b);
void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
void func_0207CB68(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
fx32 func_0207CBD0(const VecFx32 *pSrc);
fx32 func_0207CC30(const VecFx16 *pSrc);





/*
 * sdk:      VEC_Add (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab)
{
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}





/*
 * sdk:      VEC_Subtract (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab)
{
    ab->x = a->x - b->x;
    ab->y = a->y - b->y;
    ab->z = a->z - b->z;
}





/*
 * sdk:      VEC_Fx16Add (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207CA30(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab)
{
    ab->x = (fx16)(a->x + b->x);
    ab->y = (fx16)(a->y + b->y);
    ab->z = (fx16)(a->z + b->z);
}





/*
 * sdk:      VEC_DotProduct (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 func_0207CA68(const VecFx32 *a, const VecFx32 *b)
{
    return (fx32)(((fx64)a->x * b->x + (fx64)a->y * b->y + (fx64)a->z * b->z + (1 << 11)) >> 12);
}





/*
 * sdk:      VEC_Fx16DotProduct (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 func_0207CAA4(const VecFx16 *a, const VecFx16 *b)
{
    fx32 tmp1, tmp2;

    tmp1 = (a->x * b->x) + (a->y * b->y);
    tmp2 = (a->z * b->z) + (1 << 11);
    return (fx32)(((fx64)tmp1 + tmp2) >> 12);
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
 * sdk:      VEC_CrossProduct (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb)
{
    fx32 x, y, z;

    x = (fx32)(((fx64)a->y * b->z - (fx64)a->z * b->y + (1 << 11)) >> 12);
    y = (fx32)(((fx64)a->z * b->x - (fx64)a->x * b->z + (1 << 11)) >> 12);
    z = (fx32)(((fx64)a->x * b->y - (fx64)a->y * b->x + (1 << 11)) >> 12);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}




#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)



#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)



#define reg_CP_SQRT_PARAM   (*(volatile u64 *)0x040002B8)




/*
 * sdk:      VEC_Fx16CrossProduct (libfx.TWL.HYB.a fx_vec.o)
 */
void func_0207CB68(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb)
{
    fx32 x, y, z;

    x = (a->y * b->z - a->z * b->y + (1 << 11)) >> 12;
    y = (a->z * b->x - a->x * b->z + (1 << 11)) >> 12;
    z = (a->x * b->y - a->y * b->x + (1 << 11)) >> 12;
    axb->x = (fx16)x;
    axb->y = (fx16)y;
    axb->z = (fx16)z;
}



#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)


#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)


#define reg_CP_SQRT_PARAM   (*(volatile u64 *)0x040002B8)



/*
 * sdk:      VEC_Mag (libfx.TWL.HYB.a fx_vec.o)
 */
fx32 func_0207CBD0(const VecFx32 *pSrc)
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


#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)

#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)

#define reg_CP_SQRT_PARAM   (*(volatile u64 *)0x040002B8)


/*
 * sdk:      VEC_Fx16Mag (libfx.TWL.HYB.a fx_vec.o)
 */
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
