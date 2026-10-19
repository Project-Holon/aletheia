/*
 * file:     game_beacon_set.c
 * unit:     yes
 * function: GAME_BEACON_SEARCH_SetBattlePokeStart, GAME_BEACON_SEARCH_SetBattlePokeWin, GAME_BEACON_SEARCH_SetBattleWildPokeStart, GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart, GAME_BEACON_SEARCH_SetBattleWildPokeWin, GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin, GAME_BEACON_SEARCH_SetBattleSpecialPokeStart, GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart, GAME_BEACON_SEARCH_SetBattleSpecialPokeWin, GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin, GAME_BEACON_SEARCH_SetBattleTrainerStart, GAME_BEACON_SEARCH_SetInfoBattleTrainerStart, GAME_BEACON_SEARCH_SetBattleTrainerWin, GAME_BEACON_SEARCH_SetInfoBattleTrainerWin, GAME_BEACON_SEARCH_SetBattleLeaderStart, GAME_BEACON_SEARCH_SetInfoBattleLeaderStart, GAME_BEACON_SEARCH_SetBattleLeaderWin, GAME_BEACON_SEARCH_SetInfoBattleLeaderWin, GAME_BEACON_SEARCH_SetBattleBigFourStart, GAME_BEACON_SEARCH_SetInfoBattleBigFourStart, GAME_BEACON_SEARCH_SetBattleBigFourWin, GAME_BEACON_SEARCH_SetInfoBattleBigFourWin, GAME_BEACON_SEARCH_SetVersionAction, GAME_BEACON_SEARCH_SetInfoVersionAction, GAME_BEACON_SEARCH_SetItemFound, GAME_BEACON_SEARCH_SetInfoItemFound, GAME_BEACON_SEARCH_SetScriptEvent, GAME_BEACON_SEARCH_SetInfoScriptEvent, GAME_BEACON_SEARCH_SetPresetEvent, GAME_BEACON_SEARCH_SetInfoPresetEvent, GAME_BEACON_SEARCH_SetFieldEvent, GAME_BEACON_SEARCH_SetInfoFieldEvent, GAME_BEACON_SEARCH_SetPokeEvent, GAME_BEACON_SEARCH_SetInfoPokeEvent, GAME_BEACON_SEARCH_SetEventBattleNameA, GAME_BEACON_SEARCH_SetInfoEventBattleNameA, GAME_BEACON_SEARCH_SetEventBattleNameB, GAME_BEACON_SEARCH_SetInfoEventBattleNameB, GAME_BEACON_SEARCH_SetEventBattleNameC, GAME_BEACON_SEARCH_SetInfoEventBattleNameC, GAME_BEACON_SEARCH_SetEventBattleNameD, GAME_BEACON_SEARCH_SetInfoEventBattleNameD, GAME_BEACON_SEARCH_SetCountValue, GAME_BEACON_SEARCH_SetInfoCountValue, GAME_BEACON_SEARCH_SetSymbolMapEnter, GAME_BEACON_SEARCH_SetInfoSymbolMapEnter, GAME_BEACON_SEARCH_SetSymbolMapPoke, GAME_BEACON_SEARCH_SetInfoSymbolMapPoke, GAME_BEACON_SEARCH_SetFacilityEnter, GAME_BEACON_SEARCH_SetInfoFacilityEnter, GAME_BEACON_SEARCH_SetFacilityExit, GAME_BEACON_SEARCH_SetInfoFacilityExit, GAME_BEACON_SEARCH_SetWordValue, GAME_BEACON_SEARCH_SetInfoWordValue, GAME_BEACON_SEARCH_SetWordClear, GAME_BEACON_SEARCH_SetInfoWordClear, GAME_BEACON_SEARCH_SetSimpleEventA, GAME_BEACON_SEARCH_SetInfoSimpleEventA, GAME_BEACON_SEARCH_SetByteValue, GAME_BEACON_SEARCH_SetInfoByteValue, GAME_BEACON_SEARCH_SetSimpleEventB, GAME_BEACON_SEARCH_SetInfoSimpleEventB, GAME_BEACON_SEARCH_SetSimpleEventC, GAME_BEACON_SEARCH_SetInfoSimpleEventC, GAME_BEACON_SEARCH_SetNamedEvent, GAME_BEACON_SEARCH_SetInfoNamedEvent, GAME_BEACON_SEARCH_SetHalfwordValue, GAME_BEACON_SEARCH_SetInfoHalfwordValue, GAME_BEACON_SEARCH_SetThanks, GAME_BEACON_SEARCH_SetInfoThanks, GAME_BEACON_SEARCH_SetFreeText, GAME_BEACON_SEARCH_SetInfoFreeText
 * address:  0x0216505C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_BEACON_IsSpecialPokemon  0x0202708C  thumb
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   GAME_BEACON_SetDetailsBattleWildPoke   0x020273C4  thumb
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb
 *   GAME_BEACON_SetDetailsBattleSpecialPoke   0x020273DC  thumb
 *   GAME_BEACON_SetDetailsBattleTrainer   0x020273F8  thumb
 *   GAME_BEACON_SetDetailsBattleLeader   0x02027414  thumb
 *   GAME_BEACON_SetDetailsBattleBigFour   0x02027430  thumb
 *   GAME_BEACON_SEARCH_PresetEventTable      0x02171CA0  data  ov010  a1
 *   GAME_BEACON_CopyStrbufCodes  0x020270AC  thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_GetThanksMessage 0x0200C20C thumb
 *   WORDSET_CopyString 0x0201F41C thumb
 *   STRBUF_ToChars  0x02045A38  arm
 */
