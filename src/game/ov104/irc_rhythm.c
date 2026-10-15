/*
 * file:     irc_rhythm.c
 * unit:     yes
 * function: IRC_RHYTHM_Init, IRC_RHYTHM_Exit, IRC_RHYTHM_Main, IRC_RHYTHM_InitScreen, IRC_RHYTHM_ExitScreen, IRC_RHYTHM_DrawScreen, IRC_RHYTHM_GetScreenActor, IRC_RHYTHM_GetScreenActorUnit, IRC_RHYTHM_ScreenVBlankTask, IRC_RHYTHM_InitBackgrounds, IRC_RHYTHM_ExitBackgrounds, IRC_RHYTHM_VBlankBackgrounds, IRC_RHYTHM_InitActorSystem, IRC_RHYTHM_ExitActorSystem, IRC_RHYTHM_DrawActorSystem, IRC_RHYTHM_VBlankActorSystem, IRC_RHYTHM_GetActor, IRC_RHYTHM_GetActorUnit, IRC_RHYTHM_InitTextSystem, IRC_RHYTHM_ExitTextSystem, IRC_RHYTHM_RunPrintQueue, IRC_RHYTHM_GetFont, IRC_RHYTHM_GetPrintQueue, IRC_RHYTHM_GetMessages, IRC_RHYTHM_GetWordSet, IRC_RHYTHM_InitMessageWindow, IRC_RHYTHM_InitTextWindow, IRC_RHYTHM_ExitTextWindow, IRC_RHYTHM_UpdateTextWindow, IRC_RHYTHM_PrintMessage, IRC_RHYTHM_PrintCenteredMessage, IRC_RHYTHM_PrintCenteredMessageColor, IRC_RHYTHM_PrintMessageWithName, IRC_RHYTHM_ClearTextWindow, IRC_RHYTHM_InitCountdown, IRC_RHYTHM_ExitCountdown, IRC_RHYTHM_UpdateCountdown, IRC_RHYTHM_StartCountdown, IRC_RHYTHM_IsCountdownFinished, IRC_RHYTHM_SetState, IRC_RHYTHM_Finish, IRC_RHYTHM_StateIntro, IRC_RHYTHM_StateCountdown, IRC_RHYTHM_StateTapping, IRC_RHYTHM_StateResult, IRC_RHYTHM_StateAbort, IRC_RHYTHM_InitRecord, IRC_RHYTHM_StartRecord, IRC_RHYTHM_IsRecordFull, IRC_RHYTHM_RecordTap, IRC_RHYTHM_JudgeTap, IRC_RHYTHM_InitNetSync, IRC_RHYTHM_ExitNetSync, IRC_RHYTHM_SendRecord, IRC_RHYTHM_GetPartnerRecord, IRC_RHYTHM_OnRecordReceived, IRC_RHYTHM_GetRecordReceiveBuffer, IRC_RHYTHM_GetTouchTap, IRC_RHYTHM_CalcSyncScore, IRC_RHYTHM_BlendPaletteEntry, IRC_RHYTHM_InitParticles, IRC_RHYTHM_ExitParticles, IRC_RHYTHM_UpdateParticles, IRC_RHYTHM_SpawnBurst, IRC_RHYTHM_InitParticle, IRC_RHYTHM_UpdateParticle, IRC_RHYTHM_StartParticle, IRC_RHYTHM_IsParticleActive, IRC_RHYTHM_InitPulse, IRC_RHYTHM_ExitPulse, IRC_RHYTHM_UpdatePulse, IRC_RHYTHM_StartPulse, IRC_RHYTHM_ClearBlendTask
 * address:  0x021B7560
 * region:   ov104
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
 *   func_02012138 0x02012138 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   func_0207D658 0x0207D658 arm
 *   func_020056A0 0x020056A0 thumb
 *   IRC_RHYTHM_ClearBlendTask 0x021B8F08 thumb ov104
 *   func_02030EAC 0x02030EAC arm
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   COMPATIBLE_IRC_SYS_UpdateValueSync 0x021B63D0 thumb ov101
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   sRhythmVramBankConfig 0x021B8F78 data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   sRhythmDisplayConfig 0x021B8F30 data ov104
 *   sRhythmBackgroundLayers 0x021B8F5C data
 *   sRhythmBackgroundTemplates 0x021B8FB4 data
 *   sRhythmBackgroundTypes 0x021B8F40 data ov104
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   gClActorInitParam 0x020A1448 data
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 *   IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 *   OS_IsTickAvailable 0x02087058 arm
 *   OS_InitTick 0x02086FE8 arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   COMPATIBLE_IRC_SYS_AddCommandTable 0x021B64F0 thumb ov101
 *   sRhythmNetCommandTable 0x021B8F28 data a4
 *   COMPATIBLE_IRC_SYS_DeleteCommandTable 0x021B6508 thumb ov101
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   COMPATIBLE_IRC_SYS_SendData 0x021B64B8 thumb ov101
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 *   func_020056EC 0x020056EC thumb
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_0207CA00 0x0207CA00 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 */
#include "irc_rhythm_types.h"

/*
 * Infrared compatibility check, rhythm game.  Both players tap the touch
 * screen ten times after a 3, 2, 1 countdown.  Each tap spawns a burst of
 * particles whose colour tells whether the interval was steadier, faster or
 * slower than the previous one.  The two tap records are exchanged over the
 * infrared link and compared; the result (score and difference of extra
 * taps) goes back to the caller through IrcRhythmContext.
 *
 * The display kit (screen, sprite system, text system, text windows) is the
 * same code as in the other games of the check; every game carries its own
 * copy.
 */

#define REG_BLDCNT (*(volatile u16 *)0x04000050)

#define FX_FROM_INT(v) ((int)((u32)(v) << 12))
#define FX_SCALE_RADIUS(v) ((int)((u32)(v) << 8))

/* sound effects */
#define IRC_RHYTHM_SE_RESULT        0x64b
#define IRC_RHYTHM_SE_TAP_STEADY    0x64c
#define IRC_RHYTHM_SE_TAP_SLOWER    0x64d
#define IRC_RHYTHM_SE_TAP_MUCH_SLOWER 0x64e
#define IRC_RHYTHM_SE_TAP_FASTER    0x64f
#define IRC_RHYTHM_SE_TAP_MUCH_FASTER 0x650
#define IRC_RHYTHM_SE_TAPS_DONE     0x654
#define IRC_RHYTHM_SE_COUNTDOWN     0x66a
#define IRC_RHYTHM_SE_GO            0x66b

/* message numbers of the game's message bank */
#define IRC_RHYTHM_MSG_INTRO        0
#define IRC_RHYTHM_MSG_TAPS_DONE    1
#define IRC_RHYTHM_MSG_WAITING      2
#define IRC_RHYTHM_MSG_RESULT       3
#define IRC_RHYTHM_MSG_PARTNER_LEFT 4
#define IRC_RHYTHM_MSG_TITLE        7

/* values of IrcRhythmContext.status */
#define IRC_RHYTHM_STATUS_DONE          0
#define IRC_RHYTHM_STATUS_CANCELLED     1
#define IRC_RHYTHM_STATUS_PARTNER_LEFT  2

/* actor indices in IrcActorSystem.actors */
#define IRC_RHYTHM_ACTOR_PARTICLE       0
#define IRC_RHYTHM_ACTOR_COUNTDOWN      31

/* the net command table registered with this command base */
#define IRC_RHYTHM_NET_COMMAND_BASE     0xf00

/* particle spawn modes */
#define IRC_RHYTHM_PARTICLES_FALL       0
#define IRC_RHYTHM_PARTICLES_OFF        1
#define IRC_RHYTHM_PARTICLES_BURST      2

