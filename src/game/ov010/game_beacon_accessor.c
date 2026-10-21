/*
 * file:     game_beacon_accessor.c
 * unit:     yes
 * function: GAME_BEACON_ACCESSOR_TableAddNewLogs, GAME_BEACON_ACCESSOR_TablePop, GAME_BEACON_ACCESSOR_TableMarkLogsNew, GAME_BEACON_ACCESSOR_TableAdd, GAME_BEACON_ACCESSOR_TableGetRingIndex, GAME_BEACON_ACCESSOR_TableRingAdd, GAME_BEACON_ACCESSOR_TableRingGet, GAME_BEACON_ACCESSOR_TableGetCount, GAME_BEACON_ACCESSOR_AllocInfo, GAME_BEACON_ACCESSOR_AllocTable, GAME_BEACON_ACCESSOR_IsInfoInvalid, GAME_BEACON_ACCESSOR_IsDistributionAction, GAME_BEACON_ACCESSOR_GetPlayerName, GAME_BEACON_ACCESSOR_GetPmVersion, GAME_BEACON_ACCESSOR_GetLanguage, GAME_BEACON_ACCESSOR_GetNation, GAME_BEACON_ACCESSOR_GetArea, GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond, GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst, GAME_BEACON_ACCESSOR_GetDetailsPms, GAME_BEACON_ACCESSOR_GetResearchTeamRank, GAME_BEACON_ACCESSOR_GetFavoriteColorRgb, GAME_BEACON_ACCESSOR_GetFavoriteColorIndex, GAME_BEACON_ACCESSOR_GetTrainerId, GAME_BEACON_ACCESSOR_GetTrainerAppearance, GAME_BEACON_ACCESSOR_GetSex, GAME_BEACON_ACCESSOR_GetPlayTime, GAME_BEACON_ACCESSOR_GetInfoVersion, GAME_BEACON_ACCESSOR_GetZoneId, GAME_BEACON_ACCESSOR_GetTownmapRootZoneId, GAME_BEACON_ACCESSOR_GetPassCount, GAME_BEACON_ACCESSOR_GetThanksCount, GAME_BEACON_ACCESSOR_GetGreeting, GAME_BEACON_ACCESSOR_GetThanksName, GAME_BEACON_ACCESSOR_GetFreeText, GAME_BEACON_ACCESSOR_GetDetailsType, GAME_BEACON_ACCESSOR_GetDetailsTrainerNo, GAME_BEACON_ACCESSOR_GetDetailsMonsNo, GAME_BEACON_ACCESSOR_GetActionNo, GAME_BEACON_ACCESSOR_GetActionMonsNo, GAME_BEACON_ACCESSOR_GetActionItemNo, GAME_BEACON_ACCESSOR_GetActionCountValue, GAME_BEACON_ACCESSOR_GetDistributionMonsNo, GAME_BEACON_ACCESSOR_GetDistributionItemNo, GAME_BEACON_ACCESSOR_GetDistributionSerial, GAME_BEACON_ACCESSOR_GetNickname, GAME_BEACON_ACCESSOR_GetActionTrainerNo, GAME_BEACON_ACCESSOR_GetPresetEventValue, GAME_BEACON_ACCESSOR_GetActionSpecialValue, GAME_BEACON_ACCESSOR_GetActionWordValue, GAME_BEACON_ACCESSOR_GetActionByteValue, GAME_BEACON_ACCESSOR_GetActionHalfwordValue, GAME_BEACON_ACCESSOR_GetActionCheckIndex, GAME_BEACON_ACCESSOR_GetActionViewVariant, GAME_BEACON_ACCESSOR_RegisterRecordWords, GAME_BEACON_ACCESSOR_IsNoArgInvalid, GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid, GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid, GAME_BEACON_ACCESSOR_IsNoValueInvalid, GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid, GAME_BEACON_ACCESSOR_IsActionItemNoInvalid, GAME_BEACON_ACCESSOR_IsPlayTimeInvalid, GAME_BEACON_ACCESSOR_IsActionCountValueInvalid, GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid, GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid, GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid, GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid, GAME_BEACON_ACCESSOR_IsActionByteValueInvalid, GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid, GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid
 * address:  0x02165888
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
 *   MI_CpuFill8    0x02082BCC  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_STANDARD_GetCachedTime 0x0203F4CC arm
 *   GAME_BEACON_GetNextNewLogIndex 0x02026CA0 thumb
 *   GAME_BEACON_GetLog 0x02026C1C thumb
 *   GAME_BEACON_ClearNewFlag 0x02026CE0 thumb
 *   GAME_BEACON_SetNewFlagByTrainerId   0x02026D04  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   GAME_BEACON_ACCESSOR_FileName 0x021729D4 data a4
 *   GAME_BEACON_ACCESSOR_ActionCheckFuncs     0x02171CA8  data
 *   STRBUF_SetStringN  0x02045994  arm
 *   SYMBOL_SAVE_ReadBitField  0x0200E3A4  thumb
 *   OSi_GetOwnerInfoExBuffer  0x02087D1C  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_SetString  0x02045924  arm
 *   GAME_BEACON_ACCESSOR_ActionTable  0x02171CE8  data  a1
 *   WORDSET_ClearAllSlots  0x0201F31C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
 *   WORDSET_SetSlotFromMsg117  0x0201EF4C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotPokeData  0x0201F104  thumb
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   WORDSET_SetSlotWeekday  0x0201F1E0  thumb
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetFreeText  0x02165D8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionNo  0x02165E24  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionMonsNo  0x02165E34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionItemNo  0x02165E78  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCountValue  0x02165E8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionMonsNo  0x02165E9C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionItemNo  0x02165EAC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetNickname  0x02165ECC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionTrainerNo  0x02165F30  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPresetEventValue  0x02165F64  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionSpecialValue  0x02165F74  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionWordValue  0x02165F84  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionByteValue  0x02165F94  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionHalfwordValue  0x02165FA4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCheckIndex  0x02165FB4  thumb  ov010
 */
