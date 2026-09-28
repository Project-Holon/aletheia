/*
 * function: func_0205B2F8
 * address:  0x0205B2F8
 * packet:   pkt_0205B2F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CloseSocket (libdwcac.TWL.HYB.a close.o, static)
 *
 * symbols:
 *   SOCL_CalmDown   0x0215ED60  arm
 *   SOC_Cleanup     0x0215FA90  arm
 *   SOCLiConfigPtr  0x021A1CD8  data  ov009
 */

extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);
extern void *SOCLiConfigPtr;

int func_0205B2F8(void)
{
    int result;

    if (SOCLiConfigPtr == 0)
        return 1;
    if (SOCL_CalmDown() != 0)
        return 0;
    result = SOC_Cleanup();
    if (result == 0 || result == -39)
        return 1;
    return 0;
}
