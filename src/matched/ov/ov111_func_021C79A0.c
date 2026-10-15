/*
 * function: VIEWER_ACTOR_DispatchState
 * address:  0x021C79A0
 * packet:   pkt_ov111_021C79A0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C8E58  0x021C8E58  data
 *
 * Addresses are Black-image addresses.
 */

typedef struct Work Work;
struct Work {
    unsigned char pad0[0x10C];
    int state;
};

extern int (*const d_021C8E58[])(Work *p);

int VIEWER_ACTOR_DispatchState(Work *p)
{
    return d_021C8E58[p->state](p);
}