#include "../arm9/game_beacon_types.h"
#include "game_beacon_search_shared_types.h"

#include "../arm9/gf_standard_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gf_standard.h"

#include "../arm9/game_beacon.h"






int GAME_BEACON_ACCESSOR_TableAddNewLogs(GameBeaconInfoTable *table);

int GAME_BEACON_ACCESSOR_TablePop(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime);

void GAME_BEACON_ACCESSOR_TableMarkLogsNew(GameBeaconInfoTable *table);

int GAME_BEACON_ACCESSOR_TableAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode);

int GAME_BEACON_ACCESSOR_TableGetRingIndex(const GameBeaconInfoTable *table, int offset);

int GAME_BEACON_ACCESSOR_TableRingAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew);

int GAME_BEACON_ACCESSOR_TableRingGet(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset);

u8 GAME_BEACON_ACCESSOR_TableGetCount(const GameBeaconInfoTable *table);

/* ------------------------------------------------------------------ *
 * The table of received beacons (30 entries with their receive time).
 * ------------------------------------------------------------------ */

/* Moves the new beacon log entries into the table; returns how many. */
int GAME_BEACON_ACCESSOR_TableAddNewLogs(GameBeaconInfoTable *table)
{
    RTCTime time;
    int cursor;
    int added;
    int receiveTime;
    int logIndex;
    int tableIndex;

    added = 0;
    cursor = 0;
    GF_STANDARD_GetCachedTime(&time);
    receiveTime = (u16)((time.hour << 8) | time.minute);
    for (;;) {
        logIndex = GAME_BEACON_GetNextNewLogIndex(&cursor);
        if (logIndex == 30) {
            break;
        }
        tableIndex = GAME_BEACON_ACCESSOR_TableAdd(table, &GAME_BEACON_GetLog(logIndex)->info, receiveTime, 0);
        if (tableIndex == 30) {
            break;
        }
        GAME_BEACON_ClearNewFlag(logIndex);
        added++;
    }
    return added;
}

