/*
 * file:     zukan_detail_graphic.c
 * unit:     yes
 * function: ZUKAN_DETAIL_GRAPHIC_Init3dSettings, ZUKAN_DETAIL_GRAPHIC_InitBgGraphics, ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics, ZUKAN_DETAIL_GRAPHIC_DrawFrame, ZUKAN_DETAIL_GRAPHIC_ApplyCamera, ZUKAN_DETAIL_GRAPHIC_EndDraw3d, ZUKAN_DETAIL_GRAPHIC_Reset3dState, ZUKAN_DETAIL_GRAPHIC_Init3dSystem, ZUKAN_DETAIL_GRAPHIC_Delete3dSystem, ZUKAN_DETAIL_GRAPHIC_VBlankTransfer, ZUKAN_DETAIL_GRAPHIC_CreateWindows, ZUKAN_DETAIL_GRAPHIC_DeleteWindows, ZUKAN_DETAIL_GRAPHIC_NoOp, ZUKAN_DETAIL_GRAPHIC_TransferOam, ZUKAN_DETAIL_GRAPHIC_InitActorSystem, ZUKAN_DETAIL_GRAPHIC_ExitActorSystem, ZUKAN_DETAIL_GRAPHIC_DrawActors, ZUKAN_DETAIL_GRAPHIC_VBlankActors, ZUKAN_DETAIL_GRAPHIC_ResetCameraState, ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera, ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem, ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt, ZUKAN_DETAIL_GRAPHIC_EndDraw
 * address:  0x021BCD68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_GRAPHIC_InitBgGraphics 0x021BCE10 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics 0x021BCEC0 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   ZUKAN_DETAIL_GRAPHIC_DrawFrame 0x021BCF18 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ApplyCamera 0x021BCF2C thumb
 *   ZUKAN_DETAIL_GRAPHIC_EndDraw3d 0x021BCF3C thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021C8164 0x021C8164 data a2
 *   ZUKAN_DETAIL_GRAPHIC_Init3dSettings 0x021BCD68 thumb ov208
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021C8DC0 0x021C8DC0 data a1
 *   d_021C8184 0x021C8184 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021C8138 0x021C8138 data a4
 *   d_021C81B4 0x021C81B4 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4  arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DrawSystem 0x0204A600  arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021C8114 0x021C8114 data a4
 *   g_020A1EB8 0x020A1EB8 data a4
 *   G3D_SYSTEM_DrawEnd 0x02047970  arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   G3D_SYSTEM_Exit  0x02046788  arm  arm9
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   G3D_CAMERA_Reset  0x02048AD0  arm  arm9
 */
#include "zukan_detail_shared_types.h"

#define REG60 (*(volatile u16 *)0x04000060)

typedef enum {ShadeToon=0,ShadeHighlight=1} GXShading;

extern u32 GFL_HEAP_Free(void *p);

extern void TCB_DeleteTask(struct Node *n);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void G3X_SetFog(int,int,int,int);

extern void G3X_SetClearColor(u16,int,int,int,int);

extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);

extern void ZUKAN_DETAIL_GRAPHIC_Init3dSettings(void);

extern const u16 d_021C8164[][4];

static inline void SetShading(GXShading shading) {REG60=(u16)((REG60 & ~0x3002)|(shading<<1));}

static inline void AntiAlias(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x10);else REG60&=(u16)~0x3010;}

static inline void AlphaTest(int enable,int ref) {if(enable){REG60=(u16)((REG60 & ~0x3000)|4);*(volatile u16 *)0x04000340=(u16)ref;}else REG60&=(u16)~0x3004;}

static inline void AlphaBlend(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|8);else REG60&=(u16)~0x3008;}

static inline void EdgeMarking(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x20);else REG60&=(u16)~0x3020;}

/*
 * lever: SDK g3x.h shading enum and boolean inline bodies preserve the hardware mask sequence; pool word at 021BCE04 is BFFF0000.
 * volatile: hardware 04000008 and 04000060 read/write at 021BCD78-021BCDBA; 04000580 write at 021BCDD8.
 */