struct Proc;
struct Obj;
struct Bank;
struct GfFont;
struct DispConfig;
struct Cfg;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct StrObj;
struct Node;
struct Vec2;

struct BgTemplate { u8 bytes[32]; };

typedef void (*IrcTaskProc)(void *task, void *work);

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Proc *proc,u32 size,u32 heapId);
extern void MI_CpuFill8(void *,int,int);
extern u32 func_02012138(const void *gameSystem);
extern void func_0201F73C(void *window, int a1, int a2, int a3);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys,int value);
extern void func_0207D658(u32,int,int);
extern void *func_020056A0(IrcTaskProc proc,void *work,u32 priority);
extern void func_02030EAC(void *task);
extern void func_020315D4(struct Proc *proc);
extern void func_020306F0(unsigned int);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern int COMPATIBLE_IRC_SYS_UpdateValueSync(IrcSys *sys);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const void *banks);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040DA8(u32,u32,u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *,const void *config,u32 heapId);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern signed int CLACT_RegisterPalette(void *archive, u32 b, u32 c, u32 d, u16 heapId);
extern signed int CLACT_RegisterCharacter(void *archive, u32 b, u32 c, u32 a3, u16 flags);
extern signed int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern signed int CLACT_RegisterPaletteEx(void *archive, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Obj *CLACT_CreateActor(struct Bank *unit,unsigned int character,unsigned int palette,unsigned int cellAnim,const IrcActorPlacement *placement,unsigned short,unsigned short heapId);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void CLACT_SetActorBgPriority(struct Obj *,u32);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void CLACT_SetActorPaletteOffset(struct Obj *,u32,u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_0201DD60(void);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_Create(u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct MsgBank *messages);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_WIN_TransferChars(void *window);
extern void BMP_WIN_MakeScreen(void *window);
extern u8 BMP_WIN_GetBgLayer(void *window);
extern void func_020409B4(u32);
extern void *BMP_WIN_GetBmp(void *window);
extern void BMP_Clear(void *bitmap, u8 value);
extern void STRBUF_Delete(void *);
extern u32 BMP_WIN_Delete(void *window);
extern u32 PRINTSYS_QUE_IsExistTarget(void *queue, void *bitmap);
extern void func_02045CAC(void *messages, u32 index, void *dest);
extern void PRINTSYS_PrintQue(void *queue, void *bitmap, u32 x, u32 y, void *string, void *font);
extern u8 BMP_WIN_GetWidth(void *window);
extern u8 BMP_WIN_GetHeight(void *window);
extern u32 func_0201D304(void *string, void *font, u32 b);
extern u32 func_0201D42C(void *string, void *font);
extern void PRINTSYS_PrintQueColor(void *queue, void *bitmap, u32 x, u32 y, void *string, void *font, u16 color);
extern void func_0201F02C(void *wordSet, u32 i, void *a);
extern void *func_02045EC0(void *messages, u32 index);
extern void func_0201F250(void *wordSet, void *dst, void *src);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys);
extern void COMPATIBLE_IRC_SYS_ResetStep(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys,int value);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys);
extern int OS_IsTickAvailable(void);
extern void OS_InitTick(void);
extern unsigned long long func_020870D0(void);
extern void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys, u32 a, u32 b, u32 c, u32 d);
extern void COMPATIBLE_IRC_SYS_DeleteCommandTable(IrcSys *sys, u32 a);
extern void *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(void *handle);
extern u32 COMPATIBLE_IRC_SYS_SendData(IrcSys *sys, u32 commandId, u32 size, u32 data, u8 target, u32 e, u32 f, u32 g);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_02061CA4(u32 target, u32 offset, const void *src, int size);
extern u32 func_020056EC(u32);
extern void func_0207CA00(const VecFx32 *,const VecFx32 *,VecFx32 *);
extern void VEC_Normalize(const VecFx32 *,VecFx32 *);
extern int func_0207CBD0(VecFx32 *);
extern void func_0207CEE4(int,VecFx32 *,VecFx32 *,VecFx32 *);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float);
extern float _fsub(float, float);

