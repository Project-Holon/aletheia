/*
 * file:     unit_02181E28_p04.c
 * unit:     yes
 * function: func_02182FF8, func_021830D0, func_02183210
 * address:  0x02182FF8
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
 *   gsiSecondsToDate       0x0217F2C8 arm ov009
 *   sprintf                0x02094530 arm
 *   gsXmlWriteOpenTag      0x021829AC arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   gsXmlWriteCloseTag     0x02182A2C arm ov009
 *   g_021A3F64             0x021A3F64 data
 *   func_021829AC  0x021829ac  arm   ov009
 *   func_02183210  0x02183210  arm   ov009
 *   func_02182A2C  0x02182a2c  arm   ov009
 *   g_021A3F5C     0x021a3f5c  data
 *   gsiXmlUtilGrowBuffer             0x02183490 arm
 */
struct GSIXmlStreamWriter_02182FF8
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

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

struct GSIXmlStreamWriter_021830D0 {
    char *buffer;
    int position;
    int capacity;
};

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt;

struct GSIXmlStreamWriter_02183210
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter_02182FF8 *stream, char *str);
extern struct tm *gsiSecondsToDate(long *timp);
extern int sprintf(char *buf, const char *fmt, ...);
extern int func_021829AC(void *, char *, char *);
extern int func_02183210(struct GSIXmlStreamWriter_021830D0 *, char);
extern int func_02182A2C(void *, char *, char *);
extern int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter_02183210 *stream);
int func_02182FF8(void *stream, char *namespaceName, char *tag, long value);
int func_021830D0(void *stream, char *namespaceName, char *tag, gsLargeInt *lint);
extern char g_021A3F64[];
extern char g_021A3F5C[];


/*
 * sdk:      gsXmlWriteDateTimeElement (gsxml)
 */
int func_02182FF8(void *stream, char *namespaceName, char *tag, long value)
{
    struct GSIXmlStreamWriter_02182FF8 *writer = (struct GSIXmlStreamWriter_02182FF8 *)stream;
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
    struct GSIXmlStreamWriter_021830D0 *writer;
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
    writer = (struct GSIXmlStreamWriter_021830D0 *)stream;
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


static int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter_02183210 *stream, char ch)
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
