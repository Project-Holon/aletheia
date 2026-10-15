/*
 * file:     mystery_graphic.c
 * unit:     yes
 * function: MYSTERY_GRAPHIC_Create, MYSTERY_GRAPHIC_Delete, MYSTERY_GRAPHIC_Draw, MYSTERY_GRAPHIC_DrawScene, MYSTERY_GRAPHIC_DrawEnd, MYSTERY_GRAPHIC_GetClactUnit, MYSTERY_GRAPHIC_StartRender, MYSTERY_GRAPHIC_StopRender, MYSTERY_GRAPHIC_VBlank, MYSTERY_GRAPHIC_InitBg, MYSTERY_GRAPHIC_ExitBg, MYSTERY_GRAPHIC_Dummy, MYSTERY_GRAPHIC_UpdateBg, MYSTERY_GRAPHIC_InitClact, MYSTERY_GRAPHIC_ExitClact, MYSTERY_GRAPHIC_DrawClact, MYSTERY_GRAPHIC_VBlankClact, MYSTERY_GRAPHIC_GetFirstWord, MYSTERY_GRAPHIC_InitCamera, MYSTERY_GRAPHIC_ExitCamera, MYSTERY_GRAPHIC_RenderScene, MYSTERY_GRAPHIC_FinishScene
 * address:  0x021D9624
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_util.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021DFB8C 0x021DFB8C data a1
 *   d_021DF604 0x021DF604 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   d_021DF598 0x021DF598 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   d_021DF634 0x021DF634 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   MYSTERY_SetupDisplay3d 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 */
#include "mystery_net_types.h"

struct DispVram;

struct DispConfig;

struct BgTemplate;

struct Bank;

/* BG_SYS_SetGraphicsMode argument (four words, the last one toggled). */
typedef struct { int a,b,c,d; } BgSysGraphicsMode;

/* One BG_SYS_InitBgLayer descriptor in d_021DF634. */
typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } BgLayerEntry;

extern void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);

extern void MI_CpuFill8(void *, int, u32);

extern void BG_SYS_ClearGraphicsMemory(u32 keep);

extern void BG_SYS_SetVramBanks(const void *c);

extern void BMP_SetDisplaySwap(u32 swap);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_InitTextColor(void);

extern void *func_020056A0(void (*)(void *,u8 *),void *,int);

extern void func_02030EAC(void *n);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 func_020307B0(void *p);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BG_SYS_SetGraphicsMode(const void *cfg);

extern void PARTICLE_InitManager(u32 heap);

extern void PARTICLE_ExitManager(void);

extern void BG_SYS_Create(u32);

extern void BMP_WIN_Init(u32);

extern void BG_SYS_InitBgLayer(u32 bgId, const void *tmpl, u32 type);

extern void BG_SYS_FreeSlot(u8);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const void *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern struct Obj *CLACT_CreateRenderer(void *a0, u32 a1, u32 heap);

extern void CLACT_SetUnitRenderer(void *bank, void *p);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void CLACT_DeleteRenderer(void *);

extern u32 CLACT_DeleteUnit(void *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern void MYSTERY_SetupDisplay3d(void);

extern void G3D_SYSTEM_Init(int, int, int, int, int, u32, void (*)(void));

extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(void);

extern void func_02047964(void);

extern void func_02048AD0(void *l);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void PARTICLE_Main(void);

extern void G3D_SYSTEM_DrawEnd(void);

u8 *MYSTERY_GRAPHIC_Create(int arg,u16 heap);

void MYSTERY_GRAPHIC_Delete(u8 *p);

void MYSTERY_GRAPHIC_Draw(u8 *p);

void MYSTERY_GRAPHIC_DrawScene(char *p);

void MYSTERY_GRAPHIC_DrawEnd(char *p);

unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p);

void MYSTERY_GRAPHIC_StartRender(u8 *p);

void MYSTERY_GRAPHIC_StopRender(char *p);

void MYSTERY_GRAPHIC_VBlank(void *a, u8 *q);

void MYSTERY_GRAPHIC_InitBg(void *p, u32 a);

void MYSTERY_GRAPHIC_ExitBg(void *p);

void MYSTERY_GRAPHIC_Dummy(void *a0);

void MYSTERY_GRAPHIC_UpdateBg(void *a0);

void MYSTERY_GRAPHIC_InitClact(void **p, u32 a, u32 heap);

void MYSTERY_GRAPHIC_ExitClact(u8 *p);

void MYSTERY_GRAPHIC_DrawClact(void *a0);

void MYSTERY_GRAPHIC_VBlankClact(void *a0);

unsigned MYSTERY_GRAPHIC_GetFirstWord(unsigned *p);

void MYSTERY_GRAPHIC_InitCamera(u32 *p, u32 heap);

void MYSTERY_GRAPHIC_ExitCamera(char *p);

void MYSTERY_GRAPHIC_RenderScene(void **p);

void MYSTERY_GRAPHIC_FinishScene(void **p);

extern const char d_021DFB8C[];

extern const int d_021DF604[];

extern const BgSysGraphicsMode d_021DF598;

extern const BgLayerEntry d_021DF634[];

extern const u32 d_021DF5A8[];

extern const u32 d_021DF5C4[];

extern const u32 d_021DF574[];

extern const u32 d_021DF58C[];

extern const u32 d_021DF580[];

/*
 * volatile: hardware reads at 021D9654 and 021D965E
 */
