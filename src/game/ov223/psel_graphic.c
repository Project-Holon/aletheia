/*
 * file:     psel_graphic.c
 * unit:     yes
 * function: PSEL_GRAPHIC_OpenMenu, PSEL_GRAPHIC_GetMenuChoice, PSEL_GRAPHIC_SplitColor, PSEL_GRAPHIC_LoadFadeSources, PSEL_GRAPHIC_NopFade, PSEL_GRAPHIC_StepFade, PSEL_GRAPHIC_LoadPaletteBuffers, PSEL_GRAPHIC_NopBlend, PSEL_GRAPHIC_BlendPalettes, PSEL_GRAPHIC_InitFadePalettes, PSEL_GRAPHIC_UpdateFadeNop, PSEL_GRAPHIC_UpdateFade, PSEL_GRAPHIC_SetRecordState, PSEL_GRAPHIC_SetFadeSource, PSEL_GRAPHIC_IsReady, PSEL_GRAPHIC_Init, PSEL_GRAPHIC_InitSelect, PSEL_GRAPHIC_StateFadeIn, PSEL_GRAPHIC_StateFadeAnim, PSEL_GRAPHIC_StateFadeOut, PSEL_GRAPHIC_StateExit, PSEL_GRAPHIC_StateEnter, PSEL_GRAPHIC_StateRun, PSEL_GRAPHIC_Main, PSEL_GRAPHIC_StateEnd, PSEL_GRAPHIC_StateCleanup, PSEL_GRAPHIC_Delete, PSEL_GRAPHIC_GetMaxState, PSEL_GRAPHIC_G3dCallback, PSEL_GRAPHIC_Create, PSEL_GRAPHIC_Destroy, PSEL_GRAPHIC_Draw, PSEL_GRAPHIC_ApplyLight, PSEL_GRAPHIC_DrawEnd, PSEL_GRAPHIC_GetClactBank, PSEL_GRAPHIC_GetCamera, PSEL_GRAPHIC_VBlank, PSEL_GRAPHIC_InitBg, PSEL_GRAPHIC_ExitBg, PSEL_GRAPHIC_NopDraw, PSEL_GRAPHIC_UpdateBg, PSEL_GRAPHIC_InitClact, PSEL_GRAPHIC_ExitClact, PSEL_GRAPHIC_ClactDraw, PSEL_GRAPHIC_ClactVBlank, PSEL_GRAPHIC_LoadWord, PSEL_GRAPHIC_InitG3d, PSEL_GRAPHIC_ExitG3d, PSEL_GRAPHIC_ApplyLookAt, PSEL_GRAPHIC_G3dDrawEnd, PSEL_GRAPHIC_LoadWordC6F8
 * address:  0x021BB450
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   d_021BC73C 0x021BC73C data a1
 *   d_021BC6FC 0x021BC6FC data a1
 *   d_021BC708 0x021BC708 data a1
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PSEL_Task 0x021B9740 thumb ov223
 *   PSEL_CreateG3dUtil 0x021B9830 thumb ov223
 *   PSEL_CreateBmpWindows 0x021BAAB8 thumb ov223
 *   PSEL_CreateWin 0x021BAE00 thumb ov223
 *   PSEL_CreateTaskRes 0x021BB38C thumb ov223
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   PSEL_SetupListAnime 0x021B9854 thumb ov223
 *   PSEL_InitBgLayers 0x021BAB78 thumb ov223
 *   PSEL_DeleteBgLayers 0x021BAC0C thumb ov223
 *   PSEL_ClearWin2 0x021BB2A4 thumb ov223
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   PSEL_UpdateListAnime 0x021B9914 thumb ov223
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PSEL_ClearWin3 0x021BB35C thumb ov223
 *   PSEL_NopBgDelete 0x021BAC6C thumb ov223
 *   PSEL_IsBgReady 0x021BABFC thumb ov223
 *   PSEL_DeleteListAnime 0x021B98F4 thumb ov223
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   PSEL_SetupSelectAnime 0x021B99A0 thumb ov223
 *   PSEL_CreateUnits 0x021B9D9C thumb ov223
 *   PSEL_CreateUnits2 0x021BA984 thumb ov223
 *   PSEL_SetBgSys 0x021BAC70 thumb ov223
 *   PSEL_UploadBgPalette 0x021BAD80 thumb ov223
 *   PSEL_UpdateUnitAnime 0x021B9D4C thumb ov223
 *   PSEL_UpdateUnitPositions 0x021BA2B4 thumb ov223
 *   PSEL_UpdateSelectAnime 0x021B9A8C thumb ov223
 *   PSEL_UpdateUnitAnime2 0x021BA8D0 thumb ov223
 *   PSEL_SetMode 0x021BAFC4 thumb ov223
 *   PSEL_UpdateFadeUnit 0x021BA878 thumb ov223
 *   PSEL_IsModeDone 0x021BB0B0 thumb ov223
 *   PSEL_IsUnitAnimDone 0x021BA8BC thumb ov223
 *   PSEL_SetActorPosition 0x021BAA5C thumb ov223
 *   PSEL_UpdateActorPosition 0x021BAA84 thumb ov223
 *   PSEL_SelectUnit 0x021B9C90 thumb ov223
 *   PSEL_SetUnitVisible 0x021BA81C thumb ov223
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   PSEL_ShowTaskRes 0x021BB3BC thumb ov223
 *   PSEL_UpdateTaskResWin 0x021BB414 thumb ov223
 *   PSEL_SetTaskResActive 0x021BB424 thumb ov223
 *   PSEL_DeleteTaskRes 0x021BB404 thumb ov223
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   PSEL_IsTaskResFinished 0x021BB440 thumb ov223
 *   PSEL_SetAnimTarget 0x021B9AE4 thumb ov223
 *   PSEL_StepAnim 0x021B9B80 thumb ov223
 *   PSEL_IsAnimTargetReached 0x021B9B4C thumb ov223
 *   UI_SetInputMode 0x020355D8 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   PSEL_UpdateSubWindow 0x021BB134 thumb ov223
 *   PSEL_SetAnimTargetIndex 0x021B9C00 thumb ov223
 *   PSEL_StepAnimIndex 0x021B9C58 thumb ov223
 *   PSEL_ClearWin 0x021BB274 thumb ov223
 *   PSEL_PrintSubWindow 0x021BB18C thumb ov223
 *   PM_VOICE_Play 0x02006984 thumb
 *   d_021BC75C 0x021BC75C data a4
 *   d_021BC794 0x021BC794 data a2
 *   d_021BC710 0x021BC710 data a2
 *   PSEL_NopBgUpdate 0x021BADFC thumb ov223
 *   PSEL_ClearBgLayerEx 0x021BAD68 thumb ov223
 *   PSEL_DeleteActors 0x021BAA30 thumb ov223
 *   PSEL_DeleteUnits 0x021BA050 thumb ov223
 *   PSEL_DeleteSelectAnime 0x021B9A6C thumb ov223
 *   PSEL_DeleteTaskResData 0x021BB3AC thumb ov223
 *   PSEL_DeleteWin 0x021BAEE0 thumb ov223
 *   PSEL_NopBgWindows 0x021BAB74 thumb ov223
 *   PSEL_DeleteG3dUtil 0x021B9848 thumb ov223
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BC960 0x021BC960 data a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021BCB08 0x021BCB08 data a1
 *   d_021BC980 0x021BC980 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BC934 0x021BC934 data a4
 *   d_021BC9B0 0x021BC9B0 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BC944     0x021BC944  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021BC928 0x021BC928 data a4
 *   d_021BC91C 0x021BC91C data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   func_02047964  0x02047964  arm
 *   G3D_CAMERA_Reset    0x02048AD0  arm
 *   G3D_SYSTEM_ApplyLookAt    0x020479D8  arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 */
