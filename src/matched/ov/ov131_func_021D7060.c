/*
 * function: func_021D7060
 * address: 0x021D7060
 * packet: pkt_ov131_021D7060
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: byte threshold and halfword counter. Increment promotes to
 *   int in [1,65536], then the halfword store wraps; comparison reloads it.
 *   Caller 6F54 loads context r0, child r1, byte-counter pointer r2.
 */
#include "../include/Obj10509.h"
typedef unsigned char u8;
typedef unsigned short u16;
int func_021D7060(void *unused,u8 *q,u8 *counter)
{
    if(*counter<10) {
        ++((struct Obj10509 *)q)->f60;
        if(((struct Obj10509 *)q)->f60>24) return 0;
    } else ((struct Obj10509 *)q)->f60=0;
    return 1;
}
