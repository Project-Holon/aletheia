/*
 * function: EVENT_FIELD_PROCLINK_CompactReturnList
 * address:  0x02161E60
 * packet:   pkt_02161E60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CompactEntryList  0x021620B0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int EVENT_FIELD_PROCLINK_CompactEntryList();

int EVENT_FIELD_PROCLINK_CompactReturnList(int a0, int a1)
{

    if (a1 != 0) goto loc_02161E6E;
loc_02161E66:
a0 = a0 + 8;
    a0 = EVENT_FIELD_PROCLINK_CompactEntryList(a0);
loc_02161E6C:
    return a0;
loc_02161E6E:
a0 = a0 + 0xf8;
    a0 = EVENT_FIELD_PROCLINK_CompactEntryList(a0);
loc_02161E74:
    return a0;}
