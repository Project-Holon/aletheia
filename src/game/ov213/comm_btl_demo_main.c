/*
 * file:     comm_btl_demo_main.c
 * unit:     yes
 * function: COMM_BTL_DEMO_MAIN_Create, COMM_BTL_DEMO_MAIN_Delete, COMM_BTL_DEMO_MAIN_Update, COMM_BTL_DEMO_MAIN_LoadGraphics, COMM_BTL_DEMO_MAIN_Exit, COMM_BTL_DEMO_MAIN_Step, COMM_BTL_DEMO_MAIN_SetupFirstSide, COMM_BTL_DEMO_MAIN_SetupSecondSide, COMM_BTL_DEMO_MAIN_GetSoundId, COMM_BTL_DEMO_MAIN_Tick, COMM_BTL_DEMO_MAIN_Exit2, COMM_BTL_DEMO_MAIN_LayoutRows, COMM_BTL_DEMO_MAIN_UpdateBattle, COMM_BTL_DEMO_MAIN_UpdateExit, COMM_BTL_DEMO_MAIN_UpdateEnd, COMM_BTL_DEMO_MAIN_UpdateFadeOut, COMM_BTL_DEMO_MAIN_GetModeIndex, COMM_BTL_DEMO_MAIN_IsFullPartyMode, COMM_BTL_DEMO_MAIN_HasVisibleActors, COMM_BTL_DEMO_MAIN_TypeToFrame, COMM_BTL_DEMO_MAIN_InitActorRow, COMM_BTL_DEMO_MAIN_DeleteActorRow, COMM_BTL_DEMO_MAIN_UpdateActorRow, COMM_BTL_DEMO_MAIN_UpdateRowDelay, COMM_BTL_DEMO_MAIN_MarkRowDone, COMM_BTL_DEMO_MAIN_SetRowActorAnim, COMM_BTL_DEMO_MAIN_CreateRowWindow, COMM_BTL_DEMO_MAIN_InitRowContext, COMM_BTL_DEMO_MAIN_RefreshRowText, COMM_BTL_DEMO_MAIN_DeleteRowContext, COMM_BTL_DEMO_MAIN_UpdateRowContext, COMM_BTL_DEMO_MAIN_DrawRowText, COMM_BTL_DEMO_MAIN_InitRows, COMM_BTL_DEMO_MAIN_DeleteRows, COMM_BTL_DEMO_MAIN_UpdateRows, COMM_BTL_DEMO_MAIN_MarkRowsDone, COMM_BTL_DEMO_MAIN_SetActorAnimKind, COMM_BTL_DEMO_MAIN_UpdateNetKind, COMM_BTL_DEMO_MAIN_InitBattleContext, COMM_BTL_DEMO_MAIN_DeleteBattleContext, COMM_BTL_DEMO_MAIN_UpdateBattleActors, COMM_BTL_DEMO_MAIN_ShowBattleActor, COMM_BTL_DEMO_MAIN_InitCursor, COMM_BTL_DEMO_MAIN_DeleteCursor, COMM_BTL_DEMO_MAIN_CreateActor, COMM_BTL_DEMO_MAIN_CreateSideActor, COMM_BTL_DEMO_MAIN_InitGraphics, COMM_BTL_DEMO_MAIN_DeleteGraphics, COMM_BTL_DEMO_MAIN_DrawGraphics, COMM_BTL_DEMO_MAIN_InitEffect, COMM_BTL_DEMO_MAIN_DeleteEffect, COMM_BTL_DEMO_MAIN_DeleteEffectManager, COMM_BTL_DEMO_MAIN_StartEffect, COMM_BTL_DEMO_MAIN_StartEffects, COMM_BTL_DEMO_MAIN_BindModelPalette, COMM_BTL_DEMO_MAIN_LoadObject, COMM_BTL_DEMO_MAIN_UnloadObject, COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded, COMM_BTL_DEMO_MAIN_UpdateObjectAnime, COMM_BTL_DEMO_MAIN_InitializeFlags, COMM_BTL_DEMO_MAIN_CountFlags, COMM_BTL_DEMO_MAIN_Init3dSystem
 * address:  0x021B95A0
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   COMM_BTL_DEMO_GRAPHIC_Create 0x021BAB64 thumb ov213
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   UI_SCENE_Create 0x021B6100 thumb ov067
 *   callbacks 0x021BB02C data ov213 a4
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   FADE_Start 0x0204E720 arm
 *   ov067_id 0x00000043 data a1
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   COMM_BTL_DEMO_GRAPHIC_Delete 0x021BAC0C thumb ov213
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   COMM_BTL_DEMO_GRAPHIC_Draw 0x021BAC68 thumb ov213
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021BAF14 0x021BAF14 data a4
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   d_021BB004 0x021BB004 data ov213 a4
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   records 0x021BB0A4 data a4
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   FADE_Start 0x0204E720 arm
 *   gCommBtlDemoEffectPos0 0x021BB0D4 data a4
 *   gCommBtlDemoEffectPos1 0x021BB0E0 data ov213
 *   gCommBtlDemoEffectPos2 0x021BB068 data ov213
 *   gCommBtlDemoEffectPos3 0x021BB074 data ov213
 *   gCommBtlDemoEffectPos4 0x021BB080 data ov213
 *   gCommBtlDemoEffectPos5 0x021BB098 data a4
 *   FADE_IsActive 0x0204E804 arm
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   zero 0x021BB08C data ov213
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MYSTATUS_NameToStrbuf 0x02008500 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   COMM_BTL_DEMO_MAIN_UpdateRowContext 0x021BA30C thumb ov213
 *   RECORD_AddOne 0x02008DF0 thumb
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   COMM_BTL_DEMO_GRAPHIC_GetCamera 0x021BAC94 thumb ov213
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   COMM_BTL_DEMO_GRAPHIC_Draw3d 0x021BAC7C thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_DrawEnd 0x021BAC88 thumb ov213
 *   PARTICLE_Main 0x02050BE8 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_RESOURCE_GetType 0x02051B04 arm
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021BB324 0x021BB324 data a4
 *   d_021BB330 0x021BB330 data a4
 *   d_021BB360 0x021BB360 data a4
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   G3D_SYSTEM_GetObjectRender 0x02047788 arm
 *   G3D_SYSTEM_GetRenderTexRes 0x02047554 arm
 *   G3D_SYSTEM_GetRenderObj 0x0204755C arm
 *   G3D_SYSTEM_GetResourceTex 0x02047250 arm
 *   NNS_G3dReleaseMdlPltt 0x0206A67C arm
 *   NNS_G3dBindMdlPlttEx 0x0206A5B4 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   d_021BB0F8 0x021BB0F8 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   d_021BB320 0x021BB320 data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BB1A8 0x021BB1A8 data a2
 */

#include "../arm9/nns_g3d_tex.h"
#include "../sdk_ioreg.h"
#include "comm_btl_demo_shared_types.h"

#define REG3D (*(volatile unsigned short *)REG_DISP3DCNT_ADDR)
struct MsgData;
struct PrintSys;
struct ProcOwner;
struct UiScene;
struct Actor;
struct Strbuf;
struct TextSys;
struct BmpWin;
struct BmpWinCfg;
struct BmpCharBuf;
struct AnimUnit;
struct ParticleCamera;
struct G3dSystem;
struct G3dUtil;
struct G3dRenderObjRef;
typedef struct Util Util;

#include "../types.h"

struct ActorGfxDesc;
struct ActorGfxSet;
struct G3dResource;
struct G3dUtilSetup;
struct NNSG3dResTex;
struct UiSceneEntry;
#include "../arm9/clact.h"
/* struct CommBtlDemoSide and struct CommBtlDemoArgs (the 0x58-byte setup
 * record ov199 builds) live in comm_btl_demo_shared_types.h. */

/* One row's actor set, the struct the CLACT helpers receive as the row body. */
struct CommBtlDemoActorRow {
    void *owner;        /* 0x00 */
    void *parent;       /* 0x04 */
    u8 kind;            /* 0x08 */
    u8 index;           /* 0x09 */
    u8 memberCount;     /* 0x0A */
    u8 actorCount;      /* 0x0B */
    void *obj[6];       /* 0x0C */
    int step;           /* 0x24 */
    u8 active;          /* 0x28 */
    u8 pad29[3];        /* 0x29 */
    const u8 *types;    /* 0x2C */
};

