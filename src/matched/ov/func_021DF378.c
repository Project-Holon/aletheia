/*
 * function: BOX2_MAIN_PopSubArgs
 * address:  0x021DF378
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
 * Mirror a word into a halfword field, forward, return 0.
 */
#include "../include/Obj12156.h"
#include "../include/Obj18460.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int BOX2_MAIN_PopSubArgs(char *p)
{
    char *q = *(char * *)&((struct Obj12156 *)p)->fC;

    ((struct Obj12156 *)p)->f10 = ((struct Obj18460 *)q)->f38;
    func_020307B0(q);
    return 0;
}