u8 *MYSTERY_GRAPHIC_Create(int arg,u16 heap)
{
    u8 *p;
    p=func_02030734(heap,28,0,d_021DFB8C,448);
    MI_CpuFill8(p,0,28);
    ((MysteryGraphicWork *)p)->heapId=heap;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DF604);
    BMP_SetDisplaySwap(arg);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    MYSTERY_GRAPHIC_InitBg(p,heap);
    MYSTERY_GRAPHIC_InitClact((void **)(p+4),(u32)d_021DF604,heap);
    ((MysteryGraphicWork *)p)->updateTask=func_020056A0(MYSTERY_GRAPHIC_VBlank,p,0);
    return p;
}

/*
 * volatile: hardware reads at 021D96EA and 021D96F4
 */
void MYSTERY_GRAPHIC_Delete(u8 *p)
{
    func_02030EAC(((MysteryGraphicWork *)p)->updateTask);
    MYSTERY_GRAPHIC_ExitClact(p+4);
    MYSTERY_GRAPHIC_ExitBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,28);
    func_020307B0(p);
}

/*
 * Addresses are Black-image addresses.
 */
void MYSTERY_GRAPHIC_Draw(u8 *p)
{
    MYSTERY_GRAPHIC_DrawClact(p + 4);
    MYSTERY_GRAPHIC_Dummy(p);
}

void MYSTERY_GRAPHIC_DrawScene(char *p) { MYSTERY_GRAPHIC_RenderScene((void **)(p+12)); }

void MYSTERY_GRAPHIC_DrawEnd(char *p) { MYSTERY_GRAPHIC_FinishScene((void **)(p+12)); }

unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p) { return MYSTERY_GRAPHIC_GetFirstWord((unsigned *)(p+4)); }

void MYSTERY_GRAPHIC_StartRender(u8 *p)
{
    BgSysGraphicsMode c;
    func_02040588(0,0);
    c=d_021DF598;
    c.d=1;
    BG_SYS_SetGraphicsMode((const struct DispConfig *)(&c));
    MYSTERY_GRAPHIC_InitCamera((u32 *)(p+12),((MysteryGraphicWork *)p)->heapId);
    PARTICLE_InitManager(((MysteryGraphicWork *)p)->heapId);
}

void MYSTERY_GRAPHIC_StopRender(char *p) { func_02040588(0,0);PARTICLE_ExitManager();MYSTERY_GRAPHIC_ExitCamera(p+12);BG_SYS_SetGraphicsMode((const struct DispConfig *)&d_021DF598); }

void MYSTERY_GRAPHIC_VBlank(void *a, u8 *q)
{
    MYSTERY_GRAPHIC_UpdateBg(q);
    MYSTERY_GRAPHIC_VBlankClact(q + 4);
}

void MYSTERY_GRAPHIC_InitBg(void *p, u32 a)
{
    u32 i;
    const BgLayerEntry *e;
    u32 id;
    i = 0;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(a);
    BMP_WIN_Init(a);
    BG_SYS_SetGraphicsMode((const struct DispConfig *)&d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)e->config, (u8)e->a);
        BG_SYS_FreeSlot((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}

/*
 * note: u8 extern parameter reproduces original truncation before BLX.
 */
void MYSTERY_GRAPHIC_ExitBg(void *p) {
    u32 i=0;
    do { BG_SYS_FreeLayerBuf((u8)d_021DF634[i].id); ++i; } while(i<7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}

/*
 * note: two trailing zero alignment bytes.
 */
void MYSTERY_GRAPHIC_Dummy(void *a0) {}

void MYSTERY_GRAPHIC_UpdateBg(void *a0) { BG_SYS_Update(); }

void MYSTERY_GRAPHIC_InitClact(void **p, u32 a, u32 heap)
{
    void *q;
    MI_CpuFill8(p, 0, 8);
    CLACT_InitSystem((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = CLACT_CreateUnit(128, 0, heap);
    q = CLACT_CreateRenderer((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    CLACT_SetUnitRenderer(p[0], q);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

void MYSTERY_GRAPHIC_ExitClact(u8 *p) {
    CLACT_DeleteRenderer(((MysteryGraphicClact *)p)->renderer);
    CLACT_DeleteUnit(((MysteryGraphicClact *)p)->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(p,0,8);
}

void MYSTERY_GRAPHIC_DrawClact(void *a0) { CLACT_DrawSystem(); }

/*
 * note: tail wrapper plus unlabelled getter follower; seed 021D98F0.
 */
void MYSTERY_GRAPHIC_VBlankClact(void *a0) { CLACT_VBlankSystem(); }

unsigned MYSTERY_GRAPHIC_GetFirstWord(unsigned *p) { return *p; }

void MYSTERY_GRAPHIC_InitCamera(u32 *p, u32 heap)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, MYSTERY_SetupDisplay3d);
    p[0] = (u32)G3D_CAMERA_Create(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}

void MYSTERY_GRAPHIC_ExitCamera(char *p)
{
    ((MysteryGraphicCamera *)p)->enabled = 0;
    G3D_CAMERA_Delete(((MysteryGraphicCamera *)p)->handle);
    G3D_SYSTEM_Exit();
}

void MYSTERY_GRAPHIC_RenderScene(void **p) {
    if(((MysteryGraphicCamera *)p)->enabled) {
        func_02047964();
        func_02048AD0(((MysteryGraphicCamera *)p)->handle);
        G3D_SYSTEM_ApplyLookAt();
        PARTICLE_Main();
    }
}

void MYSTERY_GRAPHIC_FinishScene(void **p)
{
    if (p[1])
        G3D_SYSTEM_DrawEnd();
}