int IRC_RHYTHM_Init(struct Proc *proc,void *state,IrcRhythmContext *context);
int IRC_RHYTHM_Exit(struct Proc *proc,int unused1,int unused2,IrcRhythm *work);
int IRC_RHYTHM_Main(void *proc,u32 *state,void *unused,IrcRhythm *work);
void IRC_RHYTHM_InitScreen(IrcScreen *screen,u16 heapId);
void IRC_RHYTHM_ExitScreen(IrcScreen *screen);
void IRC_RHYTHM_DrawScreen(IrcScreen *screen);
struct Obj *IRC_RHYTHM_GetScreenActor(IrcScreen *screen, int index);
struct Bank *IRC_RHYTHM_GetScreenActorUnit(IrcScreen *screen);
void IRC_RHYTHM_ScreenVBlankTask(void *task,void *screen);
void IRC_RHYTHM_InitBackgrounds(IrcScreen *screen,u16 heapId);
void IRC_RHYTHM_ExitBackgrounds(u32 *bgCharRegion);
void IRC_RHYTHM_VBlankBackgrounds(void *unused);
void IRC_RHYTHM_InitActorSystem(IrcActorSystem *sys,const void *config,u16 heapId);
void IRC_RHYTHM_ExitActorSystem(IrcActorSystem *sys);
void IRC_RHYTHM_DrawActorSystem(void *unused);
void IRC_RHYTHM_VBlankActorSystem(void *unused);
struct Obj *IRC_RHYTHM_GetActor(IrcActorSystem *sys, int index);
struct Bank *IRC_RHYTHM_GetActorUnit(IrcActorSystem *sys);
void IRC_RHYTHM_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId);
void IRC_RHYTHM_ExitTextSystem(IrcTextSystem *text);
int IRC_RHYTHM_RunPrintQueue(IrcTextSystem *text);
void *IRC_RHYTHM_GetFont(IrcTextSystem *text);
void *IRC_RHYTHM_GetPrintQueue(IrcTextSystem *text);
void *IRC_RHYTHM_GetMessages(IrcTextSystem *text);
void *IRC_RHYTHM_GetWordSet(IrcTextSystem *text);
void IRC_RHYTHM_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId);
void IRC_RHYTHM_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId);
void IRC_RHYTHM_ExitTextWindow(IrcTextWindow *win);
int IRC_RHYTHM_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text);
void IRC_RHYTHM_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y);
void IRC_RHYTHM_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId);
void IRC_RHYTHM_PrintCenteredMessageColor(IrcTextWindow *win,IrcTextSystem *text,int msgId,u16 color);
void IRC_RHYTHM_PrintMessageWithName(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *profile, s16 x, s16 y, u16 unused);
void IRC_RHYTHM_ClearTextWindow(IrcTextWindow *win);
void IRC_RHYTHM_InitCountdown(IrcRhythmCountdown *countdown, IrcScreen *screen, int unused);
void IRC_RHYTHM_ExitCountdown(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_UpdateCountdown(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_StartCountdown(IrcRhythmCountdown *countdown);
u32 IRC_RHYTHM_IsCountdownFinished(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_SetState(IrcRhythm *work, IrcRhythmStateFn fn);
void IRC_RHYTHM_Finish(IrcRhythm *work);
void IRC_RHYTHM_StateIntro(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateCountdown(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateTapping(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateResult(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateAbort(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_InitRecord(IrcRhythmRecord *record);
void IRC_RHYTHM_StartRecord(IrcRhythmRecord *record);
int IRC_RHYTHM_IsRecordFull(IrcRhythmRecord *record);
void IRC_RHYTHM_RecordTap(IrcRhythmRecord *record);
int IRC_RHYTHM_JudgeTap(IrcRhythmRecord *record);
void IRC_RHYTHM_InitNetSync(IrcRhythmNetSync *sync,IrcSys *ircSys);
void IRC_RHYTHM_ExitNetSync(IrcRhythmNetSync *sync);
int IRC_RHYTHM_SendRecord(IrcRhythmNetSync *sync,const IrcRhythmRecord *record);
void IRC_RHYTHM_GetPartnerRecord(IrcRhythmNetSync *sync,IrcRhythmRecord *out);
void IRC_RHYTHM_OnRecordReceived(int aid,int size,int data,IrcRhythmNetSync *sync,void *handle);
IrcRhythmRecord *IRC_RHYTHM_GetRecordReceiveBuffer(int aid,IrcRhythmNetSync *sync);
int IRC_RHYTHM_GetTouchTap(IrcPoint *out);
int IRC_RHYTHM_CalcSyncScore(IrcRhythm *work);
int IRC_RHYTHM_BlendPaletteEntry(u32 target,u16 *color,int angle,int paletteBank,u8 colorIndex,u16 from,u16 to);
void IRC_RHYTHM_InitParticles(IrcRhythmParticles *particles,IrcScreen *screen,int mode,int firstActor,int surface);
void IRC_RHYTHM_ExitParticles(IrcRhythmParticles *particles);
void IRC_RHYTHM_UpdateParticles(IrcRhythmParticles *particles);
void IRC_RHYTHM_SpawnBurst(IrcRhythmParticles *particles, const IrcPoint *center, int palette);
void IRC_RHYTHM_InitParticle(IrcRhythmParticle *particle, struct Obj *actor, int surface);
void IRC_RHYTHM_UpdateParticle(IrcRhythmParticle *particle);
void IRC_RHYTHM_StartParticle(IrcRhythmParticle *particle, const IrcPoint *start, const IrcPoint *end, int palette, u32 lifetime);
u32 IRC_RHYTHM_IsParticleActive(IrcRhythmParticle *particle);
void IRC_RHYTHM_InitPulse(IrcRhythmPulse *pulse, int unused);
void IRC_RHYTHM_ExitPulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_UpdatePulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_StartPulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_ClearBlendTask(void *task,void *work);

extern const u8 sRhythmVramBankConfig[];
extern struct DispConfig sRhythmDisplayConfig;
extern const u32 sRhythmBackgroundLayers[];
extern const struct BgTemplate sRhythmBackgroundTemplates[];
extern const u32 sRhythmBackgroundTypes[];
extern const struct Cfg gClActorInitParam;
extern const u32 sRhythmNetCommandTable[];
extern const s16 FX_SinCosTable_[];

/* ---- proc entry points ---- */

int IRC_RHYTHM_Init(struct Proc *proc,void *state,IrcRhythmContext *context) {
 IrcRhythm *work; struct Bank *unit; void *printQueue; void *font;
 GFL_HEAP_CreateChildHeap(1,0x38,0x20000);
 work=PROCSYS_AllocProcWork(proc,0x8b4,0x38);
 MI_CpuFill8(work,0,0x8b4);
 work->context=context;
 IRC_RHYTHM_InitScreen(&work->screen,0x38);
 IRC_RHYTHM_InitTextSystem(&work->text,0,0x38);
 if(work->context->gameSystem) func_02012138(work->context->gameSystem);
 IRC_RHYTHM_InitMessageWindow(&work->messageWindow,5,1,18,30,5,8,0x38);
 func_0201F73C(work->messageWindow.window,0,(u16)(work->screen.bgCharRegion),6);
 IRC_RHYTHM_InitPulse(&work->pulse,0x38);
 if(work->context->gameSystem) IRC_RHYTHM_PrintMessageWithName(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_INTRO,work->context->partner,0,0,0x38);
 else IRC_RHYTHM_PrintMessage(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_INTRO,0,0);
 IRC_RHYTHM_InitCountdown(&work->countdown,&work->screen,0x38);
 IRC_RHYTHM_InitTextWindow(&work->timerWindow,7,6,3,20,5,8,1,1,0x38);
 IRC_RHYTHM_PrintCenteredMessage(&work->timerWindow,&work->text,IRC_RHYTHM_MSG_TITLE);
 func_02041F6C(7,3,0x1000);
 func_02041F6C(7,6,0x1000);
 func_02041FB0(7,9,0x80);
 func_02041FB0(7,12,0x28);
 IRC_RHYTHM_InitTextWindow(&work->captionWindow,2,8,10,16,2,13,0,0,0x38);
 IRC_RHYTHM_InitNetSync(&work->netSync,work->context->ircSys);
 IRC_RHYTHM_InitRecord(&work->record);
 IRC_RHYTHM_InitParticles(&work->particles,&work->screen,1,0,0);
 unit=IRC_RHYTHM_GetScreenActorUnit(&work->screen);
 font=IRC_RHYTHM_GetFont(&work->text);
 printQueue=IRC_RHYTHM_GetPrintQueue(&work->text);
 work->appBar=IRC_APPBAR_Create(2,unit,0,14,13,2,font,printQueue,0x38);
 COMPATIBLE_IRC_SYS_SetOwnValue(work->context->ircSys,1);
 func_0207D658(0x04000050,0x22,-8);
 work->blendTask=func_020056A0(IRC_RHYTHM_ClearBlendTask,work,0);
 IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateIntro);
 return 1;
}

/*
 * volatile: 021B7784 writes the hardware register at 0x04000050.
 */
int IRC_RHYTHM_Exit(struct Proc *proc,int unused1,int unused2,IrcRhythm *work) {
 func_02030EAC(work->blendTask);IRC_RHYTHM_ExitParticles(&work->particles);
 REG_BLDCNT=0;
 IRC_APPBAR_Delete(work->appBar);IRC_RHYTHM_ExitNetSync(&work->netSync);IRC_RHYTHM_ExitCountdown(&work->countdown);IRC_RHYTHM_ExitPulse(&work->pulse);IRC_RHYTHM_ExitTextWindow(&work->captionWindow);IRC_RHYTHM_ExitTextWindow(&work->timerWindow);IRC_RHYTHM_ExitTextWindow(&work->messageWindow);IRC_RHYTHM_ExitScreen(&work->screen);IRC_RHYTHM_ExitTextSystem(&work->text);func_020315D4(proc);func_020306F0(56);return 1;
}

/*
 * prototype: 021B7DD4 tail-forwards live r0 from u32 0201C4E4; caller reads it.
 */
int IRC_RHYTHM_Main(void *proc,u32 *state,void *unused,IrcRhythm *work) {
 switch(*state) {
 case 0: *state=1; break;
 case 1: FADE_Start(3,16,0,0); *state=2; break;
 case 2: if(!FADE_IsActive()) *state=3; break;
 case 3: work->stateFn(work,&work->stateStep); if(work->finished) *state=4; IRC_RHYTHM_UpdatePulse(&work->pulse); break;
 case 4: FADE_Start(3,0,16,0); *state=5; break;
 case 5: if(!FADE_IsActive()) *state=6; break;
 case 6: return 1;
 }
 if(IRC_RHYTHM_RunPrintQueue(&work->text)) { IRC_RHYTHM_UpdateTextWindow(&work->messageWindow,&work->text); IRC_RHYTHM_UpdateTextWindow(&work->timerWindow,&work->text); IRC_RHYTHM_UpdateTextWindow(&work->captionWindow,&work->text); }
 IRC_RHYTHM_DrawScreen(&work->screen);
 IRC_RHYTHM_UpdateParticles(&work->particles);
 if(!work->tappedThisFrame) IRC_APPBAR_Update(work->appBar);
 COMPATIBLE_IRC_SYS_UpdateValueSync(work->context->ircSys);
 return 0;
}

/* ---- screen: backgrounds, sprites and the vblank task ---- */

void IRC_RHYTHM_InitScreen(IrcScreen *screen,u16 heapId) { MI_CpuFill8(screen,0,0xbc); BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks(sRhythmVramBankConfig); func_0204363C(0); BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); IRC_RHYTHM_InitActorSystem(&screen->actorSystem,sRhythmVramBankConfig,heapId); IRC_RHYTHM_InitBackgrounds(screen,heapId); screen->vblankTask=func_020056A0(IRC_RHYTHM_ScreenVBlankTask, screen, 0); }

/*
 * extent: two zero alignment bytes follow compiled code.
 */
void IRC_RHYTHM_ExitScreen(IrcScreen *screen) { func_02030EAC(screen->vblankTask); IRC_RHYTHM_ExitBackgrounds(&screen->bgCharRegion); IRC_RHYTHM_ExitActorSystem(&screen->actorSystem); }

void IRC_RHYTHM_DrawScreen(IrcScreen *screen) { IRC_RHYTHM_DrawActorSystem(&screen->actorSystem); }

struct Obj *IRC_RHYTHM_GetScreenActor(IrcScreen *screen, int index) { return IRC_RHYTHM_GetActor(&screen->actorSystem, index); }

/*
 * Unblocked by matching IRC_RHYTHM_GetActorUnit in ov104 (pkt_ov104_021B7D24).
 */
struct Bank *IRC_RHYTHM_GetScreenActorUnit(IrcScreen *screen) { return IRC_RHYTHM_GetActorUnit(&screen->actorSystem); }

void IRC_RHYTHM_ScreenVBlankTask(void *task,void *arg) { IrcScreen *screen=arg; IRC_RHYTHM_VBlankBackgrounds(screen); IRC_RHYTHM_VBlankActorSystem(&screen->actorSystem); }

void IRC_RHYTHM_InitBackgrounds(IrcScreen *screen,u16 heapId) {
 int i; u32 layer; void *archive;
 func_0203F8F4(heapId);
 BMP_WIN_Init(heapId);
 func_0203FC28(&sRhythmDisplayConfig);
 for(i=0;i<7;i++) {
  layer=sRhythmBackgroundLayers[i];
  func_0203FCA0((u8)layer,&sRhythmBackgroundTemplates[i],(u8)sRhythmBackgroundTypes[i]);
  func_020414AC(layer);
  func_02040588(layer,1);
 }
 archive=func_020490F4(IRC_GRAPHICS_ARCHIVE_ID,heapId);
 func_02049B68(archive,1,0,0,0,heapId);
 func_02049B68(archive,1,4,0,0,heapId);
 func_02049658(archive,0x24,1,0,0,0,heapId);
 func_02049658(archive,0,6,0,0,0,heapId);
 func_02049658(archive,0x30,4,0,0,0,heapId);
 func_020498F4(archive,0x25,1,0,0,0,heapId);
 func_020498F4(archive,4,6,0,0,0,heapId);
 func_020498F4(archive,0x2f,4,0,0,0,heapId);
 func_02040C14(5,0,1,0);
 screen->bgCharRegion=func_02049740(archive,0x31,5,0,0,heapId);
 ARC_TOOL_DeleteHandle(archive);
 func_02049B40(0x17,5,0,0x1a0,0x20,heapId);
 func_02040C14(2,0,1,0);
}

void IRC_RHYTHM_ExitBackgrounds(u32 *bgCharRegion) { int i; func_02040DA8(2,1,0); func_0203FB44(5,(u16)(*bgCharRegion),(u16)(*bgCharRegion>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++) func_020403F4((u8)sRhythmBackgroundLayers[i]); BMP_WIN_Exit(); func_0203F9B4(); }

void IRC_RHYTHM_VBlankBackgrounds(void *unused) { func_020419E4(); }

/* ---- sprite system ---- */

/*
 * prototype: ABF0 forwards AC18's index; B294 forwards CFDC's pointer live in r0.
 */
void IRC_RHYTHM_InitActorSystem(IrcActorSystem *sys,const void *config,u16 heapId) {
 void *archive; int i; IrcActorPlacement placement;
 MI_CpuFill8(sys,0,0xb4);
 CLACT_InitSystem(&gClActorInitParam,config,heapId);
 sys->unit=CLACT_CreateUnit(0x80,0,heapId);
 CLACT_SetUnitDefaultRenderer(sys->unit);
 BG_SYS_SetMainPlaneVisible(0x10,1);
 BG_SYS_SetSubPlaneVisible(0x10,1);
 archive=func_020490F4(IRC_GRAPHICS_ARCHIVE_ID,heapId);
 sys->particlePalette=CLACT_RegisterPalette(archive,0x23,0,0,heapId);
 sys->particleCharacter=CLACT_RegisterCharacter(archive,0x22,0,0,heapId);
 sys->particleCellAnim=CLACT_RegisterCellAnim(archive,0x21,0x20,heapId);
 sys->countdownPalette=CLACT_RegisterPaletteEx(archive,0xc,0,0xe0,0xc,1,heapId);
 sys->countdownCharacter=CLACT_RegisterCharacter(archive,0xb,0,0,heapId);
 sys->countdownCellAnim=CLACT_RegisterCellAnim(archive,0xa,9,heapId);
 sys->subParticlePalette=CLACT_RegisterPalette(archive,0x23,1,0,heapId);
 sys->subParticleCharacter=CLACT_RegisterCharacter(archive,0x22,0,1,heapId);
 sys->subParticleCellAnim=CLACT_RegisterCellAnim(archive,0x21,0x20,heapId);
 ARC_TOOL_DeleteHandle(archive);
 MI_CpuFill8(&placement,0,8);
 for(i=0;i<30;i++) {
  sys->actors[i]=CLACT_CreateActor(sys->unit,sys->particleCharacter,sys->particlePalette,sys->particleCellAnim,&placement,0,heapId);
  CLACT_SetActorDrawEnable(sys->actors[i],0);
  CLACT_SetActorBgPriority(sys->actors[i],3);
  CLACT_SetActorAutoAnim(sys->actors[i],1);
  CLACT_SetActorAnimSeq(sys->actors[i],0);
 }
 placement.x=128; placement.y=96;
 for(i=31;i<34;i++) {
  placement.depth=i-30;
  sys->actors[i]=CLACT_CreateActor(sys->unit,sys->countdownCharacter,sys->countdownPalette,sys->countdownCellAnim,&placement,0,heapId);
  CLACT_SetActorDrawEnable(sys->actors[i],0);
  CLACT_SetActorPaletteOffset(sys->actors[i],0,1);
 }
}

void IRC_RHYTHM_ExitActorSystem(IrcActorSystem *sys) { int i; for(i=0;i<35;i++) if(sys->actors[i]) CLACT_DeleteActor(sys->actors[i]); CLACT_ReleasePalette(sys->particlePalette); CLACT_ReleaseCharacter(sys->particleCharacter); CLACT_ReleaseCellAnim(sys->particleCellAnim); CLACT_ReleasePalette(sys->subParticlePalette); CLACT_ReleaseCharacter(sys->subParticleCharacter); CLACT_ReleaseCellAnim(sys->subParticleCellAnim); CLACT_ReleasePalette(sys->countdownPalette); CLACT_ReleaseCharacter(sys->countdownCharacter); CLACT_ReleaseCellAnim(sys->countdownCellAnim); CLACT_DeleteUnit(sys->unit); CLACT_ExitSystem(); MI_CpuFill8(sys,0,0xb4); }

/*
 * Thumb long-branch veneer in a .word run:
 *   ldr r3,[pc,#0]; bx r3; .word 0x0204A600
 * Declared as an ordinary tail-call extern at the veneer address.
 */
void IRC_RHYTHM_DrawActorSystem(void *unused)
{
    CLACT_DrawSystem();
}

void IRC_RHYTHM_VBlankActorSystem(void *unused) { CLACT_VBlankSystem(); }

/*
 * Unlabelled leaf accessor, witness for the thunk IRC_RHYTHM_GetScreenActor.
 */
struct Obj *IRC_RHYTHM_GetActor(IrcActorSystem *sys, int index)
{
    return sys->actors[index];
}

/*
 * First-word accessor.
 */
struct Bank *IRC_RHYTHM_GetActorUnit(IrcActorSystem *sys)
{
    return sys->unit;
}

/* ---- text system and text windows ---- */

void IRC_RHYTHM_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId) {
 MI_CpuFill8(text,0,0x10);
 func_0201DD60();
 switch (fontStyle) {
 case 0:
  text->font=GF_FONT_Create(0x17,0,0,0,heapId);
  break;
 case 1:
  text->font=GF_FONT_Create(0x17,1,0,0,heapId);
  break;
 }
 text->printQueue=PRINTSYS_QUE_Create(heapId);
 text->messages=func_02045B38(0,2,0x34,heapId);
 text->wordSet=func_0201EC64(heapId);
 func_02049B40(0x17,5,4,0x1C0,0x20,heapId);
 func_02049B40(0x17,5,0,0x1C0,0x20,heapId);
}

void IRC_RHYTHM_ExitTextSystem(IrcTextSystem *text) { func_0201ED04(text->wordSet); MSGDATA_Delete(text->messages); PRINTSYS_QUE_Delete(text->printQueue); GF_FONT_Delete(text->font); MI_CpuFill8(text,0,16); }

int IRC_RHYTHM_RunPrintQueue(IrcTextSystem *text) { return PRINTSYS_QUE_Main(text->printQueue); }

void *IRC_RHYTHM_GetFont(IrcTextSystem *text)
{
    return text->font;
}

void *IRC_RHYTHM_GetPrintQueue(IrcTextSystem *text)
{
    return text->printQueue;
}

/*
 * four getters at +0, +8, +4, +c.
 */
void *IRC_RHYTHM_GetMessages(IrcTextSystem *text)
{
    return text->messages;
}

void *IRC_RHYTHM_GetWordSet(IrcTextSystem *text)
{
    return text->wordSet;
}

void IRC_RHYTHM_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId)
{
    void *window;
    MI_CpuFill8(win, 0, 0x14);
    win->clearColor = 15;
    win->window = BMP_WIN_Create(layer, x, y, width, height, paletteNo, 1);
    win->buffer = STRBUF_Create(0xff, heapId);
    win->printTarget = win->window;
    win->isPrinting = 0;
    IRC_RHYTHM_ClearTextWindow(win);
    window = win->window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_020409B4(BMP_WIN_GetBgLayer(window));
}

/*
 * lever: y and its callee parameter are u8; u32 hoists its spill reload.
 */
void IRC_RHYTHM_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId) { void *window; MI_CpuFill8(win,0,0x14); win->clearColor=clearColor; win->window=BMP_WIN_Create(layer,x,y,width,height,paletteNo,slot); win->buffer=STRBUF_Create(0xff,heapId); win->printTarget=win->window; win->isPrinting=0; BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor); window=win->window; BMP_WIN_TransferChars(window); BMP_WIN_MakeScreen(window); func_020409B4(BMP_WIN_GetBgLayer(window)); }

void IRC_RHYTHM_ExitTextWindow(IrcTextWindow *win) { STRBUF_Delete(win->buffer); BMP_WIN_Delete(win->window); MI_CpuFill8(win,0,20); }

int IRC_RHYTHM_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text) { void *printQueue; printQueue=text->printQueue; if(win->isPrinting) { if(!PRINTSYS_QUE_IsExistTarget(printQueue,BMP_WIN_GetBmp(win->printTarget))) { BMP_WIN_TransferChars(win->printTarget); win->isPrinting=0; } } if(!win->isPrinting) return 1; return 0; }

void IRC_RHYTHM_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y) { void *messages; void *printQueue; void *font; messages=IRC_RHYTHM_GetMessages(text); printQueue=IRC_RHYTHM_GetPrintQueue(text); font=IRC_RHYTHM_GetFont(text); BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor); func_02045CAC(messages,msgId,win->buffer); PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),(s16)x,y,win->buffer,font); win->isPrinting=1; }

