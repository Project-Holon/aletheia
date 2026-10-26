/*
 * file:     party_status.c
 * unit:     yes
 * function: PARTY_STATUS_Create, PARTY_STATUS_Destroy, PARTY_STATUS_Update, PARTY_STATUS_SetupDisplay, PARTY_STATUS_InitRecord, PARTY_STATUS_CreateSub, PARTY_STATUS_DestroySub, PARTY_STATUS_UpdateSub, PARTY_STATUS_Noop, PARTY_STATUS_NetSync, PARTY_STATUS_DestroySubWork, PARTY_STATUS_CreateSubWork, PARTY_STATUS_NetSync2, PARTY_STATUS_ExitSubWork
 * address:  0x021E5440
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Release the handle at *p, then tear down channel ov176_id.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov090_id 0x0000005A data
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   ov091_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PLIST_COMM_Update 0x021B6114 thumb ov090
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYSTEM_DATA_GetConfig 0x0200873C thumb
 *   PLIST_COMM_Start 0x021B6100 thumb ov090
 *   ov90_id 0x0000005A data a1
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   ZUKAN_SAVE_GetFromGameData   0x0200CA1C  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled   0x0200CA38  thumb
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov175_id 0x000000AF data a1
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   WIFIBATTLEMATCH_NET_CreateNetContext 0x021D9DC8 thumb ov175
 *   WIFIBATTLEMATCH_NET_SendRegDataAlt 0x021DC200 thumb ov175
 *   WIFIBATTLEMATCH_NET_TakeRegBuffer 0x021DC240 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteNetContext 0x021D9EA0 thumb ov175
 *   LIVEBATTLEMATCH_IRC_Create  0x0217E00C  thumb  ov176
 *   ov176_id       0x000000B0  data
 *   LIVEBATTLEMATCH_IRC_SendSaveData 0x0217E258 thumb ov176
 *   LIVEBATTLEMATCH_IRC_RecvSaveData 0x0217E298 thumb ov176
 *   LIVEBATTLEMATCH_IRC_NoOp 0x0217E074 thumb ov176
 *   LIVEBATTLEMATCH_IRC_Delete   0x0217E058  thumb
 */

typedef struct PartyStatusObj2 {
    void *party;
    void *config;
    void *gameData;
    signed char ppt;
    signed char mode;
    signed char max;
    signed char pos;
    signed char page;
    signed char retMovePos;
    signed char retSel;
    unsigned char pad13[1];
    short newMove;
    unsigned char pad16[2];
    int isNationalDex;
    unsigned char pad1C[4];
    int canUseButtons;
    int forceExit;
} PartyStatusObj2;

typedef struct PartyStatusObj4 {
    unsigned char pad0[32];
    unsigned int exitReason;
} PartyStatusObj4;

typedef struct PartyStatusObj5 {
    unsigned char pad0[4];
    void *party;
    unsigned char pad8[24];
    unsigned int exitReason;
} PartyStatusObj5;

typedef struct PartyStatusObj6 {
    unsigned char pad0[4];
    void *party;
    unsigned char pad8[20];
    void *resultParty;
} PartyStatusObj6;

struct GameData;
struct WifiBattleMatchReportBlock;
struct WifiBattleMatchNetCtx;
struct LiveBattleMatchIrcWork;

/* Argument block of the net sub process (PARTY_STATUS_CreateSub and its siblings). */
typedef struct PartyStatusNetArgs {
    struct GameData **gameData;                     /* 0x00 */
    unsigned mode;                                    /* 0x04: 0 net context exchange, 1 save data exchange */
    unsigned result;                                   /* 0x08: exit reason written back */
    void *sendData;                                 /* 0x0C */
    void *recvData;                                 /* 0x10 */
    struct WifiBattleMatchReportBlock *reportBlock; /* 0x14 */
} PartyStatusNetArgs;

struct Proc;
struct Party;
struct PartyMon;
struct ProcSys;
struct Proc;
struct Big;
struct Sub02008700Obj;
struct Blk37;
struct Entry;
struct Link;

typedef struct {unsigned words[9];} Copy;

#include "../types.h"

typedef struct PartyStatusArgs { u8 *regulation; void *party; u32 opponentName; u8 opponentGender, padD[3]; u32 opponentParty; void *gameData; u8 tail[20]; } PartyStatusArgs;

typedef struct { u8 pad[4]; void *party; } Other;

