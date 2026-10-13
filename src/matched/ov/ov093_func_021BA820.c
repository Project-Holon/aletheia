/*
 * function: BTL_MAIN_GetServerFlow
 * address:  0x021BA820
 * packet:   pkt_021BA820
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetFlow  0x021BB964  thumb  ov093
 */

typedef unsigned int   u32;
struct Q5;
u32 BTL_SERVER_GetFlow(struct Q5 *p);

u32 BTL_MAIN_GetServerFlow(int *p)
{
    return BTL_SERVER_GetFlow((struct Q5 *)p[2]);
}
