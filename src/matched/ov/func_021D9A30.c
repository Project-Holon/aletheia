/*
 * function: func_021D9A30
 * address:  0x021D9A30
 * packet:   pkt_021D9A30
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8A80  0x021E8A80  thumb  ov177
 *   func_021E8A90  0x021E8A90  thumb  ov177
 *
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors func_021D679C.
 */

typedef unsigned long u32;

extern void func_021E8A80(u32 h);
extern int func_021E8A90(u32 h);

u32 func_021D9A30(char *obj)
{
    func_021E8A80(*(u32 *)(obj + 0x3c));
    if (func_021E8A90(*(u32 *)(obj + 0x3c)) != 0)
        return *(u32 *)(obj + 0x40);
    return 0xFFFF;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * Identical blocker to func_021D679C: the call at +0x0C targets 0x021E8A90,
 * which is not a traced function label in any overlay listing.
 */
