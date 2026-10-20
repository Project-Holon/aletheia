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
    u32 color0, color1; u8 *user;
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
extern u32 WORDSET_Delete(struct WordSet *p);
#include "livebattlematch_irc.h"
#include "../arm9/key.h"
struct BattleBoxSave;
typedef unsigned short StatRow;
#include "../arm9/bsubway_savedata.h"
#include "../arm9/bg_sys.h"
#include "../arm9/game_data.h"
void DIGITALCARDCHECK_UpdateMenu(void *obj, int a, int b);
int DIGITALCARDCHECK_GetMenuResult(u8 *p);
void DIGITALCARDCHECK_End(u8 *p,int v);
void DIGITALCARDCHECK_CreateRecord(u8 *p);
void DIGITALCARDCHECK_WaitRecord(int *p);
void DIGITALCARDCHECK_DeleteRecord(int *p);
int DIGITALCARDCHECK_IsRecordDone(u8 *p);
int DIGITALCARDCHECK_IsWorkDone(int *p);
void DIGITALCARDCHECK_SetRecordMode(u8 *p,int mode);
void DIGITALCARDCHECK_CreateRecord2(char *p, const WifiBattleMatchViewRecord *value);
void DIGITALCARDCHECK_DeleteRecord2(int *p);
int DIGITALCARDCHECK_IsRecord2Done(u8 *p);
void DIGITALCARDCHECK_CreateRecord3(char *p);
void DIGITALCARDCHECK_DeleteRecord3(u8 *p);
int DIGITALCARDCHECK_IsRecord3DoneA(u8 *p);
int DIGITALCARDCHECK_IsRecord3DoneB(u8 *p);
void DIGITALCARDCHECK_CopyRegulation(u8 *p,const void *q);
void DIGITALCARDCHECK_BuildBattleRecord(u8 *p, u8 *q);
void DIGITALCARDCHECK_SetBattleRecordValue(int *p, int *q);
LivebattlematchRequest *DIGITALCARDCHECK_Create(RequestConfig *p, int heap);
void DIGITALCARDCHECK_Delete(int *p);
void DIGITALCARDCHECK_DeleteAlt(int *p);
int DIGITALCARDCHECK_GetProcResult(int *p);
void DIGITALCARDCHECK_SelectPhase(int a, int unused, char *p);
void DIGITALCARDCHECK_Phase1(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase2(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase3(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase4(int sys, int *state, int *p);
void DIGITALCARDCHECK_Phase5(int sys, int *state, int *p);
void DIGITALCARDCHECK_Phase6(int a, int *state, int *p);
void DIGITALCARDCHECK_EndPhase(int a);
void DIGITALCARDCHECK_InitRecord(int *p);
void DIGITALCARDCHECK_DeleteInitRecord(int *p);
int DIGITALCARDCHECK_IsInitRecordDone(int *p);
int DIGITALCARDCHECK_IsInitWorkDone(int *p);
extern const char d_0217E61C[];

void DIGITALCARDCHECK_UpdateMenu(void *obj, int a, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((struct WifibattlematchUtilWork *)(((struct LiveBattleMatchWork *)obj)->printSys), (void *)(((struct LiveBattleMatchWork *)obj)->menuValue), a, b);
}

int DIGITALCARDCHECK_GetMenuResult(u8 *p){return WIFIBATTLEMATCH_UTIL_GetBusy((struct WifibattlematchUtilWork *)(*(int * *)&((struct LiveBattleMatchWork *)p)->printSys));}

void DIGITALCARDCHECK_End(u8 *p,int v){((struct LiveBattleMatchWork *)p)->flowResult=v;WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)(*(int * *)&((struct LiveBattleMatchWork *)p)->proc),(sptr)LIVEBATTLEMATCH_FLOW_End);}

/*
 * extent: two zero alignment bytes at 0217D15E before existing 0217D160.
 * ABI: 0200AE14 is an empty void callee leaving its supplied pointer in r0; caller reads it.
 */
void DIGITALCARDCHECK_CreateRecord(u8 *p)
{
    DigitalcardcheckRecord rec;
    void *base;
    sptr box, aux, x, table; int a, b, c, d;
    if (*(int *)&((struct LiveBattleMatchWork *)p)->record) return;
    base = GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save);
    BATTLE_BOX_GetFromSave((struct SaveControl *)base);
    box = (sptr)REGULATION_NoOp((void *)(((struct LiveBattleMatchWork *)p)->card));
    aux = (sptr)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base), 1);
    x = (sptr)GAME_DATA_GetMyStatus(((struct LiveBattleMatchWork *)p)->save);
    table = WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int * *)&((struct LiveBattleMatchWork *)p)->graphic);
    MI_CpuFill8(&rec, 0, 0xAC);
    rec.fa0 = LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock, 1);
    rec.fa2 = LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock, 2);
    rec.fa4 = LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock, 0);
    rec.fa6 = REGULATION_GetRuleValue((struct Regulation *)box, 0x16);
    rec.f9c = MYSTATUS_GetTrainerView((const struct MyStatus *)x);
    MI_CpuCopy8(REGULATION_Card_GetCupName(((struct LiveBattleMatchWork *)p)->card), &rec, 0x92);
    a = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 6);
    b = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 5);
    c = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 4);
    rec.f94 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    a = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 9);
    b = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 8);
    c = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 7);
    rec.f98 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    rec.fa8 = REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 11);
    *(int *)&((struct LiveBattleMatchWork *)p)->record = (sptr)WIFIBATTLEMATCH_VIEW_CreateDateWindow((char *)(&rec), (void *)x, (void *)table, (void *)(((struct LiveBattleMatchWork *)p)->view), ((struct LiveBattleMatchWork *)p)->font, (void *)(*(int *)&((struct LiveBattleMatchWork *)p)->printQue), (void *)(*(int *)&((struct LiveBattleMatchWork *)p)->mgr), (void *)(((struct LiveBattleMatchWork *)p)->arg2C), (void *)aux, 0, ((struct LiveBattleMatchWork *)p)->heap);
}

