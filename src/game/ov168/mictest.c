/*
 * file:     mictest.c
 * unit:     yes
 * function: MICTEST_Create, MICTEST_Exit, MICTEST_Main, MICTEST_InitStepMachine, MICTEST_RunStepMachine, MICTEST_SetStep, MICTEST_GetOwner, MICTEST_IsStepDone, MICTEST_MarkStepDone, MICTEST_StepWipeIn, MICTEST_StepRecord, MICTEST_StepWaitAnim, MICTEST_StepWipeOut, MICTEST_StepFinish, MICTEST_ResetDisplay, MICTEST_ClearDisplay, MICTEST_SetupVramBanks, MICTEST_VBlank, MICTEST_InitActorSystem, MICTEST_ExitActorSystem, MICTEST_UpdateActors, MICTEST_CreateActors, MICTEST_DeleteUnit, MICTEST_ActorVBlank, MICTEST_InitBg, MICTEST_ExitBg, MICTEST_BgNoop, MICTEST_InitBgTiles, MICTEST_UpdateBg, MICTEST_CreateWindows, MICTEST_DeleteWindows, MICTEST_InitMic, MICTEST_ExitMic, MICTEST_UpdateMic, MICTEST_ArmMic, MICTEST_DisarmMic, MICTEST_GetMicLevel, MICTEST_OnMicEvent, MICTEST_LevelToAnim, MICTEST_AreAllSpritesIdle, MICTEST_SpawnSprite, MICTEST_InitSpriteTask, MICTEST_UpdateSpriteTask, MICTEST_DeleteSpriteTasks, MICTEST_TouchHit, MICTEST_CheckTouchOrKey
 * address:  0x02183B60
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   TCB_Init 0x02030CBC arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_02184A20 0x02184A20 data a4
 *   TCB_DeleteTask  0x02030EAC  arm
 *   TCB_Noop  0x02030DA4  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   ov088_id       0x00000058  data  a1
 *   d_021BD574     0x021BD574  data  ov088 a4
 *   TCB_Main   0x02030D28  arm
 *   WIPE_SYS_Start   0x0202208C  thumb
 *   WIPE_SYS_EndCheck   0x020221A4  thumb
 *   MICTEST_CheckTouchOrKey   0x0218484C  thumb
 *   SND_MIC_IsLimitReached   0x02006D94  thumb
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *   CLACT_SetActorAnimSeq   0x0204B878  arm
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   NNS_GfdDoVramTransfer  0x02061C44  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021848D4     0x021848D4  data  ov168  a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_02184878 0x02184878 data a4
 *   d_02184964 0x02184964 data a1
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromArchive 0x02049624 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BG_SYS_Update 0x020419E4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_WIN_CreateAt 0x02045180 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_02184888 0x02184888 data a1
 *   d_02184868 0x02184868 data a2
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   SND_MIC_Init 0x02006CBC thumb
 *   UI_SetKeepAwakeFlagsGlobal 0x02034F84 arm
 *   SND_MIC_Exit  0x02006D44  thumb
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   SND_MIC_AddElapsed   0x02006D64  thumb
 *   MIC_StartLimitedSampling  0x0208B500  arm
 *   MIC_StopLimitedSampling  0x0208B528  arm
 *   d_02184A40 0x02184A40 data a4
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   TCB_AddTask  0x02030DA8  arm
 *   TCBL_GetOwnedWork  0x02030EE8  arm
 *   GF_STANDARD_SinFromDegrees  0x0203F5FC  arm
 *   CLACT_SetActorPosAxis  0x0204B550  arm
 *   _ll_mul        0x0209C054  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   VEC_Add 0x0207C9D0 arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   KEY_GetTrg  0x020362DC  arm  arm9
 */
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct Proc;
struct TcbSystem;
struct Node;
struct Actor;
struct Obj;
struct Cfg;
struct Bank;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct S02030EE8;

#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/fx_vec.h"
#include "../arm9/printsys.h"
#include "../arm9/procsys.h"
#include "../arm9/tcb_list.h"
#include "../arm9/touchpanel.h"
#include "../types.h"

#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

typedef enum {OBJECT_SIZE=0x150} Size;
enum Result {DONE=1};

