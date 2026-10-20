#ifndef GAME_TWL_MICEX_H
#define GAME_TWL_MICEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of micex.c, prototypes copied from their definitions. */

#include "../types.h"

u32 MICEXi_StopLimitedSampling(void);
u32 MICEXi_StopLimitedSamplingAsync(u32 callback, u32 arg);
void MicexSyncCallback(u32 result, u32 queue);
u32 MicexStartLimitedSampling(u32 addr, u32 len, u32 size, u32 flags);
u32 MicexStopLimitedSampling(void);
/* END mkheaders: generated region */

#endif
