/*
 * file:     br_proc_sys.c
 * unit:     yes
 * function: BR_PROC_SYS_Init, BR_PROC_SYS_Exit, BR_PROC_SYS_Main, BR_PROC_SYS_BuildBasicRecord, BR_PROC_SYS_NoopA, BR_PROC_SYS_BuildChoiceRecord, BR_PROC_SYS_PopMenuEntry, BR_PROC_SYS_BuildBattleRecord, BR_PROC_SYS_SetPendingFlag, BR_PROC_SYS_BuildProfileRecord, BR_PROC_SYS_NoopB, BR_PROC_SYS_BuildProfileRecord2, BR_PROC_SYS_NoopC, BR_PROC_SYS_BuildTypeRecord, BR_PROC_SYS_NoopD, BR_PROC_SYS_CopyRecord1, BR_PROC_SYS_NoopE, BR_PROC_SYS_CopyRecord2, BR_PROC_SYS_NoopF, BR_PROC_SYS_CopyRecord3, BR_PROC_SYS_NoopG, BR_PROC_SYS_BuildRecord, BR_PROC_SYS_UpdateRecord, BR_PROC_SYS_BuildRecord2, BR_PROC_SYS_LoadBattleRecord, BR_PROC_SYS_CopyWordsA, BR_PROC_SYS_NoopH, BR_PROC_SYS_CopyWordsB, BR_PROC_SYS_NoopI, BR_PROC_SYS_LoadRecords, BR_PROC_SYS_Create, BR_PROC_SYS_Delete, BR_PROC_SYS_RunSlot, BR_PROC_SYS_IsDone, BR_PROC_SYS_GetSlotId, BR_PROC_SYS_PopEntry, BR_PROC_SYS_PushEntry, BR_PROC_SYS_SetupWindow, BR_PROC_SYS_FlushWindows, BR_PROC_SYS_InitEntry, BR_PROC_SYS_ClearEntry
 * address:  0x021F90C0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, ov186_func_02200228.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_GRAPHIC_Create 0x021FC3BC thumb ov186
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_GetRecorderFlag 0x0200C3E0 thumb
 *   BR_RES_Create 0x021FB884 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_FADE_Create 0x021FE6C0 thumb ov186
 *   BR_FADE_CaptureHwPalettes 0x021FE7B4 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   BR_FADE_BlendFull 0x021FE7F8 thumb ov186
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_SIDEBAR_Create 0x021FED50 thumb ov186
 *   BR_NET_Create 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 *   BR_NET_IsFatal 0x021FF8D4 thumb ov186
 *   BR_NET_Destroy 0x021FF4E4 thumb ov186
 *   func_02034A5C 0x02034A5C arm
 *   BR_SIDEBAR_Destroy 0x021FEDC4 thumb ov186
 *   BR_FADE_Delete 0x021FE734 thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BEACON_SetRecorderFlag 0x0200C3EC thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_Delete 0x021FB92C thumb ov186
 *   BR_GRAPHIC_Destroy 0x021FC474 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BR_FADE_Update 0x021FE768 thumb ov186
 *   BR_SIDEBAR_Update 0x021FEE00 thumb ov186
 *   BR_GRAPHIC_Draw 0x021FC4C8 thumb ov186
 *   BR_NET_Main 0x021FF52C thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   func_020071CC   0x020071CC  thumb
 *   MISC_SAVEDATA_GetBlock3C   0x0200E9F4  thumb
 *   MISC_SAVEDATA_GetStatsBase2   0x0200EA04  thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   MUSICAL_SAVE_IsShowActive 0x0200A630 thumb
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02200D04 0x02200D04 data a1
 *   func_0203133C  0x0203133C  arm
 *   func_020307B0  0x020307B0  arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_02200D14 0x02200D14 data a1
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "br_types.h"

struct BrProcWorkOwner;

struct SoundSys;

struct BigObj;

struct Blk34;

struct S020315D4;

struct BrBattleRecWork;

struct Sub020071CCCtrl;

struct Bits;

struct S020314B8;

typedef struct { struct { u16 id; u16 x; } e[6]; int n; } BrProcStack;

typedef struct { u8 pad[0x24]; BrProcStack *s; } BrProcStackWork;

typedef struct Inner {
    int f0;
    int f4;
} Inner;

typedef struct Mid {
    int pad0;
    int pad4;
    int f8;
    Inner *p0c;
} Mid;

typedef struct Top {
    int w0;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    Mid *f18;
    int w7;
    int w8;
    int w9;
    int f28;
    int f2c;
} Top;

typedef struct { int w0, w4, w8, wc, w10, w14, w18; } BrProcWords;

typedef struct { int w0, w4, w8, wc, w10, w14; struct { int pad[3]; struct { int pad; int v; } *q; } *w18; } BrProcWordsSrc;

typedef struct { int w0, w4, w8, wc, w10, w14, w18; } BrProcWords2;

typedef struct { int w0, w4, w8, wc, w10, w14; struct { int pad[3]; struct { int pad; int v; } *q; } *w18; } BrProcWords2Src;

typedef struct Fields {u32 words[4];void *handles[4];u32 flags[4];u64 values[4];u32 state,ready;} Fields;

typedef struct Context {
    unsigned object;               /* 0x00 process-system object */
    void *base;                    /* 0x04 record array base */
    unsigned short count;          /* 0x08 record count */
    unsigned short pad0;           /* 0x0A */
    unsigned arg;                  /* 0x0C */
    unsigned short heap;           /* 0x10 heap id */
    unsigned short pad1;           /* 0x12 */
    int done;                      /* 0x14 set when the running slot completes */
    int state;                     /* 0x18 slot state machine */
    u8 slotArea[0x30];             /* 0x1C old/current/next slots and entry scratch */
    unsigned pending[6];           /* 0x4C pending record indices */
    int pendingCount;              /* 0x64 */
    unsigned *list;                /* 0x68 loaded index list */
    int loaded;                    /* 0x6C */
} Context;