void IRC_RHYTHM_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId) { IRC_RHYTHM_PrintCenteredMessageColor(win,text,msgId,0x3dc4); }

void IRC_RHYTHM_PrintCenteredMessageColor(IrcTextWindow *win,IrcTextSystem *text,int msgId,u16 color) { void *messages; void *printQueue; void *font; u16 x; u16 y; messages=IRC_RHYTHM_GetMessages(text); printQueue=IRC_RHYTHM_GetPrintQueue(text); font=IRC_RHYTHM_GetFont(text); BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor); func_02045CAC(messages,msgId,win->buffer); x=BMP_WIN_GetWidth(win->window)*4; y=BMP_WIN_GetHeight(win->window)*4; x-=(u16)(func_0201D304(win->buffer,font,0)/2); y-=(u16)(func_0201D42C(win->buffer,font)/2); PRINTSYS_PrintQueColor(printQueue,BMP_WIN_GetBmp(win->printTarget),(s16)x,(s16)y,win->buffer,font,color); win->isPrinting=1; }

void IRC_RHYTHM_PrintMessageWithName(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *profile, s16 x, s16 y, u16 unused) { void *wordSet; void *messages; void *string; void *printQueue; void *font; BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor); wordSet=IRC_RHYTHM_GetWordSet(text); messages=IRC_RHYTHM_GetMessages(text); func_0201F02C(wordSet,0,profile->myStatus); string=func_02045EC0(messages,msgId); func_0201F250(wordSet,win->buffer,string); STRBUF_Delete(string); printQueue=IRC_RHYTHM_GetPrintQueue(text); font=IRC_RHYTHM_GetFont(text); PRINTSYS_PrintQue(printQueue,BMP_WIN_GetBmp(win->printTarget),x,y,win->buffer,font); win->isPrinting=1; }

