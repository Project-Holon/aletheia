/*
 * function: BTL_CALC_ActionGetKind
 * address:  0x021D8454
 * packet:   pkt_ov093_021D8454
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct
{
    unsigned int x : 4;
} S021D8454;

unsigned int BTL_CALC_ActionGetKind(S021D8454 *p)
{
    return p->x;
}
