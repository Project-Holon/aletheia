/*
 * file:     gsdebug.c
 * unit:     yes
 * function: func_0217D188, func_0217D19C, func_0217D254, func_0217D280, func_0217D32C
 * address:  0x0217D188
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
 *   func_0218402C  0x0218402C  arm
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   g_021AD000     0x021AD000  data
 *   g_021AD008     0x021AD008  data
 *   g_021AD020     0x021AD020  data
 *   func_020923B0                  0x020923B0  arm
 *   OS_SPrintf                  0x02084F40  arm
 *   g_020A61DC                     0x020A61DC  data
 *   g_021A3710                     0x021A3710  data
 *   g_021A3718                     0x021A3718  data
 */
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
typedef char *va_list;

typedef struct {
    void (*callback)(int, int, int, const char *, va_list);
    int initialized;
} GSIDebugState;

extern void func_0218402C(char *format, char *args);
extern void gsiInitializeCriticalSection(void *mutex);
extern void gsiEnterCriticalSection(void *mutex);
extern void gsiLeaveCriticalSection(void *mutex);
extern void *func_020923B0(void *p, int c, unsigned long n);
extern int OS_SPrintf(char *dst, char *fmt, ...);
void func_0217D188(int a, int b, int c, int d, int e);
void func_0217D19C(int cat, int type, int level, const char *fmt, va_list args);
void func_0217D254(int cat, int type, int level, const char *fmt, ...);
void func_0217D280(char *theInStream, char *theOutStream, unsigned int theInLen);
void func_0217D32C(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern GSIDebugState g_021AD000;
extern int g_021AD008[];
extern unsigned char g_021AD020[][5];
extern const unsigned short g_020A61DC[];
extern char g_021A3710[];
extern char g_021A3718[];



void func_0217D188(int a, int b, int c, int d, int e)
{
    func_0218402C((char *)d, (char *)e);
}



/*
 * gsDebugVaList: the filtering dispatcher behind gsDebugFormat
 * (func_0217D254).  Lazily initialise the debug lock, take it, test the
 * category/type level byte and dispatch to the registered callback (or the
 * default va_list printer), then release the lock.
 *
 * The callback and the init flag are one object at 0x021AD000 (the flag is
 * read as [base,#4]); declaring them as a struct keeps that single pool
 * relocation.  The level table at 0x021AD020 is indexed [cat][type] with a
 * 5-byte row stride.
 */
void func_0217D19C(int cat, int type, int level, const char *fmt, va_list args)
{
    unsigned char enabled;

    if (g_021AD000.initialized == 0) {
        g_021AD000.initialized = 1;
        gsiInitializeCriticalSection(g_021AD008);
    }
    gsiEnterCriticalSection(g_021AD008);
    enabled = g_021AD020[cat][type];
    if (enabled & level) {
        if (g_021AD000.callback != 0)
            g_021AD000.callback(cat, type, level, fmt, args);
        else
            func_0217D188(cat, type, level, (int)fmt, (int)args);
    }
    gsiLeaveCriticalSection(g_021AD008);
}



/*
 * Variadic logging thunk: capture the anonymous arguments with va_start and
 * forward (index, table, mask, fmt, args) to the filtering dispatcher
 * func_0217D19C.  Callers use it as a printf-style logger over one of the
 * DWC category tables.
 */
void func_0217D254(int cat, int type, int level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    func_0217D19C(cat, type, level, fmt, args);
}


static inline int isgraph(int c) { return ((c < 0 || c >= 0x80) ? 0 : (g_020A61DC[c] & 0x10)); }



/*
 * sdk:      HexEncode16 (gsdebug.o, stamp 4.0.0.1025)
 *
 * Closed 2026-10-01 (ov SDK lane 01): the long-standing r6/r7 tie between
 * aTextOutStream and aChar was the isgraph spelling. Written as a
 * `static inline int isgraph(int c)` function (the DS GameSpy ctype form, as
 * in ov114 ghiParseStatus) the inline's int parameter is a separate web and the
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

        OS_SPrintf(theOutStream, g_021A3710, aChar);
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
        func_0217D254(theCat, theType, theLevel, g_021A3718, aHexStr);
        aBytesLeft -= n;
        aReadPos += n;
    }
}
