#ifndef GAME_OV021_SCRCMD_WIFI_HISTORY_H
#define GAME_OV021_SCRCMD_WIFI_HISTORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_wifi_history.c, prototypes copied from their definitions. */

struct GameSystem;
struct WifiHistory;
struct PartnerCandidates;
struct WordSet;
struct GameData;
struct ScriptVm;
struct ScrcmdWork;
typedef struct PartnerCandidates PartnerCandidates;

#include "../types.h"

void SCRCMD_FillPartnerCandidates(struct GameSystem *gameSystem, int language, u32 mode);
void SCRCMD_CollectPartnersByLanguage(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode);
u8 SCRCMD_GetPartnerCandidateHistoryIndex(PartnerCandidates *candidates, u32 index);
int SCRCMD_GetPartnerGreetingMessage(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant);
int SCRCMD_CalcPartnerGreetingIndex(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage);
void SCRCMD_SetPartnerWords(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex);
int SCRCMD_GetWifiHistoryCountryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetWifiHistoryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_MarkPartnerCandidate(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_IsPartnerCandidateMarked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SetWifiHistoryRatingLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FillPartnerCandidatesFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetPartnerGreetingMessageFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_HasPlayerLanguage(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
