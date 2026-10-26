/*
 * file:     digitalcardcheck.c
 * unit:     yes
 * function: DIGITALCARDCHECK_UpdateMenu, DIGITALCARDCHECK_GetMenuResult, DIGITALCARDCHECK_End, DIGITALCARDCHECK_CreateRecord, DIGITALCARDCHECK_WaitRecord, DIGITALCARDCHECK_DeleteRecord, DIGITALCARDCHECK_IsRecordDone, DIGITALCARDCHECK_IsWorkDone, DIGITALCARDCHECK_SetRecordMode, DIGITALCARDCHECK_CreateRecord2, DIGITALCARDCHECK_DeleteRecord2, DIGITALCARDCHECK_IsRecord2Done, DIGITALCARDCHECK_CreateRecord3, DIGITALCARDCHECK_DeleteRecord3, DIGITALCARDCHECK_IsRecord3DoneA, DIGITALCARDCHECK_IsRecord3DoneB, DIGITALCARDCHECK_CopyRegulation, DIGITALCARDCHECK_BuildBattleRecord, DIGITALCARDCHECK_SetBattleRecordValue, DIGITALCARDCHECK_Create, DIGITALCARDCHECK_Delete, DIGITALCARDCHECK_DeleteAlt, DIGITALCARDCHECK_GetProcResult, DIGITALCARDCHECK_SelectPhase, DIGITALCARDCHECK_Phase1, DIGITALCARDCHECK_Phase2, DIGITALCARDCHECK_Phase3, DIGITALCARDCHECK_Phase4, DIGITALCARDCHECK_Phase5, DIGITALCARDCHECK_Phase6, DIGITALCARDCHECK_EndPhase, DIGITALCARDCHECK_InitRecord, DIGITALCARDCHECK_DeleteInitRecord, DIGITALCARDCHECK_IsInitRecordDone, DIGITALCARDCHECK_IsInitWorkDone
 * address:  0x0217CFE8
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_End 0x0217BBD4 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   LIVEBATTLEMATCH_SAVE_GetCounter 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   MYSTATUS_GetTrainerView 0x02008554 thumb
 *   REGULATION_Card_GetCupName 0x0200B074 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   WIFIBATTLEMATCH_VIEW_CreateDateWindow 0x021E6118 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteDateWindow  0x021E62A0  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow 0x021E64C8 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepMainWindowIdle 0x021E65FC thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DrawDateWindow 0x021E62CC thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreateRecordWindow 0x021E7520 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWindow 0x021E7710 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepRecordWindow 0x021E777C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreatePartyWindow 0x021E7E3C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeletePartyWindow 0x021E82BC thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindow 0x021E8338 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt 0x021E8420 thumb ov177
 *   BATTLE_BOX_CreateParty 0x0200BAF4 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GREETING_SAVEDATA_GetFromSaveThunk  0x0200E6E8  thumb
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb
 *   ov067_id       0x00000043  data
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WIFIBATTLEMATCH_VIEW_LoadBgPalette 0x021E58A4 thumb ov177
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   d_0217E61C 0x0217E61C data a1
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback  0x021E8A80  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList  0x021E64C0  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   LIVEBATTLEMATCH_IRC_ShowMenu 0x0217DEA4 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   LIVEBATTLEMATCH_IRC_DeleteMenuRecord 0x0217E000 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ToggleSe 0x0217DFF0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_SetMenuValue 0x0217DFD0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetMenuValue 0x0217DFE4 thumb ov176
 *   LIVEBATTLEMATCH_IRC_CreateWindow 0x0217DEDC thumb ov176
 *   LIVEBATTLEMATCH_IRC_PollWindowResult 0x0217DFBC thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeleteWindow 0x0217DFA8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   LIVEBATTLEMATCH_SAVE_GetFromSave 0x0200E9F4 thumb
 *   LIVEBATTLEMATCH_SAVE_GetStats 0x0200EA00 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   WIFIBATTLEMATCH_VIEW_CreateStatusWindow 0x021E5D68 thumb ov177
 *   LIVEBATTLEMATCH_SAVE_GetRecord 0x0200EA08 thumb
 *   WIFIBATTLEMATCH_VIEW_DeleteStatusWindow 0x021E5EF8 thumb ov177
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "livebattlematch_shared_types.h"

struct GameData;
struct RegulationCard;
struct RegulationParty;
struct BattleCompetitionSave;
struct Reg;
struct MyStatus;
struct Rec0200E6FC;
struct MsgBank;
struct DigitalcardcheckRec;
struct WordSet;
struct RegulationCard;
struct Obj;
#include "../types.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define WORDSET_Create WORDSET_Create_header
#endif
#include "../arm9/wordset.h"
#ifdef __MWERKS__
#undef WORDSET_Create
extern struct WordSet * WORDSET_Create(int, int, int);
#endif

typedef struct { u8 image[0x94]; u32 f94, f98; int f9c; u16 fa0, fa2, fa4, fa6, fa8, faa; } DigitalcardcheckRecord;

typedef struct WifibattlematchViewWork Work;

typedef u16 Row[3];

typedef struct {
    u8 data[0x92]; u16 pad92;
    u32 color0, color1; u32 user;
    u16 count0, count1;
    union { u32 total; struct { u16 count2, ruleValue22; } h; } v;
    u16 cardValueDate, cardValueStatus;
} DigitalcardcheckRec;
struct WifibattlematchUtilWork;

#include "../ov177/wifibattlematch_util.h"
struct WifibattlematchCallback;
#include "livebattlematch_flow.h"
#include "../arm9/battle_box.h"
#include "../arm9/regulation.h"
struct GameData;
#include "../ov177/wifibattlematch_graphic.h"
#include "../arm9/mi_memory.h"
#include "../arm9/livebattlematch_savedata.h"
struct Regulation;
#include "../arm9/mystatus.h"
struct RegulationCard;
#include "../ov177/wifibattlematch_view.h"
struct BoxMonGroup;
struct Party;
#include "../arm9/poke_regulation.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/config.h"
#include "../arm9/os_ownerinfo.h"
#include "../arm9/greeting_savedata.h"
struct QuadRecord;
#include "../arm9/msgdata.h"
#include "livebattlematch_irc.h"
#include "../arm9/key.h"
struct BattleBoxSave;
typedef unsigned short StatRow;
#include "../arm9/bsubway_savedata.h"
#include "../arm9/bg_sys.h"
#include "../arm9/game_data.h"
#include "digitalcardcheck.h"
extern const char d_0217E61C[];

void DIGITALCARDCHECK_UpdateMenu(struct LiveBattleMatchWork *obj, int a, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage(obj->printSys, obj->menuValue, a, b);
}

int DIGITALCARDCHECK_GetMenuResult(struct LiveBattleMatchWork *p){return WIFIBATTLEMATCH_UTIL_GetBusy(p->printSys);}

void DIGITALCARDCHECK_End(struct LiveBattleMatchWork *p,int v){p->flowResult=v;WIFIBATTLEMATCH_UTIL_SetCallback(p->proc, LIVEBATTLEMATCH_FLOW_End);}

/*
 * extent: two zero alignment bytes at 0217D15E before existing 0217D160.
 * ABI: 0200AE14 is an empty void callee leaving its supplied pointer in r0; caller reads it.
 */
