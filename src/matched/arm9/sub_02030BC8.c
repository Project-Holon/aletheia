/*
 * unit:     no
 * address:  0x02030BC8
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030BC8
 *
 * symbols:
 *   sub_020305E4  0x020305E4  arm
 *
 * A four-instruction tail call to sub_020305E4 (src/matched/sub_020305E4.c,
 * pkt_02030534), attested by the `matched` class: sub_020305E4's own EXACT
 * entry pins its address, and this call is the only branch to it found in
 * the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BC8.c \
 *       --func sub_02030BC8 --addr 0x02030BC8 --cc 1.1p1
 */

typedef unsigned int u32;

extern int sub_020305E4(u32 idx);

int sub_02030BC8(u32 idx)
{
    return sub_020305E4(idx);
}
