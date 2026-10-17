/*
 * file:     gsxml.c
 * unit:     yes
 * function: gsUnicodeStringLen, gsXmlCreateStreamWriter, gsXmlCreateStreamReader, gsXmlParseBuffer, gsXmlFreeWriter, gsXmlFreeReader, gsXmlResetReader, gsXmlCloseWriter, gsiXmlUtilElementFree, gsiXmlUtilAttributeFree, gsXmlWriterGetData, gsXmlWriterGetDataLength, gsiXmlUtilSkipWhiteSpace, gsiXmlUtilParseElement, gsiXmlUtilParseName, gsiXmlUtilParseString, gsiXmlUtilDecodeString, gsiXmlUtilParseValue, gsXmlWriteOpenTag, gsXmlWriteCloseTag, gsXmlWriteStringElement, gsXmlWriteAsciiStringElement, gsXmlWriteUnicodeStringElement, gsXmlWriteIntElement, gsXmlWriteInt64Element, gsXmlWriteFloatElement, gsXmlWriteHexBinaryElement, gsXmlWriteBase64BinaryElement, gsXmlWriteDateTimeElement, gsXmlWriteLargeIntElement, gsiXmlUtilWriteChar, gsiXmlUtilWriteString, gsiXmlUtilWriteUnicodeString, gsiXmlUtilWriteXmlSafeString, gsiXmlUtilGrowBuffer, gsXmlMoveToStart, gsXmlMoveToNext, gsXmlMoveToParent, gsXmlMoveToChild, gsXmlReadChildAsString, gsXmlReadChildAsStringNT, gsXmlReadChildAsHexBinary, gsXmlReadChildAsBase64Binary, gsXmlReadChildAsInt, gsXmlReadChildAsInt64, gsXmlReadChildAsDateTimeElement, gsXmlReadChildAsFloat, gsiXmlUtilTagMatches, gsXmlReadChildAsLargeInt, gsXmlCountChildren
 * address:  0x0218198C
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
 *   gsimalloc                    0x0217eab0 arm  ov009
 *   gsDebugFormat                    0x0217d254 arm  ov009
 *   strlen                    0x0209477c arm
 *   gsiXmlUtilWriteString                    0x0218325c arm  ov009
 *   gsifree                    0x0217eae0 arm  ov009
 *   gsiXmlUtilWriteChar                    0x02183210 arm  ov009
 *   gGsXmlOomWriterFormat                       0x021a3de4 data
 *   gGsXmlNamespacePrefix                       0x021a3e20 data
 *   gGsXmlSoapDefaultNamespaces                       0x021a3d0c data
 *   gGsXmlSoapEnvelopeStart                       0x021a3e28 data
 *   gGsXmlSoapBodyStart                       0x021a3e64 data
 *   gsimalloc                0x0217EAB0 arm ov009
 *   gsDebugFormat            0x0217D254 arm ov009
 *   ArrayNew                 0x02184144 arm ov009
 *   gsifree                  0x0217EAE0 arm ov009
 *   ArrayFree                0x021841B0 arm ov009
 *   gsXmlMoveToStart         0x021834D0 arm ov009
 *   gGsXmlOomStreamFormat               0x021A3E74 data
 *   gsiXmlUtilElementFree    0x02181E10 arm ov009
 *   gGsXmlOomElementArrayFormat               0x021A3EA8 data
 *   gsiXmlUtilAttributeFree  0x02181E14 arm ov009
 *   gsiXmlUtilParseElement           0x02181e80 arm
 *   ArrayClear                       0x0218452c arm
 *   gGsXmlSoapEnvelopeEnd                       0x021a3eec data
 *   strchr                           0x02094a28 arm
 *   gGsXmlWhiteSpaceChars                       0x021a3f14 data
 *   gsiXmlUtilParseName              0x02182414 arm ov009
 *   ArrayLength                      0x02184200 arm ov009
 *   ArrayAppend                      0x02184234 arm ov009
 *   gsiXmlUtilParseString            0x02182554 arm ov009
 *   gsiXmlUtilParseValue             0x0218290C arm ov009
 *   ArrayReplaceAt                   0x0218439C arm ov009
 *   strncmp                          0x020949F4 arm
 *   __ctype_mapC                     0x020A61DC data
 *   gsiXmlUtilSkipWhiteSpace  0x02181e28  arm   ov009
 *   gCtypeMap     0x020a61dc  data
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *   strncmp                    0x020949f4 arm
 *   strchr                    0x02094a28 arm
 *   STD_TSScanf                    0x0208cf34 arm
 *   atoi                    0x020964e0 arm
 *   memmove                    0x02092364 arm
 *   MSL_C_LIB_MemsetPtr                    0x020923b0 arm
 *   gGsXmlEntityAmp                       0x021a3f1c data
 *   gGsXmlEntityQuot                       0x021a3f24 data
 *   gGsXmlEntityApos                       0x021a3f2c data
 *   gGsXmlEntityLt                       0x021a3f34 data
 *   gGsXmlEntityGt                       0x021a3f3c data
 *   gGsXmlEntityHexPrefix                       0x021a3f44 data
 *   gGsXmlHex8Format                       0x021a3f48 data
 *   gGsXmlEntityDecPrefix                       0x021a3f50 data
 *   strlen                        0x0209477C arm
 *   gsXmlWriteOpenTag             0x021829AC arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
 *   gsXmlWriteCloseTag            0x02182A2C arm ov009
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   gsiXmlUtilWriteUnicodeString  0x021832DC arm ov009
 *   sprintf                0x02094530 arm
 *   gGsXmlIntFormat             0x021A3F54 data
 *   gsiInt64ToString       0x0217F130 arm ov009
 *   _f2d                   0x0209BD38 arm
 *   gGsXmlFloatFormat             0x021A3F58 data
 *   gGsXmlHex2Format           0x021A3F5C data
 *   B64InitEncodeStream    0x0217FC68 arm ov009
 *   B64EncodeStream        0x0217FC70 arm ov009
 *   gsiSecondsToDate       0x0217F2C8 arm ov009
 *   gGsXmlDateTimeFormat             0x021A3F64 data
 *   strcpy                           0x02094798 arm
 *   _UCS2CharToUTF8String         0x021801C0 arm ov009
 *   gGsXmlEntitySpace     0x021a3f84  data
 *   gGsXmlEntityByteFormat     0x021a3f8c  data
 *   gsirealloc                       0x0217eac8 arm
 *   ArrayNth                         0x02184208 arm
 *   strncpy                          0x02094860 arm
 *   STD_TSScanf           0x0208cf34  arm
 *   gGsXmlHex1Format            0x021a3f98  data
 *   B64Decode         0x0217F8B4 arm ov009
 *   B64DecodeLen         0x0217FBC8 arm ov009
 *   atoi                  0x020964E0 arm
 *   gsiStringToInt64      0x0217F124 arm ov009
 *   gsiDateToSeconds         0x0217F478 arm ov009
 *   gGsXmlDateTimeFormatNoZ            0x021A3FA0 data
 *   atof                  0x02095B2C arm
 *   _d2f                  0x0209B64C arm
 *   gsLargeIntReverseBytes  0x0217E934  arm
 */
