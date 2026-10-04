/*
 * function: func_021B9398
 * address: 0x021B9398
 * packet: pkt_ov067_021B9398
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: 2-byte alignment padding; separate existing functions follow
 */
#include "../include/Obj20628.h"
typedef unsigned int u32;
u32 func_021B9398(char *p, int index)
{
    return *(u32 *)(*(char * *)&((struct Obj20628 *)p)->f28 + index * 8 + 4);
}
