/*
 * function: func_0217D32C
 * address:  0x0217D32C
 * packet:   pkt_ov009_0217D32C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsDebugBinary (gsdebug.o)
 *
 * symbols:
 *   func_0217D280                  0x0217D280  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   g_021A3718                     0x021A3718  data
 */

extern void func_0217D280(char *theInStream, char *theOutStream, unsigned int theInLen);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern char g_021A3718[];

void func_0217D32C(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength)
{
    char aHexStr[80];
    char *aReadPos;
    int aBytesLeft;
    int n;

    aReadPos = theBuffer;
    aBytesLeft = theLength;
    while (aBytesLeft > 0) {
        n = aBytesLeft;
        if (n >= 16)
            n = 16;
        func_0217D280(aReadPos, aHexStr, n);
        func_0217D254(theCat, theType, theLevel, g_021A3718, aHexStr);
        aBytesLeft -= n;
        aReadPos += n;
    }
}