/* One text row of the demo (84 bytes, four per object). */
struct CommBtlDemoRow {
    const char *owner;  /* 0x00 */
    void *actorBase;    /* 0x04 */
    void *parent;       /* 0x08 */
    int textArg;        /* 0x0C */
    u8 kind;            /* 0x10 */
    u8 index;           /* 0x11 */
    u8 pad12[2];        /* 0x12 */
    u32 paletteKind;    /* 0x14 */
    void *textBuf;      /* 0x18 */
    u32 window;         /* 0x1C */
    struct CommBtlDemoActorRow actor; /* 0x20 */
    int counter;        /* 0x50 */
};

/* Battle context at 0x498C. */
struct CommBtlDemoBattleContext {
    int pad00;          /* 0x00 */
    const void *owner;  /* 0x04 */
    void *other;        /* 0x08 */
    u16 sideACount;     /* 0x0C */
    u16 sideBCount;     /* 0x0E */
    void *sideActor[2]; /* 0x10 */
    void *actors[3];    /* 0x18 */
    u16 timer;          /* 0x24 */
    u8 kind;            /* 0x26 */
    u8 pad27;           /* 0x27 */
};

/* 3D graphics sub-object at 0x24. */
struct CommBtlDemoGfx {
    void *state;        /* 0x0000 */
    u16 heap;           /* 0x0004 */
    u16 pad06;          /* 0x0006 */
    struct Util *util;  /* 0x0008 */
    u16 unitIndex;      /* 0x000C */
    u8 animeDone;       /* 0x000E */
    u8 loaded;          /* 0x000F */
    void *particleSystem; /* 0x0010 */
    u8 pad14[0x4800];   /* 0x0014 */
    u8 resourceType;    /* 0x4814 */
    u8 pad4815[3];      /* 0x4815 */
};

/* Actor-gfx slot filled by UI_SCENE_LoadActorGfx (16 bytes). */
typedef struct { int id, resource, palette, frame; } UiSceneActorGfx;

/* Actor-gfx config passed to UI_SCENE_LoadActorGfx. */
typedef struct { int mode; u32 flags; int archiveId; int cellId; int paletteId; int animId; int frameId; u8 alpha; u8 flip; u8 visible; } UiSceneActorGfxConfig;

/* Cursor sub-object at 0x0C. */
struct CommBtlDemoCursor {
    void *state;        /* 0x00 */
    u16 heap;           /* 0x04 */
    u16 pad06;          /* 0x06 */
    UiSceneActorGfx gfx; /* 0x08 */
};

/* The comm battle demo work record (0x49D8 bytes, COMM_BTL_DEMO_MAIN_Create). */
struct CommBtlDemoMain {
    u16 heap;           /* 0x0000 */
    u16 pad02;          /* 0x0002 */
    struct CommBtlDemoArgs *args; /* 0x0004 */
    u8 pad08[4];        /* 0x0008 */
    struct CommBtlDemoCursor cursor; /* 0x000C */
    struct CommBtlDemoGfx gfx;       /* 0x0024 */
    struct CommBtlDemoRow rows[4];   /* 0x483C */
    struct CommBtlDemoBattleContext battle; /* 0x498C */
    void *graphic;      /* 0x49B4 */
    void *font;         /* 0x49B8 */
    void *printQue;     /* 0x49BC */
    void *messages;     /* 0x49C0 */
    void *uiScene;      /* 0x49C4 */
    u8 mode;            /* 0x49C8 */
    u8 pad49C9[3];      /* 0x49C9 */
    u32 variant;        /* 0x49CC */
    u32 stage;          /* 0x49D0 */
    int frameCount;     /* 0x49D4 */
};

enum Count {CountZero,CountTwo=2,CountFour=4};

#include "../sdk_fx.h"

struct G3dDrawArg { VecFx32 pos, scale; MtxFx33 rot; };

struct ParticleCameraParam {u32 f00,f04,f08,f0c,f10,f14,f18,f1c;};

struct G3dUnitSetup { void *resTbl; u16 resCount; void *objTbl; u16 objCount; };

struct GfxEntry { u32 cell; u32 palette; u32 anim; };

struct AnimRecord { int frame; int repeat; int mode; };

struct AnimTable { struct AnimRecord recA; u32 callback[3]; struct AnimRecord recB,recC; u8 gap[24]; struct AnimRecord recD; };

struct Vec3i {int x,y,z;};

/* Offset-4 view of arm9 NNSG3dRenderObj: only resMdl is read here. */
struct G3dRenderObjRef { u32 flag; void *resMdl; };

#include "../sdk_gx.h"

