/*
 * function: WCMi_CpsifSetMacAddress
 * address:  0x021665CC
 * packet:   pkt_ov009_021665CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy                   0x02082EA4  arm
 *   gWcmCpsifMac                   0x021AA80C  data
*/

extern void MI_CpuCopy(const void *src, void *dst, unsigned long size);
extern char gWcmCpsifMac[6];

void WCMi_CpsifSetMacAddress(const void *mac)
{
	MI_CpuCopy(mac, gWcmCpsifMac, 6);
}
