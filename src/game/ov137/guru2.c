/*
 * file:     guru2.c
 * unit:     yes
 * function: GURU2_EntryProcInit, GURU2_EntryProcMain, GURU2_EntryProcExit, GURU2_SessionCreate, GURU2_SessionDestroy, GURU2_SessionGetArgs, GURU2_EntryStateStartReceipt, GURU2_PartyListArgsCreate, GURU2_EntryStateOpenPartyList, GURU2_EntryStateAfterPartyList, GURU2_EntryStateReopenPartyList, GURU2_EntryStateFinish, GURU2_EntryStateDestroySession, GURU2_GetUnionApp
 * address:  0x021DC860
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from guru2.c, guru2_main.c, GURU2_MAIN_BroadcastResult.c by tools/splitfile.py.
 *
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   gGuru2EntryStateTable 0x021E1A50 data a4
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   gGuru2AllocFileName 0x021E2260 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PROCSYS_Push 0x02031348 arm
 *   gGuru2LobbyProcData 0x021E1A38 data a4
 *   d_0000005B 0x0000005B data a1
 *   gPartyListProcData 0x021BED00 data ov091 a4
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   d_00000083 0x00000083 data a1
 *   gGuru2MainProcData 0x021E1A44 data a4
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb  arm9
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   GURU2_COMM_Create 0x021DCB04 thumb ov137
 *   GURU2_COMM_Destroy 0x021DCB60 thumb ov137
 *   GURU2_COMM_Exit 0x021DCB90 thumb ov137
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */

#include "ov137_types.h"
#include "guru2_shared_types.h"
#include "guru2_types.h"

struct S020314B8;

struct BigObj;

struct Blk37;

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,u32);

extern void *PROCSYS_Create(int a0);

extern u32 PROCSYS_Main(void *);

extern void PROCSYS_Delete(struct S020314B8 *p);

extern void PROCSYS_FreeProcWork(struct Proc *p);

extern void *GFL_HEAP_Alloc(u16,u32,int,const char *,u16);

extern u32 GFL_HEAP_Free(void *p);

extern void PROCSYS_Push(void *,int,const void *,void *);

extern void *GAME_DATA_GetMyParty(const struct BigObj *p);

extern void *GAME_DATA_GetMyItem(const struct BigObj *p);

extern u32 POKEPARTY_GetCount(void *);

extern void *POKEPARTY_GetMember(void *p, u32 idx);

extern void GFL_NET_SetAutoExit(u8 a0);