typedef struct {
    void *party;
    u32 bag, mailBox, config, f10;
    u8 *regulation;
    u8 pad18[24];
    u16 itemUseParam, pad32;
    u32 mode, f38, selectedIndex, exitCode;
    u16 itemId, moveId;
    u8 moveSlot, slotOrder[6], pad4F;
    u32 levelUpCursor;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 timeLeft;
    u8 pad62, closeRequested;
    u32 battleKind;
    u8 pad68[12];
    u32 opponentParty, opponentName;
    u8 opponentGender, pad7D[15];
    u32 timerShown, timerRunning;
} Output;

/* Work of the party status proc: the PartyList arguments, then the PokeStatus record. */
typedef struct PartyStatusWork {
    unsigned int state;                  /* 0x00 */
    void *party;                         /* 0x04 */
    Output output;                       /* 0x08 */
    unsigned char padOutput[(sizeof(void *) == 4) ? 4 : 1]; /* 0x9C, the DS Output ends at 0x9C */
    PartyStatusObj2 record;              /* 0xA0 */
    unsigned char tickAccum;             /* 0xC8 */
    unsigned char padC9[3];
    unsigned int lastTick;               /* 0xCC */
    void *procSys;                       /* 0xD0 */
    Copy args;                           /* 0xD4 */
    unsigned short heapId;               /* 0xF8 */
} PartyStatusWork;

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct PokemonParam;
#include "../arm9/pokeparty.h"
#include "../ov090/plist_comm.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/net.h"
struct GFLNetSession;
#include "../arm9/net_err.h"
#include "../ov009/dwc_rapcommon.h"
struct PartyListCommWork;
struct GameData;
struct SaveControl;
#include "../arm9/game_data.h"
#include "../arm9/system_data.h"
struct MyStatus;
#include "../arm9/zukan_save.h"
struct ZukanSave;
struct GFLNetHandle;
#include "../arm9/net_handle.h"
#include "../ov175/wifibattlematch_net.h"
#include "../ov176/livebattlematch_irc.h"
int PARTY_STATUS_Create(void *handle,int unused,PartyStatusObj5 *q);
int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusWork *p);
int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,PartyStatusWork *p);
void PARTY_STATUS_SetupDisplay(PartyStatusArgs *p, Other *o, Output *out);
void PARTY_STATUS_InitRecord(PartyStatusArgs *r5, PartyStatusWork *r6, PartyStatusObj2 *r4);
int PARTY_STATUS_CreateSub(struct Proc *a, int b, PartyStatusNetArgs *p);
int PARTY_STATUS_DestroySub(void *a, u32 b, PartyStatusNetArgs *c, void *d);
int PARTY_STATUS_UpdateSub(u32 a, u32 *b, PartyStatusNetArgs *c, void *d);
void PARTY_STATUS_Noop(void *work, PartyStatusNetArgs *param, int heapId);
int PARTY_STATUS_NetSync(struct WifiBattleMatchNetCtx **out,PartyStatusNetArgs *ctx,u32 *state);
void PARTY_STATUS_DestroySubWork(struct WifiBattleMatchNetCtx **pp, PartyStatusNetArgs *c);
void PARTY_STATUS_CreateSubWork(struct LiveBattleMatchIrcWork **out, PartyStatusNetArgs *pp, u16 v);
unsigned PARTY_STATUS_NetSync2(struct LiveBattleMatchIrcWork **d,PartyStatusNetArgs *c,unsigned *state);
void PARTY_STATUS_ExitSubWork(struct LiveBattleMatchIrcWork **p, PartyStatusNetArgs *c);
extern unsigned d_02FFFC3C;
extern unsigned ov090_id[];
extern u8 ov091_id[],ov131_id[],gPartyListProcData[],gPokeStatusProcData[];
extern const char ov90_id[];
extern unsigned char ov067_id[],ov114_id[],ov175_id[];
extern u8 ov114_id[];
extern u8 ov067_id[];
extern u8 ov176_id[];

int PARTY_STATUS_Create(void *handle,int unused,PartyStatusObj5 *q)
{
 PartyStatusWork *p;
 GFL_HEAP_CreateChildHeap(1,0x58,0x30000);
 p=(PartyStatusWork *) PROCSYS_AllocProcWork(handle,sizeof(*p),0x58);
 MI_CpuFill8(p,0,sizeof(*p));
 p->args=*(Copy *)q;
 p->heapId=0x58;
 p->procSys=PROCSYS_Create(p->heapId);
 p->party=q->party;
 PARTY_STATUS_SetupDisplay((PartyStatusArgs *)q, (Other *)p, &p->output);PARTY_STATUS_InitRecord((PartyStatusArgs *)q,p,&p->record);
 p->tickAccum=0;
 p->lastTick=d_02FFFC3C;
 p->state=0;q->exitReason=0;
 return 1;
}

