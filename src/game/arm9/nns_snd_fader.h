#ifndef GAME_ARM9_NNS_SND_FADER_H
#define GAME_ARM9_NNS_SND_FADER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_fader.c, prototypes copied from their definitions. */

#include "../arm9/nns_snd_types.h"
#include "../types.h"

void NNSi_SndFaderSet(SndFader *fader, u32 target, u32 duration);
s32 NNS_SndFaderGet(SndFader *fader);
void NNS_SndFaderUpdate(SndFader *fader);
int NNS_SndFaderIsFinished(SndFader *fader);
/* END mkheaders: generated region */

#endif
