#ifndef GAME_ARM9_NNS_SND_MAIN_H
#define GAME_ARM9_NNS_SND_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_main.c, prototypes copied from their definitions. */

#include "../arm9/nns_snd_main_types.h"
#include "../types.h"
#include "../arm9/nns_snd_arc_types.h"

void NNSi_SndStrmStart(NNSSndStrm *strm);
void NNSi_SndMainReset(void);
void NNS_SndMain(void);
void NNSi_SndShutdown(void);
void NNS_SndStartTimer(void);
void NNSi_SndCaptureReset(void);
u32 NNS_SndArcInit(NNSSndArc *arc, const char *path, u32 *heap, u32 loadSymbols);
u32 NNSi_SndArcLoadTables(NNSSndArc *arc, u32 *heap, u32 loadSymbols);
void NNS_SndArcInitOnMemory(NNSSndArc *arc, u8 *base);
/* END mkheaders: generated region */

#endif
