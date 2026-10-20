#ifndef GAME_ARM9_SND_WORK_H
#define GAME_ARM9_SND_WORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of snd_work.c, prototypes copied from their definitions. */

struct SNDDriverInfo;
struct SNDTrackInfo;
typedef struct SNDDriverInfo SNDDriverInfo;
typedef struct SNDTrackInfo SNDTrackInfo;

#include "../types.h"
#include "../arm9/snd_shared_types.h"

u32 SND_GetPlayerStatus(void);
unsigned long SND_GetChannelStatus(void);
BOOL SND_ReadTrackInfo(SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);
unsigned long SNDi_GetFinishedCommandTag(void);
void SNDi_InitSharedWork(SNDSharedWork *work);
/* END mkheaders: generated region */

typedef struct SNDDriverInfo SNDDriverInfo;
typedef struct SNDTrackInfo SNDTrackInfo;

#endif