void DIGITALCARDCHECK_WaitRecord(int *p)
{
    DIGITALCARDCHECK_CreateRecord((u8 *)p);
    while (DIGITALCARDCHECK_IsRecordDone((u8 *)p) == 0)
        ;
}

void DIGITALCARDCHECK_DeleteRecord(int *p)
{
    if (((struct LiveBattleMatchWork *)p)->record) {
        WIFIBATTLEMATCH_VIEW_DeleteDateWindow((void *)(((struct LiveBattleMatchWork *)p)->record));
        ((struct LiveBattleMatchWork *)p)->record = 0;
    }
}

int DIGITALCARDCHECK_IsRecordDone(u8 *p) {return WIFIBATTLEMATCH_VIEW_StepMainWindow(((struct LiveBattleMatchWork *)p)->record);}

/*
 * extent: 12-byte tail stub before labelled 0217D1A0.
 */
int DIGITALCARDCHECK_IsWorkDone(int *p)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle((Work *)p[4]);
}

/*
 * calls: 021E62CC own source has five inputs, but this caller visibly
 *   stores the sixth at 0217D1B6; retain the zero-extended halfword payload.
 */
void DIGITALCARDCHECK_SetRecordMode(u8 *p,int mode) {WIFIBATTLEMATCH_VIEW_DrawDateWindow(*(char * *)&((struct LiveBattleMatchWork *)p)->record,mode,((struct LiveBattleMatchWork *)p)->mgr,((struct LiveBattleMatchWork *)p)->printQue,((struct LiveBattleMatchWork *)p)->font,((struct LiveBattleMatchWork *)p)->heap);}

/*
 * extent: two bytes of zero alignment padding follow.
 */
