#ifndef GAME_ARM9_NNS_FND_FRAMEHEAP_H
#define GAME_ARM9_NNS_FND_FRAMEHEAP_H

typedef struct NNSiFndFrmHeapHead NNSiFndFrmHeapHead;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_fnd_frameheap.c, prototypes copied from their definitions. */

struct NNSiFndFrmHeapHead;
typedef struct NNSiFndFrmHeapHead NNSiFndFrmHeapHead;

#include "../arm9/nns_fnd_types.h"
#include "../arm9/nns_fnd_types.h"
#include "../types.h"

NNSiFndHeapHead *NNSi_FndInitFrmHeap(NNSiFndHeapHead *pHeapHd, u32 heapEnd, u32 optFlag);
u32 NNSi_FndAllocFromFrmHeapHead(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align);
u32 NNSi_FndAllocFromFrmHeapTail(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align);
void NNSi_FndResetFrmHeapHead(NNSiFndHeapHead *pHeapHd);
void NNSi_FndResetFrmHeapState(NNSiFndHeapHead *pHeapHd);
void *NNS_FndCreateFrmHeap(void *mem, u32 size, u32 opt);
void NNS_FndDestroyFrmHeap(void *heap);
u32 NNS_FndAllocFromFrmHeapEx(char *p, int size, int align);
void NNS_FndFreeToFrmHeap(void *heap, int flags);
int NNS_FndRecordStateForFrmHeap(NNSiFndHeapHead *pHeapHd, u32 tagName);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);
/* END mkheaders: generated region */

#endif
