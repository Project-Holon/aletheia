/*
 * function: gsUdpEngineGetLocalPort
 * address:  0x0218158C
 * packet:   pkt_ov009_0218158C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineGetLocalPort (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineGetEngine             0x02180404 arm
 *   gsDebugFormat                    0x0217d254 arm
 *   d_021A3B9C                       0x021a3b9c data
 */

struct GSUdpEngineObject {
    void *field0;             /* +0x00 */
    void *field4;             /* +0x04 */
    void *field8;             /* +0x08 */
    int   fieldC;             /* +0x0c */
    char  pad10[0x38 - 0x10];
    unsigned short field38;   /* +0x38 */
};

extern struct GSUdpEngineObject *gsUdpEngineGetEngine(void);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr);
extern char d_021A3B9C[];

unsigned short gsUdpEngineGetLocalPort(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 1, d_021A3B9C);
        return 0;
    }
    return aUdp->field38;
}
