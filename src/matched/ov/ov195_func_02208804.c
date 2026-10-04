/*
 * function: func_02208804
 * address:  0x02208804
 * packet:   pkt_02208804
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02208A78 0x02208A78 thumb
 *   func_02208A24 0x02208A24 thumb
 */
#include "../include/Obj08350.h"

extern void func_02208A78(void *);
extern void func_02208A24(int);

void func_02208804(char *a)
{
    func_02208A78(a);
    func_02208A24(((struct Obj08350 *)a)->f10);
}
