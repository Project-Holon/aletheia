/*
 * file:     zukan.c
 * unit:     yes
 * function: ZUKAN_Create, ZUKAN_Update, ZUKAN_Delete, ZUKAN_FreeIdList, ZUKAN_SetResumeState, ZUKAN_GetResumeState, ZUKAN_StartProc211, ZUKAN_ResumeProc211, ZUKAN_StartProc209, ZUKAN_ResumeProc209, ZUKAN_StartProc210, ZUKAN_ResumeProc210, ZUKAN_StartProc208, ZUKAN_ResumeProc208, ZUKAN_LoadListAndSelection, ZUKAN_FixLastViewedSpecies, ZUKAN_IsNationalMode, ZUKAN_InitQuery, ZUKAN_StartWipeIn, ZUKAN_StartWipeOut, ZUKAN_TickCounter, ZUKAN_CreateActor
 * address:  0x021C8E80
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BC8BC 0x021BC8BC data ov211 a4
 *   ov211_id 0x000000D3 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021C0714 0x021C0714 data ov210 a4
 *   ov210_id 0x000000D2 data a1
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   d_021C8108 0x021C8108 data ov208 a4
 *   ov208_id 0x000000D0 data a1
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 *   ZUKAN_SEARCH_ENGINE_LoadSpeciesIds 0x021C976C thumb ov212
 *   PROCSYS_Delete  0x0203133C  arm  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 */
#include "zukan_shared_types.h"

struct Proc;

struct Blk37;

struct S020314B8;

struct ProcSys;

struct Obj;

/*
 * Arguments the field proclink builds and hands to the zukan proc. Layout
 * matches the ZukanParam record in ov010/event_field_proclink.c.
 */
struct ZukanParam {
    void *gameData;      /* 0x00 game data handle */
    void *zukanSave;     /* 0x04 pokedex save block */
    void *myStatus;      /* 0x08 trainer status */
    u16 startSpecies;    /* 0x0C starting screen selector (0..5) */
    u16 result;          /* 0x0E result the sub proc writes back */
};

/* The zukan proc work object (44 bytes, PROCSYS_AllocProcWork(obj,44,105)). */
struct ZukanWork {
    struct ZukanParam *ctx;   /* 0x00 arguments passed to ZUKAN_Create */
    void *proc;               /* 0x04 PROCSYS_Create handle */
    u32 procResult;           /* 0x08 result returned by PROCSYS_Main */
    u16 *idList;              /* 0x0C species id list */
    u16 count;                /* 0x10 number of entries in idList */
    u16 mode;                 /* 0x12 list mode (0 regional, 1 national) */
    u8 query[8];              /* 0x14 search query buffer (7 bytes used) */
    u32 state;                /* 0x1C proc state index */
    int resumeState;          /* 0x20 state to resume after the sub proc */
    u32 subMode;              /* 0x24 sub proc selector (1..4) */
    void *subWork;            /* 0x28 argument object of the running sub proc */
};

/* Argument object of the ov211 search proc (12 bytes). Layout matches the
 * ZukanSearchOwner record in ov211/zukan_search_types.h. */
struct ZukanSearchOwner {
    void *gameData;   /* 0x00 */
    void *context;    /* 0x04 trainer status */
    u32 state;        /* 0x08 result the search writes back */
};

/* Argument object of the ov209 list proc (20 bytes). Layout matches the
 * ZukanListArgs record in ov209/zukan_list.c. */
struct ZukanListArgs {
    void *gameData;   /* 0x00 */
    void *save;       /* 0x04 pokedex save block */
    u16 mode;         /* 0x08 header mode (0 regional, 1 national) */
    u16 count;        /* 0x0A number of species rows */
    u16 *ids;         /* 0x0C row species ids */
    u32 state;        /* 0x10 screen state the list writes back */
};

/* Argument object of the ov210 search proc (24 bytes). */
struct ZknSearchArgs {
    void *gameData;   /* 0x00 */
    void *save;       /* 0x04 pokedex save block */
    u8 *query;        /* 0x08 search query buffer */
    int result;       /* 0x0C result the search writes back */
    u16 *idList;      /* 0x10 result species id list */
    u16 count;        /* 0x14 number of result entries */
};

/* Argument object of the ov208 detail proc (20 bytes). */
struct ZukanDetailArgs {
    void *gameData;   /* 0x00 */
    u32 mode;         /* 0x04 detail screen mode (1..4) */
    u16 *idList;      /* 0x08 species id list */
    u16 count;        /* 0x0C number of entries */
    u16 index;        /* 0x0E index of the selected entry */
    int step;         /* 0x10 result the detail screen writes back */
};

