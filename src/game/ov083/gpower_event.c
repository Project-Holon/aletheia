/*
 * file:     gpower_event.c
 * unit:     yes
 * function: GPOWER_EVENT_CreateActivateEvent, GPOWER_EVENT_CreateTimeoutScriptEvent, GPOWER_EVENT_CreateFlashEvent, GPOWER_EVENT_CreateListEvent, GPOWER_EVENT_InitListWork, GPOWER_EVENT_FreeListWork, GPOWER_EVENT_FlashMain, GPOWER_EVENT_RestoreParty, GPOWER_EVENT_ListMain, GPOWER_EVENT_PrintPowerRow, GPOWER_EVENT_PrintPowerList
 * address:  0x021F5260
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   GPOWER_GetPowerType  0x02010F94  thumb
 *   GPOWER_Activate   0x02010E14  thumb
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   GPOWER_GetPowerCost  0x02010FA0  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   MYITEM_SAVEDATA_RemoveItem   0x02007F1C  thumb
 *   GAME_BEACON_SEARCH_SetVersionAction  0x021652C4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetHalfwordValue  0x021657B0  thumb  ov010
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   FLDMMDL_SysResumeMove 0x0216D9E4 thumb ov010
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   GPOWER_UseHpRestore  0x0201104C  thumb
 *   GPOWER_UsePpRestore  0x020110CC  thumb
 *   FIELD_MSGBG_CreateInfoSysWin 0x02190FA0 thumb ov021
 *   FIELD_MSGBG_InfoSysWinPrintMsg 0x0219103C thumb ov021
 *   FIELD_MSGBG_InfoSysWinMain 0x021910C0 thumb ov021
 *   FIELD_MSGBG_DeleteInfoSysWin 0x02191008 thumb ov021
 *   FIELD_MSGBG_CreateInfoMsgWin 0x021907C4 thumb ov021
 *   FIELD_MSGBG_ClearInfoMsgWin 0x02190854 thumb ov021
 *   FIELD_MSGBG_DeleteInfoMsgWin 0x0219082C thumb ov021
 *   KEY_GetTrg 0x020362DC arm
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_InfoMsgWinPrintStr  0x02190844  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   GPOWER_GetActiveIdByType  0x02010EB4  thumb
 *   GPOWER_GetMinutesLeftByType  0x02010EC0  thumb
 */
#include "../types.h"

#include "gpower_event_types.h"

