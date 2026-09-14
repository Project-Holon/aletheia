/*
 * function: func_02025B3C
 * address:  0x02025B3C
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02025B3C_Table  0x0209FA34  data
 *
 * A linear search over a fixed 19-entry, 12-byte-stride table, matching
 * on the first byte of each record; returns the matching index, or 0
 * (not -1) when nothing matches, which is why the caller cannot
 * distinguish "matched slot 0" from "no match".
 *
 * The table pointer is a plain pool word to private data outside this
 * range; left as an untyped byte-stride index rather than a struct
 * pointer since nothing else in this file constrains its layout.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B3C.c \
 *       --func func_02025B3C --addr 0x02025B3C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 sub_02025B3C_Table[];

u32 func_02025B3C(u32 key)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (key == sub_02025B3C_Table[i * 0xc]) {
            return i;
        }
    }
    return 0;
}
