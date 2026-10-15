/*
 * function: EGG_DEMO_GRAPHIC_Delete
 * address: 0x021F6474
 * packet: pkt_ov215_021F6474
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads/stores 021F649A,64A0,64A2,64AA,64AC,64B0.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   EGG_DEMO_GRAPHIC_DeleteG3d 0x021F669C thumb ov215
 *   EGG_DEMO_GRAPHIC_DeleteClact 0x021F6600 thumb ov215
 *   EGG_DEMO_GRAPHIC_DeleteBg 0x021F657C thumb ov215
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25750.h"
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void EGG_DEMO_GRAPHIC_DeleteG3d(int *p);
extern void EGG_DEMO_GRAPHIC_DeleteClact(char *p);
extern void EGG_DEMO_GRAPHIC_DeleteBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void EGG_DEMO_GRAPHIC_Delete(char *p)
{
    func_02030EAC(((struct Obj25750 *)p)->fC);
    EGG_DEMO_GRAPHIC_DeleteG3d((int *)(p+8));
    EGG_DEMO_GRAPHIC_DeleteClact(p+4);
    EGG_DEMO_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
