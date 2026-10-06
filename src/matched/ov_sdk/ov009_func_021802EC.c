/*
 * function: func_021802EC
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
 *   func_0218022C                  0x0218022C  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_02180334                  0x02180334  arm ov009
 */

extern int func_0218022C(const char *s, int n);
extern void *func_0217EAB0(unsigned long size);
typedef unsigned short u16;
extern int func_02180334(const unsigned char *src, int size, u16 *out, int max);

unsigned short *func_021802EC(char *theUTF8String, int theUTF8StringLength)
{
    unsigned short *aUCS2String;
    int newLength;

    if (theUTF8String == 0)
        return 0;
    newLength = func_0218022C(theUTF8String, theUTF8StringLength);
    aUCS2String = (unsigned short *)func_0217EAB0((newLength + 1) * 2);
    func_02180334((const unsigned char *)theUTF8String, theUTF8StringLength, aUCS2String, newLength);
    return aUCS2String;
}
