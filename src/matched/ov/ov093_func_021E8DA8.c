/*
 * function: BTLV_CORE_BytesEqual
 * address:  0x021E8DA8
 * packet:   pkt_ov093_021E8DA8
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
extern unsigned char BTLV_CORE_GetHighByte(int x);
extern int BTLV_CORE_GetLowByte(int x);

int BTLV_CORE_BytesEqual(int x)
{
    if (BTLV_CORE_GetHighByte(x) == BTLV_CORE_GetLowByte(x)) {
        return 1;
    }
    return 0;
}
