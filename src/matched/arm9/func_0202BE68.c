/*
 * function: ISS_ZONE_SYS_Create
 * address:  0x0202BE68
 * packet:   pkt_0202BE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x18-byte iss_zone_sys node through the debug allocator, zeroes
 * its fields with the two exceptions (+0xc takes 0xff, the "no record" index),
 * and runs the init that takes the heap id.
 *
 * The allocator's __FILE__ word is the anchor at 0x0202BEA0, the same
 * 0x020A7748 the sibling ISS_ZONE_SYS_LoadRecords pools.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_Create.c \
 *       --func ISS_ZONE_SYS_Create --addr 0x0202BE68 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ZONE_SYS_LoadRecords  0x0202BEEC  thumb
 */
#include "../include/Obj03439.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  ISS_ZONE_SYS_LoadRecords(u8 *p, u32 heapId);

u8 *ISS_ZONE_SYS_Create(u32 heapId)
{
    u8 *p = (u8 *)func_02030734(heapId, 0x18, 0, (const void *)0x020A7748,
                                0x55);

    ((struct Obj03439 *)p)->f0 = 0;
    p[4] = 0;
    ((struct Obj03439 *)p)->f8 = 0;
    p[0xc] = 0xff;
    ((struct Obj03439 *)p)->fE = 0;
    ((struct Obj03439 *)p)->f10 = 0;
    ((struct Obj03439 *)p)->f12 = 0;
    ((struct Obj03439 *)p)->f14 = 0;
    ISS_ZONE_SYS_LoadRecords(p, heapId);
    return p;
}
