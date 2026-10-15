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
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
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
 *   func_02047964 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "shinka_demo_graphic_shared_types.h"

struct DispVram;

struct BgTemplate;

struct BgVramReq;

struct DispConfig;

struct Cfg;

struct Bank;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} Entry;

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

extern void *func_02030734(u32, u32, int, const char *, u16);

extern void MI_CpuFill8(void *, int, int);

extern void BG_SYS_ClearGraphicsMemory(u32 keep);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_SetLcdSwap(u32);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_ResetTextColor(void);

extern u32 func_020056A0(void *, void *, int);

extern void func_02030EAC(struct Node *n);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 func_020307B0(void *p);

extern void BG_SYS_ApplyGraphicsMode(const struct BgVramReq *req, u32 which);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_FreeSlot(u8);

extern void func_02040588(u8, u8);

extern void func_020403F4(u32 i);

extern void BG_SYS_Create(void *);

extern void BMP_WIN_Init(void *);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(int);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern void SHINKA_DEMO_Setup3d(void);

extern void G3D_SYSTEM_Init(int, int, int, int, int, void *, void *);

extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, void *);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(int);

extern void func_02047964(void);

extern void G3D_CAMERA_Reset(struct Light *l);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void G3D_SYSTEM_DrawEnd(void);

char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u32 b);

void SHINKA_DEMO_GRAPHIC_Destroy(char *p);

void SHINKA_DEMO_GRAPHIC_Draw(char *a);

void SHINKA_DEMO_GRAPHIC_Update(char *a);

void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a);

int SHINKA_DEMO_GRAPHIC_GetCamera(char *a);

void SHINKA_DEMO_GRAPHIC_SetupSubBg(void);

void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(int a0);

void SHINKA_DEMO_GRAPHIC_VBlank(int a, char *b);

void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *a, void *b);

void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *p);

void SHINKA_DEMO_GRAPHIC_Noop(void *a0);

void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *a0);

void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b);

void SHINKA_DEMO_GRAPHIC_ExitClact(char *a);

void SHINKA_DEMO_GRAPHIC_DrawClact(void *a0);

void SHINKA_DEMO_GRAPHIC_VBlankClact(void *a0);

int SHINKA_DEMO_GRAPHIC_GetCameraId(int *p);

void SHINKA_DEMO_GRAPHIC_Init3d(u32 *a, void *b);

void SHINKA_DEMO_GRAPHIC_Exit3d(int *p);

void SHINKA_DEMO_GRAPHIC_Update3d(char *a);

void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *p);

extern u32 d_02208F50[];

extern u32 d_02208CEC[];

extern u8 d_02208CA0[];

extern Entry d_02208D1C[];

extern const s16 d_020A1EB8[];

extern u32 d_02208C88[];

extern u32 d_02208C7C[];

extern u32 d_02208C94[];

char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u32 b)
{
    char *p = func_02030734(b, 0x10, 0, (const char *)d_02208F50, 0x1df);

    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_02208CEC);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_ResetTextColor();
    SHINKA_DEMO_GRAPHIC_SetupMainBg(p, (void *)b);
    SHINKA_DEMO_GRAPHIC_InitClact((unsigned char *)(p + 4), (int)d_02208CEC, b);
    SHINKA_DEMO_GRAPHIC_Init3d((u32 *)(p + 8), (void *)b);
    ((ShinkaGraphic *)p)->vblank = (void *)func_020056A0(SHINKA_DEMO_GRAPHIC_VBlank, p, 0);
    return p;
}

/*
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 */
void SHINKA_DEMO_GRAPHIC_Destroy(char *p)
{
    func_02030EAC(((ShinkaGraphic *)p)->vblank);
    SHINKA_DEMO_GRAPHIC_Exit3d((int *)(p + 8));
    SHINKA_DEMO_GRAPHIC_ExitClact(p + 4);
    SHINKA_DEMO_GRAPHIC_ReleaseMainBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}

void SHINKA_DEMO_GRAPHIC_Draw(char *a)
{
    SHINKA_DEMO_GRAPHIC_DrawClact(a + 4);
    SHINKA_DEMO_GRAPHIC_Noop(a);
}

void SHINKA_DEMO_GRAPHIC_Update(char *a)
{
    SHINKA_DEMO_GRAPHIC_Update3d(a + 8);
}

void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a)
{
    SHINKA_DEMO_GRAPHIC_Draw3dEnd(a + 8);
}

int SHINKA_DEMO_GRAPHIC_GetCamera(char *a)
{
    return SHINKA_DEMO_GRAPHIC_GetCameraId((int *)(a + 4));
}

/*
 * The `(int)i` cast on the id read (permuter, seed 6401) keeps the id load
 * and the element address separate values, so `adds r6, r7, r0` is emitted
 * inside the guarded block instead of hoisted above the `cmp`.
 */
void SHINKA_DEMO_GRAPHIC_SetupSubBg(void)
{
    u32 i;

    BG_SYS_ApplyGraphicsMode((const struct BgVramReq *)d_02208CA0, (int)1);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v >= 4) {
            Entry *e = &d_02208D1C[i];
            BG_SYS_InitBgLayer((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            BG_SYS_FreeSlot(v);
            func_02040588(v, e->mode);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(int a0)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        unsigned int v = d_02208D1C[i].id;
        if (v >= 4)
        {
            func_020403F4(v & 0xff);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_VBlank(int a, char *b)
{
    SHINKA_DEMO_GRAPHIC_UpdateSubBg(b);
    SHINKA_DEMO_GRAPHIC_VBlankClact(b + 4);
}

/*
 * Twin of SHINKA_DEMO_GRAPHIC_SetupSubBg: the `(int)i` cast on the id read keeps the element
 * address from being hoisted above the guard.
 */
void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *a, void *b)
{
    u32 i;

    MI_CpuFill8(a, 0, 4);
    BG_SYS_Create(b);
    BMP_WIN_Init(b);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_02208CA0);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v <= 3) {
            Entry *e = &d_02208D1C[i];
            BG_SYS_InitBgLayer((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            BG_SYS_FreeSlot(v);
            func_02040588(v, e->mode);
        }
    }
}

void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *p) {u32 i;for(i=0;i<6;i++){u32 id=d_02208D1C[i].id;if(id<=3)func_020403F4((u8)id);}BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
void SHINKA_DEMO_GRAPHIC_Noop(void *a0) {}

void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *a0){BG_SYS_Update();}

void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x02208CB0, a, b);
    ((ShinkaClact *)p)->unit = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((ShinkaClact *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void SHINKA_DEMO_GRAPHIC_ExitClact(char *a)
{
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((ShinkaClact *)a)->unit)));
    MI_CpuFill8(a, 0, 4);
}

void SHINKA_DEMO_GRAPHIC_DrawClact(void *a0){CLACT_DrawSystem();}

void SHINKA_DEMO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}

int SHINKA_DEMO_GRAPHIC_GetCameraId(int *p)
{
    return *p;
}

void SHINKA_DEMO_GRAPHIC_Init3d(u32 *a, void *b)
{
    G3D_SYSTEM_Init(0, 2, 0, 1, 0, b, SHINKA_DEMO_Setup3d);
    *a = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                       d_02208C88, d_02208C7C, d_02208C94, b);
}

void SHINKA_DEMO_GRAPHIC_Exit3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}

void SHINKA_DEMO_GRAPHIC_Update3d(char *a)
{
    func_02047964();
    G3D_CAMERA_Reset((struct Light *)((ShinkaG3d *)a)->camera);
    G3D_SYSTEM_ApplyLookAt();
}

void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *p)
{
    G3D_SYSTEM_DrawEnd();
}
