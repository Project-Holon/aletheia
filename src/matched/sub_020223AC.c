/*
 * function: func_020223AC
 * address:  0x020223AC
 * packet:   pkt_02022390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_0209F538  0x0209F538  data
 */

typedef unsigned int u32;
typedef u32 (*FuncPtr)(void *);

extern FuncPtr g_0209F538[];

u32 func_020223AC(void *p)
{
    u32 idx = *(u32 *)p;
    return g_0209F538[idx](p);
}
