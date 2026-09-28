/*
 * function: func_0205F384
 * address:  0x0205F384
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: ConnectTestRetry (test.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   SOCL_CalmDown   0x0215ED60  arm
 *   SOC_Cleanup     0x0215FA90  arm
 */

extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);

unsigned char func_0205F384(void)
{
    int result = SOCL_CalmDown();

    if (result != 0)
        return 0xb;
    result = SOC_Cleanup();
    if (result == 0 || result == -0x27)
        return 9;
    return 0xb;
}
