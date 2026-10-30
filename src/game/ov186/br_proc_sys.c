/*
 * file:     br_proc_sys.c
 * unit:     yes
 * function: BR_PROC_SYS_Create, BR_PROC_SYS_Delete, BR_PROC_SYS_RunSlot, BR_PROC_SYS_IsDone, BR_PROC_SYS_GetSlotId, BR_PROC_SYS_PopEntry, BR_PROC_SYS_PushEntry, BR_PROC_SYS_SetupWindow, BR_PROC_SYS_FlushWindows, BR_PROC_SYS_InitEntry, BR_PROC_SYS_ClearEntry
 * address:  0x021F99CC
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_GRAPHIC_Create 0x021FC3BC thumb ov186
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_GetRecorderFlag 0x0200C3E0 thumb
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
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume 0x02028A58 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 *   BR_NET_IsFatal 0x021FF8D4 thumb ov186
 *   BR_NET_Destroy 0x021FF4E4 thumb ov186
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   BR_SIDEBAR_Destroy 0x021FEDC4 thumb ov186
 *   BR_FADE_Delete 0x021FE734 thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   MISC_SetRecorderFlag 0x0200C3EC thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_Delete 0x021FB92C thumb ov186
 *   BR_GRAPHIC_Destroy 0x021FC474 thumb ov186
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BR_FADE_Update 0x021FE768 thumb ov186
 *   BR_SIDEBAR_Update 0x021FEE00 thumb ov186
 *   BR_GRAPHIC_Draw 0x021FC4C8 thumb ov186
 *   BR_NET_Main 0x021FF52C thumb ov186
 *   GF_PANIC_Fail 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   SAVE_CONTROL_GetBlock   0x020071CC  thumb
 *   LIVEBATTLEMATCH_SAVE_GetFromSave   0x0200E9F4  thumb
 *   LIVEBATTLEMATCH_SAVE_GetStats2   0x0200EA04  thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   MUSICAL_SAVE_IsShowActive 0x0200A630 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02200D04 0x02200D04 data a1
 *   PROCSYS_Delete  0x0203133C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_02200D14 0x02200D14 data a1
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "br_types.h"
#include "br_proc_sys_types.h"

struct BrProcWorkOwner;

struct SoundSys;

struct BigObj;

struct Blk34;

struct Proc;

struct BrBattleRecWork;

struct Sub020071CCCtrl;

struct Bits;

struct ProcSys;

typedef struct { struct { u16 id; u16 x; } e[6]; int n; } BrProcStack;

typedef struct { u8 pad[0x24]; BrProcStack *s; } BrProcStackWork;


typedef struct Top {
    int w0;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    struct BrProcGameState *gameState;
    int w7;
    int w8;
    int w9;
    int hasRecord;
    int recordId;
} Top;


/* The screen object built by BR_PROC_SYS_Init. */
typedef struct BrProcSys {
    struct BrGraphic *graphic;         /* 0x00 */
    struct BrRes *resources;           /* 0x04 */
    struct BrProcSysContext *proc;     /* 0x08 */
    struct BrFade *fade;               /* 0x0C */
    struct BrSidebar *sidebar;         /* 0x10 */
    struct BrNet *net;                 /* 0x14 */
    struct BrProcGameState *gameState; /* 0x18 */
} BrProcSys;

/* Save-data handle shared by the process system and its records. */
typedef struct BrProcShared {
    int state;                         /* 0x00 */
    struct GameData *gameData;         /* 0x04 game data of the save */
    void *netArg;                      /* 0x08 */
    int unknownC;                      /* 0x0C */
} BrProcShared;

/* The shared game state reached from the screen object (p->gameState). */
typedef struct BrProcGameState {
    int pad0;                          /* 0x00 */
    int flag;                          /* 0x04 */
    struct BrRecorderData *data;       /* 0x08 the battle-record data block */
    struct BrProcShared *shared;       /* 0x0C */
} BrProcGameState;

/* Handle reached through a source record (record->handle). */
typedef struct BrProcSrcHandle {
    int pad0[2];                       /* 0x00 */
    u8 *data;                          /* 0x08 base of the battle-record data block */
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

/* A slot-list buffer: six pending indices then the count. */
typedef struct BrProcSlotList {
    unsigned int index[6];             /* 0x00 */
    int count;                         /* 0x18 */
} BrProcSlotList;

/* The object owning a record that is refreshed while it is active. */
typedef struct BrProcOwner {
    char pad0[0x1C];                   /* 0x00 */
    int active;                        /* 0x1C */
} BrProcOwner;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32),MI_CpuFill8(void *,int,unsigned);

