/*
 * file:     zenkoku_zukan_award_graphic.c
 * unit:     yes
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update, ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg, ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw, ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank, ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera
 * address:  0x021B9F10
 * region:   ov222
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
 *   d_021BA390 0x021BA390 data a1
 *   d_021BA2CC 0x021BA2CC data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera 0x021BA1C8 thumb ov222
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   sZenkokuZukanAwardGraphicConfig 0x021BA280 data a4
 *   sZenkokuZukanAwardGraphicRecords 0x021BA2FC data a4
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
 *   ZENKOKU_ZUKAN_AWARD_Callback 0x021B9E6C thumb ov222
 *   gCameraParams 0x020A1EB8 data
 *   sZenkokuZukanAwardGraphicVec1 0x021BA268 data a4
 *   sZenkokuZukanAwardGraphicVec2 0x021BA25C data a4
 *   sZenkokuZukanAwardGraphicVec3 0x021BA274 data ov222
 */
struct Node;
struct Bank;
struct Cfg;
#include "../types.h"

struct G3dCamera;
struct VecFx32;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

struct ZenkokuZukanAwardGraphicBgRow { u32 id; u8 cfg[32]; u32 type; u32 enable; };

struct ClactCtx {
    struct Bank *unit;     /* +0x00 CLACT unit from CLACT_CreateUnit */
};

struct ZenkokuZukanAwardGraphic {
    u32 bgState;           /* +0x00 zeroed by SetupBg and CleanupBg, never read */
    struct ClactCtx clact; /* +0x04 CLACT context */
    u32 *camera;           /* +0x08 G3D camera from SetupCamera */
    void *proc;            /* +0x0C task proc from GFL_USE_AddMainTask */
};

struct ZenkokuZukanAwardGraphicVec3 { u32 x,y,z; };

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
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *);
/* The DS code was built against other parameter widths for BG_SYS_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_Create(u32);
#else
#include "../arm9/bg_sys.h"
#endif
extern void G3D_SYSTEM_Exit(void);
#include "../arm9/bmp_win.h"
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
#include "zenkoku_zukan_award.h"
/* The DS code was built against other parameter widths for G3D_SYSTEM_Init (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
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
void* ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32 **out,u32 heap);
extern char d_021BA390[];
extern u32 d_021BA2CC[];
extern u32 sZenkokuZukanAwardGraphicConfig[];
extern const struct ZenkokuZukanAwardGraphicBgRow sZenkokuZukanAwardGraphicRecords[];
extern const char gCameraParams[];
extern struct ZenkokuZukanAwardGraphicVec3 sZenkokuZukanAwardGraphicVec1,sZenkokuZukanAwardGraphicVec2,sZenkokuZukanAwardGraphicVec3;

void* ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=GFL_HEAP_Alloc(heap,16,0,d_021BA390,0x1cc);
 MI_CpuFill8(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA2CC;
 BG_SYS_SetVramBanks((const struct DispVram *)g);
 BG_SYS_SetLcdSwap(swap);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 GF_FONT_InitTextColor();
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(p,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact((unsigned char*)p+4,(struct DispVramCfg *)g,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera((u32**)(p+8),heap);
 *(void* *)&((struct ZenkokuZukanAwardGraphic *)p)->proc=GFL_USE_AddMainTask(ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task, p,0);
 return p;
}

/*
 * volatile: BLDCNT stores 021B9FDE/021B9FE4; DISPCNT accesses 021B9FE6..021B9FF4
 * 1DD68 ignores incoming arguments and tails with fixed 1,2,0.
 */
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p)
{
    TCB_DeleteTask(((struct ZenkokuZukanAwardGraphic *)p)->proc);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera((u32 *)(p+8));
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(p+4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    GFL_HEAP_Free(p);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p)
{
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(p + 4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(p);
}

u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p) { return ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue((const u32 *)(p+4)); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *work_)
{ char * p = work_;
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(p);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(p + 4);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap)
{
    u32 i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)sZenkokuZukanAwardGraphicConfig);
    for(i=0;i<2;i++) {
        const struct ZenkokuZukanAwardGraphicBgRow *r=&sZenkokuZukanAwardGraphicRecords[i];
        u32 id=r->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)r->cfg,(u8)r->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,r->enable);
    }
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p) { u32 i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf((u8)sZenkokuZukanAwardGraphicRecords[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *p) { }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p) { BG_SYS_Update(); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x021BA290, (struct DispVramCfg *)a, b);
    ((struct ClactCtx *)p)->unit = (struct Bank *)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((struct Unit *)(((struct ClactCtx *)p)->unit));
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * Addresses are Black-image addresses.
 */
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit((struct Unit *)(((struct ClactCtx *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *p) { CLACT_DrawSystem(); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p) { CLACT_VBlankSystem(); }

u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p) { return *p; }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,ZENKOKU_ZUKAN_AWARD_Callback);
    *out=(u32 *)G3D_CAMERA_Create(0,*(s16 *)(gCameraParams+12),*(s16 *)(gCameraParams+14),0x1555,0,4096,0x400000,0,(struct VecFx32 *)(&sZenkokuZukanAwardGraphicVec1),(struct VecFx32 *)(&sZenkokuZukanAwardGraphicVec2),(struct VecFx32 *)(&sZenkokuZukanAwardGraphicVec3),heap);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
