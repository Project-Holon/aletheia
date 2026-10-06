/*
 * function: func_021B0B48
 * address:  0x021B0B48
 * packet:   pkt_ov013_021B0B48
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The two MIi_CpuClearFast calls (found==0 arm, failed-guard arm) are
 * kept apart in the original; under one extern name 1.1p1 cross-jumps the
 * two `bl`s into one (4 bytes short, see docs/notes/pkt_ov013_021B0B48.c.txt).
 * Two extern names for 0x02082AC0 give two independent call sites, the
 * call-site form of
 * docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 * `j = i + 1; if (j == 3) ret = 1; else for (...)` is what gives the
 * original's `cmp sb,#3; moveq r4,#1; beq; bhs`.
 *
 * symbols:
 *   d_021B3C84  0x021B3C84  data  ov013  a4
 *   d_021B3E78  0x021B3E78  data  ov013  a4
 *   func_021B0904  0x021B0904  arm  ov013
 *   func_021B3624  0x021B3624  arm  ov013
 *   func_021B33E0  0x021B33E0  arm  ov013
 *   func_02082AC0  0x02082AC0  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x18];
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Ctx3C84;

extern Ctx3C84 d_021B3C84;
extern u8 d_021B3E78[];

typedef signed short   s16;
extern int func_021B0904(void *dst, u32 size, u32 idx, u32 *mask);
extern void func_021B3624(s16 *a, s16 *b, s16 *d, u32 len);
extern void func_021B33E0(void *a, u32 b);
extern void func_02082AC0(int x, void *a, u32 b);
extern void MIi_CpuClearFast(int x, void *a, u32 b);

int func_021B0B48(void *a, u32 b, int *out)
{
    int ret;
    u32 i;
    u32 j;

    if (out != 0)
        *out = 0;

    ret = 0;
    if (b == d_021B3C84.f24 && d_021B3C84.f20 != 0) {
        for (i = 0; i < 3; i++) {
            if (func_021B0904(a, b, i, (u32 *)out) == 1) {
                ret = 1;
                break;
            }
        }
        if (ret != 0) {
            j = i + 1;
            if (j == 3) {
                ret = 1;
            } else {
                for (; j < 3; j++) {
                    if (func_021B0904(d_021B3E78, b, j, (u32 *)out) == 1)
                        func_021B3624(a, (s16 *)d_021B3E78, a, b);
                }
            }
        } else {
            MIi_CpuClearFast(0, a, b);
        }
    } else {
        ret = 0;
        func_02082AC0(ret, a, b);
    }

    if (d_021B3C84.f18 != 0)
        func_021B33E0(a, b);
    return ret;
}
