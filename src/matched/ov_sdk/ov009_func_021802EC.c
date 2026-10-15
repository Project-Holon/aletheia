/*
 * function: UTF8ToUCS2StringAllocLen
 * address:  0x021802EC
 * packet:   pkt_ov009_021802EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      UTF8ToUCS2StringAllocLen (gsstringutil.o)
 *
 * symbols:
 *   _UTF8ToUCS2ConversionLengthOnly                  0x0218022C  arm ov009
 *   gsimalloc                  0x0217EAB0  arm ov009
 *   UTF8ToUCS2StringLen2                  0x02180334  arm ov009
 */

extern int _UTF8ToUCS2ConversionLengthOnly(const char *s, int n);
extern void *gsimalloc(unsigned long size);
typedef unsigned short u16;
extern int UTF8ToUCS2StringLen2(const unsigned char *src, int size, u16 *out, int max);

unsigned short *UTF8ToUCS2StringAllocLen(char *theUTF8String, int theUTF8StringLength)
{
    unsigned short *aUCS2String;
    int newLength;

    if (theUTF8String == 0)
        return 0;
    newLength = _UTF8ToUCS2ConversionLengthOnly(theUTF8String, theUTF8StringLength);
    aUCS2String = (unsigned short *)gsimalloc((newLength + 1) * 2);
    UTF8ToUCS2StringLen2((const unsigned char *)theUTF8String, theUTF8StringLength, aUCS2String, newLength);
    return aUCS2String;
}
