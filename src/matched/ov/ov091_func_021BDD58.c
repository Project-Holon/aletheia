/*
 * function: func_021BDD58
 * address: 0x021BDD58
 * packet: pkt_ov091_021BDD58
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding at 0x021BDD76.
 * symbols:
 *   func_02017988 0x02017988 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 */
#include "../include/Obj20931.h"
typedef unsigned int u32;
struct Blk37;
extern u32 func_02017988(void *, u32);
extern void func_0200CDE0(struct Blk37 *, void *);
void func_021BDD58(u32 p, void *m)
{
    func_02017988(m, 1);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20931 *)p)->f280 + 0x18), m);
}
