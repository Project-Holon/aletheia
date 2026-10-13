/*
 * file:     th_award_graphic.c
 * unit:     yes
 * function: func_021BA0D8, func_021BA178, func_021BA1CC, func_021BA1E0, func_021BA1EC, func_021BA200, func_021BA260, func_021BA298, func_021BA29C, func_021BA2A4, func_021BA2E4, func_021BA300, func_021BA308
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
 *   func_021BA310 0x021BA310 thumb ov220
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BA3FC 0x021BA3FC data a4
 *   d_021BA458 0x021BA458 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
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
extern u32 func_021BA310(u32*);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
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
void *func_021BA0D8(unsigned mode,unsigned heap);
void func_021BA178(unsigned char *p);
void func_021BA1CC(char *p);
u32 func_021BA1E0(u8*p);
void func_021BA1EC(void *unused, char *p);
void func_021BA200(void *p, unsigned heap);
void func_021BA260(void*p);
void func_021BA298(void *p);
void func_021BA29C(void *p);
void func_021BA2A4(unsigned char *p, int a, int b);
void func_021BA2E4(char *p);
void func_021BA300(void *p);
void func_021BA308(void *p);
extern char d_021BA4F8[];
extern const struct DispVram d_021BA428;
extern const unsigned d_021BA458[][11];
extern struct DispConfig d_021BA3FC;


void *func_021BA0D8(unsigned mode,unsigned heap)
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
    func_021BA200(p,heap);
    func_021BA2A4(p+4,(int)&d_021BA428,heap);
    ((struct Obj26061 *)p)->fC=func_020056A0((void *)func_021BA1EC,p,0);
    return p;
}


void func_021BA178(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj26062 *)p)->fC);
    func_021BA2E4((char *)p+4);
    func_021BA260(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}



void func_021BA1CC(char *p)
{
    func_021BA300(p + 4);
    func_021BA298(p);
}


u32 func_021BA1E0(u8*p){return func_021BA310((u32*)(p+4));}



void func_021BA1EC(void *unused, char *p)
{
    func_021BA29C(p);
    func_021BA308(p + 4);
}


void func_021BA200(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_021BA3FC);
    for (i = 0; i < 3; i++) {
        row = d_021BA458[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}


void func_021BA260(void*p){u32 i;for(i=0;i<3;i++)func_020403F4((u8)d_021BA458[i][0]);BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4);}


void func_021BA298(void *p){}


void func_021BA29C(void *p){func_020419E4();}



void func_021BA2A4(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BA40C, a, b);
    ((struct Obj14783 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14783 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void func_021BA2E4(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26063 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}


void func_021BA300(void *p){CLACT_DrawSystem();}



/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
void func_021BA308(void *p)
{
    CLACT_VBlankSystem();
}
