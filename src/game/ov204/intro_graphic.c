/*
 * file:     intro_graphic.c
 * unit:     yes
 * function: INTRO_GRAPHIC_Create, INTRO_GRAPHIC_Delete, INTRO_GRAPHIC_Main, INTRO_GRAPHIC_Setup3d, INTRO_GRAPHIC_CreateDisplay, INTRO_GRAPHIC_DeleteDisplay, INTRO_GRAPHIC_UpdateDisplay, INTRO_GRAPHIC_Draw3d, INTRO_GRAPHIC_Draw3dEnd, INTRO_GRAPHIC_GetClactOwner, INTRO_GRAPHIC_VBlank, INTRO_GRAPHIC_InitBg, INTRO_GRAPHIC_ExitBg, INTRO_GRAPHIC_ResetBgSlot, INTRO_GRAPHIC_UpdateBg, INTRO_GRAPHIC_InitBg7, INTRO_GRAPHIC_InitClact, INTRO_GRAPHIC_DeleteClact, INTRO_GRAPHIC_DrawClact, INTRO_GRAPHIC_VBlankClact, INTRO_GRAPHIC_InitCamera, INTRO_GRAPHIC_InitCamera7, INTRO_GRAPHIC_DeleteCamera, INTRO_GRAPHIC_DrawCamera, INTRO_GRAPHIC_SetScenario, INTRO_GRAPHIC_CmdSetScenario, INTRO_GRAPHIC_DrawMenuEntry, INTRO_GRAPHIC_CmdMenu, INTRO_GRAPHIC_CmdRunHandler, INTRO_GRAPHIC_CmdLoadPalette
 * address:  0x021BDA40
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   INTRO_MCSS_Create 0x021BF594 thumb ov204
 *   INTRO_G3D_Create 0x021BF8DC thumb ov204
 *   INTRO_PARTICLE_Create 0x021BFC24 thumb ov204
 *   INTRO_CMD_Create 0x021BEF20 thumb ov204
 *   ov067_id 0x00000043 data
 *   INTRO_PARTICLE_Delete 0x021BFCD0 thumb ov204
 *   INTRO_MCSS_Delete 0x021BF5E0 thumb ov204
 *   INTRO_G3D_Delete 0x021BF9D0 thumb ov204
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   INTRO_CMD_Delete 0x021BEF74 thumb ov204
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   INTRO_CMD_Main  0x021BEF88  thumb  ov204
 *   INTRO_G3D_UpdateIdleAnim  0x021BF898  thumb  ov204
 *   INTRO_MCSS_Main 0x021BF610  thumb  ov204
 *   INTRO_PARTICLE_Main 0x021BFCE0  thumb  ov204
 *   INTRO_G3D_Draw  0x021BF9FC  thumb  ov204
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BFDAC 0x021BFDAC data a2
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   gIntroGraphicSite 0x021C09C0 data a4
 *   d_021BFE4C 0x021BFE4C data a4
 *   d_021BFE1C 0x021BFE1C data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFF1C 0x021BFF1C data a4
 *   BG_SYS_Update 0x020419E4 arm
 *   d_021BFEFC 0x021BFEFC data a4
 *   d_021BFEDC 0x021BFEDC data a4
 *   d_021BFE7C 0x021BFE7C data a4
 *   d_021BFE9C 0x021BFE9C data a4
 *   d_021BFEBC 0x021BFEBC data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_CAMERA_SetNear 0x02048B60 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   gIntroGraphicCameraPos 0x021BFD68 data a4
 *   gIntroGraphicCameraTarget 0x021BFD5C data a4
 *   gIntroGraphicCameraUp 0x021BFD74 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021BFD4C 0x021BFD4C data a4
 *   d_021BFD54 0x021BFD54 data a4
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   G3D_SYSTEM_Exit  0x02046788  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   INTRO_CMD_GetScenarioRow 0x021BF094 thumb ov204
 *   INTRO_MSG_DrawMenuList 0x021BF4E8 thumb ov204
 *   INTRO_CMD_AddCommand 0x021BF00C thumb ov204
 *   INTRO_MSG_CreateMenuList 0x021BF384 thumb ov204
 *   INTRO_MSG_MainMenuList 0x021BF528 thumb ov204
 *   INTRO_MSG_GetMenuChoice 0x021BF538 thumb ov204
 *   gIntroGraphicHandlerTable 0x021C09D0 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 *   BMP_GetVisiblePlane  0x02043658  arm  arm9
 */
