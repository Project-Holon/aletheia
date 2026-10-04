/*
 * function: func_021FD110
 * address: 0x021FD110
 * packet: pkt_ov186_021FD110
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: accessor after func_021FD0B8; two alignment bytes after return.
 */
#include "../include/Obj08333.h"
void func_021FD110(char *p)
{
    ((struct Obj08333 *)p)->f48=((int *)(((struct Obj08333 *)p)->f0+(((struct Obj08333 *)p)->f40+((struct Obj08333 *)p)->f42)*8))[1];
}
