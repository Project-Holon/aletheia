/*
 * function: func_0204F604
 * address:  0x0204F604
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   none (no external calls, no data references)
 *
 * Same record and field as BILLBOARD_FreeElem, but the low 14 bits are copied
 * in from the caller's u16.  The compiler reuses the inverted mask it
 * already needed as `lsr #18` rather than materialising 0x3fff twice.
 */
#include "../include/Obj08866.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0204F604(void *p, u32 idx, u16 *src)
{
    u16 *q = (u16 *)(*(u8 * *)&((struct Obj08866 *)p)->f8 + idx * 0x1c);

    *q = (u16)((*q & ~0x3fff) | (*src & 0x3fff));
}
