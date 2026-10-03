/*
 * function: func_0202B8E4
 * address:  0x0202B8E4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears the object down: func_0202B9C8 first, then the matched heap release
 * func_020307B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B8E4.c \
 *       --func func_0202B8E4 --addr 0x0202B8E4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern void func_0202B9C8(struct Obj *o);
extern void func_020307B0(void *p);

void func_0202B8E4(struct Obj *o)
{
    func_0202B9C8(o);
    func_020307B0(o);
}
