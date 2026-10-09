/*
 * file:     unit_02180410_p13.c
 * unit:     yes
 * function: gsUdpEngineNoMoreMsgHandlers, gsUdpEngineNoApp
 * address:  0x02181828
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
 *   ArrayLength                      0x02184200 arm
 *   d_021A3B9C                       0x021a3b9c data
 */
struct GSUdpEngineObject {
    void *field0;             /* +0x00 */
    void *field4;             /* +0x04 */
    void *field8;             /* +0x08 */
    int   fieldC;             /* +0x0c */
    void *field10;            /* +0x10 */
    void *field14;            /* +0x14 */
    void *field18;            /* +0x18 */
    void *field1c;            /* +0x1c */
    void *field20;            /* +0x20 */
    void *field24;            /* +0x24 */
    void *field28;            /* +0x28 */
};

extern struct GSUdpEngineObject *gsUdpEngineGetEngine(void);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr);
extern int ArrayLength(void *array);
int gsUdpEngineNoMoreMsgHandlers(void);
int gsUdpEngineNoApp(void);
extern char d_021A3B9C[];


int gsUdpEngineNoMoreMsgHandlers(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 0xf, d_021A3B9C);
        return 1;
    }
    return ArrayLength(aUdp->field8) == 0;
}


int gsUdpEngineNoApp(void)
{
    struct GSUdpEngineObject *aUdp = gsUdpEngineGetEngine();

    if (aUdp->fieldC == 0) {
        gsDebugFormat(0xc, 0, 0xf, d_021A3B9C);
        return 1;
    }
    if (aUdp->field14 != 0 || aUdp->field20 != 0 || aUdp->field10 != 0 ||
        aUdp->field24 != 0 || aUdp->field18 != 0 || aUdp->field1c != 0 ||
        aUdp->field28 != 0)
        return 0;
    return 1;
}
