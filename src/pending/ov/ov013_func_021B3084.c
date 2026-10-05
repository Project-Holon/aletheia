/*
 * function: func_021B3084
 * address:  0x021B3084
 * packet:   pkt_ov013_021B3084
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * note 2026-10-05 (wave P5 lane T4): written from the listing, no twin found.
 * Voice-activity style gate: d_021B4C38 is a 4-entry ring of energies, the
 * hardware sqrt of the ring mean is compared to a threshold (d_021B4C2C.f0);
 * returns 0/1 (idle: start), 2 (active), 3 (active timed out). 17 bytes differ,
 * 1 block: in the start path the compiler keeps the sqrt result in ip and loads
 * the d_021B3C50 pool word before the *3 >> 1, the original keeps r1 for the
 * result, puts mov lr,#1 in the load stall and loads the pool word after.
 * Closed by: separate loop counters (int i, block-local u32 j), i = sum = 0
 * chains, ring read before the compare (root local), return-3 tail with
 * if (res <= thr) { ... } else f8 = 0; ret = 2 after the join. Tried without
 * effect: all six per-function pragmas, ret = 1 earlier, chained
 * d_021B3C50.f0 = ret = 1, inline ring-rms helper (worse).
 *
 * symbols:
 *   d_021B3C50  0x021B3C50  data  a4
 *   d_021B4C38  0x021B4C38  data  a4
 *   d_021B4C2C  0x021B4C2C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define reg_CP_SQRTCNT       (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT   (*(volatile u32 *)0x040002B4)
#define reg_CP_SQRT_PARAM    (*(volatile u32 *)0x040002B8)

typedef struct VadCfg { u32 f0; u32 f4; s32 f8; } VadCfg;
typedef struct VadState { u32 f0; u32 f4; s32 f8; } VadState;

extern VadCfg d_021B3C50;
extern u32 d_021B4C38[];
extern VadState d_021B4C2C;

static inline void CP_SetSqrt32(u32 v)
{
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM = v;
}

static inline void CP_WaitSqrt(void)
{
    while (reg_CP_SQRTCNT & 0x8000) {
    }
}

u32 func_021B3084(u32 x, u32 sq, u8 *out)
{
    u32 ret;
    u32 sum;
    int i;
    u32 root;

    d_021B3C50.f4 = sq >> 8;
    if (out != 0)
        *out = sq >> 8;
    if (d_021B3C50.f0 == 0) {
        i = sum = 0;
        for (; i < 4; i++)
            sum += d_021B4C38[i];
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        root = reg_CP_SQRT_RESULT;
        if (sq != 0 && sq >= (root << 1)) {
            u32 sum2;
            u32 j;

            j = sum2 = 0;
            for (; j < 4; j++)
                sum2 += d_021B4C38[j];
            CP_SetSqrt32(sum2 >> 2);
            CP_WaitSqrt();
            d_021B4C2C.f0 = (reg_CP_SQRT_RESULT * 3) >> 1;
            d_021B4C2C.f4 = 0;
            d_021B3C50.f0 = 1;
            ret = 1;
        } else {
            ret = 0;
        }
        d_021B4C38[d_021B4C2C.f4] = x;
        d_021B4C2C.f4 = (d_021B4C2C.f4 + 1) & 3;
    } else {
        d_021B4C38[d_021B4C2C.f4] = x;
        d_021B4C2C.f4 = (d_021B4C2C.f4 + 1) & 3;
        i = sum = 0;
        for (; i < 4; i++)
            sum += d_021B4C38[i];
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        if (reg_CP_SQRT_RESULT <= d_021B4C2C.f0) {
            d_021B4C2C.f8++;
            if (d_021B4C2C.f8 > d_021B3C50.f8) {
                d_021B3C50.f0 = 0;
                d_021B4C2C.f8 = 0;
                d_021B4C2C.f4 = 0;
                return 3;
            }
        } else {
            d_021B4C2C.f8 = 0;
        }
        ret = 2;
    }
    return ret;
}
