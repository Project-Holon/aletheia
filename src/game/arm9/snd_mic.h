#ifndef GAME_ARM9_SND_MIC_H
#define GAME_ARM9_SND_MIC_H

/* Public functions of snd_mic.c, prototypes copied from their definitions. */

struct MICAutoParam;
struct PerapVoice;

#include "../types.h"
#include "../arm9/mic.h"

void SND_MIC_Init(u16 heapId);
void SND_MIC_Exit(void);
void SND_MIC_AddElapsed(u32 ticks);
u32 SND_MIC_IsLimitReached(void);
u32 SND_MIC_StartSampling(const struct MICAutoParam *param);
u32 SND_MIC_StartRecording(MICCallback callback, void *arg);
void SND_MIC_StoreRecording(struct PerapVoice *perapVoice);
void *SND_MIC_GetBufferAligned(void);

#endif
