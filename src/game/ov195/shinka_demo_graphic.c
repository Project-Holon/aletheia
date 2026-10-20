/*
 * file:     shinka_demo_graphic.c
 * unit:     yes
 * function: SHINKA_DEMO_GRAPHIC_Create, SHINKA_DEMO_GRAPHIC_Destroy, SHINKA_DEMO_GRAPHIC_Draw, SHINKA_DEMO_GRAPHIC_Update, SHINKA_DEMO_GRAPHIC_DrawEnd, SHINKA_DEMO_GRAPHIC_GetCamera, SHINKA_DEMO_GRAPHIC_SetupSubBg, SHINKA_DEMO_GRAPHIC_ReleaseSubBg, SHINKA_DEMO_GRAPHIC_VBlank, SHINKA_DEMO_GRAPHIC_SetupMainBg, SHINKA_DEMO_GRAPHIC_ReleaseMainBg, SHINKA_DEMO_GRAPHIC_Noop, SHINKA_DEMO_GRAPHIC_UpdateSubBg, SHINKA_DEMO_GRAPHIC_InitClact, SHINKA_DEMO_GRAPHIC_ExitClact, SHINKA_DEMO_GRAPHIC_DrawClact, SHINKA_DEMO_GRAPHIC_VBlankClact, SHINKA_DEMO_GRAPHIC_GetCameraId, SHINKA_DEMO_GRAPHIC_Init3d, SHINKA_DEMO_GRAPHIC_Exit3d, SHINKA_DEMO_GRAPHIC_Update3d, SHINKA_DEMO_GRAPHIC_Draw3dEnd
 * address:  0x022058F8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from shinka_demo_view.c by tools/splitfile.py.
 *
 * symbols:
 *   d_02208F50 0x02208F50 data a4
 *   d_02208CEC 0x02208CEC data a4
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
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
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
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_02208C88 0x02208C88 data a4
 *   d_02208C7C 0x02208C7C data a4
 *   d_02208C94 0x02208C94 data a4
 *   SHINKA_DEMO_Setup3d 0x02205854 thumb ov195
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "shinka_demo_graphic_shared_types.h"

struct DispVram;

struct BgTemplate;

struct DispConfig;

struct DispConfig;

struct Cfg;

struct Unit;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} ShinkaDemoGraphicEntry;

typedef struct ShinkaGraphic {
    u8 mainBg[4];
    u8 clact[4];
    u8 g3d[4];
    void *vblank;
} ShinkaGraphic;

typedef struct ShinkaClact {
    void *unit;
} ShinkaClact;

typedef struct ShinkaG3d {
    void *camera;
} ShinkaG3d;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"

#include "../arm9/bg_sys.h"






#include "../arm9/gf_font.h"

#include "../arm9/gfl_use.h"
struct TcbTask;

#include "../arm9/tcb_list.h"









#include "../arm9/bmp_win.h"




struct DispVramCfg;
struct ClactSysInit;

#include "../arm9/clact.h"









#include "shinka_demo.h"

/* The DS code was built against a prototype with a halfword heap id (the header has a signed halfword). The host build uses the header. */
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_header
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
extern void G3D_SYSTEM_Init(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize, u16 geBufSize, u16 heapId, void (*setUpFunc)(void));
#endif

#include "../arm9/g3d_camera.h"



struct G3dCamera;




char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u16 b);

void SHINKA_DEMO_GRAPHIC_Destroy(char *p);

void SHINKA_DEMO_GRAPHIC_Draw(char *a);

void SHINKA_DEMO_GRAPHIC_Update(char *a);

void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a);

int SHINKA_DEMO_GRAPHIC_GetCamera(char *a);

void SHINKA_DEMO_GRAPHIC_SetupSubBg(void);

void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(void *unused);

void SHINKA_DEMO_GRAPHIC_VBlank(struct TcbTask *a, void *b);

void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *a, u16 b);

void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *p);

void SHINKA_DEMO_GRAPHIC_Noop(void *unused);

void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *unused);

void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b);

void SHINKA_DEMO_GRAPHIC_ExitClact(char *a);

void SHINKA_DEMO_GRAPHIC_DrawClact(void *unused);

void SHINKA_DEMO_GRAPHIC_VBlankClact(void *unused);

int SHINKA_DEMO_GRAPHIC_GetCameraId(int *p);

void SHINKA_DEMO_GRAPHIC_Init3d(u32 *a, u16 b);

void SHINKA_DEMO_GRAPHIC_Exit3d(int *p);

void SHINKA_DEMO_GRAPHIC_Update3d(char *a);

void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *p);

extern u32 d_02208F50[];

extern u32 d_02208CEC[];

extern u8 d_02208CA0[];

extern ShinkaDemoGraphicEntry d_02208D1C[];

extern const s16 d_020A1EB8[];

extern u32 d_02208C88[];

extern u32 d_02208C7C[];

extern u32 d_02208C94[];

char *SHINKA_DEMO_GRAPHIC_Create(u32 lcdSwap, u16 heap)
{
    char *p = GFL_HEAP_Alloc(heap, 0x10, 0, (const char *)d_02208F50, 0x1df);

    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_02208CEC);
    BG_SYS_SetLcdSwap(lcdSwap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    SHINKA_DEMO_GRAPHIC_SetupMainBg(p, heap);
    SHINKA_DEMO_GRAPHIC_InitClact((unsigned char *)(p + 4), (int)d_02208CEC, heap);
    SHINKA_DEMO_GRAPHIC_Init3d((u32 *)(p + 8), heap);
    ((ShinkaGraphic *)p)->vblank = GFL_USE_AddMainTask(SHINKA_DEMO_GRAPHIC_VBlank, p, 0);
    return p;
}

