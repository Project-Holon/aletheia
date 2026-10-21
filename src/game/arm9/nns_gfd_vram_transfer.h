#ifndef GAME_ARM9_NNS_GFD_VRAM_TRANSFER_H
#define GAME_ARM9_NNS_GFD_VRAM_TRANSFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_gfd_vram_transfer.c, prototypes copied from their definitions. */

struct GfdLnkBlock;
struct GfdLnkRange;
struct GfdLnkBlockList;
struct GfdLnkBlockPool;

#include "../types.h"

void NNS_GfdDoVramTransfer(void);
s32 NNS_GfdRegisterNewVramTransferTask(u32 type, u32 dstOffset, void *pSrc, s32 szByte);
u32 NNSi_GfdMergeAdjacentFreeBlocks(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, struct GfdLnkRange *range);
void NNSi_GfdClearBlockListHead(struct GfdLnkBlock **ppHead);
struct GfdLnkBlock *NNSi_GfdInitBlockPool(struct GfdLnkBlock *blocks, u32 count);
u32 NNSi_GfdAddBlock(struct GfdLnkBlockList *list, struct GfdLnkBlockPool *pool, u32 start, u32 size);
int NNSi_GfdAllocBlockUnaligned(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, u32 *pAddr, u32 size);
/* END mkheaders: generated region */

#endif
