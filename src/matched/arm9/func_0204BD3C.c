/*
 * unit:     no
 * function: func_0204BD3C
 * address:  0x0204BD3C
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  02063138 has no witness outside this range
 */
#include "../include/Obj11428.h"

extern unsigned int func_02063138(void *p, int a, int b, int which);
void func_0204BD3C(char *p, int a, int b, int which)
{
    if (b == 0) {
        ((struct Obj11428 *)p)->f1C = 0;
        return;
    }
    func_02063138(p, a, b, which);
    ((struct Obj11428 *)p)->f1C = 1;
}