/*
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 */
void SHINKA_DEMO_GRAPHIC_Destroy(char *graphic)
{
    TCB_DeleteTask(((ShinkaGraphic *)graphic)->vblank);
    SHINKA_DEMO_GRAPHIC_Exit3d((int *)(graphic + 8));
    SHINKA_DEMO_GRAPHIC_ExitClact(graphic + 4);
    SHINKA_DEMO_GRAPHIC_ReleaseMainBg(graphic);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(graphic, 0, 0x10);
    GFL_HEAP_Free(graphic);
}

void SHINKA_DEMO_GRAPHIC_Draw(char *graphic)
{
    SHINKA_DEMO_GRAPHIC_DrawClact(graphic + 4);
    SHINKA_DEMO_GRAPHIC_Noop(graphic);
}

void SHINKA_DEMO_GRAPHIC_Update(char *graphic)
{
    SHINKA_DEMO_GRAPHIC_Update3d(graphic + 8);
}

void SHINKA_DEMO_GRAPHIC_DrawEnd(char *graphic)
{
    SHINKA_DEMO_GRAPHIC_Draw3dEnd(graphic + 8);
}

int SHINKA_DEMO_GRAPHIC_GetCamera(char *graphic)
{
    return SHINKA_DEMO_GRAPHIC_GetCameraId((int *)(graphic + 4));
}

/*
 * The `(int)i` cast on the id read (permuter, seed 6401) keeps the id load
 * and the element address separate values, so `adds r6, r7, r0` is emitted
 * inside the guarded block instead of hoisted above the `cmp`.
 */
void SHINKA_DEMO_GRAPHIC_SetupSubBg(void)
{
    u32 i;

    BG_SYS_ApplyGraphicsMode((const struct DispConfig *)d_02208CA0, (int)1);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v >= 4) {
            ShinkaDemoGraphicEntry *e = &d_02208D1C[i];
            BG_SYS_InitBgLayer((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            BG_SYS_FreeSlot(v);
            BG_SYS_SetPlaneVisible(v, e->mode);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(void *unused)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        unsigned int v = d_02208D1C[i].id;
        if (v >= 4)
        {
            BG_SYS_FreeLayerBuf(v & 0xff);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_VBlank(struct TcbTask *unused, void *graphicArg)
{
    char * graphic = graphicArg;
    SHINKA_DEMO_GRAPHIC_UpdateSubBg(graphic);
    SHINKA_DEMO_GRAPHIC_VBlankClact(graphic + 4);
}

/*
 * Twin of SHINKA_DEMO_GRAPHIC_SetupSubBg: the `(int)i` cast on the id read keeps the element
 * address from being hoisted above the guard.
 */
void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *mainBg, u16 heap)
{
    u32 i;

    MI_CpuFill8(mainBg, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_02208CA0);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v <= 3) {
            ShinkaDemoGraphicEntry *e = &d_02208D1C[i];
            BG_SYS_InitBgLayer((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            BG_SYS_FreeSlot(v);
            BG_SYS_SetPlaneVisible(v, e->mode);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *mainBg) {u32 i;for(i=0;i<6;i++){u32 id=d_02208D1C[i].id;if(id<=3)BG_SYS_FreeLayerBuf((u8)id);}BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(mainBg,0,4);}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
void SHINKA_DEMO_GRAPHIC_Noop(void *unused) {}

void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *unused){BG_SYS_Update();}

void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *clact, int vramBanks, u32 heap)
{
    MI_CpuFill8(clact, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x02208CB0, (struct DispVramCfg *)vramBanks, heap);
    ((ShinkaClact *)clact)->unit = CLACT_CreateUnit(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer(((ShinkaClact *)clact)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void SHINKA_DEMO_GRAPHIC_ExitClact(char *clact)
{
    CLACT_DeleteUnit((struct Unit *)(((ShinkaClact *)clact)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(clact, 0, 4);
}

void SHINKA_DEMO_GRAPHIC_DrawClact(void *unused){CLACT_DrawSystem();}

void SHINKA_DEMO_GRAPHIC_VBlankClact(void *unused){CLACT_VBlankSystem();}

int SHINKA_DEMO_GRAPHIC_GetCameraId(int *camera)
{
    return *camera;
}

void SHINKA_DEMO_GRAPHIC_Init3d(u32 *cameraOut, u16 heap)
{
    G3D_SYSTEM_Init(0, 2, 0, 1, 0, heap, (void (*)(void))SHINKA_DEMO_Setup3d);
    *cameraOut = (u32)G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                       (VecFx32 *)d_02208C88, (VecFx32 *)d_02208C7C, (VecFx32 *)d_02208C94, heap);
}

void SHINKA_DEMO_GRAPHIC_Exit3d(int *camera)
{
    G3D_CAMERA_Delete((void *)(*camera));
    G3D_SYSTEM_Exit();
}

void SHINKA_DEMO_GRAPHIC_Update3d(char *g3d)
{
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset((struct G3dCamera *)((ShinkaG3d *)g3d)->camera);
    G3D_SYSTEM_ApplyLookAt();
}

void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *unused)
{
    G3D_SYSTEM_DrawEnd();
}
