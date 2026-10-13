/*
 * file:     sciserialize.c
 * unit:     yes
 * function: sciSerializeInt8, sciSerializeInt16, sciSerializeInt32, sciSerializeGUID
 * address:  0x021E04FC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Stats and Control client (libdwcgssc, object sciserialize.o): writes
 * integers and GUIDs into the report buffer in network byte order.
 *
 * symbols:
 *   STD_TSScanf  0x0208CF34  arm
 *   sSciGuidFormatInt32  0x021E4198  data
 *   sSciGuidFormatInt16  0x021E419C  data
 *   sSciGuidFormatByte  0x021E41A0  data
 *   sSciGuidFormatByteRun  0x021E41A4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sc_types.h"

extern int STD_TSScanf(const char *src, const char *fmt, ...);

extern char sSciGuidFormatInt32[];
extern char sSciGuidFormatInt16[];
extern char sSciGuidFormatByte[];
extern char sSciGuidFormatByteRun[];

/* sciSerializeInt8 (name guessed): writes one byte and returns the next position. */
char *sciSerializeInt8(char *dst, int value)
{
    *dst++ = value;
    return dst;
}

/*
 * sciSerializeInt16: writes a 16 bit value in network byte order.  The swapped
 * halfword is built in a local whose address is taken and its two bytes are
 * copied out one at a time; that form gives the original instruction order.
 */
unsigned char *sciSerializeInt16(unsigned char *dst, unsigned int value)
{
    unsigned short half = (unsigned short)value;
    unsigned short swapped = ((half >> 8) & 0xff) | ((half << 8) & 0xff00);
    unsigned char *bytes = (unsigned char *)&swapped;

    dst[0] = bytes[0];
    dst[1] = bytes[1];
    return dst + 2;
}

/* sciSerializeInt32: as sciSerializeInt16 for a 32 bit value. */
unsigned char *sciSerializeInt32(unsigned char *dst, unsigned int value)
{
    unsigned int swapped = ((value >> 24) & 0xff) | ((value >> 8) & 0xff00) | ((value << 8) & 0xff0000)
                         | ((value << 24) & 0xff000000);
    unsigned char *bytes = (unsigned char *)&swapped;

    dst[0] = bytes[0];
    dst[1] = bytes[1];
    dst[2] = bytes[2];
    dst[3] = bytes[3];
    return dst + 4;
}

/*
 * sciSerializeGUID: parses the text form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
 * and writes the 16 bytes (one int, two shorts, eight bytes) at the cursor.
 */
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
