/*
 * file:     gsdebug.c
 * unit:     yes
 * function: gsiDebugCallback, gsDebugVaList, gsDebugFormat, HexEncode16, gsDebugBinary
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
 *   VPrintf  0x0218402C  arm
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   gGsDebugState     0x021AD000  data
 *   gGsDebugCriticalSection     0x021AD008  data
 *   gGsDebugEnabled     0x021AD020  data
 *   MSL_C_LIB_MemsetPtr                  0x020923B0  arm
 *   OS_SPrintf                  0x02084F40  arm
 *   gCtypeMap                     0x020A61DC  data
 *   gGsDebugHexFormat2                     0x021A3710  data
 *   gGsDebugMsgFmt                     0x021A3718  data
 */
#include "../sdk_stdarg.h"

typedef struct {
    void (*callback)(int, int, int, const char *, va_list);
    int initialized;
} GSIDebugState;

#include "screen.h"
#include "gsplatformthread.h"
typedef unsigned int size_t;
#include "../arm9/msl_string_mem.h"
#include "../arm9/os_printf.h"
void gsiDebugCallback(int cat, int type, int level, const char *fmt, va_list args);
void gsDebugVaList(int cat, int type, int level, const char *fmt, va_list args);
void gsDebugFormat(int cat, int type, int level, const char *fmt, ...);
void HexEncode16(char *theInStream, char *theOutStream, unsigned int theInLen);
void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern GSIDebugState gGsDebugState;
extern int gGsDebugCriticalSection[];
extern unsigned char gGsDebugEnabled[][5];
extern const unsigned short gCtypeMap[];
extern char gGsDebugHexFormat2[];
extern char gGsDebugMsgFmt[];

void gsiDebugCallback(int cat, int type, int level, const char *fmt, va_list args)
{
    VPrintf(fmt, args);
}

/*
 * gsDebugVaList: the filtering dispatcher behind gsDebugFormat
 * (gsDebugFormat).  Lazily initialise the debug lock, take it, test the
 * category/type level byte and dispatch to the registered callback (or the
 * default va_list printer), then release the lock.
 *
 * The callback and the init flag are one object at 0x021AD000 (the flag is
 * read as [base,#4]); declaring them as a struct keeps that single pool
 * relocation.  The level table at 0x021AD020 is indexed [cat][type] with a
 * 5-byte row stride.
 */
void gsDebugVaList(int cat, int type, int level, const char *fmt, va_list args)
{
    unsigned char enabled;

    if (gGsDebugState.initialized == 0) {
        gGsDebugState.initialized = 1;
        gsiInitializeCriticalSection(gGsDebugCriticalSection);
    }
    gsiEnterCriticalSection(gGsDebugCriticalSection);
    enabled = gGsDebugEnabled[cat][type];
    if (enabled & level) {
        if (gGsDebugState.callback != 0)
            gGsDebugState.callback(cat, type, level, fmt, args);
        else
            gsiDebugCallback(cat, type, level, fmt, args);
    }
    gsiLeaveCriticalSection(gGsDebugCriticalSection);
}

/*
 * Variadic logging thunk: capture the anonymous arguments with va_start and
 * forward (index, table, mask, fmt, args) to the filtering dispatcher
 * gsDebugVaList.  Callers use it as a printf-style logger over one of the
 * DWC category tables.
 */
void gsDebugFormat(int cat, int type, int level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    gsDebugVaList(cat, type, level, fmt, args);
}

static inline int isgraph(int c) { return ((c < 0 || c >= 0x80) ? 0 : (gCtypeMap[c] & 0x10)); }

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

/*
 * sdk:      gsDebugBinary (gsdebug.o)
 */
void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength)
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
        HexEncode16(aReadPos, aHexStr, n);
        gsDebugFormat(theCat, theType, theLevel, gGsDebugMsgFmt, aHexStr);
        aBytesLeft -= n;
        aReadPos += n;
    }
}
