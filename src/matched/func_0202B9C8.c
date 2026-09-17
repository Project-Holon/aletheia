/*
 * function: func_0202B9C8
 * address:  0x0202B9C8
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0x264 field through the matched heap release func_020307B0,
 * then tears the object down through func_0202B944.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B9C8.c \
 *       --func func_0202B9C8 --addr 0x0202B9C8 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern void func_020307B0(u32 p);
extern void func_0202B944(struct Obj *o);

void func_0202B9C8(struct Obj *o)
{
    func_020307B0(*(u32 *)((u8 *)o + 0x264));
    func_0202B944(o);
}
