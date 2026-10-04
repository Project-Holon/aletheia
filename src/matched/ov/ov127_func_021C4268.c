/*
 * function: func_021C4268
 * address: 0x021C4268
 * packet: pkt_ov127_021C4268
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return.
 */
#include "../include/Obj23017.h"
#include "../include/Obj23018.h"
typedef unsigned char u8;
void *func_021C4268(u8 *p)
{
    return ((struct Obj23018 *)(*(u8 * *)&((struct Obj23017 *)p)->f0))->f10;
}
