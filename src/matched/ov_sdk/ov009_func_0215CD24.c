/*
 * function: SOCL_LinkIsOn
 * address:  0x0215CD24
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Non-zero test on the word call.
 *
 * symbols:
 *   WCM_GetApMacAddress  0x02166384  arm  ov009
 */

extern unsigned char *WCM_GetApMacAddress(void);

int SOCL_LinkIsOn(void)
{
    return WCM_GetApMacAddress() != 0;
}

