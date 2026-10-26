/*
 * file:     demo3d_graphic.c
 * unit:     yes
 * function: DEMO3D_GRAPHIC_Create, DEMO3D_GRAPHIC_Delete, DEMO3D_GRAPHIC_Draw, DEMO3D_GRAPHIC_UpdateLookAt, DEMO3D_GRAPHIC_EndDraw, DEMO3D_GRAPHIC_GetUnit, DEMO3D_GRAPHIC_SetupLightBlock, DEMO3D_GRAPHIC_SetLightSlot, DEMO3D_GRAPHIC_SetLightVector, DEMO3D_GRAPHIC_VBlank, DEMO3D_GRAPHIC_InitBg, DEMO3D_GRAPHIC_DeleteBg, DEMO3D_GRAPHIC_Noop, DEMO3D_GRAPHIC_UpdateBg, DEMO3D_GRAPHIC_InitClact, DEMO3D_GRAPHIC_DeleteClact, DEMO3D_GRAPHIC_DrawClact, DEMO3D_GRAPHIC_VBlankClact, DEMO3D_GRAPHIC_GetClactUnit, DEMO3D_GRAPHIC_InitG3d, DEMO3D_GRAPHIC_DeleteG3d, DEMO3D_GRAPHIC_ApplyLookAt, DEMO3D_GRAPHIC_DrawEnd, DEMO3D_GRAPHIC_DeleteDouble3d, DEMO3D_GRAPHIC_DeleteCamera
 * address:  0x021BDDD8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from demo3d_graphic.c, demo3d_data.c, demo3d_cmdsys.c by tools/splitfile.py.
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
 *   d_021C3CCC 0x021C3CCC data a1
 *   d_021BFBC4 0x021BFBC4 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   G3D_LIGHT_SetColor 0x02048CDC arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   VEC_Fx16Normalize 0x0207CDB8 arm
 *   G3D_LIGHT_SetDirection 0x02048CA4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   d_021BFB50 0x021BFB50 data a4
 *   d_021BFC24 0x021BFC24 data a4
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   DEMO3D_SetupGx 0x021BDD40 thumb ov203
 *   d_021BFB48 0x021BFB48 data a4
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   DOUBLE3DDISP_Delete 0x0204EA64 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   DEMO3D_GRAPHIC_SetLightSlot 0x021BDF74 thumb ov203
 *   DEMO3D_GRAPHIC_SetLightVector 0x021BDF88 thumb ov203
 *   DEMO3D_DATA_IsDouble3dDisplay 0x021BE938 thumb ov203
 */
#include "demo3d_graphic_shared_types.h"

#include "../arm9/bg_sys.h"

struct Rgb555;

struct Bank;

struct LightSet;

/* One background layer template (0x28 bytes) in d_021BFC24. */
typedef struct Demo3dBgLayer { unsigned layer; unsigned config[8]; unsigned type, enable; } Demo3dBgLayer;

/* The clact sub-section of Demo3dGraphic at 0x04. */
typedef struct Demo3dGraphicClact { struct Bank *unit; } Demo3dGraphicClact;

/* The g3d sub-section of Demo3dGraphic at 0x08. */
typedef struct Demo3dGraphicG3d { int tag; struct LightSlot *lightSlots; } Demo3dGraphicG3d;

#include "../types.h"

struct TcbTask;
struct LightSlot;
struct ClactSysInit;
struct DispVramCfg;
struct Unit;
struct LightSlotValue;
struct LightSetDesc;
#include "../arm9/tcb_list.h"
#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"







#include "../arm9/gf_font.h"

#include "../arm9/gfl_use.h"
struct TcbTask;






#include "../arm9/fx_vec.h"

