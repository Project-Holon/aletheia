/*
 * function: func_0208B4C8
 * address:  0x0208B4C8
 * packet:   pkt_0208B4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o.  Catalog calls this MIC_AdjustLimitedSamplingAsync,
 * but the member section that reproduces these bytes is
 * MIC_StartLimitedSamplingAsync (its TWL callee is MICEXi_StartLimitedSampling
 * Async); the catalog/DWARF disagree here.
 *
 * symbols:
 *   OSi_IsCodecTwlMode               0x02087B20  arm
 *   MICEXi_StartLimitedSamplingAsync 0x02703CDC  arm
 *   MIC_StartAutoSamplingAsync       0x0208B2BC  arm
 */

typedef long s32;

extern s32 OSi_IsCodecTwlMode(void);
extern s32 MICEXi_StartLimitedSamplingAsync(s32 a, s32 b, s32 c);
extern s32 MIC_StartAutoSamplingAsync(s32 a, s32 b, s32 c);

s32 func_0208B4C8(s32 a, s32 b, s32 c)
{
    if (OSi_IsCodecTwlMode() == 1) {
        return MICEXi_StartLimitedSamplingAsync(a, b, c);
    }
    return MIC_StartAutoSamplingAsync(a, b, c);
}
