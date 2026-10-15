/*
 * function: strchr
 * address:  0x02094A28
 * packet:   pkt_02094A28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strchr with a u8 needle: scan for the first byte equal to the (narrowed)
 * second argument, and on running into the terminator return the terminator's
 * own address when the needle was zero and NULL otherwise, which is why the
 * tail is `cmp r1, #0; movne r0, #0; subeq r0, r0, #1`.
 *
 * The narrowing is one `and r1, r1, #0xff` in the loop preheader, so the
 * needle is a wider parameter narrowed once into a `u8` local rather than a
 * `u8` parameter: with `u8 c` the AND disappears and the scan's registers
 * renumber (36 bytes), and with the cast applied at each comparison the AND
 * lands inside the loop (24 bytes).
 *
 * The final conditional is `m ? 0 : (u8 *)s - 1`, not `(m == 0) ? s - 1 : 0`:
 * both are correct, but only that operand order has mwcc evaluate the test
 * first and materialise `s - 1` under the predicate (`subeq r0, r0, #1`),
 * instead of computing `s - 1` eagerly and predicating the zero store.
 *
 * This address carries a func_ label in the listing, is absent from
 * layout/worklist.json and is not an SDK symbol, so it is one of the
 * unlabelled-gap leaves inside this window; it is filed under a packet id of
 * its own so it lands in a shard no other lane writes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strchr.c \
 *       --func strchr --addr 0x02094A28 --cc 1.1p1 --arm
 *   EXACT, 56 bytes, no relocation sites.
 */

typedef unsigned char u8;

u8 *strchr(const u8 *s, int c)
{
    u8 m = (u8)c;
    u8 ch;

    ch = *s++;
    while (ch != 0) {
        if (ch == m)
            return (u8 *)s - 1;
        ch = *s++;
    }
    return m ? 0 : (u8 *)s - 1;
}
