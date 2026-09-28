/*
 * function: CloseSocket
 * address:  0x0205B2F8
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * symbols:
 *   SOCLiConfigPtr  0x021A1CD8  data  a4
 *   SOC_Cleanup     0x0215FA90  arm
 *
 * TwlDWC libdwcac close.o.
 * Blocker: the only literal-pool reference to SOCLiConfigPtr (0x021A1CD8)
 * in arm9 is this function's own pool word, so the ABS32 site has no
 * outside witness and cannot leave MATCH.
 */
extern void *SOCLiConfigPtr;
extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);

int func_0205B2F8(void)
{
    int result;

    if (SOCLiConfigPtr == 0) {
        return 1;
    }
    if (SOCL_CalmDown() != 0) {
        return 0;
    }
    result = SOC_Cleanup();
    return (result == 0 || result == -39) ? 1 : 0;
}
