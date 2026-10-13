/*
 * function: gti2CloseAllConnectionsHardMap
 * address:  0x02195DD4
 * packet:   pkt_ov009_02195DD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWC_IsSendableReliable       0x02195DC4  arm
*/

extern void DWC_IsSendableReliable(void *p);

static void gti2CloseAllConnectionsHardMap(void **elem)
{
    DWC_IsSendableReliable(*elem);
}
