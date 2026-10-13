/*
 * file:     unit_021BC240.c
 * unit:     yes
 * function: func_021BC240, func_021BC270, func_021BC284, func_021BC294, func_021BC2AC, func_021BC2B8, func_021BC318, func_021BC330, func_021BC33C, func_021BC3D4, func_021BC3E8
 * address:  0x021BC240
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BCF50  0x021BCF50  thumb  ov210
 *   func_02030EAC  0x02030EAC  arm
 *   d_02FE0000 0x02FE0000 data a4
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C0754  0x021C0754  data  a4
 */
#include "../../matched/include/Obj25581.h"
#include "../../matched/include/Obj25582.h"
#include "../../matched/include/Obj06692.h"
#include "../../matched/include/Obj25583.h"
#include "../../matched/include/Obj25584.h"

struct Obj0203159C;
struct S020315D4;
struct S_02021D50;
struct S02021D50;
struct DispVram;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_021BCF50(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern u32 func_020056A0(void (*)(void), u8 *, u32);
extern u32 func_02030EAC(u32 a);
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_020434DC(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void BG_SYS_ClearGraphicsMemory(u32 a);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
u32 func_021BC240(void *man, u32 b, u32 arg);
u32 func_021BC270(u32 a, u32 b, u32 c, u32 d);
u32 func_021BC284(void *p);
void func_021BC294(u8 *p);
u32 func_021BC2AC(u8 *p);
void func_021BC2B8(void *unused,unsigned char *p);
void func_021BC318(u8 *p);
u32 func_021BC330(u8 *p);
void func_021BC33C(void *ctx, unsigned char *p);
void func_021BC3D4(void);
void *func_021BC3E8(void);
extern unsigned d_02FE0000[];
extern u8 d_021C0754[];


u32 func_021BC240(void *man, u32 b, u32 arg)
{
    u32 *p;
    GFL_HEAP_CreateChildHeap(1, 0x7b, 0x60000);
    p = PROCSYS_AllocProcWork(man, 0x2d4, 0x7b);
    func_02082BCC(p, 0, 0x2d4);
    *p = arg;
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021BC270(u32 a, u32 b, u32 c, u32 d)
{
    return func_021BCF50((u8 *)d) == 0;
}


u32 func_021BC284(void *p)
{
    func_020315D4(p);
    func_020306F0(0x7b);
    return 1;
}


void func_021BC294(u8 *p)
{
    ((struct Obj25581 *)p)->f4 = func_020056A0((void (*)(void))func_021BC2B8, p, 0);
}


u32 func_021BC2AC(u8 *p)
{
    return func_02030EAC(((struct Obj25582 *)p)->f4);
}

void func_021BC2B8(void *unused,unsigned char *p)
{
    func_020419E4();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(*(struct S_02021D50 * *)&((struct Obj06692 *)p)->fC));
    if (p[0x2b8]==1) {
        func_020434DC(10,1);
        BG_SYS_SetSubPlaneVisible(2,1);
        p[0x2b8]=0;
    } else if (p[0x2b8]==2) {
        func_020434DC(10,0);
        BG_SYS_SetSubPlaneVisible(2,0);
        p[0x2b8]=0;
    }
    *(volatile unsigned *)((unsigned)d_02FE0000+0x3ff8) |= 1;
}


void func_021BC318(u8 *p)
{
    ((struct Obj25583 *)p)->f8 = (u32)func_02005624((u32)func_021BC33C, (u32)p, 0);
}


u32 func_021BC330(u8 *p)
{
    return func_02030EAC(((struct Obj25584 *)p)->f8);
}

/*
 * Unlabelled leaf in ov210 directly after func_021BC318 (which ends at
 * 0x021BC328, pool at 0x021BC32C); it saves nothing, so disasm.py prints it
 * inside a .word run.  It is the function-pointer blocker target of
 * func_021BC318 (pkt_021BC318).  Reads a mode byte from [p+0x2b9] and a
 * halfword from the IO register at 0x04000006, then writes one of six packed
 * halfwords to the register at 0x04001052.
 */
void func_021BC33C(void *ctx, unsigned char *p)
{
    int v = *(volatile unsigned short *)0x04000006;
    int b = p[0x2b9];

    if (b == 4) {
        if (v >= 0x98)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x70)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x20)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else
            *(volatile unsigned short *)0x04001052 = 0x0A06;
    } else {
        if (v >= 0xa8)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x90)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x78)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x60)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0A06;
        else
            *(volatile unsigned short *)0x04001052 = 0x0C04;
    }
}


void func_021BC3D4(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C0754);
}


void *func_021BC3E8(void)
{
    return d_021C0754;
}