#include "../arm9/fade.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "comm_btl_demo_graphic.h"
struct GfFont;
#include "../arm9/gf_font.h"
struct MsgBank;
#include "../arm9/msgdata.h"
struct PrintQueue;
#include "../arm9/printsys.h"
extern struct UiScene *UI_SCENE_Create(u32,const struct UiSceneEntry *,u8,u32,void *);
#include "../arm9/net.h"
#include "../arm9/bg_sys.h"
extern void UI_SCENE_Delete(struct UiScene *scene);
extern void COMM_BTL_DEMO_MAIN_DeleteCursor(char *),COMM_BTL_DEMO_MAIN_DeleteGraphics(char *),COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *);
#include "../arm9/gfl_heap_wrap.h"
extern int UI_SCENE_Step(struct UiScene *s);
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
extern void UI_SCENE_SetNextScene(struct UiScene *scene, int nextSceneIndex);
extern u32 G3D_UTIL_GetObject(struct G3dUtil *, int);
extern u32 UI_SCENE_GetPhaseFrame(const u8 *);
extern void UI_SCENE_AdvancePhaseFrame(u8 *);
extern u32 UI_SCENE_GetPhaseFrame(const unsigned char*);
extern void UI_SCENE_AdvancePhaseFrame(unsigned char*);
#include "../arm9/gfl_use.h"
struct Party;
#include "../arm9/pokeparty.h"
struct PokemonParam;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/mystatus.h"
struct MyStatus;
extern u32 BMP_WIN_Delete(struct BmpWin *d);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *p);
typedef short s16_p07;
#include "../arm9/bmp.h"
extern void BMP_WIN_TransferChars(struct BmpWin *d);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *p);
void COMM_BTL_DEMO_MAIN_UpdateRowContext();
#include "../arm9/record.h"
extern void UI_SCENE_LoadActorGfx(struct ActorGfxSet *out, struct ActorGfxDesc *in, void *, unsigned heap);
extern void UI_SCENE_FreeActorGfx(struct ActorGfxSet *p);
extern struct Actor *UI_SCENE_CreateActor(struct ActorGfxSet *,void *,unsigned char,unsigned char,unsigned char,unsigned short);
extern void G2x_SetBlendAlpha_(void *,int,int,int,int),PARTICLE_InitManager(unsigned);
extern struct G3dUtil *G3D_UTIL_Create(unsigned,unsigned,unsigned);
extern void G3D_UTIL_Delete(struct G3dUtil *p);
#include "../arm9/particle.h"
#include "../arm9/fx_mtx33.h"
struct G3dObjectStatus;
struct G3dObject;
extern void G3D_SYSTEM_DrawObject(struct G3dObject *obj, struct G3dObjectStatus *status);
struct ParticleSys;
struct TcbList;
extern int G3D_SYSTEM_GetObjectRender(int *),G3D_SYSTEM_GetRenderTexRes(int *),G3D_SYSTEM_GetRenderObj(int *);
extern struct NNSG3dResTex *G3D_SYSTEM_GetResourceTex(struct G3dResource *);
extern u16 G3D_UTIL_AddUnit(struct G3dUtil *util, const struct G3dUtilSetup *setup);
extern unsigned short G3D_SYSTEM_GetObjectAnimeCount(struct G3dObject *obj);
extern int G3D_SYSTEM_EnableObjectAnime(struct G3dObject *obj, unsigned int anmIdx);
extern void G3D_UTIL_RemoveUnit(struct G3dUtil *,u32);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(struct G3dObject *obj, int anmIdx, int step);
#include "../arm9/g3x.h"
struct G3dLight;
extern void G3D_SYSTEM_SetLight(unsigned int lightIdx, struct G3dLight *light);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
int COMM_BTL_DEMO_MAIN_Create(void *manager,int *state,struct CommBtlDemoArgs *args);
int COMM_BTL_DEMO_MAIN_Delete(struct ProcOwner *owner,int unused,const void *cfg,char *p);
int COMM_BTL_DEMO_MAIN_Update(int a,int b,int c,char *p);
void COMM_BTL_DEMO_MAIN_LoadGraphics(int a,u16 heap,int index);
void COMM_BTL_DEMO_MAIN_Exit(u8 *task, char *p);
int COMM_BTL_DEMO_MAIN_Step(void *unused, struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_SetupFirstSide(struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_SetupSecondSide(struct CommBtlDemoMain *p);
int COMM_BTL_DEMO_MAIN_GetSoundId(int a, int b);
int COMM_BTL_DEMO_MAIN_Tick(u8 *task,char *p);
int COMM_BTL_DEMO_MAIN_Exit2(u8 *task,void *p);
int COMM_BTL_DEMO_MAIN_LayoutRows(int unused,char *p);
int COMM_BTL_DEMO_MAIN_UpdateBattle(unsigned char *state,unsigned char *p);
int COMM_BTL_DEMO_MAIN_UpdateExit(u8 *task,char *p);
int COMM_BTL_DEMO_MAIN_UpdateEnd(void *state,char *p);
int COMM_BTL_DEMO_MAIN_UpdateFadeOut(void *a,void *b);
int COMM_BTL_DEMO_MAIN_GetModeIndex(const struct CommBtlDemoArgs *p);
int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32 x);
int COMM_BTL_DEMO_MAIN_HasVisibleActors(u32 x);
int COMM_BTL_DEMO_MAIN_TypeToFrame(void *p,u32 x);
void COMM_BTL_DEMO_MAIN_InitActorRow(struct CommBtlDemoActorRow *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types);
void COMM_BTL_DEMO_MAIN_DeleteActorRow(struct CommBtlDemoActorRow *p);
void COMM_BTL_DEMO_MAIN_UpdateActorRow(struct CommBtlDemoActorRow *p, u32 time);
void COMM_BTL_DEMO_MAIN_UpdateRowDelay(struct CommBtlDemoActorRow *p,unsigned limit);
void COMM_BTL_DEMO_MAIN_MarkRowDone(struct CommBtlDemoActorRow *p);
void COMM_BTL_DEMO_MAIN_SetRowActorAnim(struct CommBtlDemoActorRow *p,void *list,const u8 *flags,int index);
unsigned COMM_BTL_DEMO_MAIN_CreateRowWindow(unsigned kind,unsigned index);
void COMM_BTL_DEMO_MAIN_InitRowContext(struct CommBtlDemoRow *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c);
void COMM_BTL_DEMO_MAIN_RefreshRowText(struct CommBtlDemoRow *a);
void COMM_BTL_DEMO_MAIN_DeleteRowContext(struct CommBtlDemoRow *p);
void COMM_BTL_DEMO_MAIN_DrawRowText(struct CommBtlDemoRow *p, int a);
void COMM_BTL_DEMO_MAIN_InitRows(struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_DeleteRows(char *p);
void COMM_BTL_DEMO_MAIN_UpdateRows(char *p);
void COMM_BTL_DEMO_MAIN_MarkRowsDone(char *p);
void COMM_BTL_DEMO_MAIN_SetActorAnimKind(void *p,int kind,int variant);
void COMM_BTL_DEMO_MAIN_UpdateNetKind(char *p);
void COMM_BTL_DEMO_MAIN_InitBattleContext(struct CommBtlDemoBattleContext *p,const void *owner,void *other,u16 a,u16 b,u8 kind);
void COMM_BTL_DEMO_MAIN_DeleteBattleContext(struct CommBtlDemoBattleContext *p);
void COMM_BTL_DEMO_MAIN_UpdateBattleActors(char *p);
void COMM_BTL_DEMO_MAIN_ShowBattleActor(struct CommBtlDemoBattleContext *p,unsigned i,int kind);
void COMM_BTL_DEMO_MAIN_InitCursor(char *p, void *state, int heap);
void COMM_BTL_DEMO_MAIN_DeleteCursor(char *p);
void *COMM_BTL_DEMO_MAIN_CreateActor(char *p,int a,int b,unsigned short c);
void *COMM_BTL_DEMO_MAIN_CreateSideActor(void *p,int kind,unsigned a);
void COMM_BTL_DEMO_MAIN_InitGraphics(char *p,void *state,int heap);
void COMM_BTL_DEMO_MAIN_DeleteGraphics(char *p);
void COMM_BTL_DEMO_MAIN_DrawGraphics(unsigned char *p);
void COMM_BTL_DEMO_MAIN_InitEffect(u8 *p,unsigned code);
void COMM_BTL_DEMO_MAIN_DeleteEffect(char *p, int object);
void COMM_BTL_DEMO_MAIN_DeleteEffectManager(char *p);
int COMM_BTL_DEMO_MAIN_StartEffect(char *p,int b,int c);
void COMM_BTL_DEMO_MAIN_StartEffects(char *p,int v);
int COMM_BTL_DEMO_MAIN_BindModelPalette(int *p,u32 b,u32 c);
void COMM_BTL_DEMO_MAIN_LoadObject(unsigned char *p, int index);
void COMM_BTL_DEMO_MAIN_UnloadObject(char *p);
void COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(void *a);
int COMM_BTL_DEMO_MAIN_UpdateObjectAnime(unsigned char *p);
void COMM_BTL_DEMO_MAIN_InitializeFlags(unsigned char *p);
int COMM_BTL_DEMO_MAIN_CountFlags(char *p);
void COMM_BTL_DEMO_MAIN_Init3dSystem(void);
extern const char callbacks[];
extern const char ov067_id[];
extern char overlay_id[];
extern const struct GfxEntry d_021BAF14[];
extern int d_021BB004[];
extern const struct AnimTable records;
extern const struct Vec3i gCommBtlDemoEffectPos0, gCommBtlDemoEffectPos1, gCommBtlDemoEffectPos2, gCommBtlDemoEffectPos3, gCommBtlDemoEffectPos4, gCommBtlDemoEffectPos5;
extern struct Vec3i zero;
extern int d_021BB324[],d_021BB330[],d_021BB360[];
extern const struct G3dUnitSetup d_021BB0F8[];
extern int d_021BB320;
extern const unsigned short d_021BB1A8[][4];

int COMM_BTL_DEMO_MAIN_Create(void *manager,int *state,struct CommBtlDemoArgs *args)
{
    struct CommBtlDemoMain *p;
    if(*state==1 && FADE_IsActive()==1) return 1;
    GF_OVERLAY_Load((sptr)ov067_id);
    GFL_HEAP_CreateChildHeap(1,116,0x80000);
    p=PROCSYS_AllocProcWork(manager,0x49D8,116);
    MI_CpuFill8(p,0,0x49D8);
    p->heap=116;
    p->args=args;
    p->mode=(u8)args->partyMode;
    p->variant=p->args->battleKind;
    COMM_BTL_DEMO_MAIN_InitializeFlags((u8 *)args);
    p->graphic=COMM_BTL_DEMO_GRAPHIC_Create(0,p->heap);
    p->font=GF_FONT_Create(23,0,0,0,p->heap);
    p->messages=MSGDATA_CreateFromArchive(0,2,65,p->heap);
    p->printQue=PRINTSYS_QUE_Create(p->heap);
    p->uiScene=UI_SCENE_Create(p->heap,(struct UiSceneEntry *)callbacks,3,COMM_BTL_DEMO_MAIN_GetModeIndex((const struct CommBtlDemoArgs *)args),p);
    COMM_BTL_DEMO_MAIN_LoadGraphics((sptr)((char *)p+8),p->heap,p->args->soundKind);
    COMM_BTL_DEMO_MAIN_InitGraphics((char *)p+0x24,p->graphic,p->heap);
    COMM_BTL_DEMO_MAIN_InitCursor((char *)p+0xC,p->graphic,p->heap);
    *(volatile u16 *)0x04000304 |= 0x8000;
    GFL_NET_RefreshWmIconAtTopRight(0,p->heap);
    FADE_Start(3,16,0,1);
    *state=1;
    return 0;
}

int COMM_BTL_DEMO_MAIN_Delete(struct ProcOwner *owner,int unused,const void *cfg,char *p) {
u16 heap;
BG_SYS_ChangeScroll(3,0,0);
if(*(int *)((uptr)cfg+0x44)==2 || *(int *)((uptr)cfg+0x44)==4)COMM_BTL_DEMO_MAIN_UpdateNetKind(p);
UI_SCENE_Delete(((struct CommBtlDemoMain *)p)->uiScene);
MSGDATA_Delete(((struct CommBtlDemoMain *)p)->messages);
PRINTSYS_QUE_Delete(((struct CommBtlDemoMain *)p)->printQue);
GF_FONT_Delete(((struct CommBtlDemoMain *)p)->font);
COMM_BTL_DEMO_MAIN_DeleteCursor(p+0xc);COMM_BTL_DEMO_MAIN_DeleteGraphics(p+0x24);
COMM_BTL_DEMO_GRAPHIC_Delete(((struct CommBtlDemoMain *)p)->graphic);
heap=((struct CommBtlDemoMain *)p)->heap;PROCSYS_FreeProcWork((struct Proc *)owner);GFL_HEAP_DeleteChecked(heap);GF_OVERLAY_Unload((sptr)overlay_id);return 1;
}

int COMM_BTL_DEMO_MAIN_Update(int a,int b,int c,char *p)
{
    COMM_BTL_DEMO_MAIN_DrawGraphics((unsigned char *)(p+0x24));
    if(UI_SCENE_Step(((struct CommBtlDemoMain *)p)->uiScene)) return 1;
    PRINTSYS_QUE_Main(((struct CommBtlDemoMain *)p)->printQue);
    COMM_BTL_DEMO_GRAPHIC_Draw(((struct CommBtlDemoMain *)p)->graphic);
    (((struct CommBtlDemoMain *)p)->frameCount)++;
    BG_SYS_ChangeScroll(3,0,((struct CommBtlDemoMain *)p)->frameCount/2);
    return 0;
}

/*
 * prototype: 49238 asm body saves entry r0 and forwards it to destructors; retain caller's resource argument.
 */
void COMM_BTL_DEMO_MAIN_LoadGraphics(int a,u16 heap,int index)
{
    void *p;
    p=ARC_TOOL_CreateHandle(181,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(p,d_021BAF14[index].cell,0,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(p,d_021BAF14[index].palette,3,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(p,d_021BAF14[index].anim,3,0,0,0,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(p,4,4,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(p,3,6,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(p,5,6,0,0,0,heap);
    ARC_TOOL_DeleteHandle(p);
}

void COMM_BTL_DEMO_MAIN_Exit(u8 *task, char *p) {
    COMM_BTL_DEMO_MAIN_DeleteRows(p);
    COMM_BTL_DEMO_MAIN_DeleteBattleContext((struct CommBtlDemoBattleContext *)(p + 0x498C));
    UI_SCENE_SetNextScene((struct UiScene *)task,65534);
}

int COMM_BTL_DEMO_MAIN_Step(void *unused, struct CommBtlDemoMain *p) { COMM_BTL_DEMO_MAIN_InitRows(p); return 1; }

void COMM_BTL_DEMO_MAIN_SetupFirstSide(struct CommBtlDemoMain *p) {
    void *object;
    int i;
    struct CommBtlDemoGfx *sub;
    sub = &p->gfx;
    object = (void *)G3D_UTIL_GetObject((struct G3dUtil *)sub->util, sub->unitIndex);
    for(i=0;i<2;i++) {
        int state = 1;
        if (p->rows[i].paletteKind) state = 2;
        COMM_BTL_DEMO_MAIN_BindModelPalette(object,i+1,state);
    }
}

void COMM_BTL_DEMO_MAIN_SetupSecondSide(struct CommBtlDemoMain *p) {int *object;int i;struct CommBtlDemoGfx *sub;sub=&p->gfx;object=(int *)G3D_UTIL_GetObject((struct G3dUtil *)sub->util,sub->unitIndex);for(i=0;i<4;i++){int value=1;if(p->rows[i].paletteKind)value=3;COMM_BTL_DEMO_MAIN_BindModelPalette(object,i+1,value);}}

int COMM_BTL_DEMO_MAIN_GetSoundId(int a, int b)
{
    return *(int *)((char *)d_021BB004 + a * 8 + b * 4);
}

int COMM_BTL_DEMO_MAIN_Tick(u8 *task,char *p)
{
    u32 state;
    struct AnimRecord a,b,c,d;
    state=UI_SCENE_GetPhaseFrame(task);
    COMM_BTL_DEMO_MAIN_UpdateRows(p);
    switch(state) {
    case 0:
        COMM_BTL_DEMO_MAIN_InitEffect((u8 *)p+0x24,13);
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode)) {
            COMM_BTL_DEMO_MAIN_LoadObject((u8 *)p+0x24,0);
            COMM_BTL_DEMO_MAIN_SetupFirstSide((struct CommBtlDemoMain *)p);
        } else {
            COMM_BTL_DEMO_MAIN_LoadObject((u8 *)p+0x24,2);
            COMM_BTL_DEMO_MAIN_SetupSecondSide((struct CommBtlDemoMain *)p);
        }
        COMM_BTL_DEMO_MAIN_MarkRowsDone(p);
        UI_SCENE_AdvancePhaseFrame(task);
        break;
    case 1:
        if(COMM_BTL_DEMO_MAIN_UpdateObjectAnime((u8 *)p+0x24)==0) {
            COMM_BTL_DEMO_MAIN_LoadObject((u8 *)p+0x24,4);
            if(((struct CommBtlDemoMain *)p)->args->soundKind) COMM_BTL_DEMO_MAIN_InitEffect((u8 *)p+0x24,11);
            else COMM_BTL_DEMO_MAIN_InitEffect((u8 *)p+0x24,10);
            ((struct CommBtlDemoMain *)p)->stage=0;
            UI_SCENE_AdvancePhaseFrame(task);
        }
        break;
    case 2:
        COMM_BTL_DEMO_MAIN_UpdateObjectAnime((u8 *)p+0x24);
        if(((struct CommBtlDemoMain *)p)->stage==15) {
            GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(1,((struct CommBtlDemoMain *)p)->args->soundKind));
            a=records.recA; COMM_BTL_DEMO_MAIN_StartEffect(p+0x24,0,(sptr)&a);
            b=records.recD; COMM_BTL_DEMO_MAIN_StartEffect(p+0x24,1,(sptr)&b);
            c=records.recB; COMM_BTL_DEMO_MAIN_StartEffect(p+0x24,2,(sptr)&c);
        } else if(((struct CommBtlDemoMain *)p)->stage==25) {
            d=records.recC; COMM_BTL_DEMO_MAIN_StartEffect(p+0x24,3,(sptr)&d);
        } else if(((struct CommBtlDemoMain *)p)->stage==160) { FADE_Start(12,0,16,-3);
        } else if(((struct CommBtlDemoMain *)p)->stage==150) { GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(3,((struct CommBtlDemoMain *)p)->args->soundKind));
        } else if(((struct CommBtlDemoMain *)p)->stage==168) {return 1;
        }
        (((struct CommBtlDemoMain *)p)->stage)++;
        break;
    }
    return 0;
}

int COMM_BTL_DEMO_MAIN_Exit2(u8 *task,void *p) {COMM_BTL_DEMO_MAIN_DeleteRows((char *)p);UI_SCENE_SetNextScene((struct UiScene *)task,65534);return 1;}

int COMM_BTL_DEMO_MAIN_LayoutRows(int unused,char *p)
{
    u16 a,b;
    COMM_BTL_DEMO_MAIN_InitRows((struct CommBtlDemoMain *)p);
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode)) {
        a=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args);
        b=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args+16);
    } else {
        a=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args);
        a+=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args+16);
        b=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args+32);
        b+=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct CommBtlDemoMain *)p)->args+48);
    }
    COMM_BTL_DEMO_MAIN_InitBattleContext((struct CommBtlDemoBattleContext *)(p+0x498C), p+0xC, p+0x24, a, b, ((struct CommBtlDemoMain *)p)->mode);
    return 1;
}

