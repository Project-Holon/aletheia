/*
 * function: func_021C533C
 * address:  0x021C533C
 * packet:   pkt_021C533C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Calls 0x0204AFD8 on +0x138, 0x0204ADA4 on +0x134 and 0x02049238 on +0x128 of the second argument.
 */

extern void func_0204AFD8(int);
extern void func_0204ADA4(int);
extern void func_02049238(int);

void func_021C533C(void *a, char *q)
{
    func_0204AFD8(*(int *)(q + 0x138));
    func_0204ADA4(*(int *)(q + 0x134));
    func_02049238(*(int *)(q + 0x128));
}
