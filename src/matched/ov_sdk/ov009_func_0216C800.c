/*
 * function: DWCi_GetServerOrSubServerAID
 * address:  0x0216C800
 * packet:   pkt_ov009_0216C800
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetServerOrSubServerAID (dwc_main.o)
 *
 * symbols:
 *   DWC_GetServerAID  0x0216B9B0  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 */

extern unsigned char DWC_GetServerAID(void);
extern char *func_0217637C(int index);

unsigned char DWCi_GetServerOrSubServerAID(void)
{
    unsigned char aid = DWC_GetServerAID();
    if (aid == 0xff) {
        char *info = func_0217637C(0);
        if (info != 0) aid = info[0x16];
    }
    return aid;
}