int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusWork *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=p->output.slotOrder[i];
 if(n!=0)POKEPARTY_Add(q->resultParty,POKEPARTY_GetMember(q->party,n-1));
 }
 PLIST_COMM_End((struct PartyListCommWork *)&p->output);GF_OVERLAY_Unload((uptr)ov090_id);
 PROCSYS_Delete(p->procSys);PROCSYS_FreeProcWork(handle);GFL_HEAP_DeleteChecked(0x58);
 return 1;
}

int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,PartyStatusWork *p)
{
    if(p->output.timerRunning==1 && p->output.timeLeft!=0) {
        u32 now;
        now=d_02FFFC3C;
        p->tickAccum+=(u8)(now-p->lastTick);
        p->lastTick=now;
        if(p->tickAccum>60) {
            --p->output.timeLeft;
            p->tickAccum-=60;
        }
    }
    if(GFL_NET_GetRunState()) {
        if(*((u8 *)GFL_NET_GetInitParam()+0x65)==3) {
            if(GFL_NET_ERR_GetErrorLevel()) {
                GFL_NET_ERR_RequestScreen();
                q->exitReason=2;
                p->output.closeRequested=1;p->record.forceExit=1;
            }
        } else {
            int one;
            one=1;
            switch(DWC_RAPCOMMON_HandleNetError((int)1,(int)1)) {
            case 0:case 3:break;
            case 4:q->exitReason=3;p->output.closeRequested=one;p->record.forceExit=one;break;
            case 1:case 2:default:q->exitReason=1;p->output.closeRequested=1;p->record.forceExit=1;break;
            }
        }
    }
    switch(p->state) {
    case 0:GF_OVERLAY_Load((sptr)ov091_id);
        PROCSYS_Push(p->procSys,-1,(const struct ProcData *)gPartyListProcData,&p->output);p->state=1;break;
    case 1:if(PROCSYS_Main(p->procSys)==0)p->state=2;break;
    case 2:GF_OVERLAY_Unload((sptr)ov091_id);
        if(p->output.exitCode==1) {p->record.pos=p->output.selectedIndex;p->state=3;}
        else return 1;
        break;
    case 3:GF_OVERLAY_Load((sptr)ov131_id);
        PROCSYS_Push(p->procSys,-1,(const struct ProcData *)gPokeStatusProcData,&p->record);p->state=4;break;
    case 4:
        if(p->output.timerRunning==1 && p->output.timeLeft==0)p->record.forceExit=1;
        if(PROCSYS_Main(p->procSys)==0)p->state=5;break;
    case 5:GF_OVERLAY_Unload((sptr)ov131_id);
        if(p->output.closeRequested==0) {p->output.selectedIndex=(u8)p->record.pos;p->state=0;}
        else return 1;
        break;
    }
    if(p->output.closeRequested==0) {
        PLIST_COMM_Update((struct PartyListCommWork *)&p->output);
    }
    return 0;
}

/*
 *  * note 2026-10-05 (wave P12 A7): DIFF 12/236 B, one residue: src and the record pointer
 * swap callee-saved registers (original src r6, record r5; build src r5, record r6).
 * Twin: ov134 021DCB48 (same typed Args/Output shape, matched; there src r5, record r6 is correct).
 * Tried, all 12 B: twin struct shape, int* params, typed record struct, const params (28 B),
 * b-before-a (18 B), save in local, declaration orders of a/b/i, block-local i, and each of
 * opt_lifetimes/opt_common_subs/opt_dead_assignments/scheduling/peephole off (12 B),
 * opt_propagation off (113 B). Callee returns: 02012EBC void*, 0200873C pointer, 02034AC4 int.
 * Difference to the twin: here the second parameter stays live across the first call.
 * final push 2026-10-05 G4L3: still DIFF 12/236 B (same swap), 40 compiles, 3 rounds. New tries, all 12 B:
 * initializer decl for a, raw offsets for p, restrict out, party/mode/save locals, a via
 * inline getter or AView struct view, p copy local (arg, block-scope, q), whole body or tail in a
 * static inline, o as Args or const, u8* p with struct casts, a as u32 or const u8*, callee decls
 * u32 (02012EBC/0200873C), do-while marks loop, default: break, -lang c, opt_strength_reduction,
 * opt_loop_invariants, opt_unroll_loops off. Dead ends: no local a (78 B), b-before-a (18 B), int i (111 B).
 * Finding: moving the three p reads (f10,f8,fC) before the switch (p dies earlier) gives the original
 * colours (p r6, a r5) but changes the code (125 B), so the swap is p's live range / degree against
 * the colouring threshold, not source order of p and a. mwcc Coloring.c (inspiredrobot/mwcc): nodes of
 * degree >= K are chosen by spill_cost/degree and p wins the lower register here. The original p
 * has the same live range in the listing, so the lever must change cost or degree without code.
 * pass 2 2026-10-06 P2L25: EXACT. The p/a colour swap was the source order of the stores after the
 * second call: out->f10 then out->a before out->f34 and out->f30 (code order is unchanged; the earlier
 * pcode position of the a store gives a the higher spill score, so a takes r5 and p r6).
 */
