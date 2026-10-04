/*
 * function: func_021B9FC8
 * address: 0x021B9FC8
 * packet: pkt_ov069_021B9FC8
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * symbols:
 *   func_0202616C 0x0202616C thumb
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj09876.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Point { u16 x, y; } Point;
extern u8 *func_0202616C(void *p, int i);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021B9FC8(char *p, int i)
{
    Point pt;
    u8 *v;
    v = func_0202616C(((struct Obj09876 *)p)->f14C, i);
    pt.x = v[0];
    pt.y = v[1];
    func_0204B404(((struct Obj09876 *)p)->f124, (const struct Vec2 *)(&pt), 0);
}