/* Pops the first entry: copies it out and shifts the rest down. */
int GAME_BEACON_ACCESSOR_TablePop(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime)
{
    int i;

    if (table->info[0].versionBit == 0)
        return 0;
    *info = table->info[0];
    *receiveTime = table->receiveTime[0];
    for (i = 1; i < 30; i++) {
        table->info[i - 1] = table->info[i];
        table->receiveTime[i - 1] = table->receiveTime[i];
    }
    MI_CpuFill8(&table->info[29], 0, sizeof(GameBeaconInfo));
    return 1;
}

/* Hands every used entry back to the beacon log as new. */
void GAME_BEACON_ACCESSOR_TableMarkLogsNew(GameBeaconInfoTable *table)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (table->info[i].versionBit == 0)
            break;
        GAME_BEACON_SetNewFlagByTrainerId(&table->info[i]);
    }
}

/*
 * Stores the beacon in the first free entry or over the entry of the same
 * trainer. When the table is full and mode is 1, the oldest entry is
 * dropped. Returns the entry used, or 30 when nothing was stored.
 */
int GAME_BEACON_ACCESSOR_TableAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (table->info[i].versionBit == 0 || info->trainerId == table->info[i].trainerId) {
            table->info[i] = *info;
            table->receiveTime[i] = receiveTime;
            return i;
        }
    }
    if (mode == 1) {
        MIi_CpuCopy32(&table->info[1], &table->info[0], 29 * sizeof(GameBeaconInfo));
        MIi_CpuCopy16(&table->receiveTime[1], &table->receiveTime[0], 29 * sizeof(u16));
        table->info[29] = *info;
        table->receiveTime[29] = receiveTime;
        return 29;
    }
    return 30;
}

/* Ring use of the table: entry at a signed offset from the head. */
int GAME_BEACON_ACCESSOR_TableGetRingIndex(const GameBeaconInfoTable *table, int offset)
{
    int head = table->head;

    if (offset < 0)
        return (head + offset + 30) % 30;
    return (head + offset) % 30;
}

/*
 * Ring insert: replaces the entry of the same trainer, else pushes a new
 * head. *isNew (optional) is 1 when a new entry was taken.
 */
int GAME_BEACON_ACCESSOR_TableRingAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew)
{
    int i;
    int index;

    if (isNew)
        *isNew = 0;
    for (i = 0; i < 30; i++) {
        index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, i);
        if (table->info[index].versionBit == 0)
            break;
        if (info->trainerId == table->info[index].trainerId) {
            table->info[index] = *info;
            table->receiveTime[index] = receiveTime;
            return i;
        }
    }
    if (isNew)
        *isNew = 1;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, -1);
    table->info[index] = *info;
    table->receiveTime[index] = receiveTime;
    table->head = index;
    if (table->count < 30)
        table->count++;
    return 0;
}

int GAME_BEACON_ACCESSOR_TableRingGet(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset)
{
    int index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, offset);

    if (table->info[index].versionBit == 0)
        return 0;
    *info = table->info[index];
    *receiveTime = table->receiveTime[index];
    return 1;
}

u8 GAME_BEACON_ACCESSOR_TableGetCount(const GameBeaconInfoTable *table)
{
    return table->count;
}

typedef int (*GameBeaconActionCheckFunc)(const GameBeaconInfo *info);

/* Per-action attributes, 2 bytes. */
typedef struct GameBeaconActionAttr {
    u8 checkIndex;              /* index into GAME_BEACON_ACCESSOR_ActionCheckFuncs */
    u8 group;
} GameBeaconActionAttr;

#include "../arm9/strbuf.h"

#include "../arm9/symbol_save.h"

#include "../arm9/os_ownerinfoex.h"



GameBeaconInfo *GAME_BEACON_ACCESSOR_AllocInfo(u32 heapId);

GameBeaconInfoTable *GAME_BEACON_ACCESSOR_AllocTable(u32 heapId);

