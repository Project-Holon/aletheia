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
 * sdk:      MIC_StartLimitedSampling (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   OSi_IsCodecTwlMode  0x02087B20  arm
 *   MICEXi_StartLimitedSampling  0x02703C60  arm
 *   MIC_StartAutoSampling  0x0208B3EC  arm
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
extern MICResult MICEXi_StartLimitedSampling(MICAutoParam *param);
extern MICResult MIC_StartAutoSampling(MICAutoParam *param);

MICResult func_0208B500(MICAutoParam *param)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StartLimitedSampling(param);
    }
    return MIC_StartAutoSampling(param);
}
