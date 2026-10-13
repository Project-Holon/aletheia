/*
 * function: func_021B3084
 * address:  0x021B3084
 * packet:   pkt_ov013_021B3084
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Voice-activity gate: d_021B4C38 is a 4-entry ring of energies, the hardware
 * sqrt of the ring mean is compared with a threshold (d_021B4C2C.f0); returns
 * 0/1 (idle: start), 2 (active), 3 (active timed out).
 * Closed 2026-10-12 (lane F01): d_021B3C50 declared with a size under four bytes
 * puts all its accesses in the unknown-memory set, which gives the missing
 * alias between the d_021B4C2C.f4 store and the d_021B3C50 store.
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

typedef struct VadCfg { volatile u32 f0; u32 f4; s32 f8; } VadCfg;
typedef struct VadState { volatile u32 f0; u32 f4; s32 f8; } VadState;

/* under four bytes: every access is in the compiler's unknown-memory set */
extern u16 d_021B3C50;
#define CFG (*(VadCfg *)&d_021B3C50)
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

#pragma opt_propagation off
u32 func_021B3084(u32 x, u32 sq, u8 *out)
{
    u32 ret;
    u32 sum;
    int i;
    u32 root;

    CFG.f4 = sq >> 8;
    if (out != 0)
        *out = sq >> 8;
    if (CFG.f0 == 0) {
        i = sum = 0;
        do {
            sum += d_021B4C38[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        root = reg_CP_SQRT_RESULT;
        if (sq != 0 && sq >= (root << 1)) {
            u32 sum2;
            u32 j;
            VadState *p;
            u32 thr;

            j = sum2 = 0;
            do {
                sum2 += d_021B4C38[j];
                j++;
            } while (j < 4);
            CP_SetSqrt32(sum2 >> 2);
            CP_WaitSqrt();
            thr = (reg_CP_SQRT_RESULT * 3) >> 1;
            p = &d_021B4C2C;
            p->f0 = thr;
            d_021B4C2C.f4 = 0;
            CFG.f0 = 1;
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
        do {
            sum += d_021B4C38[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        if (reg_CP_SQRT_RESULT <= d_021B4C2C.f0) {
            d_021B4C2C.f8++;
            if (d_021B4C2C.f8 > CFG.f8) {
                CFG.f0 = 0;
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
#pragma opt_propagation reset
