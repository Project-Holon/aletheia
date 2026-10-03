/*
 * function: func_0202C2EC
 * address:  0x0202C2EC
 * packet:   pkt_0202C2EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed: func_0202C384 became an EXACT manifest entry, so the matched class attests the call at 0x0202C2F0.
 */

typedef unsigned int u32;

extern u32  func_0202C384(void *heap);
struct Obj0202C360;
extern void func_0202C360(struct Obj0202C360 *p);
extern void func_0202C3A8(char *p, int a1);

u32 func_0202C2EC(void *heap)
{
    u32 r = func_0202C384(heap);

    func_0202C360((void *)r);
    func_0202C3A8((char *)r, (int)heap);
    return r;
}
