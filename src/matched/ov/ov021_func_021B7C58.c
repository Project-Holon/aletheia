/*
 * function: func_021B7C58
 * address:  0x021B7C58
 * packet:   pkt_ov021_021B7C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B7EE4  0x021B7EE4  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    u16 h4;
    u16 h6;
} Arg;

typedef struct {
    u8 pad[0x18];
    int x18;
    u8 pad1c[8];
    void *x24;
} Inner;

typedef struct {
    u8 pad[0x1C];
    Inner *x1c;
} Outer;

extern void func_021B7EE4(Inner *, Arg *);

void func_021B7C58(Outer *o, void *a1, u16 a2, u16 a3, u16 a4, Arg *out)
{
    Inner *t = o->x1c;

    t->x24 = a1;
    out->h0 = a2;
    out->b2 = 1;
    out->h4 = 0;
    out->h6 = a3;
    func_021B7EE4(t, out);
    out->h4 = a4 - t->x18 / 16;
    t->x24 = (u8 *)o + 0x20;
}