void IRC_RHYTHM_ClearTextWindow(IrcTextWindow *win) { BMP_Clear(BMP_WIN_GetBmp(win->window),win->clearColor); BMP_WIN_TransferChars(win->window); }

/* ---- countdown ---- */

void IRC_RHYTHM_InitCountdown(IrcRhythmCountdown *countdown, IrcScreen *screen, int unused) { int i; MI_CpuFill8(countdown,0,0x1c); for(i=0;i<3;i++) countdown->actor=IRC_RHYTHM_GetScreenActor(screen,i+IRC_RHYTHM_ACTOR_COUNTDOWN); }

void IRC_RHYTHM_ExitCountdown(IrcRhythmCountdown *countdown) { MI_CpuFill8(countdown, 0, 0x1c); }

void IRC_RHYTHM_UpdateCountdown(IrcRhythmCountdown *countdown) { if(countdown->running) { if(countdown->frames==0) { GFL_USE_PlaySeDefaultVolume(IRC_RHYTHM_SE_COUNTDOWN); CLACT_SetActorDrawEnable(countdown->actor,1); CLACT_SetActorAnimSeq(countdown->actor,4-countdown->step); } if(countdown->frames++>=60) { countdown->frames=0; countdown->step++; } if(countdown->step==3) { GFL_USE_PlaySeDefaultVolume(IRC_RHYTHM_SE_GO); countdown->finished=1; countdown->running=0; CLACT_SetActorDrawEnable(countdown->actor,0); } } }

