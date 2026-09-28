/*
 * function: DWCi_DeleteAID
 * address:  0x0216BCA4
 * packet:   pkt_ov009_0216BCA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DeleteAID (dwc_main.o)
 *
 * symbols:
 *   func_02176410  0x02176410  arm  ov009
 *   func_02176164  0x02176164  arm  ov009
 */

extern char *func_02176410(unsigned char aid);
extern int func_02176164(unsigned char aid);

int DWCi_DeleteAID(unsigned char aid)
{
    char *pNodeInfo = func_02176410(aid);
    int profileID;

    if (pNodeInfo == 0) return 0;
    profileID = *(int *)pNodeInfo;
    func_02176164(aid);
    return profileID;
}
