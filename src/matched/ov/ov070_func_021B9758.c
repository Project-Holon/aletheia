/*
 * function: func_021B9758
 * address:  0x021B9758
 * packet:   pkt_ov070_021B9758
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */
#include "../include/Obj06175.h"

typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);

void func_021B9758(char *p)
{
    unsigned v;
    v = ((struct Obj06175 *)p)->f7FC;
    func_0203FB44((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f800;
    func_0203FB44((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f808;
    func_0203FB44((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f7F8;
    func_0203FB44((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f804;
    func_0203FB44((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}
