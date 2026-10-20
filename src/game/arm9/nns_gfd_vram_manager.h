#ifndef GAME_ARM9_NNS_GFD_VRAM_MANAGER_H
#define GAME_ARM9_NNS_GFD_VRAM_MANAGER_H

typedef struct NNSiFndObject NNSiFndObject;
typedef struct NNSG2dCellBank NNSG2dCellBank;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_gfd_vram_manager.c, prototypes copied from their definitions. */

struct NNSiFndObject;
struct NNSG2dCellBank;
typedef struct NNSiFndObject NNSiFndObject;
typedef struct NNSG2dCellBank NNSG2dCellBank;

#include "../types.h"

void *NNS_FndAllocFromAllocator(NNSiFndObject *o, u32 x);
void NNS_FndFreeToAllocator(NNSiFndObject *o, u32 x);
void NNS_FndInitAllocatorForExpHeap(NNSG2dCellBank *s, u32 a, u32 b);
int NNS_G2dStubReturnZeroA(void);
int NNS_G2dStubReturnMinusOneA(void);
int NNS_G2dStubReturnZeroB(void);
int NNS_G2dStubReturnMinusOneB(void);
void NNSi_GfdSetTexVramSlotOrder(u32 a, u32 b, u32 c, u32 d, u32 e);
void NNS_GfdInitVramManager(u32 mode, u32 flag);
void NNSi_GfdUpdateVramManager(void);
u32 NNSi_GfdDefaultAllocTexVram(u32 size, u32 which);
u32 NNSi_GfdDefaultFreeTexVram(void);
void NNS_GfdSaveVramManager(u32 *dst);
void NNS_GfdLoadVramManager(u32 *src);
/* END mkheaders: generated region */

#endif