void DIGITALCARDCHECK_CreateRecord2(char *p, const WifiBattleMatchViewRecord *value)
{
    sptr a;
    int b;
    if (((struct LiveBattleMatchWork *)p)->record2 == 0) {
        a = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)(((struct LiveBattleMatchWork *)p)->graphic));
        b = REGULATION_Card_GetValue((struct RegulationCard *)(((struct LiveBattleMatchWork *)p)->card), 11);
        ((struct LiveBattleMatchWork *)p)->record2 = (void *)WIFIBATTLEMATCH_VIEW_CreateRecordWindow(value, (void *)a, ((struct LiveBattleMatchWork *)p)->view, (void *)((struct LiveBattleMatchWork *)p)->font,
            ((struct LiveBattleMatchWork *)p)->printQue, ((struct LiveBattleMatchWork *)p)->mgr, ((struct LiveBattleMatchWork *)p)->arg2C, 1, 0, b, ((struct LiveBattleMatchWork *)p)->heap);
    }
}

void DIGITALCARDCHECK_DeleteRecord2(int *p) {if(*(char * *)&((struct LiveBattleMatchWork *)p)->record2) {WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(*(char * *)&((struct LiveBattleMatchWork *)p)->record2);((struct LiveBattleMatchWork *)p)->record2=0;}}

int DIGITALCARDCHECK_IsRecord2Done(u8 *p){return WIFIBATTLEMATCH_VIEW_StepRecordWindow(((struct LiveBattleMatchWork *)p)->record2);}

void DIGITALCARDCHECK_CreateRecord3(char *p)
{
    sptr a;
    if (((struct LiveBattleMatchWork *)p)->record3 == 0) {
        a = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)(*(int *)&((struct LiveBattleMatchWork *)p)->graphic));
        ((struct LiveBattleMatchWork *)p)->record3 = (void *)WIFIBATTLEMATCH_VIEW_CreatePartyWindow(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((struct GameData *)(*(int *)&((struct LiveBattleMatchWork *)p)->save))), (void *)a,
            ((struct LiveBattleMatchWork *)p)->view, ((struct LiveBattleMatchWork *)p)->partyFont, ((struct LiveBattleMatchWork *)p)->printQue, ((struct LiveBattleMatchWork *)p)->mgr, ((struct LiveBattleMatchWork *)p)->heap);
    }
}

void DIGITALCARDCHECK_DeleteRecord3(u8 *p) {if(*(char * *)&((struct LiveBattleMatchWork *)p)->record3) {WIFIBATTLEMATCH_VIEW_DeletePartyWindow(*(char * *)&((struct LiveBattleMatchWork *)p)->record3);((struct LiveBattleMatchWork *)p)->record3=0;}}

int DIGITALCARDCHECK_IsRecord3DoneA(u8 *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindow(((struct LiveBattleMatchWork *)p)->record3);}

int DIGITALCARDCHECK_IsRecord3DoneB(u8 *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(((struct LiveBattleMatchWork *)p)->record3);}

void DIGITALCARDCHECK_CopyRegulation(u8 *p,const void *q) {void *v;v=BATTLE_BOX_CreateParty((struct BoxMonGroup *)(BATTLE_BOX_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save)))),((struct LiveBattleMatchWork *)p)->heap);MI_CpuCopy8((const void *)v,(void *)q,POKE_REGULATION_GetDataSize());GFL_HEAP_Free((void *)v);}

/*
 *           have no witness outside this range. Both are unlabelled Thumb
 *           leaf code in arm9 that disasm.py emitted as `.word` runs
 *           (0200BAC8 is inside a `0x21314B01` word block, 0201A918 inside a
 *           `0x47704800` word block), so they are neither `label` nor
 *           `sole-ref/code` (not a traced func_ start) and no SDK symbol
 *           exists. Nothing to cut: both call sites are inside this function.
 */
