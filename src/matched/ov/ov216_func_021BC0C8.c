/*
 * function: func_021BC0C8
 * address: 0x021BC0C8
 * packet: pkt_ov216_021BC0C8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203101C 0x0203101C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 */
#include "../include/Obj00366.h"
typedef unsigned short u16;

struct Tcbl; struct GfFont; struct WordSet; struct MsgBank; struct U16Vec;
extern struct Tcbl *func_0203101C(unsigned,unsigned short,unsigned,unsigned);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_0201DD78(unsigned,unsigned,unsigned);
extern void *func_0201C450(unsigned short,unsigned);
extern struct GfFont *func_0201D7EC(int,int,int,int,unsigned);
extern struct WordSet *func_0201EC74(unsigned,unsigned,unsigned);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
void func_021BC0C8(char *p)
{
    *(struct Tcbl * *)&((struct Obj00366 *)p)->f18=func_0203101C(((struct Obj00366 *)p)->f0,((struct Obj00366 *)p)->f0,64,128);
    ((struct Obj00366 *)p)->f54=func_020490F4(173,((struct Obj00366 *)p)->f0);
    func_0201DD78(7,8,15);
    ((struct Obj00366 *)p)->f12C=func_0201C450(2048,((struct Obj00366 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00366 *)p)->f128=func_0201D7EC(23,0,0,0,((struct Obj00366 *)p)->f0);
    *(struct WordSet * *)&((struct Obj00366 *)p)->f138=func_0201EC74(8,64,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f130=func_02045B38(0,2,7,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f134=func_02045B38(0,2,231,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f13C=func_020457B0(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f140=func_020457B0(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f144=func_020457B0(109,((struct Obj00366 *)p)->f0);
}
