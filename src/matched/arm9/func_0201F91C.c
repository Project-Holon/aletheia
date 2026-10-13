/*
 * function: BMP_MENUWORK_CountItems
 * address:  0x0201F91C
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the occupied entries of the same eight-byte-stride table
 * BMP_MENUWORK_FindFreeEntry claims from, stopping at the 0xFFFFFFFF terminator.  An empty
 * table returns zero without entering the loop.
 *
 * Two shape facts.  The terminator constant is `subs r1, r3, #1` off the
 * counter while it still holds zero rather than a `movs`/`mvns` pair, and it
 * is rematerialised that way twice, once per block.  And the occupancy test
 * has to read the word as a pointer while the terminator tests read it as
 * u32, or the guard's load is forwarded into the loop body and two
 * instructions disappear; see
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_CountItems.c \
 *       --func BMP_MENUWORK_CountItems --addr 0x0201F91C --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

u32 BMP_MENUWORK_CountItems(struct Slot *s)
{
    u32 n;

    n = 0;
    if (s->u.raw != 0xFFFFFFFF) {
        do {
            if (s->u.ptr != 0)
                n++;
            s++;
        } while (s->u.raw != 0xFFFFFFFF);
    }
    return n;
}
