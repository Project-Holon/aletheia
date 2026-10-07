/*
 * function: func_02166358
 * address:  0x02166358
 * packet:   pkt_ov009_02166358
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_CpsifRecvCallback (cpsif.o)
 *
 * Forwards its four arguments to the receive callback at +0x28 of the
 * cpsif work block, if one is set.
 *
 * symbols:
 *   g_021AA7DC  0x021AA7DC  data
 */

#include "../../../matched/include/G_WCMCpsifWork.h"

extern struct WCMCpsifWork g_021AA7DC;

void func_02166358(unsigned char *s, unsigned char *d, unsigned char *dat, long len)
{
    if (g_021AA7DC.cb != 0)
        g_021AA7DC.cb(s, d, dat, len);
}
