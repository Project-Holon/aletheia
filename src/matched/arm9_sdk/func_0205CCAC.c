/*
 * function: func_0205CCAC
 * address:  0x0205CCAC
 * packet:   pkt_0205CCAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CheckDisconnected (dwc_connectinet.o)
 *
 * symbols:
 *   g_02146AD4 0x02146AD4 data
 */

typedef struct {
    int ac_state;
    unsigned short state;
} DWCstInetControl;

/* dwc_connectinet.o .bss: stateOld (DWC_GetInetStatus static) then stpInetCntl */
typedef struct {
    int stateOld;
    DWCstInetControl *stpInetCntl;
} INETBSS;

extern INETBSS g_02146AD4;

int func_0205CCAC(void)
{
    if (g_02146AD4.stpInetCntl != 0 && g_02146AD4.stpInetCntl->state == 6) {
        return 1;
    }
    return 0;
}
