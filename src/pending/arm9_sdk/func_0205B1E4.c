/*
 * function: DWCi_AC_CloseNetwork
 * address:  0x0205B1E4
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * TwlDWC libdwcac close.o.
 */
extern int DisConnectAP(void);
extern int CloseSocket(void);
extern void DWC_Netcheck_Abort(void);
extern void DWC_Netcheck_Destroy(void);

int func_0205B1E4(unsigned char *phase)
{
    int result;

    if (*phase <= 10) {
        result = DisConnectAP();
        if (result == 1) {
            *phase = 0;
            return 1;
        }
        if (result == -1) {
            *phase = 18;
            return 1;
        }
    } else if (*phase == 14) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *phase = 12;
    } else if (*phase < 18) {
        result = CloseSocket();
        if (result == 1) {
            *phase = 10;
        }
    }
    return 0;
}
