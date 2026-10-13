/*
 * function: EVENT_WIFIBATTLEMATCH_Entry
 * address:  0x02154438
 * packet:   pkt_ov002_02154438
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_WIFIBATTLEMATCH_Create  0x021543E8  thumb  ov002
 */

typedef int s32;

extern void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, int fieldMap, int entryMode, int ratedFlag, int matchKind);

/* Overlay entry point: unpacks the four-word request and creates the event. */
void EVENT_WIFIBATTLEMATCH_Entry(s32 gameSystem, s32 *request)
{
    EVENT_WIFIBATTLEMATCH_Create((void *)gameSystem, request[0], request[1], request[2], request[3]);
}
