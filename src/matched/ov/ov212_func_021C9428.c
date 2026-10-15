/*
 * function: ZUKAN_SEARCH_ENGINE_Create
 * address:  0x021C9428
 * packet:   pkt_021C9428
 * region:   ov212
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 */
#include "../include/Obj03938.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);

void ZUKAN_SEARCH_ENGINE_Create(int p, int b, int c)
{
    unsigned char *q = func_02030734(c, 0x48, 1, (const char *)0x021C99A8, 0x1ce);

    ((struct Obj03938 *)q)->f0 = p;
    ((struct Obj03938 *)q)->f4 = b;
    ((struct Obj03938 *)q)->f8 = 0;
    ((struct Obj03938 *)q)->fC = 0;
    ((struct Obj03938 *)q)->f10 = 0;
    ((struct Obj03938 *)q)->f3C = 0;
    ((struct Obj03938 *)q)->f40 = 0;
    ((struct Obj03938 *)q)->f44 = 0;
}
