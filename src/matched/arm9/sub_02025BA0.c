/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by
 * the C.
 *
 * unit:     yes
 * function: func_02025BA0
 * address:  0x02025BA0
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02025BA0_Table  0x0209FA36  data
 *
 * Parked at MATCH by the evidence rather than by the C: every concrete
 * byte is reproduced (confirmed against the exact shape below), but the
 * one relocation, the table pointer, has no witness outside this
 * function's own range. The only other occurrence of the word
 * 0x0209FA36 in the image is at 0x02025BB4, inside the unlabelled filler
 * that immediately follows this function and that this compile's own
 * trailing bytes overlap, so the honesty rule discards it. The table is
 * two bytes into the same record array func_02025B3C searches
 * (src/matched/sub_02025B3C.c, whose own table symbol at 0x0209FA34 does
 * have outside witnesses), but declaring this address as an offset off
 * that symbol changes the code shape mwccarm emits for the pointer
 * arithmetic and no longer reproduces the bytes, so the two are kept as
 * separate declarations. BMP_OAM_Get (src/matched/sub_02025B94.c)
 * calls this function and reaches EXACT anyway, because the `label`
 * class attests the call itself from a second caller in ov186 at
 * 0x02185CC6, independently of this file's own status.
 *
 * Bounds-checked lookup into a 19-entry (0x13) table of u16, 12-byte
 * stride, at offset +2 into the record func_02025B3C indexes. Out of
 * range returns the sentinel 0xE7.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02025BA0.c \
 *       --func func_02025BA0 --addr 0x02025BA0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 sub_02025BA0_Table[];

u32 func_02025BA0(u32 idx)
{
    if (idx < 0x13) {
        return *(const u16 *)(sub_02025BA0_Table + idx * 0xc);
    }
    return 0xE7;
}
