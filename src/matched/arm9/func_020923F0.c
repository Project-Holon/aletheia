/*
 * function: memcmp
 * address:  0x020923F0
 * packet:   pkt_020923F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bounded unsigned byte compare: walks both operands up to n bytes and
 * returns -1, 1 or 0 for the first difference or for equality.  Two
 * spellings pin it:
 *
 *  - the loop is a `while (n != 0)` that decrements n as its last statement.
 *    `for (i = 0; i < n; i++)`, `while (n-- != 0)` (the post-decrement form,
 *    docs/idioms/a-post-decrement-in-the-loop-condition-splits-the-compare-from-the-subtract)
 *    and a manual pointer-pair walk all come out 38 to 56 bytes different;
 *    this one gives the original's single `subs r2, r2, #1` / `bne` back
 *    edge and the `cmp r2, #0` / `beq` entry guard.
 *  - the inequality arm re-reads the two bytes through `a[-1]` and `b[-1]`
 *    after the post-incremented loads, which is why the original reloads
 *    `ldrb r2, [r0, #-1]` / `ldrb r0, [r1, #-1]` instead of reusing the
 *    values it already has in ip and r3.
 *
 * This address carries a func_ label in the listing, is absent from
 * layout/worklist.json and is not an SDK symbol, so it is one of the
 * unlabelled-gap leaves inside this window; it is filed under a packet id of
 * its own so it lands in a shard no other lane writes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/memcmp.c \
 *       --func memcmp --addr 0x020923F0 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, no relocation sites.
 */

typedef unsigned char u8;

int memcmp(const u8 *a, const u8 *b, int n)
{
    while (n != 0) {
        if (*a++ != *b++)
            return (a[-1] < b[-1]) ? -1 : 1;
        n--;
    }
    return 0;
}
