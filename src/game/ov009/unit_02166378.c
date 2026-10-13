/*
 * file:     unit_02166378.c
 * function: WCMi_GetCpsifWork
 * address:  0x02166378
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the address of the CPS interface work block (initialised flag,
 * send mutex, receive and send callbacks, AP MAC address; see WCMCpsifWork
 * in twl/nwmif.c and unit_02166304.c).
 *
 * symbols:
 *   g_021AA7DC  0x021AA7DC  data
 */

extern unsigned char g_021AA7DC[];

void *WCMi_GetCpsifWork(void)
{
    return g_021AA7DC;
}

