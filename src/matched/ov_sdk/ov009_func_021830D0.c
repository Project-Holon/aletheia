/*
 * function: gsXmlWriteLargeIntElement
 * address:  0x021830D0
 * packet:   pkt_ov009_021830D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteLargeIntElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * symbols:
 *   gsXmlWriteOpenTag  0x021829ac  arm   ov009
 *   sprintf        0x02094530  arm
 *   gsiXmlUtilWriteChar  0x02183210  arm   ov009
 *   gsXmlWriteCloseTag  0x02182a2c  arm   ov009
 *   gGsXmlHex2Format     0x021a3f5c  data
 */

struct GSIXmlStreamWriter {
    char *buffer;
    int position;
    int capacity;
};

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt;

extern int gsXmlWriteOpenTag(void *, char *, char *);
extern int sprintf(char *, const char *, ...);
extern int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *, char);
extern int gsXmlWriteCloseTag(void *, char *, char *);
extern char gGsXmlHex2Format[];

int gsXmlWriteLargeIntElement(void *stream, char *namespaceName, char *tag, gsLargeInt *lint)
{
    struct GSIXmlStreamWriter *writer;
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
