/*
 * function: func_0208B528
 * address:  0x0208B528
 * packet:   pkt_0208B528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o, catalog name MIC_StopLimitedSampling.  Dispatches to
 * the TWL codec variant when the codec is in TWL mode, else the DS path.
 *
 * symbols:
 *   OSi_IsCodecTwlMode           0x02087B20  arm
 *   MICEXi_StopLimitedSampling   0x02703E90  arm
 *   MIC_StopAutoSampling         0x0208B480  arm
 */

typedef long s32;

extern s32 OSi_IsCodecTwlMode(void);
extern s32 MICEXi_StopLimitedSampling(void);
extern s32 MIC_StopAutoSampling(void);

s32 func_0208B528(void)
{
    if (OSi_IsCodecTwlMode() == 1) {
        return MICEXi_StopLimitedSampling();
    }
    return MIC_StopAutoSampling();
}
