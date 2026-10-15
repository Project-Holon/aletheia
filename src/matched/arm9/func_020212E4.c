/*
 * unit:     no
 * address:  0x020212E4
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_Check12E4
 *
 * symbols:
 *   g_0209EAA0  0x0209EAA0  data
 *
 * Linear search of the six-entry tail of the same halfword table
 * FILE_UTIL_Get_12B0 indexes, entries 0x5C..0x61.  The 0xB8 byte offset is kept out
 * of the `ldrh` encoding because it is past the halfword load's +62 reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md), so the address comes
 * out as base, plus the scaled index, plus a separate `adds r1, #0xb8`.
 *
 * The counter is a `u8`: the increment is `adds`/`lsls #0x18`/`lsrs #0x18`
 * through a scratch register, which a `u32` counter does not produce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Check12E4.c \
 *       --func FILE_UTIL_Check12E4 --addr 0x020212E4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209EAA0[];

u32 FILE_UTIL_Check12E4(u16 v)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209EAA0[0x5C + i]) {
            return 1;
        }
    }
    return 0;
}