struct MictestWork;
struct MictestState;
typedef void (*MictestStepFn)(struct MictestState *, int *);

/* one row of the actor spawn table d_02184910 */
typedef struct {u32 group,id,config;} MictestActorRow;
/* one per-actor placement blob indexed by MictestActorRow.config */
typedef struct {short x,y; u16 id; u8 a,b;} MictestActorParam;
/* one BMP window description row of d_02184888 */
typedef struct {
    u8 layer;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 palette;
    u16 charOffset;
    u8 printX;
    u8 pad_09[3];
} MictestBmpDesc;

/* sprite task object driven by MICTEST_UpdateSpriteTask */
typedef struct {
    void *actor;
    int wait;
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 vx;
    fx32 vy;
    fx32 vz;
    fx32 angle;
    fx32 step;
    fx32 radius;
    void *task;
} MictestMotion;

/* one CLACT registration triple inside MictestWork */
typedef struct {
    u32 character;
    u32 palette;
    u32 cell;
} MictestAnimReg;

/* the spawn table reads one registration triple at 0x20 plus group*4 into
   MictestWork, so the row table stores a u32 index into that block */
typedef struct {
    u8 pad_00[0x20];
    MictestAnimReg animReg;
} MictestActorRegView;

/* one spawn slot inside MictestWork */
typedef struct {
    u8 pad_00[0x2C];
    void *task;
} MictestSprite;

/* BMP windows, message bank and font inside MictestWork */
typedef struct {
    void *bmpWin[3];
    struct MsgBank *msgBank;
    struct GfFont *font;
} MictestRender;

/* microphone sample buffer and recording state inside MictestWork.
 * The leading 0x1C bytes are the MICAutoParam view read by arm9/mic.c
 * (MIC_StartAutoSamplingAsync): type/buffer/size/rate/loop_enable/full_callback/full_arg.
 * allocBuffer at 0x1C is Mictest's own 0x120-byte allocation, past the view. */
typedef struct {
    u32 type;
    u8 *buffer;
    int size;
    u32 rate;
    u32 loop_enable;
    void (*full_callback)(int, struct MictestWork *);
    struct MictestWork *full_arg;
    u8 *allocBuffer;
    int level;
    int levelChanged;
    int recording;
    int stopPending;
    int busy;
    int limitLatch;
} MictestMic;

/* step machine embedded in MictestWork */
typedef struct MictestState {
    struct MictestWork *owner;
    MictestStepFn step;
    int state;
    int done;
} MictestState;

/* the 0x150 byte work object allocated by MICTEST_Create */
typedef struct MictestWork {
    void *actor[7];
    struct Bank *unit;
    MictestAnimReg animReg[4];
    MictestSprite sprite[3];
    int messageTimer;
    MictestRender render;
    MictestMic mic;
    MictestState state;
    void *heapHandle;
    struct TcbSystem *taskCtx;
    struct Node *node;
    int heapId;
} MictestWork;

