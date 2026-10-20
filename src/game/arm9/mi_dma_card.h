#ifndef GAME_ARM9_MI_DMA_CARD_H
#define GAME_ARM9_MI_DMA_CARD_H

/* Public functions of mi_dma_card.c, prototypes copied from their definitions. */

#include "../types.h"

void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);

#endif
