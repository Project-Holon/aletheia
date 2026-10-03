/*
 * function: func_0202C590
 * address:  0x0202C590
 * packet:   pkt_0202C590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_020A7780      0x020A7780  data
 */

extern char g_020A7780[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *func_0202C590(int a0)
{
    return func_02030734(a0, 0xc, 0, g_020A7780, 0x115);
}
