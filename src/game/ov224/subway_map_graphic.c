/*
 * file:     subway_map_graphic.c
 * unit:     yes
 * function: SUBWAY_MAP_GRAPHIC_Init, SUBWAY_MAP_GRAPHIC_Exit, SUBWAY_MAP_GRAPHIC_Main, SUBWAY_MAP_GRAPHIC_TaskNoop, SUBWAY_MAP_GRAPHIC_LoadCommonAssets, SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets, SUBWAY_MAP_GRAPHIC_Setup3d, SUBWAY_MAP_GRAPHIC_CreateScreen, SUBWAY_MAP_GRAPHIC_DeleteScreen, SUBWAY_MAP_GRAPHIC_DrawScreen, SUBWAY_MAP_GRAPHIC_VBlankScreen, SUBWAY_MAP_GRAPHIC_CreateBg, SUBWAY_MAP_GRAPHIC_DeleteBg, SUBWAY_MAP_GRAPHIC_DrawBg, SUBWAY_MAP_GRAPHIC_VBlankBg, SUBWAY_MAP_GRAPHIC_CreateClactUnit, SUBWAY_MAP_GRAPHIC_DeleteClactUnit, SUBWAY_MAP_GRAPHIC_DrawClactUnit, SUBWAY_MAP_GRAPHIC_VBlankClactUnit, SUBWAY_MAP_GRAPHIC_CreateCamera, SUBWAY_MAP_GRAPHIC_DeleteCamera
 * address:  0x021B95A0
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GXS_SetGraphicsMode 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   gSubwayMapGraphicSubBgLayerTable 0x021B9C04 data a4
 *   gSubwayMapGraphicChoiceAssets 0x021B9D40 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   gSubwayMapGraphicLightParams 0x021B9C80 data ov224
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   sSubwayMapGraphicFile 0x021B9D58 data ov224 a1
 *   sSubwayMapGraphicVram 0x021B9CA0 data
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   sSubwayMapGraphicConfig 0x021B9C54 data
 *   gSubwayMapGraphicMainBgLayerTable 0x021B9CD0 data ov224
 *   d_021B9CD0 0x021B9CD0 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   gCameraParams 0x020A1EB8 data
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */
#define DISP (*(volatile u16 *)REG_DISP3DCNT_ADDR)
struct GfFont;
struct Proc;
struct Node;
struct PrintSys;
struct Proc;
struct Bank;
struct Cfg;
#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/arc_util.h"
#include "../arm9/ui.h"
#include "../types.h"

struct G3dCamera;
struct VecFx32;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

typedef enum { SUB_BG_LAYER_FIRST = 0, SUB_BG_LAYER_SECOND = 1 } SubBgLayerIndex;

typedef enum { SUB_DISPLAY_MODE_2 = 2 } SubDisplayMode;

struct SubwayMapGraphicEntry { u32 id; struct BgTemplate bg; u32 kind,visible; };

struct Assets {u32 palette,screen,chars;};

struct SubwayMapWork {u16 heap,pad2; void **args; void *screen,*font;u32 string;void *task;};

struct SubwayMapClactUnit {void *unit;};

struct SubwayMapScreen {u32 bgState; struct SubwayMapClactUnit clactUnit; void *camera; void *task;};

#include "../sdk_gx.h"

