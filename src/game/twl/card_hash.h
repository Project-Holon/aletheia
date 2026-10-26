#ifndef GAME_TWL_CARD_HASH_H
#define GAME_TWL_CARD_HASH_H

#include "../types.h"
#include "../arm9/os_thread.h"

typedef struct CardHashNode {
    struct CardHashNode *next;
    u32 key;
    u32 offset;
    u8 *data;
    u8 *buffer;
} CardHashNode;

typedef struct Node16 {
    struct Node16 *next;
    int key;
    u32 offset;
    u8 *data;
} Node16;

/* ROM header fields read by CARD_InitRomHashContext */
typedef struct {
    char pad0[0x1e0];
    u32 ntrAreaOffset, ntrAreaLength, ltdAreaOffset, ltdAreaLength, sectorHashOffset, sectorHashLength, blockHashOffset, blockHashLength, sectorSize, blockSectorCount;
    char pad1[0x328 - 0x208];
    u32 digest[5];
} RomHdr;

typedef struct {
    u32 ntrAreaOffset;
    u32 ntrAreaLength;
    u32 ltdAreaOffset;
    u32 ltdAreaLength;
    u32 sectorHashOffset;
    u32 sectorHashLength;
    u32 blockHashOffset;
    u32 blockHashLength;
    u32 sectorSize;
    u32 blockSectorCount;
    u32 blockCacheCount;
    u32 sectorCacheCount;
    void *userData;
    int (*readCallback)(void *, void *, u32, u32);
    int (*asyncReadCallback)(void *, void *, u32, u32);
    OSThread *thread;
    CardHashNode *cur;
    CardHashNode *free_a;
    CardHashNode *used_a;
    CardHashNode *cache_a;
    CardHashNode *free_b;
    CardHashNode *used_b;
    CardHashNode *cache_b;
    u8 *hash;
    u8 *l0;
    u8 *l1;
    Node16 *l2;
    CardHashNode *l3;
} CardHash;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_hash.c, prototypes copied from their definitions. */

#include "../types.h"

u32 CARD_CalcRomHashBufferLength(const void *romHeader);
void CARDi_CompareHash(const u32 *expect, void *data, u32 len);
void CARDi_StartLoading(CardHash *obj);
void CARD_NotifyRomHashReadAsync(void *arg);
CardHashNode *CARDi_TouchRomHashBlock(CardHash *obj, u32 sector);
u8 *CARDi_TouchRomHashSector(CardHash *obj, u32 addr);
void CARD_InitRomHashContext(CardHash *obj, const RomHdr *hdr, u8 *base, u32 size, int (*cb34)(void *, void *, u32, u32), int (*cb38)(void *, void *, u32, u32), void *arg30);
void CARDi_ReadRomHashImageDirect(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARDi_ReadRomHashImageCaching(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARD_ReadRomHashImage(CardHash *obj, u8 *buf, u32 off, u32 len);
/* END mkheaders: generated region */

#endif
