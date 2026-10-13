/*
 * function: func_021DD528
 * address: 0x021DD528
 * packet: pkt_ov119_021DD528
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj06425.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021DD528(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,((struct Obj06425 *)p)->f5F4);off=96;if(n!=1)off=0;((struct Obj06425 *)p)->f890=CLACT_RegisterPaletteCompressed(v,func_0201BC3C(),n,(u16)off,((struct Obj06425 *)p)->f5F4);a=func_0201BC78();((struct Obj06425 *)p)->f8C0=CLACT_RegisterCellAnim(v,a,func_0201BCB4(),((struct Obj06425 *)p)->f5F4);ARC_TOOL_DeleteHandle(v);
}
