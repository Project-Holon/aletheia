/*
 * function: func_0208B500
 * address:  0x0208B500
 * packet:   pkt_0208B500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o, catalog name MIC_AdjustLimitedSampling.  Dispatches to
 * the TWL codec variant when the codec is in TWL mode, else the DS path.
 *
 * symbols:
 *   OSi_IsCodecTwlMode             0x02087B20  arm
 *   MICEXi_AdjustLimitedSampling   0x02703C60  arm
 *   MIC_AdjustAutoSampling         0x0208B3EC  arm
 */

typedef long s32;

extern s32 OSi_IsCodecTwlMode(void);
extern s32 MICEXi_AdjustLimitedSampling(s32 arg);
extern s32 MIC_AdjustAutoSampling(s32 arg);

s32 func_0208B500(s32 arg)
{
    if (OSi_IsCodecTwlMode() == 1) {
        return MICEXi_AdjustLimitedSampling(arg);
    }
    return MIC_AdjustAutoSampling(arg);
}