#include "../arm9/gfl_heap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
struct TcbSystem;
#include "../arm9/gfl_use.h"
struct TcbSystem;
#include "../arm9/wipe.h"
extern int MICTEST_CheckTouchOrKey(void);
#include "../arm9/snd_mic.h"
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
#include "../arm9/nns_gfd_vram_transfer.h"
struct DispVramCfg;
struct SysInit;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
#include "../arm9/app_icon.h"
extern void BG_SYS_Create(u16);
/* The DS code was built against other parameter widths for BMP_WIN_Init (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BMP_WIN_Init(u16);
#else
#include "../arm9/bmp_win.h"
#endif
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
#include "../arm9/gf_font.h"
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u8);
/* The DS code was built against other parameter widths for BG_SYS_InitRun (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u16 heapId);
#else
#include "../arm9/bg_sys.h"
#endif
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(u32 v);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
#include "../arm9/msgdata.h"
struct BmpWin;
extern struct BmpWin *BMP_WIN_CreateAt(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned int charOffset);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
#include "../arm9/bmp.h"
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
struct Strbuf;
#include "../arm9/strbuf.h"
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_PushTile(unsigned);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
#include "../arm9/ui.h"
struct MICAutoParam;
#include "../arm9/mic.h"
struct TcbTask;
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gf_standard.h"
#include "../arm9/key.h"
#include "../sdk_ioreg.h"
#include "../version.h"

/* source line number of the heap allocation */
/* source line number of the heap allocation, part of the heap tag */
enum Result MICTEST_Create(struct Proc *proc);
int MICTEST_Exit(struct Proc *a, int b, int c, MictestWork *p);
int MICTEST_Main(int a, int b, int c, MictestWork *p);
void MICTEST_InitStepMachine(MictestState *p, MictestWork *owner, MictestStepFn step);
void MICTEST_RunStepMachine(MictestState *p);
void MICTEST_SetStep(MictestState *p, MictestStepFn step);
MictestWork *MICTEST_GetOwner(MictestState *p);
int MICTEST_IsStepDone(MictestState *p);
void MICTEST_MarkStepDone(MictestState *p);
void MICTEST_StepWipeIn(MictestState *self, int *state);
void MICTEST_StepRecord(MictestState *self, int *state);
void MICTEST_StepWaitAnim(MictestState *self, int *state);
void MICTEST_StepWipeOut(MictestState *self, int *state);
void MICTEST_StepFinish(MictestState *self, int *state);
void MICTEST_ResetDisplay(int unused);
void MICTEST_ClearDisplay(void);
void MICTEST_SetupVramBanks(void);
void MICTEST_VBlank(struct TcbTask *unused, void *p);
void MICTEST_InitActorSystem(int unused, u32 heap);
void MICTEST_ExitActorSystem(MictestWork *unused);
void MICTEST_UpdateActors(MictestWork *p);
void MICTEST_CreateActors(MictestWork *p, u16 heap);
void MICTEST_DeleteUnit(MictestWork *p);
void MICTEST_ActorVBlank(void *unused);
void MICTEST_InitBg(MictestRender *p, int heap);
void MICTEST_ExitBg(MictestRender *unused);
void MICTEST_BgNoop(MictestRender *unused);
void MICTEST_InitBgTiles(MictestRender *unused, int heap);
void MICTEST_UpdateBg(MictestRender *unused);
void MICTEST_CreateWindows(MictestRender *p, int heap);
void MICTEST_DeleteWindows(MictestRender *p);
void MICTEST_InitMic(MictestMic *p, int heap, void (*callback)(int, MictestWork *), MictestWork *context);
void MICTEST_ExitMic(MictestMic *p);
void MICTEST_UpdateMic(MictestMic *p);
void MICTEST_ArmMic(MictestMic *p);
void MICTEST_DisarmMic(MictestMic *p);
int MICTEST_GetMicLevel(MictestMic *p);
void MICTEST_OnMicEvent(int event, MictestWork *p);
int MICTEST_LevelToAnim(u8 level);
int MICTEST_AreAllSpritesIdle(MictestWork *p);
int MICTEST_SpawnSprite(MictestWork *p, int unused, s16 x, s16 y, void *owner);
void MICTEST_InitSpriteTask(struct TcbSystem *owner, void *handle, MictestSprite *entry, s16 x, s16 y, int speed, u32 angle, u32 radius, u32 wait);
void MICTEST_UpdateSpriteTask(struct TcbTask *task, void *work);
void MICTEST_DeleteSpriteTasks(MictestWork *p);
int MICTEST_TouchHit(void);
int MICTEST_CheckTouchOrKey(void);

extern const char d_02184A20[];
extern char ov088_id[];
extern char d_021BD574[];
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern const MictestActorRow d_02184910[];
extern const MictestActorParam d_021848AC[];
extern int d_02184878[];
extern u8 d_02184964[];
extern const MictestBmpDesc d_02184888[];
extern u16 d_02184868[];
extern unsigned d_02184A40;

