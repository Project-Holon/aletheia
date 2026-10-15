/*
 * unit:     no
 * address:  0x02021288
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_Check1288
 *
 * The membership test for the two id windows this file's tables are indexed
 * by: 0x148..0x1A9 and 0x26A..0x26C.  Written as one disjunction so that both
 * true arms share the single `movs r0, #1` exit and both false arms the single
 * `movs r0, #0` (docs/idioms/disjunction-must-be-one-expression-to-share-its-
 * exit.md); as two separate `if` statements each window grows its own return.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Check1288.c \
 *       --func FILE_UTIL_Check1288 --addr 0x02021288 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

u32 FILE_UTIL_Check1288(u32 id)
{
    if ((id >= 0x148 && id <= 0x1A9) || (id >= 0x26A && id <= 0x26C)) {
        return 1;
    }
    return 0;
}