#include "psel_types.h"

struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct GfFont;
struct Main;
struct Node;
struct PrintSys;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
struct Light;
struct PselWork;

typedef struct Obj Obj;

struct Item { void *text; u16 color; unsigned value; };

struct TaskMenuTmpl {
    unsigned heapId;
    u8 count;
    u8 pad05[3];
    const void *unk08;
    unsigned unk0c;
    u8 pad10[2];
    u8 unk12;
    u8 unk13;
};

struct Ent { u8 a, b, c, d, e; };


struct Colors {u16 b2,g2,r2,b1,g1,r1;};

enum Offset {OffsetZero=0};

typedef enum { BIT8=8, BIT32=32 } Bits;

typedef enum { TOON, HIGHLIGHT } Shading;

struct Entry { unsigned id; char fields[32]; unsigned a,b; };

extern void *MSGDATA_AllocString(struct MsgBank *, unsigned);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *, void *);
extern void STRBUF_Delete(struct U16Vec *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
extern void APP_TASKMENU_UpdateMenu(Obj *);
extern unsigned APP_TASKMENU_IsFinish(struct TaskMenu *);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern u32 GFL_HEAP_Free(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern int NNS_GfdRegisterNewVramTransferTask(void *, unsigned, unsigned, int);
extern struct GfFont *GF_FONT_Create(int, int, int, int, unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
extern void BG_SYS_SetVisibleLayer(int, u16);
extern void *GFL_USE_AddMainTask(void (*)(void *, char *), void *, int);
extern void PSEL_Task(void *, char *);
extern void PSEL_CreateG3dUtil(char *);
extern void PSEL_CreateBmpWindows(u16 *p);
extern void PSEL_CreateWin(char *p);
extern void PSEL_CreateTaskRes(char *p);
extern void BG_SYS_LoadPlttEntry(unsigned, unsigned);
extern void PSEL_SetupListAnime(u8 *p);
extern void PSEL_InitBgLayers(u16 *p);
extern void PSEL_DeleteBgLayers(unsigned short *);
extern void PSEL_ClearWin2(char *p);
extern void G2x_SetBlendAlpha_(void *, unsigned, unsigned, unsigned, unsigned);
extern void PSEL_UpdateListAnime(char *p);
extern void FADE_Start(unsigned, int, int, int);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PSEL_ClearWin3(char *p);
extern void PSEL_DeleteListAnime(char *p);
extern void PSEL_NopBgDelete(unsigned char *);
extern int PSEL_IsBgReady(unsigned char *);
extern void BMP_SetDisplaySwap(u32 swap);
extern void PSEL_SetupSelectAnime(char *);
extern void PSEL_CreateUnits(char *);
extern void PSEL_CreateUnits2(char *);
extern void PSEL_SetBgSys(const u16 *p);
extern void PSEL_UploadBgPalette(u16 *p);
extern void PSEL_StepAnimIndex(char *);
extern void PSEL_UpdateSelectAnime(char *p);
extern void PSEL_UpdateUnitAnime(char *);
extern void PSEL_UpdateUnitPositions(struct Main *p);
extern void PSEL_UpdateUnitAnime2(char *);
extern void PSEL_SetMode(char *p, int idx);
extern void PSEL_UpdateFadeUnit(char *);
extern int PSEL_IsModeDone(char *),PSEL_IsUnitAnimDone(char *);
extern void PSEL_SetActorPosition(char *,int);
extern void PSEL_UpdateActorPosition(char *);
extern void PSEL_SelectUnit(char *,u32);
extern void PSEL_SetUnitVisible(char *,u32);
extern int TOUCHPANEL_HitTrg(const void *);
extern void PSEL_ShowTaskRes(char *),PSEL_UpdateTaskResWin(char *),PSEL_SetTaskResActive(char *),PSEL_DeleteTaskRes(char *),BG_SYS_SetFlagField06(u32);
extern u32 PSEL_IsTaskResFinished(char *);
extern void PSEL_SetAnimTarget(char *,int,int),PSEL_StepAnim(char *);
extern int PSEL_IsAnimTargetReached(char *);
extern void UI_SetInputMode(u32);
extern void PSEL_UpdateSubWindow(char *);
extern void PSEL_SetAnimTargetIndex(char *,u32);
extern void PSEL_ClearWin(char *);
extern void PSEL_PrintSubWindow(char *p, int idx);
extern u8 UI_GetInputMode(void);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern void PSEL_NopBgUpdate(char *);
extern void PSEL_ClearBgLayerEx(char *);
extern void PSEL_DeleteActors(char *);
extern void PSEL_DeleteUnits(char *);
extern void PSEL_DeleteSelectAnime(char *);
extern int PSEL_DeleteTaskResData(int *);
extern void PSEL_DeleteWin(char *p);
extern void PSEL_NopBgWindows(int *);
extern void PSEL_DeleteG3dUtil(int *);
extern void TCB_DeleteTask(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(unsigned short,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(int,int,int,int,int,int,void (*)(void));
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const int *,const int *,const int *,int);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern int G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
void PSEL_GRAPHIC_OpenMenu(char *work);
void PSEL_GRAPHIC_CloseMenu(char *work);
void PSEL_GRAPHIC_UpdateMenu(char *work);
unsigned PSEL_GRAPHIC_IsMenuFinished(char *work);
int PSEL_GRAPHIC_GetMenuChoice(int *work);
void PSEL_GRAPHIC_SplitColor(int v, unsigned short *a, unsigned short *b, unsigned short *c);
void PSEL_GRAPHIC_LoadFadeSources(u8 *work);
void PSEL_GRAPHIC_NopFade(void *a0);
void PSEL_GRAPHIC_StepFade(struct PselWork *work);
void PSEL_GRAPHIC_LoadPaletteBuffers(char *work);
void PSEL_GRAPHIC_NopBlend(void *a0);
void PSEL_GRAPHIC_BlendPalettes(char *work);
void PSEL_GRAPHIC_InitFadePalettes(char *work);
void PSEL_GRAPHIC_UpdateFadeNop(char *work);
void PSEL_GRAPHIC_UpdateFade(char *work);
void PSEL_GRAPHIC_SetRecordState(unsigned char *work,unsigned index,int cmd);
void PSEL_GRAPHIC_SetFadeSource(unsigned char *work,int value);
int PSEL_GRAPHIC_IsReady(void);
int PSEL_GRAPHIC_Init(char *work);
int PSEL_GRAPHIC_InitSelect(char *work);
int PSEL_GRAPHIC_StateFadeIn(char *work, int *state);
int PSEL_GRAPHIC_StateFadeAnim(char *work,u32 *state);
int PSEL_GRAPHIC_StateFadeOut(char *work, int *state);
int PSEL_GRAPHIC_StateExit(unsigned char *work);
int PSEL_GRAPHIC_StateEnter(char *work);
int PSEL_GRAPHIC_StateRun(char *work,unsigned *state);
int PSEL_GRAPHIC_Main(char *work,u32 *state);
int PSEL_GRAPHIC_StateEnd(char *work,unsigned *state);
int PSEL_GRAPHIC_StateCleanup(char *work);
int PSEL_GRAPHIC_Delete(int *work);
int PSEL_GRAPHIC_GetMaxState(void);
void PSEL_GRAPHIC_G3dCallback(void);
void *PSEL_GRAPHIC_Create(int a,int heap);
void PSEL_GRAPHIC_Destroy(unsigned *sys);
void PSEL_GRAPHIC_Draw(char *work);
void PSEL_GRAPHIC_ApplyLight(unsigned char *work);
void PSEL_GRAPHIC_DrawEnd(unsigned char *work);
unsigned PSEL_GRAPHIC_GetClactBank(unsigned char *work);
unsigned PSEL_GRAPHIC_GetCamera(unsigned char *work);
void PSEL_GRAPHIC_VBlank(void *unused, char *sys);
void PSEL_GRAPHIC_InitBg(void *sys,int heap);
void PSEL_GRAPHIC_ExitBg(void *work);
void PSEL_GRAPHIC_NopDraw(void *a0);
void PSEL_GRAPHIC_UpdateBg(void *a0);
void PSEL_GRAPHIC_InitClact(int *out, int a, int b);
void PSEL_GRAPHIC_ExitClact(char *bank);
void PSEL_GRAPHIC_ClactDraw(void *a0);
void PSEL_GRAPHIC_ClactVBlank(void *a0);
u32 PSEL_GRAPHIC_LoadWord(const u32 *work);
void PSEL_GRAPHIC_InitG3d(int *camera,int heap);
void PSEL_GRAPHIC_ExitG3d(int *camera);
void PSEL_GRAPHIC_ApplyLookAt(int *camera);
void PSEL_GRAPHIC_G3dDrawEnd(unsigned char *unused);
unsigned PSEL_GRAPHIC_LoadWordC6F8(unsigned char *work);
extern const struct Ent d_021BC73C[3];
extern const u8 d_021BC6FC[];
extern const u8 d_021BC708[];
extern const u8 d_021BC75C[];
extern const u16 d_021BC794[],d_021BC710[];
extern char d_021BC960[];
extern char d_021BCB08[];
extern unsigned d_021BC980[];
extern const unsigned d_021BC934[];
extern const struct Entry d_021BC9B0[];
extern int d_021BC944;
extern const short d_020A1EB8[];
extern int d_021BC91C[],d_021BC910[],d_021BC928[];

/*
 * The psel work object and the graphic-system helpers live in psel_types.h so
 * psel.c and psel_graphic.c share one owner struct.
 */







/*
 * Lead EXACT* ends at BB4D8; three 16-byte load/tail-call followers
 * complete the extent. Parent cleared these starts. The value local
 * assigns zero then conditionally one; a boolean expression reverses
 * the compare polarity. Template precedes items in declaration order.
 */
void PSEL_GRAPHIC_OpenMenu(char *work)
{
    struct TaskMenuTmpl tmpl;
    struct Item items[2];
    unsigned i;
    for (i = 0; i < 2; i++) {
        unsigned value;
        items[i].text = MSGDATA_AllocString(*(struct MsgBank * *)&((struct PselWork *)work)->msgBank, i + 22);
        items[i].color = 0x39E3;
        value = 0;
        if (i != 0)
            value = 1;
        items[i].value = value;
    }
    tmpl.heapId = ((struct PselWork *)work)->heapId;
    tmpl.count = 2;
    tmpl.unk0c = 1;
    tmpl.pad10[0] = 32;
    tmpl.pad10[1] = 17;
    tmpl.unk12 = 9;
    tmpl.unk13 = 3;
    tmpl.unk08 = items;
    *(struct TaskMenu * *)&((struct PselWork *)work)->taskMenu = APP_TASKMENU_OpenMenu(&tmpl, ((struct PselWork *)work)->taskRes);
    for (i = 0; i < 2; i++)
        STRBUF_Delete(items[i].text);
}







void PSEL_GRAPHIC_CloseMenu(char *work)
{
    APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct PselWork *)work)->taskMenu);
}







void PSEL_GRAPHIC_UpdateMenu(char *work)
{
    APP_TASKMENU_UpdateMenu(*(Obj * *)&((struct PselWork *)work)->taskMenu);
}







unsigned PSEL_GRAPHIC_IsMenuFinished(char *work)
{
    return APP_TASKMENU_IsFinish(*(struct TaskMenu * *)&((struct PselWork *)work)->taskMenu);
}








int PSEL_GRAPHIC_GetMenuChoice(int *work)
{
    return APP_TASKMENU_GetCursorPos((const u8 *)work[0x99]) == 0;
}







void PSEL_GRAPHIC_SplitColor(int v, unsigned short *a, unsigned short *b, unsigned short *c)
{
    *a = v & 0x1f;
    *b = (v & 0x3e0) >> 5;
    *c = (v & 0x7c00) >> 10;
}







void PSEL_GRAPHIC_LoadFadeSources(u8 *work)
{
    void *object = ARC_TOOL_CreateHandle(205, ((struct PselWork *)work)->heapId);
    u8 i;
    for (i = 0; i < 3; i++) {
        u8 *out;
        void *buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC73C[i].b, (u32)&out, ((struct PselWork *)work)->heapId);
        MI_CpuCopy8(*(u8 **)(out + 0xC), (u8 *)((struct PselWork *)work)->fade.slots[i].src, 0x20);
        GFL_HEAP_Free(buffer);
        buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC73C[i].e, (u32)&out, ((struct PselWork *)work)->heapId);
        MI_CpuCopy8(*(u8 **)(out + 0xC), (u8 *)((struct PselWork *)work)->fade.slots[i].dst, 0x20);
        GFL_HEAP_Free(buffer);
    }
    ARC_TOOL_DeleteHandle(object);
    for (i = 0; i < 3; i++) {
        ((struct PselWork *)work)->fade.slots[i].state = 2;
        ((struct PselWork *)work)->fade.slots[i].step = 0x10;
    }
    for (i = 0; i < 3; i++) {
        MI_CpuCopy8((u8 *)((struct PselWork *)work)->fade.slots[i].dst, (u8 *)((struct PselWork *)work)->fade.slots[i].out, 0x20);
        NNS_GfdRegisterNewVramTransferTask((void *)0x1E, d_021BC6FC[i] << 5, (u32)((struct PselWork *)work)->fade.slots[i].out, 0x20);
    }
}







