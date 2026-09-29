/*
 * function: func_021B7884
 * address:  0x021B7884
 * packet:   pkt_ov021_021B7884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021B9164  0x021B9164  thumb
 *   g_021DE2A0     0x021DE2A0  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Elem { u16 f0; u16 f2; char pad[0x78]; };
struct Obj {
    u16 f0;
    u16 f2;
    u16 f4;
    char pad06[2];
    struct Elem *f8;
    u32 fC;
    int f10;
    int f14;
    int f18;
    struct Elem *f1C;
    char f20[4];
};

extern const char g_021DE2A0[];
extern void *func_02030734();
extern void func_021B9164(struct Elem *e, void *p, struct Obj *o);

struct Obj *func_021B7884(u16 heap, u32 n, int a2)
{
    u32 i;
    struct Obj *o;

    o = func_02030734(heap, 0x74, 1, g_021DE2A0, 302);
    o->f0 = heap;
    o->f2 = 0;
    o->f4 = 1;
    o->f10 = a2;
    o->f14 = 0;
    o->f8 = func_02030734(heap, 0x7c * n, 1, g_021DE2A0, 311);
    o->fC = n;
    for (i = 0; i < n; i++)
        func_021B9164(&o->f8[i], o->f20, o);
    o->f1C = func_02030734(heap, 0x7c, 1, g_021DE2A0, 319);
    func_021B9164(o->f1C, o->f20, o);
    o->f1C->f2 = 1;
    return o;
}
