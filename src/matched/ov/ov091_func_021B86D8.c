/*
 * function: func_021B86D8
 * address:  0x021B86D8
 * packet:   pkt_ov091_021B86D8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021B9968  0x021B9968  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B7B98  0x021B7B98  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BB7A4(void *p, u32 *s);
extern void func_021B9968(u8 *p);
extern void func_021B8F68(u8 *p, int v);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021B7B98(u8 *p);
extern void func_020061E4(u32 id);

#define W(o) (*(int *)(p + (o)))

void func_021B86D8(u8 *p)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3 && W(0x2c) == W(0x30)) {
        p[0xf] = 1;
    }
    if (p[0xf] != 1) {
        if (p[0xf] == 3) {
            func_021B9968(p);
        }
    } else {
        W(0x38) = 0;
        p[0xc] = 2;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        W(0x30) = 9;
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_021B7B98(p);
        func_020061E4(0x551);
    }
}
