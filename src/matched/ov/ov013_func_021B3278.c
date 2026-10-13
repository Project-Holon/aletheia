/*
 * function: VCT_DSP_HighPassFilter
 * address:  0x021B3278
 * packet:   pkt_ov013_021B3278
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gEchoState  0x021B4C48  data  ov013
 */

typedef short s16;
typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT_L (*(volatile u32 *)0x040002A0)

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

extern s32 gEchoState[];

s32 VCT_DSP_HighPassFilter(s16 *x, u32 len)
{
    s32 prev;
    u32 i;
    s64 e;
    s32 y;
    s32 t;

    t = x[0] * 0xE9F;
    y = (t + gEchoState[1] + gEchoState[4] * 0xD3E) >> 12;
    gEchoState[4] = y;
    gEchoState[1] = prev = -t;
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
        gEchoState[1] = prev;
        gEchoState[4] = y;
    }
    (x + len)[-1] = y;
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = e;
    reg_CP_DIV_DENOM = len;
    CP_WaitDiv();
    return reg_CP_DIV_RESULT_L;
}
