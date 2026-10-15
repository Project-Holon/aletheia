/*
 * function: WCM_CompareBssID
 * address:  0x021666B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the constant third argument 6.
 *
 * symbols:
 *   WcmCompareMemory  0x02166680  arm  ov009
 */

extern int WcmCompareMemory(unsigned char *a, unsigned char *b, unsigned int n);

void WCM_CompareBssID(int a, int b)
{
    WcmCompareMemory((unsigned char *)a, (unsigned char *)b, 6);
}

