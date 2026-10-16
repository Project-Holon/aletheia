/*
 * function: BEACON_DETAIL_HasEntry
 * address:  0x02185CF4
 * packet:   pkt_02185CF4
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_DETAIL_GetRecordIndex  0x02184790  thumb  ov219
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 BEACON_DETAIL_GetRecordIndex(u32 key);

int BEACON_DETAIL_HasEntry(int a)
{
    return BEACON_DETAIL_GetRecordIndex(a) != 0;
}
