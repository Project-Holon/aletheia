/*
 * function: P_STA_INFO_FreeWork
 * address:  0x021D7B34
 * packet:   pkt_021D7B34
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23143.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void P_STA_INFO_FreeWork(int a, char *p)
{
    func_020307B0(((struct Obj23143 *)p)->f8);
    func_020307B0(p);
}
