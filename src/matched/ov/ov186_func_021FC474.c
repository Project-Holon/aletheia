/*
 * function: BR_GRAPHIC_Destroy
 * address: 0x021FC474
 * packet: pkt_ov186_021FC474
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDCNT 04000050/04001050 and DISPCNT 04000000/04001000, read-modify-write at 021FC49A..021FC4A8.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   BR_GRAPHIC_ExitActors 0x021FC5E0 thumb ov186
 *   BR_GRAPHIC_ExitBgWindows 0x021FC55C thumb ov186
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24835.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void BR_GRAPHIC_ExitActors(void *);
extern void BR_GRAPHIC_ExitBgWindows(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void BR_GRAPHIC_Destroy(char *p)
{
    func_02030EAC(((struct Obj24835 *)p)->fC);
    BR_GRAPHIC_ExitActors(p+4);
    BR_GRAPHIC_ExitBgWindows(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
