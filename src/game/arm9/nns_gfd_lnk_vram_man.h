#ifndef GAME_ARM9_NNS_GFD_LNK_VRAM_MAN_H
#define GAME_ARM9_NNS_GFD_LNK_VRAM_MAN_H

#include "../types.h"

typedef struct NNSiGfdLnkBlock {
    u32 addr;
    u32 size;
    struct NNSiGfdLnkBlock *prev;
    struct NNSiGfdLnkBlock *next;
} NNSiGfdLnkBlock;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_gfd_lnk_vram_man.c, prototypes copied from their definitions. */

#include "../types.h"

BOOL NNSi_GfdAllocLnkVram(NNSiGfdLnkBlock **list, NNSiGfdLnkBlock **pool, u32 *pRet, u32 size, u32 alignment);
void NNSi_GfdMergeFreeBlockList(u32 *pp, u32 *arg);
int NNSi_GfdFreeLnkVram(void *headp, void *freep, int addr, int szByte);
int NNSi_GfdSizeToGranuleTex(int v);
void NNSi_GfdInitTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork, u32 useAsDefault);
u32 NNS_GfdAllocTexVram(u32 size, u32 flag, u32 opt);
u32 NNS_GfdFreeTexVram(u32 h);
void NNSi_GfdInitTexVramHeap(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork);
int NNSi_GfdSizeToGranulePltt(int v);
void NNSi_GfdInitPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, u32 useAsDefault);
u32 NNS_GfdAllocPlttVram(u32 size, u32 flag);
int NNS_GfdFreePlttVram(u32 id);
void NNSi_GfdInitPlttVramHeap(void);
/* END mkheaders: generated region */

#endif