int COMM_BTL_DEMO_MAIN_UpdateBattle(unsigned char *state,unsigned char *p)
{
    int stage,x,y,index;
    struct Vec3i effectPos0,effectPos1,effectPos2,effectPos3,effectPos4,effectPos5;
    stage=UI_SCENE_GetPhaseFrame(state);
    COMM_BTL_DEMO_MAIN_UpdateRows((char *)p);COMM_BTL_DEMO_MAIN_UpdateBattleActors((char *)(p+0x498c));
    switch(stage){
    case 0:
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode))COMM_BTL_DEMO_MAIN_LoadObject(p+0x24,1);
        else COMM_BTL_DEMO_MAIN_LoadObject(p+0x24,3);
        COMM_BTL_DEMO_MAIN_InitEffect(p+0x24,0xd);
        COMM_BTL_DEMO_MAIN_MarkRowsDone((char *)p);UI_SCENE_AdvancePhaseFrame((unsigned char *)state);break;
    case 1:
        if(COMM_BTL_DEMO_MAIN_UpdateObjectAnime(p+0x24)==0){
            if(((struct CommBtlDemoMain *)p)->variant==2)return 1;
            ((struct CommBtlDemoMain *)p)->stage=0;
            COMM_BTL_DEMO_MAIN_InitEffect(p+0x24,0xc);UI_SCENE_AdvancePhaseFrame(state);
        }break;
    case 2:
        if(((struct CommBtlDemoMain *)p)->stage==15){
            index=((struct CommBtlDemoMain *)p)->variant!=0;
            GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(2,((struct CommBtlDemoMain *)p)->args->soundKind));
            COMM_BTL_DEMO_MAIN_ShowBattleActor((struct CommBtlDemoBattleContext *)(p+0x498c),index,0);
        }else if(((struct CommBtlDemoMain *)p)->stage==24){
            index=((struct CommBtlDemoMain *)p)->variant!=0;
            CLACT_SetActorDrawEnable(((struct CommBtlDemoBattleContext *)(p+0x498c))->sideActor[index],0);
        }else if(((struct CommBtlDemoMain *)p)->stage==45){
            index=((struct CommBtlDemoMain *)p)->variant!=1;
            COMM_BTL_DEMO_MAIN_ShowBattleActor((struct CommBtlDemoBattleContext *)(p+0x498c),index,1);
        }else if(((struct CommBtlDemoMain *)p)->stage==54){
            index=((struct CommBtlDemoMain *)p)->variant!=1;
            CLACT_SetActorDrawEnable(((struct CommBtlDemoBattleContext *)(p+0x498c))->sideActor[index],0);
        }else if(((struct CommBtlDemoMain *)p)->stage==120)FADE_Start(3,0,16,-3);
        else if(((struct CommBtlDemoMain *)p)->stage==128)return 1;
        if((int)((struct CommBtlDemoMain *)p)->stage%180==0){
            if(((struct CommBtlDemoMain *)p)->variant==1){x=-0x2800;y=0x2000;}
            else{x=0x2800;y=-0x1800;}
            effectPos0=gCommBtlDemoEffectPos0;effectPos0.x=x;effectPos0.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),0,(sptr)(&effectPos0));
            effectPos1=gCommBtlDemoEffectPos1;effectPos1.x=x;effectPos1.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),1,(sptr)(&effectPos1));
            effectPos2=gCommBtlDemoEffectPos2;effectPos2.x=x;effectPos2.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),2,(sptr)(&effectPos2));
            effectPos3=gCommBtlDemoEffectPos3;effectPos3.x=x;effectPos3.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),3,(sptr)(&effectPos3));
            effectPos4=gCommBtlDemoEffectPos4;effectPos4.x=x;effectPos4.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),4,(sptr)(&effectPos4));
            effectPos5=gCommBtlDemoEffectPos5;effectPos5.x=x;effectPos5.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),5,(sptr)(&effectPos5));
        }
        (((struct CommBtlDemoMain *)p)->stage)++;break;
    }
    return 0;
}