void DIGITALCARDCHECK_BuildBattleRecord(u8 *p, u8 *q)
{
    u8 *r = *(u8 * *)&((struct LiveBattleMatchWork *)q)->save;
    uptr x;
    uptr a;

    ((struct BattleRecord *)p)->version = 0x64;
    x = (uptr)GAME_DATA_GetMyStatus((struct GameData *)r);
    MI_CpuCopy8((const void *)((void *)x), (void *)p, MYSTATUS_GetSize());
    OS_GetMacAddress(p + 0x20);
    GREETING_SAVEDATA_GetSentence((struct QuadRecord *)(GREETING_SAVEDATA_GetFromSaveThunk((uptr)GAME_DATA_GetSaveControl((struct GameData *)r))), 0, (struct QuadRecord *)(p + 0x38));
    a = (uptr)BATTLE_BOX_CreateParty((struct BoxMonGroup *)(BATTLE_BOX_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl((struct GameData *)r)))), 0x8056);
    MI_CpuCopy8((void *)a, p + 0xd4, POKE_REGULATION_GetDataSize());
    GFL_HEAP_Free((void *)a);
    ((struct BattleRecord *)p)->stat1 = LIVEBATTLEMATCH_SAVE_GetCounter((const u8 *)(((struct LiveBattleMatchWork *)q)->saveBlock), 1);
    ((struct BattleRecord *)p)->stat2 = LIVEBATTLEMATCH_SAVE_GetCounter((const u8 *)(((struct LiveBattleMatchWork *)q)->saveBlock), 2);
    ((struct BattleRecord *)p)->stat0 = LIVEBATTLEMATCH_SAVE_GetCounter((const u8 *)(((struct LiveBattleMatchWork *)q)->saveBlock), 0);
    ((struct BattleRecord *)p)->cardValue = REGULATION_Card_GetValue((struct RegulationCard *)(((struct LiveBattleMatchWork *)q)->card), 2);
}

void DIGITALCARDCHECK_SetBattleRecordValue(int *p, int *q)
{
    ((struct BattleRecord *)p)->cardValue = REGULATION_Card_GetValue((struct RegulationCard *)(((struct LiveBattleMatchWork *)q)->card), 2);
}

LivebattlematchRequest *DIGITALCARDCHECK_Create(RequestConfig *p, int heap)
{
    LivebattlematchRequest *r;
    r = GFL_HEAP_Alloc(heap, 0x38, 0, d_0217E61C, 0x9A);
    MI_CpuFill8(r, 0, 0x38);
    r->config = *p;
    r->heap = heap;
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(r->config.view, 3, heap);
    r->msgBank = (void *)MSGDATA_CreateFromArchive(0, 2, 0xD2, heap);
    r->wordSet = (void *)WORDSET_Create(8, 0x40, heap);
    r->callback = (sptr)WIFIBATTLEMATCH_UTIL_CreateCallback((sptr)r, (sptr)DIGITALCARDCHECK_SelectPhase, heap);
    return r;
}

void DIGITALCARDCHECK_Delete(int *p) {WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p[4]);DIGITALCARDCHECK_DeleteInitRecord(p);WORDSET_Delete((struct WordSet *)p[1]);MSGDATA_Delete((struct MsgBank *)p[0]);GFL_HEAP_Free(p);}