#include "../arm9/game_beacon_types.h"
#include "game_beacon_search_shared_types.h"
#include "beacon_view_event_shared_types.h"

struct Strbuf;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern int GAME_BEACON_IsSpecialPokemon(u32 monsNo);

extern u32 GAME_BEACON_CheckActionPriority(u32 action);

extern void GAME_BEACON_RequestSend(GameBeaconRecord *record);

extern void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u32 monsNo);

extern void GAME_BEACON_ResetDetails(GameBeaconInfo *info);

extern void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u32 monsNo);

extern void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest);

extern struct MyStatus *BEACON_GetBlock(struct SaveControl *saveControl);

extern const u16 *BEACON_GetThanksMessage(const struct MyStatus *myStatus);

extern void WORDSET_CopyString(const u16 *src, u16 *dest, u32 length);

extern void STRBUF_ToChars(const struct Strbuf *str, u16 *dest, u32 length);

void GAME_BEACON_SEARCH_SetBattlePokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetBattlePokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleWildPokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleWildPokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleTrainerStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleTrainerWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleLeaderStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleLeaderWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleBigFourStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleBigFourWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetVersionAction(u32 version);

void GAME_BEACON_SEARCH_SetInfoVersionAction(GameBeaconInfo *info, u32 version);

void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo);

void GAME_BEACON_SEARCH_SetInfoItemFound(GameBeaconInfo *info, u32 itemNo);

void GAME_BEACON_SEARCH_SetScriptEvent(void);

void GAME_BEACON_SEARCH_SetInfoScriptEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetPresetEvent(u32 eventId);

void GAME_BEACON_SEARCH_SetInfoPresetEvent(GameBeaconInfo *info, u32 eventId);

void GAME_BEACON_SEARCH_SetFieldEvent(void);

void GAME_BEACON_SEARCH_SetInfoFieldEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetPokeEvent(u16 monsNo);

