/*
 * function: ZUKAN_SAVE_SetSeenGenderFlag
 * address:  0x0200C818
 * packet:   pkt_0200C818
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set one bit in a byte array of a manager struct.  `sel` picks the pair of
 * tables, `half` which table of the pair, and the bit is entry `idx - 1`
 * (the parameter is 1-based).  Each of the six arms is an independent
 * read-modify-write of one byte.
 *
 * Shape notes:
 *  - `idx` is 32-bit in the ABI: every arm opens with a cast-to-u16 /
 *    subtract-one / cast-to-u16 quintet, which is `u16 i = (u16)idx - 1;`
 *    and only exists when the parameter is wider than u16.  Declaring the
 *    parameter `u16` loses the leading shift pair and reallocates the whole
 *    function (196 vs 250 bytes).
 *  - The index local is declared inside each arm, not hoisted above the
 *    `sel` tests.  Hoisting it keeps it in r1 and drops the callee-saved
 *    r5, which is where the original parks it -- each arm alone needs
 *    r0 (base), r1 (offset), r2 (pointer), r3/r4 (mask temps), so the
 *    index has to be r5, and that is what pulls in `push {r4, r5}`.
 *  - `|= (u8)(1 << (i & 7))` on a u8 lvalue is what emits the
 *    lsls/lsrs #0x18 pair around the mask.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZUKAN_SAVE_SetSeenGenderFlag.c \
 *       --func ZUKAN_SAVE_SetSeenGenderFlag --addr 0x0200C818 --cc 1.1p1 --thumb
 *   -> EXACT* (250 of 250 bytes; the listing extent runs two bytes long
 *      over the pool padding after the body)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void ZUKAN_SAVE_SetSeenGenderFlag(u8 *p, u32 idx, int sel, int half)
{
    if (sel == 0) {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x104))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x5C))[i >> 3] |= (u8)(1 << (i & 7));
        }
    } else if (sel == 1) {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x158))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0xB0))[i >> 3] |= (u8)(1 << (i & 7));
        }
    } else {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x104))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x5C))[i >> 3] |= (u8)(1 << (i & 7));
        }
    }
}