void DIGITALCARDCHECK_CreateRecord(struct LiveBattleMatchWork *p)
{
    DigitalcardcheckRecord rec;
    void *base;
    void *box;
    struct RegulationParty *aux;
    struct MyStatus *x;
    struct Unit *table;
    int a, b, c, d;
    if (p->record) return;
    base = GAME_DATA_GetSaveControl(p->save);
    BATTLE_BOX_GetFromSave((struct SaveControl *)base);
    box = REGULATION_NoOp(p->card);
    aux = REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base), 1);
    x = GAME_DATA_GetMyStatus(p->save);
    table = WIFIBATTLEMATCH_GRAPHIC_GetCamera(p->graphic);
    MI_CpuFill8(&rec, 0, 0xAC);
    rec.fa0 = LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock, 1);
    rec.fa2 = LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock, 2);
    rec.fa4 = LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock, 0);
    rec.fa6 = REGULATION_GetRuleValue(box, 0x16);
    rec.f9c = MYSTATUS_GetTrainerView(x);
    MI_CpuCopy8(REGULATION_Card_GetCupName(p->card), &rec, 0x92);
    a = REGULATION_Card_GetValue(p->card, 6);
    b = REGULATION_Card_GetValue(p->card, 5);
    c = REGULATION_Card_GetValue(p->card, 4);
    rec.f94 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    a = REGULATION_Card_GetValue(p->card, 9);
    b = REGULATION_Card_GetValue(p->card, 8);
    c = REGULATION_Card_GetValue(p->card, 7);
    rec.f98 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    rec.fa8 = REGULATION_Card_GetValue(p->card, 11);
    p->record = WIFIBATTLEMATCH_VIEW_CreateDateWindow((char *)(&rec), x, table, p->view, p->font, p->printQue, p->mgr, p->arg2C, aux, 0, p->heap);
}

