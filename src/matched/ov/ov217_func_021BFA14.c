/*
 * function: RESEARCH_GRAPH_Alloc
 * address:  0x021BFA14
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_GRAPH_Alloc  0x021BFA14  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
u32 RESEARCH_GRAPH_Alloc(u32 a0)
{
    return (u32)func_02030734(a0, 1000, 0, (const char *)0x21C400C, 4096);
}

