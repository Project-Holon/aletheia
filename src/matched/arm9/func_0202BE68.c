/*
 * function: func_0202BE68
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
 * 0x020A7748 the sibling func_0202BEEC pools.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE68.c \
 *       --func func_0202BE68 --addr 0x0202BE68 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, u32 zero,
                           const void *file, u32 line);
extern void  func_0202BEEC(u8 *p, u32 heapId);

u8 *func_0202BE68(u32 heapId)
{
    u8 *p = (u8 *)func_02030734(heapId, 0x18, 0, (const void *)0x020A7748,
                                0x55);

    *(u32 *)p = 0;
    p[4] = 0;
    *(u32 *)(p + 8) = 0;
    p[0xc] = 0xff;
    *(u16 *)(p + 0xe) = 0;
    *(u16 *)(p + 0x10) = 0;
    *(u16 *)(p + 0x12) = 0;
    *(u16 *)(p + 0x14) = 0;
    func_0202BEEC(p, heapId);
    return p;
}