void DIGITALCARDCHECK_WaitRecord(struct LiveBattleMatchWork *p)
{
    DIGITALCARDCHECK_CreateRecord(p);
    while (DIGITALCARDCHECK_IsRecordDone(p) == 0)
        ;
}

void DIGITALCARDCHECK_DeleteRecord(struct LiveBattleMatchWork *p)
{
    if (p->record) {
        WIFIBATTLEMATCH_VIEW_DeleteDateWindow(p->record);
        p->record = 0;
    }
}

int DIGITALCARDCHECK_IsRecordDone(struct LiveBattleMatchWork *p) {return WIFIBATTLEMATCH_VIEW_StepMainWindow(p->record);}

/*
 * extent: 12-byte tail stub before labelled 0217D1A0.
 */
int DIGITALCARDCHECK_IsWorkDone(struct LiveBattleMatchWork *p)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(p->record);
}

/*
 * calls: 021E62CC own source has five inputs, but this caller visibly
 *   stores the sixth at 0217D1B6; retain the zero-extended halfword payload.
 */
void DIGITALCARDCHECK_SetRecordMode(struct LiveBattleMatchWork *p,int mode) {WIFIBATTLEMATCH_VIEW_DrawDateWindow(p->record,mode,p->mgr,p->printQue,p->font,p->heap);}

/*
 * extent: two bytes of zero alignment padding follow.
 */
void DIGITALCARDCHECK_CreateRecord2(struct LiveBattleMatchWork *p, const WifiBattleMatchViewRecord *value)
{
    struct Unit *a;
    int b;
    if (p->record2 == 0) {
        a = WIFIBATTLEMATCH_GRAPHIC_GetCamera(p->graphic);
        b = REGULATION_Card_GetValue(p->card, 11);
        p->record2 = WIFIBATTLEMATCH_VIEW_CreateRecordWindow(value, a, p->view, p->font,
            p->printQue, p->mgr, p->arg2C, 1, 0, b, p->heap);
    }
}

void DIGITALCARDCHECK_DeleteRecord2(struct LiveBattleMatchWork *p) {if(p->record2) {WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(p->record2);p->record2=0;}}

int DIGITALCARDCHECK_IsRecord2Done(struct LiveBattleMatchWork *p){return WIFIBATTLEMATCH_VIEW_StepRecordWindow(p->record2);}

void DIGITALCARDCHECK_CreateRecord3(struct LiveBattleMatchWork *p)
{
    struct Unit *a;
    if (p->record3 == 0) {
        a = WIFIBATTLEMATCH_GRAPHIC_GetCamera(p->graphic);
        p->record3 = WIFIBATTLEMATCH_VIEW_CreatePartyWindow(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(p->save)), a,
            p->view, p->partyFont, p->printQue, p->mgr, p->heap);
    }
}

void DIGITALCARDCHECK_DeleteRecord3(struct LiveBattleMatchWork *p) {if(p->record3) {WIFIBATTLEMATCH_VIEW_DeletePartyWindow(p->record3);p->record3=0;}}

int DIGITALCARDCHECK_IsRecord3DoneA(struct LiveBattleMatchWork *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindow(p->record3);}

int DIGITALCARDCHECK_IsRecord3DoneB(struct LiveBattleMatchWork *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(p->record3);}

