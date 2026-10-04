/*
 * function: func_021F68BC
 * address: 0x021F68BC
 * packet: pkt_ov112_021F68BC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0200C52C 0x0200C52C thumb
 *   func_0200C6D8 0x0200C6D8 thumb
 *   func_0200C6DC 0x0200C6DC thumb
 *   func_0200C5A4 0x0200C5A4 thumb
 *   func_0204913C 0x0204913C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A39C 0x0204A39C arm
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02049238 0x02049238 arm
 *   d_021F83E4 0x021F83E4 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021F83E4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0200C52C(void *sys, u32 heap);
extern void *func_0200C6D8(void *a);
extern u32 func_0200C6DC(void *x);
extern void *func_0204913C(void *a0, u32 a1, u32 heap);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_0204A39C(void *arc, u32 member, u32 z, u32 heap, void *out);
extern u32 func_020493D4(void *arc, u32 member);
extern void func_0204932C(void *arc, u32 member, void *dst);
extern void func_02049238(void *arc);
extern void func_0200C5A4(void *p);
void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = func_0200C52C(sys, heap);
        arc = func_0204913C(func_0200C6D8(x), func_0200C6DC(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = func_020490F4(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = func_0204A39C(arc, 0, 0, heap, p + 0x20);
    *(void **)(p + 8) = func_0204A39C(arc, 1, 0, heap, p + 0x24);
    *(void **)(p + 0xc) = func_0204A39C(arc, 2, 0, heap, p + 0x28);
    c = func_020493D4(arc, 4);
    d = func_020493D4(arc, 3);
    e = func_020493D4(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = func_02030734(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    func_0204932C(arc, 4, *(void **)(p + 0x14));
    func_0204932C(arc, 3, *(void **)(p + 0x18));
    func_0204932C(arc, 5, *(void **)(p + 0x1c));
    func_02049238(arc);
    if (kind >= 4) func_0200C5A4(x);
}
