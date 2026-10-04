/*
 * function: func_021B61FC
 * address:  0x021B61FC
 * packet:   pkt_ov090_021B61FC
 * region:   ov090
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 */
#include "../include/Obj20845.h"

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);

int func_021B61FC(int a, int b)
{
    if (func_02039CB4((struct Link *)func_020399A8(), b, 0x2d) == 1)
        return 1;
    if (((struct Obj20845 *)a)->f63 == 1)
        return 1;
    return 0;
}