/* The DS code was built against other parameter widths for G3D_LIGHT_SetDirection (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void G3D_LIGHT_SetDirection(struct LightSlot *slots, u32 i, struct Rgb555 *in);
#else
#include "../arm9/g3d_light.h"
#endif
#include "../arm9/g3d_system.h"


#include "../arm9/bmp_win.h"










struct DispVramCfg;
struct SysInit;

#include "../arm9/clact.h"









struct LightSetDesc;
struct LightSlotValue;


#include "demo3d.h"






#include "../arm9/double3Ddisp.h"

#include "../arm9/g3d_camera.h"

Demo3dGraphic *DEMO3D_GRAPHIC_Create(unsigned swap, u32 id, u8 heap);

void DEMO3D_GRAPHIC_Delete(Demo3dGraphic *ctx);

void DEMO3D_GRAPHIC_Draw(Demo3dGraphic *p);

void DEMO3D_GRAPHIC_UpdateLookAt(Demo3dGraphic *p);

void DEMO3D_GRAPHIC_EndDraw(Demo3dGraphic *p);

int DEMO3D_GRAPHIC_GetUnit(Demo3dGraphic *p);

void DEMO3D_GRAPHIC_SetupLightBlock(Demo3dGraphic *graphic, unsigned short *colors, int unused);

void DEMO3D_GRAPHIC_SetLightSlot(Demo3dGraphic *p, unsigned i, unsigned short val);

void DEMO3D_GRAPHIC_SetLightVector(Demo3dGraphic *p, int a, VecFx16 *b);

void DEMO3D_GRAPHIC_VBlank(struct TcbTask *unused, void *arg);

void DEMO3D_GRAPHIC_InitBg(Demo3dGraphic *ctx, u16 heap);

void DEMO3D_GRAPHIC_DeleteBg(Demo3dGraphic *ctx);

void DEMO3D_GRAPHIC_Noop(void *unused);

void DEMO3D_GRAPHIC_UpdateBg(void *unused);

void DEMO3D_GRAPHIC_InitClact(Demo3dGraphicClact *p, struct DispVramCfg *a, int b);

void DEMO3D_GRAPHIC_DeleteClact(Demo3dGraphicClact *p);

void DEMO3D_GRAPHIC_DrawClact(void *unused);

void DEMO3D_GRAPHIC_VBlankClact(u8 *unused);

int DEMO3D_GRAPHIC_GetClactUnit(Demo3dGraphicClact *p);

void DEMO3D_GRAPHIC_InitG3d(Demo3dGraphicG3d *p, u8 heap);

void DEMO3D_GRAPHIC_DeleteG3d(Demo3dGraphicG3d *p);

void DEMO3D_GRAPHIC_ApplyLookAt(void *a);

void DEMO3D_GRAPHIC_DrawEnd(void *p);

void DEMO3D_GRAPHIC_DeleteDouble3d(void *unused0);

void DEMO3D_GRAPHIC_DeleteCamera(void *p);

#include "demo3d_data.h"

extern const char d_021C3CCC[];

extern const unsigned char d_021BFBC4[][48];

extern const Demo3dBgLayer d_021BFC24[];

extern const unsigned d_021BFB50[];

extern const struct LightSet d_021BFB48;

/*
 * volatile: 04000050/04001050 hardware stores DE06/DE0C; 04000000/04001000 rereads DE10/DE1A.
 */
Demo3dGraphic *DEMO3D_GRAPHIC_Create(unsigned swap, u32 id, u8 heap)
{
    Demo3dGraphic *ctx = GFL_HEAP_Alloc(heap, sizeof(Demo3dGraphic), 0, d_021C3CCC, 0x15a);
    MI_CpuFill8(ctx, 0, sizeof(Demo3dGraphic));
    ctx->engineOn = DEMO3D_DATA_IsDouble3dDisplay(id);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BFBC4[ctx->engineOn]);
    BG_SYS_SetLcdSwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    if (ctx->engineOn == 0) {
        DEMO3D_GRAPHIC_InitBg(ctx, heap);
        DEMO3D_GRAPHIC_InitClact((Demo3dGraphicClact *)&ctx->clact, (struct DispVramCfg *)d_021BFBC4, heap);
        ctx->proc = GFL_USE_AddMainTask(DEMO3D_GRAPHIC_VBlank, (void *)((uptr)ctx), 0);
    }
    DEMO3D_GRAPHIC_InitG3d((Demo3dGraphicG3d *)&ctx->g3dTag, heap);
    return ctx;
}

void DEMO3D_GRAPHIC_Delete(Demo3dGraphic *ctx)
{
    if (ctx->engineOn == 0) TCB_DeleteTask(ctx->proc);
    DEMO3D_GRAPHIC_DeleteG3d((Demo3dGraphicG3d *)&ctx->g3dTag);
    if (ctx->engineOn == 0) {
        DEMO3D_GRAPHIC_DeleteClact((Demo3dGraphicClact *)&ctx->clact);
        DEMO3D_GRAPHIC_DeleteBg(ctx);
    }
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    MI_CpuFill8(ctx, 0, sizeof(Demo3dGraphic));
    GFL_HEAP_Free(ctx);
}

/*
 * Addresses are Black-image addresses.
 */
void DEMO3D_GRAPHIC_Draw(Demo3dGraphic *p)
{
    if (p->engineOn == 0) {
        DEMO3D_GRAPHIC_DrawClact((void *)&p->clact);
        DEMO3D_GRAPHIC_Noop(p);
    }
}

void DEMO3D_GRAPHIC_UpdateLookAt(Demo3dGraphic *p){DEMO3D_GRAPHIC_ApplyLookAt(&p->g3dTag);}

void DEMO3D_GRAPHIC_EndDraw(Demo3dGraphic *p){DEMO3D_GRAPHIC_DrawEnd(&p->g3dTag);}

int DEMO3D_GRAPHIC_GetUnit(Demo3dGraphic *p){return DEMO3D_GRAPHIC_GetClactUnit((Demo3dGraphicClact *)&p->clact);}

