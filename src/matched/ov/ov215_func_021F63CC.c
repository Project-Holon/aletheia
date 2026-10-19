/*
 * function: EGG_DEMO_GRAPHIC_Create
 * address: 0x021F63CC
 * packet: pkt_ov215_021F63CC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 021F63F2,63F4,63F8,6400,6402,6406.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   EGG_DEMO_GRAPHIC_InitBg 0x021F651C thumb ov215
 *   EGG_DEMO_GRAPHIC_InitClact 0x021F65C0 thumb ov215
 *   EGG_DEMO_GRAPHIC_InitG3d 0x021F6630 thumb ov215
 *   func_020056A0 0x020056A0 thumb
 *   EGG_DEMO_GRAPHIC_VBlank 0x021F6508 thumb ov215
 *   d_021F73E0 0x021F73E0 data a4
 *   d_021F71C4 0x021F71C4 data a4
 */
#include "../include/Obj25749.h"
typedef unsigned short u16;
extern const char d_021F73E0[];
extern const unsigned d_021F71C4[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void EGG_DEMO_GRAPHIC_InitBg(void *,unsigned);
extern void EGG_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b);
extern void EGG_DEMO_GRAPHIC_InitG3d(void **out, u16 heap);
extern void EGG_DEMO_GRAPHIC_VBlank(int,char *);
extern void *func_020056A0(void (*)(int,char *),char *,unsigned);
char *EGG_DEMO_GRAPHIC_Create(unsigned mode,u16 heap)
{
    char *p;
    p=func_02030734(heap,16,0,d_021F73E0,466);
    MI_CpuFill8(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021F71C4);
    BG_SYS_SetLcdSwap(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    EGG_DEMO_GRAPHIC_InitBg(p,heap);
    EGG_DEMO_GRAPHIC_InitClact((unsigned char *)(p+4),(int)d_021F71C4,heap);
    EGG_DEMO_GRAPHIC_InitG3d((void **)(p+8),heap);
    ((struct Obj25749 *)p)->fC=func_020056A0(EGG_DEMO_GRAPHIC_VBlank,p,0);
    return p;
}
