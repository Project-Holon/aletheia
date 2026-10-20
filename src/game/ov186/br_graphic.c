/*
 * file:     br_graphic.c
 * unit:     yes
 * function: BR_GRAPHIC_Create, BR_GRAPHIC_Destroy, BR_GRAPHIC_Draw, BR_GRAPHIC_GetActorUnit, BR_GRAPHIC_VBlankTask, BR_GRAPHIC_InitBgWindows, BR_GRAPHIC_ExitBgWindows, BR_GRAPHIC_DrawBg, BR_GRAPHIC_VBlankBg, BR_GRAPHIC_InitActors, BR_GRAPHIC_ExitActors, BR_GRAPHIC_DrawActors, BR_GRAPHIC_VBlankActors, BR_GRAPHIC_GetUnitFromActorSys, BR_GRAPHIC_Begin3d, BR_GRAPHIC_End3d
 * address:  0x021FC3BC
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
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_GRAPHIC_Create 0x021FC3BC thumb ov186
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_GRAPHIC_Destroy 0x021FC474 thumb ov186
 *   BR_GRAPHIC_Draw 0x021FC4C8 thumb ov186
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_02200D4C 0x02200D4C data a1
 *   d_0220093C 0x0220093C data a4
 *   d_0220096C 0x0220096C data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_02200900 0x02200900 data a4
 *   d_0220099C 0x0220099C data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   d_02200920      0x02200920  data
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible   0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 */
#include "br_types.h"
#include "../arm9/bmp_win.h"

struct Cfg;
struct Node;

#include "../arm9/gfl_heap_wrap.h"

struct DispVram;

struct Unit;

#include "../arm9/bg_sys.h"

typedef struct BrBgLayerRow {unsigned id;struct BgTemplate template;unsigned type,enable;} BrBgLayerRow;



#include "../arm9/mi_memory.h"




extern void BG_SYS_ResetSubDisplay(void),BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void),GF_FONT_InitTextColor(void);

#include "../arm9/gfl_use.h"
struct TcbTask;

#include "../arm9/tcb_list.h"

#include "../arm9/gf_font.h"






struct DispVramCfg;
struct ClactSysInit;
struct ClactSysInit;

#include "../arm9/clact.h"










#include "../arm9/gx.h"

void *BR_GRAPHIC_Create(unsigned mode,int vramSetting,u16 heapId);

void BR_GRAPHIC_Destroy(struct BrGraphic *gfx);

void BR_GRAPHIC_Draw(struct BrGraphic *gfx);

u32 BR_GRAPHIC_GetActorUnit(struct BrGraphic *gfx);

void BR_GRAPHIC_VBlankTask(struct TcbTask *taskId, void *gfx);

void BR_GRAPHIC_InitBgWindows(void *bgState,u16 heapId);

void BR_GRAPHIC_ExitBgWindows(void *bgState);

void BR_GRAPHIC_DrawBg(void *bgState);

void BR_GRAPHIC_VBlankBg(void *bgState);

void BR_GRAPHIC_InitActors(int *p, int b, int c);

void BR_GRAPHIC_ExitActors(struct BrActorSys *actorSys);

void BR_GRAPHIC_DrawActors(void *actorSys);

void BR_GRAPHIC_VBlankActors(void *actorSys);

u32 BR_GRAPHIC_GetUnitFromActorSys(u32*p);

void BR_GRAPHIC_Begin3d(void *graphicHandle, u16 b);

void BR_GRAPHIC_End3d(void *graphicHandle, u16 heap);

extern const char d_02200D4C[];

extern const struct DispVram d_0220093C,d_0220096C;

extern const BrBgLayerRow d_0220099C[];

extern struct DispConfig d_02200900;

extern unsigned char d_02200920[];

/*
 * note: the mode switch has no default arm: the original 021FC3E8 branches
 *       to 021FC3F0 with r6 (config) never set for modes other than 0/1,
 *       which is what a default-less switch over an unset local compiles to
 *       (docs/idioms/switch-arms-tail-merge.md). A `default: config = 0`
 *       arm adds a `movs r4, #0` and shifts every register.
 * volatile: hardware DISPCNT read-modify-write at 021FC3FC..021FC40A; BLDCNT stores at 021FC3F4/021FC3FA.
 */
