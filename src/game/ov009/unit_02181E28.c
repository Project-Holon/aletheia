/*
 * file:     unit_02181E28.c
 * unit:     yes
 * function: gsiXmlUtilSkipWhiteSpace, func_02181E80, func_02182414, func_02182554, func_0218263C, func_0218290C, func_021829AC, func_02182A2C, func_02182AC0, func_02182B68, func_02182C10, func_02182CF0, func_02182D78, func_02182DFC, func_02182E90, func_02182F40, func_02182FF8, func_021830D0, func_02183210, func_0218325C, func_021832DC, func_0218335C, func_02183490, func_021834D0, func_021834E8, func_02183560, func_021835D0, func_02183670, func_0218372C, func_021837A4, func_02183918, func_02183A24, func_02183AE4, func_02183BA4, func_02183CD4, gsiXmlUtilTagMatches, func_02183E50, func_02183EE0
 * address:  0x02181E28
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
 *   strchr                           0x02094a28 arm
 *   g_021A3F14                       0x021a3f14 data
 *   gsiXmlUtilParseName              0x02182414 arm ov009
 *   ArrayLength                      0x02184200 arm ov009
 *   ArrayAppend                      0x02184234 arm ov009
 *   gsiXmlUtilParseString            0x02182554 arm ov009
 *   gsiXmlUtilParseValue             0x0218290C arm ov009
 *   ArrayReplaceAt                   0x0218439C arm ov009
 *   strncmp                          0x020949F4 arm
 *   __ctype_mapC                     0x020A61DC data
 *   func_02181E28  0x02181e28  arm   ov009
 *   g_020A61DC     0x020a61dc  data
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *   func_020949F4                    0x020949f4 arm
 *   func_02094A28                    0x02094a28 arm
 *   func_0208CF34                    0x0208cf34 arm
 *   func_020964E0                    0x020964e0 arm
 *   func_02092364                    0x02092364 arm
 *   func_020923B0                    0x020923b0 arm
 *   g_021A3F1C                       0x021a3f1c data
 *   g_021A3F24                       0x021a3f24 data
 *   g_021A3F2C                       0x021a3f2c data
 *   g_021A3F34                       0x021a3f34 data
 *   g_021A3F3C                       0x021a3f3c data
 *   g_021A3F44                       0x021a3f44 data
 *   g_021A3F48                       0x021a3f48 data
 *   g_021A3F50                       0x021a3f50 data
 *   strlen                        0x0209477C arm
 *   gsXmlWriteOpenTag             0x021829AC arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
 *   gsXmlWriteCloseTag            0x02182A2C arm ov009
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   gsiXmlUtilWriteUnicodeString  0x021832DC arm ov009
 *   sprintf                0x02094530 arm
 *   g_021A3F54             0x021A3F54 data
 *   gsiInt64ToString       0x0217F130 arm ov009
 *   _f2d                   0x0209BD38 arm
 *   g_021A3F58             0x021A3F58 data
 *   g_021A3F5C           0x021A3F5C data
 *   B64InitEncodeStream    0x0217FC68 arm ov009
 *   B64EncodeStream        0x0217FC70 arm ov009
 *   gsiSecondsToDate       0x0217F2C8 arm ov009
 *   g_021A3F64             0x021A3F64 data
 *   func_02183210  0x02183210  arm   ov009
 *   strcpy                           0x02094798 arm
 *   _UCS2CharToUTF8String         0x021801C0 arm ov009
 *   func_0218325C  0x0218325c  arm   ov009
 *   g_021A3F84     0x021a3f84  data
 *   g_021A3F8C     0x021a3f8c  data
 *   gsirealloc                       0x0217eac8 arm
 *   ArrayNth                         0x02184208 arm
 *   strncpy                          0x02094860 arm
 *   STD_TSScanf           0x0208cf34  arm
 *   g_021A3F98            0x021a3f98  data
 *   func_0217F8B4         0x0217F8B4 arm ov009
 *   func_0217FBC8         0x0217FBC8 arm ov009
 *   atoi                  0x020964E0 arm
 *   gsiStringToInt64      0x0217F124 arm ov009
 *   func_0217F478         0x0217F478 arm ov009
 *   g_021A3FA0            0x021A3FA0 data
 *   atof                  0x02095B2C arm
 *   _d2f                  0x0209B64C arm
 */
#include "../../matched/arm9_sdk/libc/strncmp/string.h"

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (g_020A61DC[c] & 0x8))
struct GSIXmlStreamWriter;
typedef struct GSIXmlString {
    char *string;                   /* 0x00 */
    int length;                     /* 0x04 */
} GSIXmlString;