void PSEL_GRAPHIC_NopFade(void *a0){}







/*
 * note (2026-10-05, wave D4 lane 06): EXACT. Three 0x94-byte fade slots at work+0x74 modelled as a
 *   struct array (src/dst/out palettes, state, step); inner loop indexes work->fade.slots[i] directly (no element
 *   pointer); step changes written as ++/-- (the read-modify-write form reloads the step); signed
 *   /16 via an int weight t; dst[j] read into a local before the first split call; colour packed
 *   as A << 10 | (B | C << 5).
 */
void PSEL_GRAPHIC_StepFade(struct PselWork *work)
{
    u8 i;
    for (i = 0; i < 3; i++) {
        int go = 0;
        switch (work->fade.slots[i].state) {
        case 1:
            if (work->fade.slots[i].step == 0x10) {
                work->fade.slots[i].state = 2;
            } else {
                work->fade.slots[i].step++;
                work->fade.slots[i].step = 0x10;
                go = 1;
            }
            break;
        case 3:
            if (work->fade.slots[i].step == 0) {
                work->fade.slots[i].state = 0;
            } else {
                work->fade.slots[i].step--;
                go = 1;
            }
            break;
        }
        if (go) {
            if (work->fade.slots[i].state == 1 || work->fade.slots[i].state == 3) {
                u8 j;
                u16 w[6];
                for (j = 0; j < 0x10; j++) {
                    int t = work->fade.slots[i].step;
                    u16 c = work->fade.slots[i].dst[j];
                    PSEL_GRAPHIC_SplitColor(work->fade.slots[i].src[j], &w[5], &w[4], &w[3]);
                    PSEL_GRAPHIC_SplitColor(c, &w[2], &w[1], &w[0]);
                    work->fade.slots[i].out[j] =
                        (u16)((w[3] * (16 - t) + w[0] * t) / 16) << 10 | ((u16)((w[5] * (16 - t) + w[2] * t) / 16) | (u16)((w[4] * (16 - t) + w[1] * t) / 16) << 5);
                }
            }
            NNS_GfdRegisterNewVramTransferTask((void *)0x1E, d_021BC6FC[i] << 5, (u32)work->fade.slots[i].out, 0x20);
        }
    }
}