struct Ops {u32 id,size,fn;void (*init)(void *,u32,void *,int);void (*update)(void *,u32);};

struct Slot {u32 active;void *work;const struct Ops *ops;int arg;};

typedef struct BrProcEntry {
    int kind;        /* 0x00 */
    int unused;      /* 0x04 */
    int entry;       /* 0x08 record address */
    int index;       /* 0x0C */
} BrProcEntry;

/* The screen object built by BR_PROC_SYS_Init. */
typedef struct BrProcSys {
    void *graphic;                     /* 0x00 */
    void *resources;                   /* 0x04 */
    Context *proc;                     /* 0x08 */
    void *fade;                        /* 0x0C */
    void *sidebar;                     /* 0x10 */
    void *net;                         /* 0x14 */
    struct BrProcGameState *gameState; /* 0x18 */
} BrProcSys;

/* Save-data handle shared by the process system and its records. */
typedef struct BrProcShared {
    int state;                         /* 0x00 */
    int saveControl;                   /* 0x04 save-control address */
    int netArg;                        /* 0x08 */
    int unknownC;                      /* 0x0C */
} BrProcShared;

/* The shared game state reached from the screen object (p->gameState). */
typedef struct BrProcGameState {
    int pad0;                          /* 0x00 */
    int flag;                          /* 0x04 */
    unsigned int data;                 /* 0x08 base of the battle-record data block */
    struct BrProcShared *shared;       /* 0x0C */
} BrProcGameState;

/* Handle reached through a source record (record->handle). */
typedef struct BrProcSrcHandle {
    int pad0[2];                       /* 0x00 */
    unsigned int data;                 /* 0x08 base of the battle-record data block */
    struct BrProcShared *shared;       /* 0x0C */
} BrProcSrcHandle;

/* A record filled from a source object. */
typedef struct BrProcOutRecord {
    int kind;                          /* 0x00 */
    int actor;                         /* 0x04 */
    int value1;                        /* 0x08 */
    int value2;                        /* 0x0C */
    int value3;                        /* 0x10 */
    int owner;                         /* 0x14 */
} BrProcOutRecord;

/* A source record whose handle points at the shared state. */
typedef struct BrProcSrcRecord {
    int actor;                         /* 0x00 */
    int value1;                        /* 0x04 */
    int value2;                        /* 0x08 */
    int kind;                          /* 0x0C */
    int pad10;                         /* 0x10 */
    int value3;                        /* 0x14 */
    int handle;                        /* 0x18 handle address, offsets are byte-based */
} BrProcSrcRecord;

/* The parameter block read by the type-2 record builder. */
typedef struct BrProcParam {
    int pad0;                          /* 0x00 */
    int kind;                          /* 0x04 */
    char pad8[0x14];                   /* 0x08 */
    int value1;                        /* 0x1C */
    int value2;                        /* 0x20 */
} BrProcParam;

/* A slot-list buffer: six pending indices then the count. */
typedef struct BrProcSlotList {
    unsigned int index[6];             /* 0x00 */
    int count;                         /* 0x18 */
} BrProcSlotList;

/* A process-system handle whose slot id is read by the leaf getter. */
typedef struct BrProcQuery {
    char pad0[0x10];                   /* 0x00 */
    unsigned short id;                 /* 0x10 */
} BrProcQuery;

/* The object owning a record that is refreshed while it is active. */
typedef struct BrProcOwner {
    char pad0[0x1C];                   /* 0x00 */
    int active;                        /* 0x1C */
} BrProcOwner;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32),MI_CpuFill8(void *,int,unsigned);

extern void *PROCSYS_AllocProcWork(struct BrProcWorkOwner *obj, u32 size, u32 heap);

extern void *BR_GRAPHIC_Create(unsigned mode, int setting, unsigned heap);

extern void *GAME_DATA_GetMiscSave(int *);

extern void *BR_RES_Create(unsigned,unsigned,unsigned);

extern u8 BEACON_GetRecorderFlag(struct Blk34 *p);

extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);

extern int *BR_FADE_Create(unsigned);

extern void BR_FADE_CaptureHwPalettes(char *),BR_FADE_SetBlendColor(int *,int),BR_FADE_BlendFull(char *,int);

extern int BR_RES_GetCurrentSetParam(char *);

extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);

extern char *BR_SIDEBAR_Create(int,int,char *,unsigned);

extern char *BR_NET_Create(void *owner, void *arg, u32 heap);

extern int func_02034AC4(int),GFL_NET_GetRunState(void);

extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);

extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);

extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);

extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);

extern void BR_SIDEBAR_ResetPositions(char *p);

extern void BR_SIDEBAR_StartWobble(char *p);

