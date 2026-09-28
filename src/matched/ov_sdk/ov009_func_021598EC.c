/*
 * function: func_021598EC
 * address:  0x021598EC
 * packet:   pkt_ov009_021598EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      mark_rwin_chunk (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 */

struct rwin {
    unsigned long a;
    unsigned long b;
    unsigned long order;
};

struct soc {
    char pad[0x70];
    struct rwin rw[3];
};

void func_021598EC(struct soc *soc, long chunk)
{
    long ci;
    unsigned long order_max = 0;

    for (ci = 0; ci < 3 && soc->rw[ci].a != 0; ci++) {
        if (order_max < soc->rw[ci].order)
            order_max = soc->rw[ci].order;
    }
    soc->rw[chunk].order = order_max + 1;
}