void PSEL_GRAPHIC_LoadPaletteBuffers(char *work)
{
    void *object = ARC_TOOL_CreateHandle(205, ((struct PselWork *)work)->heapId);
    u8 i;
    for (i = 0; i < 4; i++) {
        char *out;
        void *buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC708[i], (u32)(&out), ((struct PselWork *)work)->heapId);
        MI_CpuCopy8(((struct PselResMember *)out)->data + 256, (char *)((struct PselWork *)work)->palBuf[i], 256);
        GFL_HEAP_Free(buffer);
    }
    ARC_TOOL_DeleteHandle(object);
    ((struct PselWork *)work)->fadeActive = 0;
    ((struct PselWork *)work)->fadeWeight = 16;
    ((struct PselWork *)work)->fadeSrcIndex = 3;
    MI_CpuCopy8((char *)((struct PselWork *)work)->palBuf[3], (char *)((struct PselWork *)work)->palDst, 256);
    NNS_GfdRegisterNewVramTransferTask((void *)31, 256, (unsigned)((struct PselWork *)work)->palDst, 256);
}







void PSEL_GRAPHIC_NopBlend(void *a0){}







void PSEL_GRAPHIC_BlendPalettes(char *work)
{
    int active=0;
    enum Offset which;
    u8 i;
    u8 weight;
    struct Colors colors;
    u32 q;
    int next;
    u16 red,green,blue;
    u32 tmp;
    if(((struct PselWork *)work)->fadeActive!=1) goto done;
    {
        if(*(volatile u8 *)&((struct PselWork *)work)->fadeWeight==16) ((struct PselWork *)work)->fadeActive=0;
        else {++*(volatile u8 *)&((struct PselWork *)work)->fadeWeight;active=1;}
    }
    if(active) {
        which=0x870;
        i=0;
        which+=1;
        for(;i<128;i++) {
            weight=((struct PselWork *)work)->fadeWeight;
            next=*(u16 *)(work+(*(u8 *)(work+which))*256+i*2+0x26a);
            tmp=(u32)work+i*2;
            q=tmp;
            PSEL_GRAPHIC_SplitColor(((struct PselWork *)q)->palSrc[0],&colors.r1,&colors.g1,&colors.b1);
            PSEL_GRAPHIC_SplitColor(next,&colors.r2,&colors.g2,&colors.b2);
            blue=(colors.b1*(16-weight)+colors.b2*weight)/16;
            red=(colors.r1*(16-weight)+colors.r2*weight)/16;
            green=(colors.g1*(16-weight)+colors.g2*weight)/16;
            ((struct PselWork *)q)->palDst[0]=red|(green<<5)|(blue<<10);
        }
        NNS_GfdRegisterNewVramTransferTask((void *)31,256,(u32)(work+0x76a),256);
    }
done:;
}








