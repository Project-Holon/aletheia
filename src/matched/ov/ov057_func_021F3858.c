/*
 * function: GIMMICK57_DrawModelScene
 * address:  0x021F3858
 * packet:   pkt_021F3858
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   d_021F38C4     0x021F38C4  data
 */
#include "../include/Obj09853.h"

struct Arg;
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern int d_021F38C4;

void GIMMICK57_DrawModelScene(int a, int b, char *c)
{
    G3D_SYSTEM_DrawObject(((struct Obj09853 *)c)->f38, (struct Arg *)(&d_021F38C4));
    G3D_SYSTEM_DrawObject(((struct Obj09853 *)c)->f3C, (struct Arg *)(&d_021F38C4));
    G3D_SYSTEM_DrawObject(((struct Obj09853 *)c)->f40, (struct Arg *)(&d_021F38C4));
}
