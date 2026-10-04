/*
 * function: func_021BDCA0
 * address: 0x021BDCA0
 * packet: pkt_ov091_021BDCA0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding at 0x021BDCBE.
 * symbols:
 *   func_02017988 0x02017988 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 */
#include "../include/Obj20928.h"
typedef unsigned int u32;
struct Blk37;
extern u32 func_02017988(void *, u32);
extern void func_0200CDE0(struct Blk37 *, void *);
void func_021BDCA0(u32 p, void *m)
{
    func_02017988(m, 0);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20928 *)p)->f280 + 0x18), m);
}
