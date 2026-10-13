/*
 * function: FIELD_FOG_Create
 * address:  0x021A0104
 * packet:   pkt_ov021_021A0104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_FOG_InitFogTable  0x021A01D8  thumb  ov021
 *   d_021DDE1C     0x021DDE1C  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09535.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDE1C[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_FOG_InitFogTable(u8 *p);

u8 *FIELD_FOG_Create(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x44, 1, d_021DDE1C, 0x89);
    p[1] = 0;
    p[3] = 0x1F;
    ((struct Obj09535 *)p)->f4 = 0x7FFF;
    FIELD_FOG_InitFogTable(p);
    return p;
}
