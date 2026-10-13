/*
 * function: BTL_SERVER_FLOW_GetHandExScopeArg
 * address:  0x021CC960
 * packet:   pkt_021CC960
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct S {
    unsigned int x : 10;
};

unsigned short BTL_SERVER_FLOW_GetHandExScopeArg(struct S *p)
{
    return p->x;
}
