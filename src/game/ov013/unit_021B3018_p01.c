/*
 * file:     unit_021B3018_p01.c
 * unit:     yes
 * function: func_021B3278, func_021B3364, func_021B33E0
 * address:  0x021B3278
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B4C48  0x021B4C48  data  ov013
 *   d_021B3C60  0x021B3C60  data  a2
 *   d_021B50CC  0x021B50CC  data  a2
 *   d_021B4C74  0x021B4C74  data  a4
 *   d_021B4C5C  0x021B4C5C  data  a4
 *   MIi_CpuCopyFast              0x02082B0C  arm
 */
#include "../../matched/include/G_021B4C48.h"

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT_L (*(volatile u32 *)0x040002A0)
typedef short s16;

typedef int s32;

typedef unsigned short u16;

typedef unsigned int u32;

typedef long long s64;

typedef unsigned long long u64;

extern void MIi_CpuCopyFast(void);
s32 func_021B3278(s16 *x, u32 len);
void func_021B3364(void);
asm void sakeGetFileIdFromHeaders(void);
extern s32 d_021B4C48[];
extern s16 d_021B3C60[];
extern s16 d_021B50CC[];
extern int d_021B4C74[];
extern int d_021B4C5C[];


static inline void CP_SetDiv64_32(u64 numer, u32 denom)
{
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = numer;
    reg_CP_DIV_DENOM = denom;
}


static inline void CP_WaitDiv(void)
{
    while (reg_CP_DIVCNT & 0x8000) {
    }
}


s32 func_021B3278(s16 *x, u32 len)
{
    s32 prev;
    u32 i;
    s64 e;
    s32 y;
    s32 t;

    t = x[0] * 0xE9F;
    y = (t + d_021B4C48[1] + d_021B4C48[4] * 0xD3E) >> 12;
    d_021B4C48[4] = y;
    d_021B4C48[1] = prev = -t;
    e = y * y;
    len >>= 1;
    i = 1;
    if (len > 1) {
        do {
            t = x[i] * 0xE9F;
            x[i - 1] = y;
            y = (t + prev + y * 0xD3E) >> 12;
            e += y * y;
            prev = -t;
        } while (++i < len);
        d_021B4C48[1] = prev;
        d_021B4C48[4] = y;
    }
    (x + len)[-1] = y;
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = e;
    reg_CP_DIV_DENOM = len;
    CP_WaitDiv();
    return reg_CP_DIV_RESULT_L;
}


void func_021B3364(void)
{
    int i;
    s16 *src;

    src = d_021B3C60;
    ((int *)&d_021B4C48)[3] = 0;
    ((int *)&d_021B4C48)[2] = 0x19D;
    for (i = 0; i < 0x800; i++)
        d_021B50CC[i] = 0;
    for (i = 0; i < 6; i++) {
        d_021B4C74[i] = 0;
        d_021B4C5C[i] = src[i];
    }
}


asm void sakeGetFileIdFromHeaders(void)
{
	mov r2, r1
	ldr r1, =0x021B4C8C
	ldr ip, =MIi_CpuCopyFast
	bx ip
}