#include "../arm9/procsys.h"

#include "br_graphic.h"
struct GameData;

#include "../arm9/game_data.h"

#include "br_res.h"
struct MiscSave;

#include "../arm9/beacon.h"

struct BrFade;

extern struct BrFade *BR_FADE_Create(u16 heapId);

struct BrRes;

struct BrGraphic;

struct Unit;
struct BrSidebar;

#include "br_sidebar.h"
struct BrNet;

#include "br_net.h"

extern int GF_OVERLAY_Load(int),GFL_NET_GetRunState(void);

#include "../arm9/net.h"

struct FieldSoundSystem;

#include "../arm9/field_sound_system.h"

#include "../arm9/gfl_use.h"


extern void BR_FADE_CaptureHwPalettes(struct BrFade *),BR_FADE_SetBlendColor(struct BrFade *,int),BR_FADE_BlendFull(struct BrFade *,int);
extern void BR_FADE_SetBlendLevel(struct BrFade *,int,int);


#include "../arm9/gf_overlay.h"


extern void BR_FADE_Delete(struct BrFade *fade);


#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/fade.h"


extern void BR_FADE_Update(struct BrFade *);


#include "../arm9/gf_panic.h"
struct SaveControl;

struct BattleRecSave;

#include "../arm9/battle_rec.h"


#include "../arm9/gds_profile.h"

#include "../arm9/save_control.h"

#include "../arm9/livebattlematch_savedata.h"

struct BattleRecHeader;

struct MusicalSave;

#include "../arm9/musical_save.h"
struct Strbuf;

#include "../arm9/strbuf.h"
#include "../version.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02200CA0[];
extern const char str_ja_02200CAC[];
extern const char str_ja_02200CB0[];
extern const char str_ja_02200CCC[];
extern const char str_ja_02200CDC[];
extern const char str_ja_02200CEC[];
extern const char str_ja_02200D08[];
extern const char str_ja_02200D20[];
#endif

struct StoredMon;


extern void MI_CpuCopy8(void *, void *, int);

int BR_PROC_SYS_Init(void *obj,int unused,struct BrProcGameState *q);

int BR_PROC_SYS_Exit(struct Proc *sys,int unused,int unused2,struct BrProcSys *p);

int BR_PROC_SYS_Main(int sys,int *state,int unused,struct BrProcSys *p);

void BR_PROC_SYS_BuildBasicRecord(struct BrProcArgBasic *out,struct BrProcSys *source,int unused,int type);

void BR_PROC_SYS_NoopA(void);

void BR_PROC_SYS_BuildChoiceRecord(struct BrProcArgChoice *out,struct BrProcSys *source,int *ctx,int type);

void BR_PROC_SYS_PopMenuEntry(BrProcStackWork *o);

void BR_PROC_SYS_BuildBattleRecord(struct BrProcArgBattle *out,struct BrProcSys *source,const char *ctx,int type);

void BR_PROC_SYS_SetPendingFlag(u32 *a, struct BrProcSys *b);

void BR_PROC_SYS_BuildProfileRecord(struct BrProcArgProfile *r5, struct BrProcSys *r4);

void BR_PROC_SYS_NoopB(void);

void BR_PROC_SYS_BuildProfileRecord2(struct BrProcArgStats *r5, struct BrProcSys *r4);

void BR_PROC_SYS_NoopC(void);

void BR_PROC_SYS_BuildTypeRecord(struct BrProcArgType *out, struct BrProcSys *source, const int *ctx, int type);

void BR_PROC_SYS_NoopD(void);

void BR_PROC_SYS_CopyRecord1(struct BrProcArgSave *p,struct BrProcSys *q);

void BR_PROC_SYS_NoopE(void);

void BR_PROC_SYS_CopyRecord2(struct BrProcArgHead *out,struct BrProcSys *source);

void BR_PROC_SYS_NoopF(void);

void BR_PROC_SYS_CopyRecord3(struct BrProcArgNet *p,struct BrProcSys *q);

void BR_PROC_SYS_NoopG(void);

