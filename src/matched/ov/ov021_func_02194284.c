/*
 * function: FIELD_COMM_ACTOR_CTRL_Create
 * address:  0x02194284
 * packet:   pkt_ov021_02194284
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sFieldCommActorFileName     0x021DDA70  data  a4
 */
#include "../include/Obj07444.h"

typedef unsigned short u16;

extern int sFieldCommActorFileName;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);

void *FIELD_COMM_ACTOR_CTRL_Create(int a, void *b, int heap, int c)
{
    int n = 0xc;
    char *p = (char *)func_02030734(heap, n, 1, (const char *)&sFieldCommActorFileName, 0x5d);

    ((struct Obj07444 *)p)->f0 = a;
    ((struct Obj07444 *)p)->f2 = c;
    ((struct Obj07444 *)p)->f4 = b;
    ((struct Obj07444 *)p)->f8 = func_02030734(heap, n * a, 1, (const char *)&sFieldCommActorFileName, 0x63);
    return p;
}
