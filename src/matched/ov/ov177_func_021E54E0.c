/*
 * function: WIFIBATTLEMATCH_GRAPHIC_Delete
 * address: 0x021E54E0
 * packet: pkt_ov177_021E54E0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   WIFIBATTLEMATCH_GRAPHIC_DeleteClact 0x021E564C thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_DeleteBg 0x021E55C8 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24443.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void WIFIBATTLEMATCH_GRAPHIC_DeleteClact(int *);
extern void WIFIBATTLEMATCH_GRAPHIC_DeleteBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p)
{
    func_02030EAC(((struct Obj24443 *)p)->fC);
    WIFIBATTLEMATCH_GRAPHIC_DeleteClact((int *)(p + 4));
    WIFIBATTLEMATCH_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}
