/*
 * function: gsXmlCreateStreamWriter
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
 */

typedef struct GSIXmlStreamWriter {
    char *buffer;               /* +0x00 */
    int len;                    /* +0x04 */
    int capacity;               /* +0x08 */
    int openElements;           /* +0x0c */
} GSIXmlStreamWriter;

extern void *gsimalloc(unsigned long size);
typedef unsigned char  u8;
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int strlen(const u8 *s);
extern int gsiXmlUtilWriteString(GSIXmlStreamWriter *stream, const char *str);
extern void gsifree(void *ptr);
extern int gsiXmlUtilWriteChar(GSIXmlStreamWriter *stream, char ch);
extern char gGsXmlOomWriterFormat[];
extern char gGsXmlNamespacePrefix[];
extern const char *gGsXmlSoapDefaultNamespaces[4];   /* GS_XML_SOAP_DEFAULT_NAMESPACES */
extern char gGsXmlSoapEnvelopeStart[];
extern char gGsXmlSoapBodyStart[];

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
        namespaceLen += strlen((const u8 *)gGsXmlNamespacePrefix) + 1;
        namespaceLen += strlen((const u8 *)gGsXmlSoapDefaultNamespaces[i]);
    }
    for (i = 0; i < count; i++) {
        namespaceLen += strlen((const u8 *)gGsXmlNamespacePrefix) + 1;
        namespaceLen += strlen((const u8 *)namespaces[i]);
    }
    while (initialCapacity < namespaceLen)
        initialCapacity += 1024;

    newStream->buffer = gsimalloc(initialCapacity);
    if (newStream->buffer == 0) {
        gsDebugFormat(0xc, (char *)2, 1, gGsXmlOomWriterFormat, initialCapacity);
        return 0;
    }
    newStream->capacity = initialCapacity;
    newStream->len = 0;
    newStream->buffer[0] = '\0';
    newStream->openElements = 0;

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
