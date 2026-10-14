/*
 * function: MB_SEQ_FinishChildFreeB
 * address:  0x021C74F8
 * packet:   pkt_ov136_021C74F8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0            0x020307B0  arm
 */
#include "../include/Obj23652.h"

typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int MB_SEQ_FinishChildFreeB(u8 *p)
{
    func_020307B0(((struct Obj23652 *)p)->f10);
    return 8;
}
