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

typedef struct PartyStatusObj1 {
    unsigned int state;
    unsigned char pad4[64];
    unsigned int selectedIndex;
    unsigned int exitCode;
    unsigned char pad4C[28];
    unsigned short timeLeft;
    unsigned char pad6A[1];
    unsigned char closeRequested;
    unsigned char pad6C[44];
    unsigned int timerRunning;
    unsigned char pad9C[19];
    unsigned char savedPosition;
    unsigned char padB0[20];
    unsigned int forceExit;
    unsigned char tickAccum;
    unsigned char padC9[3];
    unsigned int lastTick;
    void *procSys;
} PartyStatusObj1;

typedef struct PartyStatusObj2 {
    int party;
    int config;
    int gameData;
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

typedef struct PartyStatusObj3 {
    unsigned int state;
    unsigned int party;
    unsigned char pad8[192];
    unsigned char tickAccum;
    unsigned char padC9[3];
    unsigned int lastTick;
    void *procSys;
    unsigned char padD4[36];
    unsigned short heapId;
} PartyStatusObj3;

typedef struct PartyStatusObj4 {
    unsigned char pad0[32];
    unsigned int exitReason;
} PartyStatusObj4;

typedef struct PartyStatusObj5 {
    unsigned char pad0[4];
    unsigned int party;
    unsigned char pad8[24];
    unsigned int exitReason;
} PartyStatusObj5;

typedef struct PartyStatusObj6 {
    unsigned char pad0[4];
    void *party;
    unsigned char pad8[20];
    void *resultParty;
} PartyStatusObj6;

typedef struct PartyStatusObj7 {
    void *f0;
} PartyStatusObj7;

struct Proc;
struct Party;
struct PartyMon;
struct S020314B8;
struct Proc;
struct Big;
struct Sub02008700Obj;
struct Blk37;
struct Entry;
struct Link;

typedef struct {unsigned words[9];} Copy;

typedef signed int     s32;


typedef unsigned char u8;

typedef unsigned short u16;


typedef unsigned int u32;

typedef struct { u8 *regulation; void *party; u32 opponentName; u8 opponentGender, padD[3]; u32 opponentParty; void *gameData; u8 tail[20]; } Args;

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
    u16 timeLeft, pad62;
    u32 battleKind;
    u8 pad68[12];
    u32 opponentParty, opponentName;
    u8 opponentGender, pad7D[15];
    u32 timerShown, timerRunning;
} Output;





extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern void *PROCSYS_Create(int heapId);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void PLIST_COMM_End(void *);
extern void GF_OVERLAY_Unload(s32 handle);
extern void PROCSYS_Delete(struct S020314B8 *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned);
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int DWC_RAPCOMMON_HandleNetError(void *,void *);
extern int GF_OVERLAY_Load(int);
extern void PROCSYS_Push(void *,u32,void *,void *);
extern u32 PROCSYS_Main(void *);
extern void PLIST_COMM_Update(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys);
extern void PLIST_COMM_Start(u8 *);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern unsigned int POKEPARTY_GetCount(void *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern char *WIFIBATTLEMATCH_NET_CreateNetContext(u32,void *,u32,u16);
extern u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(char *,u32),WIFIBATTLEMATCH_NET_TakeRegBuffer(char *,u32);
extern void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *p);
extern void *LIVEBATTLEMATCH_IRC_Create(int unused, int heap);
extern int LIVEBATTLEMATCH_IRC_SendSaveData(int unused, int arg);
extern int LIVEBATTLEMATCH_IRC_RecvSaveData(u8 *p, const void *q);
extern void LIVEBATTLEMATCH_IRC_NoOp(void *);
extern void LIVEBATTLEMATCH_IRC_Delete(int);
int PARTY_STATUS_Create(void *handle,int unused,PartyStatusObj5 *q);
int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusObj1 *p);
int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,char *p);
void PARTY_STATUS_SetupDisplay(Args *p, Other *o, Output *out);
void PARTY_STATUS_InitRecord(int *r5, int *r6, PartyStatusObj2 *r4);
int PARTY_STATUS_CreateSub(struct Proc *a, int b, int *p);
int PARTY_STATUS_DestroySub(void *a, u32 b, u32 *c, void *d);
int PARTY_STATUS_UpdateSub(u32 a, u32 b, u32 *c, void *d);
void PARTY_STATUS_Noop(int work, int *param, int heapId);
int PARTY_STATUS_NetSync(char **out,u32 *ctx,u32 *state);
void PARTY_STATUS_DestroySubWork(void **pp, u32 *c);
void PARTY_STATUS_CreateSubWork(u32 *out, u32 **pp, u32 v);
unsigned PARTY_STATUS_NetSync2(void **d,unsigned *c,unsigned *state);
void PARTY_STATUS_ExitSubWork(int *p, void *c);
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
 PartyStatusObj3 *p;
 GFL_HEAP_CreateChildHeap(1,0x58,0x30000);
 p=(PartyStatusObj3 *) PROCSYS_AllocProcWork(handle,0xFC,0x58);
 MI_CpuFill8(p,0,0xFC);
 *(Copy *)((char *)p+0xD4)=*(Copy *)q;
 p->heapId=0x58;
 p->procSys=PROCSYS_Create(p->heapId);
 p->party=q->party;
 PARTY_STATUS_SetupDisplay((Args *)q, (Other *)p, (Output *)((char *)p+8));PARTY_STATUS_InitRecord((int *)q,(int *)p,(PartyStatusObj2 *)((char *)p+0xA0));
 p->tickAccum=0;
 p->lastTick=d_02FFFC3C;
 p->state=0;q->exitReason=0;
 return 1;
}





int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusObj1 *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=*(unsigned char *)((char *)p+i+0x51);
 if(n!=0)POKEPARTY_Add(q->resultParty,POKEPARTY_GetMember(q->party,n-1));
 }
 PLIST_COMM_End((char *)p+8);GF_OVERLAY_Unload((unsigned)ov090_id);
 PROCSYS_Delete(p->procSys);PROCSYS_FreeProcWork(handle);GFL_HEAP_DeleteChecked(0x58);
 return 1;
}