typedef struct GSIXmlElement {
    GSIXmlString name;              /* 0x00 */
    GSIXmlString value;             /* 0x08 */
    int index;                      /* 0x10 */
    int parentIndex;                /* 0x14 */
} GSIXmlElement;

typedef struct GSIXmlStreamReader {
    void *elements;                 /* 0x00 */
    void *attributes;               /* 0x04 */
    int index;                      /* 0x08 */
    int readIndex;                  /* 0x0C */
    int field10;                    /* 0x10 */
} GSIXmlStreamReader;

typedef struct GSIXmlAttribute {
    GSIXmlString name;
    GSIXmlString value;
    int elementIndex;
    int unk14;
} GSIXmlAttribute;

typedef unsigned char  u8;

typedef unsigned int   u32;

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

typedef struct {
    int f0;
    int f4;
    int f8;
} B64StreamData;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt;

extern char *strchr(const char *s, int c);
extern int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int ArrayLength(void *array);
extern void ArrayAppend(void *array, void *newElem);
extern void ArrayReplaceAt(void *array, void *newElem, int n);
extern int func_02181E28(void *, char *, int, int *);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);
extern int func_020949F4(const u8 *s1, const u8 *s2, unsigned int n);
extern char *func_02094A28(const char *s, int c);
extern int func_0208CF34(const char *src, const char *fmt, ...);
extern int func_020964E0(u32 a0);
extern void *func_02092364(void *dst, const void *src, unsigned int n);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteXmlSafeString(struct GSIXmlStreamWriter *stream, char *str);
extern int gsUnicodeStringLen(unsigned short *str);
extern int gsiXmlUtilWriteUnicodeString(struct GSIXmlStreamWriter *stream, unsigned short *str);
extern int sprintf(char *buf, const char *fmt, ...);
extern void gsiInt64ToString(char *theNumberStr, long long theNumber);
extern void B64InitEncodeStream(B64StreamData *data, unsigned char *input, int len, int type);
extern int B64EncodeStream(B64StreamData *data, char *output);
extern struct tm *gsiSecondsToDate(long *timp);
extern int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String);
extern int func_0218325C(void *, char *);
extern void *gsirealloc(void *ptr, unsigned long size);
extern void *ArrayNth(void *array, int n);
extern char *strncpy(char *dest, const char *src, unsigned int n);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern int func_0217FBC8(char *input, int encodingType);
extern int atoi(const char *s);
extern long long gsiStringToInt64(const char *s);
extern long func_0217F478(struct tm *tb);
extern double atof(const char *s);
extern int func_0217E934(char *p);
int func_02182414(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int func_02182554(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int func_0218263C(char *buffer, int *len);
int func_0218290C(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int func_021829AC(void *stream, char *namespaceName, char *tag);
int func_02182A2C(void *stream, char *namespaceName, char *tag);
int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
int func_02182B68(void *stream, char *namespaceName, char *tag, char *value);
int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value);
int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
int func_02182D78(void *stream, char *namespaceName, char *tag, long long value);
int func_02182DFC(void *stream, char *namespaceName, char *tag, float value);
int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int func_02182FF8(void *stream, char *namespaceName, char *tag, long value);
int func_021830D0(void *stream, char *namespaceName, char *tag, gsLargeInt *lint);
int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch);
int func_021832DC(struct GSIXmlStreamWriter *stream, unsigned short *str);
int func_0218335C(void *stream, char *str);
int func_021834D0(int *p);
int gsXmlMoveToNext(void *stream, char *matchtag);
int gsXmlMoveToParent(void *stream);
int func_021835D0(void *stream, char *matchtag);
int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
int func_02183918(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
int func_02183A24(void *stream, char *matchtag, int *valueOut);
int func_02183AE4(void *stream, char *matchtag, long long *valueOut);
int func_02183BA4(void *stream, char *matchtag, long *valueOut);
int func_02183CD4(void *stream, char *matchtag, float *valueOut);
int func_02183E50(void *a, int b, int *c);
int func_02183EE0(void *stream, char *matchtag);
extern char g_021A3F14[];
extern const unsigned short __ctype_mapC[];
extern const unsigned short g_020A61DC[];
extern char g_021A3F54[];
extern char g_021A3F58[];
extern char g_021A3F5C[];
extern char g_021A3F64[];
extern char g_021A3F1C[];
extern char g_021A3F24[];
extern char g_021A3F2C[];
extern char g_021A3F34[];
extern char g_021A3F3C[];
extern char g_021A3F84[];
extern char g_021A3F8C[];
extern char g_021A3F98[];
extern char g_021A3FA0[];
extern char g_021A3F44[];       /* "&#x" */
extern char g_021A3F48[];       /* "%08x" */
extern char g_021A3F50[];       /* "&#" */






static int gsiXmlUtilSkipWhiteSpace(void *unused, char *buffer, int len, int *pos)
{
    while (*pos < len)
    {
        if (strchr(g_021A3F14, buffer[*pos]) == 0)
            return 1;
        (*pos)++;
    }
    return 0;
}






#define isalnum(c) (((unsigned)(c) >= 0x80u) ? 0 : (__ctype_mapC[c] & 0x9))






/*
 * notes:    strncmp is declared by the strncmp variant of the house string.h, so the
 *           compiler keeps newElem.name.length in a register across the call (a
 *           prototype in the .c file reloads it).  The vendor keeps no local for the
 *           opening quote character or for the position saved in the closing-tag loop:
 *           the quote test reads buffer[startPos + 1] twice and the loop reuses startPos.
 *           The function ends with `return 0` after the last loop, and the two `>`
 *           checks test != first, which orders the conditional returns as the image has
 *           them.
 *
 * sdk:      gsiXmlUtilParseElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
static int func_02181E80(GSIXmlStreamReader *stream, char *buffer, int len,
                                  int *pos, int parentIndex)
{
    GSIXmlElement newElem;
    GSIXmlAttribute newAttr;
    int startPos;
    int storeElement = 1;

    gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    if (*pos >= len)
        return storeElement;

    __builtin__clear(&newElem, sizeof(newElem));
    if (buffer[*pos] != '<')
        return 0;
    if (++(*pos) >= len)
        return 0;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '!' && buffer[*pos] != '?' &&
        buffer[*pos] != '%' && buffer[*pos] != '/') {
        startPos = *pos - 1;
    } else {
        storeElement = 0;
        (*pos)++;
        startPos = *pos - 2;
    }
    if (!gsiXmlUtilParseName(stream, buffer, len, pos, &newElem.name))
        return 0;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (storeElement) {
        newElem.index = ArrayLength(stream->elements);
        newElem.parentIndex = parentIndex;
        ArrayAppend(stream->elements, &newElem);
    }

    while (*pos < len && isalnum(buffer[*pos])) {
        __builtin__clear(&newAttr, sizeof(newAttr));
        if (!gsiXmlUtilParseName(stream, buffer, len, pos, &newAttr.name))
            return 0;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] != '=')
            return 0;
        (*pos)++;
        if (!gsiXmlUtilParseString(stream, buffer, len, pos, &newAttr.value))
            return 0;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (storeElement) {
            newAttr.elementIndex = ArrayLength(stream->attributes);
            newAttr.unk14 = newElem.index;
            ArrayAppend(stream->attributes, &newAttr);
        }
    }

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if ((!isalnum(buffer[startPos + 1]) && buffer[*pos] == buffer[startPos + 1]) || buffer[*pos] == '/') {
        (*pos)++;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] != '>')
            return 0;
        (*pos)++;
        return 1;
    }
    if (buffer[*pos] != '>')
        return 0;
    (*pos)++;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '<') {
        if (!gsiXmlUtilParseValue(stream, buffer, len, pos, &newElem.value))
            return 0;
        if (storeElement)
            ArrayReplaceAt(stream->elements, &newElem, newElem.index);
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
    }

    while (*pos < len) {
        startPos = *pos;
        if (buffer[*pos] != '<')
            return 0;
        (*pos)++;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] == '/') {
            (*pos)++;
            if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
                return 0;
            if (*pos + newElem.name.length >= len)
                return 0;
            if (strncmp(newElem.name.string, &buffer[*pos], newElem.name.length) != 0)
                return 0;
            *pos += newElem.name.length;
            if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
                return 0;
            if (buffer[*pos] != '>')
                return 0;
            (*pos)++;
            return 1;
        }
        if (newElem.value.string != 0)
            return 0;
        *pos = startPos;
        if (!func_02181E80(stream, buffer, len, pos, newElem.index))
            return 0;
        gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    }
    return 0;
}




#undef isalnum



#undef isalnum


#undef isalnum

#undef isalnum

#define isalnum(c) (((c) < 0 || (c) >= 0x80) ? 0 : (g_020A61DC[c] & 0x9))





/*
 * sdk:      gsiXmlUtilParseName (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * notes: DIFF, 7 words: original loads the first char into r3 and the pointer
 *   buffer+*pos into r2, ours swaps r2/r3 (rest of the function is identical,
 *   loop shaped as while (*pos < len && strchr(...) == 0)). Tried: c var vs block
 *   var vs int, no c var, pointer temp first/after, &buffer[*pos], two ifs,
 *   declaration order, mLen store first.
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x -O4,p/-O4,s/-inline off
 * /-ipa function): 1.1p1 -O4,p is the unique best, 7 concrete bytes, unchanged by
 * every other pin.  Residue is one register pair swapped over seven instructions
 * (+0038..+0088): image keeps the character in r3 and `buffer + *pos` in r2, this
 * build has them the other way round
 *   +0038  image `ldrsb r3, [sl, r0]`  | ours `ldrsb r2, [sl, r0]`.
 * Measured flat: `&buffer[*pos]` as the mData operand, a named `char *` pointer
 * local in three declaration positions, an `int idx = *pos` local, mLen written
 * before mData, the guard split into two ifs, and a `char *` cast on the base
 * (that one re-colours the entry block, 67 bytes).
 */
int func_02182414(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
{
    int haveNamespace = 0;
    char c;

    if (!func_02181E28(stream, buffer, len, pos))
        return 0;
    if (*pos >= len)
        return 0;
    c = buffer[*pos];
    if (!isalnum(c) || isdigit(buffer[*pos]))
        return 0;
    strOut->string = buffer + *pos;
    strOut->length = 1;
    (*pos)++;
    while (*pos < len && strchr(g_021A3F14, c = buffer[*pos]) == 0) {
        if (c == ':') {
            if (haveNamespace)
                return 0;
            haveNamespace = 1;
        } else if (c != '_' && c != '-' && !isalnum(c)) {
            return 1;
        }
        strOut->length++;
        (*pos)++;
    }
    return 1;
}











/*
 * sdk:      gsiXmlUtilParseString (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * Parses one quoted string literal out of an XML buffer: consumes the opening
 * quote, scans to the matching one, and decodes the body in place.
 *
 * Two spelling details carry the whole 232 bytes:
 *
 *  1. The scan loop is a `while` with the SAME test written as an explicit `if`
 *     in front of it.  mwcc rotates the while into a bottom-edge loop and keeps
 *     the `if` as well, which is why the image tests `buffer[*pos] != startCh`
 *     twice (`bne` into the loop at +0068 and a same-flags `beq` out of it at
 *     +0084).  Without the `if` the function is 8 bytes short.
 *  2. `strStart` is taken BEFORE `strOut->length = 0`, so the register that the
 *     `(*pos)++` already produced stays live for the `add r4, r8, r2` and the
 *     two length/quote tests re-read `*pos` into a fresh register (`ldr r3,
 *     [r6]` / `ldr r3, [r6]` in the loop).  With the store first the compiler
 *     reloads into the same register and both tests read through the computed
 *     strStart pointer instead, which is 7 register-field bytes out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02182554.c \
 *       --func func_02182554 --addr 0x02182554 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
int func_02182554(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
{
    char *strStart;
    char startCh;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    startCh = buffer[*pos];
    if (startCh != '"' && startCh != '\'')
        return 0;
    (*pos)++;
    strStart = &buffer[*pos];
    strOut->length = 0;
    if (*pos >= len)
        return 0;
    if (buffer[*pos] == startCh)
    {
        strOut->string = strStart;
        (*pos)++;
        return 1;
    }
    if (buffer[*pos] != startCh)
    {
        while (buffer[*pos] != startCh)
        {
            if (*pos >= len)
                return 0;
            (*pos)++;
            strOut->length++;
        }
    }
    (*pos)++;
    if (!gsiXmlUtilDecodeString(strStart, &strOut->length))
        return 0;
    strOut->string = strStart;
    return 1;
}





/*
 * sdk:      gsiXmlUtilDecodeString (gsxml.o, static)
 *
 * notes:    closed by compiling the vendor's own body from the GameSpy
 *           upstream (scratch/U2/gs/src/GameSpy/common/gsXML.c). The
 *           three-way register rotation that parked this row (image
 *           readPos r4, len r5, buffer r6) is fixed by the vendor's
 *           `int charsToRemove = 0;` declared *inside* the loop with an
 *           initialiser, plus the initialised locals (`char ch = ' ';`,
 *           `int i = 0;`, `unsigned int mask = 0xFF000000;`) and the
 *           `buffer[readPos++] = ...` post-increment form. The earlier
 *           draft hoisted charsToRemove out of the loop uninitialised,
 *           which lengthened its live range and rotated r4/r5/r6.
 *           The `%08x` vs `%x` string spelling is irrelevant (ABS32).
 */
int func_0218263C(char *buffer, int *len)
{
	int readPos = 0;

	while(readPos < *len)
	{
		int charsToRemove = 0;

		if (buffer[readPos] != '&')
		{
			readPos++;
			continue;
		}

		if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F1C, 5)==0)
		{
			buffer[readPos++] = '&';
			charsToRemove = 5-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F24, 6)==0)
		{
			buffer[readPos++] = '"';
			charsToRemove = 6-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F2C, 6)==0)
		{
			buffer[readPos++] = '\'';
			charsToRemove = 6-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F34, 4)==0)
		{
			buffer[readPos++] = '<';
			charsToRemove = 4-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F3C, 4)==0)
		{
			buffer[readPos++] = '>';
			charsToRemove = 4-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F44, 3)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = func_02094A28(&buffer[readPos+3], ';');
			if (digitEnd == 0)
				return 0;
			if (digitEnd - &buffer[readPos+3] > 8)
				return 0;

			func_0208CF34(&buffer[readPos+3], g_021A3F48, &digitValue);

			for (i=0; i < 4; i++)
			{
				ch = (char)((digitValue & mask) >> ((3-i)*8));
				if (haveWritten || ch != 0x00)
				{
					buffer[readPos++] = ch;
					haveWritten = 1;
				}
				mask = mask >> 8;
			}

			charsToRemove = digitEnd - &buffer[readPos] + 1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F50, 2)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = func_02094A28(&buffer[readPos+2], ';');
			if (digitEnd == 0)
				return 0;

			digitValue = (unsigned int)func_020964E0((u32)(&buffer[readPos+2]));

			for (i=0; i < 4; i++)
			{
				ch = (char)((digitValue & mask) >> ((3-i)*8));
				if (haveWritten || ch != 0x00)
				{
					buffer[readPos++] = ch;
					haveWritten = 1;
				}
				mask = mask >> 8;
			}

			charsToRemove = digitEnd - &buffer[readPos] + 1;
		}
		else
			return 0;

		func_02092364(&buffer[readPos], &buffer[readPos+charsToRemove], (unsigned int)(*len-(readPos+charsToRemove)));
		func_020923B0(&buffer[*len-charsToRemove], ' ', (unsigned int)charsToRemove);
		(*len) -= charsToRemove;
	}

	return 1;
}





