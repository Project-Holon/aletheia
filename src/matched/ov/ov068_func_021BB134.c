/*
 * unit:     yes
 * function: func_021BB134, func_021BB138, func_021BB140
 * address:  0x021BB134
 * packet:   pkt_ov068_021BB134
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter and two small setters.
 */
#include "../include/Obj13146.h"
#include "../include/Obj20651.h"
#include "../include/Obj20652.h"

int func_021BB134(void *p)
{
    return ((struct Obj20651 *)p)->f4;
}

void func_021BB138(void *p, int v)
{
    ((struct Obj13146 *)p)->f0 = v;
    ((struct Obj13146 *)p)->f8 = 0;
}

void func_021BB140(void *p)
{
    ((struct Obj20652 *)p)->f4 = 1;
}
