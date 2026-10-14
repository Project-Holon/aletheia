/*
 * function: GURU2_MAIN_RemovePlayerUnits
 * address: 0x021E073C
 * packet: pkt_ov137_021E073C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 */
#include "../include/Obj10629.h"
#include "../include/Obj14237.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
void GURU2_MAIN_RemovePlayerUnits(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) G3D_UTIL_RemoveUnit(((struct Obj10629 *)p)->fAF4,(u16)(*(int *)(q+0x940+i*4)));
    G3D_UTIL_RemoveUnit(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f938));
    G3D_UTIL_RemoveUnit(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f93C));
}
