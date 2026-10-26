#ifndef GAME_OV119_POKEMONTRADE_MCSS_H
#define GAME_OV119_POKEMONTRADE_MCSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_mcss.c, prototypes copied from their definitions. */

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_MCSS_SlideBegin(McssSlide *slide, int frameCount, void *targetPos);
void *POKETRADE_MCSS_SlideCreate(void *mcss, int frameCount, void *targetPos, u32 heapId);
void *POKETRADE_MCSS_SlideCreateWithOffsets(void *mcss, int frameCount, void *targetPos, void *offsetTable, u16 heapId);
int POKETRADE_MCSS_SlideInterpolate(int startValue, int targetValue, McssSlide *slide, int allowWobble);
void POKETRADE_MCSS_SlideApplyOffset(McssSlide *slide, void *eventArg);
void POKETRADE_MCSS_SlideUpdate(McssSlide *slide, void *eventArg);
void POKETRADE_MCSS_StopAnimation(void *param, u32 frame);
/* END mkheaders: generated region */

#endif
