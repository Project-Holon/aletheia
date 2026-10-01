/*
 * function: func_02209214
 * address:  0x02209214
 * packet:   pkt_ov094_02209214
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct { char pad[0xd8]; int fd8; } W;
extern W **func_02030EE8(void *h);

void func_02209214(void *h)
{
    (*func_02030EE8(h))->fd8 = 0;
}
