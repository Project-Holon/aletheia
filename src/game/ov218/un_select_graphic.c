/*
 * file:     un_select_graphic.c
 * unit:     yes
 * function: UN_SELECT_GRAPHIC_Create, UN_SELECT_GRAPHIC_Delete, UN_SELECT_GRAPHIC_Update, UN_SELECT_GRAPHIC_GetActor, UN_SELECT_GRAPHIC_Task, UN_SELECT_GRAPHIC_SetupBg, UN_SELECT_GRAPHIC_CleanupBg, UN_SELECT_GRAPHIC_Noop, UN_SELECT_GRAPHIC_DrawObjects, UN_SELECT_GRAPHIC_SetupClact, UN_SELECT_GRAPHIC_DeleteClact, UN_SELECT_GRAPHIC_Draw, UN_SELECT_GRAPHIC_VBlank, UN_SELECT_GRAPHIC_SetupCamera, UN_SELECT_GRAPHIC_DeleteCamera
 * address:  0x021BA848
 * region:   ov218
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
 *   d_021BB094 0x021BB094 data a1
 *   d_021BAEF8 0x021BAEF8 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   UN_SELECT_GRAPHIC_DeleteCamera 0x021BAB00 thumb ov218
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BAEAC 0x021BAEAC data a4
 *   d_021BAF28 0x021BAF28 data a4
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
 *   UN_SELECT_SetupDisplay 0x021BA7A4 thumb ov218
 *   d_021BAE94 0x021BAE94 data a4
 *   d_021BAE88 0x021BAE88 data a4
 *   d_021BAEA0 0x021BAEA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 */
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
#include "../types.h"

struct ClactCtx {
    struct Bank *unit;     /* +0x00 CLACT unit from CLACT_CreateUnit */
};

struct UnSelectGraphic {
    u32 bgState;           /* +0x00 zeroed by SetupBg and CleanupBg, never read */
    struct ClactCtx clact; /* +0x04 CLACT context */
    unsigned *camera;      /* +0x08 G3D camera from SetupCamera */
    void *proc;            /* +0x0C task proc from GFL_USE_AddMainTask */
};

typedef struct Record { unsigned bg; unsigned config[8]; unsigned type, enable; } Record;

typedef struct Vec3 { unsigned x, y, z; } Vec3;

extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetLcdSwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void *GFL_USE_AddMainTask(unsigned, unsigned, unsigned);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void UN_SELECT_GRAPHIC_DeleteCamera(int *);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void BG_SYS_SetPlaneVisible(unsigned char, unsigned char);
extern void BG_SYS_FreeLayerBuf(u8);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void UN_SELECT_SetupDisplay(void);
extern void G3D_SYSTEM_Init(unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned, void (*)(void));
extern unsigned *G3D_CAMERA_Create(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const Vec3 *, const Vec3 *, const Vec3 *, unsigned);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
char *UN_SELECT_GRAPHIC_Create(unsigned swap, unsigned heap);
void UN_SELECT_GRAPHIC_Delete(char *ctx);
void UN_SELECT_GRAPHIC_Update(char *p);
u32 UN_SELECT_GRAPHIC_GetActor(char *p);
void UN_SELECT_GRAPHIC_Task(void *unused, char *p);
void UN_SELECT_GRAPHIC_SetupBg(char *ctx, unsigned heap);
void UN_SELECT_GRAPHIC_CleanupBg(void *p);
void UN_SELECT_GRAPHIC_Noop(void *work);
void UN_SELECT_GRAPHIC_DrawObjects(void *work);
void UN_SELECT_GRAPHIC_SetupClact(unsigned char *p, int a, int b);
void UN_SELECT_GRAPHIC_DeleteClact(char *p);
void UN_SELECT_GRAPHIC_Draw(void *p);
void UN_SELECT_GRAPHIC_VBlank(void *p);
u32 UN_SELECT_GRAPHIC_GetValue(u32 *p);
void UN_SELECT_GRAPHIC_SetupCamera(unsigned **out, unsigned heap);
extern const struct DispVram d_021BAEF8;
extern const char d_021BB094[];
extern const unsigned d_021BAEAC[];
extern const Record d_021BAF28[];
extern const Vec3 d_021BAE94, d_021BAE88, d_021BAEA0;
extern const short d_020A1EB8[];

