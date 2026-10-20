#ifndef GAME_OV010_SCRCMD_SYMBOL_H
#define GAME_OV010_SCRCMD_SYMBOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_symbol.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct Mmdl;
struct SymbolKey;
struct PokemonParam;
struct GameEvent;
struct GameSystem;
struct FieldMap;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct SymbolKey SymbolKey;

#include "../arm9/script_vm_types.h"
#include "../types.h"

int SCRCMD_SYMBOL_StartViewEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_ApplyLinkRecord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_SelectObjectEntry(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_MoveObjectEntryToPairedBand(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_SetObjectPokemonWord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_GetState(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SYMBOL_StartEntryEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
struct Mmdl *SCRCMD_SYMBOL_GetMmdl(ScrcmdWork *cmdWork, u32 objId);
void SCRCMD_SYMBOL_GetTargetObjectKey(ScrcmdWork *cmdWork, SymbolKey *outKey);
struct PokemonParam *SCRCMD_SYMBOL_CreateObjectPokemon(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey);
void SCRCMD_SYMBOL_SendEntryFlag(ScrcmdWork *cmdWork);
struct GameEvent *SCRCMD_SYMBOL_CreateViewEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key, u16 *resultOut, u16 heapId);
int SCRCMD_SYMBOL_ViewEventMain(struct GameEvent *event, u32 *state, void *procWork);
/* END mkheaders: generated region */

#endif
