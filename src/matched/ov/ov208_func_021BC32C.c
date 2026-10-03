/*
 * function: func_021BC32C
 * address: 0x021BC32C
 * packet: pkt_ov208_021BC32C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D80 0x021C8D80 data a1
 */
typedef unsigned int u32;
struct Ov208Buf { int f0; int f4; int f8; int fc; void *buf; };
extern const char d_021C8D80[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap)
{
    p->buf = func_02030734(heap, size, 0, d_021C8D80, 0xc8);
    return p->buf;
}
