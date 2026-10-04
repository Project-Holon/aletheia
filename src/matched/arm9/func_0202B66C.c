/*
 * function: func_0202B66C
 * address:  0x0202B66C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0x14 field through func_0202B1EC (the OS_FreeToHeap thunk)
 * and clears it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B66C.c \
 *       --func func_0202B66C --addr 0x0202B66C --thumb --cc 1.1p1
 */
#include "../include/Obj02011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern void func_0202B1EC(void *ptr);

void func_0202B66C(struct Obj *o)
{
    func_0202B1EC((void *)(((struct Obj02011 *)o)->f14));
    ((struct Obj02011 *)o)->f14 = 0;
}
