/*
 * file:     scrcmd_wifi_history.c
 * unit:     yes
 * function: SCRCMD_FillPartnerCandidates, SCRCMD_CollectPartnersByLanguage, SCRCMD_GetPartnerCandidateHistoryIndex, SCRCMD_GetPartnerGreetingMessage, SCRCMD_CalcPartnerGreetingIndex, SCRCMD_SetPartnerWords, SCRCMD_GetWifiHistoryCountryCount, SCRCMD_GetWifiHistoryEntryCount, SCRCMD_MarkPartnerCandidate, SCRCMD_IsPartnerCandidateMarked, SCRCMD_SetWifiHistoryRatingLevel, SCRCMD_SetWifiHistoryGreetingSet, SCRCMD_GetWifiHistoryGreetingSet, SCRCMD_FillPartnerCandidatesFromScript, SCRCMD_GetPartnerGreetingMessageFromScript, SCRCMD_HasPlayerLanguage
 * address:  0x021CFC4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from enceff.c at 021CFC4C: the Wi-Fi history and partner candidate script commands (one SCRCMD_ run on partner candidates and Wi-Fi history, no data of its own, no statics shared with the INTRUDE_ code before it).
 *
 * symbols:
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   SAVE_SYNC_Clear  0x0200E878  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   WIFI_HISTORY_GetEntryField  0x02009634  thumb
 *   WIFI_HISTORY_GetEntry  0x0200973C  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   CURSOR_MOVE_GetTableValue  0x02025C74  thumb
 *   NATION_AREA_GetAreaCount  0x02025B64  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   MYSTATUS_GetArea  0x02008570  thumb
 *   WORDSET_SetSlotFromKeyedMessage  0x0201F094  thumb
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 *   WIFI_HISTORY_GetGreetingSet  0x02009628  thumb
 *   WORDSET_SetSlotFromMsg2B  0x0201F198  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   WIFI_HISTORY_GetDisplayCount  0x02009590  thumb
 *   WIFI_HISTORY_GetFirstFreeEntry  0x020095C8  thumb
 *   WIFI_HISTORY_SetEntryField  0x02009698  thumb
 *   WIFI_HISTORY_SetRatingLevel  0x020095FC  thumb
 *   WIFI_HISTORY_SetGreetingSet  0x02009618  thumb
 *   VM_ReadU16  0x02011330  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "enceff_shared_types.h"
#include "scrcmd_otid_shared_types.h"
#include "intrude_offer_shared_types.h"

struct WifiHistory;

struct HistoryEntry;

/* Up to five Wi-Fi history partners with the same language (16 bytes, synced with the save). */
#define PARTNER_CANDIDATE_MAX 5

typedef struct PartnerCandidates {
    u8 language;                              /* 0x00 */
    u8 count;                                 /* 0x01 */
    u8 mode;                                  /* 0x02 */
    u8 viewId[PARTNER_CANDIDATE_MAX];         /* 0x03: trainer view of the partner */
    u8 historyIndex[PARTNER_CANDIDATE_MAX];   /* 0x08: entry in the Wi-Fi history */
    u8 reserved0D[3];
} PartnerCandidates;

enum {
    WIFI_HISTORY_ENTRY_COUNT = 20,
    WIFI_HISTORY_FIELD_MARKED = 5,
    WIFI_HISTORY_FIELD_INFO = 6
};

#include "../ov010/scrcmd_work.h"


#include "../ov010/script_work_cmd.h"


#include "../arm9/vm.h"

#include "../arm9/gamesystem.h"

#include "../arm9/game_data.h"



#include "../arm9/mystatus.h"





#include "../ov010/script_work.h"

#include "../arm9/wifi_history.h"









#include "../arm9/save_sync_savedata.h"

#include "../arm9/cursor_move.h"

#include "../arm9/bmp_oam.h"

#include "../arm9/wordset.h"
#include "../version.h"






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

/*
 * Fills the partner candidates in the save sync block for a language, or
 * clears them when the language is out of range.
 */
void SCRCMD_FillPartnerCandidates(struct GameSystem *gameSystem, int language, u32 mode)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    PartnerCandidates *candidates = (PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(gameData);

    if (language < 0xe9) {
        SCRCMD_CollectPartnersByLanguage(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData)), candidates, language, mode);
        return;
    }
    SAVE_SYNC_Clear(candidates);
}

