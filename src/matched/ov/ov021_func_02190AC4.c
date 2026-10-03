/*
 * function: func_02190AC4
 * address:  0x02190AC4
 * packet:   pkt_ov021_02190AC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail call through a pool word), sole blocker of
 * ov010 func_0215A864's MATCH.
 *
 * symbols:
 *   func_0201F91C  0x0201F91C  thumb
 */

typedef unsigned int   u32;
struct Slot;
extern u32 func_0201F91C(struct Slot *s);

unsigned func_02190AC4(void *p)
{
    return func_0201F91C(p);
}
