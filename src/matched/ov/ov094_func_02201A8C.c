/*
 * function: func_02201A8C
 * address:  0x02201A8C
 * packet:   pkt_ov094_02201A8C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AE88  0x0220AE88  data  a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Res {
    void *owner;
    void *h;
    char pad[0x80 - 8];
    u16 heap;
} Res;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_0204B100(int, int, u16);
extern const char d_0220AE88[];

Res *func_02201A8C(void *owner, u16 heap)
{
    Res *r = func_02030734(heap, 0x84, 1, d_0220AE88, 0x4f);
    r->owner = owner;
    r->heap = heap;
    r->h = func_0204B100(7, 0, heap);
    return r;
}
