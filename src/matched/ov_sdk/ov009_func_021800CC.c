/*
 * function: _ReadUCS2CharFromUTF8String
 * address:  0x021800CC
 * packet:   pkt_ov009_021800CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _ReadUCS2CharFromUTF8String (gsstringutil.o)
 *
 * symbols:

 */

int _ReadUCS2CharFromUTF8String(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut)
{
    char c;

    if (theMaxBytes == 0) {
        *theUnicodeCharOut = '?';
        return 0;
    }
    c = theUTF8String[0];
    if ((unsigned char)c <= 0x7f) {
        *theUnicodeCharOut = c;
        return 1;
    }
    if (((unsigned char)c & 0xe0) == 0xc0) {
        if (theMaxBytes < 2) {
            *theUnicodeCharOut = '?';
            return 0;
        }
        if (((unsigned char)theUTF8String[1] & 0xc0) == 0x80) {
            *theUnicodeCharOut = ((c & 0x1f) << 6) + (theUTF8String[1] & 0x3f);
            return 2;
        }
    } else if (((unsigned char)c & 0xf0) == 0xe0) {
        if (theMaxBytes < 3) {
            *theUnicodeCharOut = '?';
            return 0;
        }
        if (((unsigned char)theUTF8String[1] & 0xc0) == 0x80 && ((unsigned char)theUTF8String[2] & 0xc0) == 0x80) {
            *theUnicodeCharOut = ((c & 0x0f) << 12) + ((theUTF8String[1] & 0x3f) << 6) + (theUTF8String[2] & 0x3f);
            return 3;
        }
    }
    *theUnicodeCharOut = '?';
    return 1;
}