extern void BR_FADE_SetBlendLevel(int,int,int);

extern int BR_NET_IsFatal(char *);

extern void BR_NET_Destroy(char *p);

extern void func_02034A5C(int);

extern void BR_SIDEBAR_Destroy(char *p, char *ctx);

extern void BR_FADE_Delete(char *p);

extern int BR_RES_GetPalSet(char *p);

extern void BEACON_SetRecorderFlag(struct Blk34 *p, u32 v);

extern void BR_RES_ApplyBgSet(int,unsigned);

extern void BR_RES_Delete(char *p);

extern void BR_GRAPHIC_Destroy(char *);

extern void func_020315D4(struct S020315D4 *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern int FADE_IsActive(void);

extern void BR_FADE_Update(struct BrFade *);

extern void BR_SIDEBAR_Update(char *p);

extern void BR_GRAPHIC_Draw(char *);

extern void BR_NET_Main(char *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern struct BrBattleRecWork *BATTLE_REC_GetWork(void);

extern u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);

extern void GDS_PROFILE_Init(struct GdsProfile *p, void *sys);

extern void *func_020071CC(struct Sub020071CCCtrl *, unsigned int);

extern void *MISC_SAVEDATA_GetBlock3C(void *p);

extern int MISC_SAVEDATA_GetStatsBase2(int);

extern u8 *BATTLE_REC_GetHeader(void);

extern void *MUSICAL_SAVE_GetFromSave(void *);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void *GDS_PROFILE_CreateNameStr(const void *,u32);

extern u32 GDS_PROFILE_GetEggFlag(struct RecGet *p);

extern u32 MUSICAL_SAVE_IsShowActive(struct Bits *p);

extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *PROCSYS_Create(int a0);

extern void func_0203133C(struct S020314B8 *);

extern u32 func_020307B0(void *p);

extern void PROCSYS_Push(u32,u32,u32,void *);

extern u32 PROCSYS_Main(void *);

extern void MI_CpuCopy8(void *, void *, int);

int BR_PROC_SYS_Init(void *obj,int unused,char *q);

int BR_PROC_SYS_Exit(int sys,int unused,int unused2,int *p);

int BR_PROC_SYS_Main(int sys,int *state,int unused,int *p);

void BR_PROC_SYS_BuildBasicRecord(int *out,int *source,int unused,int type);

void BR_PROC_SYS_NoopA(void);

void BR_PROC_SYS_BuildChoiceRecord(int *out,int *source,int *ctx,int type);

void BR_PROC_SYS_PopMenuEntry(BrProcStackWork *o);

void BR_PROC_SYS_BuildBattleRecord(int *out,int *source,const char *ctx,int type);

void BR_PROC_SYS_SetPendingFlag(u32 *a, u32 *b);

void BR_PROC_SYS_BuildProfileRecord(char *r5, int *r4);

void BR_PROC_SYS_NoopB(void);

void BR_PROC_SYS_BuildProfileRecord2(char *r5, int *r4);

void BR_PROC_SYS_NoopC(void);

void BR_PROC_SYS_BuildTypeRecord(int *out, int *source, const int *ctx, int type);

void BR_PROC_SYS_NoopD(void);

void BR_PROC_SYS_CopyRecord1(char *p,char *q);

void BR_PROC_SYS_NoopE(void);

void BR_PROC_SYS_CopyRecord2(int *out,int *source);

void BR_PROC_SYS_NoopF(void);

void BR_PROC_SYS_CopyRecord3(char *p,char *q);

void BR_PROC_SYS_NoopG(void);

void BR_PROC_SYS_BuildRecord(int *out,int *source,int *ctx,int type);

void BR_PROC_SYS_UpdateRecord(char *p,char *q);

void BR_PROC_SYS_BuildRecord2(int *out,int *source,const char *ctx,int type);

void BR_PROC_SYS_LoadBattleRecord(Top *p, Top *q);

void BR_PROC_SYS_CopyWordsA(BrProcWords *a, BrProcWordsSrc *b);

void BR_PROC_SYS_NoopH(void);

void BR_PROC_SYS_CopyWordsB(BrProcWords2 *a, BrProcWords2Src *b);

void BR_PROC_SYS_NoopI(void);

void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap);

Context *BR_PROC_SYS_Create(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap);

void BR_PROC_SYS_Delete(int *p);

void BR_PROC_SYS_RunSlot(char *p);

int BR_PROC_SYS_IsDone(int *p);

unsigned BR_PROC_SYS_GetSlotId(struct BrProcQuery *p);

void BR_PROC_SYS_PopEntry(unsigned *ctx);

void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index);

void BR_PROC_SYS_SetupWindow(Context *p);

void BR_PROC_SYS_FlushWindows(Context *p);

void BR_PROC_SYS_InitEntry(char *p,int a,int b);

void BR_PROC_SYS_ClearEntry(void *p);

extern char ov125_id[];

extern const char d_02200254[];

extern const char d_02200D00[];

extern const char d_02200D04[];

extern const char d_02200D04[],d_02200D14[];

