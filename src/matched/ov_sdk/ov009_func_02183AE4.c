/*
 * function: func_02183AE4
 * address:  0x02183AE4
 * packet:   pkt_ov009_02183AE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsInt64 (gsxml)
 *
 * symbols:
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 *   gsiStringToInt64      0x0217F124 arm ov009
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
extern long long gsiStringToInt64(const char *s);

int func_02183AE4(void *stream, char *matchtag, long long *valueOut)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchValueElem;
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
            *valueOut = gsiStringToInt64(searchValueElem->value);
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