#include "../../matched/arm9_sdk/libc/strncmp/string.h"

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (gCtypeMap[c] & 0x8))

typedef unsigned char  u8;



typedef struct GSIXmlStreamWriter {
    char *buffer;                   /* 0x00 */
    int length;                     /* 0x04 */
    int capacity;                   /* 0x08 */
    int closed;                     /* 0x0C */
} GSIXmlStreamWriter;

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
    int readAttributeIndex;         /* 0x10 */
} GSIXmlStreamReader;

typedef struct GSIXmlAttribute {
    GSIXmlString name;
    GSIXmlString value;
    int elementIndex;
    int owningElementIndex;
} GSIXmlAttribute;

typedef unsigned int   u32;


typedef struct {
    char *data;
    int len;
    int mode;
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

extern void *gsimalloc(unsigned long size);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
static int gsiXmlUtilWriteString(GSIXmlStreamWriter *stream, const char *str);
extern void gsifree(void *ptr);
extern int gsiXmlUtilWriteChar(GSIXmlStreamWriter *stream, char ch);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ArrayFree(void *array);
extern int gsXmlMoveToStart(void *stream);
extern void gsiXmlUtilElementFree(void *elem);
extern void gsiXmlUtilAttributeFree(void *elem);
static int gsiXmlUtilParseElement(GSIXmlStreamReader *stream, char *buffer, int len, int *pos, int parentIndex);
extern void ArrayClear(void *array);
extern int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int ArrayLength(void *array);
extern void ArrayAppend(void *array, void *newElem);
extern void ArrayReplaceAt(void *array, void *newElem, int n);
extern int gsiXmlUtilSkipWhiteSpace(void *, char *, int, int *);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);
extern int STD_TSScanf(const char *src, const char *fmt, ...);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned int n);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteXmlSafeString(void *stream, char *str);
extern int gsUnicodeStringLen(const unsigned short *str);
extern int gsiXmlUtilWriteUnicodeString(GSIXmlStreamWriter *stream, unsigned short *str);
extern int sprintf(char *buf, const char *fmt, ...);
extern void gsiInt64ToString(char *theNumberStr, long long theNumber);
extern void B64InitEncodeStream(B64StreamData *data, unsigned char *input, int len, int type);
extern int B64EncodeStream(B64StreamData *data, char *output);
extern struct tm *gsiSecondsToDate(long *timp);
extern int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String);
extern void *gsirealloc(void *ptr, unsigned long size);
extern void *ArrayNth(void *array, int n);
extern void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern int B64DecodeLen(char *input, int encodingType);
extern long long gsiStringToInt64(const char *s);
extern long gsiDateToSeconds(struct tm *tb);
extern double atof(const char *s);
extern int gsLargeIntReverseBytes(char *p);
void *gsXmlCreateStreamWriter(const char **namespaces, int count);
void *gsXmlCreateStreamReader(void);
int gsXmlParseBuffer(void *stream, char *data, int len);
void gsXmlFreeWriter(void **writerRef);
void gsXmlFreeReader(void *stream);
void gsXmlResetReader(void *stream);
int gsXmlCloseWriter(void *stream);
char *gsXmlWriterGetData(void *stream);
int gsXmlWriterGetDataLength(void *stream);
int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
int gsXmlWriteAsciiStringElement(void *stream, char *namespaceName, char *tag, char *value);
int gsXmlWriteUnicodeStringElement(void *stream, char *namespaceName, char *tag, unsigned short *value);
int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
int gsXmlWriteInt64Element(void *stream, char *namespaceName, char *tag, long long value);
int gsXmlWriteFloatElement(void *stream, char *namespaceName, char *tag, float value);
int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int gsXmlWriteBase64BinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value);
int gsXmlWriteLargeIntElement(void *stream, char *namespaceName, char *tag, gsLargeInt *lint);
int gsXmlMoveToNext(void *stream, char *matchtag);
int gsXmlMoveToParent(void *stream);
int gsXmlMoveToChild(void *stream, char *matchtag);
int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
int gsXmlReadChildAsHexBinary(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
int gsXmlReadChildAsBase64Binary(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
int gsXmlReadChildAsInt64(void *stream, char *matchtag, long long *valueOut);
int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut);
int gsXmlReadChildAsFloat(void *stream, char *matchtag, float *valueOut);
int gsXmlReadChildAsLargeInt(void *stream, char *matchtag, int *lintData);
int gsXmlCountChildren(void *stream, char *matchtag);
extern char gGsXmlOomWriterFormat[];
extern char gGsXmlNamespacePrefix[];
extern const char *gGsXmlSoapDefaultNamespaces[4];   /* GS_XML_SOAP_DEFAULT_NAMESPACES */
extern char gGsXmlSoapEnvelopeStart[];
extern char gGsXmlSoapBodyStart[];
extern char gGsXmlOomStreamFormat[];
extern char gGsXmlOomElementArrayFormat[];
extern char gGsXmlSoapEnvelopeEnd[];
extern char gGsXmlWhiteSpaceChars[];
extern const unsigned short __ctype_mapC[];
extern const unsigned short gCtypeMap[];
extern char gGsXmlIntFormat[];
extern char gGsXmlFloatFormat[];
extern char gGsXmlHex2Format[];
extern char gGsXmlDateTimeFormat[];
extern char gGsXmlEntityAmp[];
extern char gGsXmlEntityQuot[];
extern char gGsXmlEntityApos[];
extern char gGsXmlEntityLt[];
extern char gGsXmlEntityGt[];
extern char gGsXmlEntitySpace[];
extern char gGsXmlEntityByteFormat[];
extern char gGsXmlHex1Format[];
extern char gGsXmlDateTimeFormatNoZ[];
extern char gGsXmlEntityHexPrefix[];       /* "&#x" */
extern char gGsXmlHex8Format[];       /* "%08x" */
extern char gGsXmlEntityDecPrefix[];       /* "&#" */



extern int strncmp(const char *s1, const char *s2, unsigned long n);
extern const char *strncpy(const char *dest, const char *src, unsigned int n);
extern char *strchr(const char *s, int c);
extern int atoi(const char *s);
extern void *memmove(void *dst, const void *src, unsigned int n);
/*
 * Number of halfwords before the terminating zero, less one.
 */
int gsUnicodeStringLen(const unsigned short *str)
{
    const unsigned short *cursor = str;
    unsigned short ch;

    do {
        ch = *cursor++;
    } while (ch != 0);
    return (int)((const char *)cursor - (const char *)str) / 2 - 1;
}




/*
 * sdk:      gsXmlCreateStreamWriter (gsxml.o)
 */
void *gsXmlCreateStreamWriter(const char **namespaces, int count)
{
    GSIXmlStreamWriter *newStream;
    int initialCapacity = 1024;
    int namespaceLen = 0;
    int i;

    newStream = gsimalloc(sizeof(GSIXmlStreamWriter));
    if (newStream == 0) {
        gsDebugFormat(0xc, (char *)2, 1, gGsXmlOomWriterFormat, sizeof(GSIXmlStreamWriter));
        return 0;
    }

    for (i = 0; i < 4; i++) {
        namespaceLen += strlen((const char *)gGsXmlNamespacePrefix) + 1;
        namespaceLen += strlen((const char *)gGsXmlSoapDefaultNamespaces[i]);
    }
    for (i = 0; i < count; i++) {
        namespaceLen += strlen((const char *)gGsXmlNamespacePrefix) + 1;
        namespaceLen += strlen((const char *)namespaces[i]);
    }
    while (initialCapacity < namespaceLen)
        initialCapacity += 1024;

    newStream->buffer = gsimalloc(initialCapacity);
    if (newStream->buffer == 0) {
        gsDebugFormat(0xc, (char *)2, 1, gGsXmlOomWriterFormat, initialCapacity);
        return 0;
    }
    newStream->capacity = initialCapacity;
    newStream->length = 0;
    newStream->buffer[0] = '\0';
    newStream->closed = 0;

    if (!gsiXmlUtilWriteString(newStream, gGsXmlSoapEnvelopeStart)) {
        gsifree(newStream->buffer);
        gsifree(newStream);
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (!gsiXmlUtilWriteChar(newStream, ' ') ||
            !gsiXmlUtilWriteString(newStream, gGsXmlNamespacePrefix) ||
            !gsiXmlUtilWriteString(newStream, gGsXmlSoapDefaultNamespaces[i])) {
            gsifree(newStream->buffer);
            gsifree(newStream);
            return 0;
        }
    }
    for (i = 0; i < count; i++) {
        if (!gsiXmlUtilWriteChar(newStream, ' ') ||
            !gsiXmlUtilWriteString(newStream, gGsXmlNamespacePrefix) ||
            !gsiXmlUtilWriteString(newStream, namespaces[i])) {
            gsifree(newStream->buffer);
            gsifree(newStream);
            return 0;
        }
    }
    if (!gsiXmlUtilWriteChar(newStream, '>') ||
        !gsiXmlUtilWriteString(newStream, gGsXmlSoapBodyStart)) {
        gsifree(newStream->buffer);
        gsifree(newStream);
        return 0;
    }
    return newStream;
}




/*
 * sdk:      gsXmlCreateStreamReader (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * Allocates a GSIXmlStreamReader (0x14 bytes), gives it an element array
 * (24-byte elements, 32 of them) and an attribute array (24-byte elements, 16)
 * and points it at the start of the stream.  Both failure paths report through
 * the SAME diagnostic string gGsXmlOomElementArrayFormat - that shared literal is what fixes the
 * literal-pool order (gGsXmlOomStreamFormat, gsiXmlUtilElementFree, gGsXmlOomElementArrayFormat,
 * gsiXmlUtilAttributeFree) and therefore every pool offset in the function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/gsXmlCreateStreamReader.c \
 *       --func gsXmlCreateStreamReader --addr 0x02181C2C --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
void *gsXmlCreateStreamReader(void)
{
    GSIXmlStreamReader *newStream;

    newStream = (GSIXmlStreamReader *)gsimalloc(sizeof(GSIXmlStreamReader));
    if (newStream == 0)
    {
        gsDebugFormat(12, (char *)2, 1, gGsXmlOomStreamFormat, sizeof(GSIXmlStreamReader));
        return 0;
    }
    newStream->elements = ArrayNew(24, 32, gsiXmlUtilElementFree);
    if (newStream->elements == 0)
    {
        gsDebugFormat(12, (char *)2, 1, gGsXmlOomElementArrayFormat);
        gsifree(newStream);
        return 0;
    }
    newStream->attributes = ArrayNew(24, 16, gsiXmlUtilAttributeFree);
    if (newStream->attributes == 0)
    {
        gsDebugFormat(12, (char *)2, 1, gGsXmlOomElementArrayFormat);
        ArrayFree(newStream->elements);
        gsifree(newStream);
        return 0;
    }
    gsXmlMoveToStart(newStream);
    return newStream;
}




int gsXmlParseBuffer(void *stream, char *data, int len)
{
    int readPos = 0;

    gsXmlResetReader(stream);
    while (readPos < len)
    {
        if (gsiXmlUtilParseElement(stream, data, len, &readPos, -1) == 0)
            return 0;
    }
    return 1;
}




/*
 * Calls the module helper on the pointed-to block and then on the pointer.
 */
void gsXmlFreeWriter(void **writerRef)
{
    gsifree(*writerRef);
    gsifree(writerRef);
}




void gsXmlFreeReader(void *stream)
{
    GSIXmlStreamReader * reader = (GSIXmlStreamReader *)stream;

    ArrayFree(reader->attributes);
    ArrayFree(reader->elements);
    gsifree(reader);
}




void gsXmlResetReader(void *stream)
{
    GSIXmlStreamReader * reader = (GSIXmlStreamReader *)stream;

    ArrayClear(reader->attributes);
    ArrayClear(reader->elements);
    gsXmlMoveToStart(reader);
}




int gsXmlCloseWriter(void *stream)
{
    GSIXmlStreamWriter * writer = (GSIXmlStreamWriter *)stream;
    int result;

    if (gsiXmlUtilWriteString(writer, gGsXmlSoapEnvelopeEnd) == 0)
        result = 0;
    else
    {
        result = 1;
        writer->closed = 1;
    }
    return result;
}


/*
 * sdk:      gsiXmlUtilElementFree (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    a 4-byte `bx lr` (ArrayNew element free callback); gsXmlCreateStreamReader's
 *           relocation at +0xD8 (ABS32 gsiXmlUtilElementFree) is the pool word at
 *           0x02181D04 that names it.  Seeded in layout/function_starts.txt.
 */
void gsiXmlUtilElementFree(void *elem)
{
}


/*
 * sdk:      gsiXmlUtilAttributeFree (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    a 4-byte `bx lr`; gsXmlCreateStreamReader's relocation at +0xE0
 *           (ABS32 gsiXmlUtilAttributeFree) is the pool word at 0x02181D0C.
 *           Byte-identical to 0x02181E10: the name comes from that relocation.
 *           Seeded in layout/function_starts.txt.
 */
void gsiXmlUtilAttributeFree(void *elem)
{
}



/*
 * sdk:      gsXmlWriterGetData (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    `ldr r0, [r0]; bx lr`; called by bl from ov114 ghttp code (see
 *           layout/function_starts.txt).  Seeded in layout/function_starts.txt.
 */
char *gsXmlWriterGetData(void *stream)
{
    return ((GSIXmlStreamWriter *)stream)->buffer;
}



/*
 * sdk:      gsXmlWriterGetDataLength (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    `ldr r0, [r0, #4]; bx lr`; called by bl from ov114 ghttp code (see
 *           layout/function_starts.txt).  Seeded in layout/function_starts.txt.
 */
int gsXmlWriterGetDataLength(void *stream)
{
    return ((GSIXmlStreamWriter *)stream)->length;
}







static int gsiXmlUtilSkipWhiteSpace(void *unused, char *buffer, int len, int *pos)
{
    while (*pos < len)
    {
        if (strchr(gGsXmlWhiteSpaceChars, buffer[*pos]) == 0)
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
static int gsiXmlUtilParseElement(GSIXmlStreamReader *stream, char *buffer, int len,
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
            newAttr.owningElementIndex = newElem.index;
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
        if (!gsiXmlUtilParseElement(stream, buffer, len, pos, newElem.index))
            return 0;
        gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    }
    return 0;
}





#undef isalnum




#undef isalnum



#undef isalnum


#undef isalnum

#undef isalnum

#define isalnum(c) (((c) < 0 || (c) >= 0x80) ? 0 : (gCtypeMap[c] & 0x9))






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
int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
{
    int haveNamespace = 0;
    char c;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (*pos >= len)
        return 0;
    c = buffer[*pos];
    if (!isalnum(c) || isdigit(buffer[*pos]))
        return 0;
    strOut->string = buffer + *pos;
    strOut->length = 1;
    (*pos)++;
    while (*pos < len && strchr(gGsXmlWhiteSpaceChars, c = buffer[*pos]) == 0) {
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
 *   python tools/match.py one --src src/matched/ov_sdk/gsiXmlUtilParseString.c \
 *       --func gsiXmlUtilParseString --addr 0x02182554 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
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
int gsiXmlUtilDecodeString(char *buffer, int *len)
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

		if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityAmp, 5)==0)
		{
			buffer[readPos++] = '&';
			charsToRemove = 5-1;
		}
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityQuot, 6)==0)
		{
			buffer[readPos++] = '"';
			charsToRemove = 6-1;
		}
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityApos, 6)==0)
		{
			buffer[readPos++] = '\'';
			charsToRemove = 6-1;
		}
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityLt, 4)==0)
		{
			buffer[readPos++] = '<';
			charsToRemove = 4-1;
		}
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityGt, 4)==0)
		{
			buffer[readPos++] = '>';
			charsToRemove = 4-1;
		}
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityHexPrefix, 3)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = strchr(&buffer[readPos+3], ';');
			if (digitEnd == 0)
				return 0;
			if (digitEnd - &buffer[readPos+3] > 8)
				return 0;

			STD_TSScanf(&buffer[readPos+3], gGsXmlHex8Format, &digitValue);

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
		else if (strncmp((const char *)(&buffer[readPos]), (const char *)gGsXmlEntityDecPrefix, 2)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = strchr(&buffer[readPos+2], ';');
			if (digitEnd == 0)
				return 0;

			digitValue = (unsigned int)atoi((const char *)(&buffer[readPos+2]));

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

		memmove(&buffer[readPos], &buffer[readPos+charsToRemove], (unsigned int)(*len-(readPos+charsToRemove)));
		MSL_C_LIB_MemsetPtr(&buffer[*len-charsToRemove], ' ', (unsigned int)charsToRemove);
		(*len) -= charsToRemove;
	}

	return 1;
}






