#ifndef GAME_TWL_MICEX_H
#define GAME_TWL_MICEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of micex.c, prototypes copied from their definitions. */

#include "../arm9/mic.h"
#include "../types.h"

MICResult MICEXi_StartLimitedSampling(const MICAutoParam *param);
MICResult MICEXi_StartLimitedSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
u32 MICEXi_StopLimitedSampling(void);
u32 MICEXi_StopLimitedSamplingAsync(u32 callback, u32 arg);
void MicexSyncCallback(MICResult result, void *queue);
u32 MicexStartLimitedSampling(u32 addr, u32 len, u32 size, u32 flags);
u32 MicexStopLimitedSampling(void);
/* END mkheaders: generated region */

#endif
