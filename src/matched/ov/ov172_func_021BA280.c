/*
 * function: CTVT_DRAW_Create
 * address:  0x021BA280
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x98-byte record and seeds its counters.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06562.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);

void CTVT_DRAW_Create(void *a, void *b)
{
    char *v = func_02030734((u32)b, 0x98, 1, (void *)0x021C7228, 0xcf);

    v[0x36] = 0;
    v[0x37] = 3;
    ((struct Obj06562 *)v)->f28 = 0;
    ((struct Obj06562 *)v)->f24 = 0;
    ((struct Obj06562 *)v)->f34 = 0x8000;
}