enum Result MICTEST_Create(struct Proc *proc)
{
    MictestWork *p;
    Size size;
    int result=1;
    GFL_HEAP_CreateChildHeap(1,73,0x70000);
    size=(Size)sizeof(MictestWork);
    p=PROCSYS_AllocProcWork(proc,size,73);
    MI_CpuFill8(p,0,size);
    p->heapId=73;
    MICTEST_ResetDisplay(73);
    MICTEST_SetupVramBanks();
    p->heapHandle=GFL_HEAP_Alloc((u16)p->heapId,TCB_GetTaskOffset(5),0,d_02184A20,PM_SRC_LINE(0x21d, 0x21c));
    p->taskCtx=TCB_Init(5,p->heapHandle);
    p->node=(struct Node *)GFL_USE_AddMainTask(MICTEST_VBlank, p,1);
    MICTEST_InitBg(&p->render,p->heapId);
    MICTEST_InitBgTiles(&p->render,p->heapId);
    MICTEST_CreateWindows(&p->render,p->heapId);
    MICTEST_InitActorSystem((sptr)p,p->heapId);
    MICTEST_CreateActors(p,p->heapId);
    MICTEST_InitMic(&p->mic,p->heapId,MICTEST_OnMicEvent,p);
    MICTEST_InitStepMachine(&p->state,p,MICTEST_StepWipeIn);
    GFL_USE_FadeOutBgm(10);
    return result;
}

int MICTEST_Exit(struct Proc *a, int b, int c, MictestWork *p)
{
    unsigned short v;

    MICTEST_ExitMic(&p->mic);
    TCB_DeleteTask((struct TcbTask *)p->node);
    TCB_Noop(p->taskCtx);
    GFL_HEAP_Free(p->heapHandle);
    MICTEST_DeleteUnit(p);
    MICTEST_ExitActorSystem(p);
    MICTEST_DeleteWindows(&p->render);
    MICTEST_ExitBg(&p->render);
    MICTEST_ClearDisplay();
    v=(unsigned short)p->heapId;
    PROCSYS_FreeProcWork((struct Proc *)a);
    GFL_HEAP_DeleteChecked(v);
    GFL_USE_FadeInBgmFull(0xa);
    PROCSYS_ReplaceGlobal((uptr)ov088_id,(struct ProcData *)d_021BD574,0);
    return 1;
}

/*
 * Gate on p->state, then run the four init/teardown helpers and the
 *   task context through TCB_Main.
 */
int MICTEST_Main(int a, int b, int c, MictestWork *p)
{
    if (MICTEST_IsStepDone(&p->state))
        return 1;
    MICTEST_RunStepMachine(&p->state);
    MICTEST_UpdateActors(p);
    MICTEST_BgNoop(&p->render);
    MICTEST_UpdateMic(&p->mic);
    TCB_Main((struct TcbSystem *)p->taskCtx);
    return 0;
}

void MICTEST_InitStepMachine(MictestState *p, MictestWork *owner, MictestStepFn step)
{
    p->owner=owner;
    p->done=0;
    MICTEST_SetStep(p,step);
}

void MICTEST_RunStepMachine(MictestState *p)
{
    if (MICTEST_IsStepDone(p) == 0)
        p->step(p, &p->state);
}

void MICTEST_SetStep(MictestState *p, MictestStepFn step) { p->step=step; p->state=0; }

MictestWork *MICTEST_GetOwner(MictestState *p) { return p->owner; }

int MICTEST_IsStepDone(MictestState *p) { return p->done; }

/*
 * extent: 6-byte body followed by two bytes of zero alignment padding.
 */
void MICTEST_MarkStepDone(MictestState *p) { p->done=1; }

void MICTEST_StepWipeIn(MictestState *self, int *state)
{
    MictestWork *work = MICTEST_GetOwner(self);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, work->heapId);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        MICTEST_SetStep(self, MICTEST_StepRecord);
        break;
    }
}

void MICTEST_StepRecord(MictestState *self, int *state)
{
    MictestWork *work = MICTEST_GetOwner(self);
    switch (*state) {
    case 0:
        MICTEST_ArmMic(&work->mic);
        *state = 1;
        break;
    case 1:
        if (MICTEST_CheckTouchOrKey() && SND_MIC_IsLimitReached()) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = 2;
        }
        break;
    case 2:
        MICTEST_DisarmMic(&work->mic);
        *state = 3;
        break;
    case 3:
        MICTEST_SetStep(self, MICTEST_StepWaitAnim);
        break;
    }
}

/*
 * Three-state step over the actor at work->actor[3]: start on 0, poll on 1,
 *   install MICTEST_StepWipeOut on 2.
 */
