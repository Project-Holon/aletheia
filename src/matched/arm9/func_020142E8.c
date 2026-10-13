/*
 * unit:     no
 * function: func_020142E8
 * address:  0x020142E8
 * packet:   pkt_020142E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZONEDATA_GetEventFlagAddress  0x02014388  thumb
 *
 * Test one flag in a bitmap: the lookup at 0x02014388 resolves the flag id
 * to the byte that holds it, and this function picks the bit out of that
 * byte.  A null byte pointer reads as "clear" rather than asserting.
 *
 * The bit number is `id % 8` on a *signed* id, not `id & 7`.  That is the
 * whole reason for the `lsrs #31 / lsls #29 / subs / rors #29 / adds`
 * quintet: an unsigned id folds to a single `movs r1, #7 / ands`, and a
 * plain mask loses four instructions.  The two forms differ only for
 * negative ids, where the shift count would be negative, so the source is
 * relying on the caller never passing one.
 *
 * The null check and the bit test share one `return 0`, so they are nested
 * ifs, not an early return followed by a second one: written as
 * `if (byte == 0) return 0;` the compiler gives the null arm its own
 * `movs r0, #0 / pop` and the function grows two bytes
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * EXACT*: the extent runs to 44 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020142E8.c \
 *       --func func_020142E8 --addr 0x020142E8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

extern u8 *ZONEDATA_GetEventFlagAddress(void *bitmap, s32 id);

u32 func_020142E8(void *bitmap, s32 id)
{
    u8 *byte = ZONEDATA_GetEventFlagAddress(bitmap, id);

    if (byte != 0) {
        if ((*byte & (1 << (id % 8))) != 0) {
            return 1;
        }
    }
    return 0;
}
