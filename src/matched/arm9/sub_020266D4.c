/*
 * unit:     no
 * address:  0x020266D4
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020266D4
 *
 * symbols:
 *   sub_02026504  0x02026504  thumb
 *
 * The simplest of the three sub_02026504 wrappers: forwards its first
 * argument, repeats its second as both the second and third callee
 * argument, and appends the literal 0x1f. See
 * src/matched/sub_020266AC.c's header for why the three are kept as
 * separate files rather than one unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020266D4.c \
 *       --func sub_020266D4 --addr 0x020266D4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Obj;
extern void sub_02026504(struct Obj *o, u32 id0, u32 id1, u32 v);

void sub_020266D4(u32 a, u32 b)
{
    sub_02026504((struct Obj *)a, b, b, 0x1f);
}
