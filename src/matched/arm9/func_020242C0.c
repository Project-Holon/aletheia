/*
 * function: func_020242C0
 * address:  0x020242C0
 * packet:   pkt_020242C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020242A4  0x020242A4  thumb
 *   func_02024598  0x02024598  thumb
 */

typedef unsigned int   u32;
extern void func_020242A4(void *obj, u32 id);
extern void func_02024598(void *a, void *b, void *c);

void func_020242C0(void *a, void *b, void *c)
{
    func_020242A4(a, (u32)b);
    func_02024598(a, b, c);
}
