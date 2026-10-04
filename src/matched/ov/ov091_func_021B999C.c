/*
 * function: func_021B999C
 * address:  0x021B999C
 * packet:   pkt_ov091_021B999C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B7B98  0x021B7B98  thumb  ov091
 */

typedef unsigned char u8;

extern void func_021B8F68(u8 *p, int v);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021B7B98(u8 *p);

#define W(o) (*(int *)(p + (o)))

void func_021B999C(u8 *p)
{
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x30) = 9;
    *(int *)(W(0x280) + 0x3c) = W(0x2c);
    func_021B7B98(p);
}
