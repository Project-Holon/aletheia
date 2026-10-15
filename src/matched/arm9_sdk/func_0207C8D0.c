/*
 * function: FX_SqrtAsync
 * address:  0x0207C8D0
 * packet:   pkt_0207C8D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FX_SqrtAsync (libfx.TWL.HYB.a fx_cp.o)
 * notes:    the 64-bit CP parameter register is a plain (non-volatile) u64 lvalue; with a
 *           volatile u64 the two arms' high-word stores are not cross-jumped into one.
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_PARAM   (*(u64 *)0x040002B8)

static inline void CP_SetSqrt64(u64 param)
{
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = param;
}

void FX_SqrtAsync(fx32 x)
{
    if (x > 0) {
        CP_SetSqrt64((u64)x << 32);
    } else {
        CP_SetSqrt64(0);
    }
}