void MICTEST_StepWaitAnim(MictestState *self, int *state)
{
    MictestWork *work = MICTEST_GetOwner(self);
    switch (*state) {
    case 0:
        CLACT_SetActorAnimSeq(work->actor[3], 1);
        *state = 1;
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct ClactActor *)work->actor[3]) == 0)
            *state = 2;
        break;
    case 2:
        MICTEST_SetStep(self, MICTEST_StepWipeOut);
        break;
    }
}

/*
 * Step a two-slot state machine: publish through WIPE_SYS_Start on state 0,
 *   poll WIPE_SYS_EndCheck on 1, install MICTEST_StepFinish on 2.
 */
void MICTEST_StepWipeOut(MictestState *self, int *state)
{
    MictestWork *work = MICTEST_GetOwner(self);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        MICTEST_SetStep(self, MICTEST_StepFinish);
        break;
    }
}

void MICTEST_StepFinish(MictestState *self, int *state)
{
    MICTEST_DeleteSpriteTasks(MICTEST_GetOwner(self));
    MICTEST_MarkStepDone(self);
}

void MICTEST_ResetDisplay(int unused)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFFE0FFu;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xFFFFE0FFu;
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
}

void MICTEST_ClearDisplay(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)REG_DISPCNT_ADDR &= 0xFFFFE0FFu;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xFFFFE0FFu;
}

void MICTEST_SetupVramBanks(void)
{
    BG_SYS_SetVramBanks((void *)0x021848D4);
}

void MICTEST_VBlank(struct TcbTask *unused, void *work_)
{ MictestWork * p = work_;
    NNS_GfdDoVramTransfer();
    MICTEST_ActorVBlank(p);
    MICTEST_UpdateBg(&p->render);
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}

void MICTEST_InitActorSystem(int unused, u32 heap)
{
    CLACT_InitSystem((void *)0x020A1448, ((void *)0x021848D4), (u16)heap);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void MICTEST_ExitActorSystem(MictestWork *unused) { CLACT_ExitSystem(); }

void MICTEST_UpdateActors(MictestWork *p)
{
    u16 i;

    for (i = 0; i < 7; i++)
        CLACT_AddActorAnimFrame(p->actor[i], 0x1000);
    CLACT_DrawSystem();
}

/*
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 */
void MICTEST_CreateActors(MictestWork *p, u16 heap)
{
    void *first,*second;
    u16 i;
    const MictestActorRow *r;
    const MictestActorRegView *view;
    i=0;
    p->unit=(struct Bank *)CLACT_CreateUnit(32,0,heap);
    first=ARC_TOOL_CreateHandle(106,heap);
    second=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),heap);
    p->animReg[0].palette=CLACT_RegisterPalette(first,6,0,0,heap);
    p->animReg[0].character=CLACT_RegisterCharacter(first,7,0,0,heap);
    p->animReg[0].cell=CLACT_RegisterCellAnim(first,8,9,heap);
    p->animReg[1].palette=CLACT_RegisterPalette(first,10,0,32,heap);
    p->animReg[1].character=CLACT_RegisterCharacter(first,11,0,0,heap);
    p->animReg[1].cell=CLACT_RegisterCellAnim(first,12,13,heap);
    p->animReg[2].palette=CLACT_RegisterPalette(first,14,0,64,heap);
    p->animReg[2].character=CLACT_RegisterCharacter(first,15,0,0,heap);
    p->animReg[2].cell=CLACT_RegisterCellAnim(first,16,17,heap);
    p->animReg[3].palette=CLACT_RegisterPalette(second,31,1,0,heap);
    p->animReg[3].character=CLACT_RegisterCharacter(second,32,0,1,heap);
    p->animReg[3].cell=CLACT_RegisterCellAnim(first,18,19,heap);
    ARC_TOOL_DeleteHandle(second);
    ARC_TOOL_DeleteHandle(first);
    do{
        r=&d_02184910[i];
        p->actor[i]=CLACT_CreateActor((struct Unit *)p->unit,((MictestWork *)((u32 *)p + r->group))->animReg->character,((MictestWork *)((u32 *)p + r->group))->animReg->palette,((MictestWork *)((u32 *)p + r->group))->animReg->cell,(struct ActorInitParam *)(&d_021848AC[r->config]),r->id,heap);
        CLACT_SetActorAutoAnim(p->actor[i],1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)CLACT_SetActorDrawEnable(p->actor[i+4],0);
    CLACT_SetActorAffineMode(p->actor[0],0);
    CLACT_SetActorFlip(p->actor[0],1,1);
    p->messageTimer=10;
}