int COMM_BTL_DEMO_MAIN_UpdateExit(u8 *task,char *p) {if(((struct CommBtlDemoMain *)p)->variant==2){GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(4,((struct CommBtlDemoMain *)p)->args->soundKind));UI_SCENE_SetNextScene((struct UiScene *)task,2);return 1;}COMM_BTL_DEMO_MAIN_Exit(task,p);return 1;}

int COMM_BTL_DEMO_MAIN_UpdateEnd(void *state,char *p)
{
    int stage;
    stage=UI_SCENE_GetPhaseFrame(state);
    COMM_BTL_DEMO_MAIN_UpdateRows(p);COMM_BTL_DEMO_MAIN_UpdateBattleActors(p+0x498C);
    switch(stage) {
    case 0:
        COMM_BTL_DEMO_MAIN_LoadObject((unsigned char *)(p+0x24),5);((struct CommBtlDemoMain *)p)->stage=0;UI_SCENE_AdvancePhaseFrame(state);break;
    case 1:
        if((((struct CommBtlDemoMain *)p)->stage)++==30) COMM_BTL_DEMO_MAIN_ShowBattleActor((struct CommBtlDemoBattleContext *)(p+0x498C),2,2);
        if(COMM_BTL_DEMO_MAIN_UpdateObjectAnime((unsigned char *)(p+0x24))==0) {FADE_Start(3,0,16,-3);return 1;}
        break;
    case 2:break;
    }
    return 0;
}

int COMM_BTL_DEMO_MAIN_UpdateFadeOut(void *a,void *b) {if(FADE_IsActive()==1)return 0;COMM_BTL_DEMO_MAIN_Exit(a,b);return 1;}

int COMM_BTL_DEMO_MAIN_GetModeIndex(const struct CommBtlDemoArgs *p) {switch(p->partyMode){case 1:case 3:return 0;case 2:case 4:return 1;case 0:default:return 0;}}

int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32 x) {switch(x){case 1:return 1;case 2:return 1;case 3:return 0;case 4:return 0;case 0:default:return 1;}}

int COMM_BTL_DEMO_MAIN_HasVisibleActors(u32 x) {switch(x){case 1:return 1;case 2:return 0;case 3:return 1;case 4:return 0;case 0:default:return 1;}}

int COMM_BTL_DEMO_MAIN_TypeToFrame(void *p,u32 x) {if(!p)return 13;switch(x){case 3:return 13;case 0:return 10;case 1:return 11;case 2:return 12;default:return 10;}}

