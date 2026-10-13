/*
 * function: WCMi_GetDefaultDeviceId
 * address:  0x02165B68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two when the word call is non-zero, one otherwise.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9

 */

extern int OS_IsRunOnTwl(int a);

int WCMi_GetDefaultDeviceId(int a)
{
    return OS_IsRunOnTwl(a) ? 2 : 1;
}