struct SubwayMapGraphicRecord { u32 id; u32 bg[8]; u32 kind; u32 visible; };

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
extern void BG_SYS_SetPriority(int,u16);
#include "../arm9/gfl_use.h"
extern void BG_SYS_ClearSubPlanes(void);
#include "../arm9/gx.h"
extern void BG_SYS_ClearSubBgPlanes(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void BG_SYS_PushTile(u32);
#include "../arm9/fade.h"
#include "../arm9/net.h"
extern void BG_SYS_FreeLayerBuf(u32 i);
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
#include "../arm9/g3x.h"
struct G3dLight;
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
/* The DS code was built against other parameter widths for BG_SYS_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_Create(u32);
extern void G3D_SYSTEM_SetLight(u32 lightIdx, struct G3dLight *light);
#else
#include "../arm9/bg_sys.h"
#endif
extern void G3D_SYSTEM_Exit(void);
#include "../arm9/bmp_win.h"
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
/* The DS code was built against other parameter widths for G3D_SYSTEM_Init (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
#else
#include "../arm9/g3d_system.h"
#endif
/* The DS code was built against other parameter widths for G3D_CAMERA_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern struct G3dCamera *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct VecFx32 *,struct VecFx32 *,struct VecFx32 *,u32);
#else
#include "../arm9/g3d_camera.h"
#endif
extern u32 G3D_CAMERA_Delete(void *ptr);
int SUBWAY_MAP_GRAPHIC_Init(struct Proc *proc,void *unused,void **args);
int SUBWAY_MAP_GRAPHIC_Exit(void *a,int b,int c,char *p);
int SUBWAY_MAP_GRAPHIC_Main(void *a,unsigned *state,int b,char *p);
void SUBWAY_MAP_GRAPHIC_TaskNoop(struct TcbTask *unused, void *unused2);
void SUBWAY_MAP_GRAPHIC_LoadCommonAssets(u16 *work);
void SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(char *unused);
void SUBWAY_MAP_GRAPHIC_Setup3d(void);
void *SUBWAY_MAP_GRAPHIC_CreateScreen(u32 swap, u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteScreen(char *p);
void SUBWAY_MAP_GRAPHIC_DrawScreen(void *p);
void SUBWAY_MAP_GRAPHIC_VBlankScreen(struct TcbTask *unused, void *p);
void SUBWAY_MAP_GRAPHIC_CreateBg(void *p, u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteBg(void *p);
void SUBWAY_MAP_GRAPHIC_DrawBg(void *work);
void SUBWAY_MAP_GRAPHIC_VBlankBg(void *work);
void SUBWAY_MAP_GRAPHIC_CreateClactUnit(unsigned char *p, struct DispVramCfg *a, int b);
void SUBWAY_MAP_GRAPHIC_DeleteClactUnit(char *p);
void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *work);
void SUBWAY_MAP_GRAPHIC_VBlankClactUnit(void *work);
void SUBWAY_MAP_GRAPHIC_CreateCamera(void **p,u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteCamera(u32 *p);
extern const struct SubwayMapGraphicEntry gSubwayMapGraphicSubBgLayerTable[];
extern struct Assets gSubwayMapGraphicChoiceAssets[];
extern u16 gSubwayMapGraphicLightParams[][4];
extern char sSubwayMapGraphicFile[], sSubwayMapGraphicVram[];
extern u32 sSubwayMapGraphicConfig[];
extern struct SubwayMapGraphicRecord gSubwayMapGraphicMainBgLayerTable[];
extern const s16 gCameraParams[];
extern u32 vecA[],vecB[],vecC[];

static inline void GXS_SetMode(SubDisplayMode mode) {
 *(volatile u32 *)0x04001000 &= 0xffff1fff;
 *(volatile u32 *)0x04001000 |= mode<<15;
}

int SUBWAY_MAP_GRAPHIC_Init(struct Proc *proc,void *unused,void **args)
{
 struct SubwayMapWork *p;
 SubBgLayerIndex i;
 const struct SubwayMapGraphicEntry *row;
 u32 id,choice;
 u16 heap;
 void *arc;
 GFL_HEAP_CreateChildHeap((uptr)((void *)1),0x88,0x30000);
 p=PROCSYS_AllocProcWork(proc,0x18,0x88);
 MI_CpuFill8(p,0,0x18);
 p->heap=0x88; p->args=args;
 p->screen=SUBWAY_MAP_GRAPHIC_CreateScreen(1,p->heap);
 p->font=GF_FONT_Create(23,0,0,0,p->heap);
 p->string=(uptr)PRINTSYS_QUE_Create((u32)(u32)p->heap);
 BG_SYS_SetPriority(1,1); BG_SYS_SetPriority(2,0);
 p->task=GFL_USE_AddMainTask(SUBWAY_MAP_GRAPHIC_TaskNoop, p,1);
 SUBWAY_MAP_GRAPHIC_LoadCommonAssets((u16 *)p);
 i=SUB_BG_LAYER_FIRST;
 *(volatile u16 *)0x04001050=0;
 GXS_SetMode(SUB_DISPLAY_MODE_2);
 BG_SYS_ClearSubPlanes();
 GXS_SetGraphicsMode(0);
 BG_SYS_ClearSubBgPlanes();
 do {
  row=&gSubwayMapGraphicSubBgLayerTable[i]; id=row->id;
  BG_SYS_InitBgLayer((u8)id,&row->bg,(u8)row->kind);
  BG_SYS_FreeSlot(id);
  BG_SYS_SetPlaneVisible(id,row->visible);
  i++;
 }while(i<1U);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=p->heap;
 choice=1;
 if(*((u8 *)*p->args+0x1d)!=1) choice=0;
 arc=ARC_TOOL_CreateHandle(30,heap);
 ARC_UTIL_UploadPaletteFromHandleWhole(arc,gSubwayMapGraphicChoiceAssets[choice].palette,4,0,0,heap);
 ARC_UTIL_UploadBgCharFromHandle(arc,gSubwayMapGraphicChoiceAssets[choice].screen,4,0,0,0,heap);
 ARC_UTIL_UploadBgPaletteFromHandle(arc,gSubwayMapGraphicChoiceAssets[choice].chars,4,0,0,0,heap);
 ARC_TOOL_DeleteHandle(arc);
 BG_SYS_PushTile(4);
 FADE_Start(3,16,0,0);
 GFL_NET_RefreshWmIconAtTopRight(0,p->heap);
 return 1;
}

/*
 * lever: enum do-loop with unsigned bound retains one table iteration; unsigned for-loop folds it, enum for-loop adds an entry guard.
 * volatile: sub-display blend/control reads and writes 021B973C-021B9746.
 */
int SUBWAY_MAP_GRAPHIC_Exit(void *a,int b,int c,char *p)
{
    SubBgLayerIndex i=SUB_BG_LAYER_FIRST;
    do { BG_SYS_FreeLayerBuf((unsigned char)gSubwayMapGraphicSubBgLayerTable[i].id); i++; } while(i<1U);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=~0xe000;
    SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(p);
    TCB_DeleteTask(((struct SubwayMapWork *)p)->task); PRINTSYS_QUE_Clear((void *)((struct SubwayMapWork *)p)->string); PRINTSYS_QUE_Delete((void *)((struct SubwayMapWork *)p)->string);
    GF_FONT_Delete(((struct SubwayMapWork *)p)->font); SUBWAY_MAP_GRAPHIC_DeleteScreen(*(char * *)&((struct SubwayMapWork *)p)->screen);
    PROCSYS_FreeProcWork(a); GFL_HEAP_DeleteChecked(136);
    return 1;
}

int SUBWAY_MAP_GRAPHIC_Main(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2:
        flag=0;
        if(KEY_GetTrg()&3) { UI_SetInputMode(0); flag=1; }
        else if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) { UI_SetInputMode(1); flag=1; }
        if(flag) { *state=3; FADE_Start(3,0,16,0); }
        break;
    case 3: if(!FADE_IsActive()) *state=4; break;
    case 4: return 1;
    }
    PRINTSYS_QUE_Main((void *)((struct SubwayMapWork *)p)->string); SUBWAY_MAP_GRAPHIC_DrawScreen(((struct SubwayMapWork *)p)->screen);
    return 0;
}

