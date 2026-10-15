/*
 * function: gsXmlWriteDateTimeElement
 * address:  0x02182FF8
 * packet:   pkt_ov009_02182FF8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteDateTimeElement (gsxml)
 *
 * symbols:
 *   gsiSecondsToDate       0x0217F2C8 arm ov009
 *   sprintf                0x02094530 arm
 *   gsXmlWriteOpenTag      0x021829AC arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   gsXmlWriteCloseTag     0x02182A2C arm ov009
 *   gGsXmlDateTimeFormat             0x021A3F64 data
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);

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

extern struct tm *gsiSecondsToDate(long *timp);
extern int sprintf(char *buf, const char *fmt, ...);
extern char gGsXmlDateTimeFormat[];

int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
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
