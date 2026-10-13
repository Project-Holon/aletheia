/*
 * function: ISS_SYS_Delete3ds
 * address:  0x0202B6BC
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_3DS_SYS_Delete  0x0202B8E4  thumb
 */
#include "../include/Obj02011.h"

struct Obj;
extern void ISS_3DS_SYS_Delete(struct Obj *o);
void ISS_SYS_Delete3ds(int a0)
{
    ISS_3DS_SYS_Delete((struct Obj *)(((struct Obj02011 *)a0)->f24));
    ((struct Obj02011 *)a0)->f24 = 0;
}