/* Collects up to five Wi-Fi history partners of one language into out. */
void SCRCMD_CollectPartnersByLanguage(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode)
{
    int i;

    out->language = language;
    out->mode = mode;
    out->count = 0;
    for (i = 0; i < WIFI_HISTORY_ENTRY_COUNT; i++) {
        if ((u8)WIFI_HISTORY_GetEntryField(history, i, WIFI_HISTORY_FIELD_INFO) != 0) {
            struct HistoryEntry *entry = WIFI_HISTORY_GetEntry(history, i);
            u32 entryLanguage;
            if (entry != 0 && (entryLanguage = MYSTATUS_GetNation((struct MyStatus *)entry), entryLanguage == language)) {
                u32 outfit = MYSTATUS_GetTrainerView((struct MyStatus *)entry);
                if (outfit > 0xf) {
                    outfit = (MYSTATUS_GetSex((struct MyStatus *)entry) != 0) ? 0xf : 0xb;
                }
                out->historyIndex[out->count] = i;
                out->viewId[out->count] = CURSOR_MOVE_GetTableValue(outfit);
                out->count++;
                if (out->count >= PARTNER_CANDIDATE_MAX) {
                    break;
                }
            }
        }
    }
}

/* Returns the history index of candidate i, or 0xff. */
u8 SCRCMD_GetPartnerCandidateHistoryIndex(PartnerCandidates *candidates, u32 index)
{
    u8 historyIndex = 0xff;

    if (index < PARTNER_CANDIDATE_MAX && index < candidates->count) {
        historyIndex = candidates->historyIndex[index];
    }
    return historyIndex;
}

/*
 * Registers the words of candidate index and returns the index of the
 * greeting message for that partner (4 when the index is out of range).
 */
int SCRCMD_GetPartnerGreetingMessage(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant)
{
    u32 outfitVariant, trainerId, tier, historyIndex;
    struct HistoryEntry *entry;
    struct WifiHistory *history;
    struct GameData *gameData;
    u32 isSpecialLanguage;

    isSpecialLanguage = 0;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    history = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData));
    if (index >= PARTNER_CANDIDATE_MAX) {
        return PM_LANG_JA(4, 2);
    }
    historyIndex = candidates->historyIndex[index];
    SCRCMD_SetPartnerWords(wordSet, gameData, historyIndex);
    entry = WIFI_HISTORY_GetEntry(history, historyIndex);
    outfitVariant = MYSTATUS_GetSex((struct MyStatus *)entry);
    tier = WIFI_HISTORY_GetEntryField(history, historyIndex, 4);
    trainerId = MYSTATUS_GetId((struct MyStatus *)entry);
    if (NATION_AREA_GetAreaCount(((PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(gameData))->language)) {
        isSpecialLanguage = 1;
    }
    return SCRCMD_CalcPartnerGreetingIndex(outfitVariant, trainerId, tier, variant, isSpecialLanguage);
}

/* Computes the greeting message index from the partner's data. */
int SCRCMD_CalcPartnerGreetingIndex(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage)
{
    int index;

    if (isSpecialLanguage != 0) {
        index = PM_LANG_JA(4, 2);
    } else {
        index = PM_LANG_JA(0x44, 0x42);
    }
    if (tier < 5) {
        index += tier * 0xc;
    }
    if (outfitVariant != 0) {
        index += 6;
    }
    if (variant == 0) {
        index++; index += trainerId % 5;
    }
    return index;
}

