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
 * sdk:      MIC_StartLimitedSamplingAsync (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   OSi_IsCodecTwlMode  0x02087B20  arm
 *   MICEXi_StartLimitedSamplingAsync  0x02703CDC  arm
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
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
extern MICResult MICEXi_StartLimitedSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg);
extern MICResult MIC_StartAutoSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg);

MICResult func_0208B4C8(MICAutoParam *param, MICCallback callback, void *arg)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StartLimitedSamplingAsync(param, callback, arg);
    }
    return MIC_StartAutoSamplingAsync(param, callback, arg);
}
