/*
 * function: func_0202B818
 * address:  0x0202B818
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the +4 field, and passes it and the low half of func_0202B810()'s
 * result to func_02006E7C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B818.c \
 *       --func func_0202B818 --addr 0x0202B818 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0201295C(u32 v);
extern u32 func_0202B810(void);
extern void func_02006E7C(u32 a, u32 b);

void func_0202B818(struct Obj *o)
{
    u32 r = func_0201295C(*(u32 *)((u8 *)o + 0x4));

    func_02006E7C(r, (u16)func_0202B810());
}
