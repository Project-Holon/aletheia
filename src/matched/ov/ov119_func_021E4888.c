/*
 * function: POKETRADE_2D_DeleteAllBoxIcons
 * address: 0x021E4888
 * packet: pkt_ov119_021E4888
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_DeletePickedIconActor 0x021E69A4 thumb ov119
 *   POKETRADE_2D_DeleteBoxIconRow 0x021E4810 thumb ov119
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00001.h"
extern void POKETRADE_2D_DeletePickedIconActor(char *);
extern void POKETRADE_2D_DeleteBoxIconRow(char *, int);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 func_020307B0(void *p);
void POKETRADE_2D_DeleteAllBoxIcons(char *p)
{
    int i;
    POKETRADE_2D_DeletePickedIconActor(p);
    for (i = 0; i < 12; i++) POKETRADE_2D_DeleteBoxIconRow(p, i);
    if (((struct Obj00001 *)p)->f87C) {
        CLACT_ReleasePalette(((struct Obj00001 *)p)->f87C);
        ((struct Obj00001 *)p)->f87C = 0;
    }
    if (((struct Obj00001 *)p)->f8AC) {
        CLACT_ReleaseCellAnim(((struct Obj00001 *)p)->f8AC);
        ((struct Obj00001 *)p)->f8AC = 0;
    }
    if (((struct Obj00001 *)p)->f1184) func_020307B0(((struct Obj00001 *)p)->f1184);
    ((struct Obj00001 *)p)->f1184 = 0;
}
