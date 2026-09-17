/*
 * function: func_0202B65C
 * address:  0x0202B65C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Builds the +0x24 sub-object from the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B65C.c \
 *       --func func_0202B65C --addr 0x0202B65C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0202B894(u32 id);

void func_0202B65C(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x24) = func_0202B894(*(u16 *)o);
}
