/*
 * function: func_0202C124
 * address:  0x0202C124
 * packet:   pkt_0202C124
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A7758     0x020A7758  data
 *
 * Allocates 16 bytes from heap with tracking file and line.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C124.c \
 *       --func func_0202C124 --addr 0x0202C124 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern const char g_020A7758[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *func_0202C124(u32 heap)
{
    return func_02030734(heap, 0x10, 0, g_020A7758, 0x10A);
}