/*
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void DIGITALCARDCHECK_DeleteAlt(int *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback((struct WifibattlematchCallback *)(((LivebattlematchRequest *)p)->callback));
    if (((LivebattlematchRequest *)p)->record)
        WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)((LivebattlematchRequest *)p)->record, (void *)((LivebattlematchRequest *)p)->config.mgr);
}

int DIGITALCARDCHECK_GetProcResult(int *p) {return WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)p[4]);}

void DIGITALCARDCHECK_SelectPhase(int a, int unused, char *p)
{
    void *m;
    unsigned x;
    unsigned y;
    m = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(((LivebattlematchRequest *)p)->config.save)))), ((LivebattlematchRequest *)p)->config.slot);
    x = REGULATION_Card_GetValue(m, 2);
    y = REGULATION_Card_GetValue(m, 10);
    if (x && y == 1) {
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase1);
        return;
    }
    if (x && y == 2) {
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase2);
        return;
    }
    if (x && y == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase3);
        return;
    }
    if (x && y == 4) {
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase4);
        return;
    }
    if (x && y == 5) {
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase5);
        return;
    }
    WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_Phase6);
}

void DIGITALCARDCHECK_Phase1(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x67, 1);
        *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 4); break;
    case 4: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 2); *state = 5; break;
    case 5:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x71, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 7); break;
    case 7: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x72, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 10); break;
    case 10: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 11; break;
    case 11:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6B, 2); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)base)), p[5]);
        base = BATTLE_BOX_GetFromSave(base);
        BATTLE_BOX_ClearLockFlags(base, p[5] == 0 ? 1 : 2);
        REGULATION_Card_SetValue(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart(((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x73, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 17); break;
    case 17: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 18; break;
    case 18: WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_EndPhase); break;
    case 19: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) WIFIBATTLEMATCH_UTIL_CommitRequest((uptr)a); break;
    }
}

void DIGITALCARDCHECK_Phase2(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 0); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x68, 1);
        *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 4); break;
    case 4: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 2); *state = 5; break;
    case 5:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x69, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 7); break;
    case 7: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x72, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 10); break;
    case 10: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 11; break;
    case 11:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6B, 2); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)base)), p[5]);
        base = BATTLE_BOX_GetFromSave(base);
        BATTLE_BOX_ClearLockFlags(base, p[5] == 0 ? 1 : 2);
        REGULATION_Card_SetValue(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart(((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6C, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest(a, 17); break;
    case 17: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 18; break;
    case 18: WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_EndPhase); break;
    case 19: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) WIFIBATTLEMATCH_UTIL_CommitRequest((uptr)a); break;
    }
}

void DIGITALCARDCHECK_Phase3(int *a, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu((int *)p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3: LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6D, 1); *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) {
            LIVEBATTLEMATCH_IRC_DeleteWindow(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_EndPhase); break;
    }
}

/*
 * DFF0 receives the context in r0 even though its forwarding body ignores it.
 */
void DIGITALCARDCHECK_Phase4(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu((int *)p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6e, 1);
        *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 7; }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)sys, (sptr)DIGITALCARDCHECK_EndPhase); break;
    }
}

void DIGITALCARDCHECK_Phase5(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu((int *)p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x70, 1);
        *state = 4; break;
    case 4: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) *state = 5; break;
    case 5: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 1); *state = 6; break;
    case 6:
        result = LIVEBATTLEMATCH_IRC_PollWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 7; }
        break;
    case 7: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 8; break;
    case 8: WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)sys, (sptr)DIGITALCARDCHECK_EndPhase); break;
    }
}

void DIGITALCARDCHECK_Phase6(int a, int *state, int *p)
{
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
        WIFIBATTLEMATCH_UTIL_SetCallback((struct WifibattlematchCallback *)a, (sptr)DIGITALCARDCHECK_EndPhase);
        break;
    }
}

