/*
 * function: MYSTERY_GRAPHIC_Delete
 * address: 0x021D96C4
 * packet: pkt_ov121_021D96C4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads at 021D96EA and 021D96F4
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_GRAPHIC_ExitClact 0x021D98C0 thumb ov121
 *   MYSTERY_GRAPHIC_ExitBg 0x021D9828 thumb ov121
 */
#include "../include/Obj22873.h"
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void MYSTERY_GRAPHIC_ExitClact(u8 *p);
extern void MYSTERY_GRAPHIC_ExitBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void MYSTERY_GRAPHIC_Delete(u8 *p)
{
    func_02030EAC(((struct Obj22873 *)p)->f14);
    MYSTERY_GRAPHIC_ExitClact(p+4);
    MYSTERY_GRAPHIC_ExitBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,28);
    func_020307B0(p);
}