/* Descriptor ZUKAN_CreateActor builds one CLACT actor from. Layout matches
 * ZknSearchActorTemplate in ov210/zknsearch_main.c. */
struct ZknSearchActorTemplate {
    int kind;      /* 0x00 */
    u16 id;        /* 0x04 */
    u16 flags;     /* 0x06 */
    int charIdx;   /* 0x08 character resource index */
    int palIdx;    /* 0x0C palette resource index */
    int cellIdx;   /* 0x10 cell resource index */
    u16 x;         /* 0x14 */
    u16 y;         /* 0x16 */
};

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);

extern void *PROCSYS_AllocProcWork(struct Proc *,unsigned,unsigned);

extern void MI_CpuFill8(void *,unsigned char,unsigned);

extern void *PROCSYS_Create(int);

extern unsigned PROCSYS_Main(void *);

extern void PROCSYS_Delete(struct S020314B8 *);

extern void PROCSYS_FreeProcWork(struct Proc *);

extern void GFL_HEAP_DeleteChecked(u32 heap);

extern u32 GFL_HEAP_Free(void *p);

extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,u16);

extern void PROCSYS_Push(struct ProcSys *,unsigned,unsigned,unsigned);

extern void *ZUKAN_SAVE_GetFromGameData(void *);

extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *);

extern void ZUKAN_SAVE_SetLastViewedSpecies(struct Blk37 *p, u32 v);

extern unsigned ZUKAN_SAVE_GetViewMode(struct Blk37 *);

extern unsigned ZUKAN_SAVE_IsCaught(struct Blk37 *,u16);

extern unsigned ZUKAN_SAVE_IsSeen(struct Blk37 *,u16);

extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern void BG_SYS_ResetSlot(u32,u32,u32);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

int ZUKAN_Create(struct Proc *obj,int unused,struct ZukanParam *ctx);

int ZUKAN_Update(int a,int b,int c,struct ZukanWork *p);

int ZUKAN_Delete(struct Proc *obj, void *b, void *c, struct ZukanWork *p);

void ZUKAN_FreeIdList(struct ZukanWork *p);

int ZUKAN_SetResumeState(struct ZukanWork *p, int v);

u32 ZUKAN_GetResumeState(struct ZukanWork *p);

void ZUKAN_StartProc211(struct ZukanWork *p);

int ZUKAN_ResumeProc211(struct ZukanWork *p);

void ZUKAN_StartProc209(struct ZukanWork *p);

int ZUKAN_ResumeProc209(struct ZukanWork *p);

void ZUKAN_StartProc210(struct ZukanWork *p);

int ZUKAN_ResumeProc210(struct ZukanWork *p);

void ZUKAN_StartProc208(struct ZukanWork *p);

int ZUKAN_ResumeProc208(struct ZukanWork *p);

u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,unsigned heap);

void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count);

int ZUKAN_IsNationalMode(struct Blk37 *p);

void ZUKAN_InitQuery(struct Blk37 *p, u8 *out);

void ZUKAN_StartWipeIn(u32 heap);

void ZUKAN_StartWipeOut(u32 heap);

void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter);

struct Obj *ZUKAN_CreateActor(u32 bank, const struct ZknSearchActorTemplate *t, u16 heap);

u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,int heap,u16 **out);

extern unsigned char d_021C9944[];

extern const char d_021C99A0[];

extern const unsigned d_021BC8BC[];

extern unsigned char ov211_id[];

extern const unsigned d_021BE794[];

extern unsigned char ov209_id[];

extern const unsigned d_021C0714[];

extern unsigned char ov210_id[];

extern const unsigned d_021C8108[];

extern unsigned char ov208_id[];

/*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 */
int ZUKAN_Create(struct Proc *obj,int unused,struct ZukanParam *ctx)
{
    struct ZukanWork *p;
    GFL_HEAP_CreateChildHeap(1,105,0x8000);
    p=PROCSYS_AllocProcWork(obj,44,105);
    MI_CpuFill8(p,0,44);
    p->ctx=ctx;
    p->proc=PROCSYS_Create(105);
    p->count=ZUKAN_LoadListAndSelection(p->ctx->zukanSave,&p->idList,105);
    p->mode=0;
    ZUKAN_FixLastViewedSpecies(p->ctx->zukanSave,p->idList,p->count);
    ZUKAN_InitQuery(p->ctx->zukanSave,p->query);
    if(p->ctx->startSpecies==0){p->state=1;}
    else if(p->ctx->startSpecies==1){p->state=3;}
    else if(p->ctx->startSpecies==2){p->state=5;p->subMode=1;}
    else if(p->ctx->startSpecies==3){p->state=5;p->subMode=2;}
    else if(p->ctx->startSpecies==4){p->state=5;p->subMode=3;}
    else if(p->ctx->startSpecies==5){p->state=5;p->subMode=4;}
    else {p->state=7;}
    return 1;
}

