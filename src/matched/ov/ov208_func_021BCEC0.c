/*
 * function: ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics
 * address: 0x021BCEC0
 * packet: pkt_ov208_021BCEC0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware writes 021BCEE4/021BCEEA and read-modify-write 021BCEEC/021BCEF4, 021BCEF6/021BCEFA.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_DETAIL_GRAPHIC_Delete3dSystem 0x021BCF6C thumb ov208
 *   ZUKAN_DETAIL_GRAPHIC_ExitActorSystem 0x021BD07C thumb ov208
 *   ZUKAN_DETAIL_GRAPHIC_DeleteWindows 0x021BCFF8 thumb ov208
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04613.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p);
extern void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p);
extern void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p)
{
    func_02030EAC(((struct Obj04613 *)p)->fC);
    ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(p);
    ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(p+4);
    ZUKAN_DETAIL_GRAPHIC_DeleteWindows(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,0x14);
    func_020307B0((void *)((unsigned)p));
}
