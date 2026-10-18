/*
 * function: NNS_G3dRenderObjInit
 * address:  0x02069D14
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * cap:      literal - 0x020A823C (data) has no witness outside 0x02069D14..0x02069D68;
 *           the second pool word of the same word-run (0x020A8238 / 0x020A8234)
 *           resolves as data_table, this one occurs only inside the compared range.
 *           All 17 instructions and the two other pool words are byte-identical.
 * symbols:
 *   gNNSiG3dFuncBlendVisDefault     0x020A8234  data
 *   gNNSiG3dFuncBlendJntDefault     0x020A8238  data
 *   gNNSiG3dFuncBlendMatDefault     0x020A823C  data
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 gNNSiG3dFuncBlendVisDefault;
extern u32 gNNSiG3dFuncBlendJntDefault;
extern u32 gNNSiG3dFuncBlendMatDefault;
extern void MIi_CpuClear32(u32 val, void *dst, u32 len);

typedef struct {
    u8  pad00[4];
    u32 f04;
    u8  pad08[4];
    u32 f0c;
    u8  pad10[4];
    u32 f14;
    u8  pad18[4];
    u32 f1c;
} S;

void NNS_G3dRenderObjInit(S *p, u32 b)
{
    MIi_CpuClear32(0, p, 0x54);
    p->f0c = gNNSiG3dFuncBlendMatDefault;
    p->f14 = gNNSiG3dFuncBlendJntDefault;
    p->f1c = gNNSiG3dFuncBlendVisDefault;
    p->f04 = b;
}
