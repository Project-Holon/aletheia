/*
 * function: func_0216D7A8
 * address: 0x0216D7A8
 * packet: pkt_ov010_0216D7A8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj00113.h"
#include "../include/Obj19128.h"

typedef int (*Callback)(void *, unsigned int);
int func_0216D7A8(void *p, unsigned int v)
{
    Callback f;
    f = *(Callback *)&((struct Obj19128 *)((char *)((struct Obj00113 *)p)->f90))->f14;
    if (f != 0)
        return f(p, v);
    return 0;
}
