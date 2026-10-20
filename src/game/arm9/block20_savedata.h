#ifndef GAME_ARM9_BLOCK20_SAVEDATA_H
#define GAME_ARM9_BLOCK20_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of block20_savedata.c, prototypes copied from their definitions. */

struct CGearSave;
struct CgearSaveBlock;
struct CgearSaveRecord;

#include "../types.h"

u32 BLOCK20_SAVEDATA_TestPanelMark(const struct CGearSave *save, int row, int col, int kind);
void BLOCK20_SAVEDATA_SetPanelMark(struct CGearSave *save, int row, int col, int kind, int marked, int flagged);
void BLOCK20_SAVEDATA_InitPanelMarks(void);
void BLOCK20_SAVEDATA_SetPanelState(struct CGearSave *save, u8 value);
u8 BLOCK20_SAVEDATA_GetPanelState(const struct CGearSave *save);
struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlock(void *sys);
struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlockFromSys(void *p);
u32 BLOCK20_SAVEDATA_GetBlockSize(void);
void BLOCK20_SAVEDATA_InitBlock(struct CgearSaveBlock *block);
u8 *BLOCK20_SAVEDATA_GetPokemon(struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetPokemon(struct CgearSaveBlock *block, const void *src);
u32 BLOCK20_SAVEDATA_TestBit(const u8 *bits, int n);
void BLOCK20_SAVEDATA_SetMode(struct CgearSaveBlock *block, u8 value);
u8 BLOCK20_SAVEDATA_GetMode(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetPending(struct CgearSaveBlock *block, u8 value);
u8 BLOCK20_SAVEDATA_GetPending(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetActive(struct CgearSaveBlock *block, u8 value);
u8 BLOCK20_SAVEDATA_GetActive(const struct CgearSaveBlock *block);
u16 BLOCK20_SAVEDATA_GetEntryId(const struct CgearSaveBlock *block, int index);
u8 BLOCK20_SAVEDATA_GetEntryValue(const struct CgearSaveBlock *block, int index);
void BLOCK20_SAVEDATA_SetEntry(struct CgearSaveBlock *block, int index, u16 id, u8 value);
void BLOCK20_SAVEDATA_ClearEntry(struct CgearSaveBlock *block, int index);
u32 BLOCK20_SAVEDATA_CountEntries(const struct CgearSaveBlock *block);
struct CgearSaveRecord *BLOCK20_SAVEDATA_GetRecord(struct CgearSaveBlock *block, int index);
void BLOCK20_SAVEDATA_SetRecord(struct CgearSaveBlock *block, int index, const void *src);
u32 BLOCK20_SAVEDATA_GetDateStamp(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetDateStamp(struct CgearSaveBlock *block, u32 value);
s32 BLOCK20_SAVEDATA_GetSavedValue(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetSavedValue(struct CgearSaveBlock *block, s32 value);
u32 BLOCK20_SAVEDATA_GetProgress(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetProgress(struct CgearSaveBlock *block, int value);
u32 BLOCK20_SAVEDATA_GetFlag(const struct CgearSaveBlock *block);
void BLOCK20_SAVEDATA_SetFlag(struct CgearSaveBlock *block, int value);
/* END mkheaders: generated region */

#endif
