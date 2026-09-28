/*
 * function: func_0207C8D0
 * address:  0x0207C8D0
 * packet:   pkt_0207C8D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      FX_SqrtAsync (libfx.TWL.HYB.a fx_cp.o)
 * notes:    10 bytes differ, register allocation only: the image's shape (both arms predicated, one unconditional high-word store after the join, base loaded once before the cmp) is reproduced; the base lands in r2 and the gt-arm constants in r1, the image has them swapped. Pass 3 (sdk9w3_fx): the join store needs a pointer assigned in both arms (a phi); the pointer local is not in DWARF, an inline returning the base, `(x > 0 ? SqBeg() : (x = 0, SqBeg()))->hi = x`, gives the same 10 bytes with no named local. Permuter seeds 13607, 13608, 13610 flat at 10.
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

#define reg_CP_DIV_NUMER32  (*(volatile u32 *)0x04000290)
#define reg_CP_DIV_REM32    (*(volatile u32 *)0x040002A8)

typedef struct {
    u16 cnt;
    u16 pad;
    u32 result;
    u32 param_lo;
    u32 param_hi;
} CPSqrtRegs;

#define reg_CP_SQRT ((volatile CPSqrtRegs *)0x040002B0)

void func_0207C8D0(fx32 x)
{
    volatile CPSqrtRegs *p;

    if (x > 0) {
        p = reg_CP_SQRT;
        reg_CP_SQRT->cnt = 1;
        reg_CP_SQRT->param_lo = 0;
    } else {
        p = reg_CP_SQRT;
        reg_CP_SQRT->cnt = 1;
        reg_CP_SQRT->param_lo = 0;
        x = 0;
    }
    p->param_hi = (u32)x;
}