int GAME_BEACON_ACCESSOR_IsInfoInvalid(const GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionAction(const GameBeaconInfo *info);

extern void GAME_BEACON_ACCESSOR_GetPlayerName(const GameBeaconInfo *info, struct Strbuf *name);

u32 GAME_BEACON_ACCESSOR_GetPmVersion(const GameBeaconInfo *info);

u32 GAME_BEACON_ACCESSOR_GetLanguage(const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetNation(const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetArea(const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(const GameBeaconInfo *info);

void GAME_BEACON_ACCESSOR_GetDetailsPms(const GameBeaconInfo *info, GameBeaconPms *pms);

u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(const GameBeaconInfo *info);

void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(u16 *rgb, const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetTrainerId(const GameBeaconInfo *info);

u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(const GameBeaconInfo *info);

extern u8 GAME_BEACON_ACCESSOR_GetSex(const GameBeaconInfo *info);

void GAME_BEACON_ACCESSOR_GetPlayTime(const GameBeaconInfo *info, u16 *hours, u16 *minutes);

u8 GAME_BEACON_ACCESSOR_GetInfoVersion(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetZoneId(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const GameBeaconInfo *info);

u32 GAME_BEACON_ACCESSOR_GetPassCount(const GameBeaconInfo *info);

u32 GAME_BEACON_ACCESSOR_GetThanksCount(const GameBeaconInfo *info);

void GAME_BEACON_ACCESSOR_GetGreeting(const GameBeaconInfo *info, struct Strbuf *greeting);

void GAME_BEACON_ACCESSOR_GetThanksName(const GameBeaconInfo *info, struct Strbuf *name);

extern void GAME_BEACON_ACCESSOR_GetFreeText(const GameBeaconInfo *info, struct Strbuf *text);

unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionNo(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionItemNo(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionCountValue(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetDistributionMonsNo(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(const GameBeaconInfo *info);

u16 GAME_BEACON_ACCESSOR_GetDistributionSerial(const GameBeaconInfo *info);

extern void GAME_BEACON_ACCESSOR_GetNickname(const GameBeaconInfo *info, struct Strbuf *nickname);

extern u16 GAME_BEACON_ACCESSOR_GetActionTrainerNo(const GameBeaconInfo *info);

extern u32 GAME_BEACON_ACCESSOR_GetPresetEventValue(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionSpecialValue(const GameBeaconInfo *info);

extern u32 GAME_BEACON_ACCESSOR_GetActionWordValue(const GameBeaconInfo *info);

extern u8 GAME_BEACON_ACCESSOR_GetActionByteValue(const GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionHalfwordValue(const GameBeaconInfo *info);

extern u8 GAME_BEACON_ACCESSOR_GetActionCheckIndex(u16 action);

extern const char GAME_BEACON_ACCESSOR_FileName[];

extern const GameBeaconActionCheckFunc GAME_BEACON_ACCESSOR_ActionCheckFuncs[];

extern const GameBeaconActionAttr GAME_BEACON_ACCESSOR_ActionTable[];

GameBeaconInfo *GAME_BEACON_ACCESSOR_AllocInfo(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(GameBeaconInfo), 1, GAME_BEACON_ACCESSOR_FileName, 0x1b3);
}

GameBeaconInfoTable *GAME_BEACON_ACCESSOR_AllocTable(u32 heapId)
{
    GameBeaconInfoTable *table = GFL_HEAP_Alloc(heapId, sizeof(GameBeaconInfoTable), 1, GAME_BEACON_ACCESSOR_FileName, 0x1c1);

    table->head = 0;
    table->count = 0;
    return table;
}

/* ------------------------------------------------------------------ *
 * Beacon info accessors.
 * ------------------------------------------------------------------ */

/* Returns 1 when a field is out of range or the action check fails. */
int GAME_BEACON_ACCESSOR_IsInfoInvalid(const GameBeaconInfo *info)
{
    if (info->action == 0 || info->action >= 0x33)
        return 1;
    if (info->detailsPms.bits.detailsType >= 6)
        return 1;
    if (info->researchTeamRank >= 6)
        return 1;
    if (info->playHours > 999 || info->playMinutes > 59)
        return 1;
    if (info->infoVersion > 0x2D && info->infoVersion != 0x30)
        return 1;
    if (info->zoneId >= 427 || info->townmapRootZoneId >= 427)
        return 1;
    if (info->thanksCount > 99999 || info->passCount > 99999)
        return 1;
    if (GAME_BEACON_ACCESSOR_ActionCheckFuncs[GAME_BEACON_ACCESSOR_GetActionCheckIndex(info->action)](info) != 0)
        return 1;
    return 0;
}

int GAME_BEACON_ACCESSOR_IsDistributionAction(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}

void GAME_BEACON_ACCESSOR_GetPlayerName(const GameBeaconInfo *info, struct Strbuf *name)
{
    STRBUF_SetStringN(name, info->name, 8);
}

u32 GAME_BEACON_ACCESSOR_GetPmVersion(const GameBeaconInfo *info)
{
    return info->pmVersion;
}

u32 GAME_BEACON_ACCESSOR_GetLanguage(const GameBeaconInfo *info)
{
    return info->language;
}

u8 GAME_BEACON_ACCESSOR_GetNation(const GameBeaconInfo *info)
{
    return info->nation;
}

u8 GAME_BEACON_ACCESSOR_GetArea(const GameBeaconInfo *info)
{
    return info->area;
}

/* Questionnaire answers: 0xFF when the question has no answer. */
u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(const GameBeaconInfo *info)
{
    u32 answer = SYMBOL_SAVE_ReadBitField(info->questionnaire, 0x1a);

    if (answer == 0)
        return 0xff;
    return answer;
}

u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(const GameBeaconInfo *info)
{
    u32 answer = SYMBOL_SAVE_ReadBitField(info->questionnaire, 0x19);

    if (answer == 0)
        return 0xff;
    return answer;
}

void GAME_BEACON_ACCESSOR_GetDetailsPms(const GameBeaconInfo *info, GameBeaconPms *pms)
{
    pms->sentenceType = info->detailsPms.bits.pmsSentenceType;
    pms->sentenceId = info->detailsPms.bits.pmsSentenceId;
    pms->word[0] = info->pmsWord[0];
    pms->word[1] = info->pmsWord[1];
}

u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(const GameBeaconInfo *info)
{
    return info->researchTeamRank;
}

/* The owner color table has 16 entries. */
void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(u16 *rgb, const GameBeaconInfo *info)
{
    int color = info->favoriteColor;
    const u16 *colorTable = (u16 *)OSi_GetOwnerInfoExBuffer();

    *rgb = colorTable[color & 0xF];
}

u8 GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(const GameBeaconInfo *info)
{
    return info->favoriteColor;
}

u16 GAME_BEACON_ACCESSOR_GetTrainerId(const GameBeaconInfo *info)
{
    return info->trainerId;
}

/* Trainer appearance: the female ones follow the 8 male ones. */
u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(const GameBeaconInfo *info)
{
    if (info->sex == 0) {
        return info->trainerView;
    }
    return info->trainerView + 8;
}

u8 GAME_BEACON_ACCESSOR_GetSex(const GameBeaconInfo *info)
{
    return info->sex;
}

void GAME_BEACON_ACCESSOR_GetPlayTime(const GameBeaconInfo *info, u16 *hours, u16 *minutes)
{
    *hours = info->playHours;
    *minutes = info->playMinutes;
}

u8 GAME_BEACON_ACCESSOR_GetInfoVersion(const GameBeaconInfo *info)
{
    return info->infoVersion;
}

u16 GAME_BEACON_ACCESSOR_GetZoneId(const GameBeaconInfo *info)
{
    return info->zoneId;
}

u16 GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const GameBeaconInfo *info)
{
    return info->townmapRootZoneId;
}

u32 GAME_BEACON_ACCESSOR_GetPassCount(const GameBeaconInfo *info)
{
    return info->passCount;
}

u32 GAME_BEACON_ACCESSOR_GetThanksCount(const GameBeaconInfo *info)
{
    return info->thanksCount;
}

void GAME_BEACON_ACCESSOR_GetGreeting(const GameBeaconInfo *info, struct Strbuf *greeting)
{
    STRBUF_Clear(greeting);
    STRBUF_SetStringN(greeting, info->greeting, 9);
}

void GAME_BEACON_ACCESSOR_GetThanksName(const GameBeaconInfo *info, struct Strbuf *name)
{
    if (info->action != 0x18) {
        STRBUF_Clear(name);
    } else {
        STRBUF_SetString(name, info->actionData.text);
    }
}

void GAME_BEACON_ACCESSOR_GetFreeText(const GameBeaconInfo *info, struct Strbuf *text)
{
    if (info->action != 0x31) {
        STRBUF_Clear(text);
    } else {
        STRBUF_SetString(text, info->actionData.text);
    }
}

unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;

    if (type >= 6)
        type = 5;
    return type;
}

u16 GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;
    unsigned trainerNo = info->detailsValue;

    switch (type) {
    case 2:
    case 3:
    case 4:
        if (trainerNo == 0 || trainerNo >= 616)
            trainerNo = 1;
        return trainerNo;
    default:
        return 1;
    }
}

u16 GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;
    unsigned monsNo = info->detailsValue;

    switch (type) {
    case 0:
    case 1:
        if (monsNo == 0 || monsNo > 649)
            monsNo = 504;
        return monsNo;
    default:
        return 504;
    }
}

u16 GAME_BEACON_ACCESSOR_GetActionNo(const GameBeaconInfo *info)
{
    u16 action = info->action;

    if (action == 0 || action >= 0x33)
        action = 1;
    return action;
}

u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 14:
    case 15:
    case 17:
    case 38:
        return info->actionArg;
    }
    return 0x1F8;
}

u16 GAME_BEACON_ACCESSOR_GetActionItemNo(const GameBeaconInfo *info)
{
    if (info->action == 0x13 || info->action == 0x23)
        return info->actionData.value;
    return 0x11;
}

u16 GAME_BEACON_ACCESSOR_GetActionCountValue(const GameBeaconInfo *info)
{
    if (info->action == 0x24)
        return info->actionData.value;
    return 1;
}

u16 GAME_BEACON_ACCESSOR_GetDistributionMonsNo(const GameBeaconInfo *info)
{
    if (info->action == 0x19)
        return info->actionData.special.monsNo;
    return 0x1F8;
}

u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(const GameBeaconInfo *info)
{
    if (info->action == 0x1A)
        return info->actionData.special.itemNo;
    return 0x11;
}

u16 GAME_BEACON_ACCESSOR_GetDistributionSerial(const GameBeaconInfo *info)
{
    if (info->action == 0x32)
        return info->actionData.special.serial;
    return 0;
}

/* The case list has no effect; the original keeps it after the copy. */
void GAME_BEACON_ACCESSOR_GetNickname(const GameBeaconInfo *info, struct Strbuf *nickname)
{
    STRBUF_Clear(nickname);
    STRBUF_SetStringN(nickname, info->actionData.nickname, 11);
    switch (info->action) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 38:
    case 47:
        return;
    }
}

u16 GAME_BEACON_ACCESSOR_GetActionTrainerNo(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return info->actionData.value;
    }
    return 1;
}

u32 GAME_BEACON_ACCESSOR_GetPresetEventValue(const GameBeaconInfo *info)
{
    if (info->action == 0x16)
        return info->actionData.wordValue;
    return 1;
}

u16 GAME_BEACON_ACCESSOR_GetActionSpecialValue(const GameBeaconInfo *info)
{
    if (info->action == 0x14)
        return info->actionData.value;
    return 1;
}

u32 GAME_BEACON_ACCESSOR_GetActionWordValue(const GameBeaconInfo *info)
{
    if (info->action == 0x29)
        return info->actionData.wordValue;
    return 1;
}

u8 GAME_BEACON_ACCESSOR_GetActionByteValue(const GameBeaconInfo *info)
{
    if (info->action == 0x2C)
        return info->actionData.byteValue;
    return 0;
}

u16 GAME_BEACON_ACCESSOR_GetActionHalfwordValue(const GameBeaconInfo *info)
{
    if (info->action == 0x30)
        return info->actionData.value;
    return 0;
}

u8 GAME_BEACON_ACCESSOR_GetActionCheckIndex(u16 action)
{
    return GAME_BEACON_ACCESSOR_ActionTable[action].checkIndex;
}

struct WordSet;

#include "../types.h"

/* How the value of an action is registered for printing. */
enum BeaconPrintKind {
    BEACON_PRINT_TRAINER_NO = 1,
    BEACON_PRINT_MONS_NO = 2,
    BEACON_PRINT_NICKNAME = 3,
    BEACON_PRINT_MONS_NO_AND_NICKNAME = 4,
    BEACON_PRINT_ITEM_NO = 5,
    BEACON_PRINT_SPECIAL_VALUE = 6,
    BEACON_PRINT_PRESET_EVENT = 7,
    BEACON_PRINT_DISTRIBUTION_MONS_NO = 8,
    BEACON_PRINT_DISTRIBUTION_ITEM_NO = 9,
    BEACON_PRINT_COUNT_VALUE = 10,
    BEACON_PRINT_WORD_VALUE = 11,
    BEACON_PRINT_BYTE_VALUE = 12,
    BEACON_PRINT_HALFWORD_VALUE = 13,
    BEACON_PRINT_FREE_TEXT = 14,
    BEACON_PRINT_NONE = 15
};

#include "../arm9/wordset.h"













u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 actionType);

void GAME_BEACON_ACCESSOR_RegisterRecordWords(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId);

int GAME_BEACON_ACCESSOR_IsNoArgInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsNoValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionItemNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsPlayTimeInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionCountValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionByteValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid(GameBeaconInfo *info);

/*
 * Second byte of the two-byte table row for an action type.
 */
u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 actionType)
{
    return GAME_BEACON_ACCESSOR_ActionTable[actionType].group;
}

/*
 * Registers the words of a record for message printing: its name into
 * buffer 0, then the action-specific value (number, string or item) into
 * buffers 1 and 2.
 */
void GAME_BEACON_ACCESSOR_RegisterRecordWords(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId)
{
    struct Strbuf *buf;
    u8 printKind;
    uptr value;

    WORDSET_ClearAllSlots(wordSet);
    buf = STRBUF_Create(0x21, heapId);
    if (buf == 0)
        return;
    GAME_BEACON_ACCESSOR_GetPlayerName(info, buf);
    WORDSET_SetSlotTag(wordSet, 0, buf, 0, 1, 2);
    printKind = GAME_BEACON_ACCESSOR_GetActionCheckIndex(GAME_BEACON_ACCESSOR_GetActionNo(info));
    switch (printKind) {
    case BEACON_PRINT_TRAINER_NO:
        value = GAME_BEACON_ACCESSOR_GetActionTrainerNo(info);
        WORDSET_SetSlotPokeData(wordSet, 1, (void *)value);
        WORDSET_SetSlotFromMsgBE(wordSet, 2, value);
        break;
    case BEACON_PRINT_MONS_NO:
    case BEACON_PRINT_MONS_NO_AND_NICKNAME:
        WORDSET_SetSlotSpeciesName(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionMonsNo(info));
        if (printKind == BEACON_PRINT_MONS_NO)
            break;
    case BEACON_PRINT_NICKNAME:
        GAME_BEACON_ACCESSOR_GetNickname(info, buf);
        WORDSET_SetSlotTag(wordSet, 2, buf, 0, 1, 2);
        break;
    case BEACON_PRINT_ITEM_NO:
        WORDSET_SetSlotFromMsg117(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionItemNo(info));
        break;
    case BEACON_PRINT_SPECIAL_VALUE:
        WORDSET_SetSlotNumber(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionSpecialValue(info), 3, 0, 1);
        break;
    case BEACON_PRINT_PRESET_EVENT:
        WORDSET_SetSlotNumber(wordSet, 1, GAME_BEACON_ACCESSOR_GetPresetEventValue(info), 3, 0, 1);
        break;
    case BEACON_PRINT_DISTRIBUTION_MONS_NO:
        WORDSET_SetSlotSpeciesName(wordSet, 1, GAME_BEACON_ACCESSOR_GetDistributionMonsNo(info));
        break;
    case BEACON_PRINT_DISTRIBUTION_ITEM_NO:
        WORDSET_SetSlotFromMsg36(wordSet, 1, GAME_BEACON_ACCESSOR_GetDistributionItemNo(info));
        break;
    case BEACON_PRINT_COUNT_VALUE:
        WORDSET_SetSlotFromMsgCB(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionCountValue(info));
        break;
    case BEACON_PRINT_WORD_VALUE:
        WORDSET_SetSlotNumber(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionWordValue(info), 1, 0, 1);
        break;
    case BEACON_PRINT_BYTE_VALUE:
        WORDSET_SetSlotWeekday(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionByteValue(info));
        break;
    case BEACON_PRINT_HALFWORD_VALUE:
        WORDSET_SetSlotFromMsgA0(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionHalfwordValue(info));
        break;
    case BEACON_PRINT_FREE_TEXT:
        GAME_BEACON_ACCESSOR_GetFreeText((const GameBeaconInfo *)info, (struct Strbuf *)buf);
        WORDSET_SetSlotTag(wordSet, 1, buf, GAME_BEACON_ACCESSOR_GetSex(info), 1, 2);
        break;
    case BEACON_PRINT_NONE:
        break;
    }
    STRBUF_Delete(buf);
}

/*
 * Record field validators: each returns 1 when the field it checks is out
 * of range for its action kind. This one accepts everything.
 */
int GAME_BEACON_ACCESSOR_IsNoArgInvalid(GameBeaconInfo *info)
{
    return 0;
}

/* Trainer number at +0x34 must be 1..0x267. */
int GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x268)
        return 1;
    return 0;
}

