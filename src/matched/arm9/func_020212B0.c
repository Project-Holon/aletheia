/*
 * unit:     no
 * address:  0x020212B0
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_Get_12B0
 *
 * symbols:
 *   g_0209EAA0     0x0209EAA0  data
 *   FILE_UTIL_Check1288  0x02021288  thumb
 *
 * Halfword lookup keyed by one of the two id windows FILE_UTIL_Check1288 accepts:
 * 0x148..0x1A9 maps to entries 0..0x61 of the table at 0x0209EAA0 and
 * 0x26A..0x26C continues at 0x62..0x64, which is why the second window's
 * subtrahend is 0x208 rather than its own start.  Ids outside both windows
 * answer 0.
 *
 * The two subtrahends are one constant: the compiler keeps 0x26A in r0 for the
 * window test and derives 0x208 from it with `subs r0, #0x62` rather than
 * spending a second pool word.
 *
 * The id parameter is `u16` and the subtraction is written back into it, not
 * into a fresh local.  That is what puts the index in r4, the parameter's own
 * callee-saved home, and leaves r0 free for the table base: with a separate
 * `u16 i` local the narrowed index is a dead temporary, lands in r0, and the
 * last three instructions come out in the other order, five bytes wrong.  A
 * `u32` parameter with an explicit `(u16)` cast is the same five bytes wrong,
 * so the `u16` parameter type is real evidence and not a spelling choice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Get_12B0.c \
 *       --func FILE_UTIL_Get_12B0 --addr 0x020212B0 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209EAA0[];
extern u32 FILE_UTIL_Check1288(u32 id);

u16 FILE_UTIL_Get_12B0(u16 id)
{
    if (FILE_UTIL_Check1288(id) == 0) {
        return 0;
    }
    if (id >= 0x26A) {
        id -= 0x208;
    } else {
        id -= 0x148;
    }
    return g_0209EAA0[id];
}
