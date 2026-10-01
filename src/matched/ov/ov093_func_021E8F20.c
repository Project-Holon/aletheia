/*
 * function: func_021E8F20
 * address: 0x021E8F20
 * packet: pkt_ov093_021E8F20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_021EAF7C 0x021EAF7C thumb ov093
 *   func_021E9024 0x021E9024 thumb ov093
 *   func_021EEC78 0x021EEC78 thumb ov093
 *   d_021F3AC4 0x021F3AC4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Scene {
    void *a, *b;
    u32 c;
    u8 index, pad0d[3];
    int state, f14, f18;
    u8 pad1c[0x90];
    void *buffer, *font0, *font2;
    u8 padb8[0xbc];
    u8 flag, pad175[3];
    void *ctx, *view, *other;
    u16 heap;
    u8 pad186[2];
};
extern const char d_021F3AC4[];
extern void *func_02030734(u16, int, int, const void *, u16);
extern u8 func_021D3D70(void *);
extern void *func_020457B0(int, u16);
extern void *func_0201D7EC(int, int, int, int, u16);
extern void *func_0203101C(u16, u16, int, int);
extern void *func_021EAF7C(struct Scene *, void *, u32, void *, void *, void *, u8, u16);
extern void *func_021E9024(struct Scene *, void *, u32, void *, void *, void *, int, u16);
extern void func_021EEC78(u32, u32, u32, u32);
struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap)
{
    struct Scene *p;
    p = func_02030734(heap, 0x188, 0, d_021F3AC4, 0x12d);
    p->a = a;
    p->b = b;
    p->c = c;
    p->index = func_021D3D70(b);
    p->state = 4;
    p->heap = heap;
    p->buffer = func_020457B0(0x200, heap);
    p->font0 = func_0201D7EC(0x17, 0, 0, 0, heap);
    p->font2 = func_0201D7EC(0x17, 2, 0, 0, heap);
    p->ctx = func_0203101C(heap, heap, 0x40, 0x80);
    p->view = func_021EAF7C(p, p->a, c, p->ctx, p->font0, p->font2, p->index, heap);
    p->other = func_021E9024(p, p->a, c, p->ctx, p->font0, p->b, d, heap);
    p->f14 = 0;
    p->f18 = 0;
    p->flag = 0;
    func_021EEC78((u32)a, p->index, c, heap);
    return p;
}
