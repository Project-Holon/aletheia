/*
 * file:     unit_02180410_p09.c
 * unit:     yes
 * function: gsUdpEngineThink, gsUdpEngineShutdown, gsUdpEngineGetLocalPort
 * address:  0x021814EC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsUdpEngineGetEngine             0x02180404 arm
 *   gsDebugFormat                    0x0217d254 arm
 *   gt2Think                         0x02195af0 arm
 *   d_021A3B9C                       0x021a3b9c data
 *   gt2CloseSocket                   0x02195ad8 arm
 *   ArrayFree                        0x021841b0 arm
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
extern void gt2Think(void *socket);
extern void gt2CloseSocket(void *socket);
extern void ArrayFree(void *array);
int gsUdpEngineThink(void);
int gsUdpEngineShutdown(void);
unsigned short gsUdpEngineGetLocalPort(void);
extern char d_021A3B9C[];



int gsUdpEngineThink(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 0xf, d_021A3B9C);
        return 3;
    }
    gt2Think(aUdp->field0);
    return 0;
}



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


unsigned short gsUdpEngineGetLocalPort(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 1, d_021A3B9C);
        return 0;
    }
    return aUdp->field38;
}