#include "intro_types.h"

#define REG3D (*(volatile unsigned short *)0x04000060)

struct Proc;
struct GfFont;
struct MsgBank;
struct Rec;
struct Proc;
struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Light;
struct LightSet;
struct LightSlot;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

typedef signed short s16;

typedef signed char s8;

struct BgTemplate { u32 a,b,c,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; };

struct DispConfig { unsigned int a, b, c, d; };

typedef struct { u32 x, y, z; } Vec3;

typedef struct { int a, b; } Pair;

typedef struct { Pair first, second; } Request;

/*
 * The intro graphic work (0x24 allocated). Created by INTRO_GRAPHIC_Create,
 * freed by INTRO_GRAPHIC_Delete, advanced by INTRO_GRAPHIC_Main.
 */
typedef struct IntroGraphicWork {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad_2[2];
    void *args;                 /* 0x04: IntroArgs */
    void *display;              /* 0x08: IntroDisplay */
    void *font;                 /* 0x0C: GF_FONT_Create result */
    void *msgBank;              /* 0x10: MSGDATA_CreateFromArchive result */
    void *cmdWork;              /* 0x14: IntroCmdWork */
    void *mcss;                 /* 0x18: IntroMcssWork */
    void *g3d;                  /* 0x1C: IntroG3dWork */
    void *particle;             /* 0x20: INTRO_PARTICLE_Create result */
} IntroGraphicWork;

/* The CLACT bank holder (4 bytes): the CLACT_CreateUnit result. */
typedef struct IntroClact {
    void *bank;                 /* 0x00 */
} IntroClact;

/* The 3D camera holder (8 bytes): camera and light slot. */
typedef struct IntroCamera {
    void *camera;               /* 0x00: G3D_CAMERA_Create result */
    void *lightSlot;            /* 0x04: G3D_LIGHT_CreateSlots result */
} IntroCamera;

/*
 * The display object (0x14 allocated) built by INTRO_GRAPHIC_CreateDisplay.
 */
typedef struct IntroDisplay {
    unsigned int bg;            /* 0x00: bg system slot, only ever zeroed */
    IntroClact clact;           /* 0x04 */
    IntroCamera camera;         /* 0x08 */
    void *vblank;               /* 0x10: GFL_USE_AddMainTask result */
} IntroDisplay;

