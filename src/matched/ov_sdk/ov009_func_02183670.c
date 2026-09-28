/*
 * function: gsXmlReadChildAsString
 * address:  0x02183670
 * packet:   pkt_ov009_02183670
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsString (gsxml.o)
 *
 * symbols:
 *   ArrayLength                      0x02184200 arm
 *   ArrayNth                         0x02184208 arm
 *   gsiXmlUtilTagMatches             0x02183d98 arm
 */

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

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
extern int gsiXmlUtilTagMatches(char *matchtag, struct GSIXmlString *xmlstr);

int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement * searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
        if ((searchValueElem->parent == reader->index) &&
            gsiXmlUtilTagMatches(matchtag, (struct GSIXmlString *)searchValueElem))
        {
            reader->readIndex = i;
            *valueOut = searchValueElem->value;
            *lenOut = searchValueElem->valueLen;
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
