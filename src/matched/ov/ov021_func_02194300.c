/*
 * function: func_02194300
 * address:  0x02194300
 * packet:   pkt_ov021_02194300
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_02194434  0x02194434  thumb  ov021
 */
#include "../include/Obj07446.h"
#include "../include/Obj09482.h"

typedef unsigned short u16;

extern int func_021945A0(int x);
extern void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);

void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f)
{
    u16 i;
    unsigned char *q = *(unsigned char * *)&((struct Obj09482 *)a)->f8;

    func_021945A0(*d);
    for (i = 0; i < *a; i++) {
        if (*(int *)&((struct Obj07446 *)q)->f8 == 0) {
            ((struct Obj07446 *)q)->f8 = func_02194434((unsigned char *)a, c, d, e, f, (int)q);
            ((struct Obj07446 *)q)->f0 = b;
            ((struct Obj07446 *)q)->f6 = a[1];
            return;
        }
        q += 0xc;
    }
}
