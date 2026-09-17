/*
 * function: func_0202B610
 * address:  0x0202B610
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Builds the +0x10 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B610.c \
 *       --func func_0202B610 --addr 0x0202B610 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0202B7F8(struct Obj *o);
extern u32 func_0202AAF4(u32 a, u32 b);

void func_0202B610(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x10) = func_0202AAF4(func_0202B7F8(o), *(u16 *)o);
}
