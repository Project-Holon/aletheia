/*
 * function: DWCi_Auth_AbortAuthentication
 * address:  0x02178DA4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two module helpers in order.
 *
 * symbols:
 *   DWC_Auth_Abort  0x021780A8  arm
 *   DWC_Auth_Destroy  0x02178144  arm

 */

extern void DWC_Auth_Abort(void);
extern void DWC_Auth_Destroy(void);

void DWCi_Auth_AbortAuthentication(void)
{
    DWC_Auth_Abort();
    DWC_Auth_Destroy();
}