void ZUKAN_DETAIL_GRAPHIC_Init3dSettings(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    *(volatile u16 *)0x04000008=(*(volatile u16 *)0x04000008 & ~3)|1;
    SetShading(ShadeHighlight);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580=0xbfff0000;
    for(i=0;i<4;i++)G3D_SYSTEM_SetLight((unsigned char)i,d_021C8164[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}

struct DispVram;

struct DispConfig;

struct Light;

extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,unsigned short);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void BG_SYS_ClearGraphicsMemory(unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BMP_SetDisplaySwap(unsigned);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_InitTextColor(void);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern void GF_FONT_SetDefaultTextColor(void);

extern void BG_SYS_Create(u32);

extern void BMP_WIN_Init(u32);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u8 bgId, const struct BgTemplate *tmpl, u8 type);

extern void BG_SYS_FreeSlot(u8);

extern void BG_SYS_SetPlaneVisible(u8,u8);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_DrawSystem(char *);

extern void CLACT_VBlankSystem(void);

extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));

extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,const struct Vec3 *,const struct Vec3 *,const struct Vec3 *,u16);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(void);

extern void func_02047964(void);

extern void G3D_CAMERA_Reset(struct Light *l);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void G3D_SYSTEM_DrawEnd(void);

char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(unsigned display,unsigned short heap,int threeD);

void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);

void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);

void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);

void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);

int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);

void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, unsigned short x);

void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p);

void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(int unused, char *p);

void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *p,u32 heap);

void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *p);

void ZUKAN_DETAIL_GRAPHIC_NoOp(char *a0);

void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *a0);

void ZUKAN_DETAIL_GRAPHIC_InitActorSystem(unsigned char *p, int a, int b);

void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p);

void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *p);

void ZUKAN_DETAIL_GRAPHIC_VBlankActors(char *a0);

int ZUKAN_DETAIL_GRAPHIC_ResetCameraState(int *p);

void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(u32 **p,u16 heap);

void ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem(int *p);

void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(int *p);

void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *p);

extern const char d_021C8DC0[];

extern const unsigned d_021C8184[];

extern const u32 d_021C8138[];

extern const struct BgEntry d_021C81B4[];

extern const struct Vec3 d_021C8114[];

extern const char g_020A1EB8[];

/*
 * volatile: hardware 04000050/04001050 writes at 021BCE36/021BCE3C and 04000000/04001000 read-write at 021BCE40-021BCE4E.
 */
char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(unsigned display,unsigned short heap,int threeD)
{
    char *p=GFL_HEAP_Alloc(heap,20,0,d_021C8DC0,0x1db);
    MI_CpuFill8(p,0,20);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C8184);
    BMP_SetDisplaySwap(display);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    ((struct Ov208BgGfx *)p)->has3d=0;
    ZUKAN_DETAIL_GRAPHIC_CreateWindows(p,heap);
    ZUKAN_DETAIL_GRAPHIC_InitActorSystem((unsigned char *)p+4,(int)d_021C8184,heap);
    if(threeD)ZUKAN_DETAIL_GRAPHIC_Init3dSystem(p,heap);
    ((struct Ov208BgGfx *)p)->task=GFL_USE_AddMainTask((unsigned)ZUKAN_DETAIL_GRAPHIC_VBlankTransfer,(unsigned)p,0);
    return p;
}

/*
 * volatile: hardware writes 021BCEE4/021BCEEA and read-modify-write 021BCEEC/021BCEF4, 021BCEF6/021BCEFA.
 */
void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p)
{
    TCB_DeleteTask(((struct Ov208BgGfx *)p)->task);
    ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(p);
    ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(p+4);
    ZUKAN_DETAIL_GRAPHIC_DeleteWindows(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,0x14);
    GFL_HEAP_Free((void *)((unsigned)p));
}

