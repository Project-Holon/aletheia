/*
 * function: WORLDTRADE_INPUT_GetListRangeCount
 * address:  0x021FC008
 * packet:   pkt_021FC008
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_DEPOSIT_GetListRange  0x021F88D8  thumb  ov135

 *
 * Hand the second argument to WORLDTRADE_DEPOSIT_GetListRange with a scratch word.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WORLDTRADE_DEPOSIT_GetListRange(u32 id, u32 *start);

int WORLDTRADE_INPUT_GetListRangeCount(void *p, u32 a)
{
    u32 tmp;

    return WORLDTRADE_DEPOSIT_GetListRange(a, &tmp);
}