/*
 * sdk:      gsiXmlUtilParseValue (gsxml)
 */
int func_0218290C(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
{
    char *strStart = 0;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '<')
    {
        strStart = &buffer[*pos];
        strOut->string = strStart;
    }
    while (*pos < len)
    {
        if (buffer[*pos] == '<')
            return gsiXmlUtilDecodeString(strStart, &strOut->length) != 0;
        (*pos)++;
        strOut->length++;
    }
    return 0;
}





/*
 * sdk:      gsXmlWriteOpenTag (gsxml)
 */
int func_021829AC(void *stream, char *namespaceName, char *tag)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    if (!(gsiXmlUtilWriteChar(writer, '<')
        && gsiXmlUtilWriteString(writer, namespaceName)
        && gsiXmlUtilWriteChar(writer, ':')
        && gsiXmlUtilWriteString(writer, tag)
        && gsiXmlUtilWriteChar(writer, '>')))
        return 0;
    return 1;
}





/*
 * sdk:      gsXmlWriteCloseTag (gsxml)
 */
int func_02182A2C(void *stream, char *namespaceName, char *tag)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    if (!(gsiXmlUtilWriteChar(writer, '<')
        && gsiXmlUtilWriteChar(writer, '/')
        && gsiXmlUtilWriteString(writer, namespaceName)
        && gsiXmlUtilWriteChar(writer, ':')
        && gsiXmlUtilWriteString(writer, tag)
        && gsiXmlUtilWriteChar(writer, '>')))
        return 0;
    return 1;
}





