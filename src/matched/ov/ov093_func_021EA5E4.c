/*
 * function: func_021EA5E4
 * address:  0x021EA5E4
 * packet:   pkt_ov093_021EA5E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045838  0x02045838  arm
 */
#include "../include/Obj21562.h"

struct U16Vec;
void func_02045838(struct U16Vec *dst, struct U16Vec *src);

void func_021EA5E4(unsigned char *p, void *src)
{
    func_02045838(((struct Obj21562 *)p)->fAC, src);
}