int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,char *p)
{
    if(((PartyStatusObj1 *)p)->timerRunning==1 && ((PartyStatusObj1 *)p)->timeLeft!=0) {
        u32 now;
        now=d_02FFFC3C;
        ((PartyStatusObj1 *)p)->tickAccum+=(u8)(now-((PartyStatusObj1 *)p)->lastTick);
        ((PartyStatusObj1 *)p)->lastTick=now;
        if(((PartyStatusObj1 *)p)->tickAccum>60) {
            --((PartyStatusObj1 *)p)->timeLeft;
            ((PartyStatusObj1 *)p)->tickAccum-=60;
        }
    }
    if(GFL_NET_GetRunState()) {
        if(*((u8 *)GFL_NET_GetInitParam()+0x65)==3) {
            if(GFL_NET_ERR_GetErrorLevel()) {
                GFL_NET_ERR_RequestScreen();
                q->exitReason=2;
                ((PartyStatusObj1 *)p)->closeRequested=1;((PartyStatusObj1 *)p)->forceExit=1;
            }
        } else {
            int one;
            one=1;
            switch(DWC_RAPCOMMON_HandleNetError((void *)1,(void *)1)) {
            case 0:case 3:break;
            case 4:q->exitReason=3;((PartyStatusObj1 *)p)->closeRequested=one;((PartyStatusObj1 *)p)->forceExit=one;break;
            case 1:case 2:default:q->exitReason=1;((PartyStatusObj1 *)p)->closeRequested=1;((PartyStatusObj1 *)p)->forceExit=1;break;
            }
        }
    }
    switch(((PartyStatusObj1 *)p)->state) {
    case 0:GF_OVERLAY_Load((int)ov091_id);
        PROCSYS_Push(((PartyStatusObj1 *)p)->procSys,-1,gPartyListProcData,p+8);((PartyStatusObj1 *)p)->state=1;break;
    case 1:if(PROCSYS_Main(((PartyStatusObj1 *)p)->procSys)==0)((PartyStatusObj1 *)p)->state=2;break;
    case 2:GF_OVERLAY_Unload((int)ov091_id);
        if(((PartyStatusObj1 *)p)->exitCode==1) {((PartyStatusObj1 *)p)->savedPosition=((PartyStatusObj1 *)p)->selectedIndex;((PartyStatusObj1 *)p)->state=3;}
        else return 1;
        break;
    case 3:GF_OVERLAY_Load((int)ov131_id);
        PROCSYS_Push(((PartyStatusObj1 *)p)->procSys,-1,gPokeStatusProcData,p+0xa0);((PartyStatusObj1 *)p)->state=4;break;
    case 4:
        if(((PartyStatusObj1 *)p)->timerRunning==1 && ((PartyStatusObj1 *)p)->timeLeft==0)((PartyStatusObj1 *)p)->forceExit=1;
        if(PROCSYS_Main(((PartyStatusObj1 *)p)->procSys)==0)((PartyStatusObj1 *)p)->state=5;break;
    case 5:GF_OVERLAY_Unload((int)ov131_id);
        if(((PartyStatusObj1 *)p)->closeRequested==0) {((PartyStatusObj1 *)p)->selectedIndex=((PartyStatusObj1 *)p)->savedPosition;((PartyStatusObj1 *)p)->state=0;}
        else return 1;
        break;
    }
    if(((PartyStatusObj1 *)p)->closeRequested==0) {
        p+=8;
        PLIST_COMM_Update((u8 *)p);
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
void PARTY_STATUS_SetupDisplay(Args *p, Other *o, Output *out)
{
    u8 *regulation;
    void *saveControl;
    u8 i;
    regulation = p->regulation;
    saveControl = GAME_DATA_GetSaveControl(p->gameData);
    out->party = o->party;
    out->bag = 0;
    out->mailBox = 0;
    out->config = (u32)SYSTEM_DATA_GetConfig(saveControl);
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
    GF_OVERLAY_Load((int)ov90_id);
    PLIST_COMM_Start((u8 *)out);
}






/*
 * Populate the 0x28-byte record from the two source objects.
 */
void PARTY_STATUS_InitRecord(int *args, int *work, PartyStatusObj2 *record)
{
    int saveControl;
    int zukanSave;
    saveControl = (int)GAME_DATA_GetSaveControl((struct Big *)args[5]);
    GAME_DATA_GetMyStatus((void *)args[5]);
    zukanSave = (int)ZUKAN_SAVE_GetFromGameData((void *)args[5]);
    record->party = work[1];
    record->gameData = args[5];
    record->config = (int)SYSTEM_DATA_GetConfig((void *)saveControl);
    record->ppt = 1;
    record->mode = 1;
    record->max = POKEPARTY_GetCount((void *)work[1]);
    record->pos = 0;
    record->page = 0;
    record->retMovePos = 0;
    record->retSel = 0;
    record->newMove = 0;
    record->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)zukanSave);
    record->canUseButtons = 0;
    record->forceExit = 0;
}






/*
 * Allocate the 0x58-byte subobject and dispatch on track[1].
 */
int PARTY_STATUS_CreateSub(struct Proc *proc, int unused, int *param)
{
    int work;
    GFL_HEAP_CreateChildHeap(1, 0x58, 0x10000);
    work = (int)PROCSYS_AllocProcWork(proc, 4, 0x58);
    MI_CpuFill8((void *)work, 0, 4);
    param[2] = 0;
    switch (param[1]) {
    case 0:
        PARTY_STATUS_Noop(work, param, 0x58);
        break;
    case 1:
        PARTY_STATUS_CreateSubWork((u32 *)((u32 *)work), (u32 * *)((u32 **)param), 0x58);
        break;
    }
    return 1;
}





