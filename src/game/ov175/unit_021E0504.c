/*
 * file:     unit_021E0504.c
 * unit:     yes
 * function: func_021E0504, func_021E054C, func_021E05AC
 * address:  0x021E0504
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   STD_TSScanf  0x0208CF34  arm
 *   g_021E4198  0x021E4198  data
 *   g_021E419C  0x021E419C  data
 *   g_021E41A0  0x021E41A0  data
 *   g_021E41A4  0x021E41A4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int STD_TSScanf(const char *src, const char *fmt, ...);
u8 *func_021E0504(u8 *dst, unsigned int v);
u8 *func_021E054C(u8 *dst, u32 v);
unsigned char *func_021E05AC(unsigned char *theCursor, unsigned char *theGUID);
extern char g_021E4198[];
extern char g_021E419C[];
extern char g_021E41A0[];
extern char g_021E41A4[];



/*
 * Sixteen-bit byte swap: the rotated halfword is materialised in a local whose
 * address is taken, then its two bytes are copied out one at a time, advancing
 * the destination past the halfword.
 */
u8 *func_021E0504(u8 *dst, unsigned int v)
{
    u16 t = (u16)v;
    u16 w = ((t >> 8) & 0xff) | ((t << 8) & 0xff00);
    u8 *q = (u8 *)&w;

    dst[0] = q[0];
    dst[1] = q[1];
    return dst + 2;
}



/*
 * Byte-swap: the rotated word is materialised in a local whose address is
 * taken, then its four bytes are copied out one at a time.  Advances the
 * destination past the word.
 */
u8 *func_021E054C(u8 *dst, u32 v)
{
    u32 w = ((v >> 24) & 0xff) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000)
          | ((v << 24) & 0xff000000);
    u8 *q = (u8 *)&w;

    dst[0] = q[0];
    dst[1] = q[1];
    dst[2] = q[2];
    dst[3] = q[3];
    return dst + 4;
}


/*
 * sdk:      sciSerializeGUID (libdwcgssc.TWL.HYB.a sciserialize.o)
 */
unsigned char *func_021E05AC(unsigned char *theCursor, unsigned char *theGUID)
{
    unsigned int anInt = 0;
    unsigned int aShort1 = 0;
    unsigned int aShort2 = 0;
    unsigned int aIntArray[8];
    unsigned char aByteArray[8];
    int i;

    STD_TSScanf((char *)theGUID, g_021E4198, &anInt);
    STD_TSScanf((char *)theGUID + 9, g_021E419C, &aShort1);
    STD_TSScanf((char *)theGUID + 14, g_021E419C, &aShort2);
    STD_TSScanf((char *)theGUID + 19, g_021E41A0, &aIntArray[0]);
    STD_TSScanf((char *)theGUID + 21, g_021E41A0, &aIntArray[1]);
    STD_TSScanf((char *)theGUID + 24, g_021E41A4, &aIntArray[2], &aIntArray[3], &aIntArray[4],
                &aIntArray[5], &aIntArray[6], &aIntArray[7]);
    for (i = 0; i < 8; i++)
        aByteArray[i] = (unsigned char)aIntArray[i];
    theCursor = func_021E054C(theCursor, anInt);
    theCursor = func_021E0504(theCursor, (short)aShort1);
    theCursor = func_021E0504(theCursor, (short)aShort2);
    memcpy(theCursor, aByteArray, 8);
    return theCursor + 8;
}
