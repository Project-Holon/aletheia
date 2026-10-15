/*
 * function: WIFIBATTLEMATCH_NET_GdbShutdown
 * address:  0x021DB6A0
 * packet:   pkt_021DB6A0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_GdbShutdown  0x021E1340  arm
 *
 * Shuts the storage-server database client down (unlabelled; reached by bl from WIFIBATTLEMATCH_NET_GdbGetMyRecords).
 */

extern void DWC_GdbShutdown(void);

void WIFIBATTLEMATCH_NET_GdbShutdown(char *obj)
{
    DWC_GdbShutdown();
}
