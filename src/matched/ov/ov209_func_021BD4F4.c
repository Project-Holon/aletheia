/*
 * function: func_021BD4F4
 * address:  0x021BD4F4
 * packet:   pkt_ov209_021BD4F4
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045770 0x02045770 arm
 *   func_020437D4 0x020437D4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02049238 0x02049238 arm
 *   func_02082A90 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct Bmp;
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *h);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void func_020307B0(void *p);

void func_021BD4F4(u8 *p, u32 idx)
{
    void *o2;
    void *o1;
    void *t2;
    u8 *gfx;
    void *t1;
    u8 *dst;
    u16 j;
    u8 *row;
    int y;
    int h;
    u8 w;
    int x;
    u8 *map;
    struct Descriptor **ent = (struct Descriptor **)(p + 0x20);
    void *arc;
    u16 i;

    w = func_02045748(*(struct Descriptor **)((u8 *)ent + idx * 8));
    h = func_02045750(*(struct Descriptor **)((u8 *)ent + idx * 8));
    x = func_02045758(*(struct Descriptor **)((u8 *)ent + idx * 8));
    y = func_02045760(*(struct Descriptor **)((u8 *)ent + idx * 8));
    dst = func_020437D4(func_02045770(*(struct Descriptor **)((u8 *)ent + idx * 8)));
    arc = func_020490F4(0x9F, 0x6B);
    t1 = func_02049EF4(arc, 0x45, 0, &o1, 0x806B);
    map = (u8 *)o1 + 0xC;
    t2 = func_02049DF4(arc, 0x39, 0, (u32)(&o2), 0x806B);
    gfx = *(u8 **)((u8 *)o2 + 0x14);
    func_02049238(arc);
    if (h > 0) {
        row = map + x * 2;
        j = 0;
        do {
            for (i = 0; i < w; i++) {
                u16 c = *(u16 *)(row + (y + j) * 64 + i * 2);
                func_02082A90(gfx + (c & 0x3FF) * 32, dst + (i + j * w) * 32, 0x20);
            }
            j++;
        } while (j < h);
    }
    func_020307B0(t2);
    func_020307B0(t1);
}