/*
 * sdk:      gsiXmlUtilParseValue (gsxml)
 */
int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
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
int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteAsciiStringElement(void *stream, char *namespaceName, char *tag, char *value)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteUnicodeStringElement(void *stream, char *namespaceName, char *tag, unsigned short *value)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value)
{
    char buf[32];
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;

    sprintf(buf, gGsXmlIntFormat, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}







/*
 * sdk:      gsXmlWriteInt64Element (gsxml)
 */
int gsXmlWriteInt64Element(void *stream, char *namespaceName, char *tag, long long value)
{
    char buf[33];
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;

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
int gsXmlWriteFloatElement(void *stream, char *namespaceName, char *tag, float value)
{
    char buf[32];
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;

    sprintf(buf, gGsXmlFloatFormat, (double)value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}







/*
 * sdk:      gsXmlWriteHexBinaryElement (gsxml)
 */
int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
    int pos = 0;
    char hex[3];

    hex[2] = 0;
    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    for (pos = 0; pos < len; )
    {
        sprintf(hex, gGsXmlHex2Format, data[pos]);
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
int gsXmlWriteBase64BinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
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
int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value)
{
    GSIXmlStreamWriter *writer = (GSIXmlStreamWriter *)stream;
    char timeString[21];
    struct tm *timePtr;

    timePtr = gsiSecondsToDate(&value);
    sprintf(timeString, gGsXmlDateTimeFormat, timePtr->tm_year + 1900, timePtr->tm_mon + 1, timePtr->tm_mday, timePtr->tm_hour, timePtr->tm_min, timePtr->tm_sec);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, timeString)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}







/*
 * sdk:      gsXmlWriteLargeIntElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
int gsXmlWriteLargeIntElement(void *stream, char *namespaceName, char *tag, gsLargeInt *lint)
{
    GSIXmlStreamWriter *writer;
    unsigned int *readBuf;
    int readPos;
    int first = 1;
    char hex[3];
    unsigned int i;

    readPos = lint->mLength - 1;
    readBuf = lint->mData;
    if (!gsXmlWriteOpenTag(stream, namespaceName, tag))
        return 0;
    while (readPos >= 0 && readBuf[readPos] == 0)
        readPos--;
    writer = (GSIXmlStreamWriter *)stream;
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
                sprintf(hex, gGsXmlHex2Format, (lint->mData[readPos] >> ((3 - i) * 8)) & 0xff);
                if (!gsiXmlUtilWriteChar(writer, hex[0]))
                    return 0;
                if (!gsiXmlUtilWriteChar(writer, hex[1]))
                    return 0;
            }
        }
    }
    if (!gsXmlWriteCloseTag(stream, namespaceName, tag))
        return 0;
    return 1;
}







int gsiXmlUtilWriteChar(GSIXmlStreamWriter *stream, char ch)
{
    if (stream->length >= stream->capacity)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    stream->buffer[stream->length] = ch;
    stream->length++;
    return 1;
}







static int gsiXmlUtilWriteString(GSIXmlStreamWriter *stream, const char *str)
{
    int strLen;

    strLen = strlen(str);
    if (strLen == 0)
        return 1;
    while (stream->capacity - stream->length <= strLen)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    strcpy(stream->buffer + stream->length, str);
    stream->length += strLen;
    return 1;
}






/*
 * sdk:      gsiXmlUtilWriteUnicodeString (gsxml)
 */
int gsiXmlUtilWriteUnicodeString(GSIXmlStreamWriter *stream, unsigned short *str)
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
int gsiXmlUtilWriteXmlSafeString(void *stream, char *str)
{
    int strLen;
    int pos;
    int result;
    char numeric[7];

    strLen = strlen(str);
    for (pos = 0; pos < strLen; pos++) {
        char c = str[pos];
        if (c == '&') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityAmp);
        } else if (c == '\'') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityApos);
        } else if (c == '"') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityQuot);
        } else if (c == '<') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityLt);
        } else if (c == '>') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityGt);
        } else if (c == ' ') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntitySpace);
        } else if (c < ' ' || (unsigned char)c > 0x7f) {
            sprintf(numeric, gGsXmlEntityByteFormat, (unsigned char)c);
            numeric[6] = 0;
            result = gsiXmlUtilWriteString(stream, numeric);
        } else {
            result = gsiXmlUtilWriteChar(stream, c);
        }
        if (!result)
            return 0;
    }
    return 1;
}






