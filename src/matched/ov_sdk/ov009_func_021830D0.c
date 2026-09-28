/*
 * function: func_021830D0
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
 *   func_021829AC  0x021829ac  arm   ov009
 *   sprintf        0x02094530  arm
 *   func_02183210  0x02183210  arm   ov009
 *   func_02182A2C  0x02182a2c  arm   ov009
 *   g_021A3F5C     0x021a3f5c  data
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

extern int func_021829AC(void *, char *, char *);
extern int sprintf(char *, const char *, ...);
extern int func_02183210(struct GSIXmlStreamWriter *, char);
extern int func_02182A2C(void *, char *, char *);
extern char g_021A3F5C[];

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
                if (!func_02183210(writer, hex[0]))
                    return 0;
                if (!func_02183210(writer, hex[1]))
                    return 0;
            }
        }
    }
    if (!func_02182A2C(stream, namespaceName, tag))
        return 0;
    return 1;
}
