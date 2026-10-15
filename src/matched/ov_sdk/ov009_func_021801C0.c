/*
 * function: _UCS2CharToUTF8String
 * address:  0x021801C0
 * packet:   pkt_ov009_021801C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _UCS2CharToUTF8String (gsstringutil.o)
 *
 * symbols:

 */

int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String)
{
    if (theUCS2Char <= 0x7f) {
        theUTF8String[0] = (char)theUCS2Char;
        return 1;
    }
    if (theUCS2Char <= 0x7ff) {
        theUTF8String[0] = (char)(0xc0 | (theUCS2Char >> 6));
        theUTF8String[1] = (char)(0x80 | (theUCS2Char & 0x3f));
        return 2;
    }
    theUTF8String[0] = (char)(0xe0 | (theUCS2Char >> 12));
    theUTF8String[1] = (char)(0x80 | ((theUCS2Char >> 6) & 0x3f));
    theUTF8String[2] = (char)(0x80 | (theUCS2Char & 0x3f));
    return 3;
}
