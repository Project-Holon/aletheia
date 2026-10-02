/*
 * function: func_020173D0
 * address:  0x020173D0
 * packet:   pkt_020173D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_02146270      0x02146270  data
 */

typedef unsigned int u32;

extern void func_0201AD88(u32 heap);
extern unsigned char g_02146270[];
void func_020173D0(u32 heap)
{
    func_0201AD88(heap);
    *(unsigned short *)(g_02146270 + 2) = 0x28b;
}
