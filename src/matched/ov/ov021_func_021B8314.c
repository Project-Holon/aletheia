/*
 * function: func_021B8314
 * address:  0x021B8314
 * packet:   pkt_ov021_021B8314
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
    u8 pad[0x14];
    void *x14;
} Obj;

extern void func_021B91F8(Obj *, void *);

void func_021B8314(Obj *o, void *x)
{
    void *save = o->x14;

    o->x14 = 0;
    func_021B91F8(o, x);
    o->x14 = save;
}
