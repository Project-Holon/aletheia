/*
 * function: func_021B7D68
 * address:  0x021B7D68
 * packet:   pkt_ov021_021B7D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7EE4  0x021B7EE4  thumb
 *   func_021B8820  0x021B8820  thumb
 *   func_021B8870  0x021B8870  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };
struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };
typedef void (*Cb)(void *);
struct Obj { char pad00[0x14]; struct Sub *f14; char pad18[4]; struct Sub *f1C; };

extern void func_021B7EE4(struct Sub *s, void *r);
extern u32 *func_021B8820(void *p);
extern Cb func_021B8870(void *p, u32 v);

void func_021B7D68(struct Obj *o, void *r)
{
    Cb cb;
    struct Sub *keep;
    struct Sub *t;

    cb = 0;
    func_021B7EE4(o->f1C, r);
    keep = o->f14;
    t = o->f1C;
    o->f14 = t;
    switch (t->f0) {
    case 0:
        if (t->f4->f3C == 0xFFFF)
            break;
        goto lookup;
    case 1:
        if (t->f4->f10 == 0xFFFF)
            break;
lookup:
        cb = func_021B8870(t->f24, *func_021B8820(t->f24));
        break;
    }
    if (cb)
        cb(o);
    o->f14 = keep;
}
