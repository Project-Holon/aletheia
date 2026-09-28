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
 * notes:    31 bytes differ: the image if-converts both arms and shares the high-word store; this C ends the gt arm with bxgt. Permuter seeds 12602, 12603 did not close it. Pass 2 (sdk9w2_fxmisc): gt-first/le-first, ternary, early return, direct register writes, split u32 param stores, x=0 reassignment and permuter seed 13603 all keep a 5-instruction gt arm ending in bxgt lr; the image's arms are 4 instructions each with the high-word store after the join, so the merge happened before if-conversion.
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

void func_0207C8D0(fx32 x)
{
    if (x <= 0) {
        CP_SetSqrt64(0);
    } else {
        CP_SetSqrt64((u64)x << 32);
    }
}
