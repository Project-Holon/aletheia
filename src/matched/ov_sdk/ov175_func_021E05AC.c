/*
 * function: sciSerializeGUID
 * address:  0x021E05AC
 * packet:   pkt_ov175_021E05AC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciSerializeGUID (libdwcgssc.TWL.HYB.a sciserialize.o)
 *
 * symbols:
 *   STD_TSScanf  0x0208CF34  arm
 *   sciSerializeInt32  0x021E054C  arm  ov175
 *   sciSerializeInt16  0x021E0504  arm  ov175
 *   sSciGuidFormatInt32  0x021E4198  data
 *   sSciGuidFormatInt16  0x021E419C  data
 *   sSciGuidFormatByte  0x021E41A0  data
 *   sSciGuidFormatByteRun  0x021E41A4  data
 */

#include "../arm9_sdk/libc/string.h"
extern int STD_TSScanf(const char *src, const char *fmt, ...);
extern unsigned char *sciSerializeInt32(unsigned char *theCursor, int theValue);
extern unsigned char *sciSerializeInt16(unsigned char *theCursor, short theValue);
extern char sSciGuidFormatInt32[];
extern char sSciGuidFormatInt16[];
extern char sSciGuidFormatByte[];
extern char sSciGuidFormatByteRun[];

unsigned char *sciSerializeGUID(unsigned char *theCursor, unsigned char *theGUID)
{
    unsigned int anInt = 0;
    unsigned int aShort1 = 0;
    unsigned int aShort2 = 0;
    unsigned int aIntArray[8];
    unsigned char aByteArray[8];
    int i;

    STD_TSScanf((char *)theGUID, sSciGuidFormatInt32, &anInt);
    STD_TSScanf((char *)theGUID + 9, sSciGuidFormatInt16, &aShort1);
    STD_TSScanf((char *)theGUID + 14, sSciGuidFormatInt16, &aShort2);
    STD_TSScanf((char *)theGUID + 19, sSciGuidFormatByte, &aIntArray[0]);
    STD_TSScanf((char *)theGUID + 21, sSciGuidFormatByte, &aIntArray[1]);
    STD_TSScanf((char *)theGUID + 24, sSciGuidFormatByteRun, &aIntArray[2], &aIntArray[3], &aIntArray[4],
                &aIntArray[5], &aIntArray[6], &aIntArray[7]);
    for (i = 0; i < 8; i++)
        aByteArray[i] = (unsigned char)aIntArray[i];
    theCursor = sciSerializeInt32(theCursor, anInt);
    theCursor = sciSerializeInt16(theCursor, (short)aShort1);
    theCursor = sciSerializeInt16(theCursor, (short)aShort2);
    memcpy(theCursor, aByteArray, 8);
    return theCursor + 8;
}
