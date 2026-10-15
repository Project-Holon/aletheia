/*
 * function: STA_NET_GetIndexedWord57
 * address:  0x021FD910
 * packet:   pkt_021FD910
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STA_NET_GetIndexedWord57   0x021FD910  thumb ov132
 *
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x57 of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionFinish.
 */

int STA_NET_GetIndexedWord57(int *p)
{
    return p[0x57];
}