extern int GF_OVERLAY_Load(int);
extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern struct GfFont *GF_FONT_Create(int, int, int, int, unsigned);
extern struct MsgBank *MSGDATA_CreateFromArchive(unsigned, unsigned, unsigned, unsigned);
extern void *INTRO_MCSS_Create(unsigned int heap, int kind);
extern char *INTRO_G3D_Create(void *owner, int kind, u32 heap);
extern char *INTRO_PARTICLE_Create(void *owner, unsigned heap);
extern char *INTRO_CMD_Create(void *, unsigned, unsigned, char *, unsigned, unsigned short);
extern void INTRO_PARTICLE_Delete(char *);
extern void INTRO_MCSS_Delete(u8 *p);
extern void INTRO_G3D_Delete(char *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void INTRO_CMD_Delete(u8 *p);
extern void PROCSYS_FreeProcWork(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void GF_OVERLAY_Unload(s32 handle);
extern int INTRO_CMD_Main(char *p);
extern void INTRO_G3D_UpdateIdleAnim(char *p);
extern void INTRO_MCSS_Main(u8 *p);
extern void INTRO_PARTICLE_Main(int);
extern void INTRO_G3D_Draw(char *p);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(BOOL, int, int, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, BOOL);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BMP_SetDisplaySwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void GF_FONT_InitTextColor(void);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void TCB_DeleteTask(struct Node *);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void BG_SYS_SetPlaneVisible(unsigned char, unsigned char);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern u32 BMP_GetVisiblePlane(void);
extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, u16 heap, void (*setupFn)(void));
extern u32 *G3D_CAMERA_Create(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                          Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
extern void G3D_CAMERA_SetFar(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetNear(struct Light *l, const u32 *in);
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void G3D_LIGHT_DeleteSlots(u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
/* Original consumes 02048AD0's live r0 through the next veneer call. */
extern void *G3D_CAMERA_Reset(struct Light *);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern char *INTRO_CMD_GetScenarioRow(int);
extern void INTRO_MSG_DrawMenuList(char *);
extern int INTRO_CMD_AddCommand(IntroCmdWork *, IntroCommand *);
extern void INTRO_MSG_CreateMenuList(char *p, u32 *entries, u32 count, int flag);
extern void INTRO_MSG_MainMenuList(u8 *p);
extern int INTRO_MSG_GetMenuChoice(u8 *p, int *out);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void MIi_CpuCopy16(const void *,void *,u32);
extern void ARC_TOOL_DeleteHandle(void *);
int INTRO_GRAPHIC_Create(struct Proc *owner, int unused, char *args);
int INTRO_GRAPHIC_Delete(struct Proc *owner, int unused1, int unused2, char *p);
int INTRO_GRAPHIC_Main(int a, int b, int c, void *p);
void INTRO_GRAPHIC_Setup3d(void);
void *INTRO_GRAPHIC_CreateDisplay(int swap, int mode, u16 heap);
void INTRO_GRAPHIC_DeleteDisplay(unsigned char *p);
void INTRO_GRAPHIC_UpdateDisplay(u8 *p);
void INTRO_GRAPHIC_Draw3d(char *p);
void INTRO_GRAPHIC_Draw3dEnd(char *p);
unsigned INTRO_GRAPHIC_GetClactOwner(char *p);
void INTRO_GRAPHIC_VBlank(u32 a, u8 *b);
void INTRO_GRAPHIC_InitBg(IntroDisplay *disp, unsigned heap);
void INTRO_GRAPHIC_ExitBg(IntroDisplay *disp);
void INTRO_GRAPHIC_ResetBgSlot(IntroDisplay *disp);
void INTRO_GRAPHIC_UpdateBg(void *a0);
void INTRO_GRAPHIC_InitBg7(IntroDisplay *disp,u16 heap);
void INTRO_GRAPHIC_InitClact(IntroClact *clact, int a, int b);
void INTRO_GRAPHIC_DeleteClact(IntroClact *clact);
void INTRO_GRAPHIC_DrawClact(void *a0);
void INTRO_GRAPHIC_VBlankClact(void *a0);
unsigned INTRO_GRAPHIC_GetClactBank(IntroClact *clact);
void INTRO_GRAPHIC_InitCamera(IntroCamera *cam, u16 heap);
void INTRO_GRAPHIC_InitCamera7(IntroCamera *cam, u16 heap);
void INTRO_GRAPHIC_DeleteCamera(IntroCamera *cam);
void INTRO_GRAPHIC_DrawCamera(IntroCamera *cam);
void INTRO_GRAPHIC_DrawEnd(IntroCamera *unused);
int INTRO_GRAPHIC_NoOp(void);
int INTRO_GRAPHIC_SetScenario(char *p, u32 b, int *c);
u32 INTRO_GRAPHIC_CmdSetScenario(u8 *p);
void INTRO_GRAPHIC_DrawMenuEntry(char *p, int which);
int INTRO_GRAPHIC_CmdMenu(char *p, int *state, int *values);
int INTRO_GRAPHIC_CmdRunHandler(char *p, int unused, unsigned *q);
int INTRO_GRAPHIC_CmdLoadPalette(char *p,void *unused,int *state);
int INTRO_GRAPHIC_CmdSetArg(char *p,void *unused,u32 *r);
int INTRO_GRAPHIC_CmdWaitFrame(void *unused,int *q,int *r);
extern const char ov067_id[];
extern const unsigned short d_021BFDAC[][4];
extern const struct DispVram d_021BFE4C,d_021BFE1C;
extern const char gIntroGraphicSite[];
extern const unsigned d_021BFF1C[][11];
extern struct DispConfig d_021BFD80;
extern const struct BgTemplate d_021BFEFC,d_021BFEDC,d_021BFE7C,d_021BFE9C,d_021BFEBC;
extern Vec3 gIntroGraphicCameraPos;
extern Vec3 gIntroGraphicCameraTarget;
extern Vec3 gIntroGraphicCameraUp;
extern const short d_020A1EB8[];
extern const struct LightSet d_021BFD4C;
extern const struct LightSet d_021BFD54;



int INTRO_GRAPHIC_Create(struct Proc *owner, int unused, char *args)
{
    IntroGraphicWork *work;
    GF_OVERLAY_Load((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 111, 0x100000);
    work = PROCSYS_AllocProcWork(owner, 0x24, 111);
    MI_CpuFill8(work, 0, 0x24);
    work->heapId = 111;
    work->args = args;
    work->display = INTRO_GRAPHIC_CreateDisplay(1, ((IntroArgs *)args)->mode, work->heapId);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heapId);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 65, work->heapId);
    work->mcss = INTRO_MCSS_Create(work->heapId, ((IntroArgs *)work->args)->mode);
    work->g3d = INTRO_G3D_Create(work->display, ((IntroArgs *)work->args)->mode, work->heapId);
    work->particle = INTRO_PARTICLE_Create(work->display, work->heapId);
    work->cmdWork = INTRO_CMD_Create(work->g3d, (unsigned)work->particle, (unsigned)work->mcss, work->args, (unsigned)work->display, work->heapId);
    return 1;
}



int INTRO_GRAPHIC_Delete(struct Proc *owner, int unused1, int unused2, char *p)
{
    IntroGraphicWork *work = (IntroGraphicWork *)p;
    unsigned short heap;
    INTRO_PARTICLE_Delete(work->particle);
    INTRO_MCSS_Delete(work->mcss);
    INTRO_G3D_Delete(work->g3d);
    MSGDATA_Delete(work->msgBank);
    GF_FONT_Delete(work->font);
    INTRO_CMD_Delete(work->cmdWork);
    INTRO_GRAPHIC_DeleteDisplay(work->display);
    heap = work->heapId;
    PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked((unsigned)heap);
    GF_OVERLAY_Unload((unsigned)ov067_id);
    return 1;
}




int INTRO_GRAPHIC_Main(int a, int b, int c, void *p)
{
    IntroGraphicWork *work = (IntroGraphicWork *)p;
    if (INTRO_CMD_Main(work->cmdWork) == 0) {
        return 1;
    }
    INTRO_GRAPHIC_UpdateDisplay(work->display);
    INTRO_GRAPHIC_Draw3d(work->display);
    INTRO_G3D_UpdateIdleAnim(work->mcss);
    INTRO_MCSS_Main(work->mcss);
    INTRO_PARTICLE_Main((int)work->particle);
    INTRO_G3D_Draw(work->g3d);
    INTRO_GRAPHIC_Draw3dEnd(work->display);
    return 0;
}



static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }



static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }



static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)0x04000340 = ref; } else REG3D &= (unsigned short)~0x3004; }