/*
 * sdk:      gsXmlWriteAsciiStringElement (gsxml)
 */
int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = strlen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (((unsigned char *)value)[i] < 0x20 && ((unsigned char *)value)[i] != 9 && ((unsigned char *)value)[i] != 10 && ((unsigned char *)value)[i] != 13)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteXmlSafeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteStringElement (gsxml)
 */
int func_02182B68(void *stream, char *namespaceName, char *tag, char *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = strlen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (((unsigned char *)value)[i] < 0x20 && ((unsigned char *)value)[i] != 9 && ((unsigned char *)value)[i] != 10 && ((unsigned char *)value)[i] != 13)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteXmlSafeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteUnicodeStringElement (gsxml)
 */
int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = gsUnicodeStringLen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (value[i] < 0x20)
        {
            if (value[i] != 9 && value[i] != 10 && value[i] != 13)
                return 0;
        }
        else if (value[i] > 0xD7FF && value[i] < 0xE000)
            return 0;
        else if (value[i] > 0xFFFD)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteUnicodeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteIntElement (gsxml)
 */
int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value)
{
    char buf[32];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    sprintf(buf, g_021A3F54, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteInt64Element (gsxml)
 */
int func_02182D78(void *stream, char *namespaceName, char *tag, long long value)
{
    char buf[33];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    gsiInt64ToString(buf, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteFloatElement (gsxml)
 */
int func_02182DFC(void *stream, char *namespaceName, char *tag, float value)
{
    char buf[32];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    sprintf(buf, g_021A3F58, (double)value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteHexBinaryElement (gsxml)
 */
int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int pos = 0;
    char hex[3];

    hex[2] = 0;
    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    for (pos = 0; pos < len; )
    {
        sprintf(hex, g_021A3F5C, data[pos]);
        pos++;
        if (!gsiXmlUtilWriteChar(writer, hex[0]))
            return 0;
        if (!gsiXmlUtilWriteChar(writer, hex[1]))
            return 0;
    }
    if (!gsXmlWriteCloseTag(writer, namespaceName, tag))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteBase64BinaryElement (gsxml)
 */
int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    B64StreamData streamData;
    char b64[5];

    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    B64InitEncodeStream(&streamData, data, len, 0);
    while (B64EncodeStream(&streamData, b64))
    {
        b64[4] = 0;
        if (!gsiXmlUtilWriteString(writer, b64))
            return 0;
    }
    if (!gsXmlWriteCloseTag(writer, namespaceName, tag))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteDateTimeElement (gsxml)
 */
int func_02182FF8(void *stream, char *namespaceName, char *tag, long value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    char timeString[21];
    struct tm *timePtr;

    timePtr = gsiSecondsToDate(&value);
    sprintf(timeString, g_021A3F64, timePtr->tm_year + 1900, timePtr->tm_mon + 1, timePtr->tm_mday, timePtr->tm_hour, timePtr->tm_min, timePtr->tm_sec);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, timeString)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}






/*
 * sdk:      gsXmlWriteLargeIntElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
int func_021830D0(void *stream, char *namespaceName, char *tag, gsLargeInt *lint)
{
    struct GSIXmlStreamWriter *writer;
    unsigned int *readBuf;
    int readPos;
    int first = 1;
    char hex[3];
    unsigned int i;

    readPos = lint->mLength - 1;
    readBuf = lint->mData;
    if (!func_021829AC(stream, namespaceName, tag))
        return 0;
    while (readPos >= 0 && readBuf[readPos] == 0)
        readPos--;
    writer = (struct GSIXmlStreamWriter *)stream;
    for (; readPos >= 0; readPos--) {
        i = 0;
        if (first) {
            while (i < 4) {
                if ((lint->mData[readPos] >> ((3 - i) * 8)) & 0xff)
                    break;
                i++;
            }
            first = 0;
        }
        if (i < 4) {
            for (; i < 4; i++) {
                sprintf(hex, g_021A3F5C, (lint->mData[readPos] >> ((3 - i) * 8)) & 0xff);
                if (!gsiXmlUtilWriteChar(writer, hex[0]))
                    return 0;
                if (!gsiXmlUtilWriteChar(writer, hex[1]))
                    return 0;
            }
        }
    }
    if (!func_02182A2C(stream, namespaceName, tag))
        return 0;
    return 1;
}






int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch)
{
    if (stream->position >= stream->capacity)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    stream->buffer[stream->position] = ch;
    stream->position++;
    return 1;
}






static int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str)
{
    int strLen;

    strLen = strlen(str);
    if (strLen == 0)
        return 1;
    while (stream->capacity - stream->position <= strLen)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    strcpy(stream->buffer + stream->position, str);
    stream->position += strLen;
    return 1;
}





/*
 * sdk:      gsiXmlUtilWriteUnicodeString (gsxml)
 */
int func_021832DC(struct GSIXmlStreamWriter *stream, unsigned short *str)
{
    int strLen;
    int pos;
    int utf8Len;
    char utf8String[4] = {0, 0, 0, 0};

    strLen = gsUnicodeStringLen(str);
    utf8String[3] = 0;
    for (pos = 0; pos < strLen; pos++)
    {
        utf8Len = _UCS2CharToUTF8String(str[pos], utf8String);
        utf8String[utf8Len] = 0;
        if (!gsiXmlUtilWriteXmlSafeString(stream, utf8String))
            return 0;
    }
    return 1;
}





/*
 * sdk:      gsiXmlUtilWriteXmlSafeString (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
int func_0218335C(void *stream, char *str)
{
    int strLen;
    int pos;
    int result;
    char numeric[7];

    strLen = strlen(str);
    for (pos = 0; pos < strLen; pos++) {
        char c = str[pos];
        if (c == '&') {
            result = func_0218325C(stream, g_021A3F1C);
        } else if (c == '\'') {
            result = func_0218325C(stream, g_021A3F2C);
        } else if (c == '"') {
            result = func_0218325C(stream, g_021A3F24);
        } else if (c == '<') {
            result = func_0218325C(stream, g_021A3F34);
        } else if (c == '>') {
            result = func_0218325C(stream, g_021A3F3C);
        } else if (c == ' ') {
            result = func_0218325C(stream, g_021A3F84);
        } else if (c < ' ' || (unsigned char)c > 0x7f) {
            sprintf(numeric, g_021A3F8C, (unsigned char)c);
            numeric[6] = 0;
            result = func_0218325C(stream, numeric);
        } else {
            result = gsiXmlUtilWriteChar(stream, c);
        }
        if (!result)
            return 0;
    }
    return 1;
}





static int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter *stream)
{
    int newCapacity;
    void *newBuf;

    newCapacity = stream->capacity + 0x400;
    newBuf = gsirealloc(stream->buffer, newCapacity);
    if (newBuf == 0)
        return 0;
    stream->capacity = newCapacity;
    if (newBuf != stream->buffer)
        stream->buffer = newBuf;
    return 1;
}




/*
 * Fills the three words at +8, +0xc and +0x10 with -1 and reports success.
 */
int func_021834D0(int *p)
{
    p[2] = -1;
    p[3] = -1;
    p[4] = -1;
    return 1;
}





int gsXmlMoveToNext(void *stream, char *matchtag)
{
    GSIXmlStreamReader * reader = (GSIXmlStreamReader *)stream;
    int i = reader->index + 1;

    while (i < ArrayLength(reader->elements))
    {
        if (gsiXmlUtilTagMatches(matchtag, ArrayNth(reader->elements, i)))
        {
            reader->index = i;
            reader->readIndex = -1;
            reader->field10 = -1;
            return 1;
        }
        i++;
    }
    return 0;
}





int gsXmlMoveToParent(void *stream)
{
    GSIXmlStreamReader * reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement * elem;
    int result;
    int idx;

    idx = reader->index;
    if (idx >= ArrayLength(reader->elements) || idx == -1)
        return 0;
    elem = (GSIXmlElement *)ArrayNth(reader->elements, idx);
    idx = elem->parentIndex;
    if (idx == -1)
        return 0;
    if (idx >= ArrayLength(reader->elements))
        result = 0;
    else
    {
        reader->index = idx;
        reader->readIndex = -1;
        reader->field10 = -1;
        result = 1;
    }
    return result;
}





/*
 * sdk:      gsXmlMoveToChild (gsxml)
 */
int func_021835D0(void *stream, char *matchtag)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchElem;
    int i;

    for (i = reader->index + 1; i < ArrayLength(reader->elements); i++)
    {
        searchElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchElem))
        {
            reader->index = i;
            reader->readIndex = -1;
            reader->field10 = -1;
            return 1;
        }
        if (searchElem->parentIndex < reader->index)
            return 0;
    }
    return 0;
}





int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut)
{
    GSIXmlStreamReader * reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement * searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if ((searchValueElem->parentIndex == reader->index) &&
            gsiXmlUtilTagMatches(matchtag, (GSIXmlString *)searchValueElem))
        {
            reader->readIndex = i;
            *valueOut = searchValueElem->value.string;
            *lenOut = searchValueElem->value.length;
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen)
{
    char * strValue = 0;
    int strLen = 0;
    int count;

    if (gsXmlReadChildAsString(stream, matchtag, &strValue, &strLen) == 0)
    {
        valueOut[0] = 0;
        return 0;
    }
    count = (maxLen < strLen) ? maxLen : strLen;
    strncpy(valueOut, strValue, count);
    count = (maxLen - 1 < strLen) ? maxLen - 1 : strLen;
    valueOut[count] = 0;
    return 1;
}






/*
 * sdk:      gsXmlReadChildAsHexBinary (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    int i;
    unsigned int temp;
    int writepos;
    int readpos;
    int bytesleft;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements)) {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem)) {
            writepos = 0;
            temp = 0;
            readpos = 0;
            bytesleft = maxLen * 2;
            if (searchValueElem->value.length <= bytesleft)
                bytesleft = searchValueElem->value.length;
            if (searchValueElem->value.length == 0 || searchValueElem->value.string == 0) {
                valueOut[0] = 0;
                *lenOut = 0;
                return 1;
            }
            if (valueOut == 0) {
                *lenOut = searchValueElem->value.length / 2;
                return 1;
            }
            while (bytesleft > 1) {
                STD_TSScanf(searchValueElem->value.string + readpos, g_021A3F5C, &temp);
                valueOut[writepos] = temp;
                bytesleft -= 2;
                readpos += 2;
                writepos++;
            }
            if (bytesleft == 1) {
                STD_TSScanf(searchValueElem->value.string + readpos, g_021A3F98, &temp);
                valueOut[writepos] = temp;
                writepos++;
            }
            if (lenOut != 0)
                *lenOut = writepos;
            reader->readIndex = i;
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






/*
 * sdk:      gsXmlReadChildAsBase64Binary (libdwcgscommon.TWL.HYB.a(gsxml.o))
 */
int func_02183918(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            if (valueOut != 0)
            {
                reader->readIndex = i;
                if (searchValueElem->value.string == 0)
                    *lenOut = 0;
                else
                    func_0217F8B4(searchValueElem->value.string, (char *)valueOut, searchValueElem->value.length, lenOut, 0);
            }
            else
            {
                if (searchValueElem->value.string == 0)
                    *lenOut = 0;
                else
                    *lenOut = func_0217FBC8(searchValueElem->value.string, 0);
            }
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






/*
 * sdk:      gsXmlReadChildAsInt (gsxml)
 */
int func_02183A24(void *stream, char *matchtag, int *valueOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value.string == 0)
                return 0;
            *valueOut = atoi(searchValueElem->value.string);
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






/*
 * sdk:      gsXmlReadChildAsInt64 (gsxml)
 */
int func_02183AE4(void *stream, char *matchtag, long long *valueOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value.string == 0)
                return 0;
            *valueOut = gsiStringToInt64(searchValueElem->value.string);
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






/*
 * sdk:      gsXmlReadChildAsDateTimeElement (libdwcgscommon.TWL.HYB.a(gsxml.o))
 */
int func_02183BA4(void *stream, char *matchtag, long *valueOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    struct tm timePtr;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value.string == 0)
                return 0;
            func_0208CF34(searchValueElem->value.string, g_021A3FA0, &timePtr.tm_year, &timePtr.tm_mon,
                          &timePtr.tm_mday, &timePtr.tm_hour, &timePtr.tm_min, &timePtr.tm_sec);
            timePtr.tm_year -= 1900;
            timePtr.tm_mon -= 1;
            timePtr.tm_isdst = -1;
            *valueOut = func_0217F478(&timePtr);
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






/*
 * sdk:      gsXmlReadChildAsFloat (gsxml)
 *
 * note: _d2f (0x0209B64C) is a recorded MSL runtime row, matched in src/matched/arm9/d2f.c
 */
int func_02183CD4(void *stream, char *matchtag, float *valueOut)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parentIndex == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value.string == 0)
                return 0;
            *valueOut = (float)atof(searchValueElem->value.string);
            return 1;
        }
        if (searchValueElem->parentIndex < reader->index)
            return 0;
        i++;
    }
    return 0;
}






