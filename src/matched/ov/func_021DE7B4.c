/*
 * function: BOX2_MAIN_DeleteScroll
 * address:  0x021DE7B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *
 * Tail call func_020307B0 with the pooled-offset word.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18453.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BOX2_MAIN_DeleteScroll(char *p)
{
    func_020307B0(((struct Obj18453 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190);
}

