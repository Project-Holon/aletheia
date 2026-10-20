/*
 * file:     fx_cp.c
 * unit:     yes
 * function: FX_Div, FX_Inv, FX_InvFx64c, FX_Sqrt, FX_InvSqrt, FX_GetDivResultFx64c, FX_GetDivResult, FX_InvAsync, FX_SqrtAsync, FX_GetSqrtResult, FX_DivAsync, FX_DivS32, FX_ModS32
 * address:  0x0207C768
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FX_GetDivResult  0x0207C86C  arm
 *   FX_InvAsync   0x0207C8A0  arm
 *   FX_GetSqrtResult   0x0207C904  arm
 *   FX_SqrtAsync           0x0207C8D0  arm
 */
#define reg_CP_SQRTCNT      (*(volatile u16 *)REG_SQRTCNT_ADDR)
#define reg_CP_SQRT_RESULT  (*(volatile u32 *)REG_SQRT_RESULT_ADDR)
#define reg_CP_SQRT_PARAM   (*(volatile u64 *)REG_SQRT_PARAM_ADDR)
#define reg_CP_DIVCNT       (*(volatile u16 *)REG_DIVCNT_ADDR)
#define reg_CP_DIV_NUMER    (*(volatile u64 *)REG_DIV_NUMER_ADDR)
#define reg_CP_DIV_DENOM    (*(volatile u64 *)REG_DIV_DENOM_ADDR)
#define reg_CP_DIV_RESULT   (*(volatile u64 *)REG_DIV_RESULT_ADDR)
#define reg_CP_DIV_NUMER32  (*(volatile u32 *)REG_DIV_NUMER_ADDR)
#define reg_CP_DIV_REM32    (*(volatile u32 *)REG_DIVREM_RESULT_ADDR)
#define reg_CP_SQRT_PARAM_PLAIN   (*(u64 *)REG_SQRT_PARAM_ADDR)
#define REG_DIVCNT      (*(volatile u16 *)REG_DIVCNT_ADDR)
#define REG_DIV_NUMER   (*(volatile s32 *)REG_DIV_NUMER_ADDR)
#define REG_DIV_DENOM   (*(volatile u64 *)REG_DIV_DENOM_ADDR)
#define REG_DIV_RESULT  (*(volatile s32 *)REG_DIV_RESULT_ADDR)
#define DIVCNT_MODE_32_32 0x0000
#define DIVCNT_BUSY       0x8000
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_fx.h"

extern u32 FX_GetDivResult(void);
extern void FX_InvAsync(fx32 denom);
extern fx32 FX_GetSqrtResult(void);
extern void FX_SqrtAsync(fx32 x);
fx32 FX_Div(fx32 numer, fx32 denom);
fx32 FX_Inv(fx32 denom);
fx64 FX_InvFx64c(fx32 denom);
fx32 FX_Sqrt(fx32 x);
fx32 FX_InvSqrt(fx32 x);
u64 FX_GetDivResultFx64c(void);
u32 FX_GetDivResult(void);
void FX_DivAsync(s32 numer, s32 denom);
s32 FX_DivS32(s32 numer, s32 denom);
fx32 FX_ModS32(fx32 a, fx32 b);

/*
 * Start the hardware unit through FX_DivAsync with the caller's two
 * operands, then block on it and return its result through FX_GetDivResult.
 * Both arguments reach FX_DivAsync as leftovers in r0/r1; nothing is
 * spent setting them up
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FX_Div.c \
 *       --func FX_Div --addr 0x0207C768 --cc 1.1p1 --arm
 */
fx32 FX_Div(fx32 numer, fx32 denom)
{
    FX_DivAsync(numer, denom);
    return FX_GetDivResult();
}