void DEMO3D_GRAPHIC_SetupLightBlock(Demo3dGraphic *graphic, unsigned short *colors, int unused)
{
    Demo3dGraphicG3d *p = (Demo3dGraphicG3d *)&graphic->g3dTag;
    G3D_LIGHT_SetColor(p->lightSlots,0,colors);
    G3D_LIGHT_SetColor(p->lightSlots,1,colors+1);
    G3D_LIGHT_SetColor(p->lightSlots,2,colors+2);
    G3D_LIGHT_SetColor(p->lightSlots,3,colors+3);
    G3D_LIGHT_ApplySlots(p->lightSlots);
}

void DEMO3D_GRAPHIC_SetLightSlot(Demo3dGraphic *p,unsigned i,unsigned short val){G3D_LIGHT_SetColor(p->lightSlots,i,&val);}

void DEMO3D_GRAPHIC_SetLightVector(Demo3dGraphic *p, int a, VecFx16 *b)
{
    int buf[2];
    VEC_Fx16Normalize((const VecFx16 *)b, (VecFx16 *)buf);
    G3D_LIGHT_SetDirection(p->lightSlots, a, (struct Rgb555 *)buf);
}

void DEMO3D_GRAPHIC_VBlank(struct TcbTask *unused, void *arg)
{
    Demo3dGraphic *p = arg;
    if (p->engineOn == 0) {
        DEMO3D_GRAPHIC_UpdateBg(p);
        DEMO3D_GRAPHIC_VBlankClact((u8 *)&p->clact);
    }
}

void DEMO3D_GRAPHIC_InitBg(Demo3dGraphic *ctx, u16 heap)
{
    unsigned i = 0;
    const Demo3dBgLayer *descriptor;
    unsigned layer;
    MI_CpuFill8(ctx, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BFB50);
    for (; i < 4; i++) {
        descriptor = &d_021BFC24[i];
        layer = descriptor->layer;
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)descriptor->config, (unsigned char)descriptor->type);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer, descriptor->enable);
    }
    BG_SYS_Init(1, 0, 1, 0);
}

void DEMO3D_GRAPHIC_DeleteBg(Demo3dGraphic *ctx)
{
    unsigned i = 0;
    unsigned layer;
    BG_SYS_FreeTiles(1, 1, 0);
    for (; i < 4; i++) {
        layer = d_021BFC24[i].layer;
        BG_SYS_SetPlaneVisible((unsigned char)layer, 0);
        BG_SYS_FreeLayerBuf((unsigned char)layer);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(ctx, 0, 4);
}

void DEMO3D_GRAPHIC_Noop(void *unused){}

void DEMO3D_GRAPHIC_UpdateBg(void *unused){BG_SYS_Update();}

void DEMO3D_GRAPHIC_InitClact(Demo3dGraphicClact *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, sizeof(Demo3dGraphicClact));
    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)0x021BFB60), (const struct DispVramCfg *)a, b);
    p->unit = (struct Bank *)CLACT_CreateUnit(0x20, 0, b);
    CLACT_SetUnitDefaultRenderer((struct Unit *)p->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void DEMO3D_GRAPHIC_DeleteClact(Demo3dGraphicClact *p)
{
    CLACT_DeleteUnit((struct Unit *)p->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, sizeof(Demo3dGraphicClact));
}

void DEMO3D_GRAPHIC_DrawClact(void *unused){CLACT_DrawSystem();}

void DEMO3D_GRAPHIC_VBlankClact(u8 *unused) { CLACT_VBlankSystem(); }

int DEMO3D_GRAPHIC_GetClactUnit(Demo3dGraphicClact *p){return (sptr)p->unit;}

/*
 * lever: twin of ov204_func_021BE03C.c (3D setup, texSize 2, plttSize 4,
 * light set 0x021BFB48); u8 heap parameter.
 */
void DEMO3D_GRAPHIC_InitG3d(Demo3dGraphicG3d *p, u8 heap)
{
    G3D_SYSTEM_Init(0, 2, 0, 4, 0, heap, DEMO3D_SetupGx);
    p->lightSlots = (struct LightSlot *)G3D_LIGHT_CreateSlots((struct LightSetDesc *)(&d_021BFB48), heap);
    G3D_LIGHT_ApplySlots(p->lightSlots);
}

void DEMO3D_GRAPHIC_DeleteG3d(Demo3dGraphicG3d *p)
{
    G3D_LIGHT_DeleteSlots((void *)(p->lightSlots));
    G3D_SYSTEM_Exit();
}

void DEMO3D_GRAPHIC_ApplyLookAt(void *a)
{
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
}

void DEMO3D_GRAPHIC_DrawEnd(void *p){G3D_SYSTEM_DrawEnd();}

/*
 * leaf: solely blocks assigned 021BDF24; parent cleared ownership.
 * extent: three 8-byte wrappers; ends at peer-owned 021BE160, which is excluded.
 */
void DEMO3D_GRAPHIC_DeleteDouble3d(void *unused0){DOUBLE3DDISP_Delete();}

void DEMO3D_GRAPHIC_DeleteCamera(void *p){G3D_CAMERA_Delete(p);}