void GAME_BEACON_SEARCH_SetInfoPokeEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetEventBattleNameA(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameA(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameB(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameB(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameC(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameC(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameD(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameD(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetCountValue(u32 count);

void GAME_BEACON_SEARCH_SetInfoCountValue(GameBeaconInfo *info, u32 count);

void GAME_BEACON_SEARCH_SetSymbolMapEnter(void);

void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSymbolMapPoke(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetFacilityEnter(void);

void GAME_BEACON_SEARCH_SetInfoFacilityEnter(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetFacilityExit(void);

void GAME_BEACON_SEARCH_SetInfoFacilityExit(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetWordValue(u32 value);

void GAME_BEACON_SEARCH_SetInfoWordValue(GameBeaconInfo *info, u32 value);

void GAME_BEACON_SEARCH_SetWordClear(void);

void GAME_BEACON_SEARCH_SetInfoWordClear(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSimpleEventA(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventA(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetByteValue(u8 value);

void GAME_BEACON_SEARCH_SetInfoByteValue(GameBeaconInfo *info, u8 value);

void GAME_BEACON_SEARCH_SetSimpleEventB(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventB(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSimpleEventC(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventC(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetNamedEvent(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoNamedEvent(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetHalfwordValue(u16 value);

void GAME_BEACON_SEARCH_SetInfoHalfwordValue(GameBeaconInfo *info, u16 value);

void GAME_BEACON_SEARCH_SetThanks(struct GameData *gameData, u16 trainerId);

void GAME_BEACON_SEARCH_SetInfoThanks(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId);

void GAME_BEACON_SEARCH_SetFreeText(const struct Strbuf *text);

void GAME_BEACON_SEARCH_SetInfoFreeText(GameBeaconInfo *info, const struct Strbuf *text);

extern GameBeaconWork *GAME_BEACON_Work;

extern const u8 GAME_BEACON_SEARCH_PresetEventTable[5];

/* ------------------------------------------------------------------ *
 * Action setters: each pair checks that the action may be sent now,
 * writes it into the own beacon and sends the beacon.
 * ------------------------------------------------------------------ */

/* Battle start against a pokemon: special pokemon have their own action. */
void GAME_BEACON_SEARCH_SetBattlePokeStart(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(monsNo);
    } else {
        GAME_BEACON_SEARCH_SetBattleWildPokeStart(monsNo);
    }
}

void GAME_BEACON_SEARCH_SetBattlePokeWin(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(monsNo);
    } else {
        GAME_BEACON_SEARCH_SetBattleWildPokeWin(monsNo);
    }
}

void GAME_BEACON_SEARCH_SetBattleWildPokeStart(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x02)) {
        GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x02;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleWildPoke(info, monsNo);
}

void GAME_BEACON_SEARCH_SetBattleWildPokeWin(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x03)) {
        GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x03;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x04)) {
        GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x04;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleSpecialPoke(info, monsNo);
}

void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x05)) {
        GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x05;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleTrainerStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x06)) {
        GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x06;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleTrainer(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleTrainerWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x07)) {
        GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x07;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleLeaderStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x08)) {
        GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x08;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleLeader(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleLeaderWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x09)) {
        GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x09;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleBigFourStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0A)) {
        GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0A;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleBigFour(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleBigFourWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0B)) {
        GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0B;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetVersionAction(u32 version)
{
    if (GAME_BEACON_CheckActionPriority(0x12)) {
        GAME_BEACON_SEARCH_SetInfoVersionAction(&GAME_BEACON_Work->own.info, version);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoVersionAction(GameBeaconInfo *info, u32 version)
{
    info->action = 0x12;
    info->infoVersion = (u8)version;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo)
{
    if (GAME_BEACON_CheckActionPriority(0x13)) {
        GAME_BEACON_SEARCH_SetInfoItemFound(&GAME_BEACON_Work->own.info, itemNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoItemFound(GameBeaconInfo *info, u32 itemNo)
{
    info->action = 0x13;
    info->actionData.value = itemNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetScriptEvent(void)
{
    if (GAME_BEACON_CheckActionPriority(0x15)) {
        GAME_BEACON_SEARCH_SetInfoScriptEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoScriptEvent(GameBeaconInfo *info)
{
    info->action = 0x15;
    GAME_BEACON_ResetDetails(info);
}

/* Only the preset events of GAME_BEACON_SEARCH_PresetEventTable are sent. */
void GAME_BEACON_SEARCH_SetPresetEvent(u32 eventId)
{
    u32 i;

    if (GAME_BEACON_CheckActionPriority(0x16)) {
        for (i = 0; i < 5; i++) {
            if (eventId == GAME_BEACON_SEARCH_PresetEventTable[i]) {
                GAME_BEACON_SEARCH_SetInfoPresetEvent(&GAME_BEACON_Work->own.info, eventId);
                GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
                return;
            }
        }
    }
}

void GAME_BEACON_SEARCH_SetInfoPresetEvent(GameBeaconInfo *info, u32 eventId)
{
    info->action = 0x16;
    info->actionData.wordValue = eventId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFieldEvent(void)
{
    if (GAME_BEACON_CheckActionPriority(0x17)) {
        GAME_BEACON_SEARCH_SetInfoFieldEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFieldEvent(GameBeaconInfo *info)
{
    info->action = 0x17;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetPokeEvent(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x1E)) {
        GAME_BEACON_SEARCH_SetInfoPokeEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoPokeEvent(GameBeaconInfo *info)
{
    info->action = 0x1E;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameA(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x1F)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameA(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameA(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x1F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameB(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x20)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameB(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameB(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x20;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameC(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x21)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameC(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameC(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x21;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameD(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x22)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameD(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameD(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x22;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetCountValue(u32 count)
{
    if (GAME_BEACON_CheckActionPriority(0x24)) {
        GAME_BEACON_SEARCH_SetInfoCountValue(&GAME_BEACON_Work->own.info, count);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoCountValue(GameBeaconInfo *info, u32 count)
{
    info->action = 0x24;
    info->actionData.value = count;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSymbolMapEnter(void)
{
    if (GAME_BEACON_CheckActionPriority(0x25)) {
        GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GameBeaconInfo *info)
{
    info->action = 0x25;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSymbolMapPoke(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x26)) {
        GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x26;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFacilityEnter(void)
{
    if (GAME_BEACON_CheckActionPriority(0x27)) {
        GAME_BEACON_SEARCH_SetInfoFacilityEnter(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFacilityEnter(GameBeaconInfo *info)
{
    info->action = 0x27;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFacilityExit(void)
{
    if (GAME_BEACON_CheckActionPriority(0x28)) {
        GAME_BEACON_SEARCH_SetInfoFacilityExit(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFacilityExit(GameBeaconInfo *info)
{
    info->action = 0x28;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetWordValue(u32 value)
{
    if (GAME_BEACON_CheckActionPriority(0x29)) {
        GAME_BEACON_SEARCH_SetInfoWordValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoWordValue(GameBeaconInfo *info, u32 value)
{
    info->action = 0x29;
    info->actionData.wordValue = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetWordClear(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2A)) {
        GAME_BEACON_SEARCH_SetInfoWordClear(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoWordClear(GameBeaconInfo *info)
{
    info->action = 0x2A;
    info->actionData.wordValue = 0;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventA(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2B)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventA(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventA(GameBeaconInfo *info)
{
    info->action = 0x2B;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetByteValue(u8 value)
{
    if (GAME_BEACON_CheckActionPriority(0x2C)) {
        GAME_BEACON_SEARCH_SetInfoByteValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoByteValue(GameBeaconInfo *info, u8 value)
{
    info->action = 0x2C;
    info->actionData.byteValue = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventB(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2D)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventB(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventB(GameBeaconInfo *info)
{
    info->action = 0x2D;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventC(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2E)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventC(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventC(GameBeaconInfo *info)
{
    info->action = 0x2E;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetNamedEvent(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x2F)) {
        GAME_BEACON_SEARCH_SetInfoNamedEvent(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoNamedEvent(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x2F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetHalfwordValue(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x30)) {
        GAME_BEACON_SEARCH_SetInfoHalfwordValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoHalfwordValue(GameBeaconInfo *info, u16 value)
{
    info->action = 0x30;
    info->actionData.value = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetThanks(struct GameData *gameData, u16 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x18)) {
        GAME_BEACON_SEARCH_SetInfoThanks(&GAME_BEACON_Work->own.info, gameData, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoThanks(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId)
{
    WORDSET_CopyString(BEACON_GetThanksMessage(BEACON_GetBlock(GAME_DATA_GetSaveControl(gameData))), info->actionData.text, 9);
    info->action = 0x18;
    info->actionData.special.targetTrainerId = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFreeText(const struct Strbuf *text)
{
    if (GAME_BEACON_CheckActionPriority(0x31)) {
        GAME_BEACON_SEARCH_SetInfoFreeText(&GAME_BEACON_Work->own.info, text);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFreeText(GameBeaconInfo *info, const struct Strbuf *text)
{
    STRBUF_ToChars(text, info->actionData.text, 9);
    info->action = 0x31;
    GAME_BEACON_ResetDetails(info);
}
