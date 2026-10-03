/*
 * function: func_021B9800
 * address:  0x021B9800
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Allocates the 0x5a8-byte block, publishes it at 0x021CF960 and stamps the two caller fields.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

u8 *func_021B9800(int a, int b, int c)
{
    u8 *p = func_02030734(a, 0x5a8, 1, (const char *)0x021CE310, 0x1aa);

    *(u32 *)0x021CF960 = (u32)p;
    *(u32 *)(p + 0x5a4) = b;
    *(u32 *)(p + 8) = c;
    return p;
}
