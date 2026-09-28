/*
 * function: NNFreeNegotiateList
 * address:  0x0219922C
 * packet:   pkt_ov009_0219922C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NNFreeNegotiateList (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   ArrayLength    0x02184200 arm
 *   gsDebugFormat  0x0217D254 arm
 *   ArrayFree      0x021841B0 arm
 *   negotiateList  0x021AE698 data
 *   g_021A5A84     0x021A5A84 data
 */

typedef unsigned char u8;

struct DArrayImplementation
{
    int count;
};

extern int ArrayLength(void *array);
extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void ArrayFree(struct DArrayImplementation *array);
extern struct DArrayImplementation * negotiateList;
extern char g_021A5A84[];

void NNFreeNegotiateList(void)
{
    if (negotiateList == 0)
        return;
    gsDebugFormat(7, 3, 8, g_021A5A84, ArrayLength(negotiateList));
    ArrayFree(negotiateList);
    negotiateList = 0;
}
