/*
 * function: DUP_FITTING_StepPoseSlide
 * address: 0x021B9AC0
 * packet: pkt_ov133_021B9AC0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00228.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void DUP_FITTING_StepPoseSlide(u8 *p, int *a, int *b, u16 duration)
{
    int x, y;
    int count;
    ((struct Obj00228 *)p)->f18 = 1;
    if (((struct Obj00228 *)p)->f1844 == 0) ((struct Obj00228 *)p)->f14 = 1;
    else ((struct Obj00228 *)p)->f14 = 0;
    count = ((struct Obj00228 *)p)->f1844;
    y = a[1] + (b[1] - a[1]) * count / (int)duration;
    x = a[0] + (b[0] - a[0]) * count / (int)duration;
    ((struct Obj00228 *)p)->f1C = x;
    ((struct Obj00228 *)p)->f20 = y;
    CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854, 1);
    (((struct Obj00228 *)p)->f1844)++;
    if (((struct Obj00228 *)p)->f1844 > duration) {
        ((struct Obj00228 *)p)->f1844 = 0;
        (((struct Obj00228 *)p)->f1846)++;
    }
}
