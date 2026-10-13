/*
 * function: BTL_MAIN_GetPositionsPerClientThunk
 * address:  0x021B99B8
 * packet:   pkt_021B99B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetPositionsPerClient  0x021B6994  thumb  ov093
 */

typedef unsigned int   u32;
struct S;
int BTL_MAIN_GetPositionsPerClient(struct S **pp, u32 b);

int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b)
{
    return BTL_MAIN_GetPositionsPerClient(pp, b);
}
