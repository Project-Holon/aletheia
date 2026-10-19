/*
 * function: ConnectTestRetry
 * address:  0x0205F384
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectTestRetry (test.o)
 *
 * symbols:
 *   SOCL_CalmDown                    0x0215ed60 arm
 *   SOC_Cleanup                      0x0215fa90 arm
 */

extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);

static unsigned char ConnectTestRetry(void)
{
    int result;

    result = SOCL_CalmDown();
    if (result != 0) {
        return 0xB;
    }
    result = SOC_Cleanup();
    if (result == 0 || result == -39) {
        return 9;
    }
    return 0xB;
}
