/*
 * function: func_02206710
 * address:  0x02206710
 * packet:   pkt_ov094_02206710
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct { char pad[0x68]; unsigned int f68; } W;
extern W **func_02030EE8(void *h);

void func_02206710(void *h)
{
    (*func_02030EE8(h))->f68 &= 0x7fffffff;
}
