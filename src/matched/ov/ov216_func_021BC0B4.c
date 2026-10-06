/*
 * function: func_021BC0B4
 * address:  0x021BC0B4
 * packet:   pkt_021BC0B4
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BBB34  0x021BBB34  thumb  ov072
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14715.h"

extern void func_021BBB34(void *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021BC0B4(char *p)
{
    func_021BBB34((void *)(((struct Obj14715 *)p)->f1C));
    func_020307B0((void *)(((struct Obj14715 *)p)->f28));
}