static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }



static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }



/*
 * volatile: 021BDB80 BG0CNT; 021BDB8E..021BDBC2 DISP3DCNT repeated hardware updates; 021BDBE0 viewport.
 */
void INTRO_GRAPHIC_Setup3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, d_021BFDAC[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}



void *INTRO_GRAPHIC_CreateDisplay(int swap, int mode, u16 heap)
{
    IntroDisplay *disp;
    disp=GFL_HEAP_Alloc(heap,20,0,gIntroGraphicSite,406);
    MI_CpuFill8(disp,0,20);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    if (mode==7) {
        BG_SYS_SetVramBanks(&d_021BFE4C);
        INTRO_GRAPHIC_InitBg7(disp,heap);
        INTRO_GRAPHIC_InitClact(&disp->clact,(u32)&d_021BFE1C,heap);
        INTRO_GRAPHIC_InitCamera7(&disp->camera,heap);
    } else {
        BG_SYS_SetVramBanks(&d_021BFE1C);
        INTRO_GRAPHIC_InitBg(disp,heap);
        INTRO_GRAPHIC_InitClact(&disp->clact,(u32)&d_021BFE1C,heap);
        INTRO_GRAPHIC_InitCamera(&disp->camera,heap);
    }
    GF_FONT_InitTextColor();
    disp->vblank=GFL_USE_AddMainTask((u32)INTRO_GRAPHIC_VBlank,(u32)disp,0);
    return disp;
}



