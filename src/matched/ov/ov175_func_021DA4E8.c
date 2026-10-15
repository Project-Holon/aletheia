/*
 * function: WIFIBATTLEMATCH_NET_GetMatchKeyInt
 * address:  0x021DA4E8
 * packet:   pkt_021DA4E8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_GetMatchKeyValue  0x021DA4F8  thumb
 *
 * Matchmaking evaluation callback that forwards to the key-distance scorer WIFIBATTLEMATCH_NET_GetMatchKeyValue (unlabelled; its address is a code pointer in WIFIBATTLEMATCH_NET_SetMatchKey's pool).
 */

extern int WIFIBATTLEMATCH_NET_GetMatchKeyValue(int index, void *param);

int WIFIBATTLEMATCH_NET_GetMatchKeyInt(int index, void *param)
{
    return WIFIBATTLEMATCH_NET_GetMatchKeyValue(index, param);
}
