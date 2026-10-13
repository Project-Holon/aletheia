/*
 * function: func_021BC8A8
 * address: 0x021BC8A8
 * packet: pkt_ov216_021BC8A8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMS_DRAW_Delete  0x0202DC08  thumb  arm9
 */
#include "../include/Obj01437.h"
#include "../include/Obj05553.h"
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PMS_DRAW_Delete(struct Obj *p);
void func_021BC8A8(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        CLACT_SetActorDrawEnable(((struct Obj05553 *)q)->f78,0); CLACT_DeleteActor(((struct Obj05553 *)q)->f78);
        CLACT_SetActorDrawEnable(((struct Obj05553 *)q)->f74,0); CLACT_DeleteActor(((struct Obj05553 *)q)->f74);
        BMP_WIN_Delete(((struct Obj05553 *)q)->f60);
        for(j=0;j<2;j++) BMP_WIN_Delete(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) BMP_WIN_Delete(*(void **)(q+j*16));
        BMP_WIN_Delete(((struct Obj05553 *)q)->f70);
    }
    PMS_DRAW_Delete(((struct Obj01437 *)p)->f158);
}