void IRC_RHYTHM_StartCountdown(IrcRhythmCountdown *countdown) { countdown->frames = 0; countdown->step = 0; countdown->running = 1; }

u32 IRC_RHYTHM_IsCountdownFinished(IrcRhythmCountdown *countdown) { return countdown->finished; }

/* ---- state machine ---- */

void IRC_RHYTHM_SetState(IrcRhythm *work, IrcRhythmStateFn fn) {
    work->stateFn = fn;
    work->stateStep = 0;
}

void IRC_RHYTHM_Finish(IrcRhythm *work) { work->finished = 1; }

void IRC_RHYTHM_StateIntro(IrcRhythm *work,u16 *step) { switch(*step) { case 0: work->waitFrames=0; *step=1; break; case 1: func_02040588(2,0); *step=3; break; case 3: IRC_RHYTHM_StartCountdown(&work->countdown); IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateCountdown); break; } if(IRC_APPBAR_GetResult(work->appBar)==1) { work->context->status=IRC_RHYTHM_STATUS_CANCELLED; IRC_RHYTHM_Finish(work); } if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)!=0) IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateAbort); }

void IRC_RHYTHM_StateCountdown(IrcRhythm *work,u16 *step) { IRC_RHYTHM_UpdateCountdown(&work->countdown); if(IRC_RHYTHM_IsCountdownFinished(&work->countdown)) { work->blendResetPending=1; IRC_RHYTHM_StartRecord(&work->record); IRC_RHYTHM_StartPulse(&work->pulse); IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateTapping); } if(IRC_APPBAR_GetResult(work->appBar)==1) { work->context->status=IRC_RHYTHM_STATUS_CANCELLED; IRC_RHYTHM_Finish(work); } if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)!=0) IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateAbort); }

/*
 * stand-in: the record offset lives in an enum local and three fields are
 * reached as (record offset + distance).  The compiler then keeps one
 * register for the far offset, which the original code does; the same fields
 * written as work->field load their own constants and change the schedule.
 */
typedef enum { RECORD_BASE = 0x814 } RecordBase;
#define OFFSET_OF(type, field) ((int)&((type *)0)->field)
#define FAR_FIELD(type, field) (*(type *)((u8 *)work + (base + (OFFSET_OF(IrcRhythm, field) - RECORD_BASE))))
#define RECORD_AT_BASE ((IrcRhythmRecord *)((u8 *)work + base))

void IRC_RHYTHM_StateTapping(IrcRhythm *work,u16 *step) {
 RecordBase base=RECORD_BASE;
 IrcPoint point;
 FAR_FIELD(u32, tappedThisFrame)=0;
 if(!IRC_APPBAR_IsBusy(FAR_FIELD(IrcAppBar *, appBar))) {
  if(IRC_RHYTHM_GetTouchTap(&point)) {
   IRC_RHYTHM_SpawnBurst(&work->particles,&point,IRC_RHYTHM_JudgeTap(RECORD_AT_BASE));
   if(!FAR_FIELD(u16, resultStep)) IRC_RHYTHM_RecordTap(RECORD_AT_BASE);
   work->tappedThisFrame=1;
  }
 }
 if(IRC_RHYTHM_IsRecordFull(RECORD_AT_BASE)) {
  if(!work->resultStarted) {
   IRC_RHYTHM_PrintMessage(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_TAPS_DONE,0,0);
   GFL_USE_PlaySeDefaultVolume(IRC_RHYTHM_SE_TAPS_DONE);
   work->resultStarted=1;
  }
  if(work->resultStarted) IRC_RHYTHM_StateResult(work,&work->resultStep);
 }
 if(!work->resultStarted) {
  if(IRC_APPBAR_GetResult(work->appBar)==1) { work->context->status=IRC_RHYTHM_STATUS_CANCELLED; IRC_RHYTHM_Finish(work); }
  if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)) IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateAbort);
 }
}

void IRC_RHYTHM_StateResult(IrcRhythm *work,u16 *step) {
 IrcRhythmRecord partnerRecord; int diff;
 if(*step<5 && IRC_APPBAR_GetResult(work->appBar)==1) {
  COMPATIBLE_IRC_SYS_ResetStep(work->context->ircSys);
  work->context->status=IRC_RHYTHM_STATUS_CANCELLED;
  IRC_RHYTHM_Finish(work);
  return;
 }
 switch(*step) {
 case 0: if(COMPATIBLE_IRC_SYS_StepShareValue(work->context->ircSys,2)) *step=1; break;
 case 1: IRC_RHYTHM_PrintMessage(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_WAITING,0,0); *step=2; break;
 case 2: if(IRC_RHYTHM_SendRecord(&work->netSync, &work->record)) *step=3; break;
 case 3: COMPATIBLE_IRC_SYS_SetOwnValue(work->context->ircSys,2); if(COMPATIBLE_IRC_SYS_SendOwnValue(work->context->ircSys)) *step=4; break;
 case 4: if(COMPATIBLE_IRC_SYS_StepShareValue(work->context->ircSys,3)) { IRC_APPBAR_SetActive(work->appBar,0); *step=5; } break;
 case 5: if(work->waitFrames>=60) { GFL_USE_PlaySeDefaultVolume(IRC_RHYTHM_SE_RESULT); IRC_RHYTHM_PrintMessage(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_RESULT,0,0); *step=6; } break;
 case 6:
  if((work->resultTimer)++<30) return;
  work->context->score=IRC_RHYTHM_CalcSyncScore(work);
  IRC_RHYTHM_GetPartnerRecord(&work->netSync, &partnerRecord);
  diff=work->record.extraTaps-partnerRecord.extraTaps;
  if(diff<0) diff=-diff;
  work->context->tapCountDifference=diff;
  work->context->status=IRC_RHYTHM_STATUS_DONE;
  *step=7; return;
 case 7: IRC_RHYTHM_Finish(work); return;
 }
 if(*step>=1 && *step<=5) { if(work->waitFrames<=60) ++work->waitFrames; }
 if(*step<3) { if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)) IRC_RHYTHM_SetState(work,IRC_RHYTHM_StateAbort); }
}

/*
 * extent: 174 code bytes then two zero alignment bytes before 021B85D8.
 */
void IRC_RHYTHM_StateAbort(IrcRhythm *work,u16 *step) { switch(*step) { case 0: if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)>0) { work->context->score=0; work->context->status=IRC_RHYTHM_STATUS_CANCELLED; IRC_RHYTHM_Finish(work); return; } if(COMPATIBLE_IRC_SYS_GetValueDifference(work->context->ircSys)<0) *step=1; break; case 1: work->context->score=0; work->context->status=IRC_RHYTHM_STATUS_PARTNER_LEFT; *step=2; break; case 2: IRC_RHYTHM_PrintMessage(&work->messageWindow,&work->text,IRC_RHYTHM_MSG_PARTNER_LEFT,0,0); *step=3; break; case 3: if(COMPATIBLE_IRC_SYS_StepShareValue(work->context->ircSys,6)) *step=4; break; case 4: IRC_RHYTHM_Finish(work); break; } }

/* ---- tap record ---- */

void IRC_RHYTHM_InitRecord(IrcRhythmRecord *record) { MI_CpuFill8(record, 0, 0x84); }

void IRC_RHYTHM_StartRecord(IrcRhythmRecord *record) { if(OS_IsTickAvailable()) OS_InitTick(); *(unsigned long long *)record->startTime=(func_020870D0()<<6)/33514; }

