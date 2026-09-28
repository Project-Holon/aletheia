/*
 * function: func_021819B0
 * address:  0x021819B0
 * packet:   pkt_ov009_021819B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlCreateStreamWriter (gsxml.o)
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
 */

typedef struct GSIXmlStreamWriter {
    char *buffer;               /* +0x00 */
    int len;                    /* +0x04 */
    int capacity;               /* +0x08 */
    int openElements;           /* +0x0c */
} GSIXmlStreamWriter;

extern void *func_0217EAB0(unsigned long size);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern int func_0209477C(const char *s);
extern int func_0218325C(GSIXmlStreamWriter *stream, const char *str);
extern void func_0217EAE0(void *ptr);
extern int func_02183210(GSIXmlStreamWriter *stream, char ch);
extern char g_021A3DE4[];
extern char g_021A3E20[];
extern const char *g_021A3D0C[4];   /* GS_XML_SOAP_DEFAULT_NAMESPACES */
extern char g_021A3E28[];
extern char g_021A3E64[];

void *func_021819B0(const char **namespaces, int count)
{
    GSIXmlStreamWriter *newStream;
    int initialCapacity = 1024;
    int namespaceLen = 0;
    int i;

    newStream = func_0217EAB0(sizeof(GSIXmlStreamWriter));
    if (newStream == 0) {
        func_0217D254(0xc, 2, 1, g_021A3DE4, sizeof(GSIXmlStreamWriter));
        return 0;
    }

    for (i = 0; i < 4; i++) {
        namespaceLen += func_0209477C(g_021A3E20) + 1;
        namespaceLen += func_0209477C(g_021A3D0C[i]);
    }
    for (i = 0; i < count; i++) {
        namespaceLen += func_0209477C(g_021A3E20) + 1;
        namespaceLen += func_0209477C(namespaces[i]);
    }
    while (initialCapacity < namespaceLen)
        initialCapacity += 1024;

    newStream->buffer = func_0217EAB0(initialCapacity);
    if (newStream->buffer == 0) {
        func_0217D254(0xc, 2, 1, g_021A3DE4, initialCapacity);
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