/*
 * Addresses are Black-image addresses.
 */
void PSEL_GRAPHIC_InitFadePalettes(char *work)
{
    PSEL_GRAPHIC_LoadFadeSources((u8 *)work);
    PSEL_GRAPHIC_LoadPaletteBuffers(work);
}








void PSEL_GRAPHIC_UpdateFadeNop(char *work)
{
    PSEL_GRAPHIC_NopFade(work);
    PSEL_GRAPHIC_NopBlend(work);
}








void PSEL_GRAPHIC_UpdateFade(char *work)
{
    PSEL_GRAPHIC_StepFade((struct PselWork *)work);
    PSEL_GRAPHIC_BlendPalettes(work);
}







void PSEL_GRAPHIC_SetRecordState(unsigned char *work,unsigned index,int cmd){switch(cmd){case 0:if(*(unsigned short *)((unsigned)work+212+index*148)!=0)*(unsigned short *)((unsigned)work+212+index*148)=3;break;case 2:if(*(unsigned short *)((unsigned)work+212+index*148)!=2)*(unsigned short *)((unsigned)work+212+index*148)=1;break;}}







/*
 * extent: copy helper followed by unlabelled return-one stub at 021BB9DC.
 */
void PSEL_GRAPHIC_SetFadeSource(unsigned char *work,int value){if(((struct PselWork *)work)->fadeSrcIndex!=value){((struct PselWork *)work)->fadeActive=1;((struct PselWork *)work)->fadeWeight=0;((struct PselWork *)work)->fadeSrcIndex=value;MI_CpuCopy8(((struct PselWork *)work)->palDst,((struct PselWork *)work)->palSrc,256);}}







int PSEL_GRAPHIC_IsReady(void){return 1;}







int PSEL_GRAPHIC_Init(char *work)
{
    ((struct PselWork *)work)->graphicSys = PSEL_GRAPHIC_Create(1, ((struct PselWork *)work)->heapId);
    *(struct GfFont * *)&((struct PselWork *)work)->font = GF_FONT_Create(23, 0, 0, 0, ((struct PselWork *)work)->heapId);
    ((struct PselWork *)work)->printQue = PRINTSYS_QUE_Create((void *)(unsigned)((struct PselWork *)work)->heapId);
    BG_SYS_SetVisibleLayer(0, 2);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(4, 3);
    BG_SYS_SetVisibleLayer(5, 2);
    BG_SYS_SetVisibleLayer(6, 1);
    BG_SYS_SetVisibleLayer(7, 0);
    ((struct PselWork *)work)->vblankNode = GFL_USE_AddMainTask(PSEL_Task, work, 1);
    ((struct PselWork *)work)->flags = 0;
    PSEL_CreateG3dUtil(work);
    PSEL_CreateBmpWindows((u16 *)work);
    PSEL_CreateWin(work);
    PSEL_CreateTaskRes(work);
    return 2;
}







int PSEL_GRAPHIC_InitSelect(char *work)
{
    BG_SYS_LoadPlttEntry(0, 0x2F3B);
    BG_SYS_LoadPlttEntry(4, 0x2F3B);
    PSEL_SetupListAnime((u8 *)work);
    PSEL_InitBgLayers((u16 *)work);
    PSEL_DeleteBgLayers((unsigned short *)work);
    PSEL_ClearWin2(work);
    ((struct PselWork *)work)->flags |= 2;
    ((struct PselWork *)work)->alpha = 0;
    G2x_SetBlendAlpha_((void *)0x04000050, 5, 63,
                 ((struct PselWork *)work)->alpha, 16 - ((struct PselWork *)work)->alpha);
    ((struct PselWork *)work)->frame = 0;
    return 3;
}







int PSEL_GRAPHIC_StateFadeIn(char *work, int *state)
{
    if (*(unsigned *)&((struct PselWork *)work)->frame >= 1)
        PSEL_UpdateListAnime(work);
    switch (*state) {
    case 0:
        FADE_Start(3, 16, 0, 0);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            ((struct PselWork *)work)->frame = 0;
            return 4;
        }
        break;
    }
    (((struct PselWork *)work)->frame)++;
    return 3;
}






/*
 * ABI: 02035C60 return consumed at BB B2, as in matched BB0B0, despite own void forwarding declaration.
 */
