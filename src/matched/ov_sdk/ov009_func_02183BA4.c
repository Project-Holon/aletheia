/*
 * function: gsXmlReadChildAsDateTimeElement
 * address:  0x02183BA4
 * packet:   pkt_ov009_02183BA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsDateTimeElement (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * symbols:
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 *   func_0208CF34         0x0208CF34 arm
 *   gsiDateToSeconds         0x0217F478 arm ov009
 *   gGsXmlDateTimeFormatNoZ            0x021A3FA0 data
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
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

extern int func_0208CF34(char *src, char *fmt, ...);
extern long gsiDateToSeconds(struct tm *tb);
extern char gGsXmlDateTimeFormatNoZ[];

int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchValueElem;
    struct tm timePtr;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchValueElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value == 0)
                return 0;
            func_0208CF34(searchValueElem->value, gGsXmlDateTimeFormatNoZ, &timePtr.tm_year, &timePtr.tm_mon,
                          &timePtr.tm_mday, &timePtr.tm_hour, &timePtr.tm_min, &timePtr.tm_sec);
            timePtr.tm_year -= 1900;
            timePtr.tm_mon -= 1;
            timePtr.tm_isdst = -1;
            *valueOut = gsiDateToSeconds(&timePtr);
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
