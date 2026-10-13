/*
 * function: BTLV_CORE_BytesOverlap
 * address:  0x021E8D48
 * packet:   pkt_ov093_021E8D48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetHighByte  0x021E8CFC  thumb  ov093
 *   BTLV_CORE_GetLowByte  0x021E8D04  thumb  ov093
 */
typedef unsigned char u8;
extern u8 BTLV_CORE_GetHighByte(int v);
extern int BTLV_CORE_GetLowByte(int x);

int BTLV_CORE_BytesOverlap(int a, int b)
{
    if (BTLV_CORE_GetHighByte(a) == BTLV_CORE_GetHighByte(b)) return 1;
    if (BTLV_CORE_GetHighByte(a) == BTLV_CORE_GetLowByte(b)) return 1;
    if (BTLV_CORE_GetLowByte(a) == BTLV_CORE_GetHighByte(b)) return 1;
    if (BTLV_CORE_GetLowByte(a) == BTLV_CORE_GetLowByte(b)) return 1;
    return 0;
}