/* Pokemon number at +0x32 must be 1..0x289. */
int GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}

/* Accepts everything (actions without a value). */
int GAME_BEACON_ACCESSOR_IsNoValueInvalid(GameBeaconInfo *info)
{
    return 0;
}

/* Pokemon number at +0x32 must be 1..0x289 (actions that also carry a nickname). */
int GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}

/* Item number at +0x34 must be 1..0x272. */
int GAME_BEACON_ACCESSOR_IsActionItemNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x272)
        return 1;
    return 0;
}

/* Play time: hours must be at most 999 and minutes at most 59. */
int GAME_BEACON_ACCESSOR_IsPlayTimeInvalid(GameBeaconInfo *info)
{
    if (info->playHours > 999 || info->playMinutes > 59)
        return 1;
    return 0;
}

/* Count value at +0x34 (32 bit) must be at most 99999. */
int GAME_BEACON_ACCESSOR_IsActionCountValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.wordValue > 99999)
        return 1;
    return 0;
}

/* Distributed pokemon number at +0x34 must be 1..0x289. */
int GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x289)
        return 1;
    return 0;
}

/* Distributed item number at +0x36 must be 1..0x272. */
int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.special.itemNo == 0 || info->actionData.special.itemNo > 0x272)
        return 1;
    return 0;
}

/* Move number at +0x34 must be 1..0x22F. */
int GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x230)
        return 1;
    return 0;
}

/* Preset event number at +0x34 (32 bit) must be 1..7. */
int GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid(GameBeaconInfo *info)
{
    if (info->actionData.wordValue == 0 || info->actionData.wordValue > 7)
        return 1;
    return 0;
}

/* Byte value at +0x34 must be at most 6. */
int GAME_BEACON_ACCESSOR_IsActionByteValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.byteValue > 6)
        return 1;
    return 0;
}

/* Halfword value at +0x34 must be below 0x30. */
int GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value >= 0x30)
        return 1;
    return 0;
}

/* Distribution serial at +0x38 must be below 0x30. */
int GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid(GameBeaconInfo *info)
{
    if (info->actionData.special.serial >= 0x30)
        return 1;
    return 0;
}