/*
 * volatile: 021BDD1E and 021BDD28 read hardware DISPCNT for masked updates.
 */
void INTRO_GRAPHIC_DeleteDisplay(unsigned char *p)
{
    IntroDisplay *disp = (IntroDisplay *)p;
    TCB_DeleteTask(disp->vblank);
    INTRO_GRAPHIC_DeleteCamera(&disp->camera);
    INTRO_GRAPHIC_DeleteClact(&disp->clact);
    INTRO_GRAPHIC_ExitBg(disp);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(disp, 0, 0x14);
    GFL_HEAP_Free(disp);
}




/*
 * Addresses are Black-image addresses.
 */
void INTRO_GRAPHIC_UpdateDisplay(u8 *p)
{
    IntroDisplay *disp = (IntroDisplay *)p;
    INTRO_GRAPHIC_DrawClact(&disp->clact);
    INTRO_GRAPHIC_ResetBgSlot(disp);
}



void INTRO_GRAPHIC_Draw3d(char *p){INTRO_GRAPHIC_DrawCamera(&((IntroDisplay *)p)->camera);}



void INTRO_GRAPHIC_Draw3dEnd(char *p){INTRO_GRAPHIC_DrawEnd(&((IntroDisplay *)p)->camera);}



unsigned INTRO_GRAPHIC_GetClactOwner(char *p){return INTRO_GRAPHIC_GetClactBank(&((IntroDisplay *)p)->clact);}




void INTRO_GRAPHIC_VBlank(u32 a, u8 *b)
{
    IntroDisplay *disp = (IntroDisplay *)b;
    INTRO_GRAPHIC_UpdateBg(disp);
    INTRO_GRAPHIC_VBlankClact(&disp->clact);
}