void SUBWAY_MAP_GRAPHIC_TaskNoop(struct TcbTask *unused, void *unused2) {}

void SUBWAY_MAP_GRAPHIC_LoadCommonAssets(u16 *work)
{
    void *narc = ARC_TOOL_CreateHandle(0xce, *work);
    ARC_UTIL_UploadPaletteFromHandleWhole(narc, 0, 0, 0, 0, *work);
    ARC_UTIL_UploadBgCharFromHandle(narc, 1, 1, 0, 0, 0, *work);
    ARC_UTIL_UploadBgPaletteFromHandle(narc, 2, 1, 0, 0, 0, *work);
    ARC_UTIL_UploadBgPaletteFromHandle(narc, 3, 2, 0, 0, 0, *work);
    ARC_TOOL_DeleteHandle(narc);
    BG_SYS_PushTile(1);
    BG_SYS_PushTile(2);
}

void SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(char *unused) {}

static inline void G2_SetBG0Priority(int priority) {
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

static inline void G3X_SetShading(GXShading shading) {
    DISP = (u16)((DISP & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}

static inline void G3X_AntiAlias(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 16);
    else DISP &= (u16)~(16|0x1000|0x2000);
}

static inline void G3X_AlphaTest(int enable,int ref) {
    if(enable) { DISP = (u16)((DISP & ~(0x1000|0x2000)) | 4); *(volatile u16 *)REG_ALPHA_TEST_REF_ADDR = (u16)ref; }
    else DISP &= (u16)~(4|0x1000|0x2000);
}

static inline void G3X_AlphaBlend(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 8);
    else DISP &= (u16)~(8|0x1000|0x2000);
}

static inline void G3X_EdgeMarking(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 32);
    else DISP &= (u16)~(32|0x1000|0x2000);
}

