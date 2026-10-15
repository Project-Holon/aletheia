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
 *   func_02030734 0x02030734 arm
 *   d_021B98C0 0x021B98C0 data a4
 *   func_020307B0 0x020307B0 arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_020074D8  0x020074D8  thumb
 *   func_02007698  0x02007698  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
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
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_0202F190  0x0202F190  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   ov207_id  0x000000CF  data
 *   ov194_id  0x000000C2  data
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
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

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int s32;

/* proc work object of ov227 (0x38 bytes); one view for every access */
typedef struct {
    u32 nameArgs;          /* 0x00 NAMEIN_SETUP args */
    u32 strbuf;            /* 0x04 STRBUF for the status text */
    u32 resultFlag;        /* 0x08 0 or 1, pushed to the ov207 child */
    u32 partyMon;          /* 0x0C the mon being returned */
    u32 nationalDex;       /* 0x10 ZUKAN_SAVE_IsNationalDexEnabled */
    u32 messageId;         /* 0x14 func_02045EC0 message id */
    u32 boxManager;        /* 0x18 GAME_DATA_GetBoxManager */
    u32 boxSlot;           /* 0x1C box slot */
    u32 gameData;          /* 0x20 the game data object */
    u32 nameConfirmed;     /* 0x24 1 once NAMEIN_SETUP finished */
    u32 partyFullMessage;  /* 0x28 message shown when the party was full */
    u32 boxSlotCandidate;  /* 0x2C box slot returned by func_020076D0 */
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

extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern u32 func_020307B0(void *p);
extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
extern void *PROCSYS_AllocProcWork(struct ProcSys *obj, unsigned int size, unsigned int heap);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void *PROCSYS_Create(int a0);
extern void func_0203133C(struct ProcSys *p);
extern void STRBUF_Delete(struct Strbuf *p);
extern void func_020315D4(struct ProcSys *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern unsigned int PROCSYS_Main(void *p);
extern u32 PROCSYS_Push(u32 a, u32 b, u32 c, void *d);
extern void *GAME_DATA_GetMyParty(const struct GameData *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 GAME_DATA_GetBoxManager(const struct GameData *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct TrainerRecord *obj, int i);
extern void func_02008500(void *a, void *b);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 func_02007698(void *save);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 GAME_DATA_GetEventWork(const struct GameData *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct MsgEntry *rec);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *p);
extern u32 ZONEDATA_GetPlaceNameId(u32 a);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanWork *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 ZUKAN_SAVE_IsCaught(struct ZukanWork *p, u16 id);
extern void ZUKAN_SAVE_RegisterSeen(struct ZukanWork *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct ZukanWork *p, void *m);
extern void *GAME_DATA_GetSaveControl(struct GameData *p);
extern void *BEACON_GetBlock(void *sys);
extern int *NAMEIN_SETUP_CreateCaptureArgs(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int NAMEIN_SETUP_IsCanceled(int *p);
extern void NAMEIN_SETUP_CopyName(int *p, int a1);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 POKE_TOOL_Dummy(u32 a);
extern int func_020074D8(void **save, const struct BoxEntry *src);
void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap);
void EVENT_PDC_RETURN_DeleteArgs(void *p);
int EVENT_PDC_RETURN_Init(struct ProcSys *procSys);
int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p);
u32 EVENT_PDC_RETURN_Step(u32 a0, u32 *state, EventPdcReturnArgs *c, EventPdcReturnWork *g);
extern const char d_021B98C0[];
extern unsigned char ov207_id[];
extern unsigned char ov194_id[];


void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap){u32 *p; p=func_02030734(heap,12,0,d_021B98C0,94);p[0]=a;p[1]=b;p[2]=c;return p;}


void EVENT_PDC_RETURN_DeleteArgs(void *p){func_020307B0(p);}



int EVENT_PDC_RETURN_Init(struct ProcSys *procSys)
{
    EventPdcReturnWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x8b, 0x1000);
    work = (EventPdcReturnWork *)PROCSYS_AllocProcWork(procSys, 0x38, 0x8b);
    work->strbuf = (int)STRBUF_Create(0x20, 0x8b);
    work->nameArgs = 0;
    work->partyFullMessage = 0;
    work->boxSlotCandidate = 0;
    work->heapId = 0x8b;
    work->procSys = (int)PROCSYS_Create(work->heapId);
    return 1;
}


int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p){EventPdcReturnWork *work;work=(EventPdcReturnWork *)p;func_0203133C((struct ProcSys *)work->procSys);if(work->partyFullMessage)STRBUF_Delete((struct Strbuf *)work->partyFullMessage);STRBUF_Delete((struct Strbuf *)work->strbuf);func_020315D4(procSys);GFL_HEAP_DeleteChecked(139);return 1;}


