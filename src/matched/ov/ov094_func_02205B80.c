/*
 * function: func_02205B80
 * address:  0x02205B80
 * packet:   pkt_ov094_02205B80
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj21785.h"

typedef unsigned int   u32;
struct Bank;
extern void func_0204B22C(struct Bank *bank, u32 mode);

void func_02205B80(char *p, int a)
{
    func_0204B22C(((struct Obj21785 *)p)->f1C4, a);
}