void SUBWAY_MAP_GRAPHIC_Setup3d(void)
{
    u32 i;
    BG_SYS_SetMainPlaneVisible(1,1);
    i = 0;
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i,(struct G3dLight *)gSubwayMapGraphicLightParams[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}

static inline void G2_BlendNone(void) { *(volatile u16 *)REG_BLDCNT_ADDR = 0; }

static inline void G2S_BlendNone(void) { *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0; }

static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}

static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}

void *SUBWAY_MAP_GRAPHIC_CreateScreen(u32 swap, u32 heap)
{
    char *p = GFL_HEAP_Alloc(heap, 16, 0, sSubwayMapGraphicFile, 460);
    MI_CpuFill8(p, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)sSubwayMapGraphicVram);
    BG_SYS_SetLcdSwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    SUBWAY_MAP_GRAPHIC_CreateBg(p, heap);
    SUBWAY_MAP_GRAPHIC_CreateClactUnit((unsigned char *)p + 4, (struct DispVramCfg *)sSubwayMapGraphicVram, heap);
    SUBWAY_MAP_GRAPHIC_CreateCamera((void **)(p + 8), heap);
    ((struct SubwayMapScreen *)p)->task = GFL_USE_AddMainTask(SUBWAY_MAP_GRAPHIC_VBlankScreen, p, 0);
    return p;
}

void SUBWAY_MAP_GRAPHIC_DeleteScreen(char *p)
{
    TCB_DeleteTask(((struct SubwayMapScreen *)p)->task);
    SUBWAY_MAP_GRAPHIC_DeleteCamera((u32 *)(p + 8));
    SUBWAY_MAP_GRAPHIC_DeleteClactUnit(p + 4);
    SUBWAY_MAP_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 16);
    GFL_HEAP_Free(p);
}

void SUBWAY_MAP_GRAPHIC_DrawScreen(void *p)
{
    void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *);
    void SUBWAY_MAP_GRAPHIC_DrawBg(void *);
    SUBWAY_MAP_GRAPHIC_DrawClactUnit((char *)p + 4);
    SUBWAY_MAP_GRAPHIC_DrawBg(p);
}

/*
 * Addresses are Black-image addresses.
 */
void SUBWAY_MAP_GRAPHIC_VBlankScreen(struct TcbTask *unused, void *work_)
{ char * p = work_;
    SUBWAY_MAP_GRAPHIC_VBlankBg(p);
    SUBWAY_MAP_GRAPHIC_VBlankClactUnit(p + 4);
}

void SUBWAY_MAP_GRAPHIC_CreateBg(void *p, u32 heap)
{
    u32 i = 0;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)sSubwayMapGraphicConfig);
    for (; i < 2; i++) {
        struct SubwayMapGraphicRecord *r = &gSubwayMapGraphicMainBgLayerTable[i];
        u32 id = r->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id, r->visible);
    }
}

void SUBWAY_MAP_GRAPHIC_DeleteBg(void *p) {
    u32 i;
    for (i=0; i<2; i++) BG_SYS_FreeLayerBuf((u8)(*(const u32 *)((const u8 *)gSubwayMapGraphicMainBgLayerTable+i*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}

void SUBWAY_MAP_GRAPHIC_DrawBg(void *work) {}

void SUBWAY_MAP_GRAPHIC_VBlankBg(void *work) { BG_SYS_Update(); }

void SUBWAY_MAP_GRAPHIC_CreateClactUnit(unsigned char *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x021B9C64, (struct DispVramCfg *)a, b);
    ((struct SubwayMapClactUnit *)p)->unit = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct SubwayMapClactUnit *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void SUBWAY_MAP_GRAPHIC_DeleteClactUnit(char *p)
{
    CLACT_DeleteUnit((struct Unit *)(((struct SubwayMapClactUnit *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *work) { CLACT_DrawSystem(); }

void SUBWAY_MAP_GRAPHIC_VBlankClactUnit(void *work) { CLACT_VBlankSystem(); }

void SUBWAY_MAP_GRAPHIC_CreateCamera(void **p,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,SUBWAY_MAP_GRAPHIC_Setup3d);
    *p = G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,
        (struct VecFx32 *)vecA,(struct VecFx32 *)vecB,(struct VecFx32 *)vecC,heap);
}

void SUBWAY_MAP_GRAPHIC_DeleteCamera(u32 *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