int PARTY_STATUS_DestroySub(void *proc, u32 unused, u32 *param, void *work)
{
    switch (param[1]) {
    case 0:
        PARTY_STATUS_DestroySubWork(work, (u32 *)param);
        break;
    case 1:
        PARTY_STATUS_ExitSubWork(work, param);
        break;
    }
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x58);
    return 1;
}





int PARTY_STATUS_UpdateSub(u32 unused, u32 state, u32 *param, void *work)
{
    u32 r;

    switch (param[1]) {
    case 0:
        r = PARTY_STATUS_NetSync(work, (u32 *)param, (u32 *)((u32 *)state));
        break;
    case 1:
        r = PARTY_STATUS_NetSync2(work, param, (unsigned int *)state);
        break;
    }
    return r != 0;
}




/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void PARTY_STATUS_Noop(int work, int *param, int heapId) {}



int PARTY_STATUS_NetSync(char **out,u32 *ctx,u32 *state)
{
    if(GFL_NET_GetRunState()) {
        switch(DWC_RAPCOMMON_HandleNetError((void *)1,(void *)1)) {
        case 0:break;
        case 1:case 4:ctx[2]=3;return 1;
        case 2:case 3:default:ctx[2]=1;return 1;
        }
    }
    switch(*state) {
    case 0:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),16,36);++*state;break;
    case 1:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),16,36))++*state;break;
    case 2:GF_OVERLAY_Load((int)ov067_id);GF_OVERLAY_Load((int)ov114_id);GF_OVERLAY_Load((int)ov175_id);
        *out=WIFIBATTLEMATCH_NET_CreateNetContext(ctx[5],**(void ** *)&((PartyStatusObj7 *)ctx)->f0,0,88);++*state;break;
    case 3:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),17,36);++*state;break;
    case 4:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),17,36))++*state;break;
    case 5:if(WIFIBATTLEMATCH_NET_SendRegDataAlt(*out,ctx[3]))++*state;break;
    case 6:if(WIFIBATTLEMATCH_NET_TakeRegBuffer(*out,ctx[4]))++*state;break;
    case 7:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,36);++*state;break;
    case 8:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,36))++*state;break;
    case 9:WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)((u32)*out));*out=0;
        GF_OVERLAY_Unload((int)ov175_id);GF_OVERLAY_Unload((int)ov114_id);GF_OVERLAY_Unload((int)ov067_id);++*state;break;
    case 10:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),19,36);++*state;break;
    case 11:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),19,36))return 1;break;
    }
    return 0;
}




void PARTY_STATUS_DestroySubWork(void **work, u32 *param)
{
    if (*work == 0)
        return;
    WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)((u32)*work));
    GF_OVERLAY_Unload((u32)ov175_id);
    GF_OVERLAY_Unload((u32)ov114_id);
    GF_OVERLAY_Unload((u32)ov067_id);
}




void PARTY_STATUS_CreateSubWork(u32 *work, u32 **param, u32 heapId)
{
    GF_OVERLAY_Load((u32)ov176_id);
    *work = (u32)LIVEBATTLEMATCH_IRC_Create(*(u32 *)*param, heapId);
}



unsigned PARTY_STATUS_NetSync2(void **netWork,unsigned *ctx,unsigned *state)
{
 if(GFL_NET_ERR_GetErrorLevel()!=0){GFL_NET_ERR_RequestScreen();ctx[2]=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F);++*state;break;
 case 2:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F)!=0)++*state;break;
 case 3:if(LIVEBATTLEMATCH_IRC_SendSaveData((int)(*netWork),ctx[3])!=0)++*state;break;
 case 4:if(LIVEBATTLEMATCH_IRC_RecvSaveData(*netWork,(const void *)ctx[4])!=0)++*state;break;
 case 5:return 1;
 }
 LIVEBATTLEMATCH_IRC_NoOp(*netWork);return 0;
}


void PARTY_STATUS_ExitSubWork(int *work, void *param)
{
    LIVEBATTLEMATCH_IRC_Delete(*work);
    GF_OVERLAY_Unload((int)ov176_id);
}