/*
 * lever: negative constant multiplication keeps Thumb shift/negate/add; unary negation is folded back into constant-minus-shift.
 * POKEPARTY_GetCount 0x0201AA18 thumb
 * POKEPARTY_GetMember 0x0201AB28 thumb
 * COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 * COMM_BTL_DEMO_MAIN_HasVisibleActors 0x021B9E80 thumb ov213
 * COMM_BTL_DEMO_MAIN_TypeToFrame 0x021B9EB0 thumb ov213
 * COMM_BTL_DEMO_MAIN_CreateActor 0x021BA71C thumb ov213
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
void COMM_BTL_DEMO_MAIN_InitActorRow(struct CommBtlDemoActorRow *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types)
{
    int i,x,y,frame;
    void *entry;
    p->kind=kind;p->index=index;p->owner=owner;
    p->memberCount=POKEPARTY_GetCount(owner);
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(kind))p->actorCount=6;else p->actorCount=3;
    p->parent=parent;p->step=0;p->types=types;
    for(i=0;i<p->actorCount;i++){
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(kind)){
            x=(s16)((i<<4)+0x88);
            y=(s16)(index==0?0xa8:0x38);
            if(index==0)x*=-1;
        }else{
            switch(index){
            case 0:x=(s16)(i * -16+0x50);y=0x88;break;
            case 1:x=(s16)(i * -16+0x90);y=0xb0;break;
            case 2:x=(s16)((i<<4)+0x80);y=0x30;break;
            case 3:x=(s16)((i<<4)+0xc0);y=0x58;break;
            }
        }
        entry=0;
        if(i<p->memberCount)entry=POKEPARTY_GetMember(owner,i);
        frame=COMM_BTL_DEMO_MAIN_TypeToFrame(entry,types[i]);
        if(!COMM_BTL_DEMO_MAIN_HasVisibleActors(kind)&&frame!=0xd)frame=0xa;
        p->obj[i]=COMM_BTL_DEMO_MAIN_CreateActor(a,x,y,(u16)frame);
        if(COMM_BTL_DEMO_MAIN_HasVisibleActors(kind))CLACT_SetActorDrawEnable(p->obj[i],0);
        else CLACT_SetActorDrawEnable(p->obj[i],1);
    }
}

void COMM_BTL_DEMO_MAIN_DeleteActorRow(struct CommBtlDemoActorRow *p) {int i;for(i=0;i<p->actorCount;i++)CLACT_DeleteActor((struct ClactActor *)(p->obj[i]));}

void COMM_BTL_DEMO_MAIN_UpdateActorRow(struct CommBtlDemoActorRow *p, u32 time)
{
    int i=p->step-time;
    int x,y;
    struct Vec3i pos;
    if(i < p->actorCount) {
        if(i==0 && p->index==0) GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(0,0));
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(p->kind)) {
            if(p->index==0){x=-0x400-(i<<11);y=-0x2500;}
            else if(p->index==1){x=(i<<11)+0x300;y=0x1300;}
        } else {
            if(p->index==0){x=-0x1800-(i<<11);y=-0x1500;}
            else if(p->index==1){x=0x800-(i<<11);y=-0x2800;}
            else if(p->index==2){x=(i<<11)-0x100;y=0x1800;}
            else if(p->index==3){x=(i<<11)+0x1f00;y=0x300;}
        }
        pos=zero; pos.x=x; pos.y=y;
        COMM_BTL_DEMO_MAIN_StartEffects(p->parent,(sptr)(&pos));
        if(COMM_BTL_DEMO_MAIN_HasVisibleActors(p->kind)) CLACT_SetActorDrawEnable(p->obj[i],1);
        else COMM_BTL_DEMO_MAIN_SetRowActorAnim(p,p->owner,p->types,p->actorCount-1-i);
    } else {
        for(i=0;i<p->actorCount;i++) CLACT_SetActorBgPriority(p->obj[i],1);
        p->active=0;
    }
}

void COMM_BTL_DEMO_MAIN_UpdateRowDelay(struct CommBtlDemoActorRow *p,unsigned limit)
{
    if(p->active) {
        switch(p->kind) {
        case 0:break;
        case 1:limit=12;break;
        case 3:
            if(p->index==0 || p->index==2) limit=15;
            else if(p->index==1 || p->index==3) limit=19;
            break;
        case 2:limit=8;break;
        case 4:
            if(p->index==0 || p->index==2) limit=11;
            else if(p->index==1 || p->index==3) limit=15;
            break;
        }
        if(p->step>=limit) COMM_BTL_DEMO_MAIN_UpdateActorRow(p,limit);
        (p->step)++;
    }
}

void COMM_BTL_DEMO_MAIN_MarkRowDone(struct CommBtlDemoActorRow *p) {p->active=1;}

void COMM_BTL_DEMO_MAIN_SetRowActorAnim(struct CommBtlDemoActorRow *p,void *list,const u8 *flags,int index) {void *entry=0;int value;if(index<(int)POKEPARTY_GetCount(list))entry=POKEPARTY_GetMember(p->owner,index);value=COMM_BTL_DEMO_MAIN_TypeToFrame(entry,flags[index]);CLACT_ChangeActorAnimSeq((struct ClactActor *)(p->obj[index]),value);}

unsigned COMM_BTL_DEMO_MAIN_CreateRowWindow(unsigned kind,unsigned index)
{
    int x,y;
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(kind)) {
        if(index==0) {x=4;y=17;}
        else {x=16;y=3;}
    } else {
        switch(index) {
        case 0:x=5;y=13;break;
        case 1:x=13;y=19;break;
        case 2:x=15;y=1;break;
        case 3:x=23;y=7;break;
        }
    }
    return BMP_WIN_Create(1,(unsigned char)x,(unsigned char)y,10,3,1,1);
}

/*
 * extent: 021BA2DE..021BA2E0 is two zero alignment bytes; following021BA2E0 already filed separately.
 * lever: logical owner,a,b,c,zero field order restores stack-load scheduling; const owner and typed destination alone did not.
 */
void COMM_BTL_DEMO_MAIN_InitRowContext(struct CommBtlDemoRow *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c)
{
    void *first,*second;
    int value;
    value=c;first=a;second=b;
    p->owner=owner;p->actorBase=first;p->parent=second;
    p->textArg=value;p->counter=0;
    p->kind=kind;p->index=index;
    COMM_BTL_DEMO_MAIN_InitActorRow(&p->actor,((struct CommBtlDemoSide *)owner)->party,kind,index,a,b,(const unsigned char *)(owner+10));
    p->textBuf=STRBUF_Create(16,116);
    MYSTATUS_NameToStrbuf(((struct CommBtlDemoSide *)(p->owner))->textSys,p->textBuf);
    p->paletteKind=MYSTATUS_GetSex(((struct CommBtlDemoSide *)(p->owner))->textSys);
    p->window=COMM_BTL_DEMO_MAIN_CreateRowWindow(kind,index);
    if(COMM_BTL_DEMO_MAIN_HasVisibleActors(p->kind)==0) COMM_BTL_DEMO_MAIN_DrawRowText(p,p->textArg);
}

void COMM_BTL_DEMO_MAIN_RefreshRowText(struct CommBtlDemoRow *a)
{
    if ((int)a->counter == 0x2d)
        COMM_BTL_DEMO_MAIN_DrawRowText(a, a->textArg);
}

void COMM_BTL_DEMO_MAIN_DeleteRowContext(struct CommBtlDemoRow *p) {STRBUF_Delete((struct Strbuf *)(p->textBuf));COMM_BTL_DEMO_MAIN_DeleteActorRow(&p->actor);BMP_WIN_Delete((struct BmpWin *)(p->window));}

void COMM_BTL_DEMO_MAIN_UpdateRowContext(p,limit)
struct CommBtlDemoRow *p;

unsigned limit;

{COMM_BTL_DEMO_MAIN_UpdateRowDelay(&p->actor,limit);if(COMM_BTL_DEMO_MAIN_HasVisibleActors(p->kind))COMM_BTL_DEMO_MAIN_RefreshRowText(p);(p->counter)++;}

/*
 * note:     2026-10-05: the zero is passed in each arm's call of GF_FONT_SetTextColor
 *           (call written per arm), and PRINTSYS_Print takes a fifth argument
 *           (stack word); 8 byte gap closed. EXACT* (trailing alignment).
 */
void COMM_BTL_DEMO_MAIN_DrawRowText(struct CommBtlDemoRow *p, int a)
{
    int z = 0;
    sptr q;

    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)p->window), z);
    if ((int)p->paletteKind == 0)
        GF_FONT_SetTextColor(5, 6, z);
    else
        GF_FONT_SetTextColor(3, 4, z);
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)p->window), 1, 1, (void *)(p->textBuf), (void *)a);
    q = p->window;
    BMP_WIN_TransferChars((struct BmpWin *)q);
    BMP_WIN_MakeScreen((struct BmpWin *)q);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)q));
}

void COMM_BTL_DEMO_MAIN_InitRows(struct CommBtlDemoMain *p)
{
    int i;
    enum Count count;
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(p->mode)) count=CountTwo;
    else count=CountFour;
    for(i=0;i<count;i++)
        COMM_BTL_DEMO_MAIN_InitRowContext(&p->rows[i],p->mode,i,(char *)p->args+i*16,(char *)p+0xC,(char *)p+0x24,(sptr)p->font);
}

