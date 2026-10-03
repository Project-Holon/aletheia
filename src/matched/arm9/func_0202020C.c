/*
 * function: func_0202020C
 * address:  0x0202020C
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void func_02020D3C(u32 v);
extern void func_020307B0(void *p);

void func_0202020C(struct Obj *o, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = *(u16 *)((u8 *)o + 0x40);
    }
    if (b != 0) {
        *b = *(u16 *)((u8 *)o + 0x42);
    }
    func_02020D3C(*(u32 *)((u8 *)o + 0x3c));
    func_020307B0(o);
}
