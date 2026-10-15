/*
 * function: FX_InvFx64c
 * address:  0x0207C788
 * packet:   pkt_0207C788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FX_InvFx64c (libfx.TWL.HYB.a fx_cp.o); catalog row says FX_DivFx64c, but the image
 *           calls FX_InvAsync (0x0207C8A0) with one argument, so the object symbol here is FX_InvFx64c
 *
 * symbols:
 *   FX_InvAsync   0x0207C8A0  arm
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

#define reg_CP_DIV_NUMER32  (*(volatile u32 *)0x04000290)
#define reg_CP_DIV_REM32    (*(volatile u32 *)0x040002A8)

extern void FX_InvAsync(fx32 denom);

fx64 FX_InvFx64c(fx32 denom)
{
    FX_InvAsync(denom);
    CP_WaitDiv();
    return *(fx64 *)0x040002A0;
}
