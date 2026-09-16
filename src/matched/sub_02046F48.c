/*
 * function: func_02046F48
 * address:  0x02046F48
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The buffer accessor of the 0x48BF-tagged object whose destructor is
 * src/matched/unit_02046EFC.c: the pointer at +4, returned by value.  No
 * relocation, two instructions, no label of its own in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F48.c \
 *       --func func_02046F48 --addr 0x02046F48 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

void *func_02046F48(struct Tagged *p)
{
    return p->buf;
}
