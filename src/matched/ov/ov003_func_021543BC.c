/*
 * function: EVENT_MENUPROC_Entry
 * address:  0x021543BC
 * packet:   pkt_ov003_021543BC
 * region:   ov003
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf callback (tail call through a pool word), sole blocker of
 * ov010 func_0215CCE8's MATCH.
 *
 * symbols:
 *   EVENT_MENUPROC_Create  0x0215437C  thumb  ov003
 */

typedef struct { unsigned a; unsigned b; } Arg;

extern void *EVENT_MENUPROC_Create(void *p, int a, int b);

void *EVENT_MENUPROC_Entry(void *h, Arg *arg)
{
    return EVENT_MENUPROC_Create(h, arg->a, arg->b);
}
