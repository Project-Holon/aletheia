/*
 * function: func_02204FF8
 * address:  0x02204FF8
 * packet:   pkt_02204FF8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005D28 0x02005D28 thumb
 */
#include "../include/Obj14527.h"

extern int func_02005E9C(void);
extern void func_02005D28(void);

void func_02204FF8(int a, char *b)
{
    if (((struct Obj14527 *)b)->f30 == 5) {
        func_02005E9C();
        func_02005D28();
        ((struct Obj14527 *)b)->f30 = 0;
    }
}