void INTRO_GRAPHIC_InitBg(IntroDisplay *disp, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(disp, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode(&(*(struct DispConfig *)&d_021BFD80));
    for (i = 0; i < 4; i++) {
        row = d_021BFF1C[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer, row[10]);
    }
}




/*
 * Addresses are Black-image addresses.
 */
void INTRO_GRAPHIC_ExitBg(IntroDisplay *disp)
{
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(disp, 0, 4);
}




void INTRO_GRAPHIC_ResetBgSlot(IntroDisplay *disp)
{
    if (BMP_GetVisiblePlane() & 4) {
        BG_SYS_ResetSlot(2, 1, 1);
    }
}



void INTRO_GRAPHIC_UpdateBg(void *a0) { BG_SYS_Update(); }



void INTRO_GRAPHIC_InitBg7(IntroDisplay *disp,u16 heap)
{
    struct BgTemplate t1,t2,t3,t4,t5;
    MI_CpuFill8(disp,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode(&d_021BFD80);
    t1=d_021BFEFC;
    BG_SYS_InitBgLayer(1,&t1,0);
    t2=d_021BFEDC;
    BG_SYS_InitBgLayer(2,&t2,0);
    t3=d_021BFE7C;
    BG_SYS_InitBgLayer(3,&t3,0);
    t4=d_021BFE9C;
    BG_SYS_InitBgLayer(4,&t4,0);
    t5=d_021BFEBC;
    BG_SYS_InitBgLayer(6,&t5,0);
    BG_SYS_SetPlaneVisible(1,1);
    BG_SYS_SetPlaneVisible(3,1);
    BG_SYS_SetPlaneVisible(4,1);
    BG_SYS_SetPlaneVisible(6,1);
}




void INTRO_GRAPHIC_InitClact(IntroClact *clact, int a, int b)
{
    MI_CpuFill8(clact, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BFD90, a, b);
    clact->bank = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(clact->bank);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}




void INTRO_GRAPHIC_DeleteClact(IntroClact *clact)
{
    CLACT_DeleteUnit((struct Bank *)clact->bank);
    CLACT_ExitSystem();
    MI_CpuFill8(clact, 0, 4);
}



void INTRO_GRAPHIC_DrawClact(void *a0){CLACT_DrawSystem();}



void INTRO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}



unsigned INTRO_GRAPHIC_GetClactBank(IntroClact *clact){return (unsigned)clact->bank;}



/*
 * lever: the fourth 02048A24 argument is the pooled 0x1555 (earlier notes
 * decoded it as 0x155, which also moved the pool order). The heap parameter
 * is u8: with the callees' own prototypes (02046440 s16 heap, 02048A24 u16
 * heap, 02048BC4 u32 heap) a u8 converts to all three with no code, matching
 * the original's unnarrowed full-word stack stores; u16/s16/u32 each add a
 * lsls/asr|lsr pair (156-160 bytes). Twin: INTRO_GRAPHIC_InitCamera7.c.
 */
void INTRO_GRAPHIC_InitCamera(IntroCamera *cam, u16 heap)
{
    u32 far_clip, near_clip;
    G3D_SYSTEM_Init(0, 4, 0, 2, 0, heap, INTRO_GRAPHIC_Setup3d);
    cam->camera = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, &gIntroGraphicCameraPos, &gIntroGraphicCameraTarget, &gIntroGraphicCameraUp, heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    G3D_CAMERA_SetFar(cam->camera, &far_clip);
    G3D_CAMERA_SetNear(cam->camera, &near_clip);
    cam->lightSlot = G3D_LIGHT_CreateSlots(&d_021BFD4C, heap);
    G3D_LIGHT_ApplySlots(cam->lightSlot);
}



void INTRO_GRAPHIC_InitCamera7(IntroCamera *cam, u16 heap)
{
    u32 far_clip, near_clip;
    G3D_SYSTEM_Init(0, 2, 0, 2, 0, heap, INTRO_GRAPHIC_Setup3d);
    cam->camera = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, &gIntroGraphicCameraPos, &gIntroGraphicCameraTarget, &gIntroGraphicCameraUp, heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    G3D_CAMERA_SetFar(cam->camera, &far_clip);
    G3D_CAMERA_SetNear(cam->camera, &near_clip);
    cam->lightSlot = G3D_LIGHT_CreateSlots(&d_021BFD54, heap);
    G3D_LIGHT_ApplySlots(cam->lightSlot);
}




void INTRO_GRAPHIC_DeleteCamera(IntroCamera *cam)
{
    G3D_LIGHT_DeleteSlots((u32)cam->lightSlot);
    G3D_CAMERA_Delete(cam->camera);
    G3D_SYSTEM_Exit();
}



void INTRO_GRAPHIC_DrawCamera(IntroCamera *cam){G3D_CAMERA_Reset(cam->camera);G3D_SYSTEM_DrawStart();G3D_SYSTEM_ApplyLookAt();}



void INTRO_GRAPHIC_DrawEnd(IntroCamera *unused){G3D_SYSTEM_DrawEnd();}



int INTRO_GRAPHIC_NoOp(void){return 1;}




int INTRO_GRAPHIC_SetScenario(char *p, u32 b, int *c)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    work->scenarioId = *c;
    work->rowIndex = 0;
    return 1;
}




