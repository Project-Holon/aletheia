/*
 * file:     th_award_graphic.c
 * unit:     yes
 * function: TH_AWARD_GRAPHIC_Create, TH_AWARD_GRAPHIC_Delete, TH_AWARD_GRAPHIC_Update, TH_AWARD_GRAPHIC_GetActor, TH_AWARD_GRAPHIC_Task, TH_AWARD_GRAPHIC_SetupBg, TH_AWARD_GRAPHIC_CleanupBg, TH_AWARD_GRAPHIC_Noop, TH_AWARD_GRAPHIC_DrawObjects, TH_AWARD_GRAPHIC_SetupClact, TH_AWARD_GRAPHIC_DeleteClact, TH_AWARD_GRAPHIC_Draw, TH_AWARD_GRAPHIC_VBlank, TH_AWARD_GRAPHIC_GetValue
 * address:  0x021BA0D8
 * region:   ov220
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
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA428 0x021BA428 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   TH_AWARD_GRAPHIC_GetValue 0x021BA310 thumb ov220
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BA3FC 0x021BA3FC data a4
 *   d_021BA458 0x021BA458 data a4
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
 */
struct Node;
struct Bank;
struct Cfg;
#include "../types.h"

#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

struct ClactCtx {
    struct Bank *unit;     /* +0x00 CLACT unit from CLACT_CreateUnit */
};

struct ThAwardGraphic {
    u32 bgState;           /* +0x00 zeroed by SetupBg and CleanupBg, never read */
    struct ClactCtx clact; /* +0x04 CLACT context */
    u32 pad8;              /* +0x08 never read; record is 16 bytes (Create alloc size) */
    struct Node *proc;     /* +0x0C task proc from GFL_USE_AddMainTask */
};

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetLcdSwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
#include "../arm9/gf_font.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
extern struct Unit *TH_AWARD_GRAPHIC_GetValue(u32*);
/* The DS code was built against other parameter widths for BG_SYS_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_Create(unsigned);
#else
#include "../arm9/bg_sys.h"
#endif
#include "../arm9/bmp_win.h"
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void BG_SYS_SetPlaneVisible(unsigned char, unsigned char);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void *TH_AWARD_GRAPHIC_Create(unsigned mode,unsigned heap);
void TH_AWARD_GRAPHIC_Delete(unsigned char *p);
void TH_AWARD_GRAPHIC_Update(char *p);
struct Unit *TH_AWARD_GRAPHIC_GetActor(u8*p);
void TH_AWARD_GRAPHIC_Task(void *unused, char *p);
void TH_AWARD_GRAPHIC_SetupBg(void *p, unsigned heap);
void TH_AWARD_GRAPHIC_CleanupBg(void*p);
void TH_AWARD_GRAPHIC_Noop(void *p);
void TH_AWARD_GRAPHIC_DrawObjects(void *p);
void TH_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b);
void TH_AWARD_GRAPHIC_DeleteClact(char *p);
void TH_AWARD_GRAPHIC_Draw(void *p);
void TH_AWARD_GRAPHIC_VBlank(void *p);
extern char d_021BA4F8[];
extern const struct DispVram d_021BA428;
extern const unsigned d_021BA458[][11];
extern struct DispConfig d_021BA3FC;

void *TH_AWARD_GRAPHIC_Create(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=GFL_HEAP_Alloc(heap,16,0,d_021BA4F8,0x1CA);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BA428);
    BG_SYS_SetLcdSwap(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    TH_AWARD_GRAPHIC_SetupBg(p,heap);
    TH_AWARD_GRAPHIC_SetupClact(p+4,(struct DispVramCfg *)&d_021BA428,heap);
    ((struct ThAwardGraphic *)p)->proc=(struct Node *)GFL_USE_AddMainTask((void *)TH_AWARD_GRAPHIC_Task,p,0);
    return p;
}

void TH_AWARD_GRAPHIC_Delete(unsigned char *p)
{
    TCB_DeleteTask((struct TcbTask *)(((struct ThAwardGraphic *)p)->proc));
    TH_AWARD_GRAPHIC_DeleteClact((char *)p+4);
    TH_AWARD_GRAPHIC_CleanupBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    GFL_HEAP_Free(p);
}

void TH_AWARD_GRAPHIC_Update(char *p)
{
    TH_AWARD_GRAPHIC_Draw(p + 4);
    TH_AWARD_GRAPHIC_Noop(p);
}

struct Unit *TH_AWARD_GRAPHIC_GetActor(u8*p){return TH_AWARD_GRAPHIC_GetValue((u32*)(p+4));}

void TH_AWARD_GRAPHIC_Task(void *unused, char *p)
{
    TH_AWARD_GRAPHIC_DrawObjects(p);
    TH_AWARD_GRAPHIC_VBlank(p + 4);
}

void TH_AWARD_GRAPHIC_SetupBg(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode(&d_021BA3FC);
    for (i = 0; i < 3; i++) {
        row = d_021BA458[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer, row[10]);
    }
}

void TH_AWARD_GRAPHIC_CleanupBg(void*p){u32 i;for(i=0;i<3;i++)BG_SYS_FreeLayerBuf((u8)d_021BA458[i][0]);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

void TH_AWARD_GRAPHIC_Noop(void *p){}

void TH_AWARD_GRAPHIC_DrawObjects(void *p){BG_SYS_Update();}

void TH_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x021BA40C, (struct DispVramCfg *)a, b);
    ((struct ClactCtx *)p)->unit = (struct Bank *)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((struct Unit *)(((struct ClactCtx *)p)->unit));
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void TH_AWARD_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit((struct Unit *)(((struct ClactCtx *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void TH_AWARD_GRAPHIC_Draw(void *p){CLACT_DrawSystem();}

/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
void TH_AWARD_GRAPHIC_VBlank(void *p)
{
    CLACT_VBlankSystem();
}

struct Unit *TH_AWARD_GRAPHIC_GetValue(u32*p){return *(struct Unit **)p;}