void BR_PROC_SYS_BuildRecord(struct BrProcArgRecord *out,struct BrProcSys *source,int *ctx,int type);

void BR_PROC_SYS_UpdateRecord(char *p,struct BrProcSys *q);

void BR_PROC_SYS_BuildRecord2(struct BrProcArgResult *out,struct BrProcSys *source,const char *ctx,int type);

void BR_PROC_SYS_LoadBattleRecord(Top *p, Top *q);

void BR_PROC_SYS_CopyWordsA(struct BrProcArgSearch *a, struct BrProcSys *b);

void BR_PROC_SYS_NoopH(void);

void BR_PROC_SYS_CopyWordsB(struct BrProcArgDownload *a, struct BrProcSys *b);

void BR_PROC_SYS_NoopI(void);

void BR_PROC_SYS_LoadRecords(struct BrProcRecords *p, int skip, struct GameData *sys, int heap);

struct BrProcSysContext *BR_PROC_SYS_Create(unsigned fallback, const struct BrProcOps *base, unsigned count, struct BrProcSys *arg, unsigned *list, unsigned short heap);

void BR_PROC_SYS_Delete(struct BrProcSysContext *p);

void BR_PROC_SYS_RunSlot(struct BrProcSysContext *p);

int BR_PROC_SYS_IsDone(struct BrProcSysContext *p);

unsigned BR_PROC_SYS_GetSlotId(struct BrProcSysContext *p);

void BR_PROC_SYS_PopEntry(struct BrProcSysContext *ctx);

void BR_PROC_SYS_PushEntry(struct BrProcSysContext *ctx, unsigned index);

void BR_PROC_SYS_SetupWindow(struct BrProcSysContext *p);

void BR_PROC_SYS_FlushWindows(struct BrProcSysContext *p);

void BR_PROC_SYS_InitEntry(struct BrProcSlot *p,int a,const struct BrProcOps *b);

void BR_PROC_SYS_ClearEntry(struct BrProcSlot *p);

extern char ov125_id[];

extern const char d_02200254[];

extern const char d_02200D00[];

extern const char d_02200D04[];

extern const char d_02200D04[],d_02200D14[];


struct BrProcSysContext *BR_PROC_SYS_Create(unsigned fallback, const struct BrProcOps *base, unsigned count, struct BrProcSys *arg, unsigned *list, unsigned short heap)
{
    struct BrProcSysContext *ctx;
    unsigned i = 0;
    ctx = GFL_HEAP_Alloc(heap, sizeof(*ctx), 0, PM_LANG_JA(d_02200D04, str_ja_02200CCC), 0x77);
    MI_CpuFill8(ctx, 0, sizeof(*ctx));
    ctx->heap = heap;
    ctx->count = count;
    ctx->arg = arg;
    ctx->base = base;
    ctx->list = list;
    ctx->object = PROCSYS_Create(heap);
    BR_PROC_SYS_ClearEntry(&ctx->current);
    BR_PROC_SYS_ClearEntry(&ctx->next);
    BR_PROC_SYS_ClearEntry(&ctx->old);
    if (ctx->list[6]) {
        for (i = 0; i < ctx->list[6]; i++) {
            BR_PROC_SYS_PushEntry(ctx, (unsigned short)ctx->list[i]);
        }
        MI_CpuFill8(ctx->list, 0, 0x1c);
        ctx->loaded = 1;
    } else {
        BR_PROC_SYS_PushEntry(ctx, fallback);
    }
    return ctx;
}

void BR_PROC_SYS_Delete(struct BrProcSysContext *p)
{
    PROCSYS_Delete(p->object);
    GFL_HEAP_Free(p);
}

/*
 * tail: existing matched accessor followers 021F9B98 and 021F9B9C; lead only.
 */
