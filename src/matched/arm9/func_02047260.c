/*
 * function: G3D_SYSTEM_AllocTexVramKeys
 * address:  0x02047260
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dTexGetRequiredSize  0x02069FD0  arm
 *   NNS_G3dTex4x4GetRequiredSize  0x02069FE4  arm
 *   NNS_GfdDefaultFuncAllocTexVram     0x020A8140  data
 *
 * The two probes are looked up independently; the same dispatcher is called
 * for each, once in mode 0 and once in mode 1, with the first probe's handle
 * (which is necessarily null in the second branch) in r0.  Either failure
 * report is a bare zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_AllocTexVramKeys.c \
 *       --func G3D_SYSTEM_AllocTexVramKeys --addr 0x02047260 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(void *p, u32 mode, u32 a2);

extern int NNS_G3dTexGetRequiredSize(int p);
extern int NNS_G3dTex4x4GetRequiredSize(int p);

int G3D_SYSTEM_AllocTexVramKeys(u32 a0, u32 *a1, u32 *a2)
{
    void *p = (void *)NNS_G3dTexGetRequiredSize(a0);
    void *q = (void *)NNS_G3dTex4x4GetRequiredSize(a0);

    if (p != 0) {
        *a1 = NNS_GfdDefaultFuncAllocTexVram(p, 0, 0);
        if (*a1 == 0)
            return 0;
    }
    if (q != 0) {
        *a2 = NNS_GfdDefaultFuncAllocTexVram(p, 1, 0);
        if (*a2 == 0)
            return 0;
    }
    return 1;
}