int PSEL_GRAPHIC_StateFadeAnim(char *work,u32 *state)
{
    int changed=0;
    switch(*state) {
    case 0: PSEL_UpdateListAnime(work);if(((struct PselWork *)work)->animFrame==134) ++*state;break;
    case 1:
        if(((struct PselWork *)work)->alpha<8) {++((struct PselWork *)work)->alpha;changed=1;}
        PSEL_UpdateListAnime(work);if(((struct PselWork *)work)->animFrame==138) ++*state;break;
    case 2:
        if(((struct PselWork *)work)->alpha<8) {++((struct PselWork *)work)->alpha;changed=1;}
        else {((struct PselWork *)work)->flags|=1;++*state;}
        break;
    case 3: ++*state;break;
    case 4:
        if((KEY_GetTrg()&3)!=0||TOUCHPANEL_GetTrg()!=0) {
            if((KEY_GetTrg()&3)!=0) ((struct PselWork *)work)->fadeSpeed=0;
            else ((struct PselWork *)work)->fadeSpeed=1;
            GFL_USE_PlaySeDefaultVolume(1356);++*state;
        }
        break;
    case 5:
        ((struct PselWork *)work)->flags|=2;
        if(((struct PselWork *)work)->alpha!=0) {--((struct PselWork *)work)->alpha;changed=1;}
        ++*state;break;
    case 6:
        if(((struct PselWork *)work)->alpha!=0) {--((struct PselWork *)work)->alpha;changed=1;}
        if(((struct PselWork *)work)->alpha==4) ++*state;break;
    case 7:
        if(((struct PselWork *)work)->alpha!=0) {--((struct PselWork *)work)->alpha;changed=1;}
        PSEL_UpdateListAnime(work);
        if(((struct PselWork *)work)->animFrame==180) GFL_USE_PlaySeDefaultVolume(1956);
        if(((struct PselWork *)work)->animFrame==199) {((struct PselWork *)work)->frame=0;return 5;}
        break;
    }
    if(changed) G2x_SetBlendAlpha_((void *)0x04000050, 5, 63, ((struct PselWork *)work)->alpha, 16-((struct PselWork *)work)->alpha);
    ++((struct PselWork *)work)->frame;
    return 4;
}






/*
 * Preserve the original 9914 call's visible r1=258 and r2=frame inputs;
 * the full callee body reads only entry r0.
 */
int PSEL_GRAPHIC_StateFadeOut(char *work, int *state)
{
    if (((struct PselWork *)work)->animFrame != 258)
        PSEL_UpdateListAnime(work);
    switch (*state) {
    case 0:
        FADE_Start(12, 0, 16, 3);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            ((struct PselWork *)work)->frame = 0;
            return 6;
        }
        break;
    }
    (((struct PselWork *)work)->frame)++;
    return 5;
}






int PSEL_GRAPHIC_StateExit(unsigned char *work){*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;PSEL_ClearWin3((char *)work);PSEL_NopBgDelete(work);PSEL_IsBgReady(work);PSEL_DeleteListAnime((char *)work);((struct PselWork *)work)->frame=0;return 7;}






static inline void setFlagBits(char *work,Bits b) { ((struct PselWork *)work)->flags|=b; }






int PSEL_GRAPHIC_StateEnter(char *work)
{
    BMP_SetDisplaySwap(0);
    BG_SYS_LoadPlttEntry(0,0x2f3b); BG_SYS_LoadPlttEntry(4,0x2f3b);
    PSEL_SetupSelectAnime(work); PSEL_CreateUnits(work); PSEL_CreateUnits2(work); PSEL_SetBgSys((const u16 *)work); PSEL_UploadBgPalette((u16 *)work); PSEL_GRAPHIC_InitFadePalettes(work);
    setFlagBits(work,BIT8); setFlagBits(work,BIT32);
    G2x_SetBlendAlpha_((void *)0x04000050, 5, 63, 8, 8); G2x_SetBlendAlpha_((void *)0x04001050, 4, 63, 8, 8);
    ((struct PselWork *)work)->frame=0;
    return 8;
}






int PSEL_GRAPHIC_StateRun(char *work,unsigned *state)
{
    if(((struct PselWork *)work)->frame>=16) PSEL_UpdateSelectAnime(work);
    if(((struct PselWork *)work)->frame==15) GFL_USE_PlaySeDefaultVolume(1957);
    PSEL_UpdateUnitAnime(work); PSEL_UpdateUnitPositions((struct Main *)work); PSEL_GRAPHIC_UpdateFade(work);
    switch(*state) {
    case 0: FADE_Start(12,16,0,2); (*state)++; break;
    case 1: if(!FADE_IsActive()) { ((struct PselWork *)work)->frame=0; return 9; } break;
    }
    (((struct PselWork *)work)->frame)++;
    return 8;
}






/*
 * ABI: A A84 unused legacy r1 omitted: full own body reads no second input, original has no setup; BB9A4 r1 truncated to u8 at BE C6/CA and parallel sites; 355D8 widened to observed full word without pre-call truncation. 35C60 return consumed as in own-overlay BB0B0.
 */
