/*
 * function: HexEncode16
 * address:  0x0217D280
 * packet:   pkt_ov009_0217D280
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      HexEncode16 (gsdebug.o, stamp 4.0.0.1025)
 *
 * Closed 2026-10-01 (ov SDK lane 01): the long-standing r6/r7 tie between
 * aTextOutStream and aChar was the isgraph spelling. Written as a
 * `static inline int isgraph(int c)` function (the DS GameSpy ctype form, as
 * in ov114 ghiParseStatus) the inline's int parameter is a separate web and the
 * allocator hands aTextOutStream r6 as in the image; the same test as a macro
 * or open-coded ternary gives r7. DWARF has no aRowWidth/aReplaceChar/
 * aTextOffSet locals, so they are literals; theInStream is plain `char *`.
 *
 * symbols:
 *   MSL_C_LIB_MemsetPtr                  0x020923B0  arm
 *   OS_SPrintf                  0x02084F40  arm
 *   gCtypeMap                     0x020A61DC  data
 *   gGsDebugHexFormat2                     0x021A3710  data
 */

extern void *MSL_C_LIB_MemsetPtr(void *p, int c, unsigned long n);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern const unsigned short gCtypeMap[];
static inline int isgraph(int c) { return ((c < 0 || c >= 0x80) ? 0 : (gCtypeMap[c] & 0x10)); }
extern char gGsDebugHexFormat2[];

void HexEncode16(char *theInStream, char *theOutStream, unsigned int theInLen)
{
    char *aTextOutStream = theOutStream + 41;
    unsigned int aWriteBit = theInLen & 1;

    MSL_C_LIB_MemsetPtr(theOutStream, ' ', 64);
    while (theInLen--) {
        unsigned char aChar = (unsigned char)(*theInStream++);

        OS_SPrintf(theOutStream, gGsDebugHexFormat2, aChar);
        if (isgraph(aChar))
            *(aTextOutStream++) = (char)aChar;
        else
            *(aTextOutStream++) = '.';
        theOutStream += 2;
        if ((theInLen & 1) == aWriteBit)
            *theOutStream++ = ' ';
    }
    *theOutStream = ' ';
    *(aTextOutStream) = '\0';
}
