/*
 * A single matched function.
 *
 * unit:     yes
 * address:  0x020169D4
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MCSS_InitEdgeColor
 *
 * alias: a direct write of a fixed 32-bit value to a hardware register pair
 * at 0x040004C0: the low word gets the full constant, the high word (at
 * +4) gets its upper halfword. This is a raw I/O register store, not an
 * SDK call, which is why it is game code sitting on hardware address space.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020169D4.c \
 *       --func MCSS_InitEdgeColor --addr 0x020169D4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

void MCSS_InitEdgeColor(void)
{
    u32 v = 0x4210FFFF;
    *(volatile u32 *)0x040004C0 = v;
    *(volatile u32 *)0x040004C4 = v >> 16;
}
