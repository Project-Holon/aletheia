/*
 * unit:     no
 * address:  0x0203133C
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_0203133C
 *
 * symbols:
 *   sub_020314B8  0x020314B8  arm
 *
 * A four-instruction tail call to sub_020314B8
 * (src/matched/sub_020314B8.c, this same packet), attested by the
 * `matched` class: sub_020314B8's own EXACT entry pins its address, and
 * this call is the only branch to it found in the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203133C.c \
 *       --func sub_0203133C --addr 0x0203133C --cc 1.1p1
 */

struct S020314B8;

extern void sub_020314B8(struct S020314B8 *p);

void sub_0203133C(struct S020314B8 *p)
{
    sub_020314B8(p);
}