void PARTY_STATUS_SetupDisplay(PartyStatusArgs *p, Other *o, Output *out)
{
    u8 *regulation;
    void *saveControl;
    u8 i;
    regulation = p->regulation;
    saveControl = GAME_DATA_GetSaveControl(p->gameData);
    out->party = o->party;
    out->bag = 0;
    out->mailBox = 0;
    out->config = (uptr)SYSTEM_DATA_GetConfig(saveControl);
    out->f10 = 0;
    out->regulation = regulation;
    out->mode = 26;
    out->itemUseParam = 0;
    switch (regulation[0xba]) {
    case 0: out->f38 = 0; out->battleKind = 1; break;
    case 1: out->f38 = 1; out->battleKind = 1; break;
    case 2: out->f38 = 1; out->battleKind = 1; break;
    case 3: out->f38 = 1; out->battleKind = 1; break;
    case 4: out->f38 = 2; out->battleKind = 2; break;
    }
    out->itemId = 0;
    out->moveId = 0;
    out->moveSlot = 0;
    out->selectedIndex = 0;
    out->exitCode = 0;
    for (i = 0; i < 6; i++) out->slotOrder[i] = 0;
    out->levelUpCursor = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->opponentParty = p->opponentParty;
    out->opponentName = p->opponentName;
    out->opponentGender = p->opponentGender;
    out->timerShown = regulation[184];
    if (regulation[185] != 0) {
        out->timerRunning = 1;
        out->timeLeft = regulation[185];
    } else {
        out->timerRunning = 0;
        out->timeLeft = 0;
    }
    GF_OVERLAY_Load((sptr)ov90_id);
    PLIST_COMM_Start((struct PartyListCommWork *)out);
}

/*
 * Populate the 0x28-byte record from the two source objects.
 */
void PARTY_STATUS_InitRecord(PartyStatusArgs *args, PartyStatusWork *work, PartyStatusObj2 *record)
{
    void *saveControl;
    void *zukanSave;
    saveControl = GAME_DATA_GetSaveControl(args->gameData);
    GAME_DATA_GetMyStatus(args->gameData);
    zukanSave = ZUKAN_SAVE_GetFromGameData(args->gameData);
    record->party = work->party;
    record->gameData = args->gameData;
    record->config = SYSTEM_DATA_GetConfig(saveControl);
    record->ppt = 1;
    record->mode = 1;
    record->max = POKEPARTY_GetCount(work->party);
    record->pos = 0;
    record->page = 0;
    record->retMovePos = 0;
    record->retSel = 0;
    record->newMove = 0;
    record->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled(zukanSave);
    record->canUseButtons = 0;
    record->forceExit = 0;
}

/*
 * Allocate the 0x58-byte subobject and dispatch on track[1].
 */
int PARTY_STATUS_CreateSub(struct Proc *proc, int unused, PartyStatusNetArgs *param)
{
    void *work;
    GFL_HEAP_CreateChildHeap(1, 0x58, 0x10000);
    work = PROCSYS_AllocProcWork(proc, 4, 0x58);
    MI_CpuFill8(work, 0, 4);
    param->result = 0;
    switch (param->mode) {
    case 0:
        PARTY_STATUS_Noop(work, param, 0x58);
        break;
    case 1:
        PARTY_STATUS_CreateSubWork(work, param, 0x58);
        break;
    }
    return 1;
}

