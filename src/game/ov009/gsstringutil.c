/*
 * file:     gsstringutil.c
 * unit:     yes
 * function: func_021800CC, func_021801C0, func_0218022C, func_021802C8, func_021802EC, func_02180334, func_021803BC, gsUdpEngineContext
 * address:  0x021800CC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Address of the module state object.
 *
 * symbols:
 *   func_0209477C                  0x0209477C  arm
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_02092344  0x02092344  arm
 *   g_021AD188  0x021AD188  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_0209477C(const u8 *s);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
int func_021800CC(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut);
int func_021801C0(unsigned short theUCS2Char, char *theUTF8String);
int func_0218022C(const char *s, int n);
unsigned short *func_021802C8(char *theUTF8String);
unsigned short *func_021802EC(char *theUTF8String, int theUTF8StringLength);
int func_02180334(const unsigned char *src, int size, u16 *out, int max);
int func_021803BC(char *dst, const char *src, unsigned int n);
void *gsUdpEngineContext(void);
extern char g_021AD188[];


/*
 * sdk:      _ReadUCS2CharFromUTF8String (gsstringutil.o)
 */
int func_021800CC(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut)
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


/*
 * sdk:      _UCS2CharToUTF8String (gsstringutil.o)
 */
int func_021801C0(unsigned short theUCS2Char, char *theUTF8String)
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


/*
 * Count the characters of a null-terminated string, consuming at most `n`
 * bytes: a lead byte 110xxxxx with a valid continuation costs 2 bytes, a lead
 * 1110xxxx with two valid continuations costs 3, anything else 1.  A null
 * string counts as zero characters.
 */
int func_0218022C(const char *s, int n)
{
    int count = 0;

    if (s == 0)
        return 0;

    while (*s != 0 && n > 0) {
        unsigned char c = *s;

        if ((c & 0xe0) == 0xc0 && n >= 2 && (((unsigned char *)s)[1] & 0xc0) == 0x80) {
            s += 2;
            n -= 2;
        } else if ((c & 0xf0) == 0xe0 && n >= 3 && (((unsigned char *)s)[1] & 0xc0) == 0x80
                   && (((unsigned char *)s)[2] & 0xc0) == 0x80) {
            s += 3;
            n -= 3;
        } else {
            s += 1;
            n -= 1;
        }
        count++;
    }
    return count;
}



/*
 * sdk:      UTF8ToUCS2StringAlloc (gsstringutil.o)
 */
unsigned short *func_021802C8(char *theUTF8String)
{
    if (theUTF8String == 0)
        return 0;
    return func_021802EC(theUTF8String, func_0209477C((const u8 *)theUTF8String));
}



/*
 * sdk:      UTF8ToUCS2StringAllocLen (gsstringutil.o)
 */
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



/*
 * Transcode the null-terminated text at `src` into 16-bit units at `out`,
 * asking func_021800CC to consume one character at a time from the remaining
 * `size` bytes, until the input ends, `max` units have been produced, or the
 * input is exhausted.  Returns one past the number of units written, or 0 on
 * a decoding failure; a null source writes a lone terminator and returns 1.
 */
int func_02180334(const unsigned char *src, int size, u16 *out, int max)
{
    int n = 0;
    int off = 0;
    u16 *dst = out;

    if (src == 0) {
        *out = 0;
        return 1;
    }
    while (*src != 0 && max + 1 > n && size > off) {
        int r = func_021800CC((char *)src, size - off, dst);

        if (r == 0) {
            *out = 0;
            return 0;
        }
        off += r;
        src += r;
        n++;
        dst++;
    }
    *dst = 0;
    return n + 1;
}



/*
 * Bounded copy helper used by gpiProcessSearch: measure src with the ARM9
 * length helper, clamp to n-1, copy, NUL-terminate, return the byte count.
 * (A strlcpy-shaped helper.)
 */
int func_021803BC(char *dst, const char *src, unsigned int n)
{
    unsigned int len = func_0209477C((const u8 *)src);

    if (len > n - 1)
        len = n - 1;
    func_02092344(dst, src, len);
    dst[len] = 0;
    return len;
}


void *gsUdpEngineContext(void)
{
    return g_021AD188;
}
