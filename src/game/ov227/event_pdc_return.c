/*
 * file:     event_pdc_return.c
 * unit:     yes
 * function: EVENT_PDC_RETURN_CreateArgs, EVENT_PDC_RETURN_DeleteArgs, EVENT_PDC_RETURN_Init, EVENT_PDC_RETURN_Exit, EVENT_PDC_RETURN_Step
 * address:  0x021B95A0
 * region:   ov227
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * ov227 event "pdc return": the overlay registers the player's caught/seen
 * Zukan record and, when the party is full, prompts for a name (ov010
 * NAMEIN_SETUP) and deposits the mon in the box. EVENT_PDC_RETURN_Step is the proc
 * state machine; EVENT_PDC_RETURN_Init/EVENT_PDC_RETURN_Exit are its init and exit callbacks.
 *
 * note: case 1/2 bodies sit under `if (procResult != 1) { ... }` with
 *   `return 0;` after the block (late per-case epilogues); the nameConfirmed
 *   test goes through an `ok` flag. Pool words 0xCF/0xC2 are the overlay ids
 *   ov207_id/ov194_id.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021B98C0 0x021B98C0 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 *   PROCSYS_Delete 0x0203133C arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BOX_SAVEDATA_AddPokemon  0x020074D8  thumb
 *   BOX_SAVEDATA_GetCurrentBox  0x02007698  thumb
 *   BOX_SAVEDATA_FindFreeSlot  0x020076D0  thumb
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   ov207_id  0x000000CF  data
 *   ov194_id  0x000000C2  data
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   NAMEIN_SETUP_CreateCaptureArgs  0x0216C0A4  thumb  ov010
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 *   NAMEIN_SETUP_CopyName  0x0216C0D4  thumb  ov010
 *   NAMEIN_SETUP_IsCanceled  0x0216C0E4  thumb  ov010
 */

struct GameData;
struct SaveBlock;
struct ZukanWork;
struct PlayerWork;
struct Party;
struct PartyMon;
struct MsgBank;
struct MsgEntry;
struct BoxEntry;
struct TrainerRecord;
struct ProcSys;

#include "../types.h"

/* proc work object of ov227 (0x38 bytes); one view for every access */
typedef struct {
    u32 nameArgs;          /* 0x00 NAMEIN_SETUP args */
    u32 strbuf;            /* 0x04 STRBUF for the status text */
    u32 resultFlag;        /* 0x08 0 or 1, pushed to the ov207 child */
    u32 partyMon;          /* 0x0C the mon being returned */
    u32 nationalDex;       /* 0x10 ZUKAN_SAVE_IsNationalDexEnabled */
    u32 messageId;         /* 0x14 MSGDATA_AllocString message id */
    u32 boxManager;        /* 0x18 GAME_DATA_GetBoxManager */
    u32 boxSlot;           /* 0x1C box slot */
    u32 gameData;          /* 0x20 the game data object */
    u32 nameConfirmed;     /* 0x24 1 once NAMEIN_SETUP finished */
    u32 partyFullMessage;  /* 0x28 message shown when the party was full */
    u32 boxSlotCandidate;  /* 0x2C box slot returned by BOX_SAVEDATA_FindFreeSlot */
    u16 heapId;            /* 0x30 0x8b */
    u16 pad32;             /* 0x32 padding, never read */
    u32 procSys;           /* 0x34 PROCSYS_Create result */
} EventPdcReturnWork;