int IRC_RHYTHM_IsRecordFull(IrcRhythmRecord *record) { if(record->tapCount>=10) return 1; return 0; }

void IRC_RHYTHM_RecordTap(IrcRhythmRecord *record) { if(record->tapCount<10) { record->taps[record->tapCount].time=(func_020870D0()<<6)/33514-*(unsigned long long *)record->startTime; if(record->tapCount==0) record->taps[record->tapCount].interval=0; else record->taps[record->tapCount].interval=record->taps[record->tapCount].time-record->taps[record->tapCount-1].time; ++record->tapCount; } else if(record->extraTaps<99) ++record->extraTaps; }

static inline int magnitude(int x) { return x<0 ? -x : x; }

int IRC_RHYTHM_JudgeTap(IrcRhythmRecord *record) {
 int diff; int result; int sound; u16 n;
 n=record->tapCount;
 if(n<2) { sound=IRC_RHYTHM_SE_TAP_STEADY; result=3; }
 else {
  diff=record->taps[n-1].interval-record->taps[n-2].interval;
  if(magnitude(diff)>=0 && magnitude(diff)<50) {sound=IRC_RHYTHM_SE_TAP_STEADY;result=3;}
  else if(diff<0) {
   if(magnitude(diff)<200) {sound=IRC_RHYTHM_SE_TAP_FASTER;result=1;} else {sound=IRC_RHYTHM_SE_TAP_MUCH_FASTER;result=0;}
  } else {
   if(magnitude(diff)<200) {sound=IRC_RHYTHM_SE_TAP_SLOWER;result=5;} else {sound=IRC_RHYTHM_SE_TAP_MUCH_SLOWER;result=6;}
  }
 }
 GFL_USE_PlaySeDefaultVolume(sound); return result;
}

/* ---- record exchange over the infrared link ---- */

void IRC_RHYTHM_InitNetSync(IrcRhythmNetSync *sync,IrcSys *ircSys) { MI_CpuFill8(sync,0,0x198); sync->ircSys=ircSys; COMPATIBLE_IRC_SYS_AddCommandTable(ircSys,IRC_RHYTHM_NET_COMMAND_BASE,(u32)sRhythmNetCommandTable,1,(u32)sync); }

void IRC_RHYTHM_ExitNetSync(IrcRhythmNetSync *sync) { COMPATIBLE_IRC_SYS_DeleteCommandTable(sync->ircSys,IRC_RHYTHM_NET_COMMAND_BASE); MI_CpuFill8(sync,0,0x198); }

/*
 * extent: Two zero alignment bytes at 021B87F2 before 021B87F4.
 */
int IRC_RHYTHM_SendRecord(IrcRhythmNetSync *sync,const IrcRhythmRecord *record) {
 switch(sync->sendStep) {
 case 0: sync->sendBuffer=*record; sync->sendStep=1; break;
 case 1:
  if(COMPATIBLE_IRC_SYS_SendData(sync->ircSys,IRC_RHYTHM_NET_COMMAND_BASE,0x84,(u32)&sync->sendBuffer,(u8)(GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())==0),0,0,1)) sync->sendStep=2;
  break;
 case 2:
  if(sync->receivedFlag) { sync->receivedFlag=0; sync->sendStep=0; return 1; }
  break;
 }
 return 0;
}

/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void IRC_RHYTHM_GetPartnerRecord(IrcRhythmNetSync *sync,IrcRhythmRecord *out) { *out=sync->received[0]; }

void IRC_RHYTHM_OnRecordReceived(int aid,int size,int data,IrcRhythmNetSync *sync,void *handle) { if(handle==GFL_NET_HANDLE_GetCurrentHandle() && aid!=GFL_NET_SYSTEM_GetCurrentAid()) sync->receivedFlag=1; }

IrcRhythmRecord *IRC_RHYTHM_GetRecordReceiveBuffer(int aid,IrcRhythmNetSync *sync) { if(aid==GFL_NET_SYSTEM_GetCurrentAid()) return &sync->received[1]; else return &sync->received[0]; }

int IRC_RHYTHM_GetTouchTap(IrcPoint *out) { u32 x,y; if(TOUCHPANEL_GetPointTrg(&x,&y)) { if(x<=256 && y<=168) { out->x=x; out->y=y; return 1; } } return 0; }

/*
 * lever: Direct word indexing retains the second stack record's base across the call.
 */
int IRC_RHYTHM_CalcSyncScore(IrcRhythm *work) {
 IrcRhythmRecord own; IrcRhythmRecord partner; int d; u32 score, sum; int i;
 own=work->record;
 IRC_RHYTHM_GetPartnerRecord(&work->netSync, &partner);
 d=own.taps[own.tapCount-1].time-own.taps[0].time
  -(partner.taps[partner.tapCount-1].time-partner.taps[0].time);
 if(d<0) d=-d;
 if(d==0) score=100;
 else if((u32)d<500) score=90;
 else if((u32)d<1000) score=80;
 else if((u32)d<3000) score=70;
 else if((u32)d<5000) score=60;
 else if((u32)d<10000) score=50;
 else if((u32)d<15000) score=40;
 else if((u32)d<20000) score=30;
 else if((u32)d<25000) score=20;
 else if((u32)d<30000) score=10;
 sum=0;
 for(i=1;i<10;i++) {
  d=own.taps[i].interval-partner.taps[i].interval;
  if(d<0) d=-d;
  if(d==0) sum+=100;
  else if((u32)d<50) sum+=90;
  else if((u32)d<100) sum+=80;
  else if((u32)d<200) sum+=70;
  else if((u32)d<300) sum+=60;
  else if((u32)d<400) sum+=50;
  else if((u32)d<500) sum+=40;
  else if((u32)d<600) sum+=30;
  else if((u32)d<1000) sum+=20;
  else if((u32)d<15000) sum+=10;
 }
 return (u8)((score+sum/9)/2);
}

/* ---- background colour pulse ---- */

