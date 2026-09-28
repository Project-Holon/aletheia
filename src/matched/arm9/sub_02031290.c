/*
 * unit:     no
 * address:  0x02031290
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02031290
 *
 * symbols:
 *   sub_02030FB4  0x02030FB4  arm
 *
 * A four-instruction tail call to sub_02030FB4 (src/matched/sub_02030FB4.c,
 * this same packet), one section back. The mwccarm one-section-per-function
 * rule means even a same-file neighbour is reached through a pool word and
 * `bx`; see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031290.c \
 *       --func sub_02031290 --addr 0x02031290 --cc 1.1p1
 */

struct S02030FB4 {
    char  pad[0x10];
    void *field10;
    char  pad2[4];
    char  embedded[1];
};

extern void *sub_02030FB4(struct S02030FB4 *p);

void *sub_02031290(struct S02030FB4 *p)
{
    return sub_02030FB4(p);
}
