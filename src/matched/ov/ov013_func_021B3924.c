/*
 * function: func_021B3924
 * address:  0x021B3924
 * packet:   pkt_ov013_021B3924
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  a4
 *   func_020870D0  0x020870D0  arm
 *   func_021B0F38  0x021B0F38  arm  ov013
 *   func_021B2488  0x021B2488  arm  ov013
 *
 * Needs #pragma opt_common_subs off (recoup 2026-10-05): without it the
 * type byte and its high nibble swap r2/r3 (6 bytes). Idiom
 * a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md lists the
 * per-function pragmas.
 */

typedef unsigned int       u32;
typedef unsigned char      u8;
typedef unsigned long long u64;

typedef struct {
    u32 magic;
    u8  type;
} Hdr;

extern int  d_021B60CC[];
extern u64  func_020870D0(void);
extern int func_021B0F38(int a0, Hdr *h, int a2, u64 t);
extern int  func_021B2488(int a0, Hdr *h, int a2, int *a3);

#pragma opt_common_subs off
int func_021B3924(int a0, Hdr *h, int a2, int *a3)
{
    u64 t;

    if (h == 0)
        return 0;
    if (h->magic != 0x5F564354)
        return 2;
    if (d_021B60CC[7] == 0 || d_021B60CC[2] == 0)
        return 0;
    a3[0] = 0;
    a3[1] = 0;
    t = func_020870D0();
    if ((h->type & 0xf0) == 0x40) {
        d_021B60CC[1]++;
        func_021B0F38(a0, h, a2, t);
        return 0;
    }
    if (h->type == 0 || h->type == 0xff)
        return func_021B2488(a0, h, a2, a3) != 0;
    return 0;
}
#pragma opt_common_subs reset