void DIGITALCARDCHECK_CopyRegulation(struct LiveBattleMatchWork *p,const void *q) {struct Party *v;v=BATTLE_BOX_CreateParty((struct BoxMonGroup *)(BATTLE_BOX_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->save)))),p->heap);MI_CpuCopy8(v,(void *)q,POKE_REGULATION_GetDataSize());GFL_HEAP_Free(v);}

/*
 *           have no witness outside this range. Both are unlabelled Thumb
 *           leaf code in arm9 that disasm.py emitted as `.word` runs
 *           (0200BAC8 is inside a `0x21314B01` word block, 0201A918 inside a
 *           `0x47704800` word block), so they are neither `label` nor
 *           `sole-ref/code` (not a traced func_ start) and no SDK symbol
 *           exists. Nothing to cut: both call sites are inside this function.
 */
void DIGITALCARDCHECK_BuildBattleRecord(struct BattleRecord *p, struct LiveBattleMatchWork *q)
{
    struct GameData *r = q->save;
    struct MyStatus *x;
    struct Party *a;

    p->version = 0x64;
    x = GAME_DATA_GetMyStatus(r);
    MI_CpuCopy8(x, p, MYSTATUS_GetSize());
    OS_GetMacAddress(p->data + 0x20);
    GREETING_SAVEDATA_GetSentence((struct QuadRecord *)(GREETING_SAVEDATA_GetFromSaveThunk(GAME_DATA_GetSaveControl(r))), 0, (struct QuadRecord *)(p->pad_34 + 4));
    a = BATTLE_BOX_CreateParty((struct BoxMonGroup *)(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(r))), 0x8056);
    MI_CpuCopy8(a, p->pokeData, POKE_REGULATION_GetDataSize());
    GFL_HEAP_Free(a);
    p->stat1 = LIVEBATTLEMATCH_SAVE_GetCounter(q->saveBlock, 1);
    p->stat2 = LIVEBATTLEMATCH_SAVE_GetCounter(q->saveBlock, 2);
    p->stat0 = LIVEBATTLEMATCH_SAVE_GetCounter(q->saveBlock, 0);
    p->cardValue = REGULATION_Card_GetValue(q->card, 2);
}

void DIGITALCARDCHECK_SetBattleRecordValue(struct BattleRecord *p, struct LiveBattleMatchWork *q)
{
    p->cardValue = REGULATION_Card_GetValue(q->card, 2);
}

LivebattlematchRequest *DIGITALCARDCHECK_Create(RequestConfig *p, int heap)
{
    LivebattlematchRequest *r;
    r = GFL_HEAP_Alloc(heap, sizeof(*r), 0, d_0217E61C, 0x9A);
    MI_CpuFill8(r, 0, sizeof(*r));
    r->config = *p;
    r->heap = heap;
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(r->config.view, 3, heap);
    r->msgBank = MSGDATA_CreateFromArchive(0, 2, 0xD2, heap);
    r->wordSet = WORDSET_Create(8, 0x40, heap);
    r->callback = WIFIBATTLEMATCH_UTIL_CreateCallback(r, DIGITALCARDCHECK_SelectPhase, heap);
    return r;
}

void DIGITALCARDCHECK_Delete(LivebattlematchRequest *p) {WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p->callback);DIGITALCARDCHECK_DeleteInitRecord(p);WORDSET_Delete((struct WordSet *)p->wordSet);MSGDATA_Delete((struct MsgBank *)p->msgBank);GFL_HEAP_Free(p);}

