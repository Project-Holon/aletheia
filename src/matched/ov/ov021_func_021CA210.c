/*
 * function: func_021CA210
 * address:  0x021CA210
 * packet:   pkt_ov021_021CA210
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object at +0x6c's handle unless the query on +0x70 is set, then the cached +0x7c8.
 *
 * symbols:
 *   func_0200D884  0x0200D884  thumb
 *   func_02012934  0x02012934  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0200D884(u32 a, int b, int c);
extern void *func_02012934(void *p);

void *func_021CA210(u8 *p)
{
    if (func_0200D884(*(u32 *)(p + 0x70), 10, 0) == 0)
        return func_02012934(*(void **)(p + 0x6c));
    return *(void **)(p + 0x7c8);
}
