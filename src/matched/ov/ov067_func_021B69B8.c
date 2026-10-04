/*
 * unit:     yes
 * function: func_021B69B8, func_021B69BC, func_021B69C8, func_021B69D0, func_021B69D4
 * address:  0x021B69B8
 * packet:   pkt_ov067_021B69B8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj20610.h"
#include "../include/Obj20611.h"
#include "../include/Obj20612.h"
#include "../include/Obj20613.h"

int func_021B69B8(void *p)
{
    return ((struct Obj20610 *)p)->f18;
}

typedef unsigned int   u32;
struct Obj;
void func_021B69BC(void *p, unsigned int v)
{
    void func_0204B3DC(struct Obj *p, u32 v);
    func_0204B3DC(((struct Obj20611 *)p)->f0, v);
}

int func_021B69C8(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}

void func_021B69D0(void *p, int v)
{
    ((struct Obj20612 *)p)->f34 = v;
}

void func_021B69D4(void *p, int v)
{
    ((struct Obj20613 *)p)->f30 = v;
}
