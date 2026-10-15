/*
 * function: ZUKAN_DETAIL_GRAPHIC_InitBgGraphics
 * address: 0x021BCE10
 * packet: pkt_ov208_021BCE10
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000050/04001050 writes at 021BCE36/021BCE3C and 04000000/04001000 read-write at 021BCE40-021BCE4E.
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
 *   ZUKAN_DETAIL_GRAPHIC_CreateWindows 0x021BCF98 thumb ov208
 *   ZUKAN_DETAIL_GRAPHIC_InitActorSystem 0x021BD03C thumb ov208
 *   ZUKAN_DETAIL_GRAPHIC_Init3dSystem 0x021BCF58 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_GRAPHIC_VBlankTransfer 0x021BCF84 thumb ov208
 *   d_021C8DC0 0x021C8DC0 data a1
 *   d_021C8184 0x021C8184 data a4
 */
#include "../include/Obj04613.h"
extern const char d_021C8DC0[];
extern const unsigned d_021C8184[];
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *,unsigned);
extern void ZUKAN_DETAIL_GRAPHIC_InitActorSystem(unsigned char *,int,int);
extern void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, int x);
extern void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(int unused, char *p);
extern void *func_020056A0(unsigned,unsigned,unsigned);
char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(unsigned display,unsigned heap,int threeD)
{
    char *p=func_02030734(heap,20,0,d_021C8DC0,0x1db);
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
    ((struct Obj04613 *)p)->f10=0;
    ZUKAN_DETAIL_GRAPHIC_CreateWindows(p,heap);
    ZUKAN_DETAIL_GRAPHIC_InitActorSystem((unsigned char *)p+4,(int)d_021C8184,heap);
    if(threeD)ZUKAN_DETAIL_GRAPHIC_Init3dSystem(p,heap);
    ((struct Obj04613 *)p)->fC=func_020056A0((unsigned)ZUKAN_DETAIL_GRAPHIC_VBlankTransfer,(unsigned)p,0);
    return p;
}
