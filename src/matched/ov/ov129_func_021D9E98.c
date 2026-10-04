/*
 * function: func_021D9E98
 * address: 0x021D9E98
 * packet: pkt_ov129_021D9E98
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
#include "../include/Obj14059.h"
typedef unsigned short u16;
typedef struct { u16 x,y; } Pair;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021D9E98(char *p,int i)
{
    Pair s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    func_0204B404((struct Obj *)(((struct Obj14059 *)p)->f1B0),(const struct Vec2 *)(&s),0);
    func_0204B8C4((struct Obj *)(((struct Obj14059 *)p)->f1B0),0);
}
