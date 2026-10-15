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
 */

extern char gWcmCpsifMac[];
extern void func_02082EA4(char *p, int a, int n);

void WCM_GetMacAddress(int a)
{
    func_02082EA4(gWcmCpsifMac, a, 6);
}