fx32 FX_Inv(fx32 denom)
{
    FX_InvAsync(denom);
    return FX_GetDivResult();
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
 * sdk:      FX_InvFx64c (libfx.TWL.HYB.a fx_cp.o); catalog row says FX_DivFx64c, but the image
 *           calls FX_InvAsync (0x0207C8A0) with one argument, so the object symbol here is FX_InvFx64c
 */
fx64 FX_InvFx64c(fx32 denom)
{
    FX_InvAsync(denom);
    CP_WaitDiv();
    return *(fx64 *)REG_DIV_RESULT_ADDR;
}

/*
 * sdk:      FX_Sqrt (libfx.TWL.HYB.a fx_cp.o)
 */
fx32 FX_Sqrt(fx32 x)
{
    if (x > 0) {
        CP_SetSqrt64((u64)x << 32);
        return FX_GetSqrtResult();
    } else {
        return 0;
    }
}

/*
 * sdk:      FX_InvSqrt (libfx.TWL.HYB.a fx_cp.o)
 */
fx32 FX_InvSqrt(fx32 x)
{
    if (x > 0) {
        fx64 inv;

        FX_InvAsync(x);
        FX_SqrtAsync(x);
        inv = FX_GetDivResultFx64c();
        CP_WaitSqrt();
        return (fx32)((inv * reg_CP_SQRT_RESULT + ((fx64)0x200 << 32)) >> 42);
    } else {
        return 0;
    }
}

u64 FX_GetDivResultFx64c(void)
{
    while (*(volatile u16 *)REG_DIVCNT_ADDR & 0x8000)
        ;
    return *(u64 *)REG_DIV_RESULT_ADDR;
}

/*
 * Read the hardware divider result started by FX_DivAsync: poll DIVCNT
 * bit 15 until the unit is idle, then take the 64-bit DIV_RESULT, add
 * 0x80000 for rounding and shift right 20, keeping the low 32 bits.
 */
u32 FX_GetDivResult(void)
{
    u64 v;

    while (*(vu16 *)REG_DIVCNT_ADDR & 0x8000) {
        /* wait for the divider */
    }
    v = *(u64 *)REG_DIV_RESULT_ADDR;
    return (u32)((v + 0x80000) >> 20);
}

/*
 * sdk:      FX_InvAsync (libfx.TWL.HYB.a fx_cp.o)
 */
void FX_InvAsync(fx32 denom)
{
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = (u64)0x1000 << 32;
    reg_CP_DIV_DENOM = (u32)denom;
}

static inline void CP_SetSqrt64Plain(u64 param)
{
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM_PLAIN = param;
}

/*
 * sdk:      FX_SqrtAsync (libfx.TWL.HYB.a fx_cp.o)
 * notes:    the 64-bit CP parameter register is a plain (non-volatile) u64 lvalue; with a
 *           volatile u64 the two arms' high-word stores are not cross-jumped into one.
 */
void FX_SqrtAsync(fx32 x)
{
    if (x > 0) {
        CP_SetSqrt64Plain((u64)x << 32);
    } else {
        CP_SetSqrt64Plain(0);
    }
}

/*
 * sdk:      FX_GetSqrtResult (libfx.TWL.HYB.a fx_cp.o)
 */
fx32 FX_GetSqrtResult(void)
{
    CP_WaitSqrt();
    return (fx32)((CP_GetSqrtResult32() + (1 << 9)) >> 10);
}

/*
 * Start the hardware divider in 64/32 mode: DIVCNT = 1, the 64-bit
 * numerator is (numer << 32) (low word 0, high word the first argument),
 * the 32-bit denominator is the second argument.  The paired reader is
 * FX_GetDivResult, which waits on DIVCNT bit 15 and rounds the result.
 */
void FX_DivAsync(s32 numer, s32 denom)
{
    vu32 *base = (vu32 *)REG_DIVCNT_ADDR;

    *(vu16 *)base = 1;
    base[4] = 0;
    base[5] = numer;
    base[6] = denom;
    base[7] = 0;
}

s32 FX_DivS32(s32 numer, s32 denom)
{
    REG_DIVCNT = DIVCNT_MODE_32_32;
    REG_DIV_NUMER = numer;
    REG_DIV_DENOM = (u32)denom;
    while (REG_DIVCNT & DIVCNT_BUSY) {
        /* wait for the divider */
    }
    return REG_DIV_RESULT;
}

/*
 * sdk:      FX_ModS32 (libfx.TWL.HYB.a fx_cp.o)
 */
fx32 FX_ModS32(fx32 a, fx32 b)
{
    reg_CP_DIVCNT = 0;
    reg_CP_DIV_NUMER32 = (u32)a;
    reg_CP_DIV_DENOM = (u32)b;
    CP_WaitDiv();
    return (fx32)reg_CP_DIV_REM32;
}
