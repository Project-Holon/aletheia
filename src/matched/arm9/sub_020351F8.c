/*
 * function: sub_020351F8
 * address:  0x020351F8
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Forwards both arguments to the setter sub_020351EC on the object held in
 * g_021469BC (a tail call through ip).  No lr push, so disasm.py never
 * labels it; filed so its ov088/ov172 callers can resolve the BLX.
 *
 * symbols:
 *   g_021469BC    0x021469BC  data  a4
 *   sub_020351EC  0x020351EC  arm
 */

typedef unsigned int u32;

extern void *g_021469BC;
struct Obj020351EC;
extern void sub_020351EC(struct Obj020351EC *p, u32 a, u32 b);

void sub_020351F8(u32 a, u32 b)
{
    sub_020351EC(g_021469BC, a, b);
}
