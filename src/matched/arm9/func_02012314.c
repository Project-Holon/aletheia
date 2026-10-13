/*
 * function: GAME_EVENT_Delete
 * address:  0x02012314
 * packet:   pkt_02012304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj01023.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void GAME_EVENT_Delete(char *p)
{
    void *q = ((struct Obj01023 *)p)->fC;
    if (q) func_020307B0(q);
    func_020307B0(p);
}
