/*
 * function: gsXmlCountChildren
 * address:  0x02183EE0
 * packet:   pkt_ov009_02183EE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlCountChildren (gsxml)
 *
 * symbols:
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
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

int gsXmlCountChildren(void *stream, char *matchtag)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchElem;
    int i;
    int count = 0;

    for (i = reader->index + 1; i < ArrayLength(reader->elements); i++)
    {
        searchElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchElem->parent == reader->index)
        {
            if (matchtag == 0 || gsiXmlUtilTagMatches(matchtag, searchElem))
                count++;
        }
        else if (searchElem->parent < reader->index)
            break;
    }
    return count;
}
