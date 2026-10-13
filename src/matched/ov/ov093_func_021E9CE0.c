/*
 * function: BTLV_CORE_StartMoveHighlight
 * address:  0x021E9CE0
 * packet:   pkt_ov093_021E9CE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_InitPartyWork  0x021E9984  thumb  ov093
 */
typedef unsigned char u8;

extern void BTLV_CORE_InitPartyWork(u8 *p, u8 *q, int mode, u8 x, int y);

void BTLV_CORE_StartMoveHighlight(u8 *p, u8 a, u8 b)
{
    BTLV_CORE_InitPartyWork(p, p + 0x10c, 5, a, 0);
    p[0x157] = b;
    p[0x174] = 0;
}
