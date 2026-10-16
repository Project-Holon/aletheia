/*
 * function: MIC_StopLimitedSampling
 * address:  0x0208B528
 * packet:   pkt_0208B528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIC_StopLimitedSampling (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   OSi_IsCodecTwlMode  0x02087B20  arm
 *   MICEXi_StopLimitedSampling  0x02703E90  arm
 *   MIC_StopAutoSampling  0x0208B480  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

typedef enum MICResult
{
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY = 1,
    MIC_RESULT_ILLEGAL_PARAMETER = 2,
    MIC_RESULT_SEND_ERROR = 3
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

typedef struct MICAutoParam MICAutoParam;

extern BOOL OSi_IsCodecTwlMode(void);
extern MICResult MICEXi_StopLimitedSampling(void);
extern MICResult MIC_StopAutoSampling(void);

MICResult MIC_StopLimitedSampling(void)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StopLimitedSampling();
    }
    return MIC_StopAutoSampling();
}