u32 EVENT_PDC_RETURN_Step(u32 a0, u32 *state, EventPdcReturnArgs *c, EventPdcReturnWork *g)
{
    u32 procResult, placeNameId, playerStatus, party, boxManager, trainerRecord, nationalDex, msgBank, tmp;
    int partyCount, isNew, nameConfirmed;

    procResult = PROCSYS_Main((void *)g->procSys);
    if (procResult == 1) {
        return 0;
    }
    switch (*state) {
    case 0:
        party = (u32)GAME_DATA_GetMyParty((const struct GameData *)c->gameData);
        playerStatus = (u32)GAME_DATA_GetMyStatus((void *)c->gameData);
        tmp = (u32)ZUKAN_SAVE_GetFromGameData((void *)c->gameData);
        boxManager = GAME_DATA_GetBoxManager((const struct GameData *)c->gameData);
        if (c->mode == 1) {
            trainerRecord = (u32)GAME_DATA_GetTrainerRecord((int *)c->gameData);
            func_02008DF0((struct TrainerRecord *)trainerRecord, (u32)7);
            func_02008DF0((struct TrainerRecord *)trainerRecord, (u32)0x54);
            func_02008500((void *)playerStatus, (void *)g->strbuf);
            POKE_TOOL_SetPartyValue((void *)c->partyMon, 0x8d, g->strbuf);
            partyCount = (int)POKEPARTY_GetCount((void *)party);
            if (partyCount >= (int)POKEPARTY_GetCapacity((void *)party)) {
                u32 a, b;
                a = func_02007698((void *)boxManager);
                b = 0;
                func_020076D0((void *)boxManager, (int *)(&a), (int *)(&b));
                g->boxSlotCandidate = a;
                msgBank = (u32)func_02045B38(0, 2, 0xea, 0x8b);
                g->partyFullMessage = (u32)func_02045EC0((struct MsgBank *)msgBank, ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((const struct GameData *)c->gameData), (u32)0x96d) != 0 ? 0xb1 : 0xb0);
                MSGDATA_Delete((struct MsgEntry *)msgBank);
            }
            placeNameId = ZONEDATA_GetPlaceNameId((u32)GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)c->gameData)));
            func_0202F190((void *)c->partyMon, 0, playerStatus, placeNameId, (u32)g->heapId);
            isNew = 0;
            nationalDex = ZUKAN_SAVE_IsNationalDexEnabled((struct ZukanWork *)tmp);
            if (ZUKAN_SAVE_IsCaught((struct ZukanWork *)tmp, (u16)POKE_TOOL_GetPartyValue((void *)c->partyMon, 5, 0)) == 0) {
                isNew = 1;
            }
            ZUKAN_SAVE_RegisterSeen((struct ZukanWork *)tmp, (void *)c->partyMon);
            ZUKAN_SAVE_RegisterCaught((struct ZukanWork *)tmp, (void *)c->partyMon);
            g->partyMon = c->partyMon;
            g->nationalDex = nationalDex;
            g->messageId = g->partyFullMessage;
            g->boxManager = boxManager;
            g->boxSlot = g->boxSlotCandidate;
            g->gameData = c->gameData;
            if (isNew) {
                g->resultFlag = 0;
            } else {
                g->resultFlag = 1;
            }
            PROCSYS_Push(g->procSys, (u32)ov207_id, 0x0220BAB0, &g->resultFlag);
            (*state)++;
            break;
        }
        if (c->mode == 2) {
            ZUKAN_SAVE_RegisterSeen((struct ZukanWork *)tmp, (void *)c->partyMon);
        }
        *state = 4;
        break;
    case 1:
        if (procResult != 1) {
        tmp = GAME_DATA_GetBoxManager((const struct GameData *)c->gameData);
        nameConfirmed = 0;
        if (g->nameConfirmed == 1) {
            nameConfirmed = 1;
        }
        if (nameConfirmed) {
            g->nameArgs = (u32)NAMEIN_SETUP_CreateCaptureArgs((u32)g->heapId, (u32)c->partyMon, (u32)0xa, (u32)0, (u32)g->partyFullMessage, (u32)tmp, (u32)g->boxSlotCandidate, (u32)BEACON_GetBlock(GAME_DATA_GetSaveControl((struct GameData *)c->gameData)));
            PROCSYS_Push(g->procSys, (u32)ov194_id, 0x021F5580, (void *)g->nameArgs);
            (*state)++;
            break;
        }
        *state = 3;
        break;
        }
        return 0;
    case 2:
        if (procResult != 1) {
        if ((u32)NAMEIN_SETUP_IsCanceled((int *)g->nameArgs) == 0) {
            NAMEIN_SETUP_CopyName((int *)g->nameArgs, (u32)g->strbuf);
            POKE_TOOL_SetPartyValue((void *)c->partyMon, 0x73, g->strbuf);
            func_02008DF0(GAME_DATA_GetTrainerRecord((int *)c->gameData), (u32)0x1e);
        }
        NAMEIN_SETUP_FreeArgs((u32)g->nameArgs);
        g->nameArgs = 0;
        (*state)++;
        break;
        }
        return 0;
    case 3:
        party = (u32)GAME_DATA_GetMyParty((const struct GameData *)c->gameData);
        if (g->partyFullMessage == 0) {
            POKEPARTY_Add((struct Party *)party, (const struct PartyMon *)c->partyMon);
        } else {
            tmp = GAME_DATA_GetBoxManager((const struct GameData *)c->gameData);
            func_020074D8((void **)tmp, (const struct BoxEntry *)POKE_TOOL_Dummy(c->partyMon));
        }
        (*state)++;
        break;
    case 4:
    default:
        return 1;
    }
    return 0;
}
