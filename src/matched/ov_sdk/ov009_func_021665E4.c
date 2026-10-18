/*
 * function: WCM_GetMacAddress
 * address:  0x021665E4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies six bytes to the object at 0x021AA80C.
 *
 * symbols:
 *   gWcmCpsifMac  0x021AA80C  data
 *   MI_CpuCopy  0x02082EA4  arm  arm9
 */

extern char gWcmCpsifMac[];
extern void MI_CpuCopy(char *p, int a, int n);

void WCM_GetMacAddress(int a)
{
    MI_CpuCopy(gWcmCpsifMac, a, 6);
}

