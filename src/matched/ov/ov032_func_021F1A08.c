/*
 * function: func_021F1A08
 * address: 0x021F1A08
 * packet: pkt_ov032_021F1A08
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F1A28 0x021F1A28 thumb ov032
 */
#include "../include/Obj20433.h"

typedef unsigned char u8;
extern void func_021F1A28(char *p, int b, u8 c, int *r);
void func_021F1A08(char *p)
{
    func_021F1A28(p, ((struct Obj20433 *)p)->f28, 0, (int *)(p + 0xa8));
}
