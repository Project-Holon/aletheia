/*
 * function: func_021D8ED0
 * address: 0x021D8ED0
 * packet: pkt_ov131_021D8ED0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj00091.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u16 x; u16 y; } Point;
extern s16 func_021D9440(u8 *,u32);
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_0204B404(void *,const Point *,u32);
void func_021D8ED0(u8 *a,u8 *p,u8 n)
{
    Point pt;
    pt.x=8;
    pt.y=func_021D9440(p,n);
    func_0204B404(((struct Obj00091 *)p)->f54,&pt,0);
    p[0x58]=n;
    *(int *)&((struct Obj00091 *)p)->f68=1;
    p[0x59]=func_021D9428(p,n);
}