struct GameEvent;
struct ScriptWork;
struct MyItem;
struct PokeParty;
struct Pokemon;
struct SaveControl;
struct GPowerSave;
struct MsgBank;
struct Strbuf;
struct InfoMsgWin;
typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
struct GPowerData;
extern struct GPowerData *GPOWER_LoadPowerTable(u32 heapId);
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, s32 reserved);
extern void *SCRIPT_SYS_GetEventScriptWork(struct GameEvent *event);
extern unsigned int GPOWER_GetPowerType(struct GPowerData *table, s32 powerId);
extern void GPOWER_Activate(s32 powerId, struct GPowerData *table, s32 select);
extern int SCRIPT_WORK_SetParams(struct ScriptWork *scriptWork, u16 powerId, u16 powerType, u16 payWithItems, u16 unused);
extern void *SCRIPT_WORK_GetWordSet(struct ScriptWork *scriptWork);
extern u16   GPOWER_GetPowerCost(struct GPowerData *table, int powerId);
#include "../arm9/game_data.h"
#include "../arm9/myitem_savedata.h"
extern void GAME_BEACON_SEARCH_SetVersionAction(u32 version);
extern void  GAME_BEACON_SEARCH_SetHalfwordValue(int powerId);
extern void  GPOWER_FreePowerTable(struct GPowerData *table);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
#include "../ov021/fieldmap.h"
struct MmdlSys;
struct MsgBank;
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
#include "../arm9/strbuf.h"
#include "../ov010/fldmmdl.h"
#include "../arm9/wordset.h"
#include "../arm9/fade.h"
#include "../arm9/gfl_use.h"
struct Party;
#include "../arm9/pokeparty.h"
struct PokemonParam;
extern u32   GPOWER_UseHpRestore(void *party);
extern u32   GPOWER_UsePpRestore(void *party);
struct FieldSysWin;
#include "../ov021/field_msgbg.h"
struct FieldMsgWin;
#include "../arm9/key.h"
struct IntrudeSave;
#include "../arm9/intrude.h"
extern u8 GPOWER_GetActiveIdByType(int type);
extern u32 GPOWER_GetMinutesLeftByType(u32 type);
struct GameEvent *GPOWER_EVENT_CreateActivateEvent(struct GameSystem *gameSystem, GPowerActivateParam *param);
struct GameEvent *GPOWER_EVENT_CreateTimeoutScriptEvent(struct GameSystem *gameSystem);
struct GameEvent *GPOWER_EVENT_CreateFlashEvent(struct GameSystem *gameSystem);
struct GameEvent *GPOWER_EVENT_CreateListEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void GPOWER_EVENT_InitListWork(GPowerListWork *work, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void GPOWER_EVENT_FreeListWork(GPowerListWork *work);
int GPOWER_EVENT_FlashMain(struct GameEvent *event, int *seq, void *work);
void GPOWER_EVENT_RestoreParty(struct GameSystem *gameSystem, struct WordSet *wordSet, int powerType);
int GPOWER_EVENT_ListMain(struct GameEvent *event, int *seq, GPowerListWork *work);
void GPOWER_EVENT_PrintPowerRow(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row);
void GPOWER_EVENT_PrintPowerList(GPowerListWork *work);

struct GameEvent *GPOWER_EVENT_CreateActivateEvent(struct GameSystem *gameSystem, GPowerActivateParam *param)
{
    struct GameEvent *event;
    struct ScriptWork *scriptWork;
    struct GameData *gameData;
    struct GPowerTable *table;
    int powerId;
    int powerType;
    u16 cost;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    table = (struct GPowerTable *)GPOWER_LoadPowerTable(GPOWER_EVENT_HEAP_ID_BACK);
    powerId = param->powerId;
    event = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0x28B9, 0, GPOWER_EVENT_HEAP_ID);
    scriptWork = SCRIPT_SYS_GetEventScriptWork(event);
    if (powerId == GPOWER_ID_NONE || powerId > GPOWER_ID_LAST) {
        powerId = 0;
    }
    powerType = GPOWER_GetPowerType((struct GPowerData *)table, powerId);
    GPOWER_Activate(powerId, (struct GPowerData *)table, param->payWithItems);
    /* Power 0x27 tells the script type 0xB whatever its table type is. */
    if (powerId == 0x27) {
        SCRIPT_WORK_SetParams(scriptWork, powerId, 0xB, param->payWithItems, 0);
    } else {
        SCRIPT_WORK_SetParams(scriptWork, powerId, powerType, param->payWithItems, 0);
    }
    GPOWER_EVENT_RestoreParty(gameSystem, SCRIPT_WORK_GetWordSet(scriptWork), powerType);
    if (param->payWithItems != 0) {
        cost = GPOWER_GetPowerCost((struct GPowerData *)table, powerId);
        MYITEM_SAVEDATA_RemoveItem(GAME_DATA_GetMyItem(gameData), GPOWER_COST_ITEM_ID, cost, GPOWER_EVENT_HEAP_ID_BACK);
        GAME_BEACON_SEARCH_SetVersionAction(powerId);
    } else {
        GAME_BEACON_SEARCH_SetHalfwordValue(powerId);
    }
    GPOWER_FreePowerTable((struct GPowerData *)table);
    return event;
}

