/*
 * file:     unit_0218198C_p01.c
 * unit:     yes
 * function: func_0218198C, func_021819B0, func_02181C2C, func_02181D10
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
 *   func_0217EAB0                    0x0217eab0 arm  ov009
 *   func_0217D254                    0x0217d254 arm  ov009
 *   func_0209477C                    0x0209477c arm
 *   func_0218325C                    0x0218325c arm  ov009
 *   func_0217EAE0                    0x0217eae0 arm  ov009
 *   func_02183210                    0x02183210 arm  ov009
 *   g_021A3DE4                       0x021a3de4 data
 *   g_021A3E20                       0x021a3e20 data
 *   g_021A3D0C                       0x021a3d0c data
 *   g_021A3E28                       0x021a3e28 data
 *   g_021A3E64                       0x021a3e64 data
 *   gsimalloc                0x0217EAB0 arm ov009
 *   gsDebugFormat            0x0217D254 arm ov009
 *   ArrayNew                 0x02184144 arm ov009
 *   gsifree                  0x0217EAE0 arm ov009
 *   ArrayFree                0x021841B0 arm ov009
 *   gsXmlMoveToStart         0x021834D0 arm ov009
 *   g_021A3E74               0x021A3E74 data
 *   gsiXmlUtilElementFree    0x02181E10 arm ov009
 *   g_021A3EA8               0x021A3EA8 data
 *   gsiXmlUtilAttributeFree  0x02181E14 arm ov009
 *   gsXmlResetReader                 0x02181dc4 arm
 *   gsiXmlUtilParseElement           0x02181e80 arm
 */
typedef struct GSIXmlStreamWriter {
    char *buffer;               /* +0x00 */
    int len;                    /* +0x04 */
    int capacity;               /* +0x08 */
    int openElements;           /* +0x0c */
} GSIXmlStreamWriter;

typedef unsigned char  u8;

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

extern void *func_0217EAB0(unsigned long size);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern int func_0218325C(GSIXmlStreamWriter *stream, const char *str);
extern void func_0217EAE0(void *ptr);
extern int func_02183210(GSIXmlStreamWriter *stream, char ch);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ArrayFree(void *array);
extern int gsXmlMoveToStart(void *stream);
extern void gsiXmlUtilElementFree(void *elem);
extern void gsiXmlUtilAttributeFree(void *elem);
extern void gsXmlResetReader(void *stream);
extern int gsiXmlUtilParseElement(void *stream, char *buffer, int len, int *pos, int parentIndex);
int func_0218198C(const unsigned short *p);
void *func_021819B0(const char **namespaces, int count);
void *func_02181C2C(void);
int gsXmlParseBuffer(void *stream, char *data, int len);
extern char g_021A3DE4[];
extern char g_021A3E20[];
extern const char *g_021A3D0C[4];   /* GS_XML_SOAP_DEFAULT_NAMESPACES */
extern char g_021A3E28[];
extern char g_021A3E64[];
extern char g_021A3E74[];
extern char g_021A3EA8[];

/*
 * Number of halfwords before the terminating zero, less one.
 */
int func_0218198C(const unsigned short *p)
{
    const unsigned short *q = p;
    unsigned short v;

    do {
        v = *q++;
    } while (v != 0);
    return (int)((const char *)q - (const char *)p) / 2 - 1;
}


/*
 * sdk:      gsXmlCreateStreamWriter (gsxml.o)
 */
void *func_021819B0(const char **namespaces, int count)
{
    GSIXmlStreamWriter *newStream;
    int initialCapacity = 1024;
    int namespaceLen = 0;
    int i;

    newStream = func_0217EAB0(sizeof(GSIXmlStreamWriter));
    if (newStream == 0) {
        func_0217D254(0xc, (char *)2, 1, g_021A3DE4, sizeof(GSIXmlStreamWriter));
        return 0;
    }

    for (i = 0; i < 4; i++) {
        namespaceLen += func_0209477C((const u8 *)g_021A3E20) + 1;
        namespaceLen += func_0209477C((const u8 *)g_021A3D0C[i]);
    }
    for (i = 0; i < count; i++) {
        namespaceLen += func_0209477C((const u8 *)g_021A3E20) + 1;
        namespaceLen += func_0209477C((const u8 *)namespaces[i]);
    }
    while (initialCapacity < namespaceLen)
        initialCapacity += 1024;

    newStream->buffer = func_0217EAB0(initialCapacity);
    if (newStream->buffer == 0) {
        func_0217D254(0xc, (char *)2, 1, g_021A3DE4, initialCapacity);
        return 0;
    }
    newStream->capacity = initialCapacity;
    newStream->len = 0;
    newStream->buffer[0] = '\0';
    newStream->openElements = 0;

    if (!func_0218325C(newStream, g_021A3E28)) {
        func_0217EAE0(newStream->buffer);
        func_0217EAE0(newStream);
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (!func_02183210(newStream, ' ') ||
            !func_0218325C(newStream, g_021A3E20) ||
            !func_0218325C(newStream, g_021A3D0C[i])) {
            func_0217EAE0(newStream->buffer);
            func_0217EAE0(newStream);
            return 0;
        }
    }
    for (i = 0; i < count; i++) {
        if (!func_02183210(newStream, ' ') ||
            !func_0218325C(newStream, g_021A3E20) ||
            !func_0218325C(newStream, namespaces[i])) {
            func_0217EAE0(newStream->buffer);
            func_0217EAE0(newStream);
            return 0;
        }
    }
    if (!func_02183210(newStream, '>') ||
        !func_0218325C(newStream, g_021A3E64)) {
        func_0217EAE0(newStream->buffer);
        func_0217EAE0(newStream);
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
 * the SAME diagnostic string g_021A3EA8 - that shared literal is what fixes the
 * literal-pool order (g_021A3E74, gsiXmlUtilElementFree, g_021A3EA8,
 * gsiXmlUtilAttributeFree) and therefore every pool offset in the function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02181C2C.c \
 *       --func func_02181C2C --addr 0x02181C2C --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
void *func_02181C2C(void)
{
    struct GSIXmlStreamReader *newStream;

    newStream = (struct GSIXmlStreamReader *)gsimalloc(sizeof(struct GSIXmlStreamReader));
    if (newStream == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3E74, sizeof(struct GSIXmlStreamReader));
        return 0;
    }
    newStream->elements = ArrayNew(24, 32, gsiXmlUtilElementFree);
    if (newStream->elements == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3EA8);
        gsifree(newStream);
        return 0;
    }
    newStream->attributes = ArrayNew(24, 16, gsiXmlUtilAttributeFree);
    if (newStream->attributes == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3EA8);
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