/* step arguments of ov227 (c) */
typedef struct {
    u32 gameData;          /* 0x00 the game data object */
    u32 mode;              /* 0x04 1 return, 2 seen only */
    u32 partyMon;          /* 0x08 the mon */
} EventPdcReturnArgs;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/strbuf.h"
extern void PROCSYS_Delete(ProcSys *sys);
extern unsigned int PROCSYS_Main(ProcSys *sys);
extern void PROCSYS_Push(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
#include "../arm9/game_data.h"
struct MyStatus;
#include "../arm9/zukan_save.h"
#include "../arm9/record.h"
#include "../arm9/mystatus.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
#include "../arm9/pokeparty.h"
#include "../arm9/box_savedata.h"
#include "../arm9/msgdata.h"
struct EventWork;
#include "../arm9/zonedata.h"
#include "../arm9/save_event.h"
struct ZukanSave;
struct SaveControl;
struct MiscSave;
#include "../arm9/beacon.h"
struct NameInArgs;
#include "../ov010/namein_setup.h"
struct BoxPokemon;
void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap);
void EVENT_PDC_RETURN_DeleteArgs(void *p);
int EVENT_PDC_RETURN_Init(struct ProcSys *procSys);
int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p);
u32 EVENT_PDC_RETURN_Step(u32 task, u32 *state, EventPdcReturnArgs *c, EventPdcReturnWork *g);
extern const char d_021B98C0[];
extern unsigned char ov207_id[];
extern unsigned char ov194_id[];

void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap){u32 *p; p=GFL_HEAP_Alloc(heap,12,0,d_021B98C0,94);p[0]=a;p[1]=b;p[2]=c;return p;}

void EVENT_PDC_RETURN_DeleteArgs(void *p){GFL_HEAP_Free(p);}

int EVENT_PDC_RETURN_Init(struct ProcSys *procSys)
{
    EventPdcReturnWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x8b, 0x1000);
    work = (EventPdcReturnWork *)PROCSYS_AllocProcWork((struct Proc *)procSys, 0x38, 0x8b);
    work->strbuf = (sptr)STRBUF_Create(0x20, 0x8b);
    work->nameArgs = 0;
    work->partyFullMessage = 0;
    work->boxSlotCandidate = 0;
    work->heapId = 0x8b;
    work->procSys = (sptr)PROCSYS_Create(work->heapId);
    return 1;
}

int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p){EventPdcReturnWork *work;work=(EventPdcReturnWork *)p;PROCSYS_Delete((struct ProcSys *)work->procSys);if(work->partyFullMessage)STRBUF_Delete((struct Strbuf *)work->partyFullMessage);STRBUF_Delete((struct Strbuf *)work->strbuf);PROCSYS_FreeProcWork((struct Proc *)procSys);GFL_HEAP_DeleteChecked(139);return 1;}