struct GameEvent *GPOWER_EVENT_CreateTimeoutScriptEvent(struct GameSystem *gameSystem)
{
    return SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0x28BA, 0, GPOWER_EVENT_HEAP_ID);
}

struct GameEvent *GPOWER_EVENT_CreateFlashEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    GPowerFlashWork *work;

    event = GAME_EVENT_Create(gameSystem, 0, GPOWER_EVENT_FlashMain, sizeof(GPowerFlashWork));
    work = GAME_EVENT_GetWork(event);
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->gameSystem = gameSystem;
    return event;
}

struct GameEvent *GPOWER_EVENT_CreateListEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)GPOWER_EVENT_ListMain, sizeof(GPowerListWork));
    GPOWER_EVENT_InitListWork(GAME_EVENT_GetWork(event), gameSystem, fieldMap);
    return event;
}

void GPOWER_EVENT_InitListWork(GPowerListWork *work, struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    work->heapId = GPOWER_EVENT_HEAP_ID;
    work->heapIdBack = (work->heapId & 0x7FFF) | 0x8000;
    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->msgBg = FIELDMAP_GetMsgBg(work->fieldMap);
    work->mmdlSys = (struct FldMmdlSys *)FIELDMAP_GetMmdlSys(work->fieldMap);
    work->powerTable = (struct GPowerTable *)GPOWER_LoadPowerTable(work->heapId);
    work->msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 3, 0x108, work->heapId);
    work->wordSet = WORDSET_CreateDefault(work->heapId);
    work->templateStr = STRBUF_Create(0x81, work->heapId);
    work->lineStr = STRBUF_Create(0x81, work->heapId);
    FLDMMDL_SysPauseMove((struct MmdlSys *)work->mmdlSys);
}

void GPOWER_EVENT_FreeListWork(GPowerListWork *work)
{
    STRBUF_Delete(work->lineStr);
    STRBUF_Delete(work->templateStr);
    WORDSET_Delete(work->wordSet);
    MSGDATA_Delete(work->msgData);
    GPOWER_FreePowerTable((struct GPowerData *)work->powerTable);
    FLDMMDL_SysResumeMove((struct MmdlSys *)work->mmdlSys);
}

int GPOWER_EVENT_FlashMain(struct GameEvent *event, int *seq, void *work)
{
    switch (*seq) {
    case 0:
        FADE_Start(4, 10, 16, 4);
        GFL_USE_PlaySeDefaultVolume(0x5E0);
        (*seq)++;
        break;
    case 1:
        if (FADE_IsActive() != 0)
            break;
        FADE_Start(4, 16, 0, 8);
        (*seq)++;
    case 2:
        if (FADE_IsActive() != 0)
            break;
    default:
        return 1;
    }
    return 0;
}

void GPOWER_EVENT_RestoreParty(struct GameSystem *gameSystem, struct WordSet *wordSet, int powerType)
{
    struct PokeParty *party = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(gameSystem));
    u8 firstReady;

    firstReady = POKEPARTY_FindFirstBattleReady((struct Party *)party);
    WORDSET_SetSlotMonNickname(wordSet, 1, POKEPARTY_GetMember((struct Party *)party, firstReady));
    switch (powerType) {
    case 5:
        GPOWER_UseHpRestore(party);
        break;
    case 6:
        GPOWER_UsePpRestore(party);
        break;
    }
}