/*
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 */
int BR_PROC_SYS_Init(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    GFL_HEAP_CreateChildHeap(1,0x5a,0x90000);
    p=PROCSYS_AllocProcWork(obj,0x1c,0x5a);
    zero=0;
    MI_CpuFill8(p,0,0x1c);
    *(char * *)&((struct BrProcSys *)p)->gameState=q;
    ((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)q)->shared))->unknownC=zero;
    if(**(int * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared!=2) flag=zero;
    enabled=1;
    ((struct BrProcSys *)p)->graphic=BR_GRAPHIC_Create(flag,1,0x5a);
    mode=BEACON_GetRecorderFlag(GAME_DATA_GetMiscSave(*(int * *)&((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared))->saveControl));
    if(**(int * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared) enabled=0;
    ((struct BrProcSys *)p)->resources=BR_RES_Create(mode,enabled,0x5a);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct BrProcSys *)p)->resources),0,0x5a);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct BrProcSys *)p)->resources),1,0x5a);
    ((struct BrProcSys *)p)->proc=BR_PROC_SYS_Create(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->data+0x1728),0x5a);
    *(int * *)&((struct BrProcSys *)p)->fade=BR_FADE_Create(0x5a);
    BR_FADE_CaptureHwPalettes(*(char * *)&((struct BrProcSys *)p)->fade);
    BR_FADE_SetBlendColor(*(int * *)&((struct BrProcSys *)p)->fade,BR_RES_GetCurrentSetParam(*(char * *)&((struct BrProcSys *)p)->resources));
    if(!((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->flag) BR_FADE_BlendFull(*(char * *)&((struct BrProcSys *)p)->fade,3);
    *(char * *)&((struct BrProcSys *)p)->sidebar=BR_SIDEBAR_Create(BR_GRAPHIC_GetActorUnit((u8 *)(*(int *)&((struct BrProcSys *)p)->graphic)),*(int *)&((struct BrProcSys *)p)->fade,*(char * *)&((struct BrProcSys *)p)->resources,0x5a);
    BR_PROC_SYS_LoadRecords((char *)(((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->data+0x1748),1,(void *)(((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared))->saveControl),0x5a);
    if(**(int * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared) {
        ((struct BrProcSys *)p)->net=BR_NET_Create((void *)(((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared))->saveControl),(void *)(((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared))->netArg),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(GFL_NET_GetRunState()) GFL_NET_RestartWithDefaultTimeout(0,0x5a);
    if(!**(int * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared) {
        if(((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->flag!=1) func_02028A58((void *)GAME_DATA_GetBgmInfo((const struct BigObj *)(((struct BrProcShared *)(*(char * *)&((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->shared))->saveControl)),0x40,0);
    } else GFL_USE_CancelChangeAndPlayBgm(0x484,0xffff);
    if(((struct BrProcGameState *)(*(char * *)&((struct BrProcSys *)p)->gameState))->flag==1) {
        BR_SIDEBAR_ResetPositions((char *)(*(int *)&((struct BrProcSys *)p)->sidebar));BR_SIDEBAR_StartWobble((char *)(*(int *)&((struct BrProcSys *)p)->sidebar));
        BR_FADE_SetBlendLevel(*(int *)&((struct BrProcSys *)p)->fade,3,0);
    }
    return 1;
}

int BR_PROC_SYS_Exit(int sys,int unused,int unused2,int *p)
{
    int *nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) func_02028A58((struct SoundSys *)GAME_DATA_GetBgmInfo((const struct BigObj *)nested[1]),0x7f,0);
    if(p[5]) {
        if(BR_NET_IsFatal((char *)p[5])) ((int *)((int *)p[6])[3])[3]=2;
        BR_NET_Destroy((char *)p[5]); p[5]=0;
    } else func_02034A5C((int)ov125_id);
    BR_SIDEBAR_Destroy((char *)p[4],(char *)p[1]);
    BR_FADE_Delete((char *)p[3]);
    BR_PROC_SYS_Delete((int *)p[2]);
    nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) {
        int a=(int)GAME_DATA_GetMiscSave((int *)nested[1]);
        int b=BR_RES_GetPalSet((char *)p[1]);
        BEACON_SetRecorderFlag((struct Blk34 *)a,(unsigned char)b);
    }
    BR_RES_ApplyBgSet(p[1],0);
    BR_RES_ApplyBgSet(p[1],1);
    BR_RES_Delete((char *)p[1]);
    BR_GRAPHIC_Destroy((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    GFL_HEAP_DeleteChecked(0x5a);
    return 1;
}

int BR_PROC_SYS_Main(int sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1: FADE_Start(3,16,0,0); *state=2; break;
    case 2: if(!FADE_IsActive()) *state=3; break;
    case 3:
        BR_FADE_Update((struct BrFade *)p[3]);
        BR_SIDEBAR_Update((char *)p[4]);
        BR_PROC_SYS_RunSlot((char *)p[2]);
        BR_GRAPHIC_Draw((char *)p[0]);
        if(p[5]) BR_NET_Main((char *)p[5]);
        if(BR_PROC_SYS_IsDone((int *)p[2])) *state=4;
        break;
    case 4: FADE_Start(3,0,16,0); *state=5; break;
    case 5: if(!FADE_IsActive()) *state=6; break;
    case 6: return 1;
    }
    return 0;
}

/*
 * Extent includes empty follower021F93D0; zeros021F93CE and021F93D2 are alignment.
 */
void BR_PROC_SYS_BuildBasicRecord(int *out,int *source,int unused,int type)
{
    out[3]=source[1];
    out[2]=source[3];
    out[4]=source[2];
    out[1]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    out[5]=source[4];
    if(type==1) out[0]=1;
    else if(((int *)source[6])[1]==0) out[0]=0;
    else out[0]=2;
}

void BR_PROC_SYS_NoopA(void)
{
}

/*
 * note: 2026-10-05 wave P15 D3. Real extent 252 bytes (pool ends 0x021F94CC); the unlabelled
 *   follower at 0x021F94D0 is a separate function. Written from the listing, EXACT* at the first compile.
 */
void BR_PROC_SYS_BuildChoiceRecord(int *out,int *source,int *ctx,int type)
{
    out[3]=2;
    out[10]=*(int *)((char *)source[6]+0xc)+0xc;
    out[9]=*(int *)((char *)source[6]+8)+0x17A0;
    if(*(int *)((char *)source[6]+4)==1) {
        switch(**(int **)((char *)source[6]+0xc)) {
        case 0: out[0]=1; break;
        case 1: out[0]=7; break;
        case 2: out[0]=10; break;
        }
    } else {
        switch(type) {
        case 2:
            switch(ctx[2]) {
            case 0: out[0]=1; break;
            case 1: case 2: case 3: out[0]=2; break;
            case 4: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            case 5: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            }
            break;
        case 5: out[0]=7; break;
        case 6: case 7: out[0]=6; break;
        case 12:
            if(ctx[7]==0) out[3]=4;
            out[0]=10;
            break;
        default:
            switch(**(int **)((char *)source[6]+0xc)) {
            case 0: out[0]=0; break;
            case 1: out[0]=5; break;
            case 2: out[0]=10; break;
            }
            break;
        }
    }
    out[6]=source[1];
    out[4]=source[3];
    out[7]=source[2];
    out[5]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    out[8]=*(int *)((char *)source[6]+8)+0x1748;
}

void BR_PROC_SYS_PopMenuEntry(BrProcStackWork *o) { BrProcStack *s = o->s; int i = s->n - 1; if (s->e[(u16)i].id == 8) s->n = i; }

/*
 * note: final push 2026-10-05 G1L5. Real extent 312 bytes (pool ends 0x021F961A); the unlabelled
 *   follower at 0x021F961C is a separate function, not filed. Case 7 reads the adjacent words ctx+0x10 and
 *   ctx+0x14 as one u64 and splits it into out[7] and out[8] (low word first); this gives the original load
 *   order (r2 from 0x10, then r3 from 0x14). Two int locals, a Pair copy, const, int *ctx and every per-function
 *   pragma left the loads reversed (2 bytes off). A u32 pair read through a pointer or a struct is 101 bytes off.
 *   The u64 read is a judgement call for the integrator: the two words are plausibly one 64-bit field.
 */
void BR_PROC_SYS_BuildBattleRecord(int *out,int *source,const char *ctx,int type)
{
    u32 result;
    void *sys;
    unsigned a,b;
    out[4]=source[1];out[3]=source[3];out[5]=source[2];
    out[6]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    out[9]=source[5];
    out[10]=(*(int **)((char *)source[6]+12))[1];
    out[11]=*(int *)((char *)source[6]+8)+0x1720;
    out[13]=0;
    out[14]=*(int *)((char *)source[6]+8)+0x1748;
    out[15]=*(int *)((char *)source[6]+8)+0x17bc;
    switch(type) {
    case 0:case 2:case 3:case 4:case 6:case 8:case 9: goto done;
    default:
        if(type!=-2) return;
        break;
    case 1:
        out[2]=*(int *)(ctx+8);out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=out[2];
        sys=*(void **)(*(char **)((char *)source[6]+12)+4);
        BATTLE_REC_Load(GAME_DATA_GetSaveControl(sys),0x59,&result,out[2]);
        if(result==1) {if(!out[2]) GDS_PROFILE_Init((struct GdsProfile *)BATTLE_REC_GetWork(),sys);}
        else func_02034714(d_02200D00,0,d_02200D00);
        return;
    case 5:
        out[2]=4;out[12]=*(int *)((char *)source[6]+8);
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=4;
        return;
    case 7:
        out[2]=5;{ unsigned long long v=*(unsigned long long *)(ctx+0x10); out[7]=v; out[8]=v>>32;} out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=5;
        return;
    case 10:
        a=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
        b=*(int *)(ctx+0x20);
        out[2]=a;
        out[12]=*(int *)((char *)source[6]+8);
        a=*(int *)(ctx+0x1c);out[8]=b;out[7]=a;out[13]=1;
        return;
    }
    out[2]=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
    out[12]=*(int *)((char *)source[6]+8);out[13]=1;
done:
    return;
}

void BR_PROC_SYS_SetPendingFlag(u32 *a, u32 *b) { if (*a == 1) *(u32 *)b[6] = 1; }

/*
 * Fill the output record from the source object and its nested handle.
 */
void BR_PROC_SYS_BuildProfileRecord(char *r5, int *r4)
{
    int x;
    x = (int)GAME_DATA_GetSaveControl((struct Big *)(*(int *)(*(int *)(((struct BrProcSrcRecord *)r4)->handle + 0xC) + 4)));
    ((struct BrProcOutRecord *)r5)->value1 = r4[1];
    ((struct BrProcOutRecord *)r5)->kind = r4[3];
    ((struct BrProcOutRecord *)r5)->value2 = r4[2];
    ((struct BrProcOutRecord *)r5)->actor = BR_GRAPHIC_GetActorUnit((u8 *)r4[0]);
    ((struct BrProcOutRecord *)r5)->value3 = (int)func_020071CC((struct Sub020071CCCtrl *)x, 0x3a);
    ((struct BrProcOutRecord *)r5)->owner = *(int *)(*(int *)(((struct BrProcSrcRecord *)r4)->handle + 0xC) + 4);
}

void BR_PROC_SYS_NoopB(void) {}

/*
 *   unlabelled Thumb leaves with no branch anywhere outside this range, so
 *   the two calls stay wildcarded.
 *
 * Fill the output record from the source object and its nested handle.
 */
void BR_PROC_SYS_BuildProfileRecord2(char *r5, int *r4)
{
    int x;
    x = (int)GAME_DATA_GetSaveControl((struct Big *)(*(int *)(*(int *)(((struct BrProcSrcRecord *)r4)->handle + 0xC) + 4)));
    ((struct BrProcOutRecord *)r5)->value1 = r4[1];
    ((struct BrProcOutRecord *)r5)->actor = r4[3];
    ((struct BrProcOutRecord *)r5)->value2 = r4[2];
    ((struct BrProcOutRecord *)r5)->kind = BR_GRAPHIC_GetActorUnit((u8 *)r4[0]);
    ((struct BrProcOutRecord *)r5)->value3 = *(int *)(*(int *)(((struct BrProcSrcRecord *)r4)->handle + 0xC) + 4);
    ((struct BrProcOutRecord *)r5)->owner = MISC_SAVEDATA_GetStatsBase2((int)MISC_SAVEDATA_GetBlock3C((void *)x));
}

void BR_PROC_SYS_NoopC(void) {}

/*
 * extent: empty-return follower 0x021F9728; zero halfwords at 0x021F9726
 *   and 0x021F972A are alignment padding.
 * lever: ctx declared `const int *` lets the type-6 arm load ctx[5]/ctx[6]
 *   ahead of the out[0] store (021F96E4..021F96EA); a plain pointer left 13
 *   bytes, block locals for the two loads 74.
 */
void BR_PROC_SYS_BuildTypeRecord(int *out, int *source, const int *ctx, int type)
{
    out[7] = *(int *)(source[6] + 8);
    out[10] = *(int *)(source[6] + 8) + 0x17C0;
    if (type == 1) {
        out[0] = ctx[2];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = out[0];
        MI_CpuFill8((void *)out[10], 0, 4);
    } else if (type == 6) {
        out[0] = 3;
        out[8] = ctx[5];
        out[9] = ctx[6];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = 3;
        MI_CpuFill8((void *)out[10], 0, 4);
    } else if (type == 2) {
        out[0] = *(int *)(*(int *)(source[6] + 8) + 0x17C4);
        out[1] = 1;
    }
    out[4] = source[1];
    out[2] = source[3];
    out[5] = source[2];
    out[3] = BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    out[6] = source[5];
}

void BR_PROC_SYS_NoopD(void)
{
}

/*
 * extent: empty-return follower 0x021F9750; trailing two-byte padding.
 */
void BR_PROC_SYS_CopyRecord1(char *p,char *q) { ((struct BrProcOutRecord *)p)->value1=((struct BrProcSrcRecord *)q)->value1;((struct BrProcOutRecord *)p)->kind=((struct BrProcSrcRecord *)q)->kind;((struct BrProcOutRecord *)p)->value2=((struct BrProcSrcRecord *)q)->value2;((struct BrProcOutRecord *)p)->actor=BR_GRAPHIC_GetActorUnit((u8 *)(((struct BrProcSrcRecord *)q)->actor));((struct BrProcOutRecord *)p)->value3=((struct BrProcShared *)(*(char * *)&((struct BrProcSrcHandle *)(*(char * *)&((struct BrProcSrcRecord *)q)->handle))->shared))->saveControl; }

void BR_PROC_SYS_NoopE(void) {}

void BR_PROC_SYS_CopyRecord2(int *out,int *source)
{
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[2];
    out[1]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
}

/*
 * Extent includes empty follower BR_PROC_SYS_NoopF; zeros at 021F976E and 021F9772 are alignment.
 */
void BR_PROC_SYS_NoopF(void)
{
}

void BR_PROC_SYS_CopyRecord3(char *p,char *q) { ((struct BrProcOutRecord *)p)->value1=((struct BrProcSrcRecord *)q)->value1;((struct BrProcOutRecord *)p)->kind=((struct BrProcSrcRecord *)q)->kind;((struct BrProcOutRecord *)p)->value2=((struct BrProcSrcRecord *)q)->value2;((struct BrProcOutRecord *)p)->actor=BR_GRAPHIC_GetActorUnit((u8 *)(((struct BrProcSrcRecord *)q)->actor));((struct BrProcOutRecord *)p)->value3=((struct BrProcSrcRecord *)q)->value3;((struct BrProcOutRecord *)p)->owner=((struct BrProcShared *)(*(char * *)&((struct BrProcSrcHandle *)(*(char * *)&((struct BrProcSrcRecord *)q)->handle))->shared))->saveControl; }

/*
 * extent: empty-return follower 0x021F979C; trailing two-byte padding.
 */
void BR_PROC_SYS_NoopG(void) {}

void BR_PROC_SYS_BuildRecord(int *out,int *source,int *ctx,int type)
{
    if(type==1) {
        out[0]=ctx[2];
        out[3]=source[1];
        out[1]=source[3];
        out[4]=source[2];
        out[2]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
        out[5]=(*(int **)((char *)source[6]+0xc))[1];
        out[6]=*(int *)((char *)source[6]+8)+0x1748;
    } else {
        func_02034714(d_02200D00,0,d_02200D00);
    }
}

void BR_PROC_SYS_UpdateRecord(char *p,char *q) { char *s;if(((struct BrProcOwner *)p)->active){s=*(char * *)&((struct BrProcSrcRecord *)q)->handle;BR_PROC_SYS_LoadRecords((char *)(((struct BrProcSrcHandle *)s)->data+0x1748),0,(void *)(((struct BrProcShared *)(*(char * *)&((struct BrProcSrcHandle *)s)->shared))->saveControl),90);} }

/*
 * Lever: compute ctx+0x20 before storing the getter result, then read ctx+0x1c.
 * Direct getter store leaves an 8-byte scheduling/register residue.
 */
void BR_PROC_SYS_BuildRecord2(int *out,int *source,const char *ctx,int type)
{
    unsigned a;
    int b,result;
    if(type!=2) func_02034714(d_02200D00,0,d_02200D00);
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[5];
    out[4]=source[2];
    result=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    a=((struct BrProcParam *)ctx)->value2;
    out[1]=result;
    b=((struct BrProcParam *)ctx)->value1;
    out[8]=a;
    out[7]=b;
    out[5]=(*(int **)((char *)source[6]+0xc))[1];
    out[6]=*(int *)((char *)source[6]+8)+0x1748;
    out[9]=((struct BrProcParam *)ctx)->kind;
}

void BR_PROC_SYS_LoadBattleRecord(Top *p, Top *q)
{
    int buf[1];

    if (p->f28 == 0)
        return;
    BR_PROC_SYS_LoadRecords((char *)q->f18->f8 + 0x1748, 0, (void *)q->f18->p0c->f4, 0x5a);
    BATTLE_REC_Load((void *)((int)GAME_DATA_GetSaveControl((struct Big *)q->f18->p0c->f4)), 0x805a, (u32 *)buf, p->f2c);
}

void BR_PROC_SYS_CopyWordsA(BrProcWords *a, BrProcWordsSrc *b) { a->wc = b->w4; a->w0 = b->wc; a->w10 = b->w8; a->w8 = b->w0; a->w14 = b->w14; a->w4 = b->w10; a->w18 = b->w18->q->v; }

void BR_PROC_SYS_NoopH(void) {}

void BR_PROC_SYS_CopyWordsB(BrProcWords2 *a, BrProcWords2Src *b) { a->wc = b->w4; a->w0 = b->wc; a->w10 = b->w8; a->w8 = b->w0; a->w14 = b->w14; a->w4 = b->w10; a->w18 = b->w18->q->v; }

void BR_PROC_SYS_NoopI(void) {}

/*
 * note: 2026-10-05 recoup. The old draft had the save and tag spill slots swapped
 *   (4 bytes). Declaring the heap parameter of BATTLE_REC_Load as u16 and keeping the
 *   tag as a plain u32 local `(heap & 0x7fff) | 0x8000` (no u16 cast) gives EXACT in
 *   c99 and c. Other forms tried: u16 or int tag, tag inline in the call, tag set
 *   before save, declaration order of tag and save, tag in the loop body, heap
 *   reassigned, u32 heap parameter, all six per-function pragmas: all 4 bytes off.
 */
void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap)
{
    int enabled=1;
    int i;
    u32 result;
    u32 save;
    void *profile;
    if(skip && *(int *)(p+0x54)) enabled=0;
    if(enabled) {
        u32 tag;
        save=(u32)GAME_DATA_GetSaveControl(sys);
        if(*(int *)(p+0x54)) {
            for(i=0;i<4;i++) {
                if(((Fields *)p)->handles[i]) {
                    STRBUF_Delete(((Fields *)p)->handles[i]);
                    ((Fields *)p)->handles[i]=0;
                }
            }
        }
        MI_CpuFill8(p,0,0x58);
        tag=(heap&0x7fff)|0x8000;
        for(i=0;i<4;i++) {
            BATTLE_REC_Load((void *)save,tag,&result,i);
            if(result==1) {
                profile=BATTLE_REC_GetWork();
                if(i==0) GDS_PROFILE_Init(profile,sys);
                *(int *)((u32)p+(u32)i*4)=1;
                *(void **)((u32)p+(u32)i*4+0x10)=GDS_PROFILE_CreateNameStr(profile,0x59);
                *(u32 *)((u32)p+(u32)i*4+0x20)=GDS_PROFILE_GetEggFlag(profile);
                *(u64 *)((u32)p+(u32)i*8+0x30)=BATTLE_REC_GetHeaderParam(BATTLE_REC_GetHeader(),4,0);
            }
        }
        *(u32 *)(p+0x50)=MUSICAL_SAVE_IsShowActive(MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(sys)));
        *(int *)(p+0x54)=1;
    }
}

Context *BR_PROC_SYS_Create(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap)
{
    Context *ctx;
    unsigned i = 0;
    ctx = func_02030734(heap, 0x70, 0, d_02200D04, 0x77);
    MI_CpuFill8(ctx, 0, 0x70);
    ctx->heap = heap;
    ctx->count = count;
    ctx->arg = arg;
    ctx->base = base;
    ctx->list = list;
    ctx->object = (unsigned int)PROCSYS_Create(heap);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x2c);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x1c);
    if (ctx->list[6]) {
        for (i = 0; i < ctx->list[6]; i++) {
            BR_PROC_SYS_PushEntry((unsigned int *)ctx, (unsigned short)ctx->list[i]);
        }
        MI_CpuFill8(ctx->list, 0, 0x1c);
        ctx->loaded = 1;
    } else {
        BR_PROC_SYS_PushEntry((unsigned int *)ctx, fallback);
    }
    return ctx;
}

void BR_PROC_SYS_Delete(int *p)
{
    func_0203133C((struct S020314B8 *)p[0]);
    func_020307B0(p);
}

/*
 * tail: existing matched accessor followers 021F9B98 and 021F9B9C; lead only.
 */
void BR_PROC_SYS_RunSlot(char *p)
{
 struct Slot *current,*old,*next;
 current=(struct Slot *)(p+0x2c);
 old=(struct Slot *)(p+0x1c);
 next=(struct Slot *)(p+0x3c);
 switch(((struct Context *)p)->state){
 case 0:*old=*current;*current=*next;((struct Context *)p)->state=1;break;
 case 1:{
  int mode;
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(!current->ops->init)func_02034714(d_02200D14,0,d_02200D14);
  current->work=func_02030734(((struct Context *)p)->heap,current->ops->size,0,d_02200D04,0xd2);
  MI_CpuFill8(current->work,0,current->ops->size);
  mode=-2;if(!((struct Context *)p)->loaded)mode=old->arg;
  current->ops->init(current->work,((struct Context *)p)->arg,old->work,mode);
  ((struct Context *)p)->loaded=0;
  if(old->work)func_020307B0(old->work);
  PROCSYS_Push(*(u32 *)&((struct Context *)p)->object,current->ops->fn,current->ops->id,current->work);
  ((struct Context *)p)->state=2;break;
 }
 case 2:if(!PROCSYS_Main((void *)((struct Context *)p)->object))((struct Context *)p)->state=3;break;
 case 3:
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(current->ops->update)current->ops->update(current->work,((struct Context *)p)->arg);
  if(((struct Context *)p)->pendingCount)((struct Context *)p)->state=0;
  else{if(current->work)func_020307B0(current->work);((struct Context *)p)->state=4;}
  break;
 case 4:((struct Context *)p)->done=1;break;
 }
}

/*
 * Follower021F9B9C has its existing matched source/shard; no unit.
 */
int BR_PROC_SYS_IsDone(int *p)
{
    return p[5];
}

/*
 * leaf: sole blocker of ov183 021DB2E0; parent cleared ownership.
 */
unsigned BR_PROC_SYS_GetSlotId(struct BrProcQuery *p)
{
    return p->id;
}

void BR_PROC_SYS_PopEntry(unsigned *ctx)
{
    BrProcEntry info;
    if (ctx[25] != 0) {
        ctx[25]--;
        if (ctx[25] != 0) {
            unsigned idx = (unsigned short)((unsigned *)((char *)ctx + 0x48))[ctx[25]];
            BR_PROC_SYS_InitEntry((char *)(&info), idx, (int)((char *)ctx[1] + idx * 20));
            *(BrProcEntry *)((char *)ctx + 0x3c) = info;
        } else {
            BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
        }
    } else {
        BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
    }
}

void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index)
{
    BrProcEntry info;
    char *base = (char *)ctx[1];
    char *entry = base + index * 20;
    if (index >= ((struct Context *)ctx)->count)
        func_02034714(d_02200D14, 0, d_02200D14);
    BR_PROC_SYS_InitEntry((char *)(&info), index, (int)entry);
    if (ctx[25] >= 6)
        func_02034714(d_02200D14, 0, d_02200D14);
    ((unsigned (*)[6])((char *)ctx + 0x4c))[0][ctx[25]] = index;
    ctx[25]++;
    *(BrProcEntry *)((char *)ctx + 0x3c) = info;
}

void BR_PROC_SYS_SetupWindow(Context *p)
{
    MI_CpuCopy8(p->pending, p->list, 0x18);
    ((struct BrProcSlotList *)((char *)p->list))->count = p->pendingCount;
    BR_PROC_SYS_FlushWindows(p);
}

void BR_PROC_SYS_FlushWindows(Context *p)
{
    while (p->pendingCount != 0)
        BR_PROC_SYS_PopEntry((unsigned int *)p);
}

void BR_PROC_SYS_InitEntry(char *p,int a,int b) { int zero=0;MI_CpuFill8(p,0,16);((struct BrProcEntry *)p)->kind=1;((struct BrProcEntry *)p)->unused=zero;((struct BrProcEntry *)p)->index=a;((struct BrProcEntry *)p)->entry=b; }

void BR_PROC_SYS_ClearEntry(void *p)
{
    MI_CpuFill8(p, 0, 0x10);
    ((struct BrProcEntry *)p)->index = -1;
}