extern u8 *GAME_DATA_GetMyStatus(void *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

int GURU2_EntryProcInit(void *obj,int a,struct Guru2Param *param);

int GURU2_EntryProcMain(void *obj,int a,int b,struct Guru2Entry *p);

int GURU2_EntryProcExit(void *obj,int a,int b,struct Guru2Entry *p);

struct Guru2Session *GURU2_SessionCreate(struct Guru2Param *param,int heap);

void GURU2_SessionDestroy(struct Guru2Session *p);

unsigned int GURU2_SessionGetArgs(struct Guru2Session *p);

int GURU2_EntryStateStartReceipt(struct Guru2Entry *p);

struct Guru2PartyListParam *GURU2_PartyListArgsCreate(struct Guru2Entry *p,int a,int b);

int GURU2_EntryStateOpenPartyList(struct Guru2Entry *p);

int GURU2_EntryStateAfterPartyList(struct Guru2Entry *p);

int GURU2_EntryStateReopenPartyList(struct Guru2Entry *p);

int GURU2_EntryStateFinish(struct Guru2Entry *p);

int GURU2_EntryStateDestroySession(struct Guru2Entry *p);

void *GURU2_GetUnionApp(struct Guru2Comm *p);

struct Guru2Comm *GURU2_COMM_Create(struct Guru2Session *session,int heap);

void GURU2_COMM_Destroy(struct Guru2Comm *p);

void GURU2_COMM_Exit(struct Guru2Comm *p);

extern const char gGuru2AllocFileName[];

extern const u8 gGuru2LobbyProcData[];

extern const unsigned char gPartyListProcData[];

extern const unsigned char d_0000005B[];

extern const u8 gPokeStatusProcData[],gGuru2MainProcData[],d_00000083[];

extern int (* const gGuru2EntryStateTable[])(struct Guru2Entry *);

int GURU2_EntryProcInit(void *obj,int a,struct Guru2Param *param)
{
    struct Guru2Entry *p=PROCSYS_AllocProcWork(obj,36,4);
    MI_CpuFill8(p,0,36);
    p->gameData=param->gameData;
    p->param=param;
    p->procHandle=PROCSYS_Create(1);
    return 1;
}

int GURU2_EntryProcMain(void *obj,int a,int b,struct Guru2Entry *p)
{
    switch(PROCSYS_Main(p->procHandle)) {
    case 0: if(gGuru2EntryStateTable[p->state](p)==1) return 1; break;
    case 1: break;
    case 2: break;
    }
    return 0;
}

int GURU2_EntryProcExit(void *obj,int a,int b,struct Guru2Entry *p)
{
    PROCSYS_Delete(p->procHandle);
    PROCSYS_FreeProcWork(obj);
    return 1;
}

struct Guru2Session *GURU2_SessionCreate(struct Guru2Param *param,int heap)
{
    struct Guru2Session *p;
    p=GFL_HEAP_Alloc((u16)heap,36,0,gGuru2AllocFileName,171);
    MI_CpuFill8(p,0,36);
    p->param=param;
    p->comm=GURU2_COMM_Create(p,heap);
    return p;
}

void GURU2_SessionDestroy(struct Guru2Session *p)
{
    GURU2_COMM_Exit(p->comm);
    GURU2_COMM_Destroy(p->comm);
    GFL_HEAP_Free(p);
}

unsigned int GURU2_SessionGetArgs(struct Guru2Session *p) { return p->startConfirmed; }

int GURU2_EntryStateStartReceipt(struct Guru2Entry *p)
{
    struct Guru2Session *v;
    v=GURU2_SessionCreate(p->param,4);
    p->state=1;
    p->session=v;
    PROCSYS_Push(p->procHandle,-1,gGuru2LobbyProcData,v);
    return 0;
}

/*
 * GFL_HEAP_Alloc 0x02030734 arm
 * gGuru2AllocFileName 0x021E2260 data a4
 */
struct Guru2PartyListParam *GURU2_PartyListArgsCreate(struct Guru2Entry *p,int a,int b)
{
    struct Guru2PartyListParam *v;
    int i;
    v=GFL_HEAP_Alloc(4,sizeof(struct Guru2PartyListParam),1,gGuru2AllocFileName,256);
    v->party=GAME_DATA_GetMyParty(p->gameData);
    v->playerData=GAME_DATA_GetMyItem(p->gameData);
    v->initialMode=0;
    v->listType=a;
    v->cursor=b;
    for(i=0;i<(int)POKEPARTY_GetCount(v->party);i++) POKEPARTY_GetMember(v->party,i);
    return v;
}

/*
 * GURU2_SessionGetArgs 0x021DC924 thumb ov137
 * GURU2_PartyListArgsCreate 0x021DC950 thumb ov137
 * GFL_NET_SetAutoExit 0x0203D7B0 arm
 * PROCSYS_Push 0x02031348 arm
 * gPartyListProcData 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
int GURU2_EntryStateOpenPartyList(struct Guru2Entry *p)
{
    struct Guru2PartyListParam *v;
    if (!GURU2_SessionGetArgs(p->session)) p->state=5;
    else {
        GFL_NET_SetAutoExit(1);
        v=GURU2_PartyListArgsCreate(p,21,0);
        p->partyListParam=v;
        PROCSYS_Push(p->procHandle,(int)d_0000005B,gPartyListProcData,v);
        p->session->state=1;
        p->state=2;
    }
    return 0;
}

/*
 * GFL_HEAP_Free 0x020307B0 arm
 * GFL_HEAP_Alloc 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * PROCSYS_Push 0x02031348 arm
 * gGuru2AllocFileName 0x021E2260 data a4
 * gPokeStatusProcData 0x021DC800 data a4 ov131
 * gGuru2MainProcData 0x021E1A44 data a4
 * d_00000083 0x00000083 data a1
 */
int GURU2_EntryStateAfterPartyList(struct Guru2Entry *p)
{
    struct Guru2PartyListParam *v=p->partyListParam;
    int mode=v->result,sel=v->cursor;
    void *q;
    void *r;
    GFL_HEAP_Free(v);
    if(mode==1) {
        GAME_DATA_GetMyStatus(p->gameData);
        q=ZUKAN_SAVE_GetFromGameData(p->gameData);
        p->statusParam=GFL_HEAP_Alloc(4,40,0,gGuru2AllocFileName,328);
        MI_CpuFill8(p->statusParam,0,40);
        r=GAME_DATA_GetMyParty(p->gameData);
        p->statusParam->party=r;
        p->statusParam->gameData=p->gameData;
        p->statusParam->flag0C=1;
        p->statusParam->partyCount=POKEPARTY_GetCount(r);
        p->statusParam->cursor=0;
        p->statusParam->flag0D=1;
        p->statusParam->unknown_14=0;
        p->statusParam->unknown_10=0;
        p->statusParam->nationalDex=ZUKAN_SAVE_IsNationalDexEnabled(q);
        p->selectedSlot=sel;
        p->statusParam->cursor=sel;
        PROCSYS_Push(p->procHandle,(int)d_00000083,gPokeStatusProcData,p->statusParam);
        p->state=3;
    } else {
        p->session->selectedSlot=sel;
        PROCSYS_Push(p->procHandle,-1,gGuru2MainProcData,p->session);
        p->session->state=3;
        p->state=4;
    }
    return 0;
}

int GURU2_EntryStateReopenPartyList(struct Guru2Entry *p)
{
    u8 a;
    struct Guru2PartyListParam *v;
    a=p->statusParam->cursor;
    GFL_HEAP_Free(p->statusParam);
    v=GURU2_PartyListArgsCreate(p,21,a);
    p->partyListParam=v;
    PROCSYS_Push(p->procHandle,(int)d_0000005B,gPartyListProcData,v);
    p->state=2;
    return 0;
}

int GURU2_EntryStateFinish(struct Guru2Entry *p) {p->state=5;return 0;}

int GURU2_EntryStateDestroySession(struct Guru2Entry *p) {GURU2_SessionDestroy(p->session);return 1;}

void *GURU2_GetUnionApp(struct Guru2Comm *p) { return p->session->param->unionApp; }
