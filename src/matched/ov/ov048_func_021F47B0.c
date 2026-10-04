/*
 * unit:     yes
 * function: func_021F47B0, func_021F47B4, func_021F47B8
 * address:  0x021F47B0
 * packet:   pkt_021F47B0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * int getter, u16 getter, u8 getter.
 */
#include "../include/Obj20545.h"
#include "../include/Obj20546.h"
#include "../include/Obj20547.h"

int func_021F47B0(void *p)
{
    return ((struct Obj20545 *)p)->f18;
}

int func_021F47B4(void *p)
{
    return ((struct Obj20546 *)p)->f0;
}

int func_021F47B8(void *p)
{
    return ((struct Obj20547 *)p)->f2;
}
