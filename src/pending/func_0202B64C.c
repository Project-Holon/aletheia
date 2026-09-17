/*
 * function: func_0202B64C
 * address:  0x0202B64C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Builds the +0x20 sub-object from the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B64C.c \
 *       --func func_0202B64C --addr 0x0202B64C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0202C070(u32 id);

void func_0202B64C(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x20) = func_0202C070(*(u16 *)o);
}