int ZUKAN_Update(int a,int b,int c,struct ZukanWork *p){if(p->state==9)return 1;p->procResult=PROCSYS_Main(p->proc);p->state=(*(unsigned (**)(struct ZukanWork *))(d_021C9944+p->state*4))(p);return 0;}

int ZUKAN_Delete(struct Proc *obj, void *b, void *c, struct ZukanWork *p) {
    ZUKAN_FreeIdList(p);
    PROCSYS_Delete(p->proc);
    PROCSYS_FreeProcWork(obj);
    GFL_HEAP_DeleteChecked(105);
    return 1;
}

void ZUKAN_FreeIdList(struct ZukanWork *p)
{
    if (p->idList != 0) {
        GFL_HEAP_Free(p->idList);
        p->idList = 0;
    }
}

int ZUKAN_SetResumeState(struct ZukanWork *p, int v)
{
    p->resumeState = v;
    return 0;
}

/* hidden function: 16 bytes between ZUKAN_SetResumeState and ZUKAN_StartProc211 */
u32 ZUKAN_GetResumeState(struct ZukanWork *p)
{
    if (p->procResult != 1)
        return p->resumeState;
    return 0;
}

void ZUKAN_StartProc211(struct ZukanWork *p)
{
    struct ZukanSearchOwner *q;
    q=GFL_HEAP_Alloc(105,12,0,d_021C99A0,297);
    p->subWork=q;
    q->gameData=p->ctx->gameData;
    q->context=p->ctx->myStatus;
    PROCSYS_Push(p->proc,(unsigned)ov211_id,(unsigned)d_021BC8BC,(unsigned)p->subWork);
    ZUKAN_SetResumeState(p,2);
}

