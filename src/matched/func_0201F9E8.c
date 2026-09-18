/*
 * function: func_0201F9E8
 * address:  0x0201F9E8
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj;

extern void func_02020D3C(u32 v);
extern void func_020307B0(struct Obj *o);

void func_0201F9E8(struct Obj *o, u8 *out)
{
    if (out != 0) {
        *out = *(u8 *)((u8 *)o + 0x2d);
    }
    func_02020D3C(*(u32 *)((u8 *)o + 0x24));
    func_020307B0(o);
}
