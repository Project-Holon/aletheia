/*
 * function: THE_END_GRAPHIC_Delete
 * address: 0x021B998C
 * packet: pkt_ov182_021B998C
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 read/write at 0x021B99B2..0x021B99C8.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   THE_END_GRAPHIC_DeleteCamera 0x021B9B8C thumb ov182
 *   THE_END_GRAPHIC_DeleteActors 0x021B9AF4 thumb ov182
 *   THE_END_GRAPHIC_ExitWindows 0x021B9A70 thumb ov182
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24515.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void THE_END_GRAPHIC_DeleteCamera(unsigned *);
extern void THE_END_GRAPHIC_DeleteActors(void *);
extern void THE_END_GRAPHIC_ExitWindows(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void THE_END_GRAPHIC_Delete(char *p)
{
    func_02030EAC(((struct Obj24515 *)p)->fC);
    THE_END_GRAPHIC_DeleteCamera((unsigned *)(p + 8));
    THE_END_GRAPHIC_DeleteActors(p + 4);
    THE_END_GRAPHIC_ExitWindows(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}
