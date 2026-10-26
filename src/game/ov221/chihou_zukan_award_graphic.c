/*
 * file:     chihou_zukan_award_graphic.c
 * unit:     yes
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_Create, CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete, CHIHOU_ZUKAN_AWARD_GRAPHIC_Update, CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor, CHIHOU_ZUKAN_AWARD_GRAPHIC_Task, CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg, CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg, CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop, CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects, CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupClact, CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact, CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw, CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank, CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue, CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera, CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera
 * address:  0x021B9E78
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_021BA2F0 0x021BA2F0 data a1
 *   d_021BA220 0x021BA220 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera 0x021BA130 thumb ov221
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BA1D4 0x021BA1D4 data a4
 *   d_021BA250 0x021BA250 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   CHIHOU_ZUKAN_AWARD_Setup3d 0x021B9DD4 thumb ov221
 *   d_021BA1B0 0x021BA1B0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */
struct Node;
struct Bank;
struct Cfg;
#include "../types.h"

struct G3dCamera;
struct VecFx32;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

typedef struct {u32 layer; u8 cfg[32];u32 type,enable;} Row;

struct ClactCtx {
    struct Bank *unit;     /* +0x00 CLACT unit from CLACT_CreateUnit */
};

struct ChihouZukanAwardGraphic {
    u32 bgState;           /* +0x00 zeroed by SetupBg and CleanupBg, never read */
    struct ClactCtx clact; /* +0x04 CLACT context */
    struct G3dCamera *camera;           /* +0x08 G3D camera from SetupCamera */
    void *proc;            /* +0x0C task proc from GFL_USE_AddMainTask */
};

typedef struct {u32 x,y,z;} ChihouZukanAwardGraphicVec3;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
#include "../arm9/gf_font.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(struct G3dCamera **);
/* The DS code was built against other parameter widths for BG_SYS_Create, BG_SYS_FreeLayerBuf (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_Create(u32);
extern void BG_SYS_FreeLayerBuf(unsigned char);
#else
#include "../arm9/bg_sys.h"
#endif
#include "../arm9/bmp_win.h"
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BMP_WIN_Exit(void),BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
typedef int Bool;
#include "chihou_zukan_award.h"
/* The DS code was built against other parameter widths for G3D_SYSTEM_Init (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void(*)(void));
#else
#include "../arm9/g3d_system.h"
#endif
/* The DS code was built against other parameter widths for G3D_CAMERA_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern struct G3dCamera *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct VecFx32 *,struct VecFx32 *,struct VecFx32 *,u32);
#else
#include "../arm9/g3d_camera.h"
#endif
void* CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap);
/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */ void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char*p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
struct Unit *CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg(void*p,u32 heap);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw(void *work);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p);
struct Unit *CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue(struct Unit **p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera(struct G3dCamera **p,u32 heap);
extern char d_021BA2F0[];
extern u32 d_021BA220[];
extern const Row d_021BA250[];
extern u32 d_021BA1D4[];
extern ChihouZukanAwardGraphicVec3 d_021BA1B0[3];
extern const s16 d_020A1EB8[];

/*
 * volatile: 021B9EA0..021B9EB4 BLDCNT/DISPCNT stores and reads
 * prototype evidence: 434CC full 16B body and both 4349C/434B4 full bodies ignore all input; no caller setup.
 */
void* CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=GFL_HEAP_Alloc(heap,sizeof(struct ChihouZukanAwardGraphic),0,d_021BA2F0,0x1cc);
 MI_CpuFill8(p,0,sizeof(struct ChihouZukanAwardGraphic));
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA220;
 BG_SYS_SetVramBanks((const struct DispVram *)g);
 BG_SYS_SetLcdSwap(swap);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 GF_FONT_InitTextColor();
 CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg(p,heap);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupClact((unsigned char*)&((struct ChihouZukanAwardGraphic *)p)->clact,(struct DispVramCfg *)g,heap);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera((struct G3dCamera **)(&((struct ChihouZukanAwardGraphic *)p)->camera),heap);
 *(void* *)&((struct ChihouZukanAwardGraphic *)p)->proc=GFL_USE_AddMainTask(CHIHOU_ZUKAN_AWARD_GRAPHIC_Task, p,0);
 return p;
}

/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char*p)
{
 TCB_DeleteTask(*(void* *)&((struct ChihouZukanAwardGraphic *)p)->proc);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera((struct G3dCamera **)(&((struct ChihouZukanAwardGraphic *)p)->camera));
 CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact((void *)&((struct ChihouZukanAwardGraphic *)p)->clact);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(p);
 GF_FONT_SetDefaultTextColor();
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 MI_CpuFill8(p,0,sizeof(struct ChihouZukanAwardGraphic));
 GFL_HEAP_Free(p);
}

/*
 * Addresses are Black-image addresses.
 */
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p)
{
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw((void *)&((struct ChihouZukanAwardGraphic *)p)->clact);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(p);
}

struct Unit *CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p){return CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue((struct Unit **)(&((struct ChihouZukanAwardGraphic *)p)->clact));}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *work_)
{ char * p = work_;
    CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(p);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank((void *)&((struct ChihouZukanAwardGraphic *)p)->clact);
}

/*
 * lever: named row pointer fixes 8 register bytes; heap widened to preserve untruncated calls.
 */
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg(void*p,u32 heap)
{
 u32 i;
 MI_CpuFill8(p,0,4);
 BG_SYS_Create(heap);
 BMP_WIN_Init(heap);
 BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BA1D4);
 for(i=0;i<2;i++){
  const Row *row=&d_021BA250[i];
  u32 layer=row->layer;
  BG_SYS_InitBgLayer((u8)layer,(const struct BgTemplate *)row->cfg,(u8)row->type);
  BG_SYS_FreeSlot(layer);
  BG_SYS_SetPlaneVisible(layer,row->enable);
 }
}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p){unsigned i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf(d_021BA250[i].layer);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(void *p){}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p){BG_SYS_Update();}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, sizeof(struct ClactCtx));
    CLACT_InitSystem((struct ClactSysInit *)0x021BA1E4, (struct DispVramCfg *)a, b);
    ((struct ClactCtx *)p)->unit = (struct Bank *)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((struct Unit *)(((struct ClactCtx *)p)->unit));
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit((struct Unit *)(((struct ClactCtx *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, sizeof(struct ClactCtx));
}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw(void *work) { CLACT_DrawSystem(); }

void CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p){CLACT_VBlankSystem();}

struct Unit *CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue(struct Unit **p){return *p;}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera(struct G3dCamera **p,u32 heap)
{
 G3D_SYSTEM_Init(0,1,0,1,0,heap,CHIHOU_ZUKAN_AWARD_Setup3d);
 *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,(struct VecFx32 *)(&d_021BA1B0[1]),(struct VecFx32 *)(&d_021BA1B0[0]),(struct VecFx32 *)(&d_021BA1B0[2]),heap);
}

void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(struct G3dCamera **p)
{
    G3D_CAMERA_Delete(*p);
    G3D_SYSTEM_Exit();
}
