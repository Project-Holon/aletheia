/*
 * function: FIELD_EVENT_CHECK_IsConnectExitDir
 * address:  0x0218AECC
 * packet:   pkt_0218AECC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   EVENTDATA_SYSTEM_IsConnectExitDir  0x021626B8  thumb  ov010
 *
 * Unblocked by matching EVENTDATA_SYSTEM_IsConnectExitDir (ov010, EXACT): the +0004 ABS32 site now
 * attests as `matched`.
 */

int EVENTDATA_SYSTEM_IsConnectExitDir(char *a0, int a1);

int FIELD_EVENT_CHECK_IsConnectExitDir(char *a0, int a1)
{
    return EVENTDATA_SYSTEM_IsConnectExitDir(a0, a1);
}
