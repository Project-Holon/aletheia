/*
 * function: func_021BD538
 * address:  0x021BD538
 * packet:   pkt_021BD538
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   (none)

 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */
#include "../include/Obj05865.h"


typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void MI_CpuFill8(int, int, int);

void func_021BD538(char *p)
{
    unsigned int w;

    CLACT_ReleaseCellAnim(((struct Obj05865 *)p)->f8);
    CLACT_ReleaseCharacter(((struct Obj05865 *)p)->f4);
    CLACT_ReleasePalette(((struct Obj05865 *)p)->f0);
    w = ((struct Obj05865 *)p)->f10;
    func_0203FB44(((struct Obj05865 *)p)->fC, (unsigned short)w, (unsigned short)(w >> 16));
    MI_CpuFill8((int)p, 0, 0x14);
}

