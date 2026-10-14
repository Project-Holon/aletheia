/*
 * function: GURU2_MAIN_UpdateCenterTransform
 * address: 0x021E0570
 * packet: pkt_ov137_021E0570
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_AddAngleWrapped 0x021E15DC thumb ov137
 */
#include "../include/Obj01754.h"
#include "../include/Obj14233.h"
typedef unsigned char u8;
typedef short s16;
extern void GURU2_MAIN_AddAngleWrapped(int *,int);
void GURU2_MAIN_UpdateCenterTransform(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=((struct Obj14233 *)p)->f58;
    GURU2_MAIN_AddAngleWrapped(&angle,((struct Obj01754 *)s)->f40);
    GURU2_MAIN_AddAngleWrapped(&angle,((struct Obj01754 *)s)->f44);
    ((struct Obj01754 *)s)->f4E=(360-angle/4096)%360;
    ((struct Obj01754 *)s)->fC=((struct Obj14233 *)p)->fE0+((struct Obj01754 *)s)->f30+((struct Obj01754 *)s)->f24;
    ((struct Obj01754 *)s)->f10=((struct Obj01754 *)s)->f4+((struct Obj01754 *)s)->f34+((struct Obj01754 *)s)->f28;
    ((struct Obj01754 *)s)->f14=((struct Obj01754 *)s)->f8+((struct Obj01754 *)s)->f38+((struct Obj01754 *)s)->f2C;
}
