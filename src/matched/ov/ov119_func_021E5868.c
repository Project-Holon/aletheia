/*
 * function: func_021E5868
 * address:  0x021E5868
 * packet:   pkt_ov119_021E5868
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj04483.h"
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021E5868(char *p)
{
    if (((struct Obj04483 *)p)->f898 != 0) {
        CLACT_ReleaseCharacter(((struct Obj04483 *)p)->f898);
        CLACT_ReleasePalette(((struct Obj04483 *)p)->f884);
        CLACT_ReleaseCellAnim(((struct Obj04483 *)p)->f8B4);
        ((struct Obj04483 *)p)->f898 = 0;
        ((struct Obj04483 *)p)->f884 = 0;
        ((struct Obj04483 *)p)->f8B4 = 0;
    }
}