void *BR_GRAPHIC_Create(unsigned mode,int vramSetting,u16 heapId)
{
    const struct DispVram *config;
    struct BrGraphic *gfx;
    gfx=GFL_HEAP_Alloc(heapId,16,0,d_02200D4C,0x1d5);
    MI_CpuFill8(gfx,0,16);
    switch(mode){case 0:config=&d_0220093C;break;case 1:config=&d_0220096C;break;}
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    BG_SYS_ClearGraphicsMemory(0);BG_SYS_SetVramBanks(config);BG_SYS_SetLcdSwap(vramSetting);
    BG_SYS_ResetSubDisplay();BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();GF_FONT_InitTextColor();
    BR_GRAPHIC_InitBgWindows(&gfx->bgState,heapId);
    BR_GRAPHIC_InitActors((int *)&gfx->actors,(sptr)config,heapId);
    gfx->vblankTask=GFL_USE_AddMainTask(BR_GRAPHIC_VBlankTask, gfx,0);
    return gfx;
}

/*
 * volatile: hardware BLDCNT 04000050/04001050 and DISPCNT 04000000/04001000, read-modify-write at 021FC49A..021FC4A8.
 */
void BR_GRAPHIC_Destroy(struct BrGraphic *gfx)
{
    TCB_DeleteTask(gfx->vblankTask);
    BR_GRAPHIC_ExitActors(&gfx->actors);
    BR_GRAPHIC_ExitBgWindows(&gfx->bgState);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    MI_CpuFill8(gfx,0,16);
    GFL_HEAP_Free(gfx);
}

void BR_GRAPHIC_Draw(struct BrGraphic *gfx)
{
    BR_GRAPHIC_DrawActors(&gfx->actors);
    BR_GRAPHIC_DrawBg(&gfx->bgState);
}

u32 BR_GRAPHIC_GetActorUnit(struct BrGraphic *gfx){return BR_GRAPHIC_GetUnitFromActorSys((u32 *)&gfx->actors);}

void BR_GRAPHIC_VBlankTask(struct TcbTask *taskId, void *gfxArg)
{
    struct BrGraphic * gfx = gfxArg;
    BR_GRAPHIC_VBlankBg(&gfx->bgState);
    BR_GRAPHIC_VBlankActors(&gfx->actors);
}

void BR_GRAPHIC_InitBgWindows(void *bgState,u16 heapId)
{
    unsigned i;
    const BrBgLayerRow *r;
    unsigned id;
    MI_CpuFill8(bgState,0,4);
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(&d_02200900);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        BG_SYS_InitBgLayer((unsigned char)id,&r->template,(unsigned char)r->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,r->enable);
    }
}

void BR_GRAPHIC_ExitBgWindows(void *bgState){u32 i;for(i=0;i<7;i++)BG_SYS_FreeLayerBuf((u8)d_0220099C[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(bgState,0,4);}

void BR_GRAPHIC_DrawBg(void *bgState){}

void BR_GRAPHIC_VBlankBg(void *bgState){BG_SYS_Update();}

void BR_GRAPHIC_InitActors(int *actorSys, int vramConfig, int heapId)
{
    MI_CpuFill8((void *)((sptr)actorSys), 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)d_02200920, (struct DispVramCfg *)vramConfig, heapId);
    actorSys[0] = (sptr)CLACT_CreateUnit(0x80, 0, heapId);
    CLACT_SetUnitDefaultRenderer((void *)actorSys[0]);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void BR_GRAPHIC_ExitActors(struct BrActorSys *actorSys)
{
    CLACT_DeleteUnit(actorSys->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(actorSys, 0, 4);
}

void BR_GRAPHIC_DrawActors(void *actorSys){CLACT_DrawSystem();}

void BR_GRAPHIC_VBlankActors(void *actorSys){CLACT_VBlankSystem();}

u32 BR_GRAPHIC_GetUnitFromActorSys(u32 *actorSys){return *actorSys;}

void BR_GRAPHIC_Begin3d(void *graphicHandle, u16 unusedB){u32 i,id;for(i=0;i<7;i++){id=d_0220099C[i].id;if(id<4)BG_SYS_FreeLayerBuf((u8)id);}GX_SetGraphicsMode(1,0,1);}

/*
 * volatile: hardware BLDCNT 04000050 and DISPCNT 04000000, read-modify-write at 021FC64A..021FC650.
 */
void BR_GRAPHIC_End3d(void *graphicHandle, u16 heap)
{
    unsigned i,id;
    const BrBgLayerRow *r;
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    GX_SetGraphicsMode(1,0,0);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        if(id<4){BG_SYS_InitBgLayer((unsigned char)id,&r->template,(unsigned char)r->type);BG_SYS_FreeSlot(id);}
        BG_SYS_SetPlaneVisible((unsigned char)id,(unsigned char)r->enable);
    }
}
