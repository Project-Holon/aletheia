/*
 * function: VCT_SESSION_MixVoices
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
 *   gVctSendState  0x021B3C84  data  ov013  a4
 *   gVctMixScratch  0x021B3E78  data  ov013  a4
 *   VCT_SESSION_ReadChannel  0x021B0904  arm  ov013
 *   VCT_DSP_MixSaturated  0x021B3624  arm  ov013
 *   VCT_DSP_SetEchoReference  0x021B33E0  arm  ov013
 *   MIi_CpuClearFast  0x02082AC0  arm
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

extern Ctx3C84 gVctSendState;
extern u8 gVctMixScratch[];

typedef signed short   s16;
extern int VCT_SESSION_ReadChannel(void *dst, u32 size, u32 idx, u32 *mask);
extern void VCT_DSP_MixSaturated(s16 *a, s16 *b, s16 *d, u32 len);
extern void VCT_DSP_SetEchoReference(void *a, u32 b);
extern void MIi_CpuClearFast(int x, void *a, u32 b);
extern void MIi_CpuClearFast(int x, void *a, u32 b);

int VCT_SESSION_MixVoices(void *a, u32 b, int *out)
{
    int ret;
    u32 i;
    u32 j;

    if (out != 0)
        *out = 0;

    ret = 0;
    if (b == gVctSendState.f24 && gVctSendState.f20 != 0) {
        for (i = 0; i < 3; i++) {
            if (VCT_SESSION_ReadChannel(a, b, i, (u32 *)out) == 1) {
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
                    if (VCT_SESSION_ReadChannel(gVctMixScratch, b, j, (u32 *)out) == 1)
                        VCT_DSP_MixSaturated(a, (s16 *)gVctMixScratch, a, b);
                }
            }
        } else {
            MIi_CpuClearFast(0, a, b);
        }
    } else {
        ret = 0;
        MIi_CpuClearFast(ret, a, b);
    }

    if (gVctSendState.f18 != 0)
        VCT_DSP_SetEchoReference(a, b);
    return ret;
}
