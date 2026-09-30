/*
 * function: func_020589C4
 * address:  0x020589C4
 * packet:   pkt_020589C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A94  0x02146A94  data
 *
 * Getter for the Wi-Fi backup block (DWCi_BACKUPlGetWifi): returns the address of
 * a global.  Called twice from the ov016 scene-end function 0x021CD458.
 */

extern char g_02146A94[];

void *func_020589C4(void)
{
    return g_02146A94;
}
