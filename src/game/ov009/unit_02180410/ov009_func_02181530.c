/*
 * function: gsUdpEngineShutdown
 * address:  0x02181530
 * packet:   pkt_ov009_02181530
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineShutdown (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineGetEngine             0x02180404 arm
 *   gsDebugFormat                    0x0217d254 arm
 *   gt2CloseSocket                   0x02195ad8 arm
 *   ArrayFree                        0x021841b0 arm
 *   d_021A3B9C                       0x021a3b9c data
 */

struct GSUdpEngineObject {
    void *field0;             /* +0x00 */
    void *field4;             /* +0x04 */
    void *field8;             /* +0x08 */
    int   fieldC;             /* +0x0c */
};

extern struct GSUdpEngineObject *gsUdpEngineGetEngine(void);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr);
extern void gt2CloseSocket(void *socket);
extern void ArrayFree(void *array);
extern char d_021A3B9C[];

int gsUdpEngineShutdown(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 0xf, d_021A3B9C);
        return 3;
    }
    gt2CloseSocket(aUdp->field0);
    ArrayFree(aUdp->field8);
    ArrayFree(aUdp->field4);
    aUdp->fieldC = 0;
    return 0;
}