u32 INTRO_GRAPHIC_CmdSetScenario(u8 *p)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    u32 t = ((IntroArgs *)work->args)->mode;

    if (t == 0) {
        t = t + 1;
    }
    INTRO_GRAPHIC_SetScenario((char *)p, 0, (int *)(&t));
    return 1;
}



/*
 * extent: 021BE17A..021BE17C is two zero alignment bytes.
 */
void INTRO_GRAPHIC_DrawMenuEntry(char *p, int which)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    char *q = INTRO_CMD_GetScenarioRow(work->scenarioId) + 24 * work->rowIndex;
    INTRO_MSG_DrawMenuList(work->msg);
    if (which == 0) {
        if (q) INTRO_CMD_AddCommand(work, (IntroCommand *)q);
    } else {
        q += 24;
        if (q) INTRO_CMD_AddCommand(work, (IntroCommand *)q);
    }
    work->rowIndex += 2;
}



int INTRO_GRAPHIC_CmdMenu(char *p, int *state, int *values)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    Request request;
    int result, choice;
    switch (*state) {
    case 0:
        request.first.a = values[0];
        request.first.b = 0;
        request.second.a = values[1];
        request.second.b = 1;
        INTRO_MSG_CreateMenuList(work->msg, (u32 *)(&request), 2, values[2]);
        ++*state;
        break;
    case 1:
        INTRO_MSG_MainMenuList(work->msg);
        result = INTRO_MSG_GetMenuChoice(work->msg, &choice);
        if (result == 1) { INTRO_GRAPHIC_DrawMenuEntry(p, choice); return 1; }
        if (result == 2) { INTRO_GRAPHIC_DrawMenuEntry(p, 1); return 1; }
        break;
    }
    return 0;
}



extern int (*const gIntroGraphicHandlerTable[])(void *);



int INTRO_GRAPHIC_CmdRunHandler(char *p, int unused, unsigned *q)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    IntroCommand *row = (IntroCommand *)INTRO_CMD_GetScenarioRow(work->scenarioId) + work->rowIndex;
    if (!gIntroGraphicHandlerTable[*q](p)) row++;
    if (row) INTRO_CMD_AddCommand(work, row);
    work->rowIndex += 2;
    return 1;
}



/*
 * extent: lead and two store/return followers; function_starts 021BE308,021BE314.
 */
int INTRO_GRAPHIC_CmdLoadPalette(char *p,void *unused,int *state)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    u16 heap;
    void *arc,*out,*buf;
    heap=work->heapId;
    arc=ARC_TOOL_CreateHandle(0xAA,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,1,0,0,64,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,1,4,0,32,heap);
    ARC_UTIL_UploadBgCharFromHandle(arc,0,6,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,2,6,0,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(arc,0,3,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,3,3,0,0,0,heap);
    if (*state==1) {
        ARC_UTIL_UploadBgCharFromHandle(arc,12,2,0,0,0,heap);
        buf=ARC_UTIL_LoadPaletteDataFromHandle(arc,14,0,(void **)&out,heap);
        MIi_CpuCopy16((char *)out+12,work->data,4096);
        GFL_HEAP_Free(buf);
    }
    ARC_TOOL_DeleteHandle(arc);
    return 1;
}



int INTRO_GRAPHIC_CmdSetArg(char *p,void *unused,u32 *r)
{
    IntroCmdWork *work = (IntroCmdWork *)p;
    ((IntroArgs *)work->args)->value=*r;
    return 1;
}



int INTRO_GRAPHIC_CmdWaitFrame(void *unused,int *q,int *r)
{
    if (q[1]>*r) return 1;
    q[1]++;
    return 0;
}
