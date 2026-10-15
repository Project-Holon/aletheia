/*
 * function: STA_NET_GetIndexedWord5E
 * address:  0x021FD844
 * packet:   pkt_021FD844
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STA_NET_GetIndexedWord5E   0x021FD844  thumb ov132
 *
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x5e of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionReady.
 */

int STA_NET_GetIndexedWord5E(int *p)
{
    return p[0x5e];
}