/*
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void DIGITALCARDCHECK_DeleteAlt(LivebattlematchRequest *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback((struct WifibattlematchCallback *)(p->callback));
    if (p->record)
        WIFIBATTLEMATCH_VIEW_UpdatePokeList((WifibattlematchViewWork *)p->record, (struct PrintQueue *)p->config.printQue);
}

int DIGITALCARDCHECK_GetProcResult(LivebattlematchRequest *p) {return WIFIBATTLEMATCH_UTIL_IsCallbackNull(p->callback);}

void DIGITALCARDCHECK_SelectPhase(WifibattlematchCallback *a, int *unused, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    void *m;
    unsigned x;
    unsigned y;
    m = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->config.save)))), p->config.slot);
    x = REGULATION_Card_GetValue(m, 2);
    y = REGULATION_Card_GetValue(m, 10);
    if (x && y == 1) {
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase1);
        return;
    }
    if (x && y == 2) {
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase2);
        return;
    }
    if (x && y == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase3);
        return;
    }
    if (x && y == 4) {
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase4);
        return;
    }
    if (x && y == 5) {
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase5);
        return;
    }
    WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_Phase6);
}

void DIGITALCARDCHECK_Phase1(WifibattlematchCallback *a, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    int result;
    void *base, *record;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x67, 1);
        *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 4); break;
    case 4: LIVEBATTLEMATCH_IRC_CreateWindow(p, 2); *state = 5; break;
    case 5:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x71, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 7); break;
    case 7: LIVEBATTLEMATCH_IRC_CreateWindow(p, 0); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x72, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 10); break;
    case 10: LIVEBATTLEMATCH_IRC_CreateWindow(p, 0); *state = 11; break;
    case 11:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6B, 2); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p->config.save);
        record = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)base)), p->config.slot);
        base = BATTLE_BOX_GetFromSave(base);
        BATTLE_BOX_ClearLockFlags(base, p->config.slot == 0 ? 1 : 2);
        REGULATION_Card_SetValue(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart(((void *)p->config.save)); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p->config.save);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x73, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 17); break;
    case 17: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 18; break;
    case 18: WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_EndPhase); break;
    case 19: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) WIFIBATTLEMATCH_UTIL_CommitRequest(a); break;
    }
}

void DIGITALCARDCHECK_Phase2(WifibattlematchCallback *a, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    int result;
    void *base, *record;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 0); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x68, 1);
        *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 4); break;
    case 4: LIVEBATTLEMATCH_IRC_CreateWindow(p, 2); *state = 5; break;
    case 5:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x69, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 7); break;
    case 7: LIVEBATTLEMATCH_IRC_CreateWindow(p, 0); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x72, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 10); break;
    case 10: LIVEBATTLEMATCH_IRC_CreateWindow(p, 0); *state = 11; break;
    case 11:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6B, 2); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p->config.save);
        record = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)base)), p->config.slot);
        base = BATTLE_BOX_GetFromSave(base);
        BATTLE_BOX_ClearLockFlags(base, p->config.slot == 0 ? 1 : 2);
        REGULATION_Card_SetValue(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart(((void *)p->config.save)); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p->config.save);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6C, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 17); break;
    case 17: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 18; break;
    case 18: WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_EndPhase); break;
    case 19: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) WIFIBATTLEMATCH_UTIL_CommitRequest(a); break;
    }
}

void DIGITALCARDCHECK_Phase3(WifibattlematchCallback *a, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3: LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6D, 1); *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow(p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) {
            LIVEBATTLEMATCH_IRC_DeleteWindow(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_EndPhase); break;
    }
}

/*
 * DFF0 receives the context in r0 even though its forwarding body ignores it.
 */
void DIGITALCARDCHECK_Phase4(WifibattlematchCallback *sys, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6e, 1);
        *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow(p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 7; }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback(sys, DIGITALCARDCHECK_EndPhase); break;
    }
}

void DIGITALCARDCHECK_Phase5(WifibattlematchCallback *sys, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x70, 1);
        *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow(p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 7; }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback(sys, DIGITALCARDCHECK_EndPhase); break;
    }
}

void DIGITALCARDCHECK_Phase6(WifibattlematchCallback *a, int *state, void *pArg)
{
    LivebattlematchRequest *p = pArg;
    switch (*state) {
    case 0:
        LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6F, 1);
        *state = 1;
        break;
    case 1:
        if (LIVEBATTLEMATCH_IRC_GetMenuValue(p))
            *state = 2;
        break;
    case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback(a, DIGITALCARDCHECK_EndPhase);
        break;
    }
}

