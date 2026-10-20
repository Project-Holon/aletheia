#ifndef GAME_OV021_SCRCMD_WORDSET_WARP_H
#define GAME_OV021_SCRCMD_WORDSET_WARP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_wordset_warp.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../arm9/script_vm_types.h"
#include "../ov021/scrcmd_wordset_warp_types.h"

int SCRCMD_BufferPlayerName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferItemName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferItemNameAlt(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_BufferItemNameWithCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferConvertedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferCategoryEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesNameCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSpeciesEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferShortEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPartyMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonSpeciesName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferDaycareMonNickname(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferNumber(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferPlaceName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferEasyChatWord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferGroupedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferSignedEntryName(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferByteEntryCommon(ScriptVm *vm, ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int SCRCMD_BufferMapEntryNameA(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferMapEntryNameB(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferBeaconThanksCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_BufferBeaconGreetCount(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionPlain(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPositionFixedExit(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToFixedZone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToPosition3D(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WarpToRailLocationWithTransition(ScriptVm *vm, ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