static int gsiXmlUtilGrowBuffer(GSIXmlStreamWriter *stream)
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
int gsXmlMoveToStart(void *stream)
{
    int *reader = (int *)stream;
    reader[2] = -1;
    reader[3] = -1;
    reader[4] = -1;
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
            reader->readAttributeIndex = -1;
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
        reader->readAttributeIndex = -1;
        result = 1;
    }
    return result;
}






/*
 * sdk:      gsXmlMoveToChild (gsxml)
 */
int gsXmlMoveToChild(void *stream, char *matchtag)
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
            reader->readAttributeIndex = -1;
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
int gsXmlReadChildAsHexBinary(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut)
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
                STD_TSScanf(searchValueElem->value.string + readpos, gGsXmlHex2Format, &temp);
                valueOut[writepos] = temp;
                bytesleft -= 2;
                readpos += 2;
                writepos++;
            }
            if (bytesleft == 1) {
                STD_TSScanf(searchValueElem->value.string + readpos, gGsXmlHex1Format, &temp);
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
int gsXmlReadChildAsBase64Binary(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut)
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
                    B64Decode(searchValueElem->value.string, (char *)valueOut, searchValueElem->value.length, lenOut, 0);
            }
            else
            {
                if (searchValueElem->value.string == 0)
                    *lenOut = 0;
                else
                    *lenOut = B64DecodeLen(searchValueElem->value.string, 0);
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
int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut)
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
int gsXmlReadChildAsInt64(void *stream, char *matchtag, long long *valueOut)
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
int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut)
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
            STD_TSScanf(searchValueElem->value.string, gGsXmlDateTimeFormatNoZ, &timePtr.tm_year, &timePtr.tm_mon,
                          &timePtr.tm_mday, &timePtr.tm_hour, &timePtr.tm_min, &timePtr.tm_sec);
            timePtr.tm_year -= 1900;
            timePtr.tm_mon -= 1;
            timePtr.tm_isdst = -1;
            *valueOut = gsiDateToSeconds(&timePtr);
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
int gsXmlReadChildAsFloat(void *stream, char *matchtag, float *valueOut)
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
 * gsXmlReadChildAsHexBinary; the byte count it reports is rounded up to a word count and
 * stored at c[0].  Returns 1 when the object validates, 0 when the fill loop
 * reports nothing produced.
 */
int gsXmlReadChildAsLargeInt(void *stream, char *matchtag, int *lintData)
{
    u32 n = 0;
    u32 k;

    MSL_C_LIB_MemsetPtr(lintData, 0, 0x104);
    if (gsXmlReadChildAsHexBinary(stream, matchtag, (unsigned char *)(lintData + 1), 0x200, (int *)(&n)) == 0)
        return 0;

    k = n >> 2;
    lintData[0] = k;
    if (n & 3)
        lintData[0] = k + 1;

    if (gsLargeIntReverseBytes((char *)lintData) == 0)
        return 0;
    return 1;
}




int gsXmlCountChildren(void *stream, char *matchtag)
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
