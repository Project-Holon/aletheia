#ifndef GAME_ARM9_SYMBOL_SAVE_H
#define GAME_ARM9_SYMBOL_SAVE_H
struct SaveControl;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of symbol_save.c, prototypes copied from their definitions. */

struct SymbolSave;
struct SymbolRec;
struct SymbolBitSave;

#include "../types.h"

void SYMBOL_SAVE_UpdateChecksum(struct SymbolSave *save);
void SYMBOL_SAVE_FinalizeChecksum(struct SymbolSave *save);
u32 SYMBOL_SAVE_GetBlockSize(void);
void SYMBOL_SAVE_InitBlock(struct SymbolSave *save);
void *SYMBOL_SAVE_GetBlock(void *saveData);
u32 SYMBOL_SAVE_FindBand(u32 value);
u32 SYMBOL_SAVE_FindFreeSlot(const struct SymbolRec *records, int band);
void SYMBOL_SAVE_RemoveSlot(u32 *records, u32 index);
u32 SYMBOL_SAVE_RemoveSlotAndFind(struct SymbolSave *save, u32 band);
unsigned int SYMBOL_SAVE_FindBandThunk(unsigned int value);
void SYMBOL_SAVE_RemoveSlotAndCommit(struct SymbolSave *save, u32 index);
void SYMBOL_SAVE_WriteRecord(struct SymbolSave *save, u16 id, u16 param, u8 flags, u8 category, u8 status, u32 kind);
void SYMBOL_SAVE_SetRank(struct SymbolSave *save, int index);
u32 SYMBOL_SAVE_FindRecord(struct SaveControl *saveData, u32 *keyWord, u32 heapId, u32 matchMode);
int SYMBOL_SAVE_GetBitBlockSize(void);
void SYMBOL_SAVE_InitBitBlock(struct SymbolBitSave *save);
void *SYMBOL_SAVE_GetBitBlock(void *saveData);
u8 *SYMBOL_SAVE_GetQuestionnaireBits(struct SymbolBitSave *save);
u32 SYMBOL_SAVE_ReadBitField(const u8 *bits, int fieldId);
void SYMBOL_SAVE_WriteBitField(u8 *bits, int fieldId, u32 value);
void SYMBOL_SAVE_SetBitDescriptor(struct SymbolBitSave *save, int value, int index);
/* END mkheaders: generated region */

#endif
