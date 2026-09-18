/*
 * function: func_0202B624
 * address:  0x0202B624
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Builds the +0x18 sub-object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B624.c \
 *       --func func_0202B624 --addr 0x0202B624 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0202B7F8(struct Obj *o);
extern u32 func_0202B3A0(u32 a, u32 b, u32 c);

void func_0202B624(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x18) = func_0202B3A0(*(u32 *)((u8 *)o + 0x4),
                                             func_0202B7F8(o), *(u16 *)o);
}
