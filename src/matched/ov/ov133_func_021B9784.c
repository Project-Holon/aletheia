/*
 * function: func_021B9784
 * address: 0x021B9784
 * packet: pkt_ov133_021B9784
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 148-byte lead; unlabelled follower 021B9818 is parked at docs/notes/pkt_ov133_021B9818.c.txt.
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06500.h"
typedef unsigned char u8;
typedef short s16;
typedef struct {s16 x,y;} Pos;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);
void func_021B9784(u8 *p)
{
    Pos pos;
    u8 pal;
    pos.x=32;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos(((struct Obj06500 *)p)->f184C,(const struct Vec2 *)(&pos),0);
    pos.x=224;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos(((struct Obj06500 *)p)->f1850,(const struct Vec2 *)(&pos),0);
    pal=p[0x18c0]*24/60+4;
    if(pal>=11) pal=3;
    func_020413B0(2,10,44,12,12,pal);
    func_02041B6C(2);
}
