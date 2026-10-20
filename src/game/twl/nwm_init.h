#ifndef GAME_TWL_NWM_INIT_H
#define GAME_TWL_NWM_INIT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_init.c, prototypes copied from their definitions. */

struct CamBuf;
typedef struct CamBuf CamBuf;

#include "../types.h"

u32 NWM_Init(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode);
u32 NWMi_CheckInitialized(void);
u32 NWMi_CheckEnableFlag(void);
/* END mkheaders: generated region */

#endif
