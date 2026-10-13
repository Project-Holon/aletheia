/*
 * function: NNSi_G3dAnmGetScaleData
 * address:  0x0206F4C8
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Vector-2 keyframe sampler without the lerp (NNSi_G3dAnmCalcJntAnmNode calls it when the
 * cursor has no fraction or root->f08 bit 0 is clear): the NitroSystem G3D
 * joint-animation scale fetch, which reads a (scale, inverse scale) pair per
 * key.  Written from the start in the library's shape (wave 20, lane
 * nns_fresh): the NNS_G3D_JNTANM_SINFO_* step / last-interp / fx16 flags,
 * the frame through FX_Whole, one pArray base, the goto SCALE_NONINTERP /
 * SCALE_INTERP_2 tails and the inline 1:3 blend, keys as (s, invs) pair
 * structs.  The NitroSystem name of the routine is not attested in this
 * repository; the identifiers follow the library's style only.
 *
 * Compiler pin ../2.0/sp2p2, the family pin (docs/families/cluster_0206EB00.h,
 * "64-bit multiply by a constant"): ../2.0/sp2 and dsi/1.1p1 both DIFF.
 *
 * Source levers, all read off the image:
 *   - frame taken before pArray and info, so pArray reuses Frame's r1;
 *   - keys indexed through pair structs (a flat fx16/fx32 array with 2 * idx
 *     emits an extra lsl per key, 556 bytes);
 *   - SCALE_INTERP_2 through one element pointer `base + idx` read at [0]
 *     and [1] (array subscripts at idx and idx + 1 form idx + 1 separately);
 *   - fx32 1:3 blend through element pointers for idx and idx_sub and the
 *     64-bit product named, `w = (fx64)v * 3; (w + v_sub) >> 2`, which puts
 *     the product first in the adds (the unnamed sum canonicalises to
 *     v_sub first, the old 2-byte residue);
 *   - fx16 1:3 blend by array subscript with the base advanced to the
 *     idx_sub element for the second key, so that address forms in the
 *     base's dying register.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmGetScaleData.c \
 *       --func NNSi_G3dAnmGetScaleData --addr 0x0206F4C8 --cc ../2.0/sp2p2 --arm
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;
typedef long long      s64;
typedef s16 fx16;
typedef s32 fx32;
typedef s64 fx64;

#define FX32_SHIFT 12
#define FX_Whole(a) ((s32)((a) >> FX32_SHIFT))

#define NNS_G3D_JNTANM_SINFO_STEP_MASK       0xc0000000
#define NNS_G3D_JNTANM_SINFO_STEP_2          0x40000000
#define NNS_G3D_JNTANM_SINFO_STEP_4          0x80000000
#define NNS_G3D_JNTANM_SINFO_FX16ARRAY       0x20000000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK 0x1fff0000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT 16

typedef struct { u32 info; u32 offset; } NNSG3dJntAnmSInfo;
typedef struct { fx16 s; fx16 invs; } ScaleFx16;
typedef struct { fx32 s; fx32 invs; } ScaleFx32;

void NNSi_G3dAnmGetScaleData(fx32 *s_invs, fx32 Frame, const NNSG3dJntAnmSInfo *pData, const u8 *pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const void *pArray = (const void *)(pJntAnm + pData->offset);
    u32 info = pData->info;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK))
    {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    last_interp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2)
    {
        if (frame & 1)
        {
            if (frame > last_interp)
            {
                idx = (last_interp >> 1) + 1;
                goto SCALE_NONINTERP;
            }
            else
            {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    }
    else
    {
        if (frame & 3)
        {
            if (frame > last_interp)
            {
                idx = (last_interp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1)
            {
                fx32 v, v_sub;

                if (frame & 2)
                {
                    idx_sub = frame >> 2;
                    idx = idx_sub + 1;
                }
                else
                {
                    idx = frame >> 2;
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
                {
                    const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray;

                    v = p_fx16[idx].s;
                    v_sub = p_fx16[idx_sub].s;
                    s_invs[0] = (v * 3 + v_sub) >> 2;

                    v = p_fx16[idx].invs;
                    p_fx16 += idx_sub;
                    v_sub = p_fx16->invs;
                    s_invs[1] = (v * 3 + v_sub) >> 2;
                }
                else
                {
                    const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray + idx;
                    const ScaleFx32 *p_fx32_sub = (const ScaleFx32 *)pArray + idx_sub;

                    fx64 w;

                    v = p_fx32->s;
                    v_sub = p_fx32_sub->s;
                    w = (fx64)v * 3;
                    s_invs[0] = (fx32)((w + v_sub) >> 2);

                    v = p_fx32->invs;
                    v_sub = p_fx32_sub->invs;
                    w = (fx64)v * 3;
                    s_invs[1] = (fx32)((w + v_sub) >> 2);
                }

                return;
            }
            else
            {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }

SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray;
        s_invs[0] = p_fx16[idx].s;
        s_invs[1] = p_fx16[idx].invs;
    }
    else
    {
        const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray;
        s_invs[0] = p_fx32[idx].s;
        s_invs[1] = p_fx32[idx].invs;
    }
    return;

SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray + idx;
        s_invs[0] = (p_fx16[0].s + p_fx16[1].s) >> 1;
        s_invs[1] = (p_fx16[0].invs + p_fx16[1].invs) >> 1;
    }
    else
    {
        const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray + idx;
        s_invs[0] = (p_fx32[0].s + p_fx32[1].s) >> 1;
        s_invs[1] = (p_fx32[0].invs + p_fx32[1].invs) >> 1;
    }
}
