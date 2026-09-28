/*
 * function: sub_0200E6B4
 * address:  0x0200E6B4
 * packet:   pkt_0200E6B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02024344  0x02024344  thumb
 *   func_020242D8  0x020242D8  thumb
 *
 * Promoted from src/pending/sub_0200E6B4.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/sub_020242A4.c's func_02024344, and
 * src/matched/unit_020242D8.c's func_020242D8), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E6B4.c \
 *       --func sub_0200E6B4 --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02024344(void *obj);
extern void func_020242D8(void *slot, u32 idx);

void sub_0200E6B4(void *obj)
{
    func_02024344(obj);
    func_020242D8((u8 *)obj + 8, 0);
    func_020242D8((u8 *)obj + 0x10, 1);
    func_020242D8((u8 *)obj + 0x18, 2);
    obj = (u8 *)obj + 0x20;
    func_020242D8(obj, 3);
}