int PARTY_STATUS_DestroySub(void *proc, u32 unused, PartyStatusNetArgs *param, void *work)
{
    switch (param->mode) {
    case 0:
        PARTY_STATUS_DestroySubWork(work, param);
        break;
    case 1:
        PARTY_STATUS_ExitSubWork(work, param);
        break;
    }
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x58);
    return 1;
}

int PARTY_STATUS_UpdateSub(u32 unused, u32 *state, PartyStatusNetArgs *param, void *work)
{
    u32 r;

    switch (param->mode) {
    case 0:
        r = PARTY_STATUS_NetSync(work, param, state);
        break;
    case 1:
        r = PARTY_STATUS_NetSync2(work, param, state);
        break;
    }
    return r != 0;
}

/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void PARTY_STATUS_Noop(void *work, PartyStatusNetArgs *param, int heapId) {}

int PARTY_STATUS_NetSync(struct WifiBattleMatchNetCtx **out,PartyStatusNetArgs *ctx,u32 *state)
{
    if(GFL_NET_GetRunState()) {
        switch(DWC_RAPCOMMON_HandleNetError((int)1,(int)1)) {
        case 0:break;
        case 1:case 4:ctx->result=3;return 1;
        case 2:case 3:default:ctx->result=1;return 1;
        }
    }
    switch(*state) {
    case 0:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),16,36);++*state;break;
    case 1:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),16,36))++*state;break;
    case 2:GF_OVERLAY_Load((sptr)ov067_id);GF_OVERLAY_Load((sptr)ov114_id);GF_OVERLAY_Load((sptr)ov175_id);
        *out=WIFIBATTLEMATCH_NET_CreateNetContext(ctx->reportBlock,*ctx->gameData,0,88);++*state;break;
    case 3:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),17,36);++*state;break;
    case 4:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),17,36))++*state;break;
    case 5:if(WIFIBATTLEMATCH_NET_SendRegDataAlt(*out,ctx->sendData))++*state;break;
    case 6:if(WIFIBATTLEMATCH_NET_TakeRegBuffer(*out,ctx->recvData))++*state;break;
    case 7:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,36);++*state;break;
    case 8:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,36))++*state;break;
    case 9:WIFIBATTLEMATCH_NET_DeleteNetContext(*out);*out=0;
        GF_OVERLAY_Unload((sptr)ov175_id);GF_OVERLAY_Unload((sptr)ov114_id);GF_OVERLAY_Unload((sptr)ov067_id);++*state;break;
    case 10:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),19,36);++*state;break;
    case 11:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),19,36))return 1;break;
    }
    return 0;
}

void PARTY_STATUS_DestroySubWork(struct WifiBattleMatchNetCtx **work, PartyStatusNetArgs *param)
{
    if (*work == 0)
        return;
    WIFIBATTLEMATCH_NET_DeleteNetContext(*work);
    GF_OVERLAY_Unload((uptr)ov175_id);
    GF_OVERLAY_Unload((uptr)ov114_id);
    GF_OVERLAY_Unload((uptr)ov067_id);
}

void PARTY_STATUS_CreateSubWork(struct LiveBattleMatchIrcWork **work, PartyStatusNetArgs *param, u16 heapId)
{
    GF_OVERLAY_Load((uptr)ov176_id);
    *work = LIVEBATTLEMATCH_IRC_Create(*param->gameData, heapId);
}

unsigned PARTY_STATUS_NetSync2(struct LiveBattleMatchIrcWork **netWork,PartyStatusNetArgs *ctx,unsigned *state)
{
 if(GFL_NET_ERR_GetErrorLevel()!=0){GFL_NET_ERR_RequestScreen();ctx->result=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F);++*state;break;
 case 2:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F)!=0)++*state;break;
 case 3:if(LIVEBATTLEMATCH_IRC_SendSaveData(*netWork,ctx->sendData)!=0)++*state;break;
 case 4:if(LIVEBATTLEMATCH_IRC_RecvSaveData(*netWork,ctx->recvData)!=0)++*state;break;
 case 5:return 1;
 }
 LIVEBATTLEMATCH_IRC_NoOp(*netWork);return 0;
}

void PARTY_STATUS_ExitSubWork(struct LiveBattleMatchIrcWork **work, PartyStatusNetArgs *param)
{
    LIVEBATTLEMATCH_IRC_Delete(*work);
    GF_OVERLAY_Unload((sptr)ov176_id);
}
