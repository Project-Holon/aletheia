/*
 * function: func_021BB968
 * address: 0x021BB968
 * packet: pkt_ov093_021BB968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201B70C 0x0201B70C thumb
 *   func_021BB9D8 0x021BB9D8 thumb ov093
 *   d_021F3A70 0x021F3A70 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F3A70[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0201B70C(u16 heap);
extern void func_021BB9D8(u8 *p);

u8 *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap)
{
    u8 *p;
    p = func_02030734(heap, 0x212c, 1, (const char *)d_021F3A70, 0x245);
    *(void **)(p + 0) = a;
    *(void **)(p + 8) = c;
    *(void **)(p + 4) = b;
    p[0x782] = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(void **)(p + 0xc) = d;
    *(u16 *)(p + 0x780) = heap;
    *(int *)(p + 0x18) = e;
    *(void **)(p + 0x4a4) = func_0201B70C(heap);
    func_021BB9D8(p);
    return p;
}
