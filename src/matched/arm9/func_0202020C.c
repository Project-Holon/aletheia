/*
 * function: func_0202020C
 * address:  0x0202020C
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj08775.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

struct D;
extern void func_02020D3C(struct D *p);
extern u32 func_020307B0(void *p);

void func_0202020C(struct Obj *o, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = ((struct Obj08775 *)o)->f40;
    }
    if (b != 0) {
        *b = ((struct Obj08775 *)o)->f42;
    }
    func_02020D3C((struct D *)(((struct Obj08775 *)o)->f3C));
    func_020307B0(o);
}
