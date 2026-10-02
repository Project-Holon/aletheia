/*
 * function: func_02158804
 * address: 0x02158804
 * packet: pkt_ov010_02158804
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_02172888 0x02172888 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern const char d_02172888[];
void *func_02158804(u32 heap) {
    u16 *p = func_02030734(heap, 0x18, 1, d_02172888, 0xef);
    *p = heap;
    return p;
}
