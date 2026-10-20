#ifndef GAME_OV010_SYMBOL_MAP_H
#define GAME_OV010_SYMBOL_MAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of symbol_map.c, prototypes copied from their definitions. */

struct SymbolMapLinkRecord;
struct SymbolMapOwner;
struct SymbolMapProgress;
struct SaveSyncBlock;
struct PokeEventWork;
typedef struct SymbolMapLinkRecord SymbolMapLinkRecord;
typedef struct SymbolMapOwner SymbolMapOwner;
typedef struct SymbolMapProgress SymbolMapProgress;
typedef struct SaveSyncBlock SaveSyncBlock;
typedef struct PokeEventWork PokeEventWork;

#include "../types.h"

int SYMBOL_MAP_GetCellTileId(u8 *grid, int id);
int SYMBOL_MAP_GetSelection(void *gameSystem, u32 *outSymbolIndex, u32 *outSymbolGroup);
u8 *SYMBOL_MAP_GetSelectionGrid(void *gameSystem);
SymbolMapLinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heapId, void *gameSystem, u32 *outStart);
int SYMBOL_MAP_GetSelectedCellTile(void *gameSystem, int cellId);
int SYMBOL_MAP_GetSelectedNeighborCell(void *gameSystem, int cellId, int dir);
int SYMBOL_MAP_IsHomeCell(int cellId);
int SYMBOL_MAP_IsBlankCell(int cellId);
int SYMBOL_MAP_IsPlainCell(int cellId);
u32 SYMBOL_MAP_GetEventStateEntryValue(void *entries, u32 index);
void *SYMBOL_MAP_CreateRecordTask(void *gameSystem, void *progress, void *outCompleted);
void SYMBOL_MAP_DeleteLinkRecord(SymbolMapOwner *owner);
int SYMBOL_MAP_RecordTaskMain(void *task, u32 *state);
int SYMBOL_MAP_GetLastResult(void *progress);
void SYMBOL_MAP_StoreResult(SymbolMapProgress *progress, int value);
int SYMBOL_MAP_ScrCmdGetEventStateValue(void *vm, void *work);
int SYMBOL_MAP_ScrCmdStartRecordTask(void *vm, void *work);
int SYMBOL_MAP_GetSyncBlockItem(SaveSyncBlock *block, unsigned index);
int SYMBOL_MAP_GetSyncBlockHeader(SaveSyncBlock *block, int sel);
void *SYMBOL_MAP_CreatePickerTask(void *gameSystem, int mode, u32 outKind, u32 outValue, u32 outPicked);
int SYMBOL_MAP_PickerTaskMain(void *task, int *state);
int SYMBOL_MAP_ScrCmdGetSyncBlockItem(void *vm, void *work);
int SYMBOL_MAP_ScrCmdGetSyncBlockHeader(void *vm, void *work);
int SYMBOL_MAP_ScrCmdStartPicker(void *vm, void *work);
void SYMBOL_MAP_UpdateBg2Scale(void);
void SYMBOL_MAP_StartBg2Scale(void);
void SYMBOL_MAP_StopBg2Scale(void);
u32 SYMBOL_MAP_PokeEventTaskMain(void *task, u32 *state, PokeEventWork *work);
void *SYMBOL_MAP_CreatePokeEventTask(void *gameSystem, void *transitionArg, void *poke);
u32 SYMBOL_MAP_ResolveZoneId(void *gameData, u32 zoneId);
int SYMBOL_MAP_CheckEventFlag(void *gameData, u32 flagId);
int SYMBOL_MAP_ScrCmdStartPmsInput(void *vm, void *work);
u32 SYMBOL_MAP_PmsInputTaskMain(void *task, u32 *state);
int SYMBOL_MAP_ScrCmdSetSubscreenMode(void *vm, void *work);
/* END mkheaders: generated region */

#endif
