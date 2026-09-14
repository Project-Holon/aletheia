/*
 * function: sub_0200E6B4
 * address:  0x0200E6B4
 * packet:   pkt_0200E6B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02024344  0x02024344  thumb
 *   func_020242D8  0x020242D8  thumb
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte slots
 * starting at obj+8, tagging each with its index 0..3.
 *
 * Every concrete byte matches; the two callees are only ever called from
 * this one function in the whole ROM, so both are unresolved relocations
 * under the honesty rule (the only witness is the call itself). See
 * "the limit of the remedy" in docs/MATCHING.md. Closes to EXACT the day
 * either callee gets a second caller elsewhere in the image.
 *
 * The `matched` class does not reach it: neither func_02024344 nor
 * func_020242D8 is matched, so no EXACT entry covers either address.  It closes
 * when one of the two is matched, or when the image acquires a second caller.
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
