/*
 * function: EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk
 * address:  0x02162A54
 * packet:   pkt_ov010_02162A54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to EVENTDATA_SYSTEM_SearchBgEventScriptId.  Callee of ov021 FIELD_EVENT_CHECK_CheckGridEvents.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_SearchBgEventScriptId  0x02162970  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct TriggerSet;
extern u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(struct TriggerSet *set, void *flags, const void *where, u16 type);

u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(void *set, void *flags, const void *where, u16 type)
{
    return EVENTDATA_SYSTEM_SearchBgEventScriptId(set, flags, where, type);
}
