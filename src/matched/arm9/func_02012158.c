/*
 * function: func_02012158
 * address:  0x02012158
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02012BC8
 */
#include "../include/Obj15624.h"

extern void func_02012BC8(unsigned char *p, int on);
void func_02012158(char *p, unsigned int v)
{
    func_02012BC8((unsigned char *)((struct Obj15624 *)p)->f1C, v);
}
