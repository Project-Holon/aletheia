/*
 * function: EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden
 * address:  0x02162A5C
 * packet:   pkt_ov010_02162A5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to EVENTDATA_SYSTEM_SearchBgEventScriptId.  Callee of ov021 FIELD_EVENT_CHECK_CheckRailEvents.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_SearchBgEventScriptId  0x02162970  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct TriggerSet;
extern u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(struct TriggerSet *set, void *flags, const void *where, u16 type);

u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(void *set, void *flags, const void *where, u16 type)
{
    return EVENTDATA_SYSTEM_SearchBgEventScriptId(set, flags, where, type);
}