void MICTEST_DeleteUnit(MictestWork *p) { CLACT_DeleteUnit((struct Unit *)p->unit); }

void MICTEST_ActorVBlank(void *unused) { CLACT_VBlankSystem(); }

void MICTEST_InitBg(MictestRender *p, int heap)
{
    unsigned i;
    unsigned bg;
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_02184878);
    p->font = GF_FONT_Create(23, 0, 0, 0, (u16)heap);
    for (i = 0; i < 5; i++) {
        bg = d_02184964[i * 0x24 + 0x20];
        BG_SYS_InitBgLayer(bg, (const struct BgTemplate *)(d_02184964 + i * 0x24), d_02184964[i * 0x24 + 0x21]);
        BG_SYS_ClearSlot(bg);
        BG_SYS_InitRun(bg, 32, 0, (u16)heap);
        BG_SYS_SetPlaneVisible(bg, 1);
    }
}

void MICTEST_ExitBg(MictestRender *unused)
{
    u32 i;

    for (i = 0; i < 5; i++)
        BG_SYS_FreeLayerBuf(d_02184964[i * 0x24 + 0x20]);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void MICTEST_BgNoop(MictestRender *unused) {  }

void MICTEST_InitBgTiles(MictestRender *unused, int heap)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(106, 0, 0, 0, 32, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(106, 1, 4, 0, 32, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 0, 416, 32, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 416, 32, heap);
    ARC_UTIL_UploadBgCharFromArchive(106, 4, 5, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromArchive(106, 5, 5, 0, 0, 0, heap);
    ARC_UTIL_UploadBgCharFromArchive(106, 2, 1, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromArchive(106, 3, 1, 0, 0, 0, heap);
}

void MICTEST_UpdateBg(MictestRender *unused) { BG_SYS_Update(); }

void MICTEST_CreateWindows(MictestRender *p, int heap)
{
    int i;
    const MictestBmpDesc *desc;
    void *a;
    void *b;
    void *s;
    p->msgBank = MSGDATA_CreateFromArchive((int)0,(int)2,(int)65,(u16)heap);
    for (i=0;i<3;i++) {
        desc = &d_02184888[i];
        p->bmpWin[i] = (void *)BMP_WIN_CreateAt((int)desc->layer,(int)desc->x,(int)desc->y,(int)desc->width,desc->height,desc->palette,(int)desc->charOffset);
        a = BMP_WIN_GetBmp(p->bmpWin[i]);
        BMP_Clear(a,0);
        BMP_WIN_ClearScreen(p->bmpWin[i]);
        b = MSGDATA_AllocString(p->msgBank,i);
        PRINTSYS_PrintColor(a,desc->printX,0,b,p->font,d_02184868[i]);
        STRBUF_Delete(b);
        s = p->bmpWin[i];
        BMP_WIN_TransferChars(s);
        BMP_WIN_MakeScreen(s);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(s));
    }
}

void MICTEST_DeleteWindows(MictestRender *p) { int i; for(i=0;i<3;i++) {BMP_Clear(BMP_WIN_GetBmp(p->bmpWin[i]),0);BMP_WIN_ClearScreen(p->bmpWin[i]);BMP_WIN_Delete(p->bmpWin[i]);} MSGDATA_Delete(p->msgBank);GF_FONT_Delete(p->font); }

/*
 * 2026-10-05 (wD8 lane06): closed with plain literals (no size local). mwcc keeps one constant of the
 *   block in a callee-saved register and derives the others from it: with the 0x100 store written right
 *   after the aligned-pointer store, 0x120 wins r6 and 0x100 becomes `subs r6,#0x20`. With the 0x100 store
 *   last, 1 wins and 0x100 becomes `adds r0,#0xff` (108 bytes). Earlier lanes needed an enum local here.
 */
void MICTEST_InitMic(MictestMic *p, int heap, void (*callback)(int, MictestWork *), MictestWork *context)
{
    u8 *buf;
    SND_MIC_Init(heap);
    UI_SetKeepAwakeFlagsGlobal(8);
    buf = GFL_HEAP_Alloc((u16)heap, 0x120, 0, d_02184A20, PM_SRC_LINE(0x603, 0x602));
    MI_CpuFill8(buf, 0, 0x120);
    p->allocBuffer = buf;
    p->type = 0;
    p->buffer = (u8 *)(((uptr)buf + 0x1f) & ~0x1f);
    p->size = 0x100;
    p->rate = 0x1001;
    p->loop_enable = 1;
    p->full_callback = callback;
    p->full_arg = context;
    p->limitLatch = SND_MIC_IsLimitReached();
}

void MICTEST_ExitMic(MictestMic *p)
{
    GFL_HEAP_Free(p->allocBuffer);
    SND_MIC_Exit();
    UI_ClearKeepAwakeFlagsGlobal(8);
}

/*
 * Latch the polled flag into p->limitLatch, arming and disarming the
 *   recording state while p->busy tracks the transition.
 */
void MICTEST_UpdateMic(MictestMic *p)
{
    int x;
    int y;
    SND_MIC_AddElapsed(1);
    x = SND_MIC_IsLimitReached();
    if (x != 0 && p->limitLatch != 0)
        goto end;
    if (p->busy == 0) {
        if (p->recording != 0) {
            MICTEST_DisarmMic(p);
            p->stopPending = 1;
        }
        p->busy = 1;
    }
    if (x == 0)
        goto end;
    if (p->limitLatch != 0)
        goto end;
    y = p->stopPending;
    p->busy = 0;
    if (y != 0) {
        MICTEST_ArmMic(p);
        p->stopPending = 0;
    }
end:
    p->limitLatch = x;
}

void MICTEST_ArmMic(MictestMic *p)
{
    if (p->busy == 0) {
        MIC_StartLimitedSampling((struct MICAutoParam *)p);
        p->recording = 1;
    } else {
        p->stopPending = 1;
    }
}

void MICTEST_DisarmMic(MictestMic *p)
{
    MIC_StopLimitedSampling();
    p->recording = 0;
}

int MICTEST_GetMicLevel(MictestMic *p)
{
    int max = 0;
    int i;
    int n = p->size - 1;
    const u8 *d = p->buffer;
    i = 0;
    for (; i < n; i++) {
        u32 v = d[i];
        if (v < 0x80) v = 255 - v;
        if ((int)v > max) max = v;
    }
    return max;
}

void MICTEST_OnMicEvent(int event, MictestWork *p)
{
    MictestMic *q;
    int n,anim;
    if(event==0){
        q=&p->mic;
        n=MICTEST_GetMicLevel(q);
        if(q->level<n){
            anim=MICTEST_LevelToAnim(n);
            q->level=n;
            q->levelChanged=1;
        }else{
            anim=MICTEST_LevelToAnim(q->level);
            q->level-=2;
        }
        if(anim!=0){
            if(q->levelChanged!=0){
                CLACT_SetActorAnimSeq(p->actor[2],1);
                q->levelChanged=0;
            }
            if(MICTEST_AreAllSpritesIdle(p)){
                MICTEST_SpawnSprite(p,p->heapId,128,64,p->taskCtx);
            }else{
                --p->messageTimer;
                if(p->messageTimer==0){
                    MICTEST_SpawnSprite(p,p->heapId,128,64,p->taskCtx);
                    p->messageTimer=10;
                }
            }
            CLACT_SetActorAnimSeq(p->actor[0],anim);
            CLACT_SetActorAnimSeq(p->actor[1],anim);
        }else if(anim==0){
            CLACT_SetActorAnimSeq(p->actor[2],0);
            CLACT_SetActorAnimSeq(p->actor[0],0);
            CLACT_SetActorAnimSeq(p->actor[1],0);
        }
        ++d_02184A40;
    }
}

int MICTEST_LevelToAnim(u8 level) { if(level<=150)return 0;if(level>=151 && level<=162)return 1;if(level>=163 && level<=176)return 2;if(level>=177 && level<=197)return 3;if(level>=198)level=4;return level; }

int MICTEST_AreAllSpritesIdle(MictestWork *p) { int i;for(i=0;i<3;i++)if(p->sprite[i].task)return 0;return 1; }

int MICTEST_SpawnSprite(MictestWork *p, int unused, s16 x, s16 y, void *owner)
{
    void *sprite = 0;
    MictestSprite *entry = 0;
    int i;
    int a;
    int b;
    int c;
    for (i = 0; i < 3; i++) {
        if (p->sprite[i].task == 0) {
            entry = &p->sprite[i];
            sprite = p->actor[i + 4];
            break;
        }
    }
    if (entry) {
        a = GFL_USE_GetRandom(0x1001) + 0x1333;
        b = GFL_USE_GetRandom(61) + 60;
        c = GFL_USE_GetRandom(15) + 6;
        MICTEST_InitSpriteTask(owner, sprite, entry, x, y, a, b, c, 1);
        return 1;
    }
    return 0;
}

/*
 * note (2026-10-05, wD9r lane41): closed by the parameter width. x and y (a3, e) are s16, and
 *   CLACT_SetActorPosAxis takes an s16 second argument as in the matched sibling ov168 02184780. With an s16
 *   stack parameter the y load stays with the entry parameter copies (ldr r5,[sp,#0x18] before the
 *   pool load); an int parameter sinks it to the end of the entry block.
 */
void MICTEST_InitSpriteTask(struct TcbSystem *owner, void *handle, MictestSprite *entry, s16 x, s16 y, int speed, u32 angle, u32 radius, u32 wait)
{
    MictestMotion *o;
    void *t;
    int c;

    t = TCB_AddTask((struct TcbSystem *)owner, MICTEST_UpdateSpriteTask, entry, (unsigned int)0);
    entry->task = t;
    o = (MictestMotion *)TCBL_GetOwnedWork((struct TcblTask *)(struct TcblSystem *)t);
    o->actor = handle;
    o->wait = wait;
    o->x = FX_F32_TO_FX32(x);
    o->y = FX_F32_TO_FX32(y);
    o->z = 0;
    c = GF_STANDARD_SinFromDegrees((u16)(angle + 0x5a));
    o->vx = FX_MUL(speed, c);
    c = GF_STANDARD_SinFromDegrees((u16)angle);
    o->vy = -FX_MUL(speed, c);
    o->vz = 0;
    o->angle = 0;
    o->step = 0x6000;
    o->radius = radius;
    CLACT_SetActorPosAxis((struct ClactActor *)o->actor, x, 0);
    CLACT_SetActorPosAxis((struct ClactActor *)o->actor, y, 1);
}

/*
 * extent: two-byte alignment padding at 0x02184816.
 * Verified blocker C copied from GURU2_MAIN_UpdateRecordPosition.c;
 * the 0203F5FC blocker log reports EXACT, 64 bytes:
 */
void MICTEST_UpdateSpriteTask(struct TcbTask *task, void *work)
{
    MictestMotion *p = work;
    s16 x;
    s16 y;
    int angle;
    if (p->wait != 0) {
        p->wait--;
        if (p->wait == 0)
            CLACT_SetActorDrawEnable(p->actor, 1);
        return;
    }
    VEC_Add((struct VecFx32 *)(&p->x), (struct VecFx32 *)(&p->vx), (struct VecFx32 *)(&p->x));
    x = p->x >> 12;
    y = p->y >> 12;
    p->angle += p->step;
    while (p->angle > 0x168000)
        p->angle -= 0x168000;
    angle = GF_STANDARD_SinFromDegrees((u16)(p->angle >> 12));
    x += (s16)((p->radius * angle) >> 12);
    CLACT_SetActorPosAxis(p->actor, x, 0);
    CLACT_SetActorPosAxis(p->actor, y, 1);
    if (y < -16) {
        CLACT_SetActorDrawEnable(p->actor, 0);
        TCB_DeleteTask(task);
        p->task = 0;
    }
}

void MICTEST_DeleteSpriteTasks(MictestWork *p) { int i; for(i=0;i<3;i++){if(p->sprite[i].task){TCB_DeleteTask(p->sprite[i].task);p->sprite[i].task=0;}} }

int MICTEST_TouchHit(void)
{
    return TOUCHPANEL_HitTrg((void *)0x0218486E);
}

int MICTEST_CheckTouchOrKey(void)
{
    return MICTEST_TouchHit() == 0 || (KEY_GetTrg() & 2) != 0;
}