u32 EVENT_PDC_RETURN_Step(u32 task, u32 *state, EventPdcReturnArgs *args, EventPdcReturnWork *work)
{
    u32 procResult, placeNameId; uptr playerStatus, party, boxManager, trainerRecord; u32 nationalDex; uptr msgBank, tmp;
    int partyCount, isNew, nameConfirmed;

    procResult = PROCSYS_Main((void *)work->procSys);
    if (procResult == 1) {
        return 0;
    }
    switch (*state) {
    case 0:
        party = (uptr)GAME_DATA_GetMyParty((const struct GameData *)args->gameData);
        playerStatus = (uptr)GAME_DATA_GetMyStatus((void *)args->gameData);
        tmp = (uptr)ZUKAN_SAVE_GetFromGameData((void *)args->gameData);
        boxManager = GAME_DATA_GetBoxManager((const struct GameData *)args->gameData);
        if (args->mode == 1) {
            trainerRecord = (uptr)GAME_DATA_GetTrainerRecord((struct GameData *)args->gameData);
            RECORD_AddOne((struct RecordBlock *)trainerRecord, (u32)7);
            RECORD_AddOne((struct RecordBlock *)trainerRecord, (u32)0x54);
            MYSTATUS_NameToStrbuf((void *)playerStatus, (void *)work->strbuf);
            POKE_TOOL_SetPartyValue((void *)args->partyMon, 0x8d, work->strbuf);
            partyCount = (int)POKEPARTY_GetCount((void *)party);
            if (partyCount >= (int)POKEPARTY_GetCapacity((void *)party)) {
                u32 a, b;
                a = BOX_SAVEDATA_GetCurrentBox((void *)boxManager);
                b = 0;
                BOX_SAVEDATA_FindFreeSlot((void *)boxManager, (int *)(&a), (int *)(&b));
                work->boxSlotCandidate = a;
                msgBank = (uptr)MSGDATA_CreateFromArchive(0, 2, 0xea, 0x8b);
                work->partyFullMessage = (uptr)MSGDATA_AllocString((struct MsgBank *)msgBank, ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((const struct GameData *)args->gameData), (u32)0x96d) != 0 ? 0xb1 : 0xb0);
                MSGDATA_Delete((struct MsgBank *)msgBank);
            }
            placeNameId = ZONEDATA_GetPlaceNameId((u32)GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct GameData *)args->gameData)));
            SAVE_EVENT_Write((void *)args->partyMon, 0, (const struct MyStatus *)playerStatus, placeNameId, (u32)work->heapId);
            isNew = 0;
            nationalDex = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanSave *)tmp);
            if (ZUKAN_SAVE_IsCaught((struct ZukanSave *)tmp, (u16)POKE_TOOL_GetPartyValue((void *)args->partyMon, 5, 0)) == 0) {
                isNew = 1;
            }
            ZUKAN_SAVE_RegisterSeen((struct ZukanSave *)tmp, (void *)args->partyMon);
            ZUKAN_SAVE_RegisterCaught((struct ZukanSave *)tmp, (void *)args->partyMon);
            work->partyMon = args->partyMon;
            work->nationalDex = nationalDex;
            work->messageId = work->partyFullMessage;
            work->boxManager = boxManager;
            work->boxSlot = work->boxSlotCandidate;
            work->gameData = args->gameData;
            if (isNew) {
                work->resultFlag = 0;
            } else {
                work->resultFlag = 1;
            }
            PROCSYS_Push((ProcSys *)work->procSys, (uptr)ov207_id, (const ProcData *)(0x0220BAB0), (void *)&work->resultFlag);
            (*state)++;
            break;
        }
        if (args->mode == 2) {
            ZUKAN_SAVE_RegisterSeen((struct ZukanSave *)tmp, (void *)args->partyMon);
        }
        *state = 4;
        break;
    case 1:
        if (procResult != 1) {
        tmp = GAME_DATA_GetBoxManager((const struct GameData *)args->gameData);
        nameConfirmed = 0;
        if (work->nameConfirmed == 1) {
            nameConfirmed = 1;
        }
        if (nameConfirmed) {
            work->nameArgs = (uptr)NAMEIN_SETUP_CreateCaptureArgs((u32)work->heapId, (void *)args->partyMon, (u32)0xa, (struct Strbuf *)0, (struct Strbuf *)work->partyFullMessage, (void *)tmp, (u32)work->boxSlotCandidate, (void *)MISC_GetBlock(GAME_DATA_GetSaveControl((struct GameData *)args->gameData)));
            PROCSYS_Push((ProcSys *)work->procSys, (uptr)ov194_id, (const ProcData *)(0x021F5580), (void *)work->nameArgs);
            (*state)++;
            break;
        }
        *state = 3;
        break;
        }
        return 0;
    case 2:
        if (procResult != 1) {
        if ((u32)NAMEIN_SETUP_IsCanceled((struct NameInArgs *)work->nameArgs) == 0) {
            NAMEIN_SETUP_CopyName((struct NameInArgs *)work->nameArgs, (struct Strbuf *)work->strbuf);
            POKE_TOOL_SetPartyValue((void *)args->partyMon, 0x73, work->strbuf);
            RECORD_AddOne(GAME_DATA_GetTrainerRecord((struct GameData *)args->gameData), (u32)0x1e);
        }
        NAMEIN_SETUP_FreeArgs((struct NameInArgs *)work->nameArgs);
        work->nameArgs = 0;
        (*state)++;
        break;
        }
        return 0;
    case 3:
        party = (uptr)GAME_DATA_GetMyParty((const struct GameData *)args->gameData);
        if (work->partyFullMessage == 0) {
            POKEPARTY_Add((struct Party *)party, (struct PokemonParam *)args->partyMon);
        } else {
            tmp = GAME_DATA_GetBoxManager((const struct GameData *)args->gameData);
            BOX_SAVEDATA_AddPokemon((struct GameData *)tmp, (struct BoxPokemon *)POKE_TOOL_CastToBoxParam((struct PokemonParam *)args->partyMon));
        }
        (*state)++;
        break;
    case 4:
    default:
        return 1;
    }
    return 0;
}