static int gsiXmlUtilTagMatches(char *matchtag, GSIXmlString *xmlstr)
{
    char * matchNoNamespace;
    char * string;
    int xmlNamespacePos = 0;
    int matchTagLen;

    if (matchtag == 0)
        return 1;
    if (*(matchtag + strlen(matchtag) - 1) == ':')
        return 0;

    matchNoNamespace = strchr(matchtag, ':');
    if (matchNoNamespace == 0)
        matchNoNamespace = matchtag;

    while ((xmlNamespacePos < xmlstr->length) && ((unsigned char)xmlstr->string[xmlNamespacePos] != ':'))
        xmlNamespacePos++;
    if (xmlNamespacePos == xmlstr->length)
        xmlNamespacePos = 0;
    else
        xmlNamespacePos++;

    string = xmlstr->string;
    matchTagLen = xmlstr->length - xmlNamespacePos;
    if (matchTagLen <= strlen(matchNoNamespace))
        matchTagLen = strlen(matchNoNamespace);

    return (strncmp(matchNoNamespace, (string + xmlNamespacePos), matchTagLen) == 0);
}



/*
 * Clear 0x104 bytes at `c`, then fill `c+4` with up to 0x200 bytes through
 * func_021837A4; the byte count it reports is rounded up to a word count and
 * stored at c[0].  Returns 1 when the object validates, 0 when the fill loop
 * reports nothing produced.
 */
int func_02183E50(void *a, int b, int *c)
{
    u32 n = 0;
    u32 k;

    func_020923B0(c, 0, 0x104);
    if (func_021837A4(a, (char *)b, (unsigned char *)(c + 1), 0x200, (int *)(&n)) == 0)
        return 0;

    k = n >> 2;
    c[0] = k;
    if (n & 3)
        c[0] = k + 1;

    if (func_0217E934((char *)c) == 0)
        return 0;
    return 1;
}



int func_02183EE0(void *stream, char *matchtag)
{
    GSIXmlStreamReader *reader = (GSIXmlStreamReader *)stream;
    GSIXmlElement *searchElem;
    int i;
    int count = 0;

    for (i = reader->index + 1; i < ArrayLength(reader->elements); i++)
    {
        searchElem = (GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchElem->parentIndex == reader->index)
        {
            if (matchtag == 0 || gsiXmlUtilTagMatches(matchtag, &searchElem->name))
                count++;
        }
        else if (searchElem->parentIndex < reader->index)
            break;
    }
    return count;
}