int PSEL_GRAPHIC_Main(char *work,u32 *state)
{
    int dirty=0;
    int choice,changed;
    u32 selected;
    PSEL_UpdateUnitAnime(work);PSEL_UpdateUnitPositions((struct Main *)work);PSEL_UpdateUnitAnime2(work);PSEL_GRAPHIC_UpdateFade(work);
    switch(*state) {
    case 0:PSEL_UpdateSelectAnime(work);if(((struct PselWork *)work)->animFrame==78)*state=1;break;
    case 1:((struct PselWork *)work)->flags|=4;PSEL_SetMode(work,(u32)19);*state=2;PSEL_UpdateFadeUnit(work);break;
    case 2:if(PSEL_IsModeDone(work)&&PSEL_IsUnitAnimDone(work)){*state=3;((struct PselWork *)work)->fadeSpeed=1;}break;
    case 3:
        if(((struct PselWork *)work)->fadeSpeed==0){
            if(*(int *)&((struct PselWork *)work)->fade.state.menuSelected==4){dirty=1;*(int *)&((struct PselWork *)work)->fade.state.menuSelected=1;}
            PSEL_SetActorPosition(work,1);GFL_USE_PlaySeDefaultVolume(1352);PSEL_UpdateActorPosition(work);
            PSEL_SelectUnit(work,((struct PselWork *)work)->fade.state.menuSelected);PSEL_SetUnitVisible(work,((struct PselWork *)work)->fade.state.menuSelected);
            selected=((struct PselWork *)work)->fade.state.menuSelected;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)selected);
        }else{PSEL_SetActorPosition(work,0);PSEL_SelectUnit(work,4);PSEL_SetUnitVisible(work,4);PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)3);dirty=1;}
        *state=4;break;
    case 4:
        if(((struct PselWork *)work)->fadeSpeed==0){
            if(KEY_GetTrg()!=0){
                changed=0;
                if(KEY_GetTrg()&1){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetActorPosition(work,0);*state=8;}
                else if(KEY_GetTrg()&32){if(*(int *)&((struct PselWork *)work)->fade.state.menuSelected>0){--*(int *)&((struct PselWork *)work)->fade.state.menuSelected;changed=1;}}
                else if(KEY_GetTrg()&16){if(*(int *)&((struct PselWork *)work)->fade.state.menuSelected<2){++*(int *)&((struct PselWork *)work)->fade.state.menuSelected;changed=1;}}
                if(changed){GFL_USE_PlaySeDefaultVolume(1352);PSEL_UpdateActorPosition(work);PSEL_SelectUnit(work,((struct PselWork *)work)->fade.state.menuSelected);PSEL_SetUnitVisible(work,((struct PselWork *)work)->fade.state.menuSelected);selected=((struct PselWork *)work)->fade.state.menuSelected;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)selected);dirty=1;}
            }else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){if(*(int *)&((struct PselWork *)work)->fade.state.menuSelected!=choice)dirty=1;GFL_USE_PlaySeDefaultVolume(1352);PSEL_SetActorPosition(work,0);*(int *)&((struct PselWork *)work)->fade.state.menuSelected=choice;PSEL_SelectUnit(work,choice);PSEL_SetUnitVisible(work,((struct PselWork *)work)->fade.state.menuSelected);selected=((struct PselWork *)work)->fade.state.menuSelected;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)selected);((struct PselWork *)work)->fadeSpeed=1;*state=5;}}
        }else{
            if(KEY_GetTrg()!=0){((struct PselWork *)work)->fadeSpeed=0;*state=3;}
            else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){GFL_USE_PlaySeDefaultVolume(1352);*(int *)&((struct PselWork *)work)->fade.state.menuSelected=choice;PSEL_SelectUnit(work,choice);PSEL_SetUnitVisible(work,((struct PselWork *)work)->fade.state.menuSelected);selected=((struct PselWork *)work)->fade.state.menuSelected;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)selected);dirty=1;*state=5;}}
        }break;
    case 5:PSEL_ShowTaskRes(work);*state=6;break;
    case 6:
        PSEL_UpdateTaskResWin(work);
        if(KEY_GetTrg()!=0){((struct PselWork *)work)->fadeSpeed=0;if(KEY_GetTrg()&1){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetTaskResActive(work);*state=7;}else{PSEL_DeleteTaskRes(work);BG_SYS_SetFlagField06(3);*state=3;}}
        else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice==3){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetTaskResActive(work);*state=7;}else if(choice>=0&&choice<=2&&*(int *)&((struct PselWork *)work)->fade.state.menuSelected!=choice){GFL_USE_PlaySeDefaultVolume(1352);*(int *)&((struct PselWork *)work)->fade.state.menuSelected=choice;PSEL_SelectUnit(work,choice);PSEL_SetUnitVisible(work,((struct PselWork *)work)->fade.state.menuSelected);selected=((struct PselWork *)work)->fade.state.menuSelected;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)work,(u8)selected);dirty=1;}}break;
    case 7:PSEL_UpdateTaskResWin(work);if(PSEL_IsTaskResFinished(work)){PSEL_DeleteTaskRes(work);BG_SYS_SetFlagField06(3);*state=8;}break;
    case 8:PSEL_SetMode(work,(u32)20);PSEL_SetAnimTarget(work,*(int *)&((struct PselWork *)work)->fade.state.menuSelected,0);*state=9;break;
    case 9:PSEL_StepAnim(work);if(PSEL_IsModeDone(work)&&PSEL_IsAnimTargetReached(work))*state=10;break;
    case 10:UI_SetInputMode(*(u32 *)&((struct PselWork *)work)->fadeSpeed);PSEL_GRAPHIC_OpenMenu(work);*state=11;break;
    case 11:PSEL_GRAPHIC_UpdateMenu(work);if(PSEL_GRAPHIC_IsMenuFinished(work)){choice=PSEL_GRAPHIC_GetMenuChoice((int *)work);PSEL_GRAPHIC_CloseMenu(work);*(u32 *)&((struct PselWork *)work)->fadeSpeed=UI_GetInputMode();if(choice){((struct PselWork *)work)->flags|=8;PSEL_UpdateSubWindow(work);*state=14;}else{PSEL_SetMode(work,(u32)19);*state=12;}}break;
    case 12:PSEL_SetAnimTarget(work,*(int *)&((struct PselWork *)work)->fade.state.menuSelected,1);*state=13;break;
    case 13:PSEL_StepAnim(work);if(PSEL_IsAnimTargetReached(work))*state=3;break;
    case 14:PSEL_SetAnimTargetIndex(work,((struct PselWork *)work)->fade.state.menuSelected);GFL_USE_PlaySeDefaultVolume(1976);*state=15;break;
    case 15:PSEL_StepAnimIndex(work);if(((struct PselWork *)work)->animTarget==(int)*(const u16 *)((const u8 *)d_021BC794+((struct PselWork *)work)->animTableIndex*10)-2)*state=16;break;
    case 16:PSEL_StepAnimIndex(work);*(int *)&((struct PselWork *)work)->frame=0;return 10;
    }
    if(dirty){((struct PselWork *)work)->flags|=32;PSEL_ClearWin(work);}
    else if(((struct PselWork *)work)->voicePending!=0){((struct PselWork *)work)->flags|=16;PSEL_PrintSubWindow(work,(u32)(((struct PselWork *)work)->fade.state.menuSelected));PM_VOICE_Play(d_021BC710[((struct PselWork *)work)->fade.state.menuSelected],0,64,0,0,0,0,0);}
    ((struct PselWork *)work)->voicePending=0;++((struct PselWork *)work)->frame;return 9;
}





int PSEL_GRAPHIC_StateEnd(char *work,unsigned *state)
{
    PSEL_StepAnimIndex(work);
    PSEL_UpdateUnitAnime(work); PSEL_UpdateUnitPositions((struct Main *)work); PSEL_GRAPHIC_UpdateFade(work);
    switch(*state) {
    case 0: FADE_Start(12,0,16,2); (*state)++; break;
    case 1: if(!FADE_IsActive()) { ((struct PselWork *)work)->frame=0; return 11; } break;
    }
    (((struct PselWork *)work)->frame)++;
    return 10;
}





