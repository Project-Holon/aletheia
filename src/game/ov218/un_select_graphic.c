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
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021BB094 0x021BB094 data a1
 *   d_021BAEF8 0x021BAEF8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   UN_SELECT_GRAPHIC_DeleteCamera 0x021BAB00 thumb ov218
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BAEAC 0x021BAEAC data a4
 *   d_021BAF28 0x021BAF28 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
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
 *   func_021BA7A4 0x021BA7A4 thumb ov218
 *   d_021BAE94 0x021BAE94 data a4
 *   d_021BAE88 0x021BAE88 data a4
 *   d_021BAEA0 0x021BAEA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 */
#include "../../matched/include/Obj26049.h"
#include "../../matched/include/Obj26050.h"
#include "../../matched/include/Obj14774.h"
#include "../../matched/include/Obj26051.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct Record { unsigned bg; unsigned config[8]; unsigned type, enable; } Record;

typedef struct Vec3 { unsigned x, y, z; } Vec3;

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_02030EAC(struct Node *n);
extern void UN_SELECT_GRAPHIC_DeleteCamera(int *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u8);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_021BA7A4(void);
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
void UN_SELECT_GRAPHIC_Noop(void *a0);
void UN_SELECT_GRAPHIC_DrawObjects(void *a0);
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
    p = func_02030734(heap, 16, 0, d_021BB094, 436);
    MI_CpuFill8(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BAEF8);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    UN_SELECT_GRAPHIC_SetupBg(p, heap);
    UN_SELECT_GRAPHIC_SetupClact((unsigned char *)(p + 4), (int)&d_021BAEF8, heap);
    UN_SELECT_GRAPHIC_SetupCamera((unsigned **)(p + 8), heap);
    ((struct Obj26049 *)p)->fC = func_020056A0((unsigned)UN_SELECT_GRAPHIC_Task, (unsigned)p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 are cleared at A916/A91C; 04000000/04001000 read and masked at A91E-A92C.
 */
void UN_SELECT_GRAPHIC_Delete(char *ctx)
{
    func_02030EAC(((struct Obj26050 *)ctx)->fC);
    UN_SELECT_GRAPHIC_DeleteCamera((int *)(ctx + 8));
    UN_SELECT_GRAPHIC_DeleteClact(ctx + 4);
    UN_SELECT_GRAPHIC_CleanupBg(ctx);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    MI_CpuFill8(ctx, 0, 16);
    func_020307B0(ctx);
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
    func_0203FC28((struct DispConfig *)d_021BAEAC);
    for (i = 0; i < 7; i++) {
        record = &d_021BAF28[i];
        bg = record->bg;
        BG_SYS_InitBgLayer((unsigned char)bg, (const struct BgTemplate *)record->config, (unsigned char)record->type);
        func_020414AC(bg);
        func_02040588(bg, record->enable);
    }
}

void UN_SELECT_GRAPHIC_CleanupBg(void *p){u32 base=(u32)d_021BAF28;u32 i;for(i=0;i<7;i++)func_020403F4(*(const u32 *)(base+i*44));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

/*
 * extent: 2 zero alignment bytes at 021BAA1A.
 */
void UN_SELECT_GRAPHIC_Noop(void *a0) {}

void UN_SELECT_GRAPHIC_DrawObjects(void *a0) {func_020419E4();}


void UN_SELECT_GRAPHIC_SetupClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BAEBC, a, b);
    ((struct Obj14774 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14774 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void UN_SELECT_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26051 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void UN_SELECT_GRAPHIC_Draw(void *p){CLACT_DrawSystem();}

void UN_SELECT_GRAPHIC_VBlank(void *p){CLACT_VBlankSystem();}

u32 UN_SELECT_GRAPHIC_GetValue(u32 *p){return *p;}

void UN_SELECT_GRAPHIC_SetupCamera(unsigned **out, unsigned heap)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, func_021BA7A4);
    *out = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 5461, 0, 4096, 4194304, 0, &d_021BAE94, &d_021BAE88, &d_021BAEA0, heap);
}


void UN_SELECT_GRAPHIC_DeleteCamera(int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
