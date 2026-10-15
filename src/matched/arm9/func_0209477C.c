/*
 * function: strlen
 * address:  0x0209477C
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A plain byte-string length counter (strlen over a u8 buffer, not the C
 * library helper): count bytes up to and including the NUL, then return the
 * count minus one.  Self-contained, no external symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strlen.c \
 *       --func strlen --addr 0x0209477C --cc 1.1p1 --arm
 */

typedef unsigned char u8;

int strlen(const u8 *s)
{
    int n = -1;

    do {
        n++;
    } while (*s++ != 0);

    return n;
}
