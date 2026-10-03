/*
 * function: func_020082EC
 * address:  0x020082EC
 * packet:   pkt_020082EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_020A70A0      0x020A70A0  data
 */

extern char g_020A70A0[];
typedef unsigned short u16;
typedef unsigned int   u32;
struct Flags02008320;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02008320(struct Flags02008320 *p);

void *func_020082EC(int a0)
{
    void *p = func_02030734((unsigned short)a0, 4, 0, g_020A70A0, 0x4d);
    func_02008320(p);
    return p;
}