void DIGITALCARDCHECK_EndPhase(WifibattlematchCallback *a, int *unusedState, void *unusedWork) { WIFIBATTLEMATCH_UTIL_ClearCallback(a); }

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: LIVEBATTLEMATCH_SAVE_GetStats and LIVEBATTLEMATCH_SAVE_GetRecord (witness). Filed src/matched/arm9/LIVEBATTLEMATCH_SAVE_GetStats.c and LIVEBATTLEMATCH_SAVE_GetRecord.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; the integrator owns filing.
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetStats(unsigned char *p) { return p + 0x5a; }
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetRecord(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 */
void DIGITALCARDCHECK_InitRecord(LivebattlematchRequest *p)
{
    void *save, *stats;
    struct RegulationCard *base;
    struct RegulationCard *obj;
    struct RegulationParty *sub;
    struct Reg *reg;
    struct MyStatus *win;
    struct Unit *flag;
    if (p->record == 0) {
        save = GAME_DATA_GetSaveControl((struct GameData *)p->config.save);
        base = (struct RegulationCard *)BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl((struct GameData *)p->config.save)));
        obj = (struct RegulationCard *)REGULATION_GetCard(base, p->config.slot);
        sub = REGULATION_GetParty((struct BattleCompetitionSave *)base, p->config.slot);
        reg = (struct Reg *)REGULATION_NoOp(obj);
        stats = LIVEBATTLEMATCH_SAVE_GetFromSave(save);
        win = GAME_DATA_GetMyStatus(p->config.save);
        flag = WIFIBATTLEMATCH_GRAPHIC_GetCamera(p->config.graphic);
        if (p->config.slot == 0) {
            DigitalcardcheckRec rec;
            Row *table;
            int total, a, b, c, d;
            MI_CpuFill8((void *)&rec, 0, 0xac);
            MI_CpuCopy8((const void *)(REGULATION_Card_GetCupName((struct RegulationCard *)obj)), (void *)&rec, 0x92);
            table = LIVEBATTLEMATCH_SAVE_GetStats(stats);
            rec.count0 = BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)table, 10, 0);
            total = BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)table, 10, 1);
            rec.v.total = total + BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)table, 10, 2);
            rec.user = MYSTATUS_GetTrainerView(win);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 6); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 5); c = REGULATION_Card_GetValue((struct RegulationCard *)obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 9); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 8); d = REGULATION_Card_GetValue((struct RegulationCard *)obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.cardValueStatus = REGULATION_Card_GetValue((struct RegulationCard *)obj, 11);
            p->record = WIFIBATTLEMATCH_VIEW_CreateStatusWindow((char *)(&rec), 0, win, flag, p->config.view, p->config.font, p->config.printQue, p->msgBank, p->wordSet, sub, 1, p->heap);
        } else {
            DigitalcardcheckRec rec;
            const u8 *table;
            int a, b, c, d;
            MI_CpuFill8(&rec, 0, 0xac);
            MI_CpuCopy8(REGULATION_Card_GetCupName(obj), &rec, 0x92);
            table = LIVEBATTLEMATCH_SAVE_GetRecord(stats);
            rec.count0 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 1); rec.count1 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 2);
            rec.v.h.count2 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 0);
            rec.v.h.ruleValue22 = REGULATION_GetRuleValue((struct Regulation *)reg, 22);
            rec.user = MYSTATUS_GetTrainerView(win);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 6); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 5); c = REGULATION_Card_GetValue((struct RegulationCard *)obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 9); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 8); d = REGULATION_Card_GetValue((struct RegulationCard *)obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.cardValueDate = REGULATION_Card_GetValue((struct RegulationCard *)obj, 11);
            p->record = WIFIBATTLEMATCH_VIEW_CreateDateWindow((char *)(&rec), win, flag, p->config.view, p->config.font, p->config.printQue, p->msgBank, p->wordSet, sub, 1, p->heap);
        }
        LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 0);
    }
}

void DIGITALCARDCHECK_DeleteInitRecord(LivebattlematchRequest *p)
{
    if (p->record) {
        if (p->config.slot == 0)
            WIFIBATTLEMATCH_VIEW_DeleteStatusWindow((void *)p->record);
        else
            WIFIBATTLEMATCH_VIEW_DeleteDateWindow((void *)p->record);
        p->record = 0;
    }
    BG_SYS_ClearSlot(1);
    BG_SYS_PushTile(1);
}

int DIGITALCARDCHECK_IsInitRecordDone(LivebattlematchRequest *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindow((void *)p->record); }

int DIGITALCARDCHECK_IsInitWorkDone(LivebattlematchRequest *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle((Work *)p->record); }
