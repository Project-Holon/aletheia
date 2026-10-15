/*
 * function: BOX2_SEQ_StateDeleteHandle
 * address:  0x021E8014
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *
 * Forward and then return a status constant.
 */
#include "../include/Obj18466.h"
#include "../include/Obj18467.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int BOX2_SEQ_StateDeleteHandle(char *p)
{
    func_020307B0(((struct Obj18467 *)(*(char * *)&((struct Obj18466 *)p)->f2C))->f60);
    return 0x56;
}