int ZUKAN_ResumeProc211(struct ZukanWork *p) {
    int result;
    switch (((struct ZukanSearchOwner *)p->subWork)->state) {
    case 0:
        p->ctx->result = 0;
        result = 9;
        break;
    case 1:
        p->ctx->result = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    GFL_HEAP_Free(p->subWork);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 */
void ZUKAN_StartProc209(struct ZukanWork *p)
{
    struct ZukanListArgs *q=GFL_HEAP_Alloc(105,20,0,d_021C99A0,359);
    p->subWork=q;
    q->gameData=p->ctx->gameData;
    q->save=p->ctx->zukanSave;
    q->mode=p->mode;
    if(p->mode==0&&ZUKAN_IsNationalMode(p->ctx->zukanSave)==0){
        q->ids=p->idList+1;
        q->count=p->count-1;
    }else{
        q->ids=p->idList;
        q->count=p->count;
    }
    PROCSYS_Push(p->proc,(unsigned)ov209_id,(unsigned)d_021BE794,(unsigned)p->subWork);
    ZUKAN_SetResumeState(p,4);
}

/*
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 */
int ZUKAN_ResumeProc209(struct ZukanWork *p)
{
    int result;
    switch(((struct ZukanListArgs *)p->subWork)->state){
    case 0:
        if(p->mode==0){
            p->ctx->result=0;result=9;
        }else{
            ZUKAN_FreeIdList(p);
            p->count=ZUKAN_LoadListAndSelection(p->ctx->zukanSave,&p->idList,105);
            p->mode=0;result=3;
        }
        goto done;
    case 1:p->ctx->result=1;result=9;goto done;
    case 2:
        ZUKAN_FreeIdList(p);
        p->count=ZUKAN_LoadListAndSelection(p->ctx->zukanSave,&p->idList,105);
        result=3;goto done;
    case 3:result=5;p->subMode=1;goto done;
    case 4:
        if(p->mode==1){
            ZUKAN_FreeIdList(p);
            p->count=ZUKAN_LoadListAndSelection(p->ctx->zukanSave,&p->idList,105);
        }
        result=7;goto done;
    default:break;
    }
    p->ctx->result=0;result=9;
done:
    GFL_HEAP_Free(p->subWork);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 */
void ZUKAN_StartProc210(struct ZukanWork *p)
{
    struct ZknSearchArgs *q;
    q=GFL_HEAP_Alloc(105,24,0,d_021C99A0,455);
    p->subWork=q;
    q->gameData=p->ctx->gameData;
    q->save=p->ctx->zukanSave;
    q->query=p->query;
    q->idList=0;
    q->count=0;
    PROCSYS_Push(p->proc,(unsigned)ov210_id,(unsigned)d_021C0714,(unsigned)p->subWork);
    ZUKAN_SetResumeState(p,8);
}

/*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 */
int ZUKAN_ResumeProc210(struct ZukanWork *p)
{
    struct ZknSearchArgs *q=p->subWork;
    int result;
    switch(q->result){
    case 0:
        ZUKAN_FreeIdList(p);
        p->idList=q->idList;
        p->count=q->count;
        p->mode=1;
        result=3;
        break;
    case 1:
        p->mode=0;
        result=3;
        break;
    case 2:
    default:
        p->ctx->result=1;
        result=9;
        break;
    }
    GFL_HEAP_Free(p->subWork);
    return result;
}

/*
 * prototype: 02031348 forwards all four original inputs to 020314F4;
 * the matched forwarding target reads each, overriding legacy void(void).
 */
void ZUKAN_StartProc208(struct ZukanWork *p)
{
    struct ZukanDetailArgs *q;
    u16 selected,i;
    selected=ZUKAN_SAVE_GetLastViewedSpecies(ZUKAN_SAVE_GetFromGameData(p->ctx->gameData));
    q=GFL_HEAP_Alloc(105,20,0,d_021C99A0,530);
    q->gameData=p->ctx->gameData;
    q->mode=p->subMode;
    q->idList=p->idList;
    q->count=p->count;
    q->index=0;
    for(i=0;i<q->count;i++){
        if(q->idList[i]==selected){q->index=i;break;}
    }
    PROCSYS_Push(p->proc,(unsigned)ov208_id,(unsigned)d_021C8108,(unsigned)q);
    p->subWork=q;
    ZUKAN_SetResumeState(p,6);
}

int ZUKAN_ResumeProc208(struct ZukanWork *p)
{
    struct Blk37 *save;
    struct ZukanDetailArgs *q;
    int result;
    save = ZUKAN_SAVE_GetFromGameData(p->ctx->gameData);
    q = p->subWork;
    ZUKAN_SAVE_SetLastViewedSpecies(save, q->idList[q->index]);
    switch (q->step) {
    case 0:
        p->ctx->result = 1;
        result = 9;
        break;
    case 1:
        p->ctx->result = 0;
        result = 3;
        break;
    }
    GFL_HEAP_Free(p->subWork);
    return result;
}

/*
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 */
u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(ZUKAN_SAVE_GetViewMode(save)==1)count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(0,heap,&list);
    else count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(ZUKAN_SAVE_IsCaught(save,list[i])==1||ZUKAN_SAVE_IsSeen(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}

void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=ZUKAN_SAVE_GetLastViewedSpecies(p);
    for(i=0;i<count;i++) {
        if(ZUKAN_SAVE_IsSeen(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) ZUKAN_SAVE_SetLastViewedSpecies(p,chosen);
}

int ZUKAN_IsNationalMode(struct Blk37 *p) {
    if (ZUKAN_SAVE_GetViewMode(p) == 1) return 1;
    if (ZUKAN_SAVE_IsCaught(p,494) == 1 || ZUKAN_SAVE_IsSeen(p,494) == 1) return 1;
    return 0;
}

void ZUKAN_InitQuery(struct Blk37 *p, u8 *out) {
    if(ZUKAN_SAVE_GetViewMode(p)==1) out[0]=0; else out[0]=1;
    out[1]=0; out[2]=255; out[3]=255; out[4]=255; out[5]=255; out[6]=255;
}

void ZUKAN_StartWipeIn(u32 heap) { WIPE_SYS_Start(0,1,1,0,6,1,heap); }

void ZUKAN_StartWipeOut(u32 heap) { WIPE_SYS_Start(0,0,0,0,6,1,heap); }

void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { BG_SYS_ResetSlot(a,1,1); BG_SYS_ResetSlot(b,1,1); *counter=0; }
}

struct Obj *ZUKAN_CreateActor(u32 bank, const struct ZknSearchActorTemplate *t, u16 heap) {
    return CLACT_CreateActor((void *)bank,t->charIdx,t->palIdx,t->cellIdx,t,t->y,heap);
}
