/*
 * function: func_02190490
 * address:  0x02190490
 * packet:   pkt_02190490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   func_0201C6EC  0x0201C6EC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);

void func_02190490(u8 *p)
{
    func_0201C6EC((struct PrintSys *)(*(u32 *)(p + 0xc)));
}