void COMM_BTL_DEMO_MAIN_DeleteRows(char *p){int i;enum Count count;if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)COMM_BTL_DEMO_MAIN_DeleteRowContext((struct CommBtlDemoRow *)(p+i*84));}

void COMM_BTL_DEMO_MAIN_UpdateRows(char *p){int i;enum Count count;if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)COMM_BTL_DEMO_MAIN_UpdateRowContext((struct CommBtlDemoRow *)(p+i*84));}

void COMM_BTL_DEMO_MAIN_MarkRowsDone(char *p){int i;enum Count count;if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoMain *)p)->mode))count=CountTwo;else count=CountFour;p+=0x485C;for(i=0;i<count;i++)COMM_BTL_DEMO_MAIN_MarkRowDone((struct CommBtlDemoActorRow *)(p+i*84));}

void COMM_BTL_DEMO_MAIN_SetActorAnimKind(void *p,int kind,int variant)
{
    switch(kind) {
    case 13:
        if(variant==0) RECORD_AddOne(p,14);
        else if(variant==1) RECORD_AddOne(p,15);
        break;
    case 37:
        if(variant==0) RECORD_AddOne(p,38);
        else if(variant==1) RECORD_AddOne(p,39);
        break;
    case 17:
        if(variant==0) RECORD_AddOne(p,18);
        else if(variant==1) RECORD_AddOne(p,19);
        else if(variant==2) RECORD_AddOne(p,20);
        break;
    }
    RECORD_AddOne(p,kind);
}

void COMM_BTL_DEMO_MAIN_UpdateNetKind(char *p)
{
    if(((struct CommBtlDemoMain *)p)->args->animTarget) {
        switch((int)GFL_NET_GetGameKind()) {
        case 37:case 12:case 31:COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct CommBtlDemoMain *)p)->args->animTarget,37,((struct CommBtlDemoMain *)p)->variant);break;
        case 10:COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct CommBtlDemoMain *)p)->args->animTarget,17,((struct CommBtlDemoMain *)p)->variant);break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            COMM_BTL_DEMO_MAIN_SetActorAnimKind(((struct CommBtlDemoMain *)p)->args->animTarget,13,((struct CommBtlDemoMain *)p)->variant);break;
        }
    }
}

/*
 * lever: source kind,a,b emits image a,kind,b stores and both entry copies; source a,kind,b left115 differing bytes.
 * domain: loop index is exactly 0,1,2; each switch arm initializes both coordinates before use.
 */
void COMM_BTL_DEMO_MAIN_InitBattleContext(struct CommBtlDemoBattleContext *p,const void *owner,void *other,u16 a,u16 b,u8 kind)
{
    int i,x,y;
    p->owner=owner;p->other=other;
    p->kind=kind;p->sideACount=a;p->sideBCount=b;
    p->sideActor[0]=COMM_BTL_DEMO_MAIN_CreateSideActor((void *)owner,0,(u8)p->sideACount);
    p->sideActor[1]=COMM_BTL_DEMO_MAIN_CreateSideActor((void *)owner,1,(u8)p->sideBCount);
    for(i=0;i<3;i++) {
        switch(i) {
        case 0:x=206;y=152;break;
        case 1:x=50;y=40;break;
        case 2:x=128;y=96;break;
        }
        p->actors[i]=COMM_BTL_DEMO_MAIN_CreateActor((void *)owner,x,y,7);
        CLACT_SetActorDrawEnable(p->actors[i],0);
    }
}

void COMM_BTL_DEMO_MAIN_DeleteBattleContext(struct CommBtlDemoBattleContext *p){int i;for(i=0;i<3;i++)CLACT_DeleteActor(p->actors[i]);for(i=0;i<2;i++)CLACT_DeleteActor(p->sideActor[i]);}

void COMM_BTL_DEMO_MAIN_UpdateBattleActors(char *p){COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct CommBtlDemoBattleContext *)p)->kind);if(((struct CommBtlDemoBattleContext *)p)->timer==30){CLACT_SetActorDrawEnable(((struct CommBtlDemoBattleContext *)p)->sideActor[0],1);CLACT_SetActorAutoAnim(((struct CommBtlDemoBattleContext *)p)->sideActor[0],1);CLACT_SetActorDrawEnable(((struct CommBtlDemoBattleContext *)p)->sideActor[1],1);CLACT_SetActorAutoAnim(((struct CommBtlDemoBattleContext *)p)->sideActor[1],1);}(((struct CommBtlDemoBattleContext *)p)->timer)++;}

void COMM_BTL_DEMO_MAIN_ShowBattleActor(struct CommBtlDemoBattleContext *p,unsigned i,int kind){int n;switch(kind){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;}CLACT_SetActorDrawEnable(p->actors[i],1);CLACT_SetActorAutoAnim(p->actors[i],1);CLACT_ChangeActorAnimSeq(p->actors[i],n);}

void COMM_BTL_DEMO_MAIN_InitCursor(char *p, void *state, int heap)
{
    sptr resource;
    UiSceneActorGfxConfig config;
    ((struct CommBtlDemoCursor *)p)->state = state;
    ((struct CommBtlDemoCursor *)p)->heap = heap;
    config.mode=0;
    config.flags=0;
    config.archiveId=0xB5;
    config.cellId=9;
    config.paletteId=8;
    config.animId=7;
    config.frameId=6;
    config.alpha=0;
    config.flip=0;
    config.visible=4;
    resource=COMM_BTL_DEMO_GRAPHIC_GetCamera(state);
    UI_SCENE_LoadActorGfx((struct ActorGfxSet *)(p+8), (struct ActorGfxDesc *)(&config), (void *)resource, heap);
}

void COMM_BTL_DEMO_MAIN_DeleteCursor(char *p){UI_SCENE_FreeActorGfx((struct ActorGfxSet *)(p+8));}

void *COMM_BTL_DEMO_MAIN_CreateActor(char *p,int a,int b,unsigned short c){return UI_SCENE_CreateActor((struct ActorGfxSet *)(p+8),(void *)(COMM_BTL_DEMO_GRAPHIC_GetCamera(((struct CommBtlDemoCursor *)p)->state)),a,b,c,((struct CommBtlDemoCursor *)p)->heap);}

void *COMM_BTL_DEMO_MAIN_CreateSideActor(void *p,int kind,unsigned a){int x,y;void *v;if(kind==0){x=206;y=152;}else{x=50;y=40;}v=COMM_BTL_DEMO_MAIN_CreateActor(p,x,y,a);CLACT_SetActorDrawEnable(v,0);CLACT_SetActorDrawPriority(v,1);return v;}

void COMM_BTL_DEMO_MAIN_InitGraphics(char *p,void *state,int heap){G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,1,31,0,0);((struct CommBtlDemoGfx *)p)->state=state;((struct CommBtlDemoGfx *)p)->heap=heap;((struct CommBtlDemoGfx *)p)->util=(struct Util *)G3D_UTIL_Create(16,20,heap);PARTICLE_InitManager(heap);}

void COMM_BTL_DEMO_MAIN_DeleteGraphics(char *p){COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(p);COMM_BTL_DEMO_MAIN_DeleteEffectManager(p);G3D_UTIL_Delete((struct G3dUtil *)(((struct CommBtlDemoGfx *)p)->util));}

void COMM_BTL_DEMO_MAIN_DrawGraphics(unsigned char *p)
{
    struct G3dDrawArg arg;
    void *object;
    COMM_BTL_DEMO_GRAPHIC_Draw3d(((struct CommBtlDemoGfx *)p)->state);
    if(((struct CommBtlDemoGfx *)p)->particleSystem) PARTICLE_Main();
    if(((struct CommBtlDemoGfx *)p)->loaded) {
        arg.pos.x=0; arg.pos.y=0; arg.pos.z=0;
        arg.scale.x=0x1000; arg.scale.y=0x1000; arg.scale.z=0x1000;
        MTX_Identity33_(&arg.rot);
        object=(void *)G3D_UTIL_GetObject((struct G3dUtil *)(*(Util * *)&((struct CommBtlDemoGfx *)p)->util),((struct CommBtlDemoGfx *)p)->unitIndex);
        G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&arg));
    }
    COMM_BTL_DEMO_GRAPHIC_DrawEnd(((struct CommBtlDemoGfx *)p)->state);
}

