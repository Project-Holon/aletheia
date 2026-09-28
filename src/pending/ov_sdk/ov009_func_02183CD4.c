/*
 * function: func_02183CD4
 * address:  0x02183CD4
 * packet:   pkt_ov009_02183CD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      gsXmlReadChildAsFloat (gsxml)
 *
 * symbols:
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 *   atof                  0x02095B2C arm
 *   _d2f                  0x0209B64C arm
 *
 * note: byte-correct; blocked: callee _d2f at arm9 0x0209B64C is an unmatched ARM9 game row with no witness (PC24 at +0x84 unattested); becomes EXACT once _d2f is matched
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
extern double atof(const char *s);

int func_02183CD4(void *stream, char *matchtag, float *valueOut)
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
            *valueOut = (float)atof(searchValueElem->value);
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
