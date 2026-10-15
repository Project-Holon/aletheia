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
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA428 0x021BA428 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   TH_AWARD_GRAPHIC_GetValue 0x021BA310 thumb ov220
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BA3FC 0x021BA3FC data a4
 *   d_021BA458 0x021BA458 data a4
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
 */
#include "../../matched/include/Obj26061.h"
#include "../../matched/include/Obj26062.h"
#include "../../matched/include/Obj14783.h"
#include "../../matched/include/Obj26063.h"

struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Bank;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void *,void *,int);
extern void func_02030EAC(struct Node *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern u32 TH_AWARD_GRAPHIC_GetValue(u32*);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
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
void *TH_AWARD_GRAPHIC_Create(unsigned mode,unsigned heap);
void TH_AWARD_GRAPHIC_Delete(unsigned char *p);
void TH_AWARD_GRAPHIC_Update(char *p);
u32 TH_AWARD_GRAPHIC_GetActor(u8*p);
void TH_AWARD_GRAPHIC_Task(void *unused, char *p);
void TH_AWARD_GRAPHIC_SetupBg(void *p, unsigned heap);
void TH_AWARD_GRAPHIC_CleanupBg(void*p);
void TH_AWARD_GRAPHIC_Noop(void *p);
void TH_AWARD_GRAPHIC_DrawObjects(void *p);
void TH_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b);
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
    p=func_02030734(heap,16,0,d_021BA4F8,0x1CA);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BA428);
    func_0204363C(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    TH_AWARD_GRAPHIC_SetupBg(p,heap);
    TH_AWARD_GRAPHIC_SetupClact(p+4,(int)&d_021BA428,heap);
    ((struct Obj26061 *)p)->fC=func_020056A0((void *)TH_AWARD_GRAPHIC_Task,p,0);
    return p;
}


void TH_AWARD_GRAPHIC_Delete(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj26062 *)p)->fC);
    TH_AWARD_GRAPHIC_DeleteClact((char *)p+4);
    TH_AWARD_GRAPHIC_CleanupBg(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}



void TH_AWARD_GRAPHIC_Update(char *p)
{
    TH_AWARD_GRAPHIC_Draw(p + 4);
    TH_AWARD_GRAPHIC_Noop(p);
}


u32 TH_AWARD_GRAPHIC_GetActor(u8*p){return TH_AWARD_GRAPHIC_GetValue((u32*)(p+4));}



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
    func_0203FC28(&d_021BA3FC);
    for (i = 0; i < 3; i++) {
        row = d_021BA458[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}


void TH_AWARD_GRAPHIC_CleanupBg(void*p){u32 i;for(i=0;i<3;i++)func_020403F4((u8)d_021BA458[i][0]);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}


void TH_AWARD_GRAPHIC_Noop(void *p){}


void TH_AWARD_GRAPHIC_DrawObjects(void *p){func_020419E4();}



void TH_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BA40C, a, b);
    ((struct Obj14783 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14783 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void TH_AWARD_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26063 *)p)->f0));
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

u32 TH_AWARD_GRAPHIC_GetValue(u32*p){return *p;}
