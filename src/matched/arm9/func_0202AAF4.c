/*
 * function: func_0202AAF4
 * address:  0x0202AAF4
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * Allocates a 0x1c-byte node with the allocator entry point and runs the
 * two initialisers func_0202AB64 and func_0202AB7C over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AAF4.c \
 *       --func func_0202AAF4 --addr 0x0202AAF4 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

struct Node;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0202AB64(void *obj, u32 unused, u32 value);
extern void  func_0202AB7C(struct Node *p, u32 heapId);

struct Node *func_0202AAF4(u32 a, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x1c, 0,
                                                  (const void *)0x020A76E8, 0x92);

    func_0202AB64(p, heapId, a);
    func_0202AB7C(p, heapId);
    return p;
}
