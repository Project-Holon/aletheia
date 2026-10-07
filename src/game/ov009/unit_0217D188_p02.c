/*
 * file:     unit_0217D188_p02.c
 * unit:     yes
 * function: func_0217D254, func_0217D280, func_0217D32C
 * address:  0x0217D254
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217D19C  0x0217D19C  arm  ov009
 *   func_020923B0                  0x020923B0  arm
 *   func_02084F40                  0x02084F40  arm
 *   g_020A61DC                     0x020A61DC  data
 *   g_021A3710                     0x021A3710  data
 *   g_021A3718                     0x021A3718  data
 */
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
typedef char *va_list;

extern int func_0217D19C(int index, char *table, int mask, const char *fmt, va_list args);
extern void *func_020923B0(void *p, int c, unsigned long n);
extern int func_02084F40(char *dst, char *fmt, ...);
int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
void func_0217D280(char *theInStream, char *theOutStream, unsigned int theInLen);
void func_0217D32C(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern const unsigned short g_020A61DC[];
extern char g_021A3710[];
extern char g_021A3718[];


/*
 * Variadic logging thunk: capture the anonymous arguments with va_start and
 * forward (index, table, mask, fmt, args) to the filtering dispatcher
 * func_0217D19C.  Callers use it as a printf-style logger over one of the
 * DWC category tables.
 */
int func_0217D254(int index, char *table, int mask, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    return func_0217D19C(index, table, mask, fmt, args);
}

static inline int isgraph(int c) { return ((c < 0 || c >= 0x80) ? 0 : (g_020A61DC[c] & 0x10)); }


/*
 * sdk:      HexEncode16 (gsdebug.o, stamp 4.0.0.1025)
 *
 * Closed 2026-10-01 (ov SDK lane 01): the long-standing r6/r7 tie between
 * aTextOutStream and aChar was the isgraph spelling. Written as a
 * `static inline int isgraph(int c)` function (the DS GameSpy ctype form, as
 * in ov114 func_021C4830) the inline's int parameter is a separate web and the
 * allocator hands aTextOutStream r6 as in the image; the same test as a macro
 * or open-coded ternary gives r7. DWARF has no aRowWidth/aReplaceChar/
 * aTextOffSet locals, so they are literals; theInStream is plain `char *`.
 */
void func_0217D280(char *theInStream, char *theOutStream, unsigned int theInLen)
{
    char *aTextOutStream = theOutStream + 41;
    unsigned int aWriteBit = theInLen & 1;

    func_020923B0(theOutStream, ' ', 64);
    while (theInLen--) {
        unsigned char aChar = (unsigned char)(*theInStream++);

        func_02084F40(theOutStream, g_021A3710, aChar);
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


/*
 * sdk:      gsDebugBinary (gsdebug.o)
 */
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
        func_0217D254(theCat, (char *)theType, theLevel, g_021A3718, aHexStr);
        aBytesLeft -= n;
        aReadPos += n;
    }
}
