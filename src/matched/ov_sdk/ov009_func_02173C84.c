/*
 * function: DWCi_GetAIDFromProfileID
 * address:  0x02173C84
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +0x16 of the block, or 0xff when there is none.
 *
 * symbols:
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 */

extern unsigned char *DWCi_NodeInfoList_GetNodeInfoForProfileID(void);

int DWCi_GetAIDFromProfileID(void)
{
    unsigned char *p = DWCi_NodeInfoList_GetNodeInfoForProfileID();

    return p == 0 ? 0xff : *(unsigned char *)(p + 0x16);
}