static inline u16 blend(int angle,u16 from,u16 to) {
 u8 fromGreen,fromRed,fromBlue; int deltaBlue,deltaRed,deltaGreen; s16 factor;
 fromGreen=(from&0x3e0)>>5;
 factor=(s16)((FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2);
 fromRed=from&31;
 fromBlue=(from&0x7c00)>>10;
 deltaBlue=(factor*((u8)((to&0x7c00)>>10)-fromBlue))>>12;
 deltaRed=(factor*((u8)(to&31)-fromRed))>>12;
 deltaGreen=(factor*((u8)((to&0x3e0)>>5)-fromGreen))>>12;
 return ((u8)(fromBlue+deltaBlue)<<10)|((u8)(fromRed+deltaRed)|((u8)(fromGreen+deltaGreen)<<5));
}

/*
 * lever: Byte RGB endpoints and named signed deltas, with the
 * cosine factor computed after green extraction, retain channel lifetimes.
 * Evidence: ov105_func_021B8734 blend spelling and own ARM9 queue body.
 */
int IRC_RHYTHM_BlendPaletteEntry(u32 target,u16 *color,int angle,int paletteBank,u8 colorIndex,u16 from,u16 to) {
 *color=blend(angle,from,to);
 return func_02061CA4(target,paletteBank*32+colorIndex*2,color,2);
}

/* ---- particles ---- */

void IRC_RHYTHM_InitParticles(IrcRhythmParticles *particles,IrcScreen *screen,int mode,int firstActor,int surface) {
 int i;
 MI_CpuFill8(particles,0,0x534); particles->mode=mode;
 particles->spawnTimer=0; particles->spawnInterval=10;
 for(i=0;i<30;i++) IRC_RHYTHM_InitParticle(&particles->particles[i],IRC_RHYTHM_GetScreenActor(screen,firstActor+i),surface);
}

void IRC_RHYTHM_ExitParticles(IrcRhythmParticles *particles) { MI_CpuFill8(particles,0,0x534); }

static inline void initialize(IrcPoint *start,IrcPoint *end,int x,int endY)
{
    int yy=endY;
    end->y=yy;
    start->x=end->x=x;
    start->y=228;

}

/*
 * lever: named end-Y local stored before the shared X assignment yields the original 336-byte schedule.
 */
void IRC_RHYTHM_UpdateParticles(IrcRhythmParticles *particles)
{
    IrcPoint end,start;
    int i,angle;
    u32 life;
    u8 palette;
    u8 direction;
    switch(particles->mode) {
    case IRC_RHYTHM_PARTICLES_FALL:
        if(particles->spawnTimer++>particles->spawnInterval) {
            particles->spawnTimer=0;
            for(i=0;i<30;++i) {
                if(!IRC_RHYTHM_IsParticleActive(&particles->particles[i])) {
                    direction=func_020056EC(2);
                    initialize(&start,&end,func_020056EC(256),-36);
                    life=func_020056EC(50)+110;
                    palette=2;
                    if(func_020056EC(2)) palette=5;
                    if(direction) IRC_RHYTHM_StartParticle(&particles->particles[i], &start, &end, palette, life);
                    else IRC_RHYTHM_StartParticle(&particles->particles[i], &end, &start, palette, life);
                    break;
                }
            }
        }
        break;
    case IRC_RHYTHM_PARTICLES_OFF: break;
    case IRC_RHYTHM_PARTICLES_BURST:
        if(particles->spawnTimer++>particles->spawnInterval) {
            particles->spawnTimer=0;
            for(i=0;i<30;++i) {
                if(!IRC_RHYTHM_IsParticleActive(&particles->particles[i])) {
                    angle=(u16)func_020056EC(65535)>>4;
                    end.x=FX_SCALE_RADIUS(FX_SinCosTable_[angle*2])>>12;
                    end.y=FX_SCALE_RADIUS(FX_SinCosTable_[angle*2+1])>>12;
                    start.x=128;start.y=96;
                    life=func_020056EC(50)+110;
                    palette=2;
                    if(func_020056EC(2)) palette=5;
                    IRC_RHYTHM_StartParticle(&particles->particles[i], &end, &start, palette, life);
                    break;
                }
            }
        }
        break;
    }
    for(i=0;i<30;++i) IRC_RHYTHM_UpdateParticle(&particles->particles[i]);
}

void IRC_RHYTHM_SpawnBurst(IrcRhythmParticles *particles, const IrcPoint *center, int palette)
{
    VecFx32 origin, random, delta;
    IrcPoint end;
    int outer, i, angle, rawY;
    origin.x=FX_FROM_INT(center->x);
    origin.y=FX_FROM_INT(center->y);
    origin.z=0;
    for(outer=0;outer<12;++outer) {
        for(i=0;i<30;++i) {
            if(!IRC_RHYTHM_IsParticleActive(&particles->particles[i])) {
                angle=(u16)func_020056EC(65535)>>4;
                end.x=FX_SCALE_RADIUS(FX_SinCosTable_[angle*2])>>12;
                end.y=FX_SCALE_RADIUS(FX_SinCosTable_[angle*2+1])>>12;
                random.x=FX_FROM_INT(end.x);
                random.y=FX_FROM_INT(end.y);
                random.z=0;
                func_0207CA00(&random,&origin,&delta);
                VEC_Normalize(&delta,&delta);
                rawY=delta.y;
                end.x=FX_SCALE_RADIUS(delta.x)>>12;
                end.y=FX_SCALE_RADIUS(rawY)>>12;
                end.x+=center->x;
                end.y+=center->y;
                IRC_RHYTHM_StartParticle(&particles->particles[i], center, &end, palette, func_020056EC(5)+40);
                break;
            }
        }
    }
}

void IRC_RHYTHM_InitParticle(IrcRhythmParticle *particle, struct Obj *actor, int surface) { MI_CpuFill8(particle,0,44); particle->actor=actor; particle->surface=surface; }

/*
 * extent: Two zero alignment bytes at 021B8DA2 before 021B8DA4.
 * lever: Declare delta before pos; multiply length by counter in that order.
 */
void IRC_RHYTHM_UpdateParticle(IrcRhythmParticle *particle) {
 u16 xy[2]; VecFx32 delta; VecFx32 pos; int length;
 if(particle->active) {
  func_0207CA00(&particle->end,&particle->start,&delta);
  length=func_0207CBD0(&delta); VEC_Normalize(&delta,&delta);
  func_0207CEE4((u32)(length * particle->counter)/ particle->lifetime,&delta,&particle->start,&pos);
  xy[0]=pos.x>>12; xy[1]=pos.y>>12;
  if((particle->counter)++ > particle->lifetime) {
   xy[0]=particle->end.x; xy[1]=particle->end.y;
   CLACT_SetActorDrawEnable(particle->actor,0); particle->active=0;
  }
  CLACT_AddActorSurfacePos(particle->actor,(const struct Vec2 *)xy,(u16)(particle->surface));
 }
}

static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt(FX_FROM_INT(v)));
    else
        f = _fsub(_fflt(FX_FROM_INT(v)), 0.5f);
    return _ffix(f);
}

/*
 * Evidence: 44-byte particle layout from ov104_func_021B8D20; float
 * runtime identities from matched CLACT_ApplyActorTransform; object callees from
 * their own matched units. Unsigned shifts preserve 32-bit wrapping;
 * explicit runtime conversion retains all signed input values.
 */
void IRC_RHYTHM_StartParticle(IrcRhythmParticle *particle, const IrcPoint *start, const IrcPoint *end, int palette, u32 lifetime)
{
    int startY, endY;
    particle->active = 1;
    startY = convert(start->y);
    particle->start.x = convert(start->x);
    particle->start.z = 0;
    particle->start.y = startY;
    endY = convert(end->y);
    particle->end.x = convert(end->x);
    particle->end.z = 0;
    particle->counter = 0;
    particle->lifetime = lifetime;
    particle->end.y = endY;
    CLACT_SetActorDrawEnable(particle->actor, 1);
    CLACT_SetActorPaletteOffset(particle->actor, (u8)palette, 1);
}

u32 IRC_RHYTHM_IsParticleActive(IrcRhythmParticle *particle) { return particle->active; }

/* ---- pulse ---- */

void IRC_RHYTHM_InitPulse(IrcRhythmPulse *pulse, int unused)
{
    MI_CpuFill8(pulse, 0, 16);
    pulse->enabled = 1;
}

void IRC_RHYTHM_ExitPulse(IrcRhythmPulse *pulse) { MI_CpuFill8(pulse, 0, 0x10); }

void IRC_RHYTHM_UpdatePulse(IrcRhythmPulse *pulse) {
 int phase;
 if(pulse->running && pulse->enabled) {
  phase=pulse->phase+0x400;
  if(phase>=0x10000) pulse->phase=pulse->phase-0xfc00;
  else pulse->phase=phase;
  IRC_RHYTHM_BlendPaletteEntry(IRC_PALETTE_TARGET,&pulse->color,pulse->phase,5,3,0x6adf,0x55fe);
 }
}

void IRC_RHYTHM_StartPulse(IrcRhythmPulse *pulse)
{
    pulse->running = 1;
}

/*
 * volatile: BLDCNT at 04000050, the hardware halfword store at 021B8F16.
 */
void IRC_RHYTHM_ClearBlendTask(void *task,void *arg) {
 IrcRhythm *work=arg;
 if(work->blendResetPending) {
  work->blendResetPending=0;
  REG_BLDCNT=0;
 }
}
