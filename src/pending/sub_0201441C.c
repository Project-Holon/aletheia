/*
 * function: sub_0201441C
 * address:  0x0201441C
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   sub_0201441C_Table  0x0209E050  data
 *
 * Every concrete byte reproduces; the one relocation (the table's
 * address) caps at MATCH.  The only pool word anywhere in the image that
 * names 0x0209E050 is this function's own, so the honesty rule in
 * docs/MATCHING.md refuses the witness.  Parked here per
 * src/pending/README.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201441C.c \
 *       --func sub_0201441C --addr 0x0201441C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 sub_0201441C_Table[];

u8 sub_0201441C(u32 id)
{
    return sub_0201441C_Table[id];
}