void DIGITALCARDCHECK_EndPhase(int a) { WIFIBATTLEMATCH_UTIL_ClearCallback((void *)a); }

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: LIVEBATTLEMATCH_SAVE_GetStats and LIVEBATTLEMATCH_SAVE_GetRecord (witness). Filed src/matched/arm9/LIVEBATTLEMATCH_SAVE_GetStats.c and LIVEBATTLEMATCH_SAVE_GetRecord.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; the integrator owns filing.
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetStats(unsigned char *p) { return p + 0x5a; }
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetRecord(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 */
void DIGITALCARDCHECK_InitRecord(int *p)
{
    void *save, *stats;
    struct RegulationCard *base;
    struct RegulationCard *obj;
    struct RegulationParty *sub;
    struct Reg *reg;
    u8 *win;
    sptr flag;
    if (p[2] == 0) {
        save = GAME_DATA_GetSaveControl((struct GameData *)p[12]);
        base = (struct RegulationCard *)BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl((struct GameData *)p[12])));
        obj = (struct RegulationCard *)REGULATION_GetCard(base, p[5]);
        sub = REGULATION_GetParty((struct BattleCompetitionSave *)base, p[5]);
        reg = (struct Reg *)REGULATION_NoOp(obj);
        stats = LIVEBATTLEMATCH_SAVE_GetFromSave(save);
        win = (unsigned char *)GAME_DATA_GetMyStatus((void *)p[12]);
        flag = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)p[11]);
        if (p[5] == 0) {
            DigitalcardcheckRec rec;
            Row *table;
            int total, a, b, c, d;
            MI_CpuFill8((void *)&rec, 0, 0xac);
            MI_CpuCopy8((const void *)(REGULATION_Card_GetCupName((struct RegulationCard *)obj)), (void *)&rec, 0x92);
            table = (u16 (*)[3])LIVEBATTLEMATCH_SAVE_GetStats((sptr)stats);
            rec.count0 = BSUBWAY_SAVEDATA_GetStat((StatRow *)table, 10, 0);
            total = BSUBWAY_SAVEDATA_GetStat((StatRow *)table, 10, 1);
            rec.v.total = total + BSUBWAY_SAVEDATA_GetStat((StatRow *)table, 10, 2);
            rec.user = (u8 *)MYSTATUS_GetTrainerView((const struct MyStatus *)win);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 6); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 5); c = REGULATION_Card_GetValue((struct RegulationCard *)obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 9); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 8); d = REGULATION_Card_GetValue((struct RegulationCard *)obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.cardValueStatus = REGULATION_Card_GetValue((struct RegulationCard *)obj, 11);
            p[2] = (sptr)WIFIBATTLEMATCH_VIEW_CreateStatusWindow((char *)(&rec), 0, win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        } else {
            DigitalcardcheckRec rec;
            const u8 *table;
            int a, b, c, d;
            MI_CpuFill8(&rec, 0, 0xac);
            MI_CpuCopy8(REGULATION_Card_GetCupName(obj), &rec, 0x92);
            table = (const u8 *)LIVEBATTLEMATCH_SAVE_GetRecord((sptr)stats);
            rec.count0 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 1); rec.count1 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 2);
            rec.v.h.count2 = LIVEBATTLEMATCH_SAVE_GetCounter(table, 0);
            rec.v.h.ruleValue22 = REGULATION_GetRuleValue((struct Regulation *)reg, 22);
            rec.user = (u8 *)MYSTATUS_GetTrainerView((const struct MyStatus *)win);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 6); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 5); c = REGULATION_Card_GetValue((struct RegulationCard *)obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue((struct RegulationCard *)obj, 9); b = REGULATION_Card_GetValue((struct RegulationCard *)obj, 8); d = REGULATION_Card_GetValue((struct RegulationCard *)obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.cardValueDate = REGULATION_Card_GetValue((struct RegulationCard *)obj, 11);
            p[2] = (sptr)WIFIBATTLEMATCH_VIEW_CreateDateWindow((char *)(&rec), win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        }
        LIVEBATTLEMATCH_IRC_ToggleSe((sptr)p, 0);
    }
}

void DIGITALCARDCHECK_DeleteInitRecord(int *p)
{
    if (p[2]) {
        if (p[5] == 0)
            WIFIBATTLEMATCH_VIEW_DeleteStatusWindow((void *)p[2]);
        else
            WIFIBATTLEMATCH_VIEW_DeleteDateWindow((void *)p[2]);
        p[2] = 0;
    }
    BG_SYS_ClearSlot(1);
    BG_SYS_PushTile(1);
}

int DIGITALCARDCHECK_IsInitRecordDone(int *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindow((void *)p[2]); }

int DIGITALCARDCHECK_IsInitWorkDone(int *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle((Work *)p[2]); }
