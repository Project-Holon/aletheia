/*
 * function: func_0201F9E8
 * address:  0x0201F9E8
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj02993.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj;

struct D;
extern void func_02020D3C(struct D *p);
extern void func_020307B0(void *p);

void func_0201F9E8(struct Obj *o, u8 *out)
{
    if (out != 0) {
        *out = ((struct Obj02993 *)o)->f2D;
    }
    func_02020D3C((struct D *)(((struct Obj02993 *)o)->f24));
    func_020307B0(o);
}
