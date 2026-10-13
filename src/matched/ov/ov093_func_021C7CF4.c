/*
 * function: BTL_SERVER_FLOW_GetPokeParam
 * address:  0x021C7CF4
 * packet:   pkt_021C7CF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *
 * Forwarding tail call: p[2] and the caller's i go to BTL_SIDE_GetPokeByIdThunk, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */

typedef unsigned char u8;

u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);

void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i)
{
    return BTL_SIDE_GetPokeByIdThunk((char *)p[2], i);
}
