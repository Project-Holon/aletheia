/*
 * function: func_0202C384
 * address:  0x0202C384
 * packet:   pkt_0202C384
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A776C     0x020A776C  data
 */
typedef unsigned int u32;

extern void *func_02030734(void *heap, u32 size, u32 flags, const void *file, u32 line);
extern const char g_020A776C[];

void *func_0202C384(void *heap)
{
    return func_02030734(heap, 0x3c, 0, g_020A776C, 0x12a);
}
