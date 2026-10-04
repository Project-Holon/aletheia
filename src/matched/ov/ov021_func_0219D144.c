/*
 * function: func_0219D144
 * address:  0x0219D144
 * packet:   pkt_ov021_0219D144
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 */
#include "../include/Obj07478.h"

typedef unsigned short u16;
extern u16 func_0216D4F0(void *p);

int func_0219D144(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}
