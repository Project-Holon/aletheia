/*
 * function: EVENTDATA_SYSTEM_CreateFieldLinkEvent
 * address:  0x021644F4
 * packet:   pkt_ov010_021644F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatches through the eight-byte records at 0x02171504.
 *
 * symbols:
 *   FieldLinkEventTable     0x02171504  data
 */

typedef unsigned int u32;

typedef struct Entry {
    int (*fn)(void *p, void *a);
    u32 arg;
} Entry;

extern Entry FieldLinkEventTable[];

int EVENTDATA_SYSTEM_CreateFieldLinkEvent(int i, void *a, void *p)
{
    return FieldLinkEventTable[i].fn(p, a);
}