char *UN_SELECT_GRAPHIC_Create(unsigned swap, unsigned heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 16, 0, d_021BB094, 436);
    MI_CpuFill8(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BAEF8);
    BG_SYS_SetLcdSwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    UN_SELECT_GRAPHIC_SetupBg(p, heap);
    UN_SELECT_GRAPHIC_SetupClact((unsigned char *)(p + 4), (int)&d_021BAEF8, heap);
    UN_SELECT_GRAPHIC_SetupCamera((unsigned **)(p + 8), heap);
    ((struct UnSelectGraphic *)p)->proc = GFL_USE_AddMainTask((unsigned)UN_SELECT_GRAPHIC_Task, (unsigned)p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 are cleared at A916/A91C; 04000000/04001000 read and masked at A91E-A92C.
 */
void UN_SELECT_GRAPHIC_Delete(char *ctx)
{
    TCB_DeleteTask(((struct UnSelectGraphic *)ctx)->proc);
    UN_SELECT_GRAPHIC_DeleteCamera((int *)(ctx + 8));
    UN_SELECT_GRAPHIC_DeleteClact(ctx + 4);
    UN_SELECT_GRAPHIC_CleanupBg(ctx);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    MI_CpuFill8(ctx, 0, 16);
    GFL_HEAP_Free(ctx);
}

/*
 * Destructor pair: tears down the tail field then the head.
 *
 * Addresses are Black-image addresses.
 */
void UN_SELECT_GRAPHIC_Update(char *p)
{
    UN_SELECT_GRAPHIC_Draw(p + 4);
    UN_SELECT_GRAPHIC_Noop(p);
}

u32 UN_SELECT_GRAPHIC_GetActor(char *p){return UN_SELECT_GRAPHIC_GetValue((u32 *)(p+4));}

void UN_SELECT_GRAPHIC_Task(void *unused, char *p)
{
    UN_SELECT_GRAPHIC_DrawObjects(p);
    UN_SELECT_GRAPHIC_VBlank(p + 4);
}

/*
 * prototype: heap extern parameters widened where original forwards r5 without truncation; BG and flag callee parameters narrowed to u8 where A9AC-A9CE shows explicit shifts. 414AC visibly receives BG input despite its legacy asm void prototype.
 */
void UN_SELECT_GRAPHIC_SetupBg(char *ctx, unsigned heap)
{
    unsigned i;
    const Record *record;
    unsigned bg;
    MI_CpuFill8(ctx, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BAEAC);
    for (i = 0; i < 7; i++) {
        record = &d_021BAF28[i];
        bg = record->bg;
        BG_SYS_InitBgLayer((unsigned char)bg, (const struct BgTemplate *)record->config, (unsigned char)record->type);
        BG_SYS_FreeSlot(bg);
        BG_SYS_SetPlaneVisible(bg, record->enable);
    }
}

void UN_SELECT_GRAPHIC_CleanupBg(void *p){u32 base=(u32)d_021BAF28;u32 i;for(i=0;i<7;i++)BG_SYS_FreeLayerBuf(*(const u32 *)(base+i*44));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

/*
 * extent: 2 zero alignment bytes at 021BAA1A.
 */
void UN_SELECT_GRAPHIC_Noop(void *work) {}

void UN_SELECT_GRAPHIC_DrawObjects(void *work) {BG_SYS_Update();}

void UN_SELECT_GRAPHIC_SetupClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct SysInit *)0x021BAEBC, (struct DispVramCfg *)a, b);
    ((struct ClactCtx *)p)->unit = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct ClactCtx *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * Addresses are Black-image addresses.
 */
void UN_SELECT_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit(((struct ClactCtx *)p)->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void UN_SELECT_GRAPHIC_Draw(void *p){CLACT_DrawSystem();}

void UN_SELECT_GRAPHIC_VBlank(void *p){CLACT_VBlankSystem();}

u32 UN_SELECT_GRAPHIC_GetValue(u32 *p){return *p;}

void UN_SELECT_GRAPHIC_SetupCamera(unsigned **out, unsigned heap)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, UN_SELECT_SetupDisplay);
    *out = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 5461, 0, 4096, 4194304, 0, &d_021BAE94, &d_021BAE88, &d_021BAEA0, heap);
}

void UN_SELECT_GRAPHIC_DeleteCamera(int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