int GPOWER_EVENT_ListMain(struct GameEvent *event, int *seq, GPowerListWork *work)
{
    struct InfoSysWin *openWin;
    switch (*seq) {
    case 0:
        openWin = (struct InfoSysWin *)FIELD_MSGBG_CreateInfoSysWin(work->msgBg, work->msgData, 19);
        work->infoSysWin = openWin;
        FIELD_MSGBG_InfoSysWinPrintMsg((struct FieldSysWin *)openWin, 0, 0, 3);
        *seq += 1;
        break;
    case 1:
        if (FIELD_MSGBG_InfoSysWinMain((struct FieldSysWin *)work->infoSysWin)) {
            FIELD_MSGBG_DeleteInfoSysWin((struct FieldSysWin *)work->infoSysWin);
            *seq += 1;
        }
        break;
    case 2:
        work->infoMsgWin = (struct InfoMsgWin *)FIELD_MSGBG_CreateInfoMsgWin(work->msgBg, work->msgData, 4, 1, 24, 22);
        FIELD_MSGBG_ClearInfoMsgWin((struct FieldMsgWin *)work->infoMsgWin);
        GPOWER_EVENT_PrintPowerList(work);
        *seq += 1;
        break;
    case 3:
        if (KEY_GetTrg() & 3) *seq += 1;
        break;
    default:
        FIELD_MSGBG_ClearInfoMsgWin((struct FieldMsgWin *)work->infoMsgWin);
        FIELD_MSGBG_DeleteInfoMsgWin((struct FieldMsgWin *)work->infoMsgWin);
        GPOWER_EVENT_FreeListWork(work);
        return 1;
    }
    return 0;
}

void GPOWER_EVENT_PrintPowerRow(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row)
{
    WORDSET_SetSlotFromMsgA0(work->wordSet, 0, powerId);
    WORDSET_SetSlotNumber(work->wordSet, 1, minutes / 60, 2, 1, 1);
    WORDSET_SetSlotNumber(work->wordSet, 2, minutes % 60, 2, 2, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->lineStr, templateStr);
    FIELD_MSGBG_InfoMsgWinPrintStr((struct FieldMsgWin *)work->infoMsgWin, 8, (u16)(row << 4), work->lineStr);
}

void GPOWER_EVENT_PrintPowerList(GPowerListWork *work)
{
    u8 powerIds[13];
    u8 order[13];
    u16 minutesLeft[13];
    struct GPowerSave *gpowerSave;
    u8 powerId;
    u8 i;
    u8 j;
    u8 count;
    u8 swapTmp;

    gpowerSave = (struct GPowerSave *)INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(work->gameData));
    MSGDATA_ReadString(work->msgData, 4, work->templateStr);
    FIELD_MSGBG_InfoMsgWinPrintStr((struct FieldMsgWin *)work->infoMsgWin, 0, 0, work->templateStr);
    MSGDATA_ReadString(work->msgData, 6, work->templateStr);
    powerId = (int)INTRUDE_GetMonolithLevel((struct IntrudeSave *)gpowerSave);
    if (powerId != GPOWER_ID_NONE) {
        GPOWER_EVENT_PrintPowerRow(work, work->templateStr, powerId, 0, 1);
    }
    MSGDATA_ReadString(work->msgData, 5, work->templateStr);
    FIELD_MSGBG_InfoMsgWinPrintStr((struct FieldMsgWin *)work->infoMsgWin, 0, 0x30, work->templateStr);
    MSGDATA_ReadString(work->msgData, 7, work->templateStr);

    /* The `for (i = 0, count = 0; ...)` form (not `count = 0;` before the loop) keeps the constant zero in r4 across the calls and seeds i from it. */
    for (i = 0, count = 0; i < 13; i++) {
        order[i] = i;
        powerId = (int)GPOWER_GetActiveIdByType((u8)i);
        if (powerId != GPOWER_ID_NONE) {
            minutesLeft[count] = GPOWER_GetMinutesLeftByType(i);
            powerIds[count] = powerId;
            count++;
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = count - 1; j > i; j--) {
            if (minutesLeft[order[j - 1]] > minutesLeft[order[j]]) {
                swapTmp = order[j];
                order[j] = order[j - 1];
                order[j - 1] = swapTmp;
            }
        }
    }

    for (i = 0; i < count; i++) {
        GPOWER_EVENT_PrintPowerRow(work, work->templateStr, powerIds[order[i]], minutesLeft[order[i]], i + 4);
    }
}
