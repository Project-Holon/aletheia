/*
 * function: gsDebugBinary
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
 *   HexEncode16                  0x0217D280  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   g_021A3718                     0x021A3718  data
 */

extern void HexEncode16(char *theInStream, char *theOutStream, unsigned int theInLen);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern char g_021A3718[];

void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength)
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
        HexEncode16(aReadPos, aHexStr, n);
        gsDebugFormat(theCat, (char *)theType, theLevel, g_021A3718, aHexStr);
        aBytesLeft -= n;
        aReadPos += n;
    }
}