void BR_PROC_SYS_RunSlot(struct BrProcSysContext *p)
{
 struct BrProcSlot *current,*old,*next;
 current=&p->current;
 old=&p->old;
 next=&p->next;
 switch(p->state){
 case 0:*old=*current;*current=*next;p->state=1;break;
 case 1:{
  int mode;
  if(!current->active)GF_PANIC_Fail(PM_LANG_JA(d_02200D14, str_ja_02200CCC),PM_SRC_LINE(0, 0xCF),PM_LANG_JA(d_02200D14, str_ja_02200CDC));
  if(!current->ops->init)GF_PANIC_Fail(PM_LANG_JA(d_02200D14, str_ja_02200CCC),PM_SRC_LINE(0, 0xD0),PM_LANG_JA(d_02200D14, str_ja_02200CEC));
  current->work=GFL_HEAP_Alloc(p->heap,current->ops->size,0,PM_LANG_JA(d_02200D04, str_ja_02200CCC),0xd2);
  MI_CpuFill8(current->work,0,current->ops->size);
  mode=-2;if(!p->loaded)mode=old->arg;
  current->ops->init(current->work,p->arg,old->work,mode);
  p->loaded=0;
  if(old->work)GFL_HEAP_Free(old->work);
  PROCSYS_Push(p->object,current->ops->overlayId,current->ops->procData,current->work);
  p->state=2;break;
 }
 case 2:if(!PROCSYS_Main(p->object))p->state=3;break;
 case 3:
  if(!current->active)GF_PANIC_Fail(PM_LANG_JA(d_02200D14, str_ja_02200CCC),PM_SRC_LINE(0, 0xFD),PM_LANG_JA(d_02200D14, str_ja_02200CDC));
  if(current->ops->update)current->ops->update(current->work,p->arg);
  if(p->pendingCount)p->state=0;
  else{if(current->work)GFL_HEAP_Free(current->work);p->state=4;}
  break;
 case 4:p->done=1;break;
 }
}

/*
 * Follower021F9B9C has its existing matched source/shard; no unit.
 */
int BR_PROC_SYS_IsDone(struct BrProcSysContext *p)
{
    return p->done;
}

/*
 * leaf: sole blocker of ov183 021DB2E0; parent cleared ownership.
 */
unsigned BR_PROC_SYS_GetSlotId(struct BrProcSysContext *p)
{
    return p->heap;
}

void BR_PROC_SYS_PopEntry(struct BrProcSysContext *ctx)
{
    struct BrProcSlot info;
    if (ctx->pendingCount != 0) {
        ctx->pendingCount--;
        if (ctx->pendingCount != 0) {
            unsigned idx = (unsigned short)(&ctx->pending[-1])[ctx->pendingCount];
            BR_PROC_SYS_InitEntry(&info, idx, &ctx->base[idx]);
            ctx->next = info;
        } else {
            BR_PROC_SYS_ClearEntry(&ctx->next);
        }
    } else {
        BR_PROC_SYS_ClearEntry(&ctx->next);
    }
}

void BR_PROC_SYS_PushEntry(struct BrProcSysContext *ctx, unsigned index)
{
    struct BrProcSlot info;
    const struct BrProcOps *entry = &ctx->base[index];
    if (index >= ctx->count)
        GF_PANIC_Fail(PM_LANG_JA(d_02200D14, str_ja_02200CCC), PM_SRC_LINE(0, 0x183), PM_LANG_JA(d_02200D14, str_ja_02200D08));
    BR_PROC_SYS_InitEntry(&info, index, entry);
    if (ctx->pendingCount >= 6)
        GF_PANIC_Fail(PM_LANG_JA(d_02200D14, str_ja_02200CCC), PM_SRC_LINE(0, 0x189), PM_LANG_JA(d_02200D14, str_ja_02200D20));
    ctx->pending[ctx->pendingCount] = index;
    ctx->pendingCount++;
    ctx->next = info;
}

void BR_PROC_SYS_SetupWindow(struct BrProcSysContext *p)
{
    MI_CpuCopy8(p->pending, p->list, 0x18);
    ((struct BrProcSlotList *)((char *)p->list))->count = p->pendingCount;
    BR_PROC_SYS_FlushWindows(p);
}

void BR_PROC_SYS_FlushWindows(struct BrProcSysContext *p)
{
    while (p->pendingCount != 0)
        BR_PROC_SYS_PopEntry(p);
}

void BR_PROC_SYS_InitEntry(struct BrProcSlot *p,int a,const struct BrProcOps *b) { int zero=0;MI_CpuFill8(p,0,sizeof(*p));p->active=1;p->work=0;p->arg=a;p->ops=b; }

void BR_PROC_SYS_ClearEntry(struct BrProcSlot *p)
{
    MI_CpuFill8(p, 0, sizeof(*p));
    p->arg = -1;
}