int PSEL_GRAPHIC_StateCleanup(char *work)
{
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    PSEL_GRAPHIC_UpdateFadeNop(work); PSEL_NopBgUpdate(work); PSEL_ClearBgLayerEx(work);
    PSEL_DeleteActors(work); PSEL_DeleteUnits(work); PSEL_DeleteSelectAnime(work);
    ((struct PselWork *)work)->frame=0;
    return 12;
}





int PSEL_GRAPHIC_Delete(int *work)
{
    PSEL_DeleteTaskResData(work); PSEL_DeleteWin((char *)work); PSEL_NopBgWindows(work); PSEL_DeleteG3dUtil(work);
    TCB_DeleteTask((void *)work[8]); PRINTSYS_QUE_Clear((struct PrintSys *)work[7]); PRINTSYS_QUE_Delete((struct PrintSys *)work[7]);
    GF_FONT_Delete((void *)work[6]); PSEL_GRAPHIC_Destroy((unsigned *)work[5]);
    return 13;
}





/*
 * trailing: parent-cleared Thumb follower 021BC348 is movs r0,#13; bx lr.
 */
int PSEL_GRAPHIC_GetMaxState(void) { return 13; }





static inline void shading(Shading s)
{
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3002)|(s<<1));
}





static inline void priority(int prio)
{
    *(volatile unsigned short *)0x04000008=(unsigned short)((*(volatile unsigned short *)0x04000008 & ~3)|prio);
}





void PSEL_GRAPHIC_G3dCallback(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    priority(0);
    shading(HIGHLIGHT);
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|16);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3004;
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|8);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,(const u16 *)(d_021BC960+i*8));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}





void *PSEL_GRAPHIC_Create(int a,int heap)
{
    unsigned *sys=GFL_HEAP_Alloc(heap,16,0,d_021BCB08,463);
    MI_CpuFill8(sys,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BC980);
    BMP_SetDisplaySwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    PSEL_GRAPHIC_InitBg(sys,heap);
    PSEL_GRAPHIC_InitClact((int *)(sys+1),(int)d_021BC980,heap);
    PSEL_GRAPHIC_InitG3d((int *)(sys+2),heap);
    sys[3]=(unsigned)GFL_USE_AddMainTask(PSEL_GRAPHIC_VBlank,sys,0);
    return sys;
}





/*
 * volatile: hardware accesses at 0x021BC4BA-0x021BC4D4.
 */
void PSEL_GRAPHIC_Destroy(unsigned *sys)
{
    TCB_DeleteTask((void *)sys[3]);
    PSEL_GRAPHIC_ExitG3d((int *)(sys+2));
    PSEL_GRAPHIC_ExitClact((char *)(sys+1));
    PSEL_GRAPHIC_ExitBg(sys);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(sys,0,16);
    GFL_HEAP_Free(sys);
}






void PSEL_GRAPHIC_Draw(char *sys)
{
    PSEL_GRAPHIC_ClactDraw(sys + 4);
    PSEL_GRAPHIC_NopDraw(sys);
}





void PSEL_GRAPHIC_ApplyLight(unsigned char *sys){PSEL_GRAPHIC_ApplyLookAt((int *)(sys+8));}





void PSEL_GRAPHIC_DrawEnd(unsigned char *sys){PSEL_GRAPHIC_G3dDrawEnd(sys+8);}





unsigned PSEL_GRAPHIC_GetClactBank(unsigned char *sys){return PSEL_GRAPHIC_LoadWord((const unsigned *)(sys+4));}





unsigned PSEL_GRAPHIC_GetCamera(unsigned char *sys){return PSEL_GRAPHIC_LoadWordC6F8(sys+8);}






void PSEL_GRAPHIC_VBlank(void *unused, char *sys)
{
    PSEL_GRAPHIC_UpdateBg(sys);
    PSEL_GRAPHIC_ClactVBlank(sys + 4);
}



void PSEL_GRAPHIC_InitBg(void *sys,int heap)
{
    unsigned i;
    MI_CpuFill8(sys,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BC934);
    for(i=0;i<7;i++) {
        const struct Entry *e=&d_021BC9B0[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,e->b);
    }
}





void PSEL_GRAPHIC_ExitBg(void *sys){unsigned i;for(i=0;i<7;i++)BG_SYS_FreeLayerBuf((unsigned char)d_021BC9B0[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(sys,0,4);}





void PSEL_GRAPHIC_NopDraw(void *a0){}





void PSEL_GRAPHIC_UpdateBg(void *a0){BG_SYS_Update();}






void PSEL_GRAPHIC_InitClact(int *out, int a, int b)
{
    MI_CpuFill8(out, 0, 4);
    CLACT_InitSystem((const struct Cfg *)(&d_021BC944), a, b);
    *out = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)*out);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}






void PSEL_GRAPHIC_ExitClact(char *bank)
{
    CLACT_DeleteUnit((struct Bank *)((struct PselHandle *)bank)->value);
    CLACT_ExitSystem();
    MI_CpuFill8(bank, 0, 4);
}




void PSEL_GRAPHIC_ClactDraw(void *a0) { CLACT_DrawSystem(); }




void PSEL_GRAPHIC_ClactVBlank(void *a0) { CLACT_VBlankSystem(); }




/*
 * extent: tail-call stub followed by unlabelled 021BC65C load-return.
 */
u32 PSEL_GRAPHIC_LoadWord(const u32 *word) { return *word; }




void PSEL_GRAPHIC_InitG3d(int *camera,int heap)
{
    G3D_SYSTEM_Init(0,1,0,1,4096,heap,PSEL_GRAPHIC_G3dCallback);
    *camera=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,0x400000,0,d_021BC91C,d_021BC910,d_021BC928,heap);
}





void PSEL_GRAPHIC_ExitG3d(int *camera)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*camera)));
}





void PSEL_GRAPHIC_ApplyLookAt(int *camera)
{
    func_02047964();
    G3D_CAMERA_Reset((struct Light *)(*camera));
    G3D_SYSTEM_ApplyLookAt();
}




void PSEL_GRAPHIC_G3dDrawEnd(unsigned char *unused){G3D_SYSTEM_DrawEnd();}

unsigned PSEL_GRAPHIC_LoadWordC6F8(unsigned char *handle){return ((struct PselHandle *)handle)->value;}
