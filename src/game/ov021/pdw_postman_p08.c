/*
 * file:     pdw_postman_p08.c
 * unit:     yes
 * function: func_021B7D50
 * address:  0x021B7D50
 * packet:   pkt_ov021_021B7D50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7EE4  0x021B7EE4  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x18];
    int x18;
} Inner;

typedef struct {
    u8 pad[0x1C];
    Inner *x1c;
} Outer;

extern void func_021B7EE4(Inner *, void *);

int func_021B7D50(Outer *o, void *out)
{
    func_021B7EE4(o->x1c, out);
    return o->x1c->x18 / 16;
}