void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p)
{
    ZUKAN_DETAIL_GRAPHIC_DrawActors(p + 4);
    ZUKAN_DETAIL_GRAPHIC_NoOp(p);
}

/*
 * Calls ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt on +8 when the word at +0x10 is set.
 */
void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p)
{
    if (((struct Ov208BgGfx *)p)->has3d != 0)
        ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt((int *)(p + 8));
}

/*
 * Calls ZUKAN_DETAIL_GRAPHIC_EndDraw on +8 when the word at +0x10 is set.
 */
void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p)
{
    if (((struct Ov208BgGfx *)p)->has3d != 0)
        ZUKAN_DETAIL_GRAPHIC_EndDraw(p + 8);
}

int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p)
{
    return ZUKAN_DETAIL_GRAPHIC_ResetCameraState((int *)(p + 4));
}

/*
 * Lazy setup: sets the flag at +0x10 and initialises the sub-object at +8.
 * The second argument is only forwarded to ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera, which is why the
 * compiler parks the flag temp in r2 rather than r1.
 */
void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, unsigned short x)
{
    if (((struct Ov208BgGfx *)p)->has3d == 0) {
        ((struct Ov208BgGfx *)p)->has3d = 1;
        ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera((u32 **)(p + 8), x);
    }
}

void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p)
{
    if (((struct Ov208BgGfx *)p)->has3d != 0) {
        ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem((int *)(p + 8));
        ((struct Ov208BgGfx *)p)->has3d = 0;
    }
}

void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(int unused, char *p)
{
    ZUKAN_DETAIL_GRAPHIC_TransferOam(p);
    ZUKAN_DETAIL_GRAPHIC_VBlankActors(p + 4);
}

void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *p,u32 heap)
{
    u32 i=0;
    const struct BgEntry *row;
    u32 bg;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021C8138);
    for(;i<8;i++) {
        row=&d_021C81B4[i];
        bg=row->bg;
        BG_SYS_InitBgLayer((u8)bg,(const struct BgTemplate *)&row->tmpl,(u8)row->type);
        BG_SYS_FreeSlot(bg);
        BG_SYS_SetPlaneVisible(bg,row->on);
    }
}

void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        BG_SYS_FreeLayerBuf((u8)d_021C81B4[i].bg);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void ZUKAN_DETAIL_GRAPHIC_NoOp(char *a0)
{
}

/*
 * Tail call to the ARM9 function at 0x020419E4: loads the pointer from the pool and branches through it.
 */
void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *a0)
{
    BG_SYS_Update();
}

void ZUKAN_DETAIL_GRAPHIC_InitActorSystem(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021C8148, a, b);
    ((struct Ov208ActorSystem *)p)->unit = CLACT_CreateUnit(0x50, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Ov208ActorSystem *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Ov208ActorSystem *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *p)
{
    CLACT_DrawSystem(p);
}

void ZUKAN_DETAIL_GRAPHIC_VBlankActors(char *a0)
{
    CLACT_VBlankSystem();
}

int ZUKAN_DETAIL_GRAPHIC_ResetCameraState(int *p)
{
    return *p;
}

void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(u32 **p,u16 heap)
{
    G3D_SYSTEM_Init(0,1,0,2,0,heap,ZUKAN_DETAIL_GRAPHIC_Init3dSettings);
    *p=G3D_CAMERA_Create(0,*(const short *)(g_020A1EB8+12),*(const short *)(g_020A1EB8+14),0x1555,0,0x107c20,0x400000,0,&d_021C8114[1],&d_021C8114[0],&d_021C8114[2],heap);
}

/*
 * Loads the word at [p], then calls the ARM9 functions at 0x02048AC4 and 0x02046788.
 */
void ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem(int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}

/*
 * Calls 0x02047964 on p, then 0x02048AD0 on the word at [p], then 0x020479D8.
 */
void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(int *p)
{
    func_02047964();
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}

void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *p)
{
    G3D_SYSTEM_DrawEnd();
}
