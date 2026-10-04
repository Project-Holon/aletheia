/*
 * function: func_021B46FC
 * address:  0x021B46FC
 * packet:   pkt_ov021_021B46FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202020C  0x0202020C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);

void func_021B46FC(u8 *w)
{
    u16 a;
    u16 b;

    func_0202020C((struct Obj *)(*(u32 *)(w + 0x1A4)), &a, &b);
}
