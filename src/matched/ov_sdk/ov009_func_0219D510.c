/*
 * function: FIFOGetFirst
 * address:  0x0219D510
 * packet:   pkt_ov009_0219D510
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pops the head off the three-word FIFO and returns it, clearing the tail
 * when the FIFO becomes empty, then decrements the count.
 *
 * sdk:      FIFOGetFirst (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 */

struct _SBServer {
    char pad[0x24];
    struct _SBServer *next;
};

struct _SBServerFIFO {
    struct _SBServer *first;
    struct _SBServer *last;
    int count;
};

struct _SBServer *FIFOGetFirst(struct _SBServerFIFO *fifo)
{
    struct _SBServer *hold = fifo->first;

    if (hold != 0)
    {
        fifo->first = hold->next;
        if (fifo->first == 0)
            fifo->last = 0;
        fifo->count = fifo->count - 1;
    }
    return hold;
}
