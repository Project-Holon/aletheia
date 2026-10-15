/*
 * function: SHINKA_DEMO_GRAPHIC_Destroy
 * address: 0x022059A0
 * packet: pkt_ov195_022059A0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   SHINKA_DEMO_GRAPHIC_Exit3d 0x02205C48 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_ExitClact 0x02205BAC thumb ov195
 *   SHINKA_DEMO_GRAPHIC_ReleaseMainBg 0x02205B24 thumb ov195
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24952.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void SHINKA_DEMO_GRAPHIC_Exit3d(int *);
extern void SHINKA_DEMO_GRAPHIC_ExitClact(char *);
extern void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void SHINKA_DEMO_GRAPHIC_Destroy(char *p)
{
    func_02030EAC(((struct Obj24952 *)p)->fC);
    SHINKA_DEMO_GRAPHIC_Exit3d((int *)(p + 8));
    SHINKA_DEMO_GRAPHIC_ExitClact(p + 4);
    SHINKA_DEMO_GRAPHIC_ReleaseMainBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}
