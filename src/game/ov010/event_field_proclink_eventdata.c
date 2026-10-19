/*
 * file:     event_field_proclink_eventdata.c
 * function: EVENT_FIELD_PROCLINK_HasEventdataEntry
 * address:  0x02161E4C
 * packet:   pkt_02161E4C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetEventdataEntry  0x02161DC4  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/EVENT_FIELD_PROCLINK_HasEventdataEntry.c \
 *       --func EVENT_FIELD_PROCLINK_HasEventdataEntry --addr 0x02161E4C --region ov010 --cc dsi/1.1p1 --thumb
 */

#include "../types.h"
struct ProcLinkReturnList;
struct ProcLinkEntry;

extern struct ProcLinkEntry *EVENT_FIELD_PROCLINK_GetEventdataEntry(struct ProcLinkReturnList *list, int id, unsigned int mode);

/*
 * Returns 1 when the entry with this id exists in the selected list(s) of
 * the table (listSelect 0: first list, 1: second list, 2: both).
 */
int EVENT_FIELD_PROCLINK_HasEventdataEntry(void *entryTable, int entryId, unsigned listSelect)
{
    if (EVENT_FIELD_PROCLINK_GetEventdataEntry(entryTable, entryId, listSelect))
        return 1;
    return 0;
}
