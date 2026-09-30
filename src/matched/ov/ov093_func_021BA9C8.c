/*
 * function: func_021BA9C8
 * address: 0x021BA9C8
 * packet: pkt_ov093_021BA9C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_020457B0 0x020457B0 arm
 *   func_021D787C 0x021D787C thumb ov093
 *   func_021BB828 0x021BB828 thumb ov093
 *   func_021BB968 0x021BB968 thumb ov093
 *   func_021BC550 0x021BC550 thumb ov093
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BAC04 0x021BAC04 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Copy24 { int x[6]; };
extern u8 d_021F3A60[];
extern u8 *func_02030734(u16, int, int, const void *, u16);
extern int func_020457B0(int, int);
extern void func_021D787C(void *);
extern void func_021BB828(void *);
extern u8 *func_021BB968(u8 *, void *, void *, void *, int, u16);
extern void *func_021BC550(u8 *);
extern void func_021BABEC(void *, void *);
extern void func_021BAC04(void);

u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap)
{
    u8 *p;
    int i;
    p = func_02030734(heap, 0xcc4, 1, d_021F3A60, 0xad);
    *(void **)(p + 0xc) = a;
    *(void **)(p + 0x10) = c;
    *(u16 *)(p + 0xcc0) = heap;
    *(void **)(p + 0xcb0) = p + 0xf0;
    p[0xed] = 0;
    *(int *)(p + 0x44) = 0;
    p[0xcba] = 0;
    p[0xcbf] = 0;
    *(int *)(p + 0x4c) = d;
    *(struct Copy24 *)(p + 0x50) = *b;
    *(int *)(p + 0xac) = func_020457B0(0x20, heap);
    func_021D787C(b);
    for (i = 0; i < 4; i++)
        func_021BB828(p + 0x14 + i * 12);
    *(u8 **)(p + 0x44) = func_021BB968(p, *(void **)(p + 0xc), *(void **)(p + 0x10), p + 0xf0, *(int *)(p + 0x4c), *(u16 *)(p + 0xcc0));
    *(void **)(p + 0xb0) = func_021BC550(*(u8 **)(p + 0x44));
    func_021BABEC(p, (void *)func_021BAC04);
    return p;
}
