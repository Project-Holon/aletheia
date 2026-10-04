/*
 * function: func_0202B5FC
 * address:  0x0202B5FC
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * Builds the +0x14 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B5FC.c \
 *       --func func_0202B5FC --addr 0x0202B5FC --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void *func_0202B7F8(struct Obj *o);
extern u32 func_0202B1AC(u32 a, u32 b);

void func_0202B5FC(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x14) = func_0202B1AC((u32)func_0202B7F8(o), *(u16 *)o);
}
