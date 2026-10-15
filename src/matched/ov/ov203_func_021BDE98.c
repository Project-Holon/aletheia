/*
 * function: DEMO3D_GRAPHIC_Delete
 * address: 0x021BDE98
 * packet: pkt_ov203_021BDE98
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 04000050/04001050 stores DECA/DED0; 04000000/04001000 rereads DED2/DEDC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   DEMO3D_GRAPHIC_DeleteG3d 0x021BE12C thumb ov203
 *   DEMO3D_GRAPHIC_DeleteClact 0x021BE0C4 thumb ov203
 *   DEMO3D_GRAPHIC_DeleteBg 0x021BE02C thumb ov203
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10861.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void DEMO3D_GRAPHIC_DeleteG3d(int *);
extern void DEMO3D_GRAPHIC_DeleteClact(char *);
extern void DEMO3D_GRAPHIC_DeleteBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void DEMO3D_GRAPHIC_Delete(char *ctx)
{
    if (((struct Obj10861 *)ctx)->f14 == 0) func_02030EAC(((struct Obj10861 *)ctx)->f10);
    DEMO3D_GRAPHIC_DeleteG3d((int *)(ctx + 8));
    if (((struct Obj10861 *)ctx)->f14 == 0) {
        DEMO3D_GRAPHIC_DeleteClact(ctx + 4);
        DEMO3D_GRAPHIC_DeleteBg(ctx);
    }
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    MI_CpuFill8(ctx, 0, 24);
    func_020307B0(ctx);
}
