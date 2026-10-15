/*
 * function: WIFIBATTLEMATCH_NET_Noop
 * address:  0x021D9ED0
 * packet:   pkt_021D9ED0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Empty stub sitting between the WIFIBATTLEMATCH_NET_DeleteNetContext teardown and
 *     WIFIBATTLEMATCH_NET_SetTimingSyncRange; nothing calls into it, disasm.py labelled it from its
 *     alignment padding.
 */

void WIFIBATTLEMATCH_NET_Noop(int a0)
{
}