/* Registers the words (names, numbers) of one Wi-Fi history partner in the word set. */
void SCRCMD_SetPartnerWords(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex)
{
    struct WifiHistory *history;
    struct HistoryEntry *entry;
    u32 value;
    u8 language;

    history = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData));
    language = ((PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(gameData))->language;
    entry = WIFI_HISTORY_GetEntry(history, historyIndex);
    WORDSET_SetSlotFromMsgE7(wordSet, 0, language);
    if (NATION_AREA_GetAreaCount(language)) {
        WORDSET_SetSlotFromKeyedMessage(wordSet, 1, language, MYSTATUS_GetArea((struct MyStatus *)entry));
    }
    WORDSET_SetSlotMyStatus(wordSet, 3, GAME_DATA_GetMyStatus(gameData));
    WORDSET_SetSlotSpeciesName(wordSet, 5, WIFI_HISTORY_GetEntryField(history, historyIndex, 0));
    WORDSET_SetSlotFromMsg2B(wordSet, 6, WIFI_HISTORY_GetGreetingSet(history));
    WORDSET_SetSlotMyStatus(wordSet, 7, entry);
    value = WIFI_HISTORY_GetEntryField(history, historyIndex, 3);
    if (value == 0) {
        value = 1;
    }
    WORDSET_SetSlotNumber(wordSet, 8, value, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotSpeciesName(wordSet, 9, WIFI_HISTORY_GetEntryField(history, historyIndex, 1));
    language = WIFI_HISTORY_GetEntryField(history, historyIndex, 2);
    WORDSET_SetSlotFromMsg2B(wordSet, 10, language);
}

/* Script command: stores the number of countries in the Wi-Fi history, looked up with the argument. */
int SCRCMD_GetWifiHistoryCountryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 arg;
    struct GameData *gameData;
    struct WifiHistory *history;
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    arg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    history = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData));
    *resultVar = WIFI_HISTORY_GetDisplayCount(history, GAME_DATA_GetMyStatus(gameData), arg);
    return 0;
}

/* Script command: stores the number of entries of the Wi-Fi history. */
int SCRCMD_GetWifiHistoryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = WIFI_HISTORY_GetFirstFreeEntry(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
    return 0;
}

/* Script command: marks the Wi-Fi history entry of partner candidate n. */
int SCRCMD_MarkPartnerCandidate(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 historyIndex;
    u8 candidateIndex;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    candidates = (PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(gameData);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    historyIndex = SCRCMD_GetPartnerCandidateHistoryIndex(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        WIFI_HISTORY_SetEntryField(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED, 1);
    }
    return 0;
}

/* Script command: stores 1 when the history entry of partner candidate n is marked. */
int SCRCMD_IsPartnerCandidateMarked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 candidateIndex, historyIndex;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    candidates = (PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(gameData);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = 0;
    historyIndex = SCRCMD_GetPartnerCandidateHistoryIndex(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        if ((u8)WIFI_HISTORY_GetEntryField(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED)) {
            *resultVar = 1;
        }
    }
    return 0;
}

/* Script command: sets the rating level of the Wi-Fi history. */
int SCRCMD_SetWifiHistoryRatingLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 ratingLevel;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ratingLevel = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WIFI_HISTORY_SetRatingLevel(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), ratingLevel);
    return 0;
}

/* Script command: sets the greeting set of the Wi-Fi history. */
int SCRCMD_SetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 greetingSet;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    greetingSet = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WIFI_HISTORY_SetGreetingSet(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), greetingSet);
    return 0;
}

/* Script command: stores the greeting set of the Wi-Fi history. */
int SCRCMD_GetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = WIFI_HISTORY_GetGreetingSet(WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
    return 0;
}

/* Script command: fills the partner candidates for a language and mode read from the script. */
int SCRCMD_FillPartnerCandidatesFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 language;
    u16 mode;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    language = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRCMD_FillPartnerCandidates(gameSystem, language, mode);
    return 0;
}

/* Script command: stores the greeting message index for partner candidate n. */
int SCRCMD_GetPartnerGreetingMessageFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct WordSet *wordSet;
    PartnerCandidates *candidates;
    u32 candidateIndex, variant;
    u16 *resultVar;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    candidates = (PartnerCandidates *)GAME_DATA_GetSaveSyncBlock(GAMESYSTEM_GetGameData(gameSystem));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    variant = VM_ReadU16(vm);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = SCRCMD_GetPartnerGreetingMessage(wordSet, gameSystem, candidates, candidateIndex, variant);
    return 0;
}

/* Script command: stores 1 when the player's language value is set. */
int SCRCMD_HasPlayerLanguage(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = MYSTATUS_GetNation(GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork)))) != 0 ? 1 : 0;
    return 0;
}
