/*
 * function: FIFORemove
 * address:  0x0219D544
 * packet:   pkt_ov009_0219D544
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the FIFO for the matching server, unlinks it from predecessor, head
 * and tail, decrements the count and reports 1; 0 when not present.
 *
 * sdk:      FIFORemove (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
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

int FIFORemove(struct _SBServerFIFO *fifo, struct _SBServer *server)
{
    struct _SBServer *hold = fifo->first;
    struct _SBServer *prev = 0;

    while (hold != 0)
    {
        if (hold == server)
        {
            if (prev != 0)
                prev->next = hold->next;
            if (fifo->first == hold)
                fifo->first = hold->next;
            if (fifo->last == hold)
                fifo->last = prev;
            fifo->count = fifo->count - 1;
            return 1;
        }
        prev = hold;
        hold = hold->next;
    }
    return 0;
}
