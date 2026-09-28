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
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern void func_02008320(void *p);

void *func_020082EC(int a0)
{
    void *p = func_02030734((unsigned short)a0, 4, 0, g_020A70A0, 0x4d);
    func_02008320(p);
    return p;
}
