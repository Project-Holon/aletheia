/*
 * function: func_021B8328
 * address:  0x021B8328
 * packet:   pkt_ov021_021B8328
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B91F8  0x021B91F8  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0xC];
    void *xc;
} Obj;

extern void func_021B91F8(Obj *, void *);

void func_021B8328(Obj *o, void *a, void *b)
{
    void *save = o->xc;

    o->xc = a;
    func_021B91F8(o, b);
    o->xc = save;
}
