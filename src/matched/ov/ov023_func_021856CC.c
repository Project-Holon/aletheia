/*
 * function: func_021856CC
 * address:  0x021856CC
 * packet:   pkt_021856CC
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 */
#include "../include/Obj20350.h"

extern void func_02185354(char *p);
typedef unsigned int   u32;
extern void func_02186444(char *p, u32 v);
extern int  func_021862B0(char *p);

int func_021856CC(char *p, int a1)
{
    if (func_021862B0(p)) {
        ((struct Obj20350 *)p)->f1A4 = 0;
        func_02186444(p, 0xe);
    }
    func_02185354(p);
    return a1;
}