void COMM_BTL_DEMO_MAIN_InitEffect(u8 *p,unsigned code)
{
    struct ParticleCameraParam config;
    sptr resource;
    u32 context;
    if(*(int *)&((struct CommBtlDemoGfx *)p)->particleSystem) COMM_BTL_DEMO_MAIN_DeleteEffect((char *)p,*(int *)&((struct CommBtlDemoGfx *)p)->particleSystem);
    *(int *)&((struct CommBtlDemoGfx *)p)->particleSystem=(sptr)PARTICLE_CreateSystemDefault((sptr)(p+20),0x4800,1,((struct CommBtlDemoGfx *)p)->heap);
    config.f04=0x3000;
    config.f08=-0x3000;
    config.f00=2;
    config.f0c=-0x4000;
    config.f10=0x4000;
    config.f14=0x1000;
    config.f18=0x400000;
    config.f1c=0;
    PARTICLE_ReleaseCamera((struct ParticleSys *)(*(int *)&((struct CommBtlDemoGfx *)p)->particleSystem));
    PARTICLE_InitCamera((struct ParticleSys *)(*(struct ParticleCamera * *)&((struct CommBtlDemoGfx *)p)->particleSystem),(struct ParticleCameraParams *)&config,0x2000,(Vec3 *)d_021BB330,(Vec3 *)d_021BB324,(Vec3 *)d_021BB360,((struct CommBtlDemoGfx *)p)->heap);
    resource=(sptr)PARTICLE_LoadArchiveMember(0xB5,code,((struct CommBtlDemoGfx *)p)->heap);
    ((struct CommBtlDemoGfx *)p)->resourceType=PARTICLE_RESOURCE_GetType((void *)resource);
    context=(uptr)GFL_USE_GetMainTaskList();
    PARTICLE_SetupSystem((struct ParticleSys *)(*(u8 * *)&((struct CommBtlDemoGfx *)p)->particleSystem),(void *)resource,0,context);
}

void COMM_BTL_DEMO_MAIN_DeleteEffect(char *p, int object) { PARTICLE_KillAllEffects((struct ParticleSys *)(*(u8 * *)&((struct CommBtlDemoGfx *)p)->particleSystem)); PARTICLE_DeleteSystem((struct ParticleSys *)(*(u8 * *)&((struct CommBtlDemoGfx *)p)->particleSystem)); *(u32 *)&((struct CommBtlDemoGfx *)p)->particleSystem=0; }

void COMM_BTL_DEMO_MAIN_DeleteEffectManager(char *p) { if(*(u8 * *)&((struct CommBtlDemoGfx *)p)->particleSystem) PARTICLE_DeleteSystem((struct ParticleSys *)(*(u8 * *)&((struct CommBtlDemoGfx *)p)->particleSystem)); PARTICLE_ExitManager(); }

int COMM_BTL_DEMO_MAIN_StartEffect(char *p,int b,int c) { return PARTICLE_StartEffect(((struct CommBtlDemoGfx *)p)->particleSystem,b,c); }

/*
 * The original truncates the second call argument to u16; the extern preserves that width.
 */
void COMM_BTL_DEMO_MAIN_StartEffects(char *p,int v) { int i; for(i=0;i<((struct CommBtlDemoGfx *)p)->resourceType;i++) COMM_BTL_DEMO_MAIN_StartEffect(p,(u16)i,v); }

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int COMM_BTL_DEMO_MAIN_BindModelPalette(int *p,u32 b,u32 c) { int *q; char *a,*h,*r; q=(int *)G3D_SYSTEM_GetObjectRender(p); a=(char *)G3D_SYSTEM_GetRenderTexRes(q); h=*(char * *)&((struct G3dRenderObjRef *)((char *)G3D_SYSTEM_GetRenderObj(q)))->resMdl; r=(char *)G3D_SYSTEM_GetResourceTex((struct G3dResource *)a); NNS_G3dReleaseMdlPltt((struct NNSG3dResMdl *)h); return NNS_G3dBindMdlPlttEx((struct NNSG3dResMdl *)h,(struct NNSG3dResTex *)r,b,c)&1; }

/*
 * width: 477A4 index u16: original narrows at 021BA994-021BA998.
 */
void COMM_BTL_DEMO_MAIN_LoadObject(unsigned char *p, int index)
{
    int *object;
    int i, count;
    if (((struct CommBtlDemoGfx *)p)->loaded) COMM_BTL_DEMO_MAIN_UnloadObject((char *)p);
    ((struct CommBtlDemoGfx *)p)->unitIndex=G3D_UTIL_AddUnit((struct G3dUtil *)(*(Util * *)&((struct CommBtlDemoGfx *)p)->util), (struct G3dUtilSetup *)(&d_021BB0F8[index]));
    ((struct CommBtlDemoGfx *)p)->loaded=1;
    object=(int *)G3D_UTIL_GetObject((struct G3dUtil *)(*(Util * *)&((struct CommBtlDemoGfx *)p)->util), ((struct CommBtlDemoGfx *)p)->unitIndex);
    count=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)object);
    for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)object,(u16)i);
}

void COMM_BTL_DEMO_MAIN_UnloadObject(char *p) { G3D_UTIL_RemoveUnit(*(struct G3dUtil * *)&((struct CommBtlDemoGfx *)p)->util,((struct CommBtlDemoGfx *)p)->unitIndex); ((struct CommBtlDemoGfx *)p)->loaded=0; ((struct CommBtlDemoGfx *)p)->animeDone=0; }

void COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(void *a)
{
    if (((struct CommBtlDemoGfx *)a)->loaded)
        COMM_BTL_DEMO_MAIN_UnloadObject(a);
}

int COMM_BTL_DEMO_MAIN_UpdateObjectAnime(unsigned char *p)
{
    int result=1;
    int *object;
    int count,i;
    if(((struct CommBtlDemoGfx *)p)->animeDone) return 0;
    object=(int *)G3D_UTIL_GetObject((struct G3dUtil *)(*(Util * *)&((struct CommBtlDemoGfx *)p)->util), ((struct CommBtlDemoGfx *)p)->unitIndex);
    count=G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)object);
    for(i=0;i<count;i++) {
        result=G3D_SYSTEM_LoopObjectAnimeFrame((struct G3dObject *)object,(u16)i,d_021BB320<<12);
        if(!result) ((struct CommBtlDemoGfx *)p)->animeDone=1;
    }
    return result;
}

/*
 * extent: 021BAA8A..021BAA8C is two zero alignment bytes, no follower.
 */
void COMM_BTL_DEMO_MAIN_InitializeFlags(unsigned char *p)
{
    int i;
    if(((struct CommBtlDemoArgs *)p)->partyMode==1) {
        int j;
        unsigned char *row;
        for(i=0;i<2;i++) {
            row=p+16*i;
            for(j=0;j<(int)POKEPARTY_GetCount(((struct CommBtlDemoSide *)row)->party);j++) row[10+j]=0;
        }
        return;
    }
    if(((struct CommBtlDemoArgs *)p)->partyMode==3) {
        unsigned char *row;
        int j;
        for(i=0;i<4;i++) {
            row=p+16*i;
            for(j=0;j<(int)POKEPARTY_GetCount(((struct CommBtlDemoSide *)row)->party);j++) row[10+j]=0;
        }
    }
}

int COMM_BTL_DEMO_MAIN_CountFlags(char *p) { void *q; u8 *flags; int i,n; q=((struct CommBtlDemoSide *)p)->party; n=0; flags=((struct CommBtlDemoSide *)p)->flags; for(i=0;i<(int)POKEPARTY_GetCount(q);i++) if(flags[i]<=1) n++; return n; }

static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }

static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }

static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)REG_ALPHA_TEST_REF_ADDR = ref; } else REG3D &= (unsigned short)~0x3004; }

static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }

static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }

void COMM_BTL_DEMO_MAIN_Init3dSystem(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(GX_SHADING_HIGHLIGHT);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, (struct G3dLight *)d_021BB1A8[i]);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}